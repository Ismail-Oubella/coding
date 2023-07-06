<?php
    if( !isset($_GET['city']) or empty($_GET['city']) or 
        !isset($_GET['type']) or empty($_GET['type']) or
        !isset($_GET['distance']) or empty($_GET['distance'])
    ){
        echo "Not enough Data!";
    }
    else{
        $distance=$_GET['distance'];
        $city=$_GET['city'];
        $type=$_GET['type'];    
        switch($type){
            case "Voiture" :            
                $time=$distance/60;
                break;
            case "Bus" :            
                $time=$distance/50;
                break;
            case "Voiture" :            
                $time=$distance/80;
                break;
            default: $time=null;
        }
        echo "time needed to make this is : $time hours";
    }
?>