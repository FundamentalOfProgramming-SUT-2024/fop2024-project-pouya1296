CREATE DATABASE userdatabase;
USE userdatabase;

CREATE TABLE users (
    id INT AUTO_INCREMENT PRIMARY KEY,
    username VARCHAR(100),
    password VARCHAR(100),
    email VARCHAR(100),
    question VARCHAR(100),
    answer VARCHAR(100)
);
