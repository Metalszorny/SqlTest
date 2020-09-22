-- Base class for Relation.
Relation = {__id = 0, __person1 = 0, __relationship = 0, __person2 = 0, __isDeleted = false}

-- Properties

-- Gets the id.
function Relation : getId()
   return self.__id
end

-- Sets the id.
function Relation : setId(value)
   self.__id = value
end

-- Gets the person1.
function Relation : getPerson1()
   return self.__person1
end

-- Sets the person1.
function Relation : setPerson1(value)
   self.__person1 = value
end

-- Gets the relationship.
function Relation : getRelationship()
   return self.__relationship
end

-- Sets the relationship.
function Relation : setRelationship(value)
   self.__relationship = value
end

-- Gets the person2.
function Relation : getPerson2()
   return self.__person2
end

-- Sets the person2.
function Relation : setPerson2(value)
   self.__person2 = value
end

-- Gets the isDeleted.
function Relation : getIsDeleted()
   return self.__isDeleted
end

-- Sets the isDeleted.
function Relation : setIsDeleted(value)
   self.__isDeleted = value
end

-- Properties

-- Constructors

-- Initializes a new instance of the Relation class.
function Relation : new(o)
   o = o or {}
   setmetatable(o, self)
   self.__index = self
   
   return o
end

-- Initializes a new instance of the Relation class.
function Relation : new(o, id, person1, relationship, person2, isdeleted)
   o = o or {}
   setmetatable(o, self)
   self.__index = self
   self.__id = id or 0
   self.__person1 = person1 or 0
   self.__relationship = relationship or 0
   self.__person2 = person2 or 0
   self.__isDeleted = isdeleted or false
   
   return o
end

-- Constructors