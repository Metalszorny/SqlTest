' Interaction logic for Form1.
Public Class Form1

#Region "Methods"

    ' Handles the Click event of the button1 control.
    Private Sub Button1_Click(sender As Object, e As EventArgs) Handles Button1.Click
        ' Open the People Form.
        Dim people As Form2
        people = New Form2()
        people.Show()
        people = Nothing
    End Sub

    ' Handles the Click event of the button2 control.
    Private Sub Button2_Click(sender As Object, e As EventArgs) Handles Button2.Click
        ' Open the Relationships Form.
        Dim relationships As Form3
        relationships = New Form3()
        relationships.Show()
        relationships = Nothing
    End Sub

    ' Handles the Click event of the button3 control.
    Private Sub Button3_Click(sender As Object, e As EventArgs) Handles Button3.Click
        ' Open the Relations Form.
        Dim relations As Form4
        relations = New Form4()
        relations.Show()
        relations = Nothing
    End Sub

    ' Handles the Click event of the button4 control.
    Private Sub Button4_Click(sender As Object, e As EventArgs) Handles Button4.Click
        ' Exit the Program.
        Close()
    End Sub

#End Region

End Class