<?
    include_once "../db_config.php";
    
    // The fields must not be empty.
    if (isset($_POST["name"]) && $_POST["name"] != "")
    {
        // Get the values of the selected item.
        $idValue = 0;
        $nameValue = $_POST["name"];
        $isDeletedValue = false;
        $matchFound = false;
        $deletedFound = false;
        $relationships = array();
                
        // Get the items from the Relationships table.
        $query = mysql_query("SELECT * FROM MySqlTestDatabase.Relationships");
                
        // Store the items in a Relationship list.
        while ($row = mysql_fetch_assoc($query))
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
            if ($matchFound == false && $relationships[$i * 3 + 1] == $nameValue && $relationships[$i * 3 + 2] == false)
            {
                $matchFound = true;
                        
                break;
            }
                    
            // Search for a deleted maching item.
            if ($deletedFound == false && $relationships[$i * 3 + 1] == $nameValue && $relationships[$i * 3 + 2] == true)
            {
                $deletedFound = true;
                $idValue = $relationships[$i * 3 + 0];
                        
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
                $query = mysql_query("INSERT INTO MySqlTestDatabase.Relationships (Id, Name, IsDeleted) VALUES ('$idValue', '$nameValue', '$isDeletedValue')");
            }
            else
            {
                // Edit the IsDeleted value to false.
                $query = mysql_query("UPDATE MySqlTestDatabase.Relationships SET IsDeleted = '$isDeletedValue' WHERE Id = '$idValue'");
            }
        }
    }
?>