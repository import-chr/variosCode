CREATE DATABASE `transactions`
    CHARACTER SET = 'utf8mb4'
    COLLATE = 'utf8mb4_unicode_ci';

USE `transactions`;

CREATE TABLE `withdrawals` (
    `id` BIGINT UNSIGNED NOT NULL AUTO_INCREMENT,
    `payment_method` TINYINT(1) NOT NULL,
    `type` TINYINT(1) NOT NULL,
    `date` TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP,
    `amount` FLOAT NOT NULL,
    `description` TEXT NOT NULL,

    PRIMARY KEY (`id`)
)
DEFAULT CHARSET=utf8mb4
COLLATE=utf8mb4_unicode_ci;


CREATE TABLE `incomes` (
    `id` BIGINT UNSIGNED NOT NULL AUTO_INCREMENT,
    `payment_method` TINYINT(1) NOT NULL,
    `type` TINYINT(1) NOT NULL,
    `date` TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP,
    `amount` FLOAT NOT NULL,
    `description` TEXT NOT NULL,

    PRIMARY KEY (`id`)
)
DEFAULT CHARSET=utf8mb4
COLLATE=utf8mb4_unicode_ci;