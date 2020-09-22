' Base class for Relation.
Class Relation

#Region "Fields"

    ' The id field of the Relationship class.
    Private idField As Integer

    ' The person1 field of the Relationship class.
    Private person1Field As Integer

    ' The relationship field of the Relationship class.
    Private relationshipField As Integer

    ' The person2 field of the Relationship class.
    Private person2Field As Integer

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

    ' Gets or sets the person1Field.
    Property Person1() As Integer
        Get
            Return person1Field
        End Get
        Set(ByVal value As Integer)
            person1Field = value
        End Set
    End Property

    ' Gets or sets the relationshipField.
    Property Relationship() As Integer
        Get
            Return relationshipField
        End Get
        Set(ByVal value As Integer)
            relationshipField = value
        End Set
    End Property

    ' Gets or sets the person2Field.
    Property Person2() As Integer
        Get
            Return person2Field
        End Get
        Set(ByVal value As Integer)
            person2Field = value
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
    Public Sub New(ByVal id As Integer, ByVal person1 As Integer, ByVal relationship As Integer, ByVal person2 As Integer, ByVal isdeleted As Boolean)
        Me.idField = id
        Me.person1Field = person1
        Me.relationshipField = relationship
        Me.person2Field = person2
        Me.isDeletedfield = isdeleted
    End Sub

#End Region

#Region "Methods"

#End Region

End Class
