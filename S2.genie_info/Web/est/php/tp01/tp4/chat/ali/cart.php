<?php
    session_start();

    $productPrices = [
        'book 1' => 10.99,
        'book 2' => 12.99,
        'book 3' => 8.99,
        'book 4' => 9.99
    ];

    if (!isset($_SESSION['item_count'])) {
        $_SESSION['item_count'] = array();
    }

    if (isset($_POST['item'])) {
        foreach ($_POST['item'] as $item) {
            if (isset($_SESSION['item_count'][$item])) {
                $_SESSION['item_count'][$item]++;
            } else {
                $_SESSION['item_count'][$item] = 1;
            }
        }
    }
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Cart</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            background-color: #f2f2f2;
            margin: 0;
            padding: 20px;
        }

        h1 {
            color: tomato;
            margin-bottom: 20px;
        }

        p {
            color: tomato;
            margin: 10px 0;
        }

        .cart-container {
            background-color: #fff;
            padding: 20px;
            border-radius: 5px;
            box-shadow: 0 2px 5px rgba(0, 0, 0, 0.1);
        }

        .total-price {
            margin-top: 20px;
            font-weight: bold;
        }

        .btn-back {
            background-color: tomato;
            color: #fff;
            border: none;
            border-radius: 4px;
            padding: 10px 15px;
            font-size: 16px;
            cursor: pointer;
        }

        .btn-back:hover {
            background-color: #ff6347;
        }
    </style>
</head>
<body>
    <div class="cart-container">
        <h1>Cart</h1>
        <?php
            if (empty($_SESSION['item_count'])) {
                echo "<p>There are no products in the cart!</p>";
            } else {
                $totalPrice = 0;

                foreach ($_SESSION['item_count'] as $item => $count) {
                    $price = $productPrices[$item];
                    $subtotal = $price * $count;
                    $totalPrice += $subtotal;

                    echo "<p>Product $item is chosen $count times. Subtotal: $subtotal USD (Price: $price USD)</p>";
                }

                echo "<p class='total-price'>Total Price: $totalPrice USD</p>";
            }
        ?>
        <button class="btn-back" onclick="window.location.href='index.php'">Back to Store</button>
    </div>
</body>
</html>