{客户端Socket线程，
 线程的事件一定不要忘了使用同步方法，否则造成的错误是难以发现的。
 @author(吕洪波)
 @created(2004-3-16)
 @lastmod(GMT:$Date: 2012/11/26 06:34:56 $) <BR>
 最后更新人:$Author: ls $  <BR>
 当前版本:$Revision: 1.1.1.1 $  <BR>}
unit ClientThreadUnit;

interface

uses
  windows,
  scktcomp,
  
  TcpThreadUnit;

const
  {最大命令长度}
  MAX_CMDLEN=1024;

type

  TOnprocessCmd=procedure(Sender:TObject;PCmd:PByte;CmdLen:integer) of object;

  TClientThread=class(TTcpThread)
  private
    {客户端请求的数据通讯协议版本值。
    >0数据通讯协议版本验证通过
    =0未通过}
    FClientCommVerAuth:word;
    {最后一次发送命令时间}
    //FLastCmdTimeStamp:longword;
    FOnProcessCmd: TOnprocessCmd;
    FUserID: integer;
    FLogonTime: TDateTime;

    FBuffer:array[0..MAX_CMDLEN-1] of byte;
    FBufferLen:word;

    procedure SetOnProcessCmd(const Value: TOnprocessCmd);
    {数据通讯格式为 Ver=$0200的数据包处理函数
    @ver(吕洪波,2003-9-16,
    最后修改:NULL,2003-9-16)}
    procedure ProcessBuff_H0100;
    procedure SetUserID(const Value: integer);
    procedure SetLogonTime(const Value: TDateTime);
    procedure SynchrOnDoCmd;

    {在有命令发送的情况下
     在命令队列中查找命令的响应情况，并把这个响应返回给客户端
     [命令队列把 超时 没有被理会的命令移出]

    @param
    @parem
    @ver(吕洪波,2002-x-x,
    最后修改:NULL,2002-y-y)}
  protected
    procedure ProcessBuff();override;
  public
    {检查这个客户端是否有指定的MobileID的权限}
    function CheckMobileID(AMobileID:integer):boolean;
    {用户ID}
    property UserID:integer read FUserID write SetUserID;
    {客户端登录时间}
    property LogonTime:TDateTime read FLogonTime write SetLogonTime;
    {抛出命令由主线程来处理}
    property OnProcessCmd:TOnProcessCmd read FOnProcessCmd write SetOnProcessCmd;

  end;


implementation
uses
  Sysutils,
  {CmdStructUnit,
  ConstDefineUnit, }
  EventLogUnit, Classes;
{ TClientThread }

function TClientThread.CheckMobileID(AMobileID:integer): boolean;
begin
  Result:=True;
end;

procedure TClientThread.ProcessBuff;
begin
  ProcessBuff_H0100;
end;

procedure TClientThread.ProcessBuff_H0100;
begin
  //分拣每一条数据，并处理命令.如果出项异常数据，就断开连接。
  //while RecBuffDataLen>=2 do
  //begin
    FBufferLen:=ReadWord;
    if (FBufferLen=0) or (FBufferLen>MAX_CMDLEN) then
    begin
      NetServerLog.WriteEventlog('接受数据异常,断开客户端['+
        ClientSocket.RemoteAddress+','+Inttostr(ClientSocket.RemotePort)+']');

      ClientSocket.Close;
      Exit;
    end;
    if RecBuffDataLen>=FBufferLen then
    begin
      ReadAndDel(@FBuffer[0],FBufferLen);
      Synchronize(SynchrOnDoCmd);
    end;
  //end;
end;

procedure TClientThread.SynchrOnDoCmd;
begin
  if Assigned(FOnProcessCmd) then
    FOnProcessCmd(self,@FBuffer[0],FBufferLen);
end;

procedure TClientThread.SetLogonTime(const Value: TDateTime);
begin
  FLogonTime := Value;
end;

procedure TClientThread.SetOnProcessCmd(const Value: TOnprocessCmd);
begin
  FOnProcessCmd := Value;
end;

procedure TClientThread.SetUserID(const Value: integer);
begin
  FUserID := Value;
end;



end.
