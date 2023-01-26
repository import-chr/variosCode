<?php

class YangException extends Exception {
    public function yangErr() {
        return "Mewo!";
    }
}

try {
    $t = readline("excepcion a lanzar: ");

    if($t == "yang") {
        throw new YangException("Mewo error");
    }
} catch (YangException $e) {
    echo $e->getMessage() . "\n";
    echo $e->yangErr() . "\n";
}


?>