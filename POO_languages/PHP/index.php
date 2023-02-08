<?php

require_once("Car.php");
require_once("Account.php");

$car0 = new Car("MFC277", new Account("Felipe Castellanos", "fe085903"));
$car0->printDataCar();