<?
    include_once "../db_config.php";
    
    // An item must be selected.
    if (isset($_POST["id"]) && is_numeric($_POST["id"]) && $_POST["id"] > 0)
    {
        // Get the Id value of the selected item.
        $idValue = $_POST["id"];
        $isDeletedValue = true;
                
        // Edit the IsDeleted value to true.
        $query = odbc_exec($connection, "SELECT * FROM [MsSqlTestDatabase].[dbo].[Relationships] SET IsDeleted = '$isDeletedValue' WHERE Id = '$idValue'");
    }
?>