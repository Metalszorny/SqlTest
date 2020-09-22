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
        $query = odbc_exec($connection, "SELECT * FROM [MsSqlTestDatabase].[dbo].[People] WHERE Id = '$idValue'");
                  
        // Store the items in a Person object.
        while ($row = odbc_fetch_row($query))
        {
            foreach ($row as $cell)
            {
                $person[] = $cell;
            }
        }
        
        // Set the return value.
        $name = $person[2];
    }

    echo $name;
?>