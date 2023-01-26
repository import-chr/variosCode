<?php
/*
## ESTRUCTURADO

$interval = date_interval_create_from_date_string("3 days");
$date = date_create();
date_add($date, $interval);

echo date_format($date, "d-m-Y");

*/

/*
## POO
*/
$interval = DateInterval::createFromDateString("3 days");
$date = new DateTime();
$date->add($interval);

echo $date->format("d-m-Y");