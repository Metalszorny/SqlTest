#ifndef RELATION_H
#define RELATION_H

#include <string>

using namespace std;

/// \brief Base class for Relation.
class Relation
{
    public:

        #ifndef REGION_Constructors

        /// \brief Initializes a new instance of the Relation class.
        Relation();

        /// \brief Initializes a new instance of the Relation class.
        /// \par id The input value of the id field.
        /// \par person1 The input value of the person1 field.
        /// \par relationship The input value of the relationship field.
        /// \par person2 The input value of the person2 field.
        /// \par isdeleted The input value of the isDeleted field.
        Relation(int id, int person1, int relationship, int person2, bool isdeleted);

        /// \brief Deletes the instance of the Relation class.
        virtual ~Relation();

        #endif //REGION_Constructors

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

        /// \brief Gets the person1.
        /// \return The person1.
        virtual int GetPerson1()
        {
            return this->person1;
        }

        /// \brief Sets the person1.
        /// \par value The value for the person1.
        virtual void SetPerson1(int value)
        {
            this->person1 = value;
        }

        /// \brief Gets the relationship.
        /// \return The relationship.
        virtual int GetRelationship()
        {
            return this->relationship;
        }

        /// \brief Sets the relationship.
        /// \par value The value for the relationship.
        virtual void SetRelationship(int value)
        {
            this->relationship = value;
        }

        /// \brief Gets the person2.
        /// \return The person2.
        virtual int GetPerson2()
        {
            return this->person2;
        }

        /// \brief Sets the person2.
        /// \par value The value for the person2.
        virtual void SetPerson2(int value)
        {
            this->person2 = value;
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

        // The id field of the Relation class.
        int id;

        // The person1 field of the Relation class.
        int person1;

        // The relationship field of the Relation class.
        int relationship;

        // The person2 field of the Relation class.
        int person2;

        // The isDeleted field of the Relation class.
        bool isDeleted;

        #endif //REGION_Fields

};

#endif // RELATION_H
