<?php 
    $date_arr=getdate();
    echo date("D F y, H:i:s \n<br>");
    echo "Today is: " .$date_arr["weekday"];
?>