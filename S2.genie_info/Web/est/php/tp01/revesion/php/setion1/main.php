<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <?php
        $name='ismail';
        echo "Hello, World!... I mean $name <br>";
        $a="10";
        $b=5;
        echo "result of the addition operation is: " .$ismail + $a + $b . "<br>";

        $gender='male';

        switch($gender){
            case "male": echo "Bonjour Mr...<br>";
            break;
            case "female": echo "Bonjour Miss...<br>";
            break;
            default: echo "what the fuck are you...!<br>";
        }

        $tab=array(1, "true", 3.5);
        for($i=0; $i < sizeof($tab); $i++){
            echo "tab[$i]: " . $tab[$i] . "<br>";
        }

        $tab[]=10;
        $tab[]="false";

        for($i=0; $i < sizeof($tab); $i++){
            echo "tab[$i]: " . $tab[$i] . "<br>";
        }
    
        $tab[10]="item number 10";

        for($i=0; $i < 11; $i++){
            echo "tab[$i]: " . $tab[$i] . "<br>";
        }
        
        $i=0;
        foreach($tab as $element){
            echo "tab[$i]: " . $element . "<br>";
            $i++;
        }
        
        echo"<br><br><br><br><br><br>";

        $tab5['un']= 12 ;
        $tab5['trois'] = "fraise" ;
        $tab5["deux"] = 2.5 ;
        $tab5[42]= "el5" ;

        foreach($tab5 as $cle => $ele){
            echo "value[$cle]: " . $ele . "<br>";
        }

        $a=84;
        $c=&$a;

        echo"\$c = $c";
        unset($c);
    ?>
</body>
</html>