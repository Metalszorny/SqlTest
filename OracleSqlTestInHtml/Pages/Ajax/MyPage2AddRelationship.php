<?
    include_once "../db_config.php";
    
    // The fields must not be empty.
    if (isset($_POST["name"]) && $_POST["name"] != "")
    {
        // Get the values of the selected item.
        $idValue = 0;
        $nameValue = $_POST["name"];
        $isDeletedValue = 0;
        $matchFound = false;
        $deletedFound = false;
        $relationships = array();
                
        // Get the items from the Relationships table.
        $query = oci_parse($connection, "SELECT * FROM root.Relationships");
        
        // Execute.
        oci_execute($query);
                
        // Store the items in a Relationship list.
        while ($row = oci_fetch_assoc($query))
        {
            foreach ($row as $cell)
            {
                $relationships[] = $cell;
            }
        }
        
        // Search in each item.
        for ($i = 0; $i < count($relationships) / 3; $i++)
        {
            $idValue += 1;
                    
            // Search for a matching item.
            if ($matchFound == false && $relationships[$i + 1 * (count($relationships) / 3)] == $nameValue && $relationships[$i + 2 * (count($relationships) / 3)] == 0)
            {
                $matchFound = true;
                        
                break;
            }
                    
            // Search for a deleted maching item.
            if ($deletedFound == false && $relationships[$i + 1 * (count($relationships) / 3)] == $nameValue && $relationships[$i + 2 * (count($relationships) / 3)] == 1)
            {
                $deletedFound = true;
                $idValue = $relationships[$i + 0 * (count($relationships) / 3)];
                        
                break;
            }
        }
                
        // If no match was found.
        if ($matchFound == false)
        {
            // Add a new item if no deleted was found else restore the deleted item.
            if ($deletedFound == false)
            {
                $idValue += 1;
                        
                // Add new item to the Relationships table.
                $query = oci_parse($connection, "INSERT INTO root.Relationships (Id, Name, IsDeleted) VALUES ('$idValue', '$nameValue', '$isDeletedValue')");
        
                // Execute.
                oci_execute($query);
            }
            else
            {
                // Edit the IsDeleted value to false.
                $query = oci_parse($connection, "UPDATE root.Relationships SET IsDeleted = '$isDeletedValue' WHERE Id = '$idValue'");
        
                // Execute.
                oci_execute($query);
            }
        }
    }
?>