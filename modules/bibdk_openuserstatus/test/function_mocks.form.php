<?php

function bibdk_openuserstatus_get_agencyname($agencyId) {
  $names = array(
    '100451' => 'name',
  );

  if (isset($names[$agencyId])) {
    return $names[$agencyId];
  }
  else {
    return '';
  }
}
