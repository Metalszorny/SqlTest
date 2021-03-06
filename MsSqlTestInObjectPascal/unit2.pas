unit Unit2;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, FileUtil, Forms, Controls, Graphics, Dialogs, StdCtrls,
  Grids, Person, mssqlconn, sqldb, Contnrs;

type

  { TForm2 }

  TForm2 = class(TForm)
    Button1: TButton;
    Button2: TButton;
    Button3: TButton;
    Button4: TButton;
    Button5: TButton;
    Edit1: TEdit;
    Edit2: TEdit;
    Edit3: TEdit;
    Edit4: TEdit;
    GroupBox1: TGroupBox;
    Label1: TLabel;
    Label2: TLabel;
    Label3: TLabel;
    Label4: TLabel;
    MSSQLConnection1: TMSSQLConnection;
    SQLQuery1: TSQLQuery;
    SQLTransaction1: TSQLTransaction;
    StringGrid1: TStringGrid;
    procedure Button1Click(Sender: TObject);
    procedure Button2Click(Sender: TObject);
    procedure Button3Click(Sender: TObject);
    procedure Button4Click(Sender: TObject);
    procedure Button5Click(Sender: TObject);
    procedure Edit1Change(Sender: TObject);
    procedure Edit2Change(Sender: TObject);
    procedure Edit3Change(Sender: TObject);
    procedure Edit4Change(Sender: TObject);
    procedure FormShow(Sender: TObject);
    procedure StringGrid1SelectCell(Sender: TObject; aCol, aRow: Integer;
      var CanSelect: Boolean);
  private
    { private declarations }
  public
    { public declarations }
  end;

var
  Form2: TForm2;
  idValue, selectedIndex: Integer;
  nameValue, mothernameValue, locationValue, birthdateValue: String;
  sqlConnection: TMSSQLConnection;
  sqlQuery: TSQLQuery;
  sqlTransaction: TSQLTransaction;

implementation

{$R *.lfm}

{ TForm2 }

var
  personList: TObjectList;
  i: Integer;
{ Gets the data. }
procedure GetData();
begin
     try
     begin
        { Clear existing items. }
        Form2.StringGrid1.RowCount := 1;

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
        sqlQuery.SQL.Text := 'SELECT * FROM [MsSqlTestDatabase].[dbo].[People] WHERE IsDeleted = 0';

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

        { Close the datareader and the connection. }
        sqlQuery.Close();
        sqlConnection.Close();

        { Fill the StringGrid rows with the values of the People table. }
        for i := 0 to personList.Count - 1 do
        begin
            Form2.StringGrid1.RowCount := Form2.StringGrid1.RowCount + 1;

            Form2.StringGrid1.Cells[0, i + 1] := IntToStr(TPerson(personList[i]).getId());
            Form2.StringGrid1.Cells[1, i + 1] := TPerson(personList[i]).getName();
            Form2.StringGrid1.Cells[2, i + 1] := TPerson(personList[i]).getMothername();
            Form2.StringGrid1.Cells[3, i + 1] := TPerson(personList[i]).getLocation();
            Form2.StringGrid1.Cells[4, i + 1] := DateToStr(TPerson(personList[i]).getBirthdate());
        end;
     end;
     except
     begin

     end;
     end;
end;

{ Handles the Click event of the Button1 control. }
procedure TForm2.Button1Click(Sender: TObject);
begin
     { Lists the Person items. }
     GetData();
end;

var
  matchFound: Boolean;
{ Handles the Click event of the Button2 control. }
procedure TForm2.Button2Click(Sender: TObject);
begin
     { Adds a Person item. }
     try
     begin
        { The fields must not be empty. }
        if ((nameValue <> '') And (mothernameValue <> '') And (locationValue <> '')) then
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

           { Get the items from the People table. }
           sqlQuery.Close();
           sqlQuery.SQL.Text := 'SELECT * FROM [MsSqlTestDatabase].[dbo].[People]';

           { Execute. }
           sqlQuery.Open();

           { Get the number of the existing items. }
           while not sqlQuery.EOF do
           begin
               idValue += 1;

               { Search for deleted matches. }
               if ((matchFound = False) And
                  (sqlQuery.FieldByName('Name').AsString = nameValue) And
                  (sqlQuery.FieldByName('Mothername').AsString = mothernameValue) And
                  (sqlQuery.FieldByName('Location').AsString = locationValue) And
                  (sqlQuery.FieldByName('Birthdate').AsDateTime = StrToDate(birthdateValue)) And
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
              { Add new item to the People table. }
              sqlQuery.Close();
              sqlQuery.SQL.Text := 'INSERT INTO [MsSqlTestDatabase].[dbo].[People] (Id, Name, Mothername, Location, Birthdate, IsDeleted) VALUES (:param1, :param2, :param3, :param4, :param5, :param6)';

              { Fill the values of the command. }
              sqlQuery.Params.ParamByName('param1').AsInteger := idValue + 1;
              sqlQuery.Params.ParamByName('param2').AsString := nameValue;
              sqlQuery.Params.ParamByName('param3').AsString := mothernameValue;
              sqlQuery.Params.ParamByName('param4').AsString := locationValue;
              sqlQuery.Params.ParamByName('param5').AsDateTime := StrToDate(birthdateValue);
              sqlQuery.Params.ParamByName('param6').AsBoolean := False;

              { Execute. }
              sqlQuery.ExecSQL;
              sqlTransaction.Commit;
           end
           else
           begin
              { Edit the IsDeleted value to false. }
              sqlQuery.Close();
              sqlQuery.SQL.Text := 'UPDATE [MsSqlTestDatabase].[dbo].[People] SET IsDeleted = :param2 WHERE Id = :param1';

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
procedure TForm2.Button3Click(Sender: TObject);
begin
     { Edits a Person item. }
     try
     begin
        { The fields must not be empty. }
        if ((nameValue <> '') And (mothernameValue <> '') And (locationValue <> '') And (idValue <> 0)) then
        begin
           { An item must be selected in the StringGrid1. }
           if (selectedIndex >= 1) then
           begin
              { Get the Id value of the selected item. }
             idValue := StrToInt(Form2.StringGrid1.Cells[0, selectedIndex]);

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

             { Update the values in the People table. }
             sqlQuery.Close();
             sqlQuery.SQL.Text := 'UPDATE [MsSqlTestDatabase].[dbo].[People] SET Name = :param2, Mothername = :param3, Location = :param4, BirthDate = :param5 WHERE Id = :param1';

             { Fill the values of the command. }
             sqlQuery.Params.ParamByName('param1').AsInteger := idValue;
             sqlQuery.Params.ParamByName('param2').AsString := nameValue;
             sqlQuery.Params.ParamByName('param3').AsString := mothernameValue;
             sqlQuery.Params.ParamByName('param4').AsString := locationValue;
             sqlQuery.Params.ParamByName('param5').AsDateTime := StrToDate(birthdateValue);

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
procedure TForm2.Button4Click(Sender: TObject);
begin
     { Deletes a Person item. }
     try
     begin
          if (selectedIndex >= 1) then
          begin
             { Logical delete }
             { Get the Id value of the selected item. }
             idValue := StrToInt(Form2.StringGrid1.Cells[0, selectedIndex]);

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
             sqlQuery.SQL.Text := 'UPDATE [MsSqlTestDatabase].[dbo].[People] SET IsDeleted = :param2 WHERE Id = :param1';

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
procedure TForm2.Button5Click(Sender: TObject);
begin
     { Close the TForm. }
     Close;
end;

{ Handles the Change event of the Edit1 control. }
procedure TForm2.Edit1Change(Sender: TObject);
begin
     { Give the field the Edit Text. }
     nameValue := Edit1.Text;
end;

{ Handles the Change event of the Edit2 control. }
procedure TForm2.Edit2Change(Sender: TObject);
begin
     { Give the field the Edit Text. }
     mothernameValue := Edit2.Text;
end;

{ Handles the Change event of the Edit3 control. }
procedure TForm2.Edit3Change(Sender: TObject);
begin
     { Give the field the Edit Text. }
     locationValue := Edit3.Text;
end;

{ Handles the Change event of the Edit4 control. }
procedure TForm2.Edit4Change(Sender: TObject);
begin
     { Give the field the Edit Text. }
     birthdateValue := Edit4.Text;
end;

{ Handles the Show event of the TForm2 control. }
procedure TForm2.FormShow(Sender: TObject);
begin
     { Presets the values. }
     GetData();
end;

{ Handles the SelectCell event of the StringGrid1 control. }
procedure TForm2.StringGrid1SelectCell(Sender: TObject; aCol, aRow: Integer;
  var CanSelect: Boolean);
begin
     { An item must be selected in the StringGrid1. }
     if (aRow >= 1) then
     begin
        try
        begin
           selectedIndex := aRow;

           { Give the Edit Texts the selected values. }
           Edit1.Text := Form2.StringGrid1.Cells[1, aRow];
           Edit2.Text := Form2.StringGrid1.Cells[2, aRow];
           Edit3.Text := Form2.StringGrid1.Cells[3, aRow];
           Edit4.Text := Form2.StringGrid1.Cells[4, aRow];
        end;
        except
        begin
           { Empty the Edit Texts. }
           Edit1.Text := '';
           Edit2.Text := '';
           Edit3.Text := '';
           Edit4.Text := '';
        end;
        end;
     end
     else
     begin
         { Empty the Edit Texts. }
         Edit1.Text := '';
         Edit2.Text := '';
         Edit3.Text := '';
         Edit4.Text := '';
     end;
end;

end.

