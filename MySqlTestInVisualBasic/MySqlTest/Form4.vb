Imports MySql.Data.MySqlClient

' Interaction logic for Form4.
Public Class Form4

#Region "Fields"

    ' The database connectionString.
    Private url As String = "SERVER=localhost;DATABASE=MySqlTestDatabase;UID=root;PASSWORD=root;"

    ' The Id value.
    Private idValue As Integer

    ' The Name1 value.
    Private name1Value As Integer

    ' The Relationship value.
    Private relationshipValue As Integer

    ' The Name2 value.
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
                Dim mySqlConnection As MySqlConnection = New MySqlConnection(url)
                mySqlConnection.Open()

                ' Get the items from the Relations table.
                Dim relation As Relation = New Relation()
                Dim mySqlCommand As MySqlCommand = New MySqlCommand("SELECT * FROM MySqlTestDatabase.Relations WHERE Id = @param1", mySqlConnection)

                ' Fill the values of the command.
                mySqlCommand.Parameters.AddWithValue("@param1", idValue)

                ' Execute.
                Dim mySqlDataReader As MySqlDataReader = mySqlCommand.ExecuteReader()

                ' Store the items in a Relation object.
                While mySqlDataReader.Read()
                    relation = New Relation(mySqlDataReader.GetInt32(0), mySqlDataReader.GetInt32(1), mySqlDataReader.GetInt32(2),
                            mySqlDataReader.GetInt32(3), mySqlDataReader.GetBoolean(4))
                End While

                ' Close the datareader and the connection.
                mySqlDataReader.Close()
                mySqlConnection.Close()

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
                Dim mySqlConnection As MySqlConnection = New MySqlConnection(url)
                mySqlConnection.Open()

                ' Edit the IsDeleted value to true.
                Dim mySqlCommand1 As MySqlCommand = New MySqlCommand("SELECT * FROM MySqlTestDatabase.Relations", mySqlConnection)

                ' Execute.
                Dim mySqlDataReader1 As MySqlDataReader = mySqlCommand1.ExecuteReader()

                ' Get the number of the existing items.
                While mySqlDataReader1.Read()
                    idValue += 1

                    ' Search for a deleted matching item.
                    If (matchFound = False And
                            mySqlDataReader1.GetInt32(1) = name1Value And
                            mySqlDataReader1.GetInt32(2) = relationshipValue And
                            mySqlDataReader1.GetInt32(3) = name2Value And
                            mySqlDataReader1.GetBoolean(4) = True) Then
                        matchFound = True
                        idValue = mySqlDataReader1.GetInt32(0)

                        Exit While
                    End If
                End While

                ' Close the dataReader.
                mySqlDataReader1.Close()

                ' Add a new item if no deleted match found else restore the deleted item.
                If matchFound = False Then
                    ' Edit the IsDeleted value to true.
                    Dim mySqlCommand As MySqlCommand = New MySqlCommand("INSERT INTO MySqlTestDatabase.Relations (Id, Person1, Relationship, Person2, IsDeleted) VALUES (@param1, @param2, @param3, @param4, @param5)", mySqlConnection)

                    ' Fill the values of the command.
                    mySqlCommand.Parameters.AddWithValue("@param1", idValue + 1)
                    mySqlCommand.Parameters.AddWithValue("@param2", name1Value)
                    mySqlCommand.Parameters.AddWithValue("@param3", relationshipValue)
                    mySqlCommand.Parameters.AddWithValue("@param4", name2Value)
                    mySqlCommand.Parameters.AddWithValue("@param5", False)

                    ' Execute.
                    mySqlCommand.ExecuteNonQuery()
                Else
                    ' Edit the IsDeleted value to false.
                    Dim mySqlCommand As MySqlCommand = New MySqlCommand("UPDATE MySqlTestDatabase.Relations SET IsDeleted = @param2 WHERE Id = @param1", mySqlConnection)

                    ' Fill the values of the command.
                    mySqlCommand.Parameters.AddWithValue("@param1", idValue)
                    mySqlCommand.Parameters.AddWithValue("@param2", False)

                    ' Execute.
                    mySqlCommand.ExecuteNonQuery()
                End If

                ' Close the connection.
                mySqlConnection.Close()

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
                    Dim mySqlConnection As MySqlConnection = New MySqlConnection(url)
                    mySqlConnection.Open()

                    ' Edit the IsDeleted value to true.
                    Dim mySqlCommand As MySqlCommand = New MySqlCommand("UPDATE MySqlTestDatabase.Relations SET Person1 = @param2, Relationship = @param3, Person2 = @param4 WHERE Id = @param1", mySqlConnection)

                    ' Fill the values of the command.
                    mySqlCommand.Parameters.AddWithValue("@param1", idValue)
                    mySqlCommand.Parameters.AddWithValue("@param2", name1Value)
                    mySqlCommand.Parameters.AddWithValue("@param3", relationshipValue)
                    mySqlCommand.Parameters.AddWithValue("@param4", name2Value)

                    ' Execute.
                    mySqlCommand.ExecuteNonQuery()

                    ' Close the connection.
                    mySqlConnection.Close()

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
                Dim mySqlConnection As MySqlConnection = New MySqlConnection(url)
                mySqlConnection.Open()

                ' Edit the IsDeleted value to true.
                Dim mySqlCommand As MySqlCommand = New MySqlCommand("UPDATE MySqlTestDatabase.Relations SET IsDeleted = @param2 WHERE Id = @param1", mySqlConnection)

                ' Fill the values of the command.
                mySqlCommand.Parameters.AddWithValue("@param1", idValue)
                mySqlCommand.Parameters.AddWithValue("@param2", True)

                ' Execute.
                mySqlCommand.ExecuteNonQuery()

                ' Close the connection.
                mySqlConnection.Close()

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
            Dim mySqlConnection As MySqlConnection = New MySqlConnection(url)
            mySqlConnection.Open()

            ' Get the items from the People table.
            Dim retVal As Person = New Person
            Dim mySqlCommand As MySqlCommand = New MySqlCommand("SELECT * FROM MySqlTestDatabase.People WHERE Id = @param1", mySqlConnection)

            ' Fill the values of the command.
            mySqlCommand.Parameters.AddWithValue("@param1", name1Value)

            ' Execute.
            Dim mySqlDataReader As MySqlDataReader = mySqlCommand.ExecuteReader()

            ' Store the items in a Person object.
            While mySqlDataReader.Read()
                retVal = New Person(mySqlDataReader.GetInt32(0), mySqlDataReader.GetString(1), mySqlDataReader.GetString(2),
                        mySqlDataReader.GetString(3), mySqlDataReader.GetDateTime(4), mySqlDataReader.GetBoolean(5))
            End While

            ' Give the helper label the selected value.
            Label7.Text = retVal.Name

            ' Close the datareader and the connection.
            mySqlDataReader.Close()
            mySqlConnection.Close()
        Catch

        End Try
    End Sub

    ' Handles the SelectedIndexChanged event of the ComboBox2 control.
    Private Sub ComboBox2_SelectedIndexChanged(sender As Object, e As EventArgs) Handles ComboBox1.SelectedIndexChanged, ComboBox2.SelectedIndexChanged
        Try
            ' Store the comboBox SelectedItem.
            relationshipValue = Integer.Parse(ComboBox2.SelectedItem.ToString())

            ' Open a connection to the database.
            Dim mySqlConnection As MySqlConnection = New MySqlConnection(url)
            mySqlConnection.Open()

            ' Get the items from the Relationships table.
            Dim retVal As Relationship = New Relationship
            Dim mySqlCommand As MySqlCommand = New MySqlCommand("SELECT * FROM MySqlTestDatabase.Relationships WHERE Id = @param1", mySqlConnection)

            ' Fill the values of the command.
            mySqlCommand.Parameters.AddWithValue("@param1", relationshipValue)

            ' Execute.
            Dim mySqlDataReader As MySqlDataReader = mySqlCommand.ExecuteReader()

            ' Store the items in a Relationship object.
            While mySqlDataReader.Read()
                retVal = New Relationship(mySqlDataReader.GetInt32(0), mySqlDataReader.GetString(1), mySqlDataReader.GetBoolean(2))
            End While

            ' Give the helper label the selected value.
            Label8.Text = retVal.Name

            ' Close the datareader and the connection.
            mySqlDataReader.Close()
            mySqlConnection.Close()
        Catch

        End Try
    End Sub

    ' Handles the SelectedIndexChanged event of the ComboBox3 control.
    Private Sub ComboBox3_SelectedIndexChanged(sender As Object, e As EventArgs) Handles ComboBox1.SelectedIndexChanged, ComboBox3.SelectedIndexChanged
        Try
            ' Store the comboBox SelectedItem.
            name2Value = Integer.Parse(ComboBox3.SelectedItem.ToString())

            ' Open a connection to the database.
            Dim mySqlConnection As MySqlConnection = New MySqlConnection(url)
            mySqlConnection.Open()

            ' Get the items from the People table.
            Dim retVal As Person = New Person
            Dim mySqlCommand As MySqlCommand = New MySqlCommand("SELECT * FROM MySqlTestDatabase.People WHERE Id = @param1", mySqlConnection)

            ' Fill the values of the command.
            mySqlCommand.Parameters.AddWithValue("@param1", name2Value)

            ' Execute.
            Dim mySqlDataReader As MySqlDataReader = mySqlCommand.ExecuteReader()

            ' Store the items in a Person object.
            While mySqlDataReader.Read()
                retVal = New Person(mySqlDataReader.GetInt32(0), mySqlDataReader.GetString(1), mySqlDataReader.GetString(2),
                        mySqlDataReader.GetString(3), mySqlDataReader.GetDateTime(4), mySqlDataReader.GetBoolean(5))
            End While

            ' Give the helper label the selected value.
            Label9.Text = retVal.Name

            ' Close the datareader and the connection.
            mySqlDataReader.Close()
            mySqlConnection.Close()
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
            Dim mySqlConnection As MySqlConnection = New MySqlConnection(url)
            mySqlConnection.Open()

            ' Get the items from the People table.
            Dim people As List(Of Person) = New List(Of Person)
            Dim mySqlCommand1 As MySqlCommand = New MySqlCommand("SELECT * FROM MySqlTestDatabase.People", mySqlConnection)

            ' Execute.
            Dim mySqlDataReader1 As MySqlDataReader = mySqlCommand1.ExecuteReader()

            ' Store the items in a Person list.
            While mySqlDataReader1.Read()
                people.Add(New Person(mySqlDataReader1.GetInt32(0), mySqlDataReader1.GetString(1), mySqlDataReader1.GetString(2), mySqlDataReader1.GetString(3),
                                      mySqlDataReader1.GetDateTime(4), mySqlDataReader1.GetBoolean(5)))
            End While

            ' Close the datareader.
            mySqlDataReader1.Close()

            ' Get the items from the Relationships table.
            Dim relationships As List(Of Relationship) = New List(Of Relationship)
            Dim mySqlCommand2 As MySqlCommand = New MySqlCommand("SELECT * FROM MySqlTestDatabase.Relationships", mySqlConnection)

            ' Execute.
            Dim mySqlDataReader2 As MySqlDataReader = mySqlCommand2.ExecuteReader()

            ' Store the items in a Relationship list.
            While mySqlDataReader2.Read()
                relationships.Add(New Relationship(mySqlDataReader2.GetInt32(0), mySqlDataReader2.GetString(1), mySqlDataReader2.GetBoolean(2)))
            End While

            ' Close the datareader.
            mySqlDataReader2.Close()

            ' Get the items from the Relations table.
            Dim relations As List(Of Relation) = New List(Of Relation)
            Dim mySqlCommand As MySqlCommand = New MySqlCommand("SELECT * FROM MySqlTestDatabase.Relations WHERE IsDeleted = 0", mySqlConnection)

            ' Execute.
            Dim mySqlDataReader As MySqlDataReader = mySqlCommand.ExecuteReader()

            ' Store the items in a Relation list.
            While mySqlDataReader.Read()
                relations.Add(New Relation(mySqlDataReader.GetInt32(0), mySqlDataReader.GetInt32(1), mySqlDataReader.GetInt32(2),
                        mySqlDataReader.GetInt32(3), mySqlDataReader.GetBoolean(4)))
            End While

            ' Close the datareader and the connection.
            mySqlDataReader.Close()
            mySqlConnection.Close()

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