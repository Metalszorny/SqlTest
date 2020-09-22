<?
    include_once "../db_config.php";

    $name = "";
    $person = array();
    
    // An item must be selected.
    if (isset($_POST["id"]) && is_numeric($_POST["id"]) && $_POST["id"] > 0)
    {
        // Get the Id value of the selected item.
        $idValue = intval($_POST["id"]);
        
        // Get the items from the People table.
        $query = oci_parse($connection, "SELECT * FROM root.People WHERE Id = '$idValue'");
        
        // Execute.
        oci_execute($query);
                  
        // Store the items in a Person object.
        while ($row = oci_fetch_assoc($query))
        {
            foreach ($row as $cell)
            {
                $person[] = $cell;
            }
        }
        
        // Set the return value.
        $name = $person[1];
    }

    echo $name;
?>