<?php

require_once("Car.php");
require_once("Account.php");
require_once("UberX.php");
require_once("UberPool.php");

$uberx = new UberX("GCJ767", new Account("David Lopez", "da946103"), "Chevrolet", "Spark");
$uberx->printDataCar();

$uberpool = new UberPool("FDE754", new Account("Carlos Diaz", "ca730284"), "Dodge", "Attitude");
$uberpool->printDataCar();