<?php
    function create(){
        echo "Give Number of rows in array :";
        $rows=fgets(STDIN);
        echo "Give Number of columns in array :";
        $columns=fgets(STDIN);
        $table=array();
        for($i=0;i<$rows;$i++){
            $row=array();
            for($j=0;$j<$columns;$j++){
                echo "insert value into :";
                $value=fgets(STDIN);
                $row[]=$value;
            }
            $table[]=$row;
        }
        return $table;
    }
    function sum($table){
        $sum=0;
        foreach($table as $element){
            $sum+=$element;
        }
        return $sum;
    }

?>