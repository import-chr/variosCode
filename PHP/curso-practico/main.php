<?php
$palabras = array("sol", "luna", "nube", "planeta", "estrella");

$form = "<form action = 'evaluador.php'>";

for($i = 0; $i < count($palabras); $i++) {
    $form .= str_shuffle($palabras[$i]) . "<input type = 'text' name = 'palabra$i'> <br>";
}

$button = "<button type = 'submit'>Enviar</button>";
$endForm = "</form>";

echo $form.$button.$endForm;
?>