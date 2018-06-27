<?php
$input = file_get_contents('php://input');
$request_xml = simplexml_load_string($input);

$good_request = '<?xml version="1.0"?>
<placeCopyRequest xmlns="http://statsbiblioteket.dk/xws/elba-placecopyrequest-schema">
<ws_user>TEST_USER</ws_user>
<ws_password>TEST_PASS</ws_password>
<pid>870971-tsart:36023422</pid>
<user_loaner_id>123412341234</user_loaner_id>
<userName>Test Testersen</userName>
<userMail>test@dbc.dk</userMail>
<user_interest_date>2020-02-02</user_interest_date>
<pickupAgencyId>790900</pickupAgencyId>
<agencyId>790900</agencyId>
</placeCopyRequest>';
$good_xml = simplexml_load_string($good_request);


if ($request_xml->asXML() === $good_xml->asXML()) {
  header("HTTP/1.0 204 No Content");
}
else {
  header("HTTP/1.0 400 Bad Request");
}
