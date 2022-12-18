<?php

#EXPRESIONES REGULARES
/*
/:  CONTENEDOR
^: INICIO
$: FINAL
-: RANGO
[]: PATRÓN 
{}: CONDICIÓN
*/

$pass = '123456';

echo preg_match('/^[0-9]{6,9}$/', $pass);