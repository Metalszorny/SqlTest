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
        $isDeletedValue = 0;
        $matchFound = false;
        $people = array();

        // Get the items from the People table.
        $query = oci_parse($connection, "SELECT * FROM root.People");
        
        // Execute.
        oci_execute($query);
                
        // Store the items in a Person list.
        while ($row = oci_fetch_assoc($query))
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
            if ($matchFound == false && $people[$i + 1 * (count($people) / 6)] == $nameValue && $people[$i + 2 * (count($people) / 6)] == $mothernameValue && 
                $people[$i + 3 * (count($people) / 6)] == $locationValue && $people[$i + 4 * (count($people) / 6)] == $birthdateValue && 
                $people[$i + 5 * (count($people) / 6)] == 1)
            {
                $matchFound = true;
                $idValue = $people[$i + 0 * (count($people) / 6)];
                        
                break;
            }
        }
                
        // Add a new item if no deleted was found else restore the deleted item.
        if ($matchFound == false)
        {
            $idValue += 1;
                    
            // Add new item to the People table.
            $query = oci_parse($connection, "INSERT INTO root.People (Id, Name, Mothername, Location, Birthdate, IsDeleted) VALUES ('$idValue', '$nameValue', '$mothernameValue', '$locationValue', '$birthdateValue' , '$isDeletedValue')");
        
            // Execute.
            oci_execute($query);
        }
        else
        {
            // Edit the IsDeleted value to false.
            $query = oci_parse($connection, "UPDATE root.People SET IsDeleted = '$isDeletedValue' WHERE Id = '$idValue'");
        
            // Execute.
            oci_execute($query);
        }
    }
?>