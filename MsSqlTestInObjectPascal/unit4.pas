unit Unit4;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, mssqlconn, sqldb, FileUtil, Forms, Controls, Graphics,
  Dialogs, StdCtrls, Grids, Contnrs, Person, Relationship, Relation;

type

  { TForm4 }

  TForm4 = class(TForm)
    Button1: TButton;
    Button2: TButton;
    Button3: TButton;
    Button4: TButton;
    Button5: TButton;
    ComboBox1: TComboBox;
    ComboBox2: TComboBox;
    ComboBox3: TComboBox;
    GroupBox1: TGroupBox;
    GroupBox2: TGroupBox;
    Label1: TLabel;
    Label2: TLabel;
    Label3: TLabel;
    Label4: TLabel;
    Label5: TLabel;
    Label6: TLabel;
    Label7: TLabel;
    Label8: TLabel;
    Label9: TLabel;
    MSSQLConnection1: TMSSQLConnection;
    SQLQuery1: TSQLQuery;
    SQLTransaction1: TSQLTransaction;
    StringGrid1: TStringGrid;
    procedure Button1Click(Sender: TObject);
    procedure Button2Click(Sender: TObject);
    procedure Button3Click(Sender: TObject);
    procedure Button4Click(Sender: TObject);
    procedure Button5Click(Sender: TObject);
    procedure ComboBox1Change(Sender: TObject);
    procedure ComboBox2Change(Sender: TObject);
    procedure ComboBox3Change(Sender: TObject);
    procedure FormShow(Sender: TObject);
    procedure StringGrid1SelectCell(Sender: TObject; aCol, aRow: Integer;
      var CanSelect: Boolean);
  private
    { private declarations }
  public
    { public declarations }
  end;

var
  Form4: TForm4;
  idValue, name1Value, relationshipValue, name2Value, selectedIndex: Integer;
  sqlConnection: TMSSQLConnection;
  sqlQuery: TSQLQuery;
  sqlTransaction: TSQLTransaction;

implementation

{$R *.lfm}

var
  personList, relationshipList, relationList: TObjectList;
  i, j: Integer;
{ Gets the data. }
procedure GetData();
begin
     try
     begin
        { Clear existing items. }
        Form4.ComboBox1.Clear();
        Form4.ComboBox2.Clear();
        Form4.ComboBox3.Clear();
        Form4.StringGrid1.RowCount := 1;

        { Open a connection to the database. }
        sqlTransaction := TSQLTransaction.Create(nil);
        sqlConnection := TMSSQLConnection.Create(nil);
        sqlQuery := TSQLQuery.Create(nil);

        sqlConnection.Transaction := sqlTransaction;
        sqlQuery.DataBase := sqlConnection;

        sqlConnection.HostName := 'localhost';
        sqlConnection.DatabaseName := 'MsSqlTestDatabase';
        sqlConnection.UserName := 'root';
        sqlConnection.Password := 'RootUser0123456789';
        sqlConnection.CharSet := 'UTF-8';
        sqlConnection.Connected := True;

        { Get the items from the People table. }
        sqlQuery.Close();
        sqlQuery.SQL.Text := 'SELECT * FROM [MsSqlTestDatabase].[dbo].[People]';

        { Execute. }
        sqlQuery.Open();
        personList := TObjectList.Create();

        { Store the items in a Person list. }
        while not sqlQuery.EOF do
        begin
             personList.Add(TPerson.Create(
              sqlQuery.FieldByName('Id').AsInteger,
              sqlQuery.FieldByName('Name').AsString,
              sqlQuery.FieldByName('Mothername').AsString,
              sqlQuery.FieldByName('Location').AsString,
              sqlQuery.FieldByName('Birthdate').AsDateTime,
              sqlQuery.FieldByName('IsDeleted').AsBoolean));

             sqlQuery.Next();
        end;

        { Get the items from the People table. }
        sqlQuery.Close();
        sqlQuery.SQL.Text := 'SELECT * FROM [MsSqlTestDatabase].[dbo].[Relationships]';

        { Execute. }
        sqlQuery.Open();
        relationshipList := TObjectList.Create();

        { Store the items in a Relationship list. }
        while not sqlQuery.EOF do
        begin
             relationshipList.Add(TRelationship.Create(
              sqlQuery.FieldByName('Id').AsInteger,
              sqlQuery.FieldByName('Name').AsString,
              sqlQuery.FieldByName('IsDeleted').AsBoolean));

             sqlQuery.Next();
        end;

        { Get the items from the People table. }
        sqlQuery.Close();
        sqlQuery.SQL.Text := 'SELECT * FROM [MsSqlTestDatabase].[dbo].[Relations] WHERE IsDeleted = 0';

        { Execute. }
        sqlQuery.Open();
        relationList := TObjectList.Create();

        { Store the items in a Relation list. }
        while not sqlQuery.EOF do
        begin
             relationList.Add(TRelation.Create(
              sqlQuery.FieldByName('Id').AsInteger,
              sqlQuery.FieldByName('Person1').AsInteger,
              sqlQuery.FieldByName('Relationship').AsInteger,
              sqlQuery.FieldByName('Person2').AsInteger,
              sqlQuery.FieldByName('IsDeleted').AsBoolean));

             sqlQuery.Next();
        end;

        { Close the datareader and the connection. }
        sqlQuery.Close();
        sqlConnection.Close();

        { Fill the StringGrid rows with the values of the Relations table. }
        for i := 0 to relationList.Count - 1 do
        begin
            Form4.StringGrid1.RowCount := Form4.StringGrid1.RowCount + 1;

            Form4.StringGrid1.Cells[0, i + 1] := IntToStr(TRelation(relationList[i]).getId());

            { Substitute the Person1 and Person2 ids with their names. }
            for j := 0 to personList.Count - 1 do
            begin
               if (TRelation(relationList[i]).getPerson1() = TPerson(personList[j]).getId()) then
               begin
                  Form4.StringGrid1.Cells[1, i + 1] := TPerson(personList[j]).getName();
               end;

               if (TRelation(relationList[i]).getPerson2() = TPerson(personList[j]).getId()) then
               begin
                  Form4.StringGrid1.Cells[3, i + 1] := TPerson(personList[j]).getName();
               end;
            end;

            { Substitute the Relationship ids with their names. }
            for j := 0 to relationshipList.Count - 1 do
            begin
               if (TRelation(relationList[i]).getRelationship() = TRelationship(relationshipList[j]).getId()) then
               begin
                 Form4.StringGrid1.Cells[2, i + 1] := TPerson(relationshipList[j]).getName();
               end;
            end;
        end;

        { Fill the comboBox items with the values of the People table. }
        for i := 0 to personList.Count - 1 do
        begin
           if (TPerson(personList[i]).getIsDeleted() = False) then
           begin
             Form4.ComboBox1.Items.Add(IntToStr(TPerson(personList[i]).getId()));
             Form4.ComboBox3.Items.Add(IntToStr(TPerson(personList[i]).getId()));
           end;
        end;

        { Fill the comboBox items with the values of the Relationships table. }
        for i := 0 to relationshipList.Count - 1 do
        begin
           if (TRelationship(relationshipList[i]).getIsDeleted() = False) then
           begin
             Form4.ComboBox2.Items.Add(IntToStr(TRelationship(relationshipList[i]).getId()));
           end;
        end;
     end;
     except
     begin

     end;
     end;
end;

{ Handles the Click event of the Button1 control. }
procedure TForm4.Button1Click(Sender: TObject);
begin
     { Lists the Relation items. }
     GetData();
end;

var
  matchFound: Boolean;
{ Handles the Click event of the Button2 control. }
procedure TForm4.Button2Click(Sender: TObject);
begin
     { Adds a Relation item. }
     try
     begin
        { The fields must not be empty. }
        if ((name1Value <> 0) And (relationshipValue <> 0) And (name2Value <> 0)) then
        begin
           idValue := 0;
           matchFound := False;

           { Open a connection to the database. }
           sqlTransaction := TSQLTransaction.Create(nil);
           sqlConnection := TMSSQLConnection.Create(nil);
           sqlQuery := TSQLQuery.Create(nil);

           sqlConnection.Transaction := sqlTransaction;
           sqlQuery.DataBase := sqlConnection;

           sqlConnection.HostName := 'localhost';
           sqlConnection.DatabaseName := 'MsSqlTestDatabase';
           sqlConnection.UserName := 'root';
           sqlConnection.Password := 'RootUser0123456789';
           sqlConnection.CharSet := 'UTF-8';
           sqlConnection.Connected := True;

           { Get the items from the Relations table. }
           sqlQuery.Close();
           sqlQuery.SQL.Text := 'SELECT * FROM [MsSqlTestDatabase].[dbo].[Relations]';

           { Execute. }
           sqlQuery.Open();

           { Get the number of the existing items. }
           while not sqlQuery.EOF do
           begin
               idValue += 1;

               { Search for deleted matches. }
               if ((matchFound = False) And
                  (sqlQuery.FieldByName('Person1').AsInteger = name1Value) And
                  (sqlQuery.FieldByName('Relationship').AsInteger = relationshipValue) And
                  (sqlQuery.FieldByName('Person2').AsInteger = name2Value) And
                  (sqlQuery.FieldByName('IsDeleted').AsBoolean = True)) then
               begin
                  matchFound := True;
                  idValue := sqlQuery.FieldByName('Id').AsInteger;

                  Break;
               end;

               sqlQuery.Next();
            end;

           { Add a new item if no match exists or restore the deleted item. }
           if (matchFound = False) then
           begin
              { Add new item to the Relations table. }
              sqlQuery.Close();
              sqlQuery.SQL.Text := 'INSERT INTO [MsSqlTestDatabase].[dbo].[Relations] (Id, Person1, Relationship, Person2, IsDeleted) VALUES (:param1, :param2, :param3, :param4, :param5)';

              { Fill the values of the command. }
              sqlQuery.Params.ParamByName('param1').AsInteger := idValue + 1;
              sqlQuery.Params.ParamByName('param2').AsInteger := name1Value;
              sqlQuery.Params.ParamByName('param3').AsInteger := relationshipValue;
              sqlQuery.Params.ParamByName('param4').AsInteger := name2Value;
              sqlQuery.Params.ParamByName('param5').AsBoolean := False;

              { Execute. }
              sqlQuery.ExecSQL;
              sqlTransaction.Commit;
           end
           else
           begin
              { Edit the IsDeleted value to false. }
              sqlQuery.Close();
              sqlQuery.SQL.Text := 'UPDATE [MsSqlTestDatabase].[dbo].[Relations] SET IsDeleted = :param2 WHERE Id = :param1';

              { Fill the values of the command. }
              sqlQuery.Params.ParamByName('param1').AsInteger := idValue;
              sqlQuery.Params.ParamByName('param2').AsBoolean := False;

              { Execute. }
              sqlQuery.ExecSQL;
              sqlTransaction.Commit;
           end;

           { Close the connection. }
           sqlQuery.Close();
           sqlConnection.Close();

           { Refresh. }
           GetData();
        end;
     end;
     except
     begin

     end;
     end;
end;

{ Handles the Click event of the Button3 control. }
procedure TForm4.Button3Click(Sender: TObject);
begin
     { Edits a Relation item. }
     try
     begin
        { The fields must not be empty. }
        if ((name1Value <> 0) And (relationshipValue <> 0) And (name2Value <> 0) And (idValue <> 0)) then
        begin
           { An item must be selected in the StringGrid1. }
           if (selectedIndex >= 1) then
           begin
             { Get the Id value of the selected item. }
             idValue := StrToInt(Form4.StringGrid1.Cells[0, selectedIndex]);

             { Open a connection to the database. }
             sqlTransaction := TSQLTransaction.Create(nil);
             sqlConnection := TMSSQLConnection.Create(nil);
             sqlQuery := TSQLQuery.Create(nil);

             sqlConnection.Transaction := sqlTransaction;
             sqlQuery.DataBase := sqlConnection;

             sqlConnection.HostName := 'localhost';
             sqlConnection.DatabaseName := 'MsSqlTestDatabase';
             sqlConnection.UserName := 'root';
             sqlConnection.Password := 'RootUser0123456789';
             sqlConnection.CharSet := 'UTF-8';
             sqlConnection.Connected := True;

             { Update the values in the Relations table. }
             sqlQuery.Close();
             sqlQuery.SQL.Text := 'UPDATE [MsSqlTestDatabase].[dbo].[Relations] SET Person1 = :param2, Relationship = :param3, Person2 = :param4 WHERE Id = :param1';

             { Fill the values of the command. }
             sqlQuery.Params.ParamByName('param1').AsInteger := idValue;
             sqlQuery.Params.ParamByName('param2').AsInteger := name1Value;
             sqlQuery.Params.ParamByName('param3').AsInteger := relationshipValue;
             sqlQuery.Params.ParamByName('param4').AsInteger := name2Value;

             { Execute. }
             sqlQuery.ExecSQL;
             sqlTransaction.Commit;

             { Close the connection. }
             sqlQuery.Close();
             sqlConnection.Close();

             { Refresh. }
             GetData();
           end;
        end;
     end;
     except
     begin

     end;
     end;
end;

{ Handles the Click event of the Button4 control. }
procedure TForm4.Button4Click(Sender: TObject);
begin
     { Deletes a Relation item. }
     try
     begin
          if (selectedIndex >= 1) then
          begin
             { Logical delete }
             { Get the Id value of the selected item. }
             idValue := StrToInt(Form4.StringGrid1.Cells[0, selectedIndex]);

             { Open a connection to the database. }
             sqlTransaction := TSQLTransaction.Create(nil);
             sqlConnection := TMSSQLConnection.Create(nil);
             sqlQuery := TSQLQuery.Create(nil);

             sqlConnection.Transaction := sqlTransaction;
             sqlQuery.DataBase := sqlConnection;

             sqlConnection.HostName := 'localhost';
             sqlConnection.DatabaseName := 'MsSqlTestDatabase';
             sqlConnection.UserName := 'root';
             sqlConnection.Password := 'RootUser0123456789';
             sqlConnection.CharSet := 'UTF-8';
             sqlConnection.Connected := True;

             { Edit the IsDeleted value to true. }
             sqlQuery.Close();
             sqlQuery.SQL.Text := 'UPDATE [MsSqlTestDatabase].[dbo].[Relations] SET IsDeleted = :param2 WHERE Id = :param1';

             { Fill the values of the command. }
             sqlQuery.Params.ParamByName('param1').AsInteger := idValue;
             sqlQuery.Params.ParamByName('param2').AsBoolean := True;

             { Execute. }
             sqlQuery.ExecSQL;
             sqlTransaction.Commit;

             { Close the connection. }
             sqlQuery.Close();
             sqlConnection.Close();

             { Refresh. }
             GetData();
          end;
     end;
     except
     begin

     end;
     end;
end;

{ Handles the Click event of the Button5 control. }
procedure TForm4.Button5Click(Sender: TObject);
begin
     { Close the TForm. }
     Close;
end;

var
  retVal1: TPerson;
{ Handles the Change event of the ComboBox1 control. }
procedure TForm4.ComboBox1Change(Sender: TObject);
begin
     try
        begin
             { Store the ComboBox selected item. }
             name1Value := StrToInt(ComboBox1.Caption);

             { Open a connection to the database. }
             sqlTransaction := TSQLTransaction.Create(nil);
             sqlConnection := TMSSQLConnection.Create(nil);
             sqlQuery := TSQLQuery.Create(nil);

             sqlConnection.Transaction := sqlTransaction;
             sqlQuery.DataBase := sqlConnection;

             sqlConnection.HostName := 'localhost';
             sqlConnection.DatabaseName := 'MsSqlTestDatabase';
             sqlConnection.UserName := 'root';
             sqlConnection.Password := 'RootUser0123456789';
             sqlConnection.CharSet := 'UTF-8';
             sqlConnection.Connected := True;

             { Get the items from the People table. }
             sqlQuery.Close();
             sqlQuery.SQL.Text := 'SELECT * FROM [MsSqlTestDatabase].[dbo].[People] WHERE Id = :param1';

             { Fill the values of the command. }
             sqlQuery.Params.ParamByName('param1').AsInteger := name1Value;

             { Execute. }
             sqlQuery.Open();

             { Get the number of the existing items. }
             while not sqlQuery.EOF do
             begin
                  retVal1 := TPerson.Create(
                   sqlQuery.FieldByName('Id').AsInteger,
                   sqlQuery.FieldByName('Name').AsString,
                   sqlQuery.FieldByName('Mothername').AsString,
                   sqlQuery.FieldByName('Location').AsString,
                   sqlQuery.FieldByName('Birthdate').AsDateTime,
                   sqlQuery.FieldByName('IsDeleted').AsBoolean);

                  sqlQuery.Next();
             end;

             { Give the helper label the selected value. }
             Form4.Label7.Caption := retVal1.getName();

             { Close the connection. }
             sqlQuery.Close();
             sqlConnection.Close();
        end;
     except
     begin

     end;
     end;
end;

var
  retVal2: TRelationship;
{ Handles the Change event of the ComboBox2 control. }
procedure TForm4.ComboBox2Change(Sender: TObject);
begin
     try
        begin
             { Store the ComboBox selected item. }
             relationshipValue := StrToInt(ComboBox2.Caption);

             { Open a connection to the database. }
             sqlTransaction := TSQLTransaction.Create(nil);
             sqlConnection := TMSSQLConnection.Create(nil);
             sqlQuery := TSQLQuery.Create(nil);

             sqlConnection.Transaction := sqlTransaction;
             sqlQuery.DataBase := sqlConnection;

             sqlConnection.HostName := 'localhost';
             sqlConnection.DatabaseName := 'MsSqlTestDatabase';
             sqlConnection.UserName := 'root';
             sqlConnection.Password := 'RootUser0123456789';
             sqlConnection.CharSet := 'UTF-8';
             sqlConnection.Connected := True;

             { Get the items from the People table. }
             sqlQuery.Close();
             sqlQuery.SQL.Text := 'SELECT * FROM [MsSqlTestDatabase].[dbo].[Relationships] WHERE Id = :param1';

             { Fill the values of the command. }
             sqlQuery.Params.ParamByName('param1').AsInteger := relationshipValue;

             { Execute. }
             sqlQuery.Open();

             { Get the number of the existing items. }
             while not sqlQuery.EOF do
             begin
                  retVal2 := TRelationship.Create(
                   sqlQuery.FieldByName('Id').AsInteger,
                   sqlQuery.FieldByName('Name').AsString,
                   sqlQuery.FieldByName('IsDeleted').AsBoolean);

                  sqlQuery.Next();
             end;

             { Give the helper label the selected value. }
             Form4.Label8.Caption := retVal2.getName();

             { Close the connection. }
             sqlQuery.Close();
             sqlConnection.Close();
        end;
     except
     begin

     end;
     end;
end;

var
  retVal3: TPerson;
{ Handles the Change event of the ComboBox3 control. }
procedure TForm4.ComboBox3Change(Sender: TObject);
begin
     try
        begin
             { Store the ComboBox selected item. }
             name2Value := StrToInt(ComboBox3.Caption);

             { Open a connection to the database. }
             sqlTransaction := TSQLTransaction.Create(nil);
             sqlConnection := TMSSQLConnection.Create(nil);
             sqlQuery := TSQLQuery.Create(nil);

             sqlConnection.Transaction := sqlTransaction;
             sqlQuery.DataBase := sqlConnection;

             sqlConnection.HostName := 'localhost';
             sqlConnection.DatabaseName := 'MsSqlTestDatabase';
             sqlConnection.UserName := 'root';
             sqlConnection.Password := 'RootUser0123456789';
             sqlConnection.CharSet := 'UTF-8';
             sqlConnection.Connected := True;

             { Get the items from the People table. }
             sqlQuery.Close();
             sqlQuery.SQL.Text := 'SELECT * FROM [MsSqlTestDatabase].[dbo].[People] WHERE Id = :param1';

             { Fill the values of the command. }
             sqlQuery.Params.ParamByName('param1').AsInteger := name2Value;

             { Execute. }
             sqlQuery.Open();

             { Get the number of the existing items. }
             while not sqlQuery.EOF do
             begin
                  retVal3 := TPerson.Create(
                   sqlQuery.FieldByName('Id').AsInteger,
                   sqlQuery.FieldByName('Name').AsString,
                   sqlQuery.FieldByName('Mothername').AsString,
                   sqlQuery.FieldByName('Location').AsString,
                   sqlQuery.FieldByName('Birthdate').AsDateTime,
                   sqlQuery.FieldByName('IsDeleted').AsBoolean);

                  sqlQuery.Next();
             end;

             { Give the helper label the selected value. }
             Form4.Label9.Caption := retVal3.getName();

             { Close the connection. }
             sqlQuery.Close();
             sqlConnection.Close();
        end;
     except
     begin

     end;
     end;
end;

{ Handles the Show event of the TForm4 control. }
procedure TForm4.FormShow(Sender: TObject);
begin
     { Presets the values. }
     Form4.Label7.Caption := '';
     Form4.Label8.Caption := '';
     Form4.Label9.Caption := '';

     GetData();
end;

var
  relationValue: TRelation;
{ Handles the SelectCell event of the StringGrid1 control. }
procedure TForm4.StringGrid1SelectCell(Sender: TObject; aCol, aRow: Integer;
  var CanSelect: Boolean);
begin
     { An item must be selected in the StringGrid1. }
     if (aRow >= 1) then
     begin
        try
        begin
             { Give the Edit Texts the selected values. }
             selectedIndex := aRow;
             idValue := StrToInt(Form4.StringGrid1.Cells[0, aRow]);

             { Open a connection to the database. }
             sqlTransaction := TSQLTransaction.Create(nil);
             sqlConnection := TMSSQLConnection.Create(nil);
             sqlQuery := TSQLQuery.Create(nil);

             sqlConnection.Transaction := sqlTransaction;
             sqlQuery.DataBase := sqlConnection;

             sqlConnection.HostName := 'localhost';
             sqlConnection.DatabaseName := 'MsSqlTestDatabase';
             sqlConnection.UserName := 'root';
             sqlConnection.Password := 'RootUser0123456789';
             sqlConnection.CharSet := 'UTF-8';
             sqlConnection.Connected := True;

             { Get the items from the People table. }
             sqlQuery.Close();
             sqlQuery.SQL.Text := 'SELECT * FROM [MsSqlTestDatabase].[dbo].[Relations] WHERE Id = :param1';

             { Fill the values of the command. }
             sqlQuery.Params.ParamByName('param1').AsInteger := idValue;

             { Execute. }
             sqlQuery.Open();

             { Get the number of the existing items. }
             while not sqlQuery.EOF do
             begin
                  relationValue := TRelation.Create(
                   sqlQuery.FieldByName('Id').AsInteger,
                   sqlQuery.FieldByName('Person1').AsInteger,
                   sqlQuery.FieldByName('Relationship').AsInteger,
                   sqlQuery.FieldByName('Person2').AsInteger,
                   sqlQuery.FieldByName('IsDeleted').AsBoolean);

                  sqlQuery.Next();
             end;

           { Give the Edit Texts the selected values. }
           Form4.ComboBox1.Caption := IntToStr(relationValue.getPerson1());
           Form4.ComboBox1Change(nil);
           Form4.ComboBox2.Caption := IntToStr(relationValue.getRelationship());
           Form4.ComboBox2Change(nil);
           Form4.ComboBox3.Caption := IntToStr(relationValue.getPerson2());
           Form4.ComboBox3Change(nil);

           { Close the connection. }
           sqlQuery.Close();
           sqlConnection.Close();
        end;
        except
        begin
           { Empty the ComboBox Texts. }
           Form4.ComboBox1.Caption := '';
           Form4.ComboBox2.Caption := '';
           Form4.ComboBox3.Caption := '';
        end;
        end;
     end
     else
     begin
         { Empty the ComboBox Texts. }
         Form4.ComboBox1.Caption := '';
         Form4.ComboBox2.Caption := '';
         Form4.ComboBox3.Caption := '';
     end;
end;

end.

