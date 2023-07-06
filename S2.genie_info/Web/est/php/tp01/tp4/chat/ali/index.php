<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Store</title>
    <style>
        h1 {
            color: tomato;
        }

        form {
            margin-top: 20px;
        }

        label {
            display: block;
            margin-bottom: 10px;
            color: tomato;
            font-size: 16px;
        }

        input[type="checkbox"] {
            appearance: none;
            -webkit-appearance: none;
            -moz-appearance: none;
            width: 20px;
            height: 20px;
            border: 2px solid tomato;
            border-radius: 4px;
            outline: none;
            margin-right: 5px;
        }

        input[type="checkbox"]:checked {
            background-color: tomato;
        }

        input[type="checkbox"]:checked::after {
            content: '\2713';
            font-size: 14px;
            color: white;
            position: relative;
            top: -2px;
            left: 4px;
        }

        input[type="submit"] {
            margin-top: 10px;
            background-color: tomato;
            color: white;
            border: none;
            border-radius: 4px;
            padding: 10px 15px;
            font-size: 16px;
            cursor: pointer;
        }

        .price {
            color: tomato;
            font-size: 14px;
            margin-left: 10px;
        }
    </style>
</head>
<body>
    <h1>Store</h1>
    <form action="cart.php" method="post">
        <label for="item1">
            <input type="checkbox" name="item[]" id="item1" value="book 1">
            book 1
            <span class="price">$10.99</span>
        </label>
        <label for="item2">
            <input type="checkbox" name="item[]" id="item2" value="book 2">
            book 2
            <span class="price">$12.99</span>
        </label>
        <label for="item3">
            <input type="checkbox" name="item[]" id="item3" value="book 3">
            book 3
            <span class="price">$8.99</span>
        </label>
        <label for="item4">
            <input type="checkbox" name="item[]" id="item4" value="book 4">
            book 4
            <span class="price">$9.99</span>
        </label>
        <input type="submit" value="Submit">
    </form>
</body>
</html>