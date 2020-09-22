#include "Relation.h"

Relation::Relation()
{
    //ctor
}

Relation::Relation(int id, int person1, int relationship, int person2, bool isdeleted)
{
    this->id = id;
    this->person1 = person1;
    this->relationship = relationship;
    this->person2 = person2;
    this->isDeleted = isdeleted;
}

Relation::~Relation()
{
    //dtor
}
