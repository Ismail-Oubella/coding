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
        if(!isset($_POST['item'])){
            echo "There are no products available!";
            $_SESSION['cart'] = array();
        }
        else{
            $_SESSION['cart']=array_merge($_SESSION['cart'], $_POST['item']); 
            foreach($_SESSION['cart'] as $item){
                echo "<p>Product " . $item . " is chosen!</p> ";
            }
        }
    ?>
    <p>CHOOSE MORE ! <a href="store.php">Home</a></p>
</body>
</html>
