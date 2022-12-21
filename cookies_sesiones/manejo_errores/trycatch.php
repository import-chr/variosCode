<?php

try {
    $resultado = 14 / 0;
} catch (Throwable $err) {
    echo $err->getMessage();
}

?>