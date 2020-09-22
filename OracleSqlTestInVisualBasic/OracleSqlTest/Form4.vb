Imports System.Data.OracleClient

' Interaction logic for Form4.
Public Class Form4

#Region "Fields"

    ' The database connectionString.
    Private url As String = "Data Source=(DESCRIPTION=(ADDRESS_LIST=(ADDRESS=(PROTOCOL=TCP)" +
                             "(HOST=localhost)(PORT=1521)))" +
                             "(CONNECT_DATA=(SERVER=DEDICATED)(SERVICE_NAME=orcl)));" +
                             "User Id=root;Password=root;"

    ' The id value.
    Private idValue As Integer

    ' The name1 value.
    Private name1Value As Integer

    ' The relationship value.
    Private relationshipValue As Integer

    ' The name2 value.
    Private name2Value As Integer

#End Region

#Region "Methods"

    ' Handles the CellClick event of the DataGridView1 control.
    Private Sub DataGridView1_CellClick(sender As Object, e As DataGridViewCellEventArgs) Handles DataGridView1.CellClick
        ' An item must be selected in the dataGridView.
        If (DataGridView1.CurrentCellAddress.X >= 0) Then
            Try
                ' Get the Id value of the selected item.
                idValue = Integer.Parse(DataGridView1.Rows(DataGridView1.SelectedCells(0).RowIndex).Cells("Column1").Value.ToString())

                ' Open a connection to the database.
                Dim oracleSqlConnection As OracleConnection = New OracleConnection(url)
                oracleSqlConnection.Open()

                ' Get the items from the Relations table.
                Dim relation As Relation = New Relation()
                Dim oracleSqlCommand As OracleCommand = New OracleCommand("SELECT * FROM root.Relations WHERE Id = :param1", oracleSqlConnection)

                ' Fill the values of the command.
                oracleSqlCommand.Parameters.AddWithValue(":param1", idValue)

                ' Execute.
                Dim oracleSqlDataReader As OracleDataReader = oracleSqlCommand.ExecuteReader()

                ' Store the items in a Relation object.
                While oracleSqlDataReader.Read()
                    relation = New Relation(oracleSqlDataReader.GetInt32(0), oracleSqlDataReader.GetInt32(1), oracleSqlDataReader.GetInt32(2),
                            oracleSqlDataReader.GetInt32(3), If(oracleSqlDataReader.GetInt32(4), True, False))
                End While

                ' Close the datareader and the connection.
                oracleSqlDataReader.Close()
                oracleSqlConnection.Close()

                ' Give the textBox Texts the selected values.
                ComboBox1.SelectedItem = relation.Person1
                ComboBox2.SelectedItem = relation.Relationship
                ComboBox3.SelectedItem = relation.Person2
            Catch
                ' Empty the textBox Texts.
                ComboBox1.SelectedItem = Nothing
                ComboBox2.SelectedItem = Nothing
                ComboBox3.SelectedItem = Nothing
            End Try
        Else
            ' Empty the textBox Texts.
            ComboBox1.SelectedItem = Nothing
            ComboBox2.SelectedItem = Nothing
            ComboBox3.SelectedItem = Nothing
        End If
    End Sub

    ' Handles the Click event of the Button1 control.
    Private Sub Button1_Click(sender As Object, e As EventArgs) Handles Button1.Click
        ' List the records.
        GetData()
    End Sub

    ' Handles the Click event of the Button2 control.
    Private Sub Button2_Click(sender As Object, e As EventArgs) Handles Button2.Click
        ' Add a record.
        Try
            ' The fields must not be empty.
            If ((name1Value <> 0) And (name2Value <> 0) And (relationshipValue <> 0) And (name1Value <> name2Value)) Then
                idValue = 0
                Dim matchFound As Boolean = False

                ' Open a connection to the database.
                Dim oracleSqlConnection As OracleConnection = New OracleConnection(url)
                oracleSqlConnection.Open()

                ' Edit the IsDeleted value to true.
                Dim oracleSqlCommand1 As OracleCommand = New OracleCommand("SELECT * FROM root.Relations", oracleSqlConnection)

                ' Execute.
                Dim oracleSqlDataReader1 As OracleDataReader = oracleSqlCommand1.ExecuteReader()

                ' Get the number of the existing items.
                While oracleSqlDataReader1.Read()
                    idValue += 1

                    ' Search for deleted matching items.
                    If (matchFound = False And
                            oracleSqlDataReader1.GetInt32(1) = name1Value And
                            oracleSqlDataReader1.GetInt32(2) = relationshipValue And
                            oracleSqlDataReader1.GetInt32(3) = name2Value And
                            oracleSqlDataReader1.GetInt32(4) = 1) Then
                        matchFound = True
                        idValue = oracleSqlDataReader1.GetInt32(0)

                        Exit While
                    End If
                End While

                ' Close the dataReader.
                oracleSqlDataReader1.Close()

                ' Add a new item if no deleted match was found else restore the deleted item.
                If matchFound = False Then
                    ' Edit the IsDeleted value to true.
                    Dim oracleSqlCommand As OracleCommand = New OracleCommand("INSERT INTO root.Relations (Id, Person1, Relationship, Person2, IsDeleted) VALUES (:param1, :param2, :param3, :param4, :param5)", oracleSqlConnection)

                    ' Fill the values of the command.
                    oracleSqlCommand.Parameters.AddWithValue(":param1", idValue + 1)
                    oracleSqlCommand.Parameters.AddWithValue(":param2", name1Value)
                    oracleSqlCommand.Parameters.AddWithValue(":param3", relationshipValue)
                    oracleSqlCommand.Parameters.AddWithValue(":param4", name2Value)
                    oracleSqlCommand.Parameters.AddWithValue(":param5", 0)

                    ' Execute.
                    oracleSqlCommand.ExecuteNonQuery()
                Else
                    ' Edit the IsDeleted value to false.
                    Dim oracleSqlCommand As OracleCommand = New OracleCommand("UPDATE root.Relations SET IsDeleted = :param2 WHERE Id = :param1", oracleSqlConnection)

                    ' Fill the values of the command.
                    oracleSqlCommand.Parameters.AddWithValue(":param1", idValue)
                    oracleSqlCommand.Parameters.AddWithValue(":param2", 0)

                    ' Execute.
                    oracleSqlCommand.ExecuteNonQuery()
                End If

                ' Close the connection.
                oracleSqlConnection.Close()

                ' Refresh.
                GetData()
            End If
        Catch

        End Try
    End Sub

    ' Handles the Click event of the Button3 control.
    Private Sub Button3_Click(sender As Object, e As EventArgs) Handles Button3.Click
        ' Edit a record.
        Try
            ' The fields must not be empty.
            If ((name1Value <> 0) And (name2Value <> 0) And (relationshipValue <> 0) And (name1Value <> name2Value)) Then
                ' An item must be selected in the dataGridView.
                If (DataGridView1.CurrentCellAddress.X >= 0) Then
                    ' Get the Id value of the selected item.
                    idValue = Integer.Parse(DataGridView1.Rows(DataGridView1.SelectedCells(0).RowIndex).Cells("Column1").Value.ToString())

                    ' Open a connection to the database.
                    Dim oracleSqlConnection As OracleConnection = New OracleConnection(url)
                    oracleSqlConnection.Open()

                    ' Edit the IsDeleted value to true.
                    Dim oracleSqlCommand As OracleCommand = New OracleCommand("UPDATE root.Relations SET Person1 = :param2, Relationship = :param3, Person2 = :param4 WHERE Id = :param1", oracleSqlConnection)

                    ' Fill the values of the command.
                    oracleSqlCommand.Parameters.AddWithValue(":param1", idValue)
                    oracleSqlCommand.Parameters.AddWithValue(":param2", name1Value)
                    oracleSqlCommand.Parameters.AddWithValue(":param3", relationshipValue)
                    oracleSqlCommand.Parameters.AddWithValue(":param4", name2Value)

                    ' Execute.
                    oracleSqlCommand.ExecuteNonQuery()

                    ' Close the connection.
                    oracleSqlConnection.Close()

                    ' Refresh.
                    GetData()
                End If
            End If
        Catch

        End Try
    End Sub

    ' Handles the Click event of the Button4 control.
    Private Sub Button4_Click(sender As Object, e As EventArgs) Handles Button4.Click
        ' Delete a record.
        Try
            ' An item must be selected in the dataGridView.
            If (DataGridView1.CurrentCellAddress.X >= 0) Then
                ' Logical Delete
                ' Get the Id value of the selected item.
                idValue = Integer.Parse(DataGridView1.Rows(DataGridView1.SelectedCells(0).RowIndex).Cells("Column1").Value.ToString())

                ' Open a connection to the database.
                Dim oracleSqlConnection As OracleConnection = New OracleConnection(url)
                oracleSqlConnection.Open()

                ' Edit the IsDeleted value to true.
                Dim oracleSqlCommand As OracleCommand = New OracleCommand("UPDATE root.Relations SET IsDeleted = :param2 WHERE Id = :param1", oracleSqlConnection)

                ' Fill the values of the command.
                oracleSqlCommand.Parameters.AddWithValue(":param1", idValue)
                oracleSqlCommand.Parameters.AddWithValue(":param2", 1)

                ' Execute.
                oracleSqlCommand.ExecuteNonQuery()

                ' Close the connection.
                oracleSqlConnection.Close()

                ' Refresh.
                GetData()
            End If
        Catch

        End Try
    End Sub

    ' Handles the Click event of the Button5 control.
    Private Sub Button5_Click(sender As Object, e As EventArgs) Handles Button5.Click
        ' Close the program.
        Close()
    End Sub

    ' Handles the SelectedIndexChanged event of the ComboBox1 control.
    Private Sub ComboBox1_SelectedIndexChanged(sender As Object, e As EventArgs) Handles ComboBox1.SelectedIndexChanged
        Try
            ' Store the comboBox SelectedItem.
            name1Value = Integer.Parse(ComboBox1.SelectedItem.ToString())

            ' Open a connection to the database.
            Dim oracleSqlConnection As OracleConnection = New OracleConnection(url)
            oracleSqlConnection.Open()

            ' Get the items from the People table.
            Dim retVal As Person = New Person
            Dim oracleSqlCommand As OracleCommand = New OracleCommand("SELECT * FROM root.People WHERE Id = :param1", oracleSqlConnection)

            ' Fill the values of the command.
            oracleSqlCommand.Parameters.AddWithValue(":param1", name1Value)

            ' Execute.
            Dim oracleSqlDataReader As OracleDataReader = oracleSqlCommand.ExecuteReader()

            ' Store the items in a Person object.
            While oracleSqlDataReader.Read()
                retVal = New Person(oracleSqlDataReader.GetInt32(0), oracleSqlDataReader.GetString(1), oracleSqlDataReader.GetString(2),
                        oracleSqlDataReader.GetString(3), oracleSqlDataReader.GetDateTime(4), If(oracleSqlDataReader.GetInt32(5), True, False))
            End While

            ' Give the helper label the selected value.
            Label7.Text = retVal.Name

            ' Close the datareader and the connection.
            oracleSqlDataReader.Close()
            oracleSqlConnection.Close()
        Catch

        End Try
    End Sub

    ' Handles the SelectedIndexChanged event of the ComboBox2 control.
    Private Sub ComboBox2_SelectedIndexChanged(sender As Object, e As EventArgs) Handles ComboBox1.SelectedIndexChanged, ComboBox2.SelectedIndexChanged
        Try
            ' Store the comboBox SelectedItem.
            relationshipValue = Integer.Parse(ComboBox2.SelectedItem.ToString())

            ' Open a connection to the database.
            Dim oracleSqlConnection As OracleConnection = New OracleConnection(url)
            oracleSqlConnection.Open()

            ' Get the items from the Relationships table.
            Dim retVal As Relationship = New Relationship
            Dim oracleSqlCommand As OracleCommand = New OracleCommand("SELECT * FROM root.Relationships WHERE Id = :param1", oracleSqlConnection)

            ' Fill the values of the command.
            oracleSqlCommand.Parameters.AddWithValue(":param1", relationshipValue)

            ' Execute.
            Dim oracleSqlDataReader As OracleDataReader = oracleSqlCommand.ExecuteReader()

            ' Store the items in a Relationship object.
            While oracleSqlDataReader.Read()
                retVal = New Relationship(oracleSqlDataReader.GetInt32(0), oracleSqlDataReader.GetString(1), If(oracleSqlDataReader.GetInt32(2), True, False))
            End While

            ' Give the helper label the selected value.
            Label8.Text = retVal.Name

            ' Close the datareader and the connection.
            oracleSqlDataReader.Close()
            oracleSqlConnection.Close()
        Catch

        End Try
    End Sub

    ' Handles the SelectedIndexChanged event of the ComboBox3 control.
    Private Sub ComboBox3_SelectedIndexChanged(sender As Object, e As EventArgs) Handles ComboBox1.SelectedIndexChanged, ComboBox3.SelectedIndexChanged
        Try
            ' Store the comboBox SelectedItem.
            name2Value = Integer.Parse(ComboBox3.SelectedItem.ToString())

            ' Open a connection to the database.
            Dim oracleSqlConnection As OracleConnection = New OracleConnection(url)
            oracleSqlConnection.Open()

            ' Get the items from the People table.
            Dim retVal As Person = New Person
            Dim oracleSqlCommand As OracleCommand = New OracleCommand("SELECT * FROM root.People WHERE Id = :param1", oracleSqlConnection)

            ' Fill the values of the command.
            oracleSqlCommand.Parameters.AddWithValue(":param1", name2Value)

            ' Execute.
            Dim oracleSqlDataReader As OracleDataReader = oracleSqlCommand.ExecuteReader()

            ' Store the items in a Person object.
            While oracleSqlDataReader.Read()
                retVal = New Person(oracleSqlDataReader.GetInt32(0), oracleSqlDataReader.GetString(1), oracleSqlDataReader.GetString(2),
                        oracleSqlDataReader.GetString(3), oracleSqlDataReader.GetDateTime(4), If(oracleSqlDataReader.GetInt32(5), True, False))
            End While

            ' Give the helper label the selected value.
            Label9.Text = retVal.Name

            ' Close the datareader and the connection.
            oracleSqlDataReader.Close()
            oracleSqlConnection.Close()
        Catch

        End Try
    End Sub

    ' Handles the Load event of the Form4 control.
    Private Sub Form4_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        ' Preset the values.
        Label7.Text = ""
        Label8.Text = ""
        Label9.Text = ""

        GetData()
    End Sub

    ' Gets the data.
    Private Sub GetData()
        Try
            ' Clear existing items.
            DataGridView1.Rows.Clear()
            ComboBox1.Items.Clear()
            ComboBox2.Items.Clear()
            ComboBox3.Items.Clear()

            ' Open a connection to the database.
            Dim oracleSqlConnection As OracleConnection = New OracleConnection(url)
            oracleSqlConnection.Open()

            ' Get the items from the People table.
            Dim people As List(Of Person) = New List(Of Person)
            Dim oracleSqlCommand1 As OracleCommand = New OracleCommand("SELECT * FROM root.People", oracleSqlConnection)

            ' Execute.
            Dim oracleSqlDataReader1 As OracleDataReader = oracleSqlCommand1.ExecuteReader()

            ' Store the items in a Person list.
            While oracleSqlDataReader1.Read()
                people.Add(New Person(oracleSqlDataReader1.GetInt32(0), oracleSqlDataReader1.GetString(1), oracleSqlDataReader1.GetString(2), oracleSqlDataReader1.GetString(3),
                                      oracleSqlDataReader1.GetDateTime(4), If(oracleSqlDataReader1.GetInt32(5), True, False)))
            End While

            ' Close the datareader.
            oracleSqlDataReader1.Close()

            ' Get the items from the Relationships table.
            Dim relationships As List(Of Relationship) = New List(Of Relationship)
            Dim oracleSqlCommand2 As OracleCommand = New OracleCommand("SELECT * FROM root.Relationships", oracleSqlConnection)

            ' Execute.
            Dim oracleSqlDataReader2 As OracleDataReader = oracleSqlCommand2.ExecuteReader()

            ' Store the items in a Relationship list.
            While oracleSqlDataReader2.Read()
                relationships.Add(New Relationship(oracleSqlDataReader2.GetInt32(0), oracleSqlDataReader2.GetString(1), If(oracleSqlDataReader2.GetInt32(2), True, False)))
            End While

            ' Close the datareader.
            oracleSqlDataReader2.Close()

            ' Get the items from the Relations table.
            Dim relations As List(Of Relation) = New List(Of Relation)
            Dim oracleSqlCommand As OracleCommand = New OracleCommand("SELECT * FROM root.Relations WHERE IsDeleted = 0", oracleSqlConnection)

            ' Execute.
            Dim oracleSqlDataReader As OracleDataReader = oracleSqlCommand.ExecuteReader()

            ' Store the items in a Relation list.
            While oracleSqlDataReader.Read()
                relations.Add(New Relation(oracleSqlDataReader.GetInt32(0), oracleSqlDataReader.GetInt32(1), oracleSqlDataReader.GetInt32(2),
                        oracleSqlDataReader.GetInt32(3), If(oracleSqlDataReader.GetInt32(4), True, False)))
            End While

            ' Close the datareader and the connection.
            oracleSqlDataReader.Close()
            oracleSqlConnection.Close()

            ' Fill the dataGridView rows with the values of the Relations table.
            For Each oneItem As Relation In relations
                Dim row As DataGridViewRow = New DataGridViewRow()
                Dim cell1 As DataGridViewCell = New DataGridViewTextBoxCell()
                Dim cell2 As DataGridViewCell = New DataGridViewTextBoxCell()
                Dim cell3 As DataGridViewCell = New DataGridViewTextBoxCell()
                Dim cell4 As DataGridViewCell = New DataGridViewTextBoxCell()

                cell1.Value = oneItem.Id.ToString()

                ' Substitute the Person1 and Person2 ids with their names.
                For Each onePerson As Person In people
                    If (oneItem.Person1 = onePerson.Id) Then
                        cell2.Value = onePerson.Name
                    End If

                    If (oneItem.Person2 = onePerson.Id) Then
                        cell4.Value = onePerson.Name
                    End If
                Next

                ' Substitute the Relationship ids with their names.
                For Each oneRelationship As Relationship In relationships
                    If (oneItem.Relationship = oneRelationship.Id) Then
                        cell3.Value = oneRelationship.Name
                    End If
                Next

                row.Cells.Add(cell1)
                row.Cells.Add(cell2)
                row.Cells.Add(cell3)
                row.Cells.Add(cell4)

                DataGridView1.Rows.Add(row)
            Next

            ' Fill the comboBox items with the values of the People table.
            For Each oneItem As Person In people
                If (oneItem.IsDeleted = False) Then
                    ComboBox1.Items.Add(oneItem.Id)
                    ComboBox3.Items.Add(oneItem.Id)
                End If
            Next

            ' Fill the comboBox items with the values of the Relationships table.
            For Each oneItem As Relationship In relationships
                If (oneItem.IsDeleted = False) Then
                    ComboBox2.Items.Add(oneItem.Id)
                End If
            Next
        Catch

        End Try
    End Sub

#End Region

End Class