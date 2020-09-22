unit Person;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils;

type
  TPerson = class
  private
    { private declarations }

    // The id field of the Person class.
    idField: Integer;
    // The name field of the Person class.
    nameField: String;
    // The mothername field of the Person class.
    mothernameField: String;
    // The location field of the Person class.
    locationField: String;
    // The birthdate field of the Person class.
    birthdateField: TDate;
    // The isDeleted field of the Person class.
    isDeletedField: Boolean;
  public
    { public declarations }

    { Initializes a new instance of the Person class. }
    constructor Create();
    { Initializes a new instance of the Person class. }
    constructor Create(id: Integer; name: String; mothername: String;
              location: String; birthdate: TDate; isdeleted: Boolean);
    { Gets the id. }
    function getId(): Integer;
    { Sets the id. }
    procedure setId(id: Integer);
    { Gets the name. }
    function getName(): String;
    { Sets the name. }
    procedure setName(name: String);
    { Gets the mothername. }
    function getMothername(): String;
    { Sets the mothername. }
    procedure setMothername(mothername: String);
    { Gets the location. }
    function getLocation(): String;
    { Sets the location. }
    procedure setLocation(location: String);
    { Gets the birthdate. }
    function getBirthdate(): TDate;
    { Sets the birthdate. }
    procedure setBirthdate(birthdate: TDate);
    { Gets the isDeleted. }
    function getIsDeleted(): Boolean;
    { Sets the isDeleted. }
    procedure setIsDeleted(isdeleted: Boolean);
  end;

implementation

{ Initializes a new instance of the Person class. }
constructor TPerson.Create();
begin

end;

{ Initializes a new instance of the Person class. }
constructor TPerson.Create(id: Integer; name: String; mothername: String;
     location: String; birthdate: TDate; isdeleted: Boolean);
begin
     idField := id;
     nameField := name;
     mothernameField := mothername;
     locationField := location;
     birthdateField := birthdate;
     isDeletedField := isdeleted;
end;

{ Gets the id. }
function TPerson.getId(): Integer;
begin
     getId := idField;
end;

{ Sets the id. }
procedure TPerson.setId(id: Integer);
begin
     idField := id;
end;

{ Gets the name. }
function TPerson.getName(): String;
begin
     getName := nameField;
end;

{ Sets the name. }
procedure TPerson.setName(name: String);
begin
     nameField := name;
end;

{ Gets the mothername. }
function TPerson.getMothername(): String;
begin
     getMothername := mothernameField;
end;

{ Sets the mothername. }
procedure TPerson.setMothername(mothername: String);
begin
     mothernameField := mothername;
end;

{ Gets the location. }
function TPerson.getLocation(): String;
begin
     getLocation := locationField;
end;

{ Sets the location. }
procedure TPerson.setLocation(location: String);
begin
     locationField := location;
end;

{ Gets the birthdate. }
function TPerson.getBirthdate(): TDate;
begin
     getBirthdate := birthdateField;
end;

{ Sets the birthdate. }
procedure TPerson.setBirthdate(birthdate: TDate);
begin
     birthdateField := birthdate;
end;

{ Gets the isDeleted. }
function TPerson.getIsDeleted(): Boolean;
begin
     getIsDeleted := isDeletedField;
end;

{ Sets the isDeleted. }
procedure TPerson.setIsDeleted(isdeleted: Boolean);
begin
     isDeletedField := isdeleted;
end;

end.

