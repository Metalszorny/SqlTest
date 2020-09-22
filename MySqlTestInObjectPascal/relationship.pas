unit Relationship;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils;

type
  TRelationship = class
  private
    { private declarations }

    // The id field of the Relationship class.
    idField: Integer;
    // The name field of the Relationship class.
    nameField: String;
    // The isDeleted field of the Relationship class.
    isDeletedField: Boolean;
  public
    { public declarations }

    { Initializes a new instance of the Relationship class. }
    constructor Create();
    { Initializes a new instance of the Relationship class. }
    constructor Create(id: Integer; name: String; isdeleted: Boolean);
    { Gets the id. }
    function getId(): Integer;
    { Sets the id. }
    procedure setId(id: Integer);
    { Gets the name. }
    function getName(): String;
    { Sets the name. }
    procedure setName(name: String);
    { Gets the isDeleted. }
    function getIsDeleted(): Boolean;
    { Sets the isDeleted. }
    procedure setIsDeleted(isdeleted: Boolean);
  end;

implementation

{ Initializes a new instance of the Relationship class. }
constructor TRelationship.Create();
begin

end;

{ Initializes a new instance of the Relationship class. }
constructor TRelationship.Create(id: Integer; name: String; isdeleted: Boolean);
begin
     idField := id;
     nameField := name;
     isDeletedField := isdeleted;
end;

{ Gets the id. }
function TRelationship.getId(): Integer;
begin
     getId := idField;
end;

{ Sets the id. }
procedure TRelationship.setId(id: Integer);
begin
     idField := id;
end;

{ Gets the name. }
function TRelationship.getName(): String;
begin
     getName := nameField;
end;

{ Sets the name. }
procedure TRelationship.setName(name: String);
begin
     nameField := name;
end;

{ Gets the isDeleted. }
function TRelationship.getIsDeleted(): Boolean;
begin
     getIsDeleted := isDeletedField;
end;

{ Sets the isDeleted. }
procedure TRelationship.setIsDeleted(isdeleted: Boolean);
begin
     isDeletedField := isdeleted;
end;

end.

