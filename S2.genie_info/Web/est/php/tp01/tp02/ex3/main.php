<!-- <?php

    if(!isset($_GET['number1']) or !isset($_GET['number2']) or empty($_GET['number1']) or empty($_GET['number2']))
    {
        echo "Please, Fill all the inputs in the prev page!";
    }

    else{
        $number1 = $_GET['number1'];
        $number2 = $_GET['number2'];
        $number3 = $_GET['number3'];
        $number4 = $_GET['number4'];
        $number5 = $_GET['number5'];
        $number6 = $_GET['number6'];
        $number7 = $_GET['number7'];
        $number8 = $_GET['number8'];
        $number9 = $_GET['number9'];

        $table=array($number1,$number2,
        $number3,$number4,
        $number5,$number6,
        $number7,$number8,
        $number9);

        $sum=0;
        foreach($table as $ele){$sum=$sum+$ele;}
        echo "sum of table is: $sum";
    }
?> -->


<?php

    if(!isset($_GET['number1']) or !isset($_GET['number2']) or empty($_GET['number1']) or empty($_GET['number2'])
        or !isset($_GET['number3']) or !isset($_GET['number4']) or empty($_GET['number3']) or empty($_GET['number4'])
        or !isset($_GET['number5']) or !isset($_GET['number6']) or empty($_GET['number5']) or empty($_GET['number6'])
        or !isset($_GET['number7']) or !isset($_GET['number8']) or empty($_GET['number7']) or empty($_GET['number8'])
        or !isset($_GET['number9']) or empty($_GET['number9'])
    ){
        echo "Please, Fill all the inputs in the prev page!";
    }

    else{
        $number1 = $_GET['number1'];
        $number2 = $_GET['number2'];
        $number3 = $_GET['number3'];
        $number4 = $_GET['number4'];
        $number5 = $_GET['number5'];
        $number6 = $_GET['number6'];
        $number7 = $_GET['number7'];
        $number8 = $_GET['number8'];
        $number9 = $_GET['number9'];

        $table=array($number1,$number2,
        $number3,$number4,
        $number5,$number6,
        $number7,$number8,
        $number9);

        $sum=0;
        foreach($table as $ele){$sum=$sum+$ele;}
        echo "sum of table is: $sum";
    }
?>