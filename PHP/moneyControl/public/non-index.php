<?php

use App\Controllers\IncomesControllers;
use App\Controllers\WithdrawalsControllers;
use App\Enums\IncomeTypeEnum;
use App\Enums\PaymentMethodEnum;
use App\Enums\WithdrawalTypeEnum;

require("../vendor/autoload.php");

$incomes_controller = new IncomesControllers();
$incomes_controller->store([
    "payment_method" => PaymentMethodEnum::BacnkAccount->value,
    "type" => IncomeTypeEnum::Salary->value,
    "date" => date("Y-m-d H:i:s"),
    "amount" => 990,
    "description" => "pago salarial"
]);

/*
$incomes_controller = new IncomesControllers();
$incomes_controller->index();
*/

/*
$incomes_controller = new IncomesControllers();
$incomes_controller->destroy(1);
*/

/*
$withdrawal_controller = new WithdrawalsControllers();
$withdrawal_controller->store([
    "payment_method" => PaymentMethodEnum::CreditCard->value,
    "type" => WithdrawalTypeEnum::Purchase->value,
    "date" => date("Y-m-d H:i:s"),
    "amount" => 20,
    "description" => "Compra en línea"
]);
*/

/*
$withdrawal_controller = new WithdrawalsControllers();
$withdrawal_controller->index();
*/

/*
$withdrawal_controller = new WithdrawalsControllers();
$withdrawal_controller->show(1);
*/