unit Unit3;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, sqldb, mysql51conn, FileUtil, Forms, Contnrs, Controls,
  Graphics, Dialogs, StdCtrls, Grids, Relationship;

type

  { TForm3 }

  TForm3 = class(TForm)
    Button1: TButton;
    Button2: TButton;
    Button3: TButton;
    Button4: TButton;
    Button5: TButton;
    Edit1: TEdit;
    GroupBox1: TGroupBox;
    Label1: TLabel;
    MySQL51Connection1: TMySQL51Connection;
    SQLQuery1: TSQLQuery;
    SQLTransaction1: TSQLTransaction;
    StringGrid1: TStringGrid;
    procedure Button1Click(Sender: TObject);
    procedure Button2Click(Sender: TObject);
    procedure Button3Click(Sender: TObject);
    procedure Button4Click(Sender: TObject);
    procedure Button5Click(Sender: TObject);
    procedure Edit1Change(Sender: TObject);
    procedure FormShow(Sender: TObject);
    procedure StringGrid1SelectCell(Sender: TObject; aCol, aRow: Integer;
      var CanSelect: Boolean);
  private
    { private declarations }
  public
    { public declarations }
  end;

var
  Form3: TForm3;
  idValue, selectedIndex: Integer;
  nameValue: String;
  sqlConnection: TMySQL51Connection;
  sqlQuery: TSQLQuery;
  sqlTransaction: TSQLTransaction;

implementation

{$R *.lfm}

var
  relationshipList: TObjectList;
  i: Integer;
{ Gets the data. }
procedure GetData();
begin
     try
     begin
        { Clear existing items. }
        Form3.StringGrid1.RowCount := 1;

        { Open a connection to the database. }
        sqlTransaction := TSQLTransaction.Create(nil);
        sqlConnection := TMySQL51Connection.Create(nil);
        sqlQuery := TSQLQuery.Create(nil);

        sqlConnection.Transaction := sqlTransaction;
        sqlQuery.DataBase := sqlConnection;

        sqlConnection.HostName := 'localhost';
        sqlConnection.DatabaseName := 'MySqlTestDatabase';
        sqlConnection.UserName := 'root';
        sqlConnection.Password := 'root';
        sqlConnection.Connected := True;

        { Get the items from the Relationships table. }
        sqlQuery.Close();
        sqlQuery.SQL.Text := 'SELECT * FROM MySqlTestDatabase.Relationships WHERE IsDeleted = 0';

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

        { Close the datareader and the connection. }
        sqlQuery.Close();
        sqlConnection.Close();

        { Fill the StringGrid rows with the values of the Relationships table. }
        for i := 0 to relationshipList.Count - 1 do
        begin
            Form3.StringGrid1.RowCount := Form3.StringGrid1.RowCount + 1;

            Form3.StringGrid1.Cells[0, i + 1] := IntToStr(TRelationship(relationshipList[i]).getId());
            Form3.StringGrid1.Cells[1, i + 1] := TRelationship(relationshipList[i]).getName();
        end;
     end;
     except
     begin

     end;
     end;
end;

{ Handles the Click event of the Button1 control. }
procedure TForm3.Button1Click(Sender: TObject);
begin
     { Lists the Person items. }
     GetData();
end;

var
  matchFound, deletedFound: Boolean;
{ Handles the Click event of the Button2 control. }
procedure TForm3.Button2Click(Sender: TObject);
begin
     { Adds a Relationship item. }
     try
     begin
        { The fields must not be empty. }
        if (nameValue <> '') then
        begin
           idValue := 0;
           matchFound := False;
           deletedFound := False;

           { Open a connection to the database. }
           sqlTransaction := TSQLTransaction.Create(nil);
           sqlConnection := TMySQL51Connection.Create(nil);
           sqlQuery := TSQLQuery.Create(nil);

           sqlConnection.Transaction := sqlTransaction;
           sqlQuery.DataBase := sqlConnection;

           sqlConnection.HostName := 'localhost';
           sqlConnection.DatabaseName := 'MySqlTestDatabase';
           sqlConnection.UserName := 'root';
           sqlConnection.Password := 'root';
           sqlConnection.Connected := True;

           { Get the items from the Relationships table. }
           sqlQuery.Close();
           sqlQuery.SQL.Text := 'SELECT * FROM MySqlTestDatabase.Relationships';

           { Execute. }
           sqlQuery.Open();

           { Get the number of the existing items. }
           while not sqlQuery.EOF do
           begin
               idValue += 1;

               { Check if the new item already exists. }
               if ((matchFound = False) And
                  (sqlQuery.FieldByName('Name').AsString = nameValue) And
                  (sqlQuery.FieldByName('IsDeleted').AsBoolean = False)) then
               begin
                  matchFound := True;

                  Break;
               end;

               { Check if the new item already exists. }
               if ((deletedFound = False) And
                  (sqlQuery.FieldByName('Name').AsString = nameValue) And
                  (sqlQuery.FieldByName('IsDeleted').AsBoolean = True)) then
               begin
                  deletedFound := True;
                  idValue := sqlQuery.FieldByName('Id').AsInteger;

                  Break;
               end;

               sqlQuery.Next();
            end;

           { If no match was found among the active items.. }
           if (matchFound = False) then
           begin
                { Add a new item if no match exists or restore the deleted item. }
                if (deletedFound = False) then
                begin
                     { Add new item to the Relationships table. }
                     sqlQuery.Close();
                     sqlQuery.SQL.Text := 'INSERT INTO MySqlTestDatabase.Relationships (Id, Name, IsDeleted) VALUES (:param1, :param2, :param3)';

                     { Fill the values of the command. }
                     sqlQuery.Params.ParamByName('param1').AsInteger := idValue + 1;
                     sqlQuery.Params.ParamByName('param2').AsString := nameValue;
                     sqlQuery.Params.ParamByName('param3').AsBoolean := False;

                     { Execute. }
                     sqlQuery.ExecSQL;
                     sqlTransaction.Commit;
                end
                else
                begin
                     { Edit the IsDeleted value to false. }
                     sqlQuery.Close();
                     sqlQuery.SQL.Text := 'UPDATE MySqlTestDatabase.Relationships SET IsDeleted = :param2 WHERE Id = :param1';

                     { Fill the values of the command. }
                     sqlQuery.Params.ParamByName('param1').AsInteger := idValue;
                     sqlQuery.Params.ParamByName('param2').AsBoolean := False;

                     { Execute. }
                     sqlQuery.ExecSQL;
                     sqlTransaction.Commit;
                end;
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
procedure TForm3.Button3Click(Sender: TObject);
begin
     { Edits a Relationship item. }
     try
     begin
        { The fields must not be empty. }
        if ((nameValue <> '') And (idValue <> 0)) then
        begin
           { An item must be selected in the StringGrid1. }
           if (selectedIndex >= 1) then
           begin
              { Get the Id value of the selected item. }
             idValue := StrToInt(Form3.StringGrid1.Cells[0, selectedIndex]);

             { Open a connection to the database. }
             sqlTransaction := TSQLTransaction.Create(nil);
             sqlConnection := TMySQL51Connection.Create(nil);
             sqlQuery := TSQLQuery.Create(nil);

             sqlConnection.Transaction := sqlTransaction;
             sqlQuery.DataBase := sqlConnection;

             sqlConnection.HostName := 'localhost';
             sqlConnection.DatabaseName := 'MySqlTestDatabase';
             sqlConnection.UserName := 'root';
             sqlConnection.Password := 'root';
             sqlConnection.Connected := True;

             { Update the values in the People table. }
             sqlQuery.Close();
             sqlQuery.SQL.Text := 'UPDATE MySqlTestDatabase.Relationships SET Name = :param2 WHERE Id = :param1';

             { Fill the values of the command. }
             sqlQuery.Params.ParamByName('param1').AsInteger := idValue;
             sqlQuery.Params.ParamByName('param2').AsString := nameValue;

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
procedure TForm3.Button4Click(Sender: TObject);
begin
     { Deletes a Relationship item. }
     try
     begin
          if (selectedIndex >= 1) then
          begin
             { Logical delete }
             { Get the Id value of the selected item. }
             idValue := StrToInt(Form3.StringGrid1.Cells[0, selectedIndex]);

             { Open a connection to the database. }
             sqlTransaction := TSQLTransaction.Create(nil);
             sqlConnection := TMySQL51Connection.Create(nil);
             sqlQuery := TSQLQuery.Create(nil);

             sqlConnection.Transaction := sqlTransaction;
             sqlQuery.DataBase := sqlConnection;

             sqlConnection.HostName := 'localhost';
             sqlConnection.DatabaseName := 'MySqlTestDatabase';
             sqlConnection.UserName := 'root';
             sqlConnection.Password := 'root';
             sqlConnection.Connected := True;

             { Edit the IsDeleted value to true. }
             sqlQuery.Close();
             sqlQuery.SQL.Text := 'UPDATE MySqlTestDatabase.Relationships SET IsDeleted = :param2 WHERE Id = :param1';

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
procedure TForm3.Button5Click(Sender: TObject);
begin
     { Close the TForm. }
     Close;
end;

{ Handles the Change event of the Edit1 control. }
procedure TForm3.Edit1Change(Sender: TObject);
begin
     { Give the field the Edit Text. }
     nameValue := Edit1.Text;
end;

{ Handles the Show event of the TForm3 control. }
procedure TForm3.FormShow(Sender: TObject);
begin
     { Presets the values. }
     GetData();
end;

{ Handles the SelectCell event of the StringGrid1 control. }
procedure TForm3.StringGrid1SelectCell(Sender: TObject; aCol, aRow: Integer;
  var CanSelect: Boolean);
begin
     { An item must be selected in the StringGrid1. }
     if (aRow >= 1) then
     begin
        try
        begin
           selectedIndex := aRow;

           { Give the Edit Texts the selected values. }
           Edit1.Text := Form3.StringGrid1.Cells[1, aRow];
        end;
        except
        begin
           { Empty the Edit Texts. }
           Edit1.Text := '';
        end;
        end;
     end
     else
     begin
         { Empty the Edit Texts. }
         Edit1.Text := '';
     end;
end;

end.

