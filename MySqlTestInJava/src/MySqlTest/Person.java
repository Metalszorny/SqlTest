package MySqlTest;

import java.sql.Date;

/**
 * Base class for Person.
 */
public class Person
{
    //<editor-fold defaultstate="collapsed" desc="Fields">
    
        // The id field of the Person class.
        private int id;

        // The name field of the Person class.
        private String name;

        // The mothername field of the Person class.
        private String mothername;

        // The location field of the Person class.
        private String location;

        // The birthdate field of the Person class.
        private Date birthdate;

        // The isDeleted field of the Person class.
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
     * Gets the mothername.
     * 
     * @return The mothername.
     */
    public String getMothername()
    {
        return mothername;
    }

    /**
     * Sets the mothername.
     * 
     * @param mothername The mothername to set.
     */
    public void setMothername(String mothername)
    {
        this.mothername = mothername;
    }

    /**
     * Gets the location.
     * 
     * @return The location.
     */
    public String getLocation()
    {
        return location;
    }

    /**
     * Sets the location.
     * 
     * @param location The location to set.
     */
    public void setLocation(String location)
    {
        this.location = location;
    }

    /**
     * Gets the birthdate.
     * 
     * @return The birthdate.
     */
    public Date getBirthdate()
    {
        return birthdate;
    }

    /**
     * Sets the birthdate.
     * 
     * @param birthdate The birthdate to set.
     */
    public void setBirthdate(Date birthdate)
    {
        this.birthdate = birthdate;
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
     * Initializes a new instance of the Person class.
     */
    public Person()
    { }
    
    /**
     * Initializes a new instance of the Person class.
     * 
     * @param id The input value of the id field.
     * @param name The input value of the name field.
     * @param mothername The input value of the mothername field.
     * @param location The input value of the location field.
     * @param birthdate The input value of the birthDate field.
     * @param isdeleted The input value of the isDeleted field.
     */
    public Person(int id, String name, String mothername, String location, Date birthdate, boolean isdeleted)
    {
        this.id = id;
        this.name = name;
        this.mothername = mothername;
        this.location = location;
        this.birthdate = birthdate;
        this.isDeleted = isdeleted;
    }
    
    // </editor-fold>
    
    //<editor-fold defaultstate="collapsed" desc="Methods">
    
    // </editor-fold>
}
