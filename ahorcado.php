<?php

function clear() {
    if(PHP_OS === "WINNT") {
        system("cls");
        popen("cls", "w");
    }
    else {
        system("clear");
    }
}

$possible_words = ["Bebida", "Prisma", "Ala", "Dolor", "Piloto", "Baldosa", "Terremoto", "Asteroide", "Gallo", "Platzi"];

define("MAX_ATTEMPS", 6);

echo "\n\nJuego del ahorcado\n\n";

$choosen_word = $possible_words[rand(0, 9)];
$choosen_word = strtolower($choosen_word);
$word_length = strlen($choosen_word);
$discovered_letters = str_pad("", $word_length, "_");
$attemps = 0;

do {
    echo "Palabra de $word_length letras\n\n";
    echo $discovered_letters . "\n\n";

    $player_letter = readline("Escribe una letra: ");
    $player_letter = strtolower($player_letter);

    if(str_contains($choosen_word, $player_letter)) {
        $offset = 0;

        while(($letter_pos = strpos($choosen_word, $player_letter, $offset)) !== false) {
            $discovered_letters[$letter_pos] = $player_letter;
            $offset = $letter_pos + 1;
        }
    }
    else {
        clear();

        $attemps++;

        echo "Letra incorrecta... " . (MAX_ATTEMPS - $attemps) . " intentos restantes";

        sleep(1);
    }

    clear();
} while($attemps < MAX_ATTEMPS && $discovered_letters != $choosen_word);

clear();

if($attemps < MAX_ATTEMPS)
    echo "Felicidades, ganaste el juego\n\n";
else
    echo "Suerte para la proxima...\n\n";

echo "La palabra correcta es: $choosen_word\n";
echo "Tu palabra es: $discovered_letters\n";