-- (a) Create the database 'school_db' and a table named 'students'
CREATE DATABASE school_db;
USE school_db;

CREATE TABLE students (
	student_id INT PRIMARY KEY,
    full_name VARCHAR(100),
    gender VARCHAR(10),
    age INT,
    combination VARCHAR(20)
);

-- (b) Enter data into the students table
INSERT INTO students VALUES
(1001, 'John Peter', 'Male', 18, 'PCM'),
(1002, 'Asha Juma', 'Female', 17, 'PCB'),
(1003, 'David Michael', 'Male', 19, 'CBG'),
(1004, 'Neema Joseph', 'Female', 18, 'PCM'),
(1005, 'Robert James', 'Male', 17, 'PCB'),
(1006, 'Mary Thomas', 'Female', 19, 'CBA'),
(1007, 'Kelvin George', 'Male', 18, 'PCM'),
(1008, 'Rehema Said', 'Female', 17, 'PCB');

-- i. Change John Peter's age to 19
UPDATE students SET age = 19 WHERE student_id = 1001;

-- ii. Change Kelvin George's Combination to PCB
UPDATE students SET combination = 'PCB' WHERE student_id = 1007;

-- iii. Delete the record of Robert James
DELETE FROM students WHERE full_name = 'Robert James';

-- iv. Display all students
SELECT * FROM students;

-- v. Display all students taking PCM
SELECT * FROM students WHERE combination = 'PCM';

-- vi. Display all students aged 18
SELECT * FROM students WHERE age = 18;

-- (c) Add field 'phone_number' to students table
ALTER TABLE students ADD phone_number VARCHAR(10) NOT NULL AFTER combination;

-- Enter the given phone numbers
UPDATE students SET phone_number = '0712345678' WHERE student_id = 1001;
UPDATE students SET phone_number = '0756789123' WHERE student_id = 1002;
UPDATE students SET phone_number = '0765432109' WHERE student_id = 1003;
UPDATE students SET phone_number = '0789123456' WHERE student_id = 1004;