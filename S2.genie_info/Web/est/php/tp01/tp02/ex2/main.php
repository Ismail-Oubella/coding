<?php
    if (!isset($_GET['name']) or !isset($_GET['age']) or empty($_GET['name']) or empty($_GET['age'])){
        echo "Please, Fill all the inputs in the prev page!";
    }
    else{ if ($_GET['age'] < 18){
        echo "Sorry, You cannot use this WebSite!";
    }
    else{
        echo "Welcome, ". $_GET['name'];
    }}
?>