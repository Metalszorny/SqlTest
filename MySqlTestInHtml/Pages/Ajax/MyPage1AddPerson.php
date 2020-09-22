<?
    include_once "../db_config.php";

    // The fields must not be empty.
    if (isset($_POST["name"]) && isset($_POST["mothername"]) && 
       isset($_POST["location"]) && isset($_POST["birthdate"]) && 
       $_POST["name"] != "" && $_POST["mothername"] != "" && 
       $_POST["location"] != "" && $_POST["birthdate"] != "")
    {
        // Get the values of the selected item.
        $idValue = 0;
        $nameValue = $_POST["name"];
        $mothernameValue = $_POST["mothername"];
        $locationValue = $_POST["location"];
        $birthdateValue = $_POST["birthdate"];
        $isDeletedValue = false;
        $matchFound = false;
        $people = array();

        // Get the items from the People table.
        $query = mysql_query("SELECT * FROM MySqlTestDatabase.People");
                
        // Store the items in a Person list.
        while ($row = mysql_fetch_assoc($query))
        {
            foreach ($row as $cell)
            {
                $people[] = $cell;
            }
        }
        
        // Search in each item.
        for ($i = 0; $i < count($people) / 6; $i++)
        {    
            $idValue += 1;

            // Search for a deleted maching item.
            if ($matchFound == false && $people[$i * 6 + 1] == $nameValue && $people[$i * 6 + 2] == $mothernameValue && 
                $people[$i * 6 + 3] == $locationValue && $people[$i * 6 + 4] == $birthdateValue && $people[$i * 6 + 5] == true)
            {
                $matchFound = true;
                $idValue = $people[$i * 6 + 0];
                        
                break;
            }
        }
                
        // Add a new item if no deleted was found else restore the deleted item.
        if ($matchFound == false)
        {
            $idValue += 1;
                    
            // Add new item to the People table.
            $query = mysql_query("INSERT INTO MySqlTestDatabase.People (Id, Name, Mothername, Location, Birthdate, IsDeleted) VALUES ('$idValue', '$nameValue', '$mothernameValue', '$locationValue', '$birthdateValue' , '$isDeletedValue')");
        }
        else
        {
            // Edit the IsDeleted value to false.
            $query = mysql_query("UPDATE MySqlTestDatabase.People SET IsDeleted = '$isDeletedValue' WHERE Id = '$idValue'");
        }
    }
?>