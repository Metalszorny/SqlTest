Imports System.Data.OracleClient

' Interaction logic for Form3.
Public Class Form3

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
            Catch
                ' Empty the textBox Texts.
                TextBox1.Text = ""
            End Try
        Else
            ' Empty the textBox Texts.
            TextBox1.Text = ""
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
            If ((nameValue <> Nothing) And (nameValue <> "")) Then
                idValue = 0
                Dim matchFound As Boolean = False
                Dim deletedFound As Boolean = False

                ' Open a connection to the database.
                Dim oracleSqlConnection As OracleConnection = New OracleConnection(url)
                oracleSqlConnection.Open()

                ' Edit the IsDeleted value to true.
                Dim oracleSqlCommand1 As OracleCommand = New OracleCommand("SELECT * FROM root.Relationships", oracleSqlConnection)
                Dim oracleSqlDataReader1 As OracleDataReader = oracleSqlCommand1.ExecuteReader()

                ' Get the number of the existing items.
                While oracleSqlDataReader1.Read()
                    idValue += 1

                    ' Search for an already matching item.
                    If (matchFound = False And
                            oracleSqlDataReader1.GetString(1) = nameValue And
                            oracleSqlDataReader1.GetInt32(2) = 0) Then
                        matchFound = True

                        Exit While
                    End If

                    ' Search for a deleted matching item.
                    If (deletedFound = False And
                            oracleSqlDataReader1.GetString(1) = nameValue And
                            oracleSqlDataReader1.GetInt32(2) = 1) Then
                        deletedFound = True
                        idValue = oracleSqlDataReader1.GetInt32(0)

                        Exit While
                    End If
                End While

                ' Close the dataReader.
                oracleSqlDataReader1.Close()

                ' If no match was found.
                If matchFound = False Then
                    ' Add a new item if no deleted match was found else restore the deleted item.
                    If deletedFound = False Then
                        ' Edit the IsDeleted value to true.
                        Dim oracleSqlCommand As OracleCommand = New OracleCommand("INSERT INTO root.Relationships (Id, Name, IsDeleted) VALUES (:param1, :param2, :param3)", oracleSqlConnection)

                        ' Fill the values of the command.
                        oracleSqlCommand.Parameters.AddWithValue(":param1", idValue + 1)
                        oracleSqlCommand.Parameters.AddWithValue(":param2", nameValue)
                        oracleSqlCommand.Parameters.AddWithValue(":param3", 0)

                        ' Execute.
                        oracleSqlCommand.ExecuteNonQuery()
                    Else
                        ' Edit the IsDeleted value to false.
                        Dim oracleSqlCommand As OracleCommand = New OracleCommand("UPDATE root.Relationships SET IsDeleted = :param2 WHERE Id = :param1", oracleSqlConnection)

                        ' Fill the values of the command.
                        oracleSqlCommand.Parameters.AddWithValue(":param1", idValue)
                        oracleSqlCommand.Parameters.AddWithValue(":param2", 0)

                        ' Execute.
                        oracleSqlCommand.ExecuteNonQuery()
                    End If
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
            If ((nameValue <> Nothing) And (nameValue <> "")) Then
                ' An item must be selected in the dataGridView.
                If (DataGridView1.CurrentCellAddress.X >= 0) Then
                    ' Get the Id value of the selected item.
                    idValue = Integer.Parse(DataGridView1.Rows(DataGridView1.SelectedCells(0).RowIndex).Cells("Column1").Value.ToString())

                    ' Open a connection to the database.
                    Dim oracleSqlConnection As OracleConnection = New OracleConnection(url)
                    oracleSqlConnection.Open()

                    ' Edit the IsDeleted value to true.
                    Dim oracleSqlCommand As OracleCommand = New OracleCommand("UPDATE root.Relationships SET Name = :param2 WHERE Id = :param1", oracleSqlConnection)

                    ' Fill the values of the command.
                    oracleSqlCommand.Parameters.AddWithValue(":param1", idValue)
                    oracleSqlCommand.Parameters.AddWithValue(":param2", nameValue)

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
                Dim oracleSqlCommand As OracleCommand = New OracleCommand("UPDATE root.Relationships SET IsDeleted = :param2 WHERE Id = :param1", oracleSqlConnection)

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

    ' Handles the Load event of the Form3 control.
    Private Sub Form3_Load(sender As Object, e As EventArgs) Handles MyBase.Load
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

            ' Get the items from the Relationships table.
            Dim relationship As List(Of Relationship) = New List(Of Relationship)
            Dim oracleSqlCommand As OracleCommand = New OracleCommand("SELECT * FROM root.Relationships WHERE IsDeleted = 0", oracleSqlConnection)

            ' Execute.
            Dim oracleSqlDataReader As OracleDataReader = oracleSqlCommand.ExecuteReader()

            ' Store the items in a Relationship list.
            While oracleSqlDataReader.Read()
                relationship.Add(New Relationship(oracleSqlDataReader.GetInt32(0), oracleSqlDataReader.GetString(1), If(oracleSqlDataReader.GetInt32(2), True, False)))
            End While

            ' Close the datareader and the connection.
            oracleSqlDataReader.Close()
            oracleSqlConnection.Close()

            ' Fill the dataGridView rows with the values of the Relationship table.
            For Each oneItem As Relationship In relationship
                Dim row As DataGridViewRow = New DataGridViewRow()
                Dim cell1 As DataGridViewCell = New DataGridViewTextBoxCell()
                Dim cell2 As DataGridViewCell = New DataGridViewTextBoxCell()

                cell1.Value = oneItem.Id.ToString()
                cell2.Value = oneItem.Name

                row.Cells.Add(cell1)
                row.Cells.Add(cell2)

                DataGridView1.Rows.Add(row)
            Next
        Catch

        End Try
    End Sub

#End Region

End Class