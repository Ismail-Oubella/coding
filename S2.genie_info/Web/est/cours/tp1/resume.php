<?php
if(isset($_GET['submit'])){
    $students = array();

    $names = $_GET['name'];
    $ages = $_GET['age'];

    for($i=0; $i<count($names); $i++){
        $student = array("name"=>$names[$i], "age"=>$ages[$i]);
        array_push($students, $student);
    }
?>
    <table>
        <tr>
            <th>Name</th>
            <th>Age</th>
        </tr>
        <?php foreach($students as $student){ ?>
        <tr>
            <td><?php echo $student['name']; ?></td>
            <td><?php echo $student['age']; ?></td>
        </tr>
        <?php } ?>
    </table>
<?php } ?>
