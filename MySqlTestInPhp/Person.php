<?php

/**
 * Base class for Person.
 */
class Person
{
    //<editor-fold defaultstate="collapsed" desc="Fields">
	
    // The id field of the Person class.
    private $idField;
	
    // The name field of the Person class.
    private $nameField;
	
    // The mothername field of the Person class.
    private $mothernameField;
	
    // The location field of the Person class.
    private $locationField;
	
    // The birthdate field of the Person class.
    private $birthdateField;
	
    // The isDeleted field of the Person class.
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
     * Gets the mothernameField.
     * 
     * @return The mothernameField.
     */
    public function getMothername()
    {
        return $this->mothernameField;
    }

    /**
     * Sets the mothernameField.
     * 
     * @param type value The mothername to set.
     */
    public function setMothername($value)
    {
        $this->mothernameField = $value;
    }

    /**
     * Gets the locationField.
     * 
     * @return The locationField.
     */
    public function getLocation()
    {
        return $this->locationField;
    }

    /**
     * Sets the locationField.
     * 
     * @param type value The location to set.
     */
    public function setLocation($value)
    {
        $this->locationField = $value;
    }

    /**
     * Gets the birthdateField.
     * 
     * @return The birthdateField.
     */
    public function getBirthdate()
    {
        return $this->birthdateField;
    }

    /**
     * Sets the birthdateField.
     * 
     * @param type value The birthdate to set.
     */
    public function setBirthdate($value)
    {
        $this->birthdateField = $value;
    }

    /**
     * Gets the isDeletedField.
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
     * @param type value The isDeleted to set.
     */
    public function setIsDeleted($value)
    {
        $this->isDeletedField = $value;
    }
	
    // </editor-fold>
	
    //<editor-fold defaultstate="collapsed" desc="Constructors">

    /**
     * Initializes a new instance of the Person class.
     * 
     * @param type id The input value of the id field.
     * @param type name The input value of the name field.
     * @param type mothername The input value of the mothername field.
     * @param type location The input value of the location field.
     * @param type birthdate The input value of the birthDate field.
     * @param type isdeleted The input value of the isDeleted field.
     */
    public function __construct($id, $name, $mothername, $location, $birthdate, $isdeleted)
    {
        $this->idField = $id;
        $this->nameField = $name;
        $this->mothernameField = $mothername;
        $this->locationField = $location;
        $this->birthdateField = $birthdate;
        $this->isDeletedField = $isdeleted;
    }
	
    // </editor-fold>
	
    //<editor-fold defaultstate="collapsed" desc="Methods">

    // </editor-fold>
}

?>