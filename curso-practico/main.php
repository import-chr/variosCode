<?php
$palabras = array("sol", "luna", "nube");
$letras = array();

for($i = 0; $i < 3; $i++) {
    $letras[$i] = str_shuffle($palabras[$i]);
}

print_r($letras);

echo "
<form action='evaluador.php'>
    <input type='text' name='palabra0'/>
    <input type='text' name='palabra1'/>
    <input type='text' name='palabra2'/>
    <button type='submit'>Enviar</button>
</form>
";
?>