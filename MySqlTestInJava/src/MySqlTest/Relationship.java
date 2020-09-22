package MySqlTest;

/**
 * Base class for Relationship.
 */
public class Relationship
{
    //<editor-fold defaultstate="collapsed" desc="Fields">
   
    // The id field of the Relationship class.
    private int id;

    // The name field of the Relationship class.
    private String name;

    // The isDeleted field of the Relationship class.
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
     * Gets the name.
     * 
     * @return The name.
     */
    public String getName()
    {
        return name;
    }

    /**
     * Sets the name.
     * 
     * @param name The name to set.
     */
    public void setName(String name)
    {
        this.name = name;
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
     * Initializes a new instance of the Relationship class.
     */
    public Relationship()
    { }
    
    /**
     * Initializes a new instance of the Relationship class.
     * @param id The input value of the id field.
     * @param name The input value of the name field.
     * @param isdeleted The input value of the isDeleted field.
     */
    public Relationship(int id, String name, boolean isdeleted)
    {
        this.id = id;
        this.name = name;
        this.isDeleted = isdeleted;
    }
    
    // </editor-fold>
    
    //<editor-fold defaultstate="collapsed" desc="Methods">
    
    // </editor-fold>
}
