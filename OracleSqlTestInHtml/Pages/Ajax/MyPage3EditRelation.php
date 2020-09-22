<?
    include_once "../db_config.php";
    
    // The fields must not be empty.
    if (isset($_POST["person1"]) && isset($_POST["relationship"]) && isset($_POST["person2"]) && 
        is_numeric($_POST["person1"]) && is_numeric($_POST["relationship"]) && is_numeric($_POST["person2"]) && 
        $_POST["person1"] > 0 && $_POST["relationship"] > 0 && $_POST["person2"] > 0 && 
        $_POST["person1"] != $_POST["person2"])
    {
        // An item must be selected.
        if (isset($_POST["id"]) && is_numeric($_POST["id"]) && $_POST["id"] > 0)
        {
            // Get the Id value of the selected item.
            $idValue = $_POST["id"];
            $person1Value = $_POST["person1"];
            $relationshipValue = $_POST["relationship"];
            $person2Value = $_POST["person2"];

            // Update the values in the Relations table.
            $query = oci_parse($connection, "UPDATE root.Relations SET Person1 = '$person1Value', Relationship = '$relationshipValue', Person2 = '$person2Value' WHERE Id = '$idValue'");
        
            // Execute.
            oci_execute($query);
        }
    }
?>