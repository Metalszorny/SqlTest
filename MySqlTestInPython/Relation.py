# Base class for Relation.
class Relation(object):
    """description of class"""

    #region Fields

    # The id field of the Relation class.
    __id = None

    # The person1 field of the Relation class.
    __person1 = None

    # The relationship field of the Relation class.
    __relationship = None

    # The person2 field of the Relation class.
    __person2 = None

    # The isDeleted field of the Relation class.
    __isDeleted = None

    #endregion Fields

    #region Properties

    # Gets the id.
    def getId(self):
        return self.__id

    # Sets the id.
    def setId(self, value):
        self.__id = value

    # Gets the person1.
    def getPerson1(self):
        return self.__person1

    # Sets the person1.
    def setPerson1(self, value):
        self.__person1 = value

    # Gets the relationship.
    def getRelationship(self):
        return self.__relationship

    # Sets the relationship.
    def setRelationshipe(self, value):
        self.__relationship = value

    # Gets the person2.
    def getPerson2(self):
        return self.__person2

    # Sets the person2.
    def setPerson2(self, value):
        self.__person2 = value

    # Gets the isDeleted.
    def getIsDeleted(self):
        return self.__isDeleted

    # Sets the isDeleted.
    def setIsDeleted(self, value):
        self.__isDeleted = value

    #endregion Properties

    #region Constructors

    # Initializes a new instance of the Relation class.
    def __init__(self):
        self.__id = None
        self.__person1 = None
        self.__relationship = None
        self.__person2 = None
        self.__isDeleted = None

    # Initializes a new instance of the Relation class.
    def __init__(self, id, person1, relationship, person2, isdeleted):
        self.__id = id
        self.__person1 = person1
        self.__relationship = relationship
        self.__person2 = person2
        self.__isDeleted = isdeleted

    #endregion Constructors

    #region Methods

    #endregion Methods