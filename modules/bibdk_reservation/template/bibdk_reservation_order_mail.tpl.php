<div>
  <?php
  if (isset($IllOrderReceiptText)) :
    print $IllOrderReceiptText; print "\n\n";
  endif;

  print $headertext; print "\n\n";

  print $orderidtext; print " "; print $orderid;

  print "\n\n"; print $userparameter; print "\n\n";

  foreach ($userinfo as $list) :
    print $list; print "\n";
  endforeach;

  print "\n\n"; print $manifestation; print "\n\n";

  print $subtype . "\n";
  print $title . "\n";
  print $author . "\n";

  print "\n"; print $branch; print "\n";
  print "\n"; print $branchtext;
  print "\n"; print $addresstext;
  print "\n"; print $postalCodetext; print ' '; print $citytext;

  if (isset($orderinfo)) :
    print "\n\n"; print $orderparameters;print "\n\n";
    foreach ($orderinfo as $data) :
      print $data; print "\n";
    endforeach;
  endif;
  ?>
</div>
