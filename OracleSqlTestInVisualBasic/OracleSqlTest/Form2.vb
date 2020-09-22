Imports System.Data.OracleClient

' Interaction logic for Form2.
Public Class Form2

#Region "Fields"

    ' The database connectionString.
    Private url As String = "Data Source=(DESCRIPTION=(ADDRESS_LIST=(ADDRESS=(PROTOCOL=TCP)" +
                             "(HOST=localhost)(PORT=1521)))" +
                             "(CONNECT_DATA=(SERVER=DEDICATED)(SERVICE_NAME=orcl)));" +
                             "User Id=root;Password=root;"

    ' The id value.
    Private idValue As Integer

    ' The name value.
    Private nameValue As String

    ' The mothername value.
    Private mothernameValue As String

    ' The location value.
    Private locationValue As String

    ' The birthdate value.
    Private birthdateValue As String

#End Region

#Region "Methods"

    ' Handles the CellClick event of the DataGridView1 control.
    Private Sub DataGridView1_CellClick(sender As Object, e As DataGridViewCellEventArgs) Handles DataGridView1.CellClick
        ' An item must be selected in the dataGridView.
        If (DataGridView1.CurrentCellAddress.X >= 0) Then
            Try
                ' Get the selected row.
                Dim selectedRow As DataGridViewRow = DataGridView1.Rows(DataGridView1.SelectedCells(0).RowIndex)

                ' Give the textBox Texts the selected values.
                TextBox1.Text = selectedRow.Cells("Column2").Value.ToString()
                TextBox2.Text = selectedRow.Cells("Column3").Value.ToString()
                TextBox3.Text = selectedRow.Cells("Column4").Value.ToString()
                TextBox4.Text = selectedRow.Cells("Column5").Value.ToString().Split(" ")(0)
            Catch
                ' Empty the textBox Texts.
                TextBox1.Text = ""
                TextBox2.Text = ""
                TextBox3.Text = ""
                TextBox4.Text = ""
            End Try
        Else
            ' Empty the textBox Texts.
            TextBox1.Text = ""
            TextBox2.Text = ""
            TextBox3.Text = ""
            TextBox4.Text = ""
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
            If ((mothernameValue <> Nothing) And (locationValue <> Nothing) And (nameValue <> Nothing) And (birthdateValue <> Nothing) And
                (nameValue <> "") And (mothernameValue <> "") And (locationValue <> "") And (birthdateValue <> "")) Then
                idValue = 0
                Dim matchFound As Boolean = False

                ' Open a connection to the database.
                Dim oracleSqlConnection As OracleConnection = New OracleConnection(url)
                oracleSqlConnection.Open()

                ' Edit the IsDeleted value to true.
                Dim oracleSqlCommand1 As OracleCommand = New OracleCommand("SELECT * FROM root.People", oracleSqlConnection)

                ' Execute.
                Dim oracleSqlDataReader1 As OracleDataReader = oracleSqlCommand1.ExecuteReader()

                ' Get the number of the existing items.
                While oracleSqlDataReader1.Read()
                    idValue += 1

                    ' Search for a deleted matching item.
                    If (matchFound = False And
                            oracleSqlDataReader1.GetString(1) = nameValue And
                            oracleSqlDataReader1.GetString(2) = mothernameValue And
                            oracleSqlDataReader1.GetString(3) = locationValue And
                            oracleSqlDataReader1.GetDateTime(4) = DateTime.Parse(birthdateValue) And
                            oracleSqlDataReader1.GetInt32(5) = 1) Then
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
                    Dim oracleSqlCommand As OracleCommand = New OracleCommand("INSERT INTO root.People (Id, Name, Mothername, Location, Birthdate, IsDeleted) VALUES (:param1, :param2, :param3, :param4, :param5, :param6)", oracleSqlConnection)

                    ' Fill the values of the command.
                    oracleSqlCommand.Parameters.AddWithValue(":param1", idValue + 1)
                    oracleSqlCommand.Parameters.AddWithValue(":param2", nameValue)
                    oracleSqlCommand.Parameters.AddWithValue(":param3", mothernameValue)
                    oracleSqlCommand.Parameters.AddWithValue(":param4", locationValue)
                    oracleSqlCommand.Parameters.AddWithValue(":param5", DateTime.Parse(birthdateValue))
                    oracleSqlCommand.Parameters.AddWithValue(":param6", 0)

                    ' Execute.
                    oracleSqlCommand.ExecuteNonQuery()
                Else
                    ' Edit the IsDeleted value to false.
                    Dim oracleSqlCommand As OracleCommand = New OracleCommand("UPDATE root.People SET IsDeleted = :param2 WHERE Id = :param1", oracleSqlConnection)

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
            If ((mothernameValue <> Nothing) And (locationValue <> Nothing) And (nameValue <> Nothing) And (birthdateValue <> Nothing) And
                (nameValue <> "") And (mothernameValue <> "") And (locationValue <> "") And (birthdateValue <> "")) Then
                ' An item must be selected in the dataGridView.
                If (DataGridView1.CurrentCellAddress.X >= 0) Then
                    ' Get the Id value of the selected item.
                    idValue = Integer.Parse(DataGridView1.Rows(DataGridView1.SelectedCells(0).RowIndex).Cells("Column1").Value.ToString())

                    ' Open a connection to the database.
                    Dim oracleSqlConnection As OracleConnection = New OracleConnection(url)
                    oracleSqlConnection.Open()

                    ' Edit the IsDeleted value to true.
                    Dim oracleSqlCommand As OracleCommand = New OracleCommand("UPDATE root.People SET Name = :param2, Mothername = :param3, Location = :param4, BirthDate = :param5 WHERE Id = :param1", oracleSqlConnection)

                    ' Fill the values of the command.
                    oracleSqlCommand.Parameters.AddWithValue(":param1", idValue)
                    oracleSqlCommand.Parameters.AddWithValue(":param2", nameValue)
                    oracleSqlCommand.Parameters.AddWithValue(":param3", mothernameValue)
                    oracleSqlCommand.Parameters.AddWithValue(":param4", locationValue)
                    oracleSqlCommand.Parameters.AddWithValue(":param5", DateTime.Parse(birthdateValue))

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
                Dim oracleSqlCommand As OracleCommand = New OracleCommand("UPDATE root.People SET IsDeleted = :param2 WHERE Id = :param1", oracleSqlConnection)

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

    ' Handles the TextChanged event of the TextBox1 control.
    Private Sub TextBox1_TextChanged(sender As Object, e As EventArgs) Handles TextBox1.TextChanged
        ' Give the field the textBox Text.
        nameValue = TextBox1.Text
    End Sub

    ' Handles the TextChanged event of the TextBox2 control.
    Private Sub TextBox2_TextChanged(sender As Object, e As EventArgs) Handles TextBox2.TextChanged
        ' Give the field the textBox Text.
        mothernameValue = TextBox2.Text
    End Sub

    ' Handles the TextChanged event of the TextBox3 control.
    Private Sub TextBox3_TextChanged(sender As Object, e As EventArgs) Handles TextBox3.TextChanged
        ' Give the field the textBox Text.
        locationValue = TextBox3.Text
    End Sub

    ' Handles the TextChanged event of the TextBox4 control.
    Private Sub TextBox4_TextChanged(sender As Object, e As EventArgs) Handles TextBox4.TextChanged
        ' Give the field the textBox Text.
        birthdateValue = TextBox4.Text
    End Sub

    ' Handles the Load event of the Form2 control.
    Private Sub Form2_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        ' Preset the values.
        GetData()
    End Sub

    ' Gets the data.
    Private Sub GetData()
        Try
            ' Clear existing items.
            DataGridView1.Rows.Clear()

            ' Open a connection to the database.
            Dim oracleSqlConnection As OracleConnection = New OracleConnection(url)
            oracleSqlConnection.Open()

            ' Get the items from the People table.
            Dim people As List(Of Person) = New List(Of Person)
            Dim oracleSqlCommand As OracleCommand = New OracleCommand("SELECT * FROM root.People WHERE IsDeleted = 0", oracleSqlConnection)

            ' Execute.
            Dim oracleSqlDataReader As OracleDataReader = oracleSqlCommand.ExecuteReader()

            ' Store the items in a Person list.
            While oracleSqlDataReader.Read()
                people.Add(New Person(oracleSqlDataReader.GetInt32(0), oracleSqlDataReader.GetString(1), oracleSqlDataReader.GetString(2), oracleSqlDataReader.GetString(3),
                                      oracleSqlDataReader.GetDateTime(4), If(oracleSqlDataReader.GetInt32(5), True, False)))
            End While

            ' Close the datareader and the connection.
            oracleSqlDataReader.Close()
            oracleSqlConnection.Close()

            ' Fill the dataGridView rows with the values of the People table.
            For Each oneItem As Person In people
                Dim row As DataGridViewRow = New DataGridViewRow()
                Dim cell1 As DataGridViewCell = New DataGridViewTextBoxCell()
                Dim cell2 As DataGridViewCell = New DataGridViewTextBoxCell()
                Dim cell3 As DataGridViewCell = New DataGridViewTextBoxCell()
                Dim cell4 As DataGridViewCell = New DataGridViewTextBoxCell()
                Dim cell5 As DataGridViewCell = New DataGridViewTextBoxCell()

                cell1.Value = oneItem.Id.ToString()
                cell2.Value = oneItem.Name
                cell3.Value = oneItem.Mothername
                cell4.Value = oneItem.Location
                cell5.Value = oneItem.BirthDate.ToString()

                row.Cells.Add(cell1)
                row.Cells.Add(cell2)
                row.Cells.Add(cell3)
                row.Cells.Add(cell4)
                row.Cells.Add(cell5)

                DataGridView1.Rows.Add(row)
            Next
        Catch

        End Try
    End Sub

#End Region

End Class