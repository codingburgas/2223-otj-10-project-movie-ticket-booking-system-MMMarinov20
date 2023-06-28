DROP DATABASE IF EXISTS `tickets`;
CREATE DATABASE `tickets`;

USE `tickets`;
CREATE TABLE `tickets` (
    `uuid` VARCHAR(36) NOT NULL,
    `seat_number` INT NOT NULL,
    `purchase_date` DATE NOT NULL
);