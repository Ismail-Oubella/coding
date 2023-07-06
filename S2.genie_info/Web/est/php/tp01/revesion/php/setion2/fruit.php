<!DOCTYPE html>
<html>
<head>
	<title>Selected Fruits</title>
</head>
<body>
	<?php
	if (isset($_GET['submit'])) {
		if (isset($_GET['fruits'])) {
			echo "<p>You have selected the following fruits:</p>";
			echo "<ul>";
			foreach ($_GET['fruits'] as $fruit) {
				echo "<li>$fruit</li>";
			}
			echo "</ul>";
		} else {
			echo "<p>No fruits were selected.</p>";
		}
	}
	?>
</body>
</html>
