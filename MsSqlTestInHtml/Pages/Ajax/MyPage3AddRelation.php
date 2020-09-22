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
        $isDeletedValue = false;
        $matchFound = false;
        $relations = array();
             
        // Get the items from the Relations table.
        $query = odbc_exec($connection, "SELECT * FROM [MsSqlTestDatabase].[dbo].[Relations]");
                
        // Store the items in a Relation list.
        while ($row = odbc_fetch_row($query))
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
            if ($matchFound == false && $relations[$i * 5 + 1] == $person1Value && $relations[$i * 5 + 2] == $relationshipValue && 
               $relations[$i * 5 + 3] == $person2Value && $relations[$i * 5 + 4] == true)
            {
                $matchFound = true;
                $idValue = $relations[$i * 5 + 0];
                       
                break;
            }
        }
                
        // Add a new item if no deleted was found else restore the deleted item.
        if ($matchFound == false)
        {
            $idValue += 1;
                    
            // Add new item to the Relations table.
            $query = odbc_exec($connection, "INSERT INTO [MsSqlTestDatabase].[dbo].[Relationships] (Id, Person1, Relationship, Person2, IsDeleted) VALUES ('$idValue', '$person1Value', '$relationshipValue', '$person2Value', '$isDeletedValue')");
        }
        else
        {
            // Edit the IsDeleted value to false.
            $query = odbc_exec($connection, "UPDATE [MsSqlTestDatabase].[dbo].[Relationships] SET IsDeleted = '$isDeletedValue' WHERE Id = '$idValue'");
        }
    }
?>