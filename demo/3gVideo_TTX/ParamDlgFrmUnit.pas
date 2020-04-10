unit ParamDlgFrmUnit;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, ComCtrls, StdCtrls, ExtCtrls, Buttons;

type
  TParamDlgFrm = class(TForm)
    PageControl1: TPageControl;
    TabSheet1: TTabSheet;
    LabeledEditIP: TLabeledEdit;
    LabeledEditPort: TLabeledEdit;
    Label2: TLabel;
    Label3: TLabel;
    LabeledEditStreamIP: TLabeledEdit;
    LabeledEditStreamPort: TLabeledEdit;
    cbxStreamType: TComboBox;
    cbxStreamMode: TComboBox;
    BtnQD: TBitBtn;
    BtnQX: TBitBtn;
    LabeledEditCutPicFilePath: TLabeledEdit;
    SpeedButton1: TSpeedButton;
    lbledtCloseTime: TLabeledEdit;
    procedure SpeedButton1Click(Sender: TObject);
    procedure lbledtCloseTimeChange(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  ParamDlgFrm: TParamDlgFrm;

implementation
uses selectDirPathUnit;
{$R *.dfm}

procedure TParamDlgFrm.SpeedButton1Click(Sender: TObject);
var
  dlg: TselectDirPathFrm;
begin
  try
    dlg := TselectDirPathFrm.Create(Self);
    if (Trim(LabeledEditCutPicFilePath.Text) <> '') and DirectoryExists(Trim(LabeledEditCutPicFilePath.Text)) then
    begin
      try
        dlg.tvDirView.Path := Trim(LabeledEditCutPicFilePath.Text);
      except
        //MessageBox(Handle, PChar(LabeledEditCutPicFilePath.Text + '路径不存在！'), '提示',  mb_ok + MB_ICONINFORMATION);
        //LabeledEditCutPicFilePath.Text := '';
      end;
    end;
    if dlg.ShowModal = mrok then
    begin
      LabeledEditCutPicFilePath.Text := dlg.tvDirView.Path;
    end;
  finally
    dlg.Free;
  end;
end;

procedure TParamDlgFrm.lbledtCloseTimeChange(Sender: TObject);
begin
  if   StrToInt(trim(lbledtCloseTime.text))>600 then
  begin
    messagebox(handle, '不能大于10分钟！', '提示', mb_ok + mb_iconinformation);
    lbledtCloseTime.Text := '600';
    lbledtCloseTime.SelectAll;
    lbledtCloseTime.SetFocus;
  end;
end;

end.
