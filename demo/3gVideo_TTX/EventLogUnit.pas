{记录NetServer的运行日志情况.
@author(吕洪波)
@created(2001-12-4)
@lastmod(2003-9-5)}
unit EventLogUnit;

interface
uses
  SystemLog;
const
  LOGDIR = 'c:\logs';

type
  TLogType=(ltErr,ltEvent);
  TOnWritelog=procedure (ALogType:TLogType;ALogMsg:string) of object;
  {日志保存在一个指定的文件夹中，
  其路径保存在注册表中。日志文件有两种：
  <li>错误日志
  <li>事件日志
  日志的文件名用日期组合的字符串为后缀，每天独立的文件}
  TNetServerLog=class
  private
    FCurrentPostfix:string;
    ErrLog:TSystemLog;
    EventLog:TSystemLog;
    {是否初始化成功}
    FInit:boolean;
    FOnWritelog: TOnWritelog;
    {获得日期的后缀字符串，格式为20021204}
    function GetDatePostfix:string;
    procedure SetOnWritelog(const Value: TOnWritelog);
    procedure CreateLogObject(APostfix:string);
  public
    constructor Create;
    destructor Destroy;override;
    {写错误日志
    @param AErrMsg:string 要记录的错误信息
    @ver(吕洪波,2002-12-4,
    最后修改:NULL,2002-12-4)}
    procedure WriteErrlog(AErrMsg:string);
    {写事件日志
    @parem AEventMsg:string 事件信息
    @ver(吕洪波,2002-12-4,
    最后修改:NULL,2002-12-4)}
    procedure WriteEventlog(AEventMsg:string);
    property OnWritelog:TOnWritelog read FOnWritelog write SetOnWritelog;
  end;

  function NetServerLog():TNetServerLog;
implementation
uses
  Sysutils,
  FileCtrl;
var
  FNetserverLog:TNetServerLog;
{ NetServerLog }

constructor TNetServerLog.Create;
begin

  if not DirectoryExists(LOGDIR) then
    if not CreateDir(LOGDIR) then
    begin
      FInit:=False;
      Exit;
    end;

  FCurrentPostfix:=GetDatePostfix;
  CreateLogObject(FCurrentPostfix);
  FInit:=True;
end;

procedure TNetServerLog.CreateLogObject(APostfix: string);
begin
  ErrLog.Free;
  ErrLog:=TSystemLog.Create;
  ErrLog.WriteImmediate:=False;
  ErrLog.LogFile:=LOGDIR+'\Err'+APostfix+'.log';

  EventLog.Free;
  EventLog:=TSystemLog.Create;
  EventLog.WriteImmediate:=False;

  EventLog.LogFile:=LOGDIR+'\Event'+APostfix+'.log';
end;

destructor TNetServerLog.Destroy;
begin
  ErrLog.Free;
  EventLog.Free;
  inherited;
end;

function TNetServerLog.GetDatePostfix: string;
begin
  Result:=FormatDateTime('yyyymmdd',now);
end;

procedure TNetServerLog.SetOnWritelog(const Value: TOnWritelog);
begin
  FOnWritelog := Value;
end;

procedure TNetServerLog.WriteErrlog(AErrMsg: string);
begin
  AErrMsg:=FormatDateTime('yyyy-mm-dd hh:mm:ss',Now)+' '+AErrMsg;
  if Assigned(FOnWritelog) then FOnWritelog(ltErr,AErrMsg);

  if not FInit then
  begin
    if Assigned(FOnWritelog) then FOnWritelog(ltErr,'未指定日志目录！');
    Exit;
  end;

  if GetDatePostfix<>FCurrentPostfix then
  begin
    FCurrentPostfix:=GetDatePostfix;
    CreateLogObject(FCurrentPostfix);
  end;
  ErrLog.AddLog(AErrMsg);
end;

procedure TNetServerLog.WriteEventlog(AEventMsg: string);
begin
  AEventMsg:=FormatDateTime('yyyy-mm-dd hh:mm:ss',Now)+' '+AEventMsg;
  if Assigned(FOnWritelog) then FOnWritelog(ltEvent,AEventMsg);
  if not FInit then
  begin
    if Assigned(FOnWritelog) then FOnWritelog(ltEvent,'未指定日志目录！');
    Exit;
  end;
  if GetDatePostfix<>FCurrentPostfix then
  begin
    FCurrentPostfix:=GetDatePostfix;
    CreateLogObject(FCurrentPostfix);
  end;
  EventLog.AddLog(AEventMsg);
end;


function NetServerLog():TNetServerLog;
begin
  if FNetserverLog=nil then
    FNetserverLog:=TNetserverLog.Create;
  Result:=FNetserverLog;  
end;

initialization
  FNetserverLog:=nil;


finalization
  FNetserverLog.Free;
end.
