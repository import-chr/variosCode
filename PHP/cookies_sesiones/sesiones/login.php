<?php

session_start();

$users = [
    array(
        "username" => "Chrlr",
        "email" => "chrlr@domain.com"
    ),
    
    array(
        "username" => "NewU",
        "email" => "nuser@domain.com"
    )
];

$user = $_GET["user"] ?? "";

$_SESSION["id"] = $user;
$_SESSION["username"] = $users[$user]["username"];
$_SESSION["email"] = $users[$user]["email"];

?>