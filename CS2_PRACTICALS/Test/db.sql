-- Active: 1790945948643@@127.0.0.1@3306@school_users
CREATE DATABASE school_users;

USE school_users;

CREATE TABLE register(
    firstname VARCHAR(100),
    lastname VARCHAR(100),
    age INT,
    email VARCHAR(100),
    passwordhash VARCHAR(200),
    gender VARCHAR(10),
    hobby varchar(100),
    incomeSource VARCHAR(50),
    income FLOAT,
    bio TEXT
);

CREATE TABLE login(
    email VARCHAR(100),
    passwordhash VARCHAR(200)
);