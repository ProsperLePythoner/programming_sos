<?php

$hostname = "localhost";
$username = "root";
$password = "";
$database = "school_db";

$connection = new mysqli($hostname, $username, $password, $database);

// Test the connection
if ($connection->connect_error) {
    die("Failed to connect to database!\n" . $connection->connect_error);
} else {
    echo "Connected to database successfully!";
}

// Retrieve the respective input values from the form
$student_name = $_POST["name"];
$reg_no = $_POST["regNumber"];
$gender = $_POST["gender"];
$age = (int) $_POST["age"];

// Prepare and execute the query
$sql = $connection->prepare(
    "INSERT INTO `students` VALUES (?, ?, ?, ?)"
);

$sql->bind_param("sssi", $student_name, $reg_no, $gender, $age);

if ($sql->execute()) {
    echo "Successfully inserted user into database `student_db`";
} else {
    echo "Could not execute query.";
}

?>