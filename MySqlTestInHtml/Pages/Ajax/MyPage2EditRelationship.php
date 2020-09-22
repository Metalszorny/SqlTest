<?
    include_once "../db_config.php";
    
    // The fields must not be empty.
    if (isset($_POST["name"]) && $_POST["name"] != "")
    {
        // An item must be selected.
        if (isset($_POST["id"]) && is_numeric($_POST["id"]) && $_POST["id"] > 0)
        {
            // Get the values of the selected item.
            $idValue = $_POST["id"];
            $nameValue = $_POST["name"];

            // Update the values in the Relationships table.
            $query = mysql_query("UPDATE MySqlTestDatabase.Relationships SET Name = '$nameValue' WHERE Id = '$idValue'");
        }
    }
?>