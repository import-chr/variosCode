<?php
# require "main.php";
$palabras = array("sol", "luna", "nube", "planeta", "estrella");

for($i = 0; $i < count($palabras); $i++) {
    if($_REQUEST["palabra$i"] == $palabras[$i]) {
        echo "Palabra correcta<br>";
    } else {
        echo "Palabra incorrecta, la palabra es " . $palabras[$i] . "<br>";
    }
}
?>