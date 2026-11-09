<?php

$server = 'localhost';
$username = 'root';
$password = '';
$database = 'school_users';

$conn = new mysqli($server, $username, $password, $database);

if (!$conn) {
    die("Couldn't connect to database!");
} else {
    echo "Connected successfully!";
}

?>