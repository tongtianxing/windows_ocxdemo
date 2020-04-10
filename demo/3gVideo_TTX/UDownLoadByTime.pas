unit UDownLoadByTime;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, ComCtrls, StdCtrls, Buttons, ExtCtrls, DateUtils, DB, DBClient;

type
  TFrmDownLoadByTime = class(TForm)
    Panel4: TPanel;
    Panel3: TPanel;
    Panel8: TPanel;
    Panel1: TPanel;
    BtnCancel: TBitBtn;
    BtnOk: TBitBtn;
    lbl1: TLabel;
    TmBeg: TDateTimePicker;
    lbl2: TLabel;
    TmEnd: TDateTimePicker;
    DtEnd: TDateTimePicker;
    DtBeg: TDateTimePicker;
    procedure BtnOkClick(Sender: TObject);
    procedure BtnCancelClick(Sender: TObject);
    procedure FormShow(Sender: TObject);
  private
   
    { Private declarations }
  public
    StrInitBegDate,StrInitEndDate:String;
    StrOKTimeBeg,StrOKTimeEnd :String;
    { Public declarations  String MonitorBegTime, String MonitorEndTime, int MonitorTimeLen,int MonitorType }
  end;

var
  FrmDownLoadByTime: TFrmDownLoadByTime;

implementation
 
{$R *.dfm}

procedure TFrmDownLoadByTime.BtnOkClick(Sender: TObject);
var
  DateTimeBeg, DateTimeEnd : Tdatetime; 
begin 
  DateTimeBeg := DtBeg.DateTime;             ReplaceTime(DateTimeBeg, TmBeg.Time);
  DateTimeEnd := DtEnd.DateTime;             ReplaceTime(DateTimeEnd, TmEnd.Time);
  if (DtBeg.date > DtEnd.date) or
    ((DtBeg.date = DtEnd.date) and (TmBeg.Time > TmEnd.Time)) then
  begin
      messagebox(handle, '请重新输入 有效时间段!', '提示', mb_ok + mb_iconinformation);
      exit;
  end; 
  StrOKTimeBeg := FormatDateTime('yyyy-MM-dd hh:nn:ss', DateTimeBeg);
  StrOKTimeEnd := FormatDateTime('yyyy-MM-dd hh:nn:ss', DateTimeEnd); 
  ModalResult := mrOk;
end;

procedure TFrmDownLoadByTime.BtnCancelClick(Sender: TObject);
begin
  ModalResult := mrCancel;
end;

procedure TFrmDownLoadByTime.FormShow(Sender: TObject);
begin
  DtBeg.Date := StrToDateTime(StrInitBegDate);
  DtEnd.Date := StrToDateTime(StrInitEndDate);
  TmBeg.Time := StrToDateTime(StrInitBegDate);
  TmEnd.Time := StrToDateTime(StrInitEndDate);
end;

end.
