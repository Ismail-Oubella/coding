<?php
// Connexion à la base de données
$host = 'localhost';
$dbname = 'gestion_absences';
$username = 'root';
$password = '';
$options = array(PDO::MYSQL_ATTR_INIT_COMMAND => 'SET NAMES utf8');

$dbh = new PDO("mysql:host=$host;dbname=$dbname", $username, $password, $options);

// Récupération de la liste des étudiants pour le module sélectionné
$module_id = $_POST['module_id'];

$sql = "SELECT * FROM students WHERE module_id = :module_id";
$stmt = $dbh->prepare($sql);
$stmt->execute(array('module_id' => $module_id));
$students = $stmt->fetchAll(PDO::FETCH_ASSOC);

// Calcul du nombre d'heures d'absence pour chaque étudiant
foreach ($students as &$student) {
	$sql = "SELECT SUM(absence_hours) as total_hours FROM absences WHERE student_id = :student_id";
	$stmt = $dbh->prepare($sql);
	$stmt->execute(array('student_id' => $student['id']));
	$result = $stmt->fetch(PDO::FETCH_ASSOC);
	$student['absence_hours'] = $result['total_hours'];
}
unset($student);

// Affichage des résultats
include('header.php');

echo '<h2>Liste des étudiants pour le module sélectionné</h2>';
echo '<table>';
echo '<thead>';
echo '<tr><th>Nom</th><th>Prénom</th><th>Heures d\'absence</th></tr>';
echo '</thead>';
echo '<tbody>';
foreach ($students as $student) {
	echo '<tr><td>' . $student['last_name'] . '</td><td>' . $student['first_name'] . '</td><td>' . $student['absence_hours'] . '</td></tr>';
}
echo '</tbody>';
echo '</table>';

include('footer.php');
?>