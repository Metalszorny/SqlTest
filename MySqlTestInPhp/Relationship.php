<?php

/**
 * Base class for Relationship.
 */
class Relationship
{
    //<editor-fold defaultstate="collapsed" desc="Fields">
	
    // The id field of the Relationship class.
    private $idField;
	
    // The name field of the Relationship class.
    private $nameField;
	
    // The isDeleted field of the Relationship class.
    private $isDeletedField;
	
    // </editor-fold>
	
    //<editor-fold defaultstate="collapsed" desc="Properties">
	
    /**
     * Gets the idField.
     *
     * @return The idField.
     */
    public function getId()
    {
        return $this->idField;
    }
	
    /**
     * Sets the idField.
     *
     * @param type value The id to set.
     */
    public function setId($value)
    {
        $this->idField = $value;
    }
	
    /**
     * Gets the nameField.
     *
     * @return The nameField.
     */
    public function getName()
    {
        return $this->nameField;
    }
	
    /**
     * Sets the nameField.
     *
     * @param type value The name to set.
     */
    public function setName($value)
    {
        $this->nameField = $value;
    }
	
    /**
     * Gets the isDeletedfield.
     *
     * @return The isDeletedField.
     */
    public function getIsDeleted()
    {
        return $this->isDeletedField;
    }
	
    /**
     * Sets the isDeletedField.
     *
     * @param type value The isdeleted to set.
     */
    public function setIsDeleted($value)
    {
        $this->isDeletedField = $value;
    }
	
    // </editor-fold>
    
    //<editor-fold defaultstate="collapsed" desc="Constructors">

    /**
     * Initializes a new instance of the Relationship class.
     *
     * @param type id The input value of the id field.
     * @param type name The input value of the name field.
     * @param type isdeleted The input value of the isDeleted field.
     */
    public function __construct($id, $name, $isdeleted)
    {
        $this->idField = $id;
        $this->nameField = $name;
        $this->isDeletedField = $isdeleted;
    }
	
    // </editor-fold>
	
    //<editor-fold defaultstate="collapsed" desc="Methods">
    
    // </editor-fold>
}

?>