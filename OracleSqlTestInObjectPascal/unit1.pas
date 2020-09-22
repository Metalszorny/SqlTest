unit Unit1;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, FileUtil, Forms, Controls, Graphics, Dialogs, StdCtrls,
  Unit2, Unit3, Unit4;

type

  { TForm1 }

  TForm1 = class(TForm)
    Button1: TButton;
    Button2: TButton;
    Button3: TButton;
    Button4: TButton;
    procedure Button1Click(Sender: TObject);
    procedure Button2Click(Sender: TObject);
    procedure Button3Click(Sender: TObject);
    procedure Button4Click(Sender: TObject);
  private
    { private declarations }
  public
    { public declarations }
  end;

var
  Form1: TForm1;

implementation

{$R *.lfm}

{ TForm1 }

{ Handles the Click event of the Button1 control. }
procedure TForm1.Button1Click(Sender: TObject);
begin
     { Open the People TForm. }
     Form2.Show();
end;

{ Handles the Click event of the Button2 control. }
procedure TForm1.Button2Click(Sender: TObject);
begin
     { Open the Relationships TForm. }
     Form3.Show();
end;

{ Handles the Click event of the Button3 control. }
procedure TForm1.Button3Click(Sender: TObject);
begin
     { Open the Relations TForm. }
     Form4.Show();
end;

{ Handles the Click event of the Button4 control. }
procedure TForm1.Button4Click(Sender: TObject);
begin
     { Exit the program. }
     Close();
end;

end.

