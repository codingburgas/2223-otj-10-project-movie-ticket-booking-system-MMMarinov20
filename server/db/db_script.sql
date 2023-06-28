DROP DATABASE IF EXISTS `tickets`;
CREATE DATABASE `tickets`;

USE `tickets`;
CREATE TABLE `tickets` (
    `uuid` VARCHAR(36) NOT NULL,
    `seat_number` INT NOT NULL,
    `movie_name` VARCHAR(255) NOT NULL,
    `movie_time` VARCHAR(255) NOT NULL,
    `purchase_date` DATE NOT NULL
);