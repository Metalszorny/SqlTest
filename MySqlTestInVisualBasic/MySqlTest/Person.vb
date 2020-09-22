' Base class for Person.
Class Person

#Region "Fields"

    ' The id field of the Relationship class.
    Private idField As Integer

    ' The name field of the Relationship class.
    Private nameField As String

    ' The mothername field of the Relationship class.
    Private mothernameField As String

    ' The location field of the Relationship class.
    Private locationField As String

    ' The birthDate field of the Relationship class.
    Private birthdateField As Date

    ' The isDeleted field of the Relationship class.
    Private isDeletedfield As Boolean

#End Region

#Region "Properties"

    ' Gets or sets the idField.
    Property Id() As Integer
        Get
            Return idField
        End Get
        Set(ByVal value As Integer)
            idField = value
        End Set
    End Property

    ' Gets or sets the nameField.
    Property Name() As String
        Get
            Return nameField
        End Get
        Set(ByVal value As String)
            nameField = value
        End Set
    End Property

    ' Gets or sets the mothernameField.
    Property Mothername() As String
        Get
            Return mothernameField
        End Get
        Set(ByVal value As String)
            mothernameField = value
        End Set
    End Property

    ' Gets or sets the locationField.
    Property Location() As String
        Get
            Return locationField
        End Get
        Set(ByVal value As String)
            locationField = value
        End Set
    End Property

    ' Gets or sets the birthDateField.
    Property Birthdate() As Date
        Get
            Return birthdateField
        End Get
        Set(ByVal value As Date)
            birthdateField = value
        End Set
    End Property

    ' Gets or sets the isDeletedfield.
    Property IsDeleted() As Boolean
        Get
            Return isDeletedfield
        End Get
        Set(ByVal value As Boolean)
            isDeletedfield = value
        End Set
    End Property

#End Region

#Region "Constructors"

    ' Initializes a new instance of the Relationship class.
    Public Sub New()
    End Sub

    ' Initializes a new instance of the Relationship class.
    Public Sub New(ByVal id As Integer, ByVal name As String, ByVal mothername As String, ByVal location As String, ByVal birthdate As Date, ByVal isdeleted As Boolean)
        Me.idField = id
        Me.nameField = name
        Me.mothernameField = mothername
        Me.locationField = location
        Me.birthdateField = birthdate
        Me.isDeletedfield = isdeleted
    End Sub

#End Region

#Region "Methods"

#End Region

End Class
