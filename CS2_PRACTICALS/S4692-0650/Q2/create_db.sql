CREATE DATABASE student_db;

USE student_db;

CREATE TABLE students(
  student_id INT PRIMARY KEY AUTO_INCREMENT,
  name VARCHAR(100),
  reg_no VARCHAR(30),
  gender VARCHAR(10),
  age INT
);