{调试信息类,
提供将错误信息写入log文件的方法.
修改记录:<br>
<li>2003-9-5 加入了 WriteTimeMX属性，提供超过指定时间后如果有日志内容没存盘的化就存盘。
@author(吕洪波)
@created(2001-11-1)
@lastmod(2003-9-5)}
unit SystemLog;


interface
uses
  windows,
  FormS,
  shellapi,
  extctrls;
type
  {Debug信息的结构
  <Li>DateTime:string 时间
  <Li>Position:string 错误的位置，记录文件位置或调用的方法位置
  <Li>Description:string 错误的描述}
  TLogFormat=record
    DateTime:string;
    Position:string;
    Description:string;
  end;

  {调试信息类,
  提供将错误信息写入log文件的方法.
  可以静态的调用或者动态的调用.}
  TSystemLog=Class(TObject)
  private
    FLogstr:String;
    FTime:Cardinal;

    FTimer:TTimer;
    FLogFile: string;
    FWriteImmediate: Boolean;
    FBufferSize: Integer;
    FWriteMode: Word;
    FLock: TRTLCriticalSection;

    procedure WriteLog(logStr:string);
    procedure SetLogFile(const Value: string);
    procedure SetWriteImmediate(const Value: Boolean);
    procedure SetBufferSize(const Value: Integer);
    procedure SetWriteMode(const Value: Word);
    {响应时钟时间，
    如果有日志内容没保存的话就存盘}
    procedure DoOnTimer(Sender: TObject);
    procedure SetWriteTimeMX(const Value: integer);
    function GetWriteTimeMX: integer;
    procedure Lock;
    procedure UnLock;
  public
    constructor Create;virtual;
    destructor Destroy;override;
    {将错误日志加到缓冲区中，当达到64K时就写入文件}
    procedure AddLog(logStr:string);overload;
    procedure AddLog(LogFormat:TLogFormat);overload;
    {自动写入时间,发生过程,内容的日志}
    procedure AddLog(Position,Description:string);overload;
    procedure ResetTimer;
    function ElapsedTime:integer;
    property LogFile:string read FLogFile write SetLogFile;
    {写入缓冲大小}
    property BufferSize:Integer read FBufferSize write SetBufferSize;
    {写入模式}
    property WriteMode:Word read FWriteMode write SetWriteMode;
    {是否立刻写入}
    property WriteImmediate:Boolean read FWriteImmediate write SetWriteImmediate;
    {保存日志的最大时间延时(毫秒)}
    property WriteTimeMX:integer read GetWriteTimeMX write SetWriteTimeMX;
  end;

function LogFormat(errposition,description:string):TLogFormat;

implementation
uses
  Classes,
  Sysutils;

function LogFormat(errposition,description:string):TLogFormat;
begin
  Result.Position:=errposition;
  Result.DateTime:=DateToStr(date)+' '+TimeToStr(time);
  Result.Description:=description;
end;

{ TGeoLog }
destructor TSystemLog.Destroy;
begin
  FTimer.Enabled:=False;
  if FLogstr<>'' then
  begin
    WriteLog(FLogstr);
    WriteLog(#13#10);
  end;
  FTimer.Free;
  DeleteCriticalSection(FLock);  
  inherited
end;

function TSystemLog.ElapsedTime: integer;
begin
  Result:=GetTickCount-FTime;
end;

procedure TSystemLog.AddLog(LogFormat: TLogFormat);
var logstr:string;
begin
  with LogFormat do
  begin
    logstr:=Format('%s  %s  %s',[DateTime,Position,Description]);
  end;
  AddLog(logstr);
end;

procedure TSystemLog.Addlog(logStr: string);
begin
  FLogstr:=FLogstr+logStr+#13+#10;
  if (Length(FLogstr)>BufferSize) or WriteImmediate then
  begin
    WriteLog(FLogstr);
    FLogstr:='';
  end;
end;

procedure TSystemLog.ResetTimer;
begin
  Ftime:=GetTickCount;
end;

procedure TSystemLog.WriteLog(logStr: string);
var
  fs:TFileStream;
  fileName:string;
begin
  Lock;
  try
    FileName:=FLogFile;
    fs:=nil;

    try
      if FileExists(FileName) then
        fs:=TFileStream.Create(FileName,WriteMode )
      else
        fs:=TFileStream.Create(FileName,fmCreate  or fmShareDenyWrite);

      fs.Position:=fs.Size;
      fs.Write(logstr[1],Length(logstr));
      fs.Free;
    except
      fs.Free;
    end;
  finally
    UnLock;
  end;
end;

procedure TSystemLog.SetLogFile(const Value: string);
begin
  FLogFile := Value;
end;


procedure TSystemLog.SetWriteImmediate(const Value: Boolean);
begin
  FWriteImmediate := Value;
end;
procedure TSystemLog.AddLog(Position, Description: string);
begin
  addlog(LogFormat(Position,Description));
end;

procedure TSystemLog.SetBufferSize(const Value: Integer);
begin
  FBufferSize := Value;
end;

procedure TSystemLog.SetWriteMode(const Value: Word);
begin
  FWriteMode := Value;
end;

constructor TSystemLog.Create;
begin
  InitializeCriticalSection(FLock);
  FBufferSize :=16*1024;       //默认满16K存盘
  FWriteMode := fmOpenReadWrite or fmShareDenyWrite;
  FTimer:=TTimer.Create(nil);
  FTimer.OnTimer:=DoOnTimer;
  FTimer.Interval:=10*1000; //默认十秒钟保存一次数据
  FTimer.Enabled:=True;
end;

procedure TSystemLog.DoOnTimer(Sender: TObject);
begin
  if FLogstr<>'' then
  begin
    WriteLog(FLogstr);
    FLogstr:='';
  end
end;

procedure TSystemLog.SetWriteTimeMX(const Value: integer);
begin
  if Value=0 then
  begin
    FTimer.Enabled:=False;
  end else
  begin
    FTimer.Interval:=Value;
    FTimer.Enabled:=True;
  end;
end;

function TSystemLog.GetWriteTimeMX: integer;
begin
  if FTimer.Enabled then
    Result:=FTimer.Interval
  else
    Result:=0;
end;

procedure TSystemLog.Lock;
begin
  EnterCriticalSection(FLock);
end;

procedure TSystemLog.UnLock;
begin
  LeaveCriticalSection(FLock);
end;

end.
