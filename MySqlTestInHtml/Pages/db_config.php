<?php
	$connection = mysql_connect("localhost", "root", "root");
    mysql_select_db("MySqlTestDatabase", $connection);
    mysql_query("SET CHARACTER SET 'utf8'");
    mysql_query("SET COLLATION_CONNECTION='ut8_hungarian_ci'");
?>