unit Relation;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils;

type
  TRelation = class
  private
    { private declarations }

    // The id field of the Relation class.
    idField: Integer;
    // The person1 field of the Relation class.
    person1Field: Integer;
    // The relationship field of the Relation class.
    relationshipField: Integer;
    // The person2 field of the Relation class.
    person2Field: Integer;
    // The isDeleted field of the Relation class.
    isDeletedField: Boolean;
  public
    { public declarations }

    { Initializes a new instance of the Relation class. }
    constructor Create();
    { Initializes a new instance of the Relation class. }
    constructor Create(id: Integer; person1: Integer; relationship: Integer;
                person2: Integer; isdeleted: Boolean);
    { Gets the id. }
    function getId(): Integer;
    { Sets the id. }
    procedure setId(id: Integer);
    { Gets the person1. }
    function getPerson1(): Integer;
    { Sets the person1. }
    procedure setPerson1(person1: Integer);
    { Gets the relationship. }
    function getRelationship(): Integer;
    { Sets the relationship. }
    procedure setRelationship(relationship: Integer);
    { Gets the person2. }
    function getPerson2(): Integer;
    { Sets the person2. }
    procedure setPerson2(person2: Integer);
    { Gets the isDeleted. }
    function getIsDeleted(): Boolean;
    { Sets the isDeleted. }
    procedure setIsDeleted(isdeleted: Boolean);
  end;

implementation

{ Initializes a new instance of the Relation class. }
constructor TRelation.Create();
begin

end;

{ Initializes a new instance of the Relation class. }
constructor TRelation.Create(id: Integer; person1: Integer; relationship: Integer;
     person2: Integer; isdeleted: Boolean);
begin
     idField := id;
     person1Field := person1;
     relationshipField := relationship;
     person2Field := person2;
     isDeletedField := isdeleted;
end;

{ Gets the id. }
function TRelation.getId(): Integer;
begin
     getId := idField;
end;

{ Sets the id. }
procedure TRelation.setId(id: Integer);
begin
     idField := id;
end;

{ Gets the person1. }
function TRelation.getPerson1(): Integer;
begin
     getPerson1 := person1Field;
end;

{ Sets the person1. }
procedure TRelation.setPerson1(person1: Integer);
begin
     person1Field := person1;
end;

{ Gets the relationship. }
function TRelation.getRelationship(): Integer;
begin
     getRelationship := relationshipField;
end;

{ Sets the relationship. }
procedure TRelation.setRelationship(relationship: Integer);
begin
     relationshipField := relationship;
end;

{ Gets the person2. }
function TRelation.getPerson2(): Integer;
begin
     getPerson2 := person2Field;
end;

{ Sets the person2. }
procedure TRelation.setPerson2(person2: Integer);
begin
     person2Field := person2;
end;

{ Gets the isDeleted. }
function TRelation.getIsDeleted(): Boolean;
begin
     getIsDeleted := isDeletedField;
end;

{ Sets the isDeleted. }
procedure TRelation.setIsDeleted(isdeleted: Boolean);
begin
     isDeletedField := isdeleted;
end;

end.

