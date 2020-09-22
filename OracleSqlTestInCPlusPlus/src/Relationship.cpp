#include "Relationship.h"

Relationship::Relationship()
{
    //ctor
}

Relationship::Relationship(int id, string name, bool isdeleted)
{
    this->id = id;
    this->name = name;
    this->isDeleted = isdeleted;
}

Relationship::~Relationship()
{
    //dtor
}
