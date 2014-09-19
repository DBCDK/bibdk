<?php
// XML FUNKTIONER

/*
 * xmlparse
 */
function xmlparse($xmlrec, $skip_white=FALSE, $loud=FALSE) {
  global $xml_vals, $xml_tags;

  $xml_parser = xml_parser_create("ISO-8859-1");
  xml_parser_set_option($xml_parser, XML_OPTION_CASE_FOLDING, TRUE);
// XML_OPTION_SKIP_WHITE funker ikke i php5+
  //xml_parser_set_option($xml_parser, XML_OPTION_SKIP_WHITE, $skip_white);
  if (strpos($xmlrec, ' encoding='))
    $this_data = $xmlrec;
  else
    $this_data = '<?xml version="1.0" encoding="ISO-8859-1"?>' . $xmlrec;
  if ($skip_white)
    xml_parse_into_struct($xml_parser, str_replace("\r\n", "", $this_data), $xml_vals, $xml_tags);
  else
    xml_parse_into_struct($xml_parser, $this_data, $xml_vals, $xml_tags);
  $xml_error = xml_get_error_code($xml_parser);
  if ($xml_error && $loud) {
    verbose(ERROR, "xmlfield() error_code: " . xml_get_error_code($xml_parser) .
                   " error_string: " . xml_error_string($xml_error) .
                   " error_line_number: " . xml_get_current_line_number($xml_parser) .
                   " error_column_number: " . xml_get_current_column_number($xml_parser) .
                   " error_byte_index: " . xml_get_current_byte_index($xml_parser));
    verbose(DEBUG, "xmlfield() field: " . $field .
                   " xmlrec: " . $xmlrec);
    echo "Error: " . xml_error_string($xml_error);
  }
  xml_parser_free($xml_parser);
}

function xml2array($data, $save_dup=FALSE, $skip_white_space=FALSE) {
 //mvo voncken@mailandnews.com
 //original ripped from  on the php-manual:gdemartini@bol.com.br
 //to be used for data retrieval(result-structure is Data oriented)

  global $xml_vals, $xml_tags;
  xmlparse($data, $skip_white_space);

  $tree = array();
  $i = 0;
  //array_push($tree, array('tag' => $vals[$i]['tag'], 'attributes'=> $vals[$i]['attributes'],                            'children' => ));
  $tree = GetChildren($xml_vals, $i, $save_dup);
  return $tree;
}


function GetChildren($vals, &$i, $save_dup) {
//echo "\nGetChildren: $i";
  $children = array();
  if ( !isset($j) ) $j=0;
  if ( isset($vals[$i]['value']) ) array_push($children, $vals[$i]['value']);

  $prevtag = "";
  while (++$i < count($vals)) {   // so pra nao botar while true ;-)
    //echo "\n$i " . $vals[$i]['tag'] . ":" . $vals[$i]['type'] . " -> . " . $vals[$i]['value'];
    switch ($vals[$i]['type']) {
       case 'cdata':
         array_push($children, trim($vals[$i]['value']));
         break;
       case 'complete':
         $tag = strtolower($vals[$i]['tag']);
           if ($save_dup)
             // $children[$tag][] = $vals[$i]['value'];
             $children[$tag][] = ( isset($vals[$i]['value']) )  ? trim($vals[$i]['value']) : '';
           else
             // $children[$tag] = $vals[$i]['value'];
             $children[$tag] = ( isset($vals[$i]['value']) )  ? trim($vals[$i]['value']) : '';
         //}
         break;

       case 'open':
         //restartindex on unique tag-name
         $j++;
         if ($prevtag <> $vals[$i]['tag']) {
                 $j = 0;
                 $prevtag = $vals[$i]['tag'];
         }
         $children[ strtolower($vals[$i]['tag']) ][$j] = GetChildren($vals,$i, $save_dup);
         break;

       case 'close':
         return $children;
    }
  }
}


function array2xml($array, $level=1) {
  // Gijs van Tulder. gvtulder.f2o.org :: gvtulder@gmx.net
  //  This is a simple function that converts a PHP array to XML.
  // ex: define("XML_DOCTYPE",    '<!DOCTYPE menustruktur SYSTEM "menustruktur.dtd">');
  // ex: define("XML_ROOT",       "menustruktur");

  $xml = '';
  if ($level==1) {
    $xml .= '<?xml version="1.0" encoding="ISO-8859-1"?>'."\n";
    if ( defined('XML_DOCTYPE') ) $xml .= XML_DOCTYPE."\n";
    $xml .= ( defined('XML_ROOT') ) ? "<".XML_ROOT.">\n" : "<array>\n";
  }
  foreach ($array as $key=>$value) {
    $key = strtolower($key);
    if (is_array($value)) {
      $multi_tags = FALSE;
      foreach($value as $key2=>$value2) {
        if (is_array($value2)) {
          $xml .= str_repeat("  ",$level)."<$key>\n";
          $xml .= array2xml($value2, $level+1);
          $xml .= str_repeat("  ",$level)."</$key>\n";
          $multi_tags = TRUE;
        } else {
          if (trim($value2)!='') {
            if (htmlspecialchars($value2)!=$value2) {
              $xml .= str_repeat("  ",$level).  "<$key><![CDATA[$value2]]>".  "</$key>\n";
            } else {
              $xml .= str_repeat("  ",$level).  "<$key>$value2</$key>\n";
            }
          }
          $multi_tags = TRUE;
        }
      }
      if (!$multi_tags and count($value)>0) {
        $xml .= str_repeat("  ",$level)."<$key>\n";
        $xml .= array2xml($value, $level+1);
        $xml .= str_repeat("  ",$level)."</$key>\n";
      }
    } else {
      if (trim($value)!='') {
        if (htmlspecialchars($value)!=$value) {
          $xml .= str_repeat("  ",$level)."<$key>".  "<![CDATA[$value]]></$key>\n";
        } else {
          $xml .= str_repeat("  ",$level).  "<$key>$value</$key>\n";
        }
      } else {
        $xml .= str_repeat("  ",$level).  "<$key></$key>\n";
      }
    }
  }
  if ($level==1) {
    $xml .= ( defined('XML_ROOT') ) ? "</".XML_ROOT.">\n" : "</array>\n";
  }
  return $xml;
}

/*
 * xmlfield
 */
function xmlfield($field, &$xmlrec, $skip_white=FALSE, $n=0) {
  global $xml_vals, $xml_tags;
  static $s_vals, $s_tags;
  static $rec_md5 = "";
  if (md5($xmlrec) != $rec_md5) {
    $rec_md5 = md5($xmlrec);
    xmlparse(str_replace("& ", "&amp; ", $xmlrec), $skip_white, TRUE);
    $s_vals = $xml_vals;
    $s_tags = $xml_tags;
  }
  $field = strtoupper($field);
  if (count($s_tags[$field]) < ($n + 1)) {
    return("");
  } else {
    $i = $s_tags[ $field ][ $n ];
    return(trim($s_vals[ $i ]["value"]));
  }
}

/*
 * cat_xmlfield
 */
function cat_xmlfield($fieldlist, &$xmlrec) {
  $field = explode(" ", $fieldlist);
  $ret = "";
  for ($i = 0; $i < count($field); $i++)
    if (substr($field[$i], 0, 1) == "<")
      $ret .= $field[$i];
    else
      $ret .= xmlfield($field[$i], $xmlrec);
  return($ret);
}

/*
 * xmlclip
 */
function xmlclip($field, &$xmlrec, $ignorecase=TRUE) {
  if ($ignorecase && ($st = stripos($xmlrec, "<$field>")) && ($sl = strripos($xmlrec, "</$field>")))
    return '<Wrapper>' . substr($xmlrec, $st, $sl - $st + strlen($field) + 3) . '</Wrapper>';
  elseif ($ignorecase && ($st = strpos($xmlrec, "<$field>")) && ($sl = strrpos($xmlrec, "</$field>")))
    return '<Wrapper>' . substr($xmlrec, $st, $sl - $st + strlen($field) + 3) . '</Wrapper>';
  else
    return("<$field></$field>");
}

/*
 * xmlpush
 */
function xmlpush($tag, $val, $cdata = FALSE) {
  if (isset($val))
    if ($cdata)
      return "<" . $tag . "><![CDATA[" . $val . "]]></" . $tag . ">";
    else
      return "<" . $tag . ">" . $val . "</" . $tag . ">";
  else
    return "";
}

/*
 *
 */
function get_array_value(&$arr, $tag, $empty_value="") {
  $ret = "";
  if (isset($arr[$tag]["value"])) 
    $ret = $arr[$tag]["value"];
  elseif (is_array($arr[$tag]))
    foreach ($arr[$tag] as $val)
      if (isset($val["value"])) 
        $ret .= " " . $val["value"];

  if ($ret == "") $ret = $empty_value;
  return trim($ret);
}


/*
 * Converts XML to struct.
 */
function xml2struct($xml_data) {
	$p = xml_parser_create();
	xml_parse_into_struct($p, $xml_data, $vals, $index);
	xml_parser_free($p);

	$return['index']=$index;
	$return['vals']=$vals;
	return $return;
}


/*
 * Extracts attributes or values from struct.
 */

function xmlstruct_extract(&$struct, $tagname, $results=array(), $target="attributes") {
  if(!is_array($struct['vals'])) {
	return FALSE;
  }

  foreach($struct['vals'] as $k=>$v) {
	
		if(is_array($v)) {
			if(isset($v["tag"]) && $v["tag"]==$tagname) {
		    $results[]=$v[$target];
		  }
		  xmlstruct_extract($v, $tagname, $results, $target);
		}
	}
	return $results;
}


?>
