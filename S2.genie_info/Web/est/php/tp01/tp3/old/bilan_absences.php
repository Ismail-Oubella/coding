<?php
	// Connect to database
	$db = mysqli_connect('localhost', 'root', '', 'gestion_absences');
	if (!$db) {
		die("Connection failed: " . mysqli_connect_error());
	}

	// Get list of students with their absence hours
	$sql = "SELECT students.last_name, students.first_name, SUM(absences.hours) AS absence_hours 
			FROM students
			INNER JOIN absences ON students.id = absences.student_id
			GROUP BY students.id";
	$result = mysqli_query($db, $sql);

	// Display table of students with absence hours
	echo "<table>";
	echo "<thead><tr><th>Nom</th><th>Prénom</th><th>Heures d'absence</th></tr></thead>";
	echo "<tbody>";
	while ($row = mysqli_fetch_assoc($result)) {
		echo "<tr><td>" . $row['last_name'] . "</td><td>" . $row['first_name'] . "</td><td>" . $row['absence_hours'] . "</td></tr>";
	}
	echo "</tbody>";
	echo "</table>";

	// Close database connection
	mysqli_close($db);
?>
