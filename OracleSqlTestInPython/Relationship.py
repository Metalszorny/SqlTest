# Base class for Relationship.
class Relationship(object):
    """description of class"""

    #region Fields

    # The id field of the Relationship class.
    __id = None

    # The name field of the Relationship class.
    __name = None

    # The isDeleted field of the Relationship class.
    __isDeleted = None

    #endregion Fields

    #region Properties

    # Gets the id.
    def getId(self):
        return self.__id

    # Sets the id.
    def setId(self, value):
        self.__id = value

    # Gets the name.
    def getName(self):
        return self.__name

    # Sets the name.
    def setName(self, value):
        self.__name = value

    # Gets the isDeleted.
    def getIsDeleted(self):
        return self.__isDeleted

    # Sets the isDeleted.
    def setIsDeleted(self, value):
        self.__isDeleted = value

    #endregion Properties

    #region Constructors

    # Initializes a new instance of the Relationship class.
    def __init__(self):
        self.__id = None
        self.__name = None
        self.__isDeleted = None

    # Initializes a new instance of the Relationship class.
    def __init__(self, id, name, isdeleted):
        self.__id = id
        self.__name = name
        self.__isDeleted = isdeleted

    #endregion Constructors

    #region Methods

    #endregion Methods