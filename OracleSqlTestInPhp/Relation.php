<?php

/**
 * Base class for Relation.
 */
class Relation
{
    //<editor-fold defaultstate="collapsed" desc="Fields">
	
    // The id field of the Relation class.
    private $idField;
	
    // The person1 field of the Relation class.
    private $person1Field;
	
    // The relationship field of the Relation class.
    private $relationshipField;
	
    // The person2 field of the Relation class.
    private $person2Field;
	
    // The isDeleted field of the Relation class.
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
     * Gets the person1Field.
     * 
     * @return The person1Field.
     */
    public function getPerson1()
    {
        return $this->person1Field;
    }

    /**
     * Sets the person1Field.
     * 
     * @param type value The person1 to set.
     */
    public function setPerson1($value)
    {
        $this->person1Field = $value;
    }

    /**
     * Gets the relationshipField.
     * 
     * @return The relationshipField.
     */
    public function getRelationship()
    {
        return $this->relationshipField;
    }

    /**
     * Sets the relationshipField.
     * 
     * @param type value The relationship to set.
     */
    public function setRelationship($value)
    {
        $this->relationshipField = $value;
    }

    /**
     * Gets the person2Field.
     * 
     * @return The person2Field.
     */
    public function getPerson2()
    {
        return $this->person2Field;
    }

    /**
     * Sets the person2Field.
     * 
     * @param type value The person2 to set.
     */
    public function setPerson2($value)
    {
        $this->person2Field = $value;
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
     * Initializes a new instance of the Relation class.
     *
     * @param type id The input value of the id field.
     * @param type person1 The input value of the person1 field.
     * @param type relationship The input value of the relationship field.
     * @param type person2 The input value of the person2 field.
     * @param type isdeleted The input value of the isDeleted field.
     */
    public function __construct($id, $person1, $relationship, $person2, $isdeleted)
    {
        $this->idField = $id;
        $this->person1Field = $person1;
        $this->relationshipField = $relationship;
        $this->person2Field = $person2;
        $this->isDeletedField = $isdeleted;
    }
	
    // </editor-fold>
	
    //<editor-fold defaultstate="collapsed" desc="Methods">
	
    // </editor-fold>
}

?>