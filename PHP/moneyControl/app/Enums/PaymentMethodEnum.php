<?php

namespace App\Enums;

enum PaymentMethodEnum: int {
    case CreditCard = 1;
    case BacnkAccount = 2;
}