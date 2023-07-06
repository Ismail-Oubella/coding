<?php
    session_start();
    ?>
<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8">
        <meta http-equiv="X-UA-Compatible" content="IE=edge">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <title>Products</title>
    </head>
    <body>
        <h1>Products</h1>
        <?php
        if(!isset($_SESSIO['item'])){
            $_SESSION['item'] = array();
        }
        if(isset($_POST['item'])){
            $_SESSION['item']=array_merge($_SESSION['item'], $_POST['item']); 
            foreach($_SESSION['item'] as $item){
                echo "<p>Product " . $item . " is chosen!</p>";
            }
        }
        else{
            echo "There are no products available!";
        }
        ?>
    <p>CHOOSE MORE ! <a href="store.php">Home</a></p>
    <p>End Order! <a href="end.php">Home</a></p>
</body>
</html>