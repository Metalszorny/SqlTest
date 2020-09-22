<?
    include_once "../db_config.php";

    $name = "";
    $relation = array();
    
    // An item must be selected.
    if (isset($_POST["id"]) && is_numeric($_POST["id"]) && $_POST["id"] > 0)
    {
        // Get the id.
        $idValue = intval($_POST["id"]);
        
        // Get the items from the Relations table.
        $query = oci_parse($connection, "SELECT * FROM root.Relations WHERE Id = '$idValue'");
        
        // Execute.
        oci_execute($query);
                  
        // Store the items in a Relation object.
        while ($row = oci_fetch_assoc($query))
        {
            foreach ($row as $cell)
            {
                $relation[] = $cell;
            }
        }
        
        // Set the return value.
        $name = $relation[3];
    }

    echo $name;
?>