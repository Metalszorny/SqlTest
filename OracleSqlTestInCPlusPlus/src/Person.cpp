#include "Person.h"

Person::Person()
{
    //ctor
}

Person::Person(int id, string name, string mothername, string location, TIMESTAMP_STRUCT birthdate, bool isdeleted)
{
    this->id = id;
    this->name = name;
    this->mothername = mothername;
    this->location = location;
    this->birthdate = birthdate;
    this->isDeleted = isdeleted;
}

Person::~Person()
{
    //dtor
}
