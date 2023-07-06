<?php
	function register_module($code, $name){
		$server="localhost";
		$username="root";
		$password="";
		$dbname="gi";

		$conn=mysqli_connect($server, $username, $password, $dbname);

		if(!$conn){
			die ("Connection filed: " . mysqli_connect_error());
		}

		$sql="CREATE TABLE IF NOT EXISTS modules(
			id_module INT(6) UNSIGNED AUTO_INCREMENT PRIMARY KEY,
			code_module VARCHAR(20) NOT NULL,
			name_module VARCHAR(20) NOT NULL
		)";

		if(mysqli_query($conn, $sql)){
			echo "Table created Succefely <br>";
		}
		else {
			echo "Error creating table: " .mysqli_error($conn) . "<br>";
		}

		
		$sql="INSERT INTO modules(code_module, name_module)
			  VALUES ('$code', '$name')";
		if(mysqli_query($conn, $sql)){
			echo "Data inserted succefuly<br>";
		}
		else {
			echo  "Error inserting data: ". mysqli_error($conn) . "<br>";
		}
		mysqli_close($conn);
	}

	if(isset($_POST['submit'])){
		$code=$_POST['id'];
		$name=$_POST['name'];

		register_module($code, $name);
		echo "Module registered successfully!";
	}
?>
