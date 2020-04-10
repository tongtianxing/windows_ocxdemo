{ 阻塞的TCP连接线程对象，实现了基本的数据的接受和发送
  @author(吕洪波)
  @created(2002-11-04)
  @lastmod(GMT:$Date: 2012/11/26 06:34:56 $) <BR>
  最后更新人:$Author: ls $  <BR>
  当前版本:$Revision: 1.1.1.1 $  <BR>}
unit TcpThreadUnit;

interface
uses
  classes,
  windows,
  winsock,
  scktcomp,
  EventLogUnit;

const
  WAITFORDATA_TIMEOUT=60000; //连接后60秒钟客户端不发数据就断开

type
  {数据到达的事件}
  TOnDataReceived=procedure(AClient:TObject;ABuff:PByte;ALen:integer);

  TTcpThread=class(TServerClientThread)
  private
    FLockRecv: TRTLCriticalSection;   //接收数据锁，缓冲区的数据在处理的时候不能够读取和写入.
    FLockSend: TRTLCriticalSection;   //发送数据锁，缓冲区的数据在处理的时候不能够读取和写入.
    {接受缓冲区}
    FRecBuff:array of Byte;
    {接受缓冲区的数据长度}
    FRecBuffDataLen:integer;
    FSendBuff:array of Byte;
    {发送缓冲区的数据长度}
    FSendBuffDataLen:integer;
    FDirectSend: boolean;
    FQueryBuffInterVal: integer;
    FReceiveBuffSize: integer;
    FSendBuffSize: integer;
    FOnDataReceived: TOnDataReceived;
    FSendBytesCount: integer;
    FRecvBytesCount: integer;
    FOnDisconnect: TNotifyEvent;
    {对缓冲区数据进行处理的时候不能够进行其他的处理操作，需要加锁锁住。}
    procedure LockRecvData;
    {@see Lock}
    procedure UnLockRecvData;

    procedure LockSendData;
    procedure UnLockSendData;

    function WaitForData(ATimeOut:integer):boolean;
    procedure SetDirectSend(const Value: boolean);
    procedure SetQueryBuffInterVal(const Value: integer);
    procedure SetReceiveBuffSize(const Value: integer);
    procedure SetSendBuffSize(const Value: integer);
    procedure SetOnDataReceived(const Value: TOnDataReceived);
    procedure SetRecvBytesCount(const Value: integer);
    procedure SetSendBytesCount(const Value: integer);
    procedure SynchrOnDataReceiv;
    procedure SetOnDisconnect(const Value: TNotifyEvent);
    procedure SynchOnDisconnect;   //
  protected
    //
    {从缓冲区起始位置读出一个word}
    function ReadWord:integer;
    {接受缓冲区中读出指定长度的数据
    @param ABuff:Pointer; 数据读出的缓冲区
    @parem Len:integer  指定的度数据长度
    @return 返回实际读出的数据长度，-1表示出错.
    @ver(吕洪波,2003-9-11,
    最后修改:NULL,2002-9-11)}
    function Read(ABuff:Pointer;Len:integer):integer;
    {从缓冲区中读出一段数据，并且把这段数据从缓冲区中清除,
    @return 返回实际读出的数据长度}
    function ReadAndDel(ABuff:Pointer;Len:integer):integer;
    {处理缓冲区数据，将缓冲区数据分拣成单个的数据包【[长度][数据]】}
    procedure ProcessBuff(); virtual;
    procedure ClientExecute();override;
    {接受缓冲区中的数据长度
    DataLen如果<0表名数据异常}
    property RecBuffDataLen:integer read FRecBuffDataLen;
  public
    constructor Create(CreateSuspended: Boolean;
      ASocket: TServerClientWinSocket);
    destructor Destroy;override;
    {在DirectSend＝True的情况下，直接发送数据。
    否则将需要发送的数据添加到发送缓冲区直到下一个数据轮循中发送。
    @param
    @parem
    @ver(吕洪波,2002-x-x,
    最后修改:NULL,2002-y-y)}
    procedure SendBuff(APoint:pointer;ALen:integer);
    {直接发送数据，不把数据放在发送缓冲区中，此函数会阻塞主线程}
    procedure DSendBuff(APoint:pointer;ALen:integer);

    //
    {关闭这个连接，在断开连接之前将发送缓冲区中的数据送出去}
    procedure Close;

    //property SocketHandle:
    property DirectSend:boolean read FDirectSend write SetDirectSend;
    property SendBuffSize:integer read FSendBuffSize write SetSendBuffSize;
    property ReceiveBuffSize:integer read FReceiveBuffSize write SetReceiveBuffSize;
    {在DirectSend＝False的情况下,
    查询并发送SendBuff中数据的时间间隔的毫秒数}
    property QueryBuffInterVal:integer read FQueryBuffInterVal write SetQueryBuffInterVal;
    {接受到数据后主动抛出事件}
    property OnDataReceived:TOnDataReceived read FOnDataReceived write SetOnDataReceived;
    {一共接受得字节数}
    property RecvBytesCount:integer read FRecvBytesCount write SetRecvBytesCount;
    {一共发送得字节数}
    property SendBytesCount:integer read FSendBytesCount write SetSendBytesCount;
    {客户端断开时的事件}
    property OnDisconnect:TNotifyEvent read FOnDisconnect write SetOnDisconnect;
  end;

implementation
uses
  SysUtils
  ;
{ TcpThread }

procedure TTcpThread.ClientExecute;
var
  ret:integer;
  buf:array[0..1023] of Byte;
begin
  {//连接后60秒钟客户端不发数据就断开
  if not WaitForData(WAITFORDATA_TIMEOUT) then
  begin
    NetServerLog.WriteEventlog('断开沉默连接['+ClientSocket.RemoteAddress+']');
    ClientSocket.Close;
  end;   } 
  while (not Terminated) and ClientSocket.Connected do
  begin
    if WaitForData(FQueryBuffInterVal) then
    begin
      ret:=recv(ClientSocket.SocketHandle,buf,1024,0); 
      if (ret>0) then
      begin
        LockRecvData;
        inc(FRecvBytesCount,ret);
        try
          if length(FRecBuff)-FRecBuffDataLen<ret then
            setlength(FRecBuff,FRecBuffDataLen+ret);
          CopyMemory(@FRecBuff[FRecBuffDataLen],@buf[0],ret);
          FRecBuffDataLen:=FRecBuffDataLen+ret;
        finally
          UnLockRecvData;
        end;
       (* {$IFopt d+}
          NetServerLog.WriteEventlog('收到客户端数据[：'+ MemFormatUnit.BuffToHex(@FRecBuff[0],FRecBuffDataLen) +']');
        {$ENDIF}  *)
        Synchronize(SynchrOnDataReceiv);
        ProcessBuff;
      end
      else
      begin
        //socket出错 应该断开连接并结束线程.
        //如果服务器主动断开客户端时，ClientSocket.RemoteAddress=''
        ret:=WSAGetLastError;
        NetServerLog.WriteEventlog('['+ClientSocket.RemoteAddress+
         ']断开连接，ErrorCode:'+IntToStr(ret));
        break;
      end;    
    end else
    begin  //如果发送缓冲区中有数据就发送到客户端
      if FSendBuffDataLen>0 then
      begin
        LockSendData;
        try
          DSendBuff(@FSendBuff[0],FSendBuffDataLen);
          FSendBuffDataLen:=0;
        finally
          UnLockSendData;
        end;
      end;

    end;//else begin

  end;   //while


  //do on disconn...
  if (ClientSocket.Connected) then
  begin
    ClientSocket.Close;
  end;

  Synchronize(SynchOnDisconnect);
  NetServerLog.WriteEventlog('线程终止,threadId='+IntToStr(ThreadID));
end;

procedure TTcpThread.Close;
begin
  if (ClientSocket<>nil) then
    ClientSocket.Close;
  self.Terminate;
  Exit;

  //再接受数据并同步到主线成的时候，锁定了缓冲区，再主线程有可能再调用Close方法，
  //此时就不能调用Lockdata，会产生死锁。
  LockSendData;
  try
    DSendBuff(@FSendBuff[0],FSendBuffDataLen);
    FSendBuffDataLen:=0;
    SetLength(FSendBuff,FSendBuffDataLen);
    if (ClientSocket<>nil) and (ClientSocket.Connected) then
      ClientSocket.Close;
    self.Terminate;
  finally
    UnLockSendData;
  end;
end;

constructor TTcpThread.Create(CreateSuspended: Boolean;ASocket: TServerClientWinSocket);
begin
  inherited;
  InitializeCriticalSection(FLockRecv);
  InitializeCriticalSection(FLockSend);
  FDirectSend       :=True;
  FQueryBuffInterVal:=100;        //默认查询发送缓冲区数据时间间隔 100ms
  FReceiveBuffSize  :=100*1024;   //接受缓冲区 100K Byte
  FSendBuffSize     :=1024*1024;  //发送缓冲区 1M   Byte
end;


destructor TTcpThread.Destroy;
begin
  DeleteCriticalSection(FLockSend);
  DeleteCriticalSection(FLockRecv);
  inherited;
end;

procedure TTcpThread.DSendBuff(APoint: pointer; ALen: integer);
var
  ret:integer;
begin
  if ClientSocket<>nil then
  begin
    ret:=winsock.send(ClientSocket.SocketHandle,APoint^,ALen,0);
    if ret < 0 then
    begin
      ret:=WSAGetLastError;
      NetServerLog.WriteErrlog('发送数据的时候发生错误，code='+IntToStr(ret));
    end;
  end;
    //else
    //NetServerLog.WriteErrlog('发送数据的时候发生错误，Sock已关闭');
end;

procedure TTcpThread.LockRecvData;
begin
  EnterCriticalSection(FLockRecv);
end;

procedure TTcpThread.LockSendData;
begin
  EnterCriticalSection(FLockSend);
end;


procedure TTcpThread.SynchrOnDataReceiv;
begin
  if Assigned(FOnDataReceived) then
    FOnDataReceived(self,@FRecBuff[0],FRecBuffDataLen);
end;

procedure TTcpThread.SynchOnDisconnect;
begin
  if Assigned(FOnDisconnect) then
    FOnDisconnect(self);
end;

procedure TTcpThread.ProcessBuff;
begin
  //override;
end;

function TTcpThread.Read(ABuff: Pointer; Len: integer): integer;
begin
  LockRecvData;
  try
    if Len>FRecBuffDataLen then
      Result:=FRecBuffDataLen
    else
      Result:=Len;
    if Result>0 then
      CopyMemory(ABuff,@FRecBuff[0],Result);
  except
    UnLockRecvData;
    Result:=-1;
  end;
end;

function TTcpThread.ReadAndDel(ABuff: Pointer; Len: integer): integer;
begin
  LockRecvData;
  try
    if FRecBuffDataLen<len then len:=FRecBuffDataLen;
    CopyMemory(ABuff,@FRecBuff[0],len);
    FRecBuffDataLen:=FRecBuffDataLen-len;
    if FRecBuffDataLen>0 then
      CopyMemory(@FRecBuff[0],@FRecBuff[len],FRecBuffDataLen);
    Result:=len;
    setlength(FRecBuff,FRecBuffDataLen); // add by sha --只在本程序中 将 FRecBuff中 已处理部分 清除
  finally
    UnLockRecvData;
  end;
end;

function TTcpThread.ReadWord: integer;
begin
  if FRecBuffDataLen>=1 then
    Result := high(FRecBuff)+1
    //Result:=PWord(@FRecBuff[0])^  // 读首字:原网关程序中，首字=长度 (2Byte)。
  else
    Result:=0;
end;

procedure TTcpThread.SendBuff(APoint: pointer; ALen: integer);
begin
  inc(FSendBytesCount,ALen);
  if FDirectSend then
  begin
    if ClientSocket<>nil then
      winsock.send(ClientSocket.SocketHandle,APoint^,ALen,0)
  end else
  begin
    LockSendData;
    try
      //只要不超过缓冲区的大小就添加到发送缓冲区
      if FSendBuffDataLen+Alen>FSendBuffSize then Exit;

      if length(FSendBuff)-FSendBuffDataLen <Alen then
        Setlength(FSendBuff,FSendBuffDataLen+ALen);

       CopyMemory(@FSendBuff[FSendBuffDataLen],APoint,ALen);
       inc(FSendBuffDataLen,ALen);
    finally
      UnLockSendData;
    end;
  end;
end;

procedure TTcpThread.SetDirectSend(const Value: boolean);
begin
  FDirectSend := Value;
end;

procedure TTcpThread.SetOnDataReceived(const Value: TOnDataReceived);
begin
  FOnDataReceived := Value;
end;

procedure TTcpThread.SetQueryBuffInterVal(const Value: integer);
begin
  FQueryBuffInterVal := Value;
end;

procedure TTcpThread.SetReceiveBuffSize(const Value: integer);
begin
  FReceiveBuffSize := Value;
end;

procedure TTcpThread.SetRecvBytesCount(const Value: integer);
begin
  FRecvBytesCount := Value;
end;

procedure TTcpThread.SetSendBuffSize(const Value: integer);
begin
  FSendBuffSize := Value;
end;

procedure TTcpThread.SetSendBytesCount(const Value: integer);
begin
  FSendBytesCount := Value;
end;

procedure TTcpThread.UnLockRecvData;
begin
  LeaveCriticalSection(FLockRecv);
end;

procedure TTcpThread.UnLockSendData;
begin
  LeaveCriticalSection(FLockSend);
end;

function TTcpThread.WaitForData(ATimeOut: integer): boolean;
var
  FDSet: TFDSet;
  TimeVal: TTimeVal;
  re:integer;
begin
  TimeVal.tv_sec := ATimeOut div 1000;
  TimeVal.tv_usec := (ATimeOut mod 1000) * 1000;
  FD_ZERO(FDSet);
  FD_SET(ClientSocket.SocketHandle, FDSet);
  //re:=select(0, nil, nil,@FDSet,@TimeVal);
  re:=select(0, @FDSet, nil, nil, @TimeVal);

  if re>0 then
    Result:=True else
  if re=-1 then
    Result:=True else
  //if re=0 then
    Result:=False;
end;

procedure TTcpThread.SetOnDisconnect(const Value: TNotifyEvent);
begin
  FOnDisconnect := Value;
end;



end.
