<?php

function register_student($first_name, $last_name, $email, $mod1, $mod2, $mod3, $mod4){

    $server = "localhost";
    $username = "root";
    $password = "";
    $dbname = "gi";
    
    // Create connection
    $conn = mysqli_connect($server, $username, $password, $dbname);
    
    // Check connection
    if (!$conn) {
        die("Connection failed: " . mysqli_connect_error());
    }
    
    //? Create database if it doesn't exist
    // $sql = "CREATE DATABASE IF NOT E	XISTS $dbname";
    // if (mysqli_query($conn, $sql)) {
    //     echo "Database created successfully<br>";
    // } else {
    //     echo "Error creating database: " . mysqli_error($conn) . "<br>";
    // }
    
    //? Select database
    // mysqli_select_db($conn, $dbname);
    
    // Create table if it doesn't exist
    $sql = "CREATE TABLE IF NOT EXISTS students (
        id INT(6) UNSIGNED AUTO_INCREMENT PRIMARY KEY,
        first_name VARCHAR(20) NOT NULL,
        last_name VARCHAR(20) NOT NULL,
        email VARCHAR(50) NOT NULL ,
        nbab_mod1 INT(6) UNSIGNED  NOT NULL,
        nbab_mod2 INT(6) UNSIGNED  NOT NULL,
        nbab_mod3 INT(6) UNSIGNED  NOT NULL,
        nbab_mod4 INT(6) UNSIGNED  NOT NULL,
    )";
    if (mysqli_query($conn, $sql)) {
        echo "Table created successfully<br>";
    } else {
        echo "Error creating table: " . mysqli_error($conn) . "<br>";
    }
    
    // Insert data
    $sql = "INSERT INTO students (first_name, last_name, email)
            VALUES ('$first_name', '$last_name', '$email', '$mod1', '$mod2', '$mod3', '$mod4')";
    if (mysqli_query($conn, $sql)) {
        echo "Data inserted successfully<br>";
    } else {
        echo "Error inserting data: " . mysqli_error($conn) . "<br>";
    }
    
    // Close connection
    mysqli_close($conn);
}

if (isset($_POST['submit'])) {
    $first_name = $_POST['first_name'];
    $last_name = $_POST['last_name'];
    $email = $_POST['email'];
    $modules=$_POST['module'];
    
    register_student($first_name, $last_name, $email, 0, 0, 0, 0);
    echo "Student registered successfully!";
}
?>