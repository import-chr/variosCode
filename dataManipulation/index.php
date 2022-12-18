<?php

require __DIR__ . "/vendor/autoload.php";

var_dump(App\Validate::email('mail@@domain.com'));

var_dump(App\Validate::url('https://google.com'));

var_dump(App\Validate::pass('01928374'));