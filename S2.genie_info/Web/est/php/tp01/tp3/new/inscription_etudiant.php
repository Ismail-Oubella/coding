<!DOCTYPE html>
<html>
<head>
	<title>Inscription des étudiants</title>
	<link rel="stylesheet" type="text/css" href="style.css">
	<style>
		select {
			width: 164px;
    		padding: 10px;
    		margin-bottom: 20px;
    		box-sizing: border-box;
			display: block;
		}
		#email{
			width: 100%;
			padding: 10px;
			margin-bottom: 20px;
			box-sizing: border-box;	
		}
	</style>
</head>
<body>
	<header>
		<h1>Gestion d'absence</h1>
	</header>
	<nav>
		<ul>
			<li><a href="index.html">Main Page</a></li>
			<li><a href="inscription_module.html">Inscription des modules</a></li>
			<li><a href="liste_etudiants_par_module.php">Liste des etudiants par module</a></li>
			<li><a href="bilan_absence.php">Bilan d'absence</a></li>
		</ul>
	</nav>
	<main>
		<h2>Inscription des etudiants</h2>
		<form action="enregistrer_etudiant.php" method="post">
			<label for="last_name">Nom :</label>
			<input type="text" id="last_name" name="last_name" required>
			<label for="first_name">Prenom :</label>
			<input type="text" id="first_name" name="first_name" required>
			<label for="email">Email :</label>
			<input type="email" id="email" name="email"  required>
			<label >Choose Modules :</label>
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
							echo"<option name=".$row["name_module"] .">" .$row["name_module"] . "</option>";
						}
					}
					// Fermeture de la requête
					mysqli_close($conn);
				?>
			</select>

			<input type="submit" value="submit" name="submit">
		</form>
	</main>
</body>
</html>
