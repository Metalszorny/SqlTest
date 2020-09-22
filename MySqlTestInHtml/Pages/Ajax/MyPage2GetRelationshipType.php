<?
    include_once "../db_config.php";

    $name = "";
    $relationships = array();
    
    // An item must be selected.
    if (isset($_POST["id"]) && is_numeric($_POST["id"]) && $_POST["id"] > 0)
    {
        // Get the Id value of the selected item.
        $idValue = intval($_POST["id"]);
        
        // Get the items from the Relationships table.
        $query = mysql_query("SELECT * FROM MySqlTestDatabase.Relationships WHERE Id = '$idValue'");
                  
        // Store the items in a Relationship object.
        while ($row = mysql_fetch_assoc($query))
        {
            foreach ($row as $cell)
            {
                $relationships[] = $cell;
            }
        }
        
        // Set the return value.
        $name = $relationships[1];
    }

    echo $name;
?>