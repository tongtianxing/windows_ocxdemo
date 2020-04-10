unit VideoFrmUnit;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls, OleCtrls, ShellAPI, MyCommAgentCTL_TLB, Menus, ScktComp,
  TcpThreadUnit, ClientThreadUnit, ComCtrls, XPMan, Buttons, ActnList,
  ExtActns, ExtCtrls, IdHashMessageDigest, IdBaseComponent, IdComponent,
  IdTCPConnection, IdTCPClient, IdHTTP, wpCTIOcx_TLB, PPVSGUARDLib_TLB, DB,
  DBClient, TLMDVRAXLib_TLB, ImgList;

const
  VERSION = '(20130604.0900)';

  MY_APP_NAME           = '3G_VIDEO';
  ID_MAIN = 100; // 定义图标的ID
  WM_MAINNOTIFY = WM_USER + 100;  //自定义消息


  CLIENTTAGENT_0 = 0;    // 心跳
  CLIENTTAGENT_1 = 1;    // 签入系统
  CLIENTTAGENT_2 = 2;    // 签出系统


  // 代理往客户端，命令字在50以上
  AGENTTCLIENT_50 = 50;    // 通用应答
  AGENTTCLIENT_51 = 51;    // 电话打进
  AGENTTCLIENT_52 = 52;    // 电话接通
  AGENTTCLIENT_53 = 53;    // 电话空闲
  

type
  TMD5 = class(TIdHashMessageDigest5);

  TVideoMainFrm = class(TForm)
    PopupMenu1: TPopupMenu;
    N1: TMenuItem;
    N2: TMenuItem;
    StatusBar1: TStatusBar;
    XPManifest1: TXPManifest;
    Timer1: TTimer;
    Timer2: TTimer;
    FTemp: TClientDataSet;
    Panel2: TPanel;
    Label1: TLabel;
    lblState: TLabel;
    Label4: TLabel;
    Label5: TLabel;
    ComboBox1: TComboBox;
    editDeviceID: TEdit;
    Label2: TLabel;
    ComboBox2: TComboBox;
    btncut: TSpeedButton;
    btnsound: TSpeedButton;
    btnLogin: TSpeedButton;
    btnplay: TSpeedButton;
    btnstop: TSpeedButton;
    btnLogout: TSpeedButton;
    btnReload: TSpeedButton;
    SpeedButton1: TSpeedButton;
    PageControl1: TPageControl;
    TabSheet1: TTabSheet;
    TabSheet2: TTabSheet;
    Panel1: TPanel;
    Panel3: TPanel;
    Panel4: TPanel;
    Label3: TLabel;
    DateTimePicker1: TDateTimePicker;
    DateTimePicker2: TDateTimePicker;
    Label6: TLabel;
    DateTimePicker3: TDateTimePicker;
    DateTimePicker4: TDateTimePicker;
    BitBtn1: TBitBtn;
    VideoListView: TListView;
    BitBtn2: TBitBtn;
    BitBtn3: TBitBtn;
    BitBtn4: TBitBtn;
    TLMDVRAx1: TTLMDVRAx;
    Button1: TButton;
    Video3G: TTLMDVRAx;
    procedure FormClose(Sender: TObject; var Action: TCloseAction);
    procedure MSPevtQueueChanged(Sender: TObject);
    procedure N1Click(Sender: TObject);
    procedure N2Click(Sender: TObject);
    procedure FormCloseQuery(Sender: TObject; var CanClose: Boolean);
    procedure Timer1Timer(Sender: TObject);
    procedure Timer2Timer(Sender: TObject);
    procedure editDeviceIDChange(Sender: TObject);
    procedure ComboBox1KeyPress(Sender: TObject; var Key: Char);
    procedure BitBtn7Click(Sender: TObject);
    procedure ComboBox1Change(Sender: TObject);
    procedure ComboBox2Change(Sender: TObject);
    procedure btncutClick(Sender: TObject);
    procedure btnsoundClick(Sender: TObject);
    procedure btnLoginClick(Sender: TObject);
    procedure btnplayClick(Sender: TObject);
    procedure btnstopClick(Sender: TObject);
    procedure btnLogoutClick(Sender: TObject);
    procedure SpeedButton1Click(Sender: TObject);
    procedure BitBtn1Click(Sender: TObject);
    procedure BitBtn2Click(Sender: TObject);
    procedure BitBtn3Click(Sender: TObject);
    procedure BitBtn4Click(Sender: TObject);
    procedure VideoListViewCustomDrawItem(Sender: TCustomListView;
      Item: TListItem; State: TCustomDrawState; var DefaultDraw: Boolean);
    procedure Button1Click(Sender: TObject);
  private
    { Private declarations }
    FNid: NOTIFYICONDATA;


    FChannelID: Integer;    // 设备通道号(从1开始)
    FDeviceID: String;      // 设备序列号



    procedure addVideoRecordInfoToList(info: string);

    function GetFormNameAt(const Pos: TPoint): string;

    function AddIcon(hwnd: HWND): Boolean; //在状态区添加图标
    function RemoveIcon(hwnd: HWND): Boolean; //从状态区移去图标
    function ModifyIcon(hwnd: HWND; Title: String): Boolean; // 更新托盘提示信息
    procedure minimize(sender: Tobject); //定义最小化过程，赋给Application.OnMinimize;
    procedure Notify(var Msg: TMessage); message WM_MAINNOTIFY; //自定义消息处理函数
    procedure CreateParams(var Params: TCreateParams);override;

    // 接收监控端发送过来的消息
    // 消息字符串组成格式 以键值对的形式，中间用"|"隔开：  KEY1=VALUE1|KEY2=VALUE2
    // 命令(FLAG)=VALUE|流水号(CMDID)=VALUE|内容
    procedure WMCopyData(var Message: TWMCopyData); message WM_COPYDATA;
    // 返回监控端消息
    // 消息字符串组成格式 以键值对的形式，中间用"|"隔开：  KEY1=VALUE1|KEY2=VALUE2
    // 命令(FLAG)=VALUE|流水号(CMDID)=VALUE|内容
    procedure SendCopyData(Msg: string);

    // 加载车辆信息
    procedure LoadCarInfo;
    Function GetDllPath:string;

    function LoginServer: boolean;
    function Logout: boolean;
    function PlayVideo: boolean;
    function StopVideo: boolean;
  public
    { Public declarations }
    FServerIP: String;      // 注册视频服务器
    FPort: Integer;         // 注册视频服务器端口号
    FUserName: String;      // 注册服务器用户名
    FPassWord: String;      // 注册服务器密码

    FStreamServerIP: String;  // 流媒体服务器IP
    FStreamPort: Integer;     // 流媒体服务器端口号
    FStreamType: Integer;		  // 码流类型 (0-主码流; 1-子码流)
    FStreamMode: Integer;     // 流媒体服务器请求前端视频流模式 0:UDP;1:TCP
    FCutPicFilePath: string;  // 视频截图路径
    procedure InitParam;
    procedure Set3GConfig(IP: string; PORT: Integer; USER: string; Password: string; CutPicFilePath: string);
  end;

var
  VideoMainFrm: TVideoMainFrm;

implementation
uses IniFiles, DateUtils, ZipLibUnit, ParamDlgFrmUnit;
{$R *.dfm}

{ TLXZC_CallCenterFrm }

Function TVideoMainFrm.GetDllPath:string;
var
  ModuleName:string;
  FilePath: string;
  index: integer;
begin
  SetLength(ModuleName, 255);  //取得Dll自身路径
  GetModuleFileName(HInstance, PChar(ModuleName), Length(ModuleName));
  FilePath := ExtractFilePath(ModuleName);
  result := FilePath;
end;

procedure TVideoMainFrm.WMCopyData(var Message: TWMCopyData);
var
  Msg: string;
begin
  try
    Msg := PChar(Message.CopyDataStruct.lpData);
  except
  end;
end;

procedure TVideoMainFrm.FormClose(Sender: TObject;
  var Action: TCloseAction);
begin
  try
    Logout;

    RemoveIcon(handle);
  except
  end;
end;

procedure TVideoMainFrm.MSPevtQueueChanged(
  Sender: TObject);
begin
  // 电话排队
    
end;

procedure TVideoMainFrm.SendCopyData(Msg: string);
var
  h: HWND;
  Size: Integer;
  CopyDataStruct: TCopyDataStruct;
begin
  h := FindWindow(nil, '监控指挥-3G视频');           { 按标题查找目标窗口 }
  if h > 0 then
  begin
    Size := Length(Msg) + 2;                                  { 多出的两个字节用于后面的 #0 }
    CopyDataStruct.lpData := PChar(Msg + #10);                { 要发送的字符串, #0 表示 PChar 结束}
    CopyDataStruct.dwData := WM_COPYDATA;                     { 指定消息类型 }
    CopyDataStruct.cbData := Size;                            { 指定要发送的数据的大小 }
    SendMessage(h, WM_COPYDATA, 0, Integer(@CopyDataStruct)); { 发送 }
  end;
end;

procedure TVideoMainFrm.minimize(sender: Tobject);
begin
  ShowWindow(Handle, SW_HIDE);
end;

function TVideoMainFrm.AddIcon(hwnd: HWND): Boolean;
begin
  FNid.cbSize := sizeof(NOTIFYICONDATA);
  FNid.Wnd := hwnd;
  FNid.uID := ID_MAIN;
  FNid.uFlags := NIF_MESSAGE or NIF_ICON or NIF_TIP;
  FNid.uCallbackMessage := WM_MAINNOTIFY;
  FNid.hIcon := LoadIcon(HInstance, 'MAINICON');
  strCopy(FNid.szTip, '南京通用-3G视频');
  AddIcon := Shell_NotifyIcon(NIM_ADD, @FNid);      
end;

function TVideoMainFrm.RemoveIcon(hwnd: HWND): Boolean;
var
  nid: NOTIFYICONDATA;
begin
  try
    nid.cbSize := sizeof(NOTIFYICONDATA);
    nid.Wnd := hwnd;
    nid.uID := ID_MAIN;
    nid.uFlags := 0;
    RemoveIcon := Shell_NotifyIcon(NIM_DELETE, @nid);
  except
  end;
end;

function TVideoMainFrm.ModifyIcon(hwnd: HWND; Title: String): Boolean;
begin
  try
//    FNid.cbSize := sizeof(NOTIFYICONDATA);
//    FNid.Wnd := hwnd;
//    FNid.uID := ID_MAIN;
//    FNid.uFlags := NIF_MESSAGE or NIF_ICON or NIF_TIP;
//    FNid.uCallbackMessage := WM_MAINNOTIFY;
//    FNid.hIcon := LoadIcon(hInstance, 'MAINICON');
//    strCopy(FNid.szTip, Pchar(Title));
//    ModifyIcon := Shell_NotifyIcon(NIM_ADD, @FNid);
  except
  end;
end;

procedure TVideoMainFrm.CreateParams(var Params: TCreateParams);
begin
  inherited CreateParams(Params);
  Params.WinClassName := MY_APP_NAME;
end;

procedure TVideoMainFrm.Notify(var Msg: TMessage);
var
  Pt: TPoint;
begin
  case msg.LParam of
    WM_RBUTTONDOWN,WM_LBUTTONDOWN,WM_LBUTTONDBLCLK:    //当点击右键时,弹出快捷菜单
      begin
        SetForeGroundWindow(FNid.wnd);
        GetCursorPos(Pt);
        Popupmenu1.Popup(pt.x, pt.y);
      end;
  end;
end;

procedure TVideoMainFrm.N1Click(Sender: TObject);
begin
  //RemoveIcon(handle);
  ShowWindow(Self.Handle, SW_SHOWNORMAL);
end;

procedure TVideoMainFrm.N2Click(Sender: TObject);
begin
  CLOSE;
end;


procedure TVideoMainFrm.FormCloseQuery(Sender: TObject;
  var CanClose: Boolean);
begin
  if messagebox(handle, '您确定要退出3G视频播放器？', '退出选项', MB_OKCANCEL + MB_ICONQUESTION) = ID_CANCEL then
    CanClose := false;
end;

procedure TVideoMainFrm.Timer1Timer(Sender: TObject);
var
  winPos: TPoint;
  t: integer;
  b: boolean;
begin
  try
    b:= false;
    if (self.Top <= 3) then
    begin
      b:= true;
      t:= 0;
    end
    else if self.Left + self.Width - Screen.Width >= 0 then
    begin
      b:= true;
      t:= self.Top;
    end
    else
      t:= self.Top;


    if b then
    begin
      //得到当前鼠标指针的在屏幕上的坐标
      GetCursorPos(winPos);
      //当鼠标指针下的窗体的Name等于frmMain.name时
      if self.Name = GetFormNameAt(winPos) then
      {在此我们可以为frmMain取一个特别的名称，以防有别的窗体名称与它相同}
      begin
        //停用Timer2
        timer2.Enabled:= false;
        //frmMain的Top与屏幕对齐
        self.Top:= t;
        if t <> 0 then
          self.Left:= Screen.Width - self.Width;
      end
      else begin
        Timer2.Enabled:= true;
      end;
    end;
  except
  end;
end;

procedure TVideoMainFrm.Timer2Timer(Sender: TObject);
begin
  try
    // 当 top 距屏幕上侧 20 像素时,自动隐藏
    if self.Top <= 20 then
    begin
      //将frmMain向上移，在屏幕上方露出3像素
      self.Top:= -(self.Height - 3);
      if (self.Left + self.Width > Screen.Width) then
        self.Left:= Screen.Width - self.Width;
    end
    // 当 left 距屏幕下侧 20 像素时,自动隐藏
    else if self.Left + self.Width - Screen.Width >= -20 then
      //将frmMain向右移，在屏幕右方露出4像素
      self.Left:= Screen.Width - 4;
  except
  end;
end;

function TVideoMainFrm.GetFormNameAt(const Pos: TPoint): string;
var
  w: TWinControl;
begin
  try
    //得到鼠标指针下的VCL可视组件
    w:= FindVclWindow(Pos);
    if (w <> nil) then
    begin
      //当W的上级Parent不为空时就继续往上找
      while w.Parent <> nil do
        w:= w.Parent;
      //最后返回窗体的名称Name
      Result:= w.Name;
    end
    else
      Result:= '';
  except
  end;
end;

procedure TVideoMainFrm.LoadCarInfo;
var
  Info, ZIP: string;
  fs: TFileStream;
  FileName: string;
  I, fileLen: Integer;
  ft: TextFile;
begin
  try
    FileName := ExtractFilePath(Application.ExeName) + 'DBINFO\CARINFO';
    if not FileExists(FileName) then
    begin
      MessageBox(Handle, '没有车辆基数数据，请先登陆监控客户端！', '提示', MB_OK + MB_ICONWARNING);
      exit;
    end;

    fs := TFileStream.Create(FileName,fmOpenRead);
    try
      //fileLen := fs.Seek(0,2);
      //fs.Seek(0,0);
      SetLength(ZIP, fs.size);
      fs.Read(ZIP[1],fs.size);
    finally
      fs.Free;
    end;


//      try
//        // 读取文件中的内容
//        AssignFile(ft, FileName);
//        Reset(ft);
//        repeat Readln(ft,info);
//          zip := zip + Trim(info);
//        until eof(ft) = true;
//      finally
//        CloseFile(ft);
//      end;

    Info := DeCompress(ZIP);
    FTemp.XMLData := info;
    FTemp.Open;
    ComboBox1.Clear;
    FTemp.First;
    while not FTemp.Eof do
    begin
      ComboBox1.Items.Add(FTemp.FieldByName('CAR_NO').AsString);
      FTemp.Next;
    end;
  except
  end;      
end;

procedure TVideoMainFrm.editDeviceIDChange(Sender: TObject);
begin
  FDeviceID := Trim(editDeviceID.Text);
end;

procedure TVideoMainFrm.ComboBox1KeyPress(Sender: TObject; var Key: Char);
begin
  if (Key = #13) then
  begin
    editDeviceID.Text := ComboBox1.Text;
    exit;
  end;
end;

procedure TVideoMainFrm.BitBtn7Click(Sender: TObject);
begin
  LoadCarInfo;
end;

procedure TVideoMainFrm.ComboBox1Change(Sender: TObject);
begin
  editDeviceID.Text := ComboBox1.Text;
end;

procedure TVideoMainFrm.ComboBox2Change(Sender: TObject);
begin
  FChannelID := ComboBox2.ItemIndex;
end;

procedure TVideoMainFrm.btncutClick(Sender: TObject);
var
  FileName: string;
begin
  try
    FileName := FDeviceID + '_' + FormatDateTime('YYYYMMDDHHNNSSSSS', now)+'.JPG';
    Video3G.SnapPicture(FCutPicFilePath +  '\' + FileName);
    messagebox(handle, '视频截图完成！', '提示', mb_ok + MB_ICONWARNING);
  except
  end;
end;

procedure TVideoMainFrm.btnsoundClick(Sender: TObject);
begin
  if Video3G.PlayAudio < 0 then
  begin
    messagebox(handle, '打开视频声音失败！', '提示', mb_ok + MB_ICONWARNING);
  end;
end;

procedure TVideoMainFrm.InitParam;
var
  IniFile: TIniFile;
  FilePath: string;
  Index: integer;
  image: TIcon;
begin
  try
    FChannelID := 0;


    FilePath := GetDllPath;
    //FilePath := StringReplace(FilePath, 'Video_3G.dll', '', [rfReplaceAll]);
    IniFile := TIniFile.Create(FilePath + 'CMSV_4G.ini');

    try
      FServerIP := IniFile.ReadString('ini', 'IP', '');      // 218.2.75.219

      FPort := IniFile.ReadInteger('ini', 'PORT', 0);        // 10000

      FUserName := IniFile.ReadString('ini', 'USERNAME', '');   // user
      FPassWord := IniFile.ReadString('ini', 'PASSWORD', '');   // jycz

      FStreamServerIP := IniFile.ReadString('ini', 'STREAMIP', '');
      FStreamPort := IniFile.ReadInteger('ini', 'STREAMPORT', 7554);

      FStreamType:= IniFile.ReadInteger('ini', 'STREAMTYPE', 0);
      FStreamMode := IniFile.ReadInteger('ini', 'STREAMMODE', 1);

      FCutPicFilePath := IniFile.ReadString('ini', 'CUTPICFILEPATH', '');

    finally
      IniFile.Free;
    end;

//    FServerIP := '218.94.158.108';
//    FPort := 10000;
//    FUserName := 'user';
//    FPassWord := '123';


    LoadCarInfo;


//    Application.OnMinimize := minimize;
//    AddIcon(Handle);
//    SetWindowLong(HInstance, GWL_EXSTYLE, WS_EX_TOOLWINDOW);

    Self.Caption := Self.Caption + ' ' + VERSION;
    Application.Title := Self.Caption;
  except
    on e: exception do
    begin
      messagebox(handle, pchar('Create:' + e.Message), '提示', mb_ok + MB_ICONWARNING);
    end;
  end;
end;

procedure TVideoMainFrm.btnLoginClick(Sender: TObject);
begin
  if LoginServer then
  begin
    lblState.Caption := '连接视频终端服务成功';
  end else
  begin
    lblState.Caption := '连接视频终端服务失败';
  end;
end;

procedure TVideoMainFrm.btnplayClick(Sender: TObject);
begin         
  if PlayVideo then
  begin
    lblState.Caption := '打开视频播放成功';
  end else
  begin
    lblState.Caption := '打开视频播放失败';
  end;
end;

procedure TVideoMainFrm.btnstopClick(Sender: TObject);
begin
  try
    StopVideo;
    lblState.Caption := '关闭视频播放成功';
  except
    messagebox(handle, '关闭视频播放失败！', '提示', mb_ok + MB_ICONWARNING);
  end;
end;

procedure TVideoMainFrm.btnLogoutClick(Sender: TObject);
begin
  try
    Logout;
    lblState.Caption := '断开视频终端服务成功';
  except
    messagebox(handle, '断开视频终端服务失败！', '提示', mb_ok + MB_ICONWARNING);
  end;
end;

procedure TVideoMainFrm.SpeedButton1Click(Sender: TObject);
var
  dlg: TParamDlgFrm;
  IniFile: TIniFile;
  FilePath: string;
begin
  dlg := TParamDlgFrm.Create(self);
  try
    with dlg do
    begin
      LabeledEditIP.Text := FServerIP;
      LabeledEditPort.Text := IntToStr(FPort); 
      LabeledEditStreamIP.Text := FStreamServerIP;
      LabeledEditStreamPort.Text := IntToStr(FStreamPort);
      cbxStreamType.ItemIndex := FStreamType;
      cbxStreamMode.ItemIndex := FStreamMode;
      LabeledEditCutPicFilePath.Text := FCutPicFilePath;
    end;
    dlg.ShowModal;
    if dlg.ModalResult = mrOk then
    begin
      with dlg do
      begin
        FServerIP := LabeledEditIP.Text;
        FPort := StrToIntDef(LabeledEditPort.Text, 7660); 
        FStreamServerIP := LabeledEditStreamIP.Text;
        FStreamPort := StrToIntDef(LabeledEditStreamPort.Text, 7554);
        FStreamType := cbxStreamType.ItemIndex;
        FStreamMode := cbxStreamMode.ItemIndex;
        FCutPicFilePath := LabeledEditCutPicFilePath.Text;
      end;

      FilePath := GetDllPath; 
      IniFile := TIniFile.Create(FilePath + 'CMSV_4G.ini');
      try
        try
          IniFile.WriteString('ini', 'IP', FServerIP);
          IniFile.WriteString('ini', 'PORT', IntToStr(FPort));
          IniFile.WriteString('ini', 'USERNAME', FUserName);
          IniFile.WriteString('ini', 'PASSWORD', FPassWord);
          IniFile.WriteString('ini', 'STREAMIP', FStreamServerIP);
          IniFile.WriteString('ini', 'STREAMPORT', IntToStr(FStreamPort));
          IniFile.WriteInteger('ini', 'STREAMTYPE', FStreamType);
          IniFile.WriteInteger('ini', 'STREAMMODE', FStreamMode);
          IniFile.WriteString('ini', 'CUTPICFILEPATH', FCutPicFilePath);

          messagebox(handle, '保存成功！', '提示', mb_ok + mb_iconinformation);
        except
        end;
      finally
        IniFile.Free;
      end;
    end;
  finally
    dlg.Free;
  end;
end;

function TVideoMainFrm.LoginServer: boolean;
begin
  try
    result := Video3G.LoginServer(FServerIP, FPort, FUserName, FPassWord);
  except
    result := false;
  end;
end;

function TVideoMainFrm.Logout: boolean;
begin
  try
    Video3G.Logout;
    result := true;
  except
    result := false;
  end;
end;

function TVideoMainFrm.PlayVideo: boolean;
begin
  try
    result := false;
    if Video3G.PlayVideo(FDeviceID, FChannelID) = 0 then
    begin
      result := true;
    end;
  except
    result := false;
  end;
end;

function TVideoMainFrm.StopVideo: boolean;
begin
  try
    Video3G.StopVideo;
    result := true;
  except
    result := false;
  end;
end;

procedure TVideoMainFrm.BitBtn1Click(Sender: TObject);
var
  dtTemp: TDateTime;
  startDateTime, endDateTime: Tdatetime;
  recCount: Integer;
  i: Integer;
  s: string;
begin
  try
    VideoListView.Clear;
    dtTemp := StrToDateTime('1970-01-01 00:00:00');

    startDateTime := DateTimePicker1.DateTime;
    ReplaceTime(startDateTime, DateTimePicker2.Time);
    
    endDateTime := DateTimePicker3.DateTime;
    ReplaceTime(endDateTime, DateTimePicker4.Time);

    recCount := Video3G.StartRemoteFileSearch(FDeviceID, $0F, $ff, SecondsBetween(dtTemp, startDateTime), SecondsBetween(dtTemp, endDateTime));
    if recCount = 0 then
    begin
      ShowMessage('检索无视频！');
    end;
    for i := 0 to recCount - 1 do
    begin
      s := Video3G.GetNextRemoteFileInfo(FDeviceID);
      addVideoRecordInfoToList(s);
    end;
  except
    ON E: EXCEPTION DO
    begin
      //ShowMessage(E.Message);
    end;
  end;
end;

procedure TVideoMainFrm.addVideoRecordInfoToList(info: string);
var
  i: Integer;
  sList: TStringList;
  strRec: string;
  sTemp: string;
  sDevId, sFileName: string;
  sChannelNo, sRecType: string;
  dtOrg,dtS, dtE: TDateTime;
  sFileSize, sFileOffset: string;
begin
  strRec := StringReplace(info, ' ', ';', [rfReplaceAll]);
  sList := TStringList.Create;
  try
    ExtractStrings([';'], [' '], PChar(strRec), sList);
    //DEVICEID:豫G62172 CH:2 TYPE:8 STARTTIME:1370068928 ENDTIME:1370069160 IMGFORMAT:3 STREAMFLAG:1
    //FILESIZE:16411798 FILEOFFSET:20918784 FILENAME:rec/b1/fly00009.ifv
    sTemp := sList.Strings[0];
    sDevId := Copy(sTemp, 10, Length(sTemp) - 9);

    sTemp := sList.Strings[1];
    sChannelNo := Copy(sTemp, 4, Length(sTemp) - 3);

    sTemp := sList.Strings[2];
    sRecType := Copy(sTemp, 6, Length(sTemp) - 5);

    dtOrg := StrToDateTime('1970-01-01 00:00:00');
    sTemp := sList.Strings[3];
    i := StrToInt(Copy(sTemp, 11, Length(sTemp) - 10));
    dtS := IncSecond(dtOrg, i);

    sTemp := sList.Strings[4];
    i := StrToInt(Copy(sTemp, 9, Length(sTemp) - 8));
    dtE := IncSecond(dtOrg, i);

    sTemp := sList.Strings[7];
    sFileSize := Copy(sTemp, 10, Length(sTemp) - 9);

    sTemp := sList.Strings[8];
    sFileOffset := Copy(sTemp, 12, Length(sTemp) - 11);

    sTemp := sList.Strings[9];
    sFileName := Copy(sTemp, 10, Length(sTemp) - 9);

    with VideoListView.Items.Add do
    begin
      Caption := sDevId;
      //SubItems.Add(sChannelNo);
      //SubItems.Add(sRecType);
      SubItems.Add(FormatDateTime('yy-MM-dd hh:nn', dtS));
      SubItems.Add(FormatDateTime('yy-MM-dd hh:nn', dtE));
      SubItems.Add(sFileSize);
      SubItems.Add(sFileName);
      SubItems.Add(sFileOffset);

    end;  
  finally
    sList.Free;
  end;
end;

procedure TVideoMainFrm.BitBtn2Click(Sender: TObject);
var
  FileName: string;
  FileOffset, RES: longword;

begin
  if VideoListView.Selected = nil then exit;
  FileName := VideoListView.Selected.SubItems[3];
  FileOffset := StrToInt64Def(VideoListView.Selected.SubItems[4], 0);
  
  RES := TLMDVRAx1.StartRemoteRecFilePlay(FDeviceID, FileName, FileOffset);
//  SHOWMESSAGE(FILENAME + ',' + INTTOSTR(FILEOFFSET) + ',' + INTTOSTR(RES));
end;

procedure TVideoMainFrm.BitBtn3Click(Sender: TObject);
begin
  TLMDVRAx1.LoginServer(FServerIP, FPort, FUserName, FPassWord);
end;

procedure TVideoMainFrm.BitBtn4Click(Sender: TObject);
begin
  TLMDVRAx1.StopRemoteRecPlay;
end;

procedure TVideoMainFrm.VideoListViewCustomDrawItem(
  Sender: TCustomListView; Item: TListItem; State: TCustomDrawState;
  var DefaultDraw: Boolean);
var
  i: integer;
begin
  try
    i:= (Sender as TListView).Items.IndexOf(Item);

    if odd(i) then
      sender.Canvas.Brush.Color:= $eeeeee//$e0dfd8
    else
      sender.Canvas.Brush.Color:= clWhite;//$ffeeee;
  except
  end;
end;

procedure TVideoMainFrm.Button1Click(Sender: TObject);
begin
  InitParam;
end;

procedure TVideoMainFrm.Set3GConfig(IP: string; PORT: Integer; USER,
  Password: string; CutPicFilePath: string);
begin
  try
    FServerIP := IP;      // 218.2.75.219
    FPort := PORT;        // 10000
    FUserName := USER;   // user
    FPassWord := Password;   // jycz
    FCutPicFilePath := CutPicFilePath;
  except
    on e: Exception do
    begin
      ShowMessage(e.Message);
    end;
  end;
end;

end.
