#ifndef RELATIONSHIP_H
#define RELATIONSHIP_H

#include <string>

using namespace std;

/// \brief Base class for Relationship.
class Relationship
{
    public:

        #ifndef REGION_Constructors

        /// \brief Initializes a new instance of the Relationship class.
        Relationship();

        /// \brief Initializes a new instance of the Relationship class.
        /// \par id The input value of the id field.
        /// \par name The input value of the name field.
        /// \par isdeleted The input value of the isDeleted field.
        Relationship(int id, string name, bool isdeleted);

        /// \brief Deletes the instance of the Relationship class.
        virtual ~Relationship();

        #endif//REGION_Constructors

        #ifndef REGION_Properties

        /// \brief Gets the id.
        /// \return The id.
        virtual int GetId()
        {
            return this->id;
        }

        /// \brief Sets the id.
        /// \par value The value for the id.
        virtual void SetId(int value)
        {
            this->id = value;
        }

        /// \brief Gets the name.
        /// \return The name.
        virtual string GetName()
        {
            return this->name;
        }

        /// \brief Sets the name.
        /// \par value The value for the name.
        virtual void SetName(string value)
        {
            this->name = value;
        }

        /// \brief Gets the isDeleted.
        /// \return The isDeleted.
        virtual int GetIsDeleted()
        {
            return this->isDeleted;
        }

        /// \brief Sets the isDeleted.
        /// \par value The value for the isDeleted.
        virtual void SetIsDeleted(bool value)
        {
            this->isDeleted = value;
        }

        #endif //REGION_Properties

    protected:

    private:

        #ifndef REGION_Fields

        // The id field of the Relationship class.
        int id;

        // The name field of the Relationship class.
        string name;

        // The isDeleted field of the Relationship class.
        bool isDeleted;

        #endif //REGION_Fields

};

#endif // RELATIONSHIP_H
