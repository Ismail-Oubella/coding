<!DOCTYPE html>
<html>
<head>
	<title>Bilan d'absence</title>
	<link rel="stylesheet" type="text/css" href="style.css">
</head>
<body>
	<header>
		<h1>Gestion d'absence</h1>
	</header>
	<nav>
		<ul>
			<li><a href="index.html">Main Page</a></li>
			<li><a href="inscription_etudiant.php">Inscription des etudiants</a></li>
			<li><a href="inscription_module.html">Inscription des modules</a></li>
			<li><a href="liste_etudiants_par_module.php">Liste des etudiants par module</a></li>
		</ul>
	</nav>
	<main>
		<h2>Bilan d'absence</h2>
		<?php
			$server="localhost";
			$username="root";
			$password="";
			$dbnmae="gi";

			$conn=mysqli_connect($server, $username, $password, $dbnmae);

			if(!$conn){
				die ("Connection fieled: " . mysqlli_connect_error());
			}
			
			$sql="SELECT id, first_name, last_name, email from students";

			$result=mysqli_query($conn, $sql);

			if(mysqli_num_rows($result)>0){
				echo"<table>";
				echo"<tr><th>Id</th><th>First Name</th><th>Last Name</th><th>Email</th></tr>";
				
				while($row=mysqli_fetch_assoc($result)){
					echo "<tr><td>" . $row["id"]."</td><td>" . $row["first_name"]."</td><td>" . $row["last_name"]."</td><td>" . $row["email"]."</td></tr>";
				}
				echo"</table>";
			}

			else {
   			 	echo "0 results";
			}

			mysqli_close($conn);

		?>	
	</main>
</body>
</html>
