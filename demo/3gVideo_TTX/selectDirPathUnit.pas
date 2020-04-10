unit selectDirPathUnit;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls, Buttons, ComCtrls, ShellCtrls, ExtCtrls;

type
  TselectDirPathFrm = class(TForm)
    Panel1: TPanel;
    tvDirView: TShellTreeView;
    btnOK: TBitBtn;
    btnCancel: TBitBtn;
    Label1: TLabel;
    procedure FormCreate(Sender: TObject);
    procedure btnOKClick(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  selectDirPathFrm: TselectDirPathFrm;

implementation

{$R *.dfm}

procedure TselectDirPathFrm.FormCreate(Sender: TObject);
begin
  tvDirView.showRoot := true;
end;

procedure TselectDirPathFrm.btnOKClick(Sender: TObject);
begin
  Self.ModalResult := mrOk;
end;

end.
