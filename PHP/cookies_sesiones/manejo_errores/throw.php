<?php

try {
    $pet = readline("Que mascota buscas: ");

    if($pet != "yang" && $pet != "conejo")
        throw new Exception("$pet no esta disponible en esta petstore");
    
    echo "felicidades tienes un $pet";
} catch (\Throwable $th) {
    //throw $th;
    echo $th->getMessage();
}

?>