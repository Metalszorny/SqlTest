-- Base class for Person.
Person = {__id = 0, __name = "", __mothername = "", __location = "", __birthdate = "", __isDeleted = false}

-- Properties

-- Gets the id.
function Person : getId()
   return self.__id
end

-- Sets the id.
function Person : setId(value)
   self.__id = value
end

-- Gets the name.
function Person : getName()
   return self.__name
end

-- Sets the name.
function Person : setName(value)
   self.__name = value
end

-- Gets the mothername.
function Person : getMothername()
   return self.__mothername
end

-- Sets the mothername.
function Person : setMothername(value)
   self.__mothername = value
end

-- Gets the location.
function Person : getLocation()
   return self.__location
end

-- Sets the location.
function Person : setLocation(value)
   self.__location = value
end

-- Gets the birthdate.
function Person : getBirthdate()
   return self.__birthdate
end

-- Sets the birthdate.
function Person : setBirthdate(value)
   self.__birthdate = value
end

-- Gets the isDeleted.
function Person : getIsDeleted()
   return self.__isDeleted
end

-- Sets the isDeleted.
function Person : setIsDeleted(value)
   self.__isDeleted = value
end

-- Properties

-- Constructors

-- Initializes a new instance of the Person class.
function Person : new(o)
   o = o or {}
   setmetatable(o, self)
   self.__index = self
   
   return o
end

-- Initializes a new instance of the Person class.
function Person : new(o, id, name, mothername, location, birthdate, isdeleted)
   o = o or {}
   setmetatable(o, self)
   self.__index = self
   self.__id = id or 0
   self.__name = name or ""
   self.__mothername = mothername or ""
   self.__location = location or ""
   self.__birthdate = birthdate or ""
   self.__isDeleted = isdeleted or false
   
   return o
end

-- Constructors