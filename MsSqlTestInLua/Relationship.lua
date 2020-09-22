-- Base class for Relationship.
Relationship = {__id = 0, __name = "", __isDeleted = false}

-- Properties

-- Gets the id.
function Relationship : getId()
   return self.__id
end

-- Sets the id.
function Relationship : setId(value)
   self.__id = value
end

-- Gets the name.
function Relationship : getName()
   return self.__name
end

-- Sets the name.
function Relationship : setName(value)
   self.__name = value
end

-- Gets the isDeleted.
function Relationship : getIsDeleted()
   return self.__isDeleted
end

-- Sets the isDeleted.
function Relationship : setIsDeleted(value)
   self.__isDeleted = value
end

-- Properties

-- Constructors

-- Initializes a new instance of the Relationship class.
function Relationship : new(o)
   o = o or {}
   setmetatable(o, self)
   self.__index = self
   
   return o
end

-- Initializes a new instance of the Relationship class.
function Relationship : new(o, id, name, isdeleted)
   o = o or {}
   setmetatable(o, self)
   self.__index = self
   self.__id = id or 0
   self.__name = name or ""
   self.__isDeleted = isdeleted or false
   
   return o
end

-- Constructors