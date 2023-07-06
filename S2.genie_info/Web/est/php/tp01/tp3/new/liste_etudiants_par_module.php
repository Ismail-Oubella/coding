<!DOCTYPE html>
<html>
<head>
	<title>Liste des étudiants par module</title>
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
			<li><a href="bilan_absence.php">Bilan d'absence</a></li>
		</ul>
	</nav>
	<main>
		<h2>Liste des étudiants par module</h2>
		<form method="post" action="">
			<label for="module">Sélectionnez un module :</label>
			<select name="module" id="module">
				<?php
					// Connexion à la base de données
					$server="localhost";
					$username="root";
					$password="";
					$dbnmae="gi";

					$conn=mysqli_connect($server, $username, $password, $dbnmae);

					if(!$conn){
						die ("Connection fieled: " . mysqlli_connect_error());
					}

					// Récupération de la liste des modules
					$sql="SELECT name_module from modules";

					$result=mysqli_query($conn, $sql);

					// Affichage de la liste déroulante des modules
					if(mysqli_num_rows($result) > 0){
						while($row=mysqli_fetch_assoc($result)){
							echo"<option>" .$row["name_module"] . "</option>";
						}
					}
					// Fermeture de la requête
					mysqli_close($conn);
				?>
			</select>
			<input type="submit" value="Afficher">
		</form>
		<?php

		?>
	</main>
	<footer>
		<p>Réalisé par [votre nom]</p>
	</footer>
</body>
</html>
