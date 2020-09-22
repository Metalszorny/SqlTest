#ifndef PERSON_H
#define PERSON_H

#include <windows.h>
#include <string>
#include "sql.h"

using namespace std;

/// \brief Base class for Person.
class Person
{
    public:

        #ifndef REGION_Constructors

        /// \brief Initializes a new instance of the Person class.
        Person();

        /// \brief Initializes a new instance of the Person class.
        /// \par id The input value of the id field.
        /// \par name The input value of the name field.
        /// \par mothername The input value of the mothername field.
        /// \par location The input value of the location field.
        /// \par birthdate The input value of the birthdate field.
        /// \par isdeleted The input value of the isDeleted field.
        Person(int id, string name, string mothername, string location, TIMESTAMP_STRUCT birthdate, bool isdeleted);

        /// \brief Deletes the instance of the Person class.
        virtual ~Person();

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

        /// \brief Gets the mothername.
        /// \return The mothername.
        virtual string GetMothername()
        {
            return this->mothername;
        }

        /// \brief Sets the mothername.
        /// \par value The value for the mothername.
        virtual void SetMothername(string value)
        {
            this->mothername = value;
        }

        /// \brief Gets the location.
        /// \return The location.
        virtual string GetLocation()
        {
            return this->location;
        }

        /// \brief Sets the location.
        /// \par value The value for the location.
        virtual void SetLocation(string value)
        {
            this->location = value;
        }

        /// \brief Gets the birthdate.
        /// \return The birthdate.
        virtual TIMESTAMP_STRUCT GetBirthdate()
        {
            return this->birthdate;
        }

        /// \brief Sets the birthdate.
        /// \par value The value for the birthdate.
        virtual void SetBirthdate(TIMESTAMP_STRUCT value)
        {
            this->birthdate = value;
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

        // The id field of the Person class.
        int id;

        // The name field of the Person class.
        string name;

        // The mothername field of the Person class.
        string mothername;

        // The location field of the Person class.
        string location;

        // The birthdate field of the Person class.
        TIMESTAMP_STRUCT birthdate;

        // The isDeleted field of the Person class.
        bool isDeleted;

        #endif //REGION_Fields

};

#endif // PERSON_H
