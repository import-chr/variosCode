<?php
$palabras = array("sol", "luna", "nube");

print_r($_REQUEST);

if($_REQUEST["palabra0"] == $palabras[0]) {
    echo "Palabra corecta";
} else {
    echo "Palabra incorrecta, la palabra corracta es " . $palabras[0];
}

if($_REQUEST["palabra1"] == $palabras[1]) {
    echo "Palabra corecta";
} else {
    echo "Palabra incorrecta, la palabra corracta es " . $palabras[1];
}

if($_REQUEST["palabra2"] == $palabras[2]) {
    echo "Palabra corecta";
} else {
    echo "Palabra incorrecta, la palabra corracta es " . $palabras[2];
}
?>