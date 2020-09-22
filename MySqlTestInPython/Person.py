# Base class for Person.
class Person(object):
    """description of class"""

    # region Fields

    # The id field of the Person class.
    __id = None

    # The name field of the Person class.
    __name = None

    # The mothername field of the Person class.
    __mothername = None

    # The location field of the Person class.
    __location = None

    # The birthdate field of the Person class.
    __birthdate = None

    # The isDeleted field of the Person class.
    __isDeleted = None

    # endregion Fields

    # region Properties

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

    # Gets the mothername.
    def getMothername(self):
        return self.__mothername

    # Sets the mothername.
    def setMothername(self, value):
        self.__mothername = value

    # Gets the location.
    def getLocation(self):
        return self.__location

    # Sets the location.
    def setLocation(self, value):
        self.__location = value

    # Gets the birthdate.
    def getBirthdate(self):
        return self.__birthdate

    # Sets the birthdate.
    def setBirthdatee(self, value):
        self.__birthdate = value

    # Gets the isDeleted.
    def getIsDeleted(self):
        return self.__isDeleted

    # Sets the isDeleted.
    def setIsDeleted(self, value):
        self.__isDeleted = value

    # endregion Properties

    # region Constructors

    # Initializes a new instance of the Person class.
    def __init__(self):
        self.__id = None
        self.__name = None
        self.__mothername = None
        self.__location = None
        self.__birthdate = None
        self.__isDeleted = None

    # Initializes a new instance of the Person class.
    def __init__(self, id, name, mothername, location, birthdate, isdeleted):
        self.__id = id
        self.__name = name
        self.__mothername = mothername
        self.__location = location
        self.__birthdate = birthdate
        self.__isDeleted = isdeleted

    # endregion Constructors

    # region Methods

    # endregion Methods