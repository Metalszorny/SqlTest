<?
    include_once "../db_config.php";

    // The fields must not be empty.
    if (isset($_POST["name"]) && isset($_POST["mothername"]) && 
        isset($_POST["location"]) && isset($_POST["birthdate"]) && 
        $_POST["name"] != "" && $_POST["mothername"] != "" && 
        $_POST["location"] != "" && $_POST["birthdate"] != "")
    {
        // An item must be selected.
        if (isset($_POST["id"]) && is_numeric($_POST["id"]) && $_POST["id"] > 0)
        {
            // Get the values of the selected item.
            $idValue = $_POST["id"];
            $nameValue = $_POST["name"];
            $mothernameValue = $_POST["mothername"];
            $locationValue = $_POST["location"];
            $birthdateValue = $_POST["birthdate"];

            // Update the values in the People table.
            $query = mysql_query("UPDATE MySqlTestDatabase.People SET Name = '$nameValue', Mothername = '$mothernameValue', Location = '$locationValue', Birthdate = '$birthdateValue' WHERE Id = '$idValue'");
        }
    }
?>