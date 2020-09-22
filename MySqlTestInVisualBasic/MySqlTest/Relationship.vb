' Base class for Relationship.
Class Relationship

#Region "Fields"

    ' The id field of the Relationship class.
    Private idField As Integer

    ' The name field of the Relationship class.
    Private nameField As String

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
    Public Sub New(ByVal id As Integer, ByVal name As String, ByVal isdeleted As Boolean)
        Me.idField = id
        Me.nameField = name
        Me.isDeletedfield = isdeleted
    End Sub

#End Region

#Region "Methods"

#End Region

End Class
