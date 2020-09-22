<?
    include_once "../db_config.php";
    
    // The fields must not be empty.
    if (isset($_POST["person1"]) && isset($_POST["relationship"]) && isset($_POST["person2"]) && 
        is_numeric($_POST["person1"]) && is_numeric($_POST["relationship"]) && is_numeric($_POST["person2"]) && 
        $_POST["person1"] > 0 && $_POST["relationship"] > 0 && $_POST["person2"] > 0 && 
        $_POST["person1"] != $_POST["person2"])
    {
        // Get the values of the selected item.
        $idValue = 0;
        $person1Value = $_POST["person1"];
        $relationshipValue = $_POST["relationship"];
        $person2Value = $_POST["person2"];
        $isDeletedValue = 0;
        $matchFound = false;
        $relations = array();
             
        // Get the items from the Relations table.
        $query = oci_parse($connection, "SELECT * FROM root.Relations");
        
        // Execute.
        oci_execute($query);
                
        // Store the items in a Relation list.
        while ($row = oci_fetch_assoc($query))
        {
            foreach ($row as $cell)
            {
                $relations[] = $cell;
            }
        }
        
        // Search in each item.
        for ($i = 0; $i < count($relations) / 5; $i++)
        {
            $idValue += 1;
                    
            // Search for a deleted maching item.
            if ($matchFound == false && $relations[$i + 1 * (count($relations) / 5)] == $person1Value && 
                $relations[$i + 2 * (count($relations) / 5)] == $relationshipValue && $relations[$i + 3 * (count($relations) / 5)] == $person2Value && 
                $relations[$i + 4 * (count($relations) / 5)] == 1)
            {
                $matchFound = true;
                $idValue = $relations[$i + 0 * (count($relations) / 5)];
                       
                break;
            }
        }
                
        // Add a new item if no deleted was found else restore the deleted item.
        if ($matchFound == false)
        {
            $idValue += 1;
                    
            // Add new item to the Relations table.
            $query = oci_parse($connection, "INSERT INTO root.Relations (Id, Person1, Relationship, Person2, IsDeleted) VALUES ('$idValue', '$person1Value', '$relationshipValue', '$person2Value', '$isDeletedValue')");
        
            // Execute.
            oci_execute($query);
        }
        else
        {
            // Edit the IsDeleted value to false.
            $query = oci_parse($connection, "UPDATE root.Relations SET IsDeleted = '$isDeletedValue' WHERE Id = '$idValue'");
        
            // Execute.
            oci_execute($query);
        }
    }
?>