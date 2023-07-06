<?php
    session_start();
    if(!isset($_SESSION['etudiant'])){
        $_SESSION['etudiant']=array();
    }
    if(isset($_POST['first_name']) && isset($_POST['last_name'])){
        $newarr=array('first'=>$_POST['first_name'], 'last'=>$_POST['last_name']);
        array_push($_SESSION['etudiant'], $newarr);
    }
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <h3>Liste des etudiants</h3>
    <?php
        echo "<table>";
        echo "</table>";            
    ?>
    </table>
</body>
</html>