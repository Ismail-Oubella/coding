<?php
    if(isset($_GET['fruit'])){
        echo "it seems that you chosed: ";
        foreach($_GET['fruit'] as $ele){
            echo "$ele ";
        }
    }
    else {
        echo"No fruits selected";
    }
?>