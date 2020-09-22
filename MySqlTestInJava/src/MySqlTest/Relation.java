package MySqlTest;

/**
 * Base class for Relation.
 */
public class Relation
{
    //<editor-fold defaultstate="collapsed" desc="Fields">
    
    // The id field of the Relation class.
    private int id;

    // The person1 field of the Relation class.
    private int person1;

    // The relationship field of the Relation class.
    private int relationship;

    // The person2 field of the Relation class.
    private int person2;

    // The isDeleted field of the Relation class.
    private boolean isDeleted;
    
    // </editor-fold>
    
    //<editor-fold defaultstate="collapsed" desc="Properties">
    
    /**
     * Gets the id.
     * 
     * @return The id.
     */
    public int getId()
    {
        return id;
    }

    /**
     * Sets the id.
     * 
     * @param id The id to set.
     */
    public void setId(int id)
    {
        this.id = id;
    }

    /**
     * Gets the person1.
     * 
     * @return The person1.
     */
    public int getPerson1()
    {
        return person1;
    }

    /**
     * Sets the person1.
     * 
     * @param person1 The person1 to set.
     */
    public void setPerson1(int person1)
    {
        this.person1 = person1;
    }

    /**
     * Gets the relationship.
     * 
     * @return The relationship.
     */
    public int getRelationship()
    {
        return relationship;
    }

    /**
     * Sets the relationship.
     * 
     * @param relationship The relationship to set.
     */
    public void setRelationship(int relationship)
    {
        this.relationship = relationship;
    }

    /**
     * Gets the person2.
     * 
     * @return The person2.
     */
    public int getPerson2()
    {
        return person2;
    }

    /**
     * Sets the person2.
     * 
     * @param person2 The person2 to set.
     */
    public void setPerson2(int person2)
    {
        this.person2 = person2;
    }

    /**
     * Gets the isDeleted.
     * 
     * @return The isDeleted.
     */
    public boolean getIsDeleted()
    {
        return isDeleted;
    }

    /**
     * Sets the isDeleted.
     * 
     * @param isDeleted The isDeleted to set.
     */
    public void setIsDeleted(boolean isDeleted)
    {
        this.isDeleted = isDeleted;
    }
    
    // </editor-fold>
    
    //<editor-fold defaultstate="collapsed" desc="Constructors">
    
    /**
     * Initializes a new instance of the Relation class.
     */
    public Relation()
    { }
    
    /**
     * Initializes a new instance of the Relation class.
     * @param id The input value of the id field.
     * @param person1 The input value of the person1 field.
     * @param relationship The input value of the relationship field.
     * @param person2 The input value of the person2 field.
     * @param isdeleted The input value of the isDeleted field.
     */
    public Relation(int id, int person1, int relationship, int person2, boolean isdeleted)
    {
        this.id = id;
        this.person1 = person1;
        this.relationship = relationship;
        this.person2 = person2;
        this.isDeleted = isdeleted;
    }
    
    // </editor-fold>
    
    //<editor-fold defaultstate="collapsed" desc="Methods">
    
    // </editor-fold>
}
