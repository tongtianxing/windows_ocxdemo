// OCXDemoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "OCXDemo.h"
#include "OCXDemoDlg.h"
#include "AlarmTypeParse.h"
#include "DlgTransparent.h"
#include "DlgRecSearch1078.h"
#include "DlgUserSession.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


#define REAL_STREAM_TYPE_MAIN				0	//主码流
#define REAL_STREAM_TYPE_SUB				1	//子码流


#define AVDEC_STREAM_MODE_REAL			2
#define AVDEC_STREAM_MODE_SMOOTH			3

#define GPS_FILE_TYPE_NORMAL					0
#define GPS_FILE_TYPE_ALARM						1
#define GPS_FILE_TYPE_ALL						-1




#define VIEW_SIZE_UNDEFINE			-1
#define VIEW_SIZE_FULL				0
#define VIEW_SIZE_4_3				1
#define VIEW_SIZE_16_9				2

#define CLIENT_LAYOUT_COUNT			4

#define VIEW_WND_TETRIS				0		//九宫格
#define VIEW_WND_VERTICAL			1		//竖排
#define VIEW_WND_HORIZONTAL			2		//横排


#define FILE_FORMAT_GREC			0	//.grec文件
#define FILE_FORMAT_MP4				1	//.mp4文件

const int DEV_CHANNEL_ALL = -1;

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COCXDemoDlg dialog

COCXDemoDlg::COCXDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(COCXDemoDlg::IDD, pParent)
	, m_strDevInfo(_T("粤A00000"))
{
	//{{AFX_DATA_INIT(COCXDemoDlg)
	m_strDevIDNO = _T("14001");
	//m_strIP = _T("120.26.98.110");
	//m_strIP = _T("218.5.80.6");
	m_strIP = _T("192.168.1.249");
	//m_strIP = _T("47.104.146.80");
	//m_strIP = _T("202.111.173.178");
	m_strPort = _T("6605");
	m_strDevIDNO = _T("10004");
	m_strSavePicturePath = _T("");
	m_strAutoCloseTime = _T("0");
	m_strRecordSplitTime = _T("60");
	m_strReservedSpace = _T("2048");
	m_bOpenSound = FALSE;
	m_bTalkBack = FALSE;
	m_bMonitor = FALSE;
	m_strTitle = _T("123");
	m_DataBeg = COleDateTime::GetCurrentTime();
	m_nDownTotalLen = 0;
	m_bBroadcast = FALSE;
	m_bShow = FALSE;
//	m_pOCX = NULL;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_bSubscribeGps = FALSE;

	m_pDlgRecSearch1078 = NULL;
}

void COCXDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(COCXDemoDlg)
	DDX_Control(pDX, IDC_SLIDER_SPEED, m_sliSpeed);
	DDX_Control(pDX, IDC_COMBO_VIDEO_MODE, m_cmbVideoMode);
	DDX_Control(pDX, IDC_COMBO_DISK_NO_SPACE_OPERATE_TYPE, m_cmbNoSpaceOperateType);
	DDX_Control(pDX, IDC_COMBO_WND_LAYOUT, m_cmbWndLayout);
	DDX_Control(pDX, IDC_COMBO_WND, m_cmbWnd);
	DDX_Control(pDX, IDC_COMBO_CHANNEL, m_cmbChannel);
	DDX_Control(pDX, IDC_COMBO_VIEW_SIZE, m_cmbViewSize);
	DDX_Control(pDX, IDC_COMBO_VIEW_ARRANGE, m_cmbViewArrangge);
	DDX_Control(pDX, IDC_CMB_REC_FORMAT, m_cmbRecFileFormat);
	DDX_Control(pDX, IDC_CMB_STREAM_TYPE, m_cmbStreamType);

	DDX_Text(pDX, IDC_EDIT_DEV_ID, m_strDevIDNO);
	DDV_MaxChars(pDX, m_strDevIDNO, 15);
	DDX_Text(pDX, IDC_EDIT_SERVER_IP, m_strIP);
	DDV_MaxChars(pDX, m_strIP, 32);
	DDX_Text(pDX, IDC_EDIT_SERVER_PORT, m_strPort);
	DDV_MaxChars(pDX, m_strPort, 6);
	DDX_Text(pDX, IDC_EDIT_PICTURE_SAVE_PATH, m_strSavePicturePath);
	DDX_Text(pDX, IDC_EDIT_AUTO_CLOSE_TIME, m_strAutoCloseTime);
	DDV_MaxChars(pDX, m_strAutoCloseTime, 6);
	DDX_Text(pDX, IDC_EDIT_RECORD_SPLIT_TIME, m_strRecordSplitTime);
	DDV_MaxChars(pDX, m_strRecordSplitTime, 6);
	DDX_Text(pDX, IDC_EDIT_RESERVED_SPACE, m_strReservedSpace);
	DDV_MaxChars(pDX, m_strReservedSpace, 6);
	DDX_Control(pDX, IDC_OCXCTRL, m_OCX);
	DDX_Text(pDX, IDC_EDIT_TITLE, m_strTitle);

	DDX_Control(pDX, IDC_BTN_LIGHT, m_btnLight);
	DDX_Control(pDX, IDC_BTN_WIPER, m_btnWiper);
	DDX_Control(pDX, IDC_BTN_CRUISE, m_btnAutoCruise);
	DDX_Control(pDX, IDC_BTN_ZOOM_DEL, m_btnZoomDel);
	DDX_Control(pDX, IDC_BTN_ZOOM_ADD, m_btnZoomAdd);
	DDX_Control(pDX, IDC_BTN_LIGHT_DEL, m_btnLightDel);
	DDX_Control(pDX, IDC_BTN_LIGHT_ADD, m_btnLightAdd);
	DDX_Control(pDX, IDC_BTN_FOCUS_DEL, m_btnFocusDel);
	DDX_Control(pDX, IDC_BTN_FOCUS_ADD, m_btnFocusAdd);
	DDX_Control(pDX, IDC_BTN_RIGHT_DOWN, m_btnRightDown);
	DDX_Control(pDX, IDC_BTN_LEFT_DOWN, m_btnLeftDown);
	DDX_Control(pDX, IDC_BTN_DOWN, m_btnDown);
	DDX_Control(pDX, IDC_BTN_LEFT, m_btnLeft);
	DDX_Control(pDX, IDC_BTN_RIGHT, m_btnRight);
	DDX_Control(pDX, IDC_BTN_RIGHT_UP, m_btnRightUp);
	DDX_Control(pDX, IDC_BTN_LEFT_UP, m_btnLeftUp);
	DDX_Control(pDX, IDC_BTN_UP, m_btnUp);
	DDX_Control(pDX, IDC_COMBO_WND_SHOW, m_cmbWndShow);

	DDX_Control(pDX, IDC_COMBO_SEARCH_CHANNEL, m_cmbSearchChannel);
	DDX_Control(pDX, IDC_COMBO_LOCATION, m_cmbLocation);
	DDX_Control(pDX, IDC_COMBO_FILE_TYPE, m_cmbFileType);
	DDX_Control(pDX, IDC_COMBO_FILE_ATTRIBUTE, m_cmbFileAttribute);
	DDX_Control(pDX, IDC_COMBO_FILE_ALARM_TYPE, m_cmbAlarmType);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER_SEARCH_TIME, m_DataBeg);
	DDX_Control(pDX, IDC_LIST_FILE, m_lstSearch);
	DDX_Text(pDX, IDC_EDIT_PLATE_NUM, m_strPlateNum);

	//}}AFX_DATA_MAP
	DDX_Text(pDX, IDC_EDIT_DEVINFO, m_strDevInfo);
	DDV_MaxChars(pDX, m_strDevInfo, 15);
}

BEGIN_MESSAGE_MAP(COCXDemoDlg, CDialog)
	//{{AFX_MSG_MAP(COCXDemoDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_FULL, OnButtonFull)
	ON_BN_CLICKED(IDC_BUTTON_NUMBER, OnButtonNumber)
	ON_BN_CLICKED(IDC_BUTTON_STOP, OnButtonStop)
	ON_BN_CLICKED(IDC_BUTTON_PIC, OnButtonPic)
	ON_BN_CLICKED(IDC_BUTTON_PIC_ALL, OnButtonPicAll)
	ON_BN_CLICKED(IDC_BUTTON_PIC_DEV, OnButtonPicDev)
	ON_BN_CLICKED(IDC_BUTTON_OPEN_SOUND, OnButtonOpenSound)
	ON_BN_CLICKED(IDC_BUTTON_TALK_BACK, OnButtonTalkBack)
	ON_BN_CLICKED(IDC_BUTTON_MONITOR, OnButtonMonitor)
	ON_BN_CLICKED(IDC_BUTTON_START_RECORD, OnButtonStartRecord)
	ON_BN_CLICKED(IDC_BUTTON_STOP_RECORD, OnButtonStopRecord)
	ON_BN_CLICKED(IDC_BUTTON_ALL_PIC, OnButtonAllPic)
	ON_CBN_SELCHANGE(IDC_COMBO_WND_LAYOUT, OnSelchangeComboWndLayout)
	ON_BN_CLICKED(IDC_BUTTON_SELECT_PATH, OnButtonSelectPath)
	ON_BN_CLICKED(IDC_BUTTON_AUTO_CLOSE_TIME, OnButtonAutoCloseTime)
	ON_BN_CLICKED(IDC_BUTTON_REC_SPLIT_TIME, OnButtonRecSplitTime)
	ON_BN_CLICKED(IDC_BUTTON_RESERVED_SPACE, OnButtonReservedSpace)
	ON_BN_CLICKED(IDC_BUTTON_DISK_NO_SPACE, OnButtonDiskNoSpace)
	ON_BN_CLICKED(IDC_BUTTON_SAVE_PICTURE_PATH, OnButtonSavePicturePath)
	ON_BN_CLICKED(IDC_BUTTON_OCX_BK, OnButtonOCXBK)
	ON_BN_CLICKED(IDC_BUTTON_SET_TITLE, OnButtonSetTitle)
	ON_BN_CLICKED(IDC_BUTTON_SET_ACTIVE_WND, OnButtonSetActiveWnd)
	ON_BN_CLICKED(IDC_BUTTON_GET_ACTIVE_WND, OnButtonGetActiveWnd)

	ON_CBN_SELCHANGE(IDC_COMBO_VIDEO_MODE, OnSelchangeComboVideoMode)
	ON_CBN_SELCHANGE(IDC_COMBO_WND_SHOW, OnSelchangeComboWndShow)
	ON_CBN_SELCHANGE(IDC_COMBO_VIEW_SIZE, OnSelchangeComboViewSize)
	ON_CBN_SELCHANGE(IDC_COMBO_VIEW_ARRANGE, OnSelchangeComboArrange)

	ON_BN_CLICKED(IDC_BUTTON_SEARCH, OnBtnSearch)
	ON_NOTIFY(NM_RCLICK, IDC_LIST_FILE, OnRclickListFile)

	ON_COMMAND(ID_MENU_RECSEARCH_DOWN, OnMenuRecsearchDown)
	ON_COMMAND(ID_MENU_RECSEARCH_PLAY, OnMenuRecsearchPlay)
	ON_COMMAND(ID_MENU_RECSEARCH_DOWN_EX, OnMenuRecsearchDownEx)
	ON_COMMAND(ID_MENU_RECSEARCH_DOWN_CHANGE_FILE, OnMenuRecsearchDownChangeFile)
	ON_COMMAND(ID_MENU_RECSEARCH_DOWN_NO_CHANGE, OnMenuRecsearchDownNoChange)

	ON_BN_CLICKED(IDC_BTN_GPS, OnBtnGps)

	ON_EN_CHANGE(IDC_EDIT_SERVER_IP, OnChangeEdServer)
	ON_EN_CHANGE(IDC_EDIT_SERVER_PORT, OnChangeEdServer)

	ON_BN_CLICKED(IDC_BTN_ONLINE, OnBtnOnline)
	ON_BN_CLICKED(IDC_BUTTON_3G_NET, OnGet3GInfo)
	ON_BN_CLICKED(IDC_BUTTON_3G_NET_SET, OnSet3GInfo)
	ON_MESSAGE(WM_MSG_PTZ_BTN, OnPTZLButton)
	ON_BN_CLICKED(IDC_BTN_BROADCAST, OnBroadcast)
	ON_BN_CLICKED(IDC_BTN_GET_IDNO, OnGetIDNO)

	
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BTN_PRESET_SET, OnBnClickedBtnPresetSet)
	ON_BN_CLICKED(IDC_BUTTON_SET_DEVINFO, OnBnClickedButtonSetDevinfo)
	ON_BN_CLICKED(IDC_BT_TRANSPARENT, OnBnClickedBtTransparent)
	ON_CBN_SELCHANGE(IDC_COMBO_WND, OnCbnSelchangeComboWnd)
	ON_CBN_SELCHANGE(IDC_COMBO_FILE_ATTRIBUTE, &COCXDemoDlg::OnCbnSelchangeComboFileAttribute)
	ON_BN_CLICKED(IDC_BTN_STOP_PLAYBACK, &COCXDemoDlg::OnBnClickedBtnStopPlayback)
	ON_BN_CLICKED(IDC_BTN_REC_FORMAT, &COCXDemoDlg::OnBnClickedBtnRecFormat)
	ON_BN_CLICKED(IDC_BTN_REC_SEARCH_1078, &COCXDemoDlg::OnBnClickedBtnRecSearch1078)
	ON_BN_CLICKED(IDC_BTN_USER_SESSION, &COCXDemoDlg::OnBnClickedBtnUserSession)
END_MESSAGE_MAP()

BEGIN_EVENTSINK_MAP(COCXDemoDlg, CDialog)
//{{AFX_EVENTSINK_MAP(CTestocxDlg)
	ON_EVENT(COCXDemoDlg, IDC_OCXCTRL, 1, OnClickViewWndctrl, VTS_I4 VTS_BSTR)
	ON_EVENT(COCXDemoDlg, IDC_OCXCTRL, 2, OnDBClickViewWndctrl, VTS_I4 VTS_BSTR)
	ON_EVENT(COCXDemoDlg, IDC_OCXCTRL, 3, OnRClickViewWndctrl, VTS_I4 VTS_BSTR)
	ON_EVENT(COCXDemoDlg, IDC_OCXCTRL, 4, OnRecSearchEvent, VTS_BSTR  VTS_DATE  VTS_DATE  VTS_I4  VTS_I4  VTS_I4  VTS_I4  VTS_I4)
	ON_EVENT(COCXDemoDlg, IDC_OCXCTRL, 5, OnRecSearchMsgEvent, VTS_I4  VTS_I4)
	ON_EVENT(COCXDemoDlg, IDC_OCXCTRL, 6, OnDownFileEvent, VTS_I4  VTS_I4)
	ON_EVENT(COCXDemoDlg, IDC_OCXCTRL, 7, OnGpsStateEvent, VTS_BSTR  VTS_DATE  VTS_I4  VTS_I4  VTS_I4  VTS_I4  VTS_I4  VTS_I4  VTS_I4  VTS_I4  VTS_I4  VTS_I4 VTS_BSTR)
	ON_EVENT(COCXDemoDlg, IDC_OCXCTRL, 8, OnSnapshotDevEvent, VTS_BSTR  VTS_I4  VTS_BSTR  VTS_I4)
	ON_EVENT(COCXDemoDlg, IDC_OCXCTRL, 9, OnGetDevNetFlowStatisticsEvent, VTS_BSTR  VTS_I4  VTS_R4  VTS_R4  VTS_I4  VTS_I4  VTS_I4  VTS_I4  VTS_R4  VTS_R4  VTS_I4  VTS_I4  VTS_I4)
	ON_EVENT(COCXDemoDlg, IDC_OCXCTRL, 10, OnSetDevNetFlowStatisticsEvent, VTS_BSTR  VTS_I4)
	ON_EVENT(COCXDemoDlg, IDC_OCXCTRL, 11, OnDevAlarmEvent, VTS_BSTR  VTS_BSTR VTS_BSTR)
	ON_EVENT(COCXDemoDlg, IDC_OCXCTRL, 12, OnGpsStateEventEx, VTS_BSTR  VTS_BSTR)
	ON_EVENT(COCXDemoDlg, IDC_OCXCTRL, 13, OnDownFileEventEx, VTS_I4  VTS_I4)
	ON_EVENT(COCXDemoDlg, IDC_OCXCTRL, 14, OnGetDevIDNOForPlateNumEvent, VTS_BSTR)
	ON_EVENT(COCXDemoDlg, IDC_OCXCTRL, 15, TransparentConfigEvent, VTS_I4  VTS_BSTR)
	ON_EVENT(COCXDemoDlg, IDC_OCXCTRL, 16, OnRecSearchEventEx, VTS_BSTR  VTS_DATE  VTS_DATE  VTS_I4  VTS_I4  VTS_I4  VTS_I4  VTS_I4  VTS_I4  VTS_I4  VTS_I4  VTS_I4  VTS_I4)
	ON_EVENT(COCXDemoDlg, IDC_OCXCTRL, 17, OnDeviceRequestIntercom, VTS_BSTR)
	ON_EVENT(COCXDemoDlg, IDC_OCXCTRL, 19, COCXDemoDlg::BetchDownFileEventOcxctrl, VTS_BSTR VTS_I4 VTS_I4)

//}}AFX_EVENTSINK_MAP
END_EVENTSINK_MAP()


/////////////////////////////////////////////////////////////////////////////
// COCXDemoDlg message handlers

BOOL COCXDemoDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	CString str;
	int i;
	for (i = 0; i < 4; ++i)
	{
		str.Format("通道-%d", i+1);
		m_cmbChannel.AddString(str);
		m_cmbSearchChannel.AddString(str);
		m_cmbSearchChannel.SetItemData(i, i);
		str.Format("窗口-%d", i+1);
		m_cmbWnd.AddString(str);
	}
	int nIndex = m_cmbSearchChannel.AddString("所有通道");
	m_cmbSearchChannel.SetItemData(nIndex, DEV_CHANNEL_ALL);
	m_cmbSearchChannel.SetCurSel(0);
#ifdef _DEBUG
	m_cmbSearchChannel.SetCurSel(nIndex);
#endif // _DEBUG
	
	m_cmbChannel.SetCurSel(0);
	m_cmbWnd.SetCurSel(0);

	nIndex = 0;
	m_cmbWndLayout.ResetContent();
	m_cmbWndLayout.InsertString(nIndex, _T("1*1"));
	m_cmbWndLayout.SetItemData(nIndex, nIndex + 1);
	nIndex++;
	m_cmbWndLayout.InsertString(nIndex, _T("2*2"));
	m_cmbWndLayout.SetItemData(nIndex, nIndex + 1);
	nIndex++;
	m_cmbWndLayout.InsertString(nIndex, _T("3*3"));
	m_cmbWndLayout.SetItemData(nIndex, nIndex + 1);
	nIndex++;
	m_cmbWndLayout.InsertString(nIndex, _T("4*4"));
	m_cmbWndLayout.SetItemData(nIndex, nIndex + 1);
	nIndex++;
	m_cmbWndLayout.InsertString(nIndex, _T("1+5"));
	m_cmbWndLayout.SetItemData(nIndex, nIndex + 1);
	nIndex++;
// 	m_cmbWndLayout.InsertString(5, _T("1+7"));
// 	m_cmbWndLayout.SetItemData(nIndex, nIndex + 1);
//	nIndex++;
	m_cmbWndLayout.InsertString(nIndex, _T("2*1"));
	m_cmbWndLayout.SetItemData(nIndex, nIndex + 1 + 1);

	m_cmbWndLayout.SetCurSel(1);

	//自动关闭视频
	m_strAutoCloseTime.Format("%d", m_OCX.GetAutoCloseVideoTime());

	//抓拍路径
	m_strSavePicturePath = m_OCX.GetCaptureSavePath();

	//录像
	m_cmbNoSpaceOperateType.AddString("覆盖");
	m_cmbNoSpaceOperateType.AddString("停止");
	m_cmbNoSpaceOperateType.SetCurSel(m_OCX.GetDiskNoSpaceOperateType());

	m_strRecordSplitTime.Format("%d", m_OCX.GetRecordPackTime());
	m_strReservedSpace.Format("%d", m_OCX.GetDiskReservedSpace());

	//视频模式控制
	m_cmbVideoMode.AddString("实时性好");
	m_cmbVideoMode.AddString("流畅性好");
	m_cmbVideoMode.SetCurSel(0);
	OnSelchangeComboVideoMode();

	// 码流类型
	nIndex = 0;
	m_cmbStreamType.InsertString(nIndex++, _T("主码流"));
	m_cmbStreamType.InsertString(nIndex++, _T("子码流"));
	m_cmbStreamType.SetCurSel(1);

	m_cmbWndShow.AddString("实时预览");
	m_cmbWndShow.AddString("远程回放");
	m_cmbWndShow.SetCurSel(0);

	//背景
///////////////////注释部分为修改空间默认外观接口////////////////////////////////
// 	m_OCX.SetColorBK(RGB(255,0,0));
// 	m_OCX.SetColorVideoBK(RGB(0,255,0));
// 	m_OCX.SetColorVideoTitleBK(RGB(0,0,255));
// 	m_OCX.SetColorVideoBKActive(RGB(255,255,0));
// 	m_OCX.SetStrVideoBKPicturePath("dlg_voip_sound.jpg");
//////////////////////////////////////////////////////////////////////////

	DWORD styles = m_lstSearch.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES;
	m_lstSearch.SetExtendedStyle(styles );
	m_lstSearch.InsertColumn(0, "时间", LVCFMT_LEFT, 120);
	m_lstSearch.InsertColumn(1, "类型", LVCFMT_LEFT, 70);
	m_lstSearch.InsertColumn(2, "设备", LVCFMT_LEFT, 90);
	m_lstSearch.InsertColumn(3, "通道", LVCFMT_LEFT, 90);
	m_lstSearch.InsertColumn(4, "位置", LVCFMT_LEFT, 90);
	m_lstSearch.InsertColumn(5, "大小(MB)", LVCFMT_LEFT, 90);
	m_lstSearch.InsertColumn(6, "文件", LVCFMT_LEFT, 240);

	nIndex = 0;
	nIndex = m_cmbLocation.AddString("设备");
	m_cmbLocation.SetItemData(nIndex, GPS_FILE_LOCATION_DEVICE);
	nIndex = m_cmbLocation.AddString("存储服务器");
	m_cmbLocation.SetItemData(nIndex, GPS_FILE_LOCATION_STOSVR);
	nIndex = m_cmbLocation.AddString("下载服务器");
	m_cmbLocation.SetItemData(nIndex, GPS_FILE_LOCATION_DOWNSVR);
	nIndex = m_cmbLocation.AddString("本地");
	m_cmbLocation.SetItemData(nIndex, 3);
	m_cmbLocation.SetCurSel(1);
#ifdef _DEBUG
	m_cmbSearchChannel.SetCurSel(0);
#endif // _DEBUG

	nIndex = m_cmbFileType.AddString("录像");
	m_cmbFileType.SetItemData(nIndex, GPS_FILE_ATTRIBUTE_RECORD);
// 	nIndex = m_cmbFileType.AddString("图片");
// 	m_cmbFileType.SetItemData(nIndex, GPS_FILE_ATTRIBUTE_JPEG);
	m_cmbFileType.SetCurSel(0);

	nIndex = m_cmbAlarmType.AddString("紧急按钮报警");
	m_cmbAlarmType.SetItemData(nIndex, FILE_ALARM_INFO_URGENCY_BUTTON);
	nIndex = m_cmbAlarmType.AddString("超速报警");
	m_cmbAlarmType.SetItemData(nIndex, FILE_ALARM_INFO_OVERSPEED);
	nIndex = m_cmbAlarmType.AddString("低速报警");
	m_cmbAlarmType.SetItemData(nIndex, FILE_ALARM_INFO_LOWSPEED);
	nIndex = m_cmbAlarmType.AddString("振动报警");
	m_cmbAlarmType.SetItemData(nIndex, FILE_ALARM_INFO_SHARK);
	nIndex = m_cmbAlarmType.AddString("温度报警");
	m_cmbAlarmType.SetItemData(nIndex, FILE_ALARM_INFO_TEMPERATOR);
	nIndex = m_cmbAlarmType.AddString("移动侦测报警");
	m_cmbAlarmType.SetItemData(nIndex, FILE_ALARM_INFO_TMOTION);
	nIndex = m_cmbAlarmType.AddString("UPS剪断报警");
	m_cmbAlarmType.SetItemData(nIndex, FILE_ALARM_INFO_UPS_CUT);
	nIndex = m_cmbAlarmType.AddString("碰撞侧翻");
	m_cmbAlarmType.SetItemData(nIndex, FILE_ALARM_INFO_COLLISION);
	nIndex = m_cmbAlarmType.AddString("疲劳驾驶");
	m_cmbAlarmType.SetItemData(nIndex, FILE_ALARM_INFO_FATIGUE);
	nIndex = m_cmbAlarmType.AddString("IO1报警");
	m_cmbAlarmType.SetItemData(nIndex, FILE_ALARM_INFO_IO1);
	nIndex = m_cmbAlarmType.AddString("IO2报警");
	m_cmbAlarmType.SetItemData(nIndex, FILE_ALARM_INFO_IO2);
	nIndex = m_cmbAlarmType.AddString("IO3报警");
	m_cmbAlarmType.SetItemData(nIndex, FILE_ALARM_INFO_IO3);
	nIndex = m_cmbAlarmType.AddString("IO4报警");
	m_cmbAlarmType.SetItemData(nIndex, FILE_ALARM_INFO_IO4);
	nIndex = m_cmbAlarmType.AddString("IO5报警");
	m_cmbAlarmType.SetItemData(nIndex, FILE_ALARM_INFO_IO5);
	nIndex = m_cmbAlarmType.AddString("IO6报警");
	m_cmbAlarmType.SetItemData(nIndex, FILE_ALARM_INFO_IO6);
	nIndex = m_cmbAlarmType.AddString("IO7报警");
	m_cmbAlarmType.SetItemData(nIndex, FILE_ALARM_INFO_IO7);
	nIndex = m_cmbAlarmType.AddString("IO8报警");
	m_cmbAlarmType.SetItemData(nIndex, FILE_ALARM_INFO_IO8);
	nIndex = m_cmbAlarmType.AddString("急加速告警");
	m_cmbAlarmType.SetItemData(nIndex, FILE_ALARM_INFO_RAPID_ACCELERATION);
	nIndex = m_cmbAlarmType.AddString("急减速告警");
	m_cmbAlarmType.SetItemData(nIndex, FILE_ALARM_INFO_RAPID_DECELERATION);
	nIndex = m_cmbAlarmType.AddString("倒车告警");
	m_cmbAlarmType.SetItemData(nIndex, FILE_ALARM_INFO_REVERSING);
	nIndex = m_cmbAlarmType.AddString("超速告警");
	m_cmbAlarmType.SetItemData(nIndex, FILE_ALARM_INFO_CUS_OVER_SPEED);
	m_cmbAlarmType.SetCurSel(0);

	nIndex = m_cmbFileAttribute.AddString("常规");
	m_cmbFileAttribute.SetItemData(nIndex, GPS_FILE_TYPE_NORMAL);
	nIndex = m_cmbFileAttribute.AddString("报警");
	m_cmbFileAttribute.SetItemData(nIndex, GPS_FILE_TYPE_ALARM);
	nIndex = m_cmbFileAttribute.AddString("所有");
	m_cmbFileAttribute.SetItemData(nIndex, GPS_FILE_TYPE_ALL);
	m_cmbFileAttribute.SetCurSel(nIndex);

	nIndex = m_cmbViewSize.AddString("满屏");
	m_cmbViewSize.SetItemData(nIndex, VIEW_SIZE_FULL);
	nIndex = m_cmbViewSize.AddString("4:3");
	m_cmbViewSize.SetItemData(nIndex, VIEW_SIZE_4_3);
	nIndex = m_cmbViewSize.AddString("16:9");
	m_cmbViewSize.SetItemData(nIndex, VIEW_SIZE_16_9);
	m_cmbViewSize.SetCurSel(0);

	nIndex = m_cmbViewArrangge.AddString("正常");
	m_cmbViewArrangge.SetItemData(nIndex, VIEW_WND_TETRIS);
	nIndex = m_cmbViewArrangge.AddString("竖排");
	m_cmbViewArrangge.SetItemData(nIndex, VIEW_WND_VERTICAL);
	nIndex = m_cmbViewArrangge.AddString("横排");
	m_cmbViewArrangge.SetItemData(nIndex, VIEW_WND_HORIZONTAL);
	m_cmbViewArrangge.SetCurSel(0);

	nIndex = m_cmbRecFileFormat.AddString(".grec");
	m_cmbRecFileFormat.SetItemData(nIndex, FILE_FORMAT_GREC);
	nIndex = m_cmbRecFileFormat.AddString(".mp4");
	m_cmbRecFileFormat.SetItemData(nIndex, FILE_FORMAT_MP4);
	m_cmbRecFileFormat.SetCurSel(0);

	UpdateData(FALSE);
	
	m_OCX.SetServerIP(m_strIP);
	m_OCX.SetServerPort(atoi(m_strPort));
	nIndex = m_cmbWndLayout.GetCurSel();
	m_OCX.SetLayout(nIndex+1);


#ifdef _DEBUG
	GetDlgItem(IDC_BTN_REC_SEARCH_1078)->ShowWindow(SW_SHOW);
#else
	GetDlgItem(IDC_BTN_REC_SEARCH_1078)->ShowWindow(SW_HIDE);
#endif // _DEBUG
// 	m_pOCX = new CCMSV6OCX;
// 	m_pOCX->SetServerIP(m_strIP);
// 	m_pOCX->SetServerPort(atoi(m_strPort));


// 	char m_szModuleFile[MAX_PATH] = {0};
// 	strncpy(m_szModuleFile, szModule, sizeof(m_szModuleFile) - 1);
//	str = "Z:\\project\\1010gps\\Bin\\Client\\CMSV6OCX\\bin\\client.dll";
// 
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void COCXDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void COCXDemoDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR COCXDemoDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void COCXDemoDlg::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData(TRUE);
	if (m_strIP.IsEmpty() || m_strPort.IsEmpty() || m_strDevIDNO.IsEmpty() 
		|| m_cmbChannel.GetCurSel() == CB_ERR || m_cmbWnd.GetCurSel() == CB_ERR)
	{
		AfxMessageBox("Parameter Error.");
		return;
	}

	m_OCX.SetServerIP(m_strIP);
	m_OCX.SetServerPort(atoi(m_strPort));

	long nErr = m_OCX.StartVideoEx(m_strDevIDNO.GetBuffer(0), m_cmbChannel.GetCurSel(), m_cmbWnd.GetCurSel(), m_cmbStreamType.GetCurSel());

//	CDialog::OnOK();
}

void COCXDemoDlg::OnButtonFull() 
{
	m_OCX.FullScreen();	
}

void COCXDemoDlg::OnButtonNumber() //++++
{
	UpdateData(TRUE);
	if (m_bShow)
	{
		m_OCX.ShowWindowIndex(m_bShow);
		m_bShow = FALSE;
		SetDlgItemText(IDC_BUTTON_NUMBER, "隐藏标号");
	}
	else
	{
		m_OCX.ShowWindowIndex(m_bShow);
		m_bShow = TRUE;
		SetDlgItemText(IDC_BUTTON_NUMBER, "显示标号");
	}
	
}

BOOL COCXDemoDlg::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	if ( (WM_KEYDOWN == pMsg->message) && (VK_ESCAPE == pMsg->wParam || VK_RETURN == pMsg->wParam))
	{
		if (m_OCX.IsFullScreen())
		{
			m_OCX.ExitFullScreen();
		}
		return FALSE;
	}
	
	return CDialog::PreTranslateMessage(pMsg);
}

void COCXDemoDlg::OnButtonStop() 
{
	UpdateData(TRUE);
	if (m_cmbWnd.GetCurSel() != CB_ERR)
	{
		m_OCX.StopVideo(m_cmbWnd.GetCurSel());
	}
}

void COCXDemoDlg::OnButtonPic() 
{
	UpdateData(TRUE);
	if (m_cmbWnd.GetCurSel() != CB_ERR)
	{
		m_OCX.CapturePicture(m_cmbWnd.GetCurSel());
	}
}

void COCXDemoDlg::OnButtonPicAll() 
{
	UpdateData(TRUE);
	m_OCX.CaptureAllWindowPicture();
}

void COCXDemoDlg::OnButtonPicDev() 
{
	UpdateData(TRUE);
	if (m_cmbChannel.GetCurSel() != CB_ERR && m_strDevIDNO.IsEmpty() == FALSE)
	{
		m_OCX.SnapshotDev(m_strDevIDNO, m_cmbChannel.GetCurSel());
	}
}

void COCXDemoDlg::OnButtonOpenSound() 
{
	UpdateData(TRUE);
	if (m_bOpenSound)
	{
		m_OCX.CloseSound();
		m_bOpenSound = FALSE;
		SetDlgItemText(IDC_BUTTON_OPEN_SOUND, "打开声音");
	}
	else
	{
		if (m_cmbWnd.GetCurSel() != CB_ERR)
		{
			if(m_OCX.OpenSound(m_cmbWnd.GetCurSel()) == S_OK)
			{
				m_bOpenSound = TRUE;
				SetDlgItemText(IDC_BUTTON_OPEN_SOUND, "关闭声音");
			}
		}
	}
}

void COCXDemoDlg::OnButtonTalkBack() 
{
	
	UpdateData(TRUE);
	if (m_bTalkBack)
	{
		m_OCX.StopTalkBack();
		m_bTalkBack = FALSE;
		SetDlgItemText(IDC_BUTTON_TALK_BACK, "开启对讲");
	}
	else
	{
		if (!m_strDevIDNO.IsEmpty())
		{
			m_OCX.StartTalkBack(m_strDevIDNO);
			m_bTalkBack = TRUE;
			SetDlgItemText(IDC_BUTTON_TALK_BACK, "关闭对讲");
		}
	}
}

void COCXDemoDlg::OnButtonMonitor() 
{
	
	UpdateData(TRUE);
	if (m_bMonitor)
	{
		m_OCX.StopMonitor();
		m_bMonitor = FALSE;
		SetDlgItemText(IDC_BUTTON_MONITOR, "开启监听");
	}
	else
	{
		if (!m_strDevIDNO.IsEmpty() && m_cmbChannel.GetCurSel() != CB_ERR)
		{
			long nErr = m_OCX.StartMonitor(m_strDevIDNO, m_cmbChannel.GetCurSel());
			m_bMonitor = TRUE;
			SetDlgItemText(IDC_BUTTON_MONITOR, "关闭监听");
		}
	}
}

void COCXDemoDlg::OnButtonStartRecord() 
{
	
	UpdateData(TRUE);
	if (!m_strDevIDNO.IsEmpty() && m_cmbChannel.GetCurSel() != CB_ERR)
	{
		long lRet = m_OCX.StartRecord(m_strDevIDNO, m_cmbChannel.GetCurSel());
		if ( lRet == S_OK )
		{
			AfxMessageBox(_T("开始录像 成功"));
		}
		else
		{
			AfxMessageBox(_T("开始录像 失败"));
		}
	}
}

void COCXDemoDlg::OnButtonStopRecord() 
{
	UpdateData(TRUE);
	if (!m_strDevIDNO.IsEmpty() && m_cmbChannel.GetCurSel() != CB_ERR)
	{
		m_OCX.StopRecord(m_strDevIDNO, m_cmbChannel.GetCurSel());
	}
}

void COCXDemoDlg::OnButtonAllPic() 
{
	m_OCX.CaptureAllWindowPicture();
}

void COCXDemoDlg::OnSelchangeComboWndLayout() 
{	
	if (m_cmbWndLayout.GetCurSel() != CB_ERR)
	{
		int nCursel = m_cmbWndLayout.GetCurSel();
		int nData = m_cmbWndLayout.GetItemData(nCursel);
		m_OCX.SetLayout(nData);
		int nSum = 0;
		switch (nData)
		{
		case 1:		nSum = 1;					break;	//1*1
		case 2:		nSum = 4;					break;	//2*2
		case 3:		nSum = 9;					break;	//3*3
		case 4:		nSum = 16;					break;	//4*4
		case 5:		nSum = 6;					break;	//1+5
		case 6:		nSum = 8;					break;	//1+7
		case 7:		nSum = 2;					break;	//2*1
		default:
			break;
		}

		int nWndCursel = m_cmbWnd.GetCurSel();
		CString str;
		m_cmbWnd.ResetContent();
		for (int i = 0; i < nSum; ++i)
		{
			str.Format("窗口-%d", i+1);
			m_cmbWnd.AddString(str);
		}
		if (nWndCursel >= nSum)
		{
			nWndCursel = nSum-1;
			m_OCX.SetnActiveWndIndex(nWndCursel);
			m_cmbWnd.SetCurSel(nWndCursel);
		}
		else
		{
			m_cmbWnd.SetCurSel(nWndCursel);
		}
	}
}

void COCXDemoDlg::OnButtonSelectPath() 
{	
	m_strSavePicturePath = ChangeDownPath(m_strSavePicturePath);
	UpdateData(FALSE);
}

void COCXDemoDlg::OnButtonAutoCloseTime() 
{	
	UpdateData(TRUE);
	if (!m_strAutoCloseTime.IsEmpty())
	{
		m_OCX.SetAutoCloseVideoTime(atoi(m_strAutoCloseTime));
		AfxMessageBox("设置成功");
	}
	else
	{
		AfxMessageBox("不能为空");
	}
}

void COCXDemoDlg::OnButtonRecSplitTime() 
{	
	UpdateData(TRUE);
	if (!m_strRecordSplitTime.IsEmpty())
	{
		m_OCX.SetRecordPackTime(atoi(m_strRecordSplitTime));
		AfxMessageBox("设置成功");
	}
	else
	{
		AfxMessageBox("不能为空");
	}
}

void COCXDemoDlg::OnButtonReservedSpace() 
{	
	UpdateData(TRUE);
	if (!m_strReservedSpace.IsEmpty())
	{
		m_OCX.SetDiskReservedSpace(atoi(m_strReservedSpace));
		AfxMessageBox("设置成功");
	}
	else
	{
		AfxMessageBox("不能为空");
	}
}

void COCXDemoDlg::OnButtonDiskNoSpace() 
{	
	UpdateData(TRUE);
	if (m_cmbNoSpaceOperateType.GetCurSel() != CB_ERR)
	{
		m_OCX.SetDiskNoSpaceOperateType(m_cmbNoSpaceOperateType.GetCurSel());
		AfxMessageBox("设置成功");
	}
	else
	{
		AfxMessageBox("选择错误");
	}
}

INT CALLBACK COCXDemoDlg::BrowseCallbackProc(HWND hwnd, 
											  UINT uMsg,
											  LPARAM lp, 
											  LPARAM pData) 
{
	COCXDemoDlg* pThis = (COCXDemoDlg*)pData;
	
	TCHAR szDir[MAX_PATH];
	switch(uMsg) 
	{
	case BFFM_INITIALIZED: 
		pThis->DoBrowseInitialize(hwnd);
		break;
		
	case BFFM_SELCHANGED: 
		// Set the status window to the currently selected path.
		if (SHGetPathFromIDList((LPITEMIDLIST) lp ,szDir))
		{
			::SendMessage(hwnd,BFFM_SETSTATUSTEXT,0,(LPARAM)szDir);
		}
		break;
	}
	return 0;
}

void COCXDemoDlg::DoBrowseInitialize(HWND hwnd)
{
	::SendMessage(hwnd, BFFM_SETSELECTION, TRUE, (LPARAM) ((LPCTSTR)m_strSavePicturePath));
}

CString COCXDemoDlg::ChangeDownPath(CString& strOldPath)
{
	m_strSavePicturePath = strOldPath;
	
	CString strFolder;
	LPMALLOC lpMalloc;
	if (::SHGetMalloc(&lpMalloc) != NOERROR) 
	{
		return strFolder;
	}
	
	CString strName = "cmsv6";
	CString strTitle = "选择路径";
	TCHAR szDisplayName[_MAX_PATH] = {0};
	TCHAR szBuffer[_MAX_PATH] = {0};
	BROWSEINFO browseInfo;
	browseInfo.hwndOwner = GetSafeHwnd();
	browseInfo.pidlRoot = NULL; // set root at Desktop
	browseInfo.pszDisplayName = szDisplayName;
	browseInfo.lpszTitle = strTitle;
	browseInfo.ulFlags = BIF_RETURNFSANCESTORS|BIF_RETURNONLYFSDIRS;
	browseInfo.lpfn = BrowseCallbackProc;
	browseInfo.lParam = (LPARAM)this;
	
	LPITEMIDLIST lpItemIDList;
	if ((lpItemIDList = ::SHBrowseForFolder(&browseInfo)) != NULL) 
	{
		// Get the path of the selected folder from the item ID list.
		if (::SHGetPathFromIDList(lpItemIDList, szBuffer))
		{
			strFolder = szBuffer;
			if (strFolder.Right(1) != "\\")
			{
				strFolder += _T("\\");
			}
		}
		
		lpMalloc->Free(lpItemIDList);
		lpMalloc->Release(); lpMalloc = NULL;
	}
	return strFolder;
}

void COCXDemoDlg::OnButtonSavePicturePath() 
{	
	UpdateData(TRUE);
	if (!m_strSavePicturePath.IsEmpty())
	{
		m_OCX.SetCaptureSavePath(m_strSavePicturePath);
	}
}

void COCXDemoDlg::OnButtonOCXBK()
{
	static BOOL bDefault = TRUE;
	bDefault = !bDefault;
	if ( bDefault )
	{
		m_OCX.SetColorBK(RGB(242,242,242));
		m_OCX.SetColorVideoBK(RGB(194,194,194));
		m_OCX.SetColorVideoTitleBK(RGB(228,228,228));
		m_OCX.SetColorVideoBKActive(RGB(244,244,244));
		m_OCX.SetstrVideoBKPicturePath("video_bk.jpg");
	}
	else
	{
		m_OCX.SetColorBK(RGB(255,0,0));
		m_OCX.SetColorVideoBK(RGB(0,255,0));
		m_OCX.SetColorVideoTitleBK(RGB(0,0,255));
		m_OCX.SetColorVideoBKActive(RGB(255,255,0));
		m_OCX.SetstrVideoBKPicturePath("dlg_voip_sound.jpg");
	}
}


void COCXDemoDlg::OnClickViewWndctrl(long nWindow, LPCTSTR strTitle) 
{
	CString str;
	str.Format("左键单击击视频窗口事件 %d--%s\n", nWindow, strTitle);
	TRACE(str);
	m_cmbWnd.SetCurSel(nWindow);
//	AfxMessageBox(str);
}

void COCXDemoDlg::OnDBClickViewWndctrl(long nWindow, LPCTSTR strTitle) 
{
	CString str;
	str.Format("双击视频窗口事件 %d--%s\n", nWindow, strTitle);
	TRACE(str);
//	AfxMessageBox(str);
	
}

void COCXDemoDlg::OnRClickViewWndctrl(long nWindow, LPCTSTR strTitle) 
{
	CString str;
	str.Format("右键视频窗口事件 %d--%s\n", nWindow, strTitle);
	TRACE(str);
	m_cmbWnd.SetCurSel(nWindow);
//	AfxMessageBox(str);
}

void COCXDemoDlg::OnButtonSetTitle() 
{
	UpdateData(TRUE);

	int nIndex = /*m_cmbWnd.GetCurSel();*/
	m_OCX.GetnActiveWndIndex();
	if (nIndex != CB_ERR)
	{
		//m_OCX.SetViewTitle(nIndex, "123");
		m_OCX.SetViewTitle(nIndex, m_strTitle);
	}
}
void COCXDemoDlg::OnButtonSetActiveWnd()
{
	m_OCX.SetnActiveWndIndex(m_cmbChannel.GetCurSel());
}
void COCXDemoDlg::OnButtonGetActiveWnd()
{
	CString str;
	str.Format("active windows is  %d", m_OCX.GetnActiveWndIndex()+1);
	AfxMessageBox(str);
}
void COCXDemoDlg::OnSelchangeComboVideoMode() 
{
	
	int nIndex = m_cmbVideoMode.GetCurSel();
	if (nIndex != -1)
	{
		if (nIndex == 0)
		{
			nIndex = AVDEC_STREAM_MODE_REAL;
		}
		else
		{
			nIndex = AVDEC_STREAM_MODE_SMOOTH;
		}
		m_OCX.SetVideoControl(nIndex);
	}
}

void COCXDemoDlg::OnSelchangeComboWndShow()
{
	m_OCX.SetShowWnd(m_cmbWndShow.GetCurSel());
}
void COCXDemoDlg::OnSelchangeComboViewSize()
{
	m_OCX.SetPaneType(m_cmbViewSize.GetItemData(m_cmbViewSize.GetCurSel()));
}
void COCXDemoDlg::OnSelchangeComboArrange()
{
	m_OCX.SetWndArrange(m_cmbViewArrangge.GetItemData(m_cmbViewArrangge.GetCurSel()));
}
afx_msg LRESULT COCXDemoDlg::OnPTZLButton( WPARAM wParam, LPARAM lParam )
{
	if (lParam == WM_LBUTTONDOWN)
	{
		switch(wParam)
		{
		case IDC_BTN_DOWN:
			PtzControl(GPS_PTZ_MOVE_BOTTOM);
			break;
		case IDC_BTN_LEFT_DOWN:
			PtzControl(GPS_PTZ_MOVE_LEFT_BOTTOM);
			break;
		case IDC_BTN_LEFT:
			PtzControl(GPS_PTZ_MOVE_LEFT);
			break;
		case IDC_BTN_LEFT_UP:
			PtzControl(GPS_PTZ_MOVE_LEFT_TOP);
			break;
		case IDC_BTN_UP:
			PtzControl(GPS_PTZ_MOVE_TOP);
			break;
		case IDC_BTN_RIGHT_UP:
			PtzControl(GPS_PTZ_MOVE_RIGHT_TOP);
			break;
		case IDC_BTN_RIGHT:
			PtzControl(GPS_PTZ_MOVE_RIGHT);
			break;
		case IDC_BTN_RIGHT_DOWN:
			PtzControl(GPS_PTZ_MOVE_RIGHT_BOTTOM);
			break;
		case IDC_BTN_FOCUS_DEL:
			PtzControl(GPS_PTZ_FOCUS_DEL);
			break;
		case IDC_BTN_FOCUS_ADD:
			PtzControl(GPS_PTZ_FOCUS_ADD);
			break;
		case IDC_BTN_LIGHT_DEL:
			PtzControl(GPS_PTZ_LIGHT_DEL);
			break;
		case IDC_BTN_LIGHT_ADD:
			PtzControl(GPS_PTZ_LIGHT_ADD);
			break;
		case IDC_BTN_ZOOM_DEL:
			PtzControl(GPS_PTZ_ZOOM_DEL);
			break;
		case IDC_BTN_ZOOM_ADD:
			PtzControl(GPS_PTZ_ZOOM_ADD);
			break;
		default:
			break;
		}
	}
	else if(lParam == WM_LBUTTONUP)
	{
		switch(wParam)
		{
		case IDC_BTN_DOWN:
		case IDC_BTN_LEFT_DOWN:
		case IDC_BTN_LEFT:
		case IDC_BTN_LEFT_UP:
		case IDC_BTN_UP:
		case IDC_BTN_RIGHT_UP:
		case IDC_BTN_RIGHT:
		case IDC_BTN_RIGHT_DOWN:
		case IDC_BTN_FOCUS_DEL:
		case IDC_BTN_FOCUS_ADD:
		case IDC_BTN_LIGHT_DEL:
		case IDC_BTN_LIGHT_ADD:
		case IDC_BTN_ZOOM_DEL:
		case IDC_BTN_ZOOM_ADD:
			PtzControl(GPS_PTZ_MOVE_STOP);
			break;
		default:
			break;
		}
	}
	return 0;
}

void COCXDemoDlg::PtzControl(int nCommand, int nParam/* = 0*/)
{
	int nWindow = m_cmbWnd.GetCurSel();
	if (nWindow != CB_ERR)
	{
		m_OCX.PtzControl(nWindow, nCommand, nParam, m_sliSpeed.GetPos());
	}
}
void COCXDemoDlg::DelAllRecItem()
{
	for (int i = 0; i < m_lstSearch.GetItemCount(); ++i)
	{
		GPSFile_S* pNewFile = (GPSFile_S*)m_lstSearch.GetItemData(i);
		delete pNewFile;
		pNewFile = NULL;
	}
	m_lstSearch.DeleteAllItems();
	
}
void COCXDemoDlg::OnBtnSearch()
{
	UpdateData();
	DelAllRecItem();

	if (m_strDevIDNO.IsEmpty() 
		|| m_cmbSearchChannel.GetCurSel() == CB_ERR
		|| m_cmbFileType.GetCurSel() == CB_ERR
		|| m_cmbLocation.GetCurSel() == CB_ERR
		|| m_cmbFileAttribute.GetCurSel() == CB_ERR)
	{
		AfxMessageBox("搜索条件错误");
		return;
	}

	m_OCX.SetServerIP(m_strIP);
	m_OCX.SetServerPort(atoi(m_strPort));
	
	m_DataBeg.SetDateTime(m_DataBeg.GetYear(), m_DataBeg.GetMonth(), m_DataBeg.GetDay(), 0, 0, 0);
	DATE dBeg = m_DataBeg.m_dt;
	m_DataBeg.SetDateTime(m_DataBeg.GetYear(), m_DataBeg.GetMonth(), m_DataBeg.GetDay(), 23, 59, 59);
	DATE dEnd = m_DataBeg.m_dt;
	int nLocation = m_cmbLocation.GetItemData(m_cmbLocation.GetCurSel());
	m_OCX.StartRecSearch(m_strDevIDNO.GetBuffer(0), 
						m_cmbSearchChannel.GetItemData(m_cmbSearchChannel.GetCurSel()),
						m_cmbFileAttribute.GetItemData(m_cmbFileAttribute.GetCurSel()),
						dBeg, dEnd, m_cmbLocation.GetItemData(m_cmbLocation.GetCurSel()), 
						m_cmbFileType.GetItemData(m_cmbFileType.GetCurSel()));

}
int COCXDemoDlg::GetFileListIndex(GPSFile_S* pNewFile)
{
	int nCount = m_lstSearch.GetItemCount();
	int nInsertIndex = nCount;
	for (int i = 0; i < nCount; ++ i)
	{
		GPSFile_S* pFile = (GPSFile_S*)m_lstSearch.GetItemData(i);
		if (pNewFile->uiBegintime < pFile->uiBegintime)
		{
			nInsertIndex = i;
			break;
		}
	}
	return nInsertIndex;
}
CString	FormatSecond(int nSecond)
{
	CString str;
	str.Format("%02d:%02d:%02d", nSecond / 3600, nSecond % 3600 / 60, nSecond % 60);
	return str;
}
CString	GetFileType(int nFileType)
{
	CString str= _T("");
	switch (nFileType)
	{
	case GPS_FILE_TYPE_NORMAL:
		str = "正常";
		break;
	case GPS_FILE_TYPE_ALARM:
		str = "报警";
		break;
	}
	return str;
}

CString	GetFileSize(int nFileSize)
{
	double dMB = nFileSize * 1.0 / 1024 / 1024;
	CString str;
	str.Format("%.3fMB", dMB);
	return str;
}
// char* CheckFileName(const char* szRecFile)
// {
// 	char* p = strrchr(szRecFile, '/');
// 	if(NULL == p)
// 	{
// 		p = strrchr(szRecFile, '\\');
// 	}
// 	
// 	if (p)
// 	{
// 		p = p + 1;
// 	}
// 	
// 	if(!p || p[0] != 'H' || /*static_cast<int> (strlen(p)) != 26 ||*/ p[9] != '-')
// 	{
// 		return NULL;
// 	}
// 	else
// 	{
// 		int length = strlen(szRecFile);
// 		if (stricmp(szRecFile + length - 4, ".mdv") == 0)
// 		{
// 			return p;
// 		}
// 		else
// 		{
// 			return NULL;
// 		}
// 	}
// }
// BOOL GetFileChn(const char* szRecFile, std::list<int>& lstChn)
// {
// 	char *Tempch = CheckFileName(szRecFile);
// 	if (Tempch != NULL)
// 	{
// 		Tempch += 20;
// 		unsigned char c = Net2Hex2Char((unsigned char*)Tempch);
// 		for (int i = 0; i < 16; ++ i)
// 			//for (int i = 0; i < 1; ++ i)
// 		{
// 			if( (c >> i) & 0x1 )
// 			{
// 				lstChn.push_back(i);
// 			}
// 		}
// 		return TRUE;
// 	}
// 	else
// 	{
// 		return FALSE;
// 	}
// }
// 
// //如 'FA' = 15*16 + 10
// unsigned char Net2Hex2Char(unsigned char* pBuf)
// {
// 	return NetHex2Char(pBuf[0]) * 16 + NetHex2Char(pBuf[1]);
// }
// 
// //将16进制转换成char
// unsigned char NetHex2Char(unsigned char ch)
// {
// 	if (ch >= 'A' && ch <= 'F')
// 	{
// 		ch = ch - 'A' + 10;
// 	}
// 	else if ( ch >= '0' && ch <= '9')
// 	{
// 		ch = ch - '0';
// 	}
// 	else
// 	{
// 		ch = 0;
// 	}
// 	return ch;
// }
// typedef std::list<int> lstChn;
// typedef lstChn::iterator lstChnIter;
// CString	GetChannelName(GPSFile_S* pNewFile)
// {
// 	CString strChannelAll;
// 	CString strID, strChannel, strDev;
// 	if (pNewFile->nChn == 98)
// 	{
// 		lstChn chn;
// 		if (GetFileChn(pNewFile->szFile, chn))
// 		{
// 			CDevBase* pDev = CVMgrDevice::GetInstance()->FindDvsDeviceByIDNO(pNewFile->szDevIDNO);
// 			if (pDev)
// 			{
// 				if (chn.size() >= pDev->GetChannelNum())
// 				{
// 					strChannelAll = LOADSTRINGEX(ID_STR_DLG_REC_ALL_CHANNEL);
// 				}
// 				else
// 				{
// 					lstChnIter iter = chn.begin();
// 					while(iter != chn.end())
// 					{
// 						if(GetDevAndChnName(pNewFile->szDevIDNO, (*iter), strID, strDev, strChannel))
// 						{
// 							strChannelAll += strChannel;
// 						}
// 						++iter;
// 					}
// 				}
// 			}
// 		}
// 	}
// 	else
// 	{
// 		if(GetDevAndChnName(pNewFile->szDevIDNO, pNewFile->nChn, strID, strDev, strChannel))
// 		{
// 			strChannelAll += strChannel;
// 		}
// 	}
// 	return strChannelAll;
// }
CString	GetChannelName(GPSFile_S* pNewFile)
{
	CString strChannel;

	int nChnMask = 0;
	if (pNewFile->nChn == 98)
	{
		// 98表示设备所有通道,因根据设备实际通道数显示,此处按4通道展示数据
		nChnMask = 0x0F;
	}
	else
	{
		nChnMask = pNewFile->nChnMask;
	}
	if (pNewFile->nChnMask == 0)
	{
		strChannel.Format("Channel-%d", pNewFile->nChn+1);
	}
	else
	{
		CString strTemp;
		for (int i=0; i<16; i++)
		{
			if (BIT_GET(nChnMask, i))
			{
				strTemp.Format("Channel-%d", i+1);

				if (!strChannel.IsEmpty())
					strChannel += _T(";");

				strChannel += strTemp;
			}
		}
	}
	return strChannel;
}
void COCXDemoDlg::OnRecSearchEvent(LPCTSTR strFile, DATE nStartTime, DATE nEndTime, long nFileLen, long nFileType, long nSvrID, long nLocation, long nChannel)
{
	// 此接口参数太少,尽量不使用,请使用OnRecSearchEventEx
	//OnRecSearchEventEx(strFile, nStartTime, nEndTime, nFileLen, nFileType, nSvrID, nLocation, nChannel, FALSE, FALSE, 0, 0, 0);
}

void COCXDemoDlg::OnRecSearchEventEx(LPCTSTR strFile, DATE nStartTime, DATE nEndTime, long nFileLen, long nFileType, long nSvrID, long nLocation, long nChannel, long bStream, long bRecording, long nFileOffset, long nChnMask, long nAlarmInfo)
{
	//nAlarmInfo 按位解析录像文件和报警的关联,报警的定义如 GPS_ALARM_REC_TYPE_E
	//int nAlarmIndex = m_cmbAlarmType.GetItemData(m_cmbAlarmType.GetCurSel());
	//if (BIT_GET(nAlarmInfo, nAlarmIndex))
	//{
	//	OnRecSearchEvent(strFile, nStartTime, nEndTime, nFileLen, nFileType, nSvrID, nLocation, nChannel);
	//}

	GPSFile_S* pNewFile  = new GPSFile_S;
	memset(pNewFile, 0, sizeof(GPSFile_S));
	COleDateTime DataB(nStartTime);
	COleDateTime DataE(nEndTime);
	pNewFile->nYear = DataB.GetYear();
	pNewFile->nDay = DataB.GetDay();
	pNewFile->nMonth = DataB.GetMonth();

	pNewFile->uiBegintime = DataB.GetHour()*3600+DataB.GetMinute()*60+DataB.GetSecond();
	pNewFile->uiEndtime = DataE.GetHour()*3600+DataE.GetMinute()*60+DataE.GetSecond();
	pNewFile->nFileLen = nFileLen;
	pNewFile->nChn = nChannel;

	pNewFile->nLocation = nLocation;
	pNewFile->nFileType = nFileType;
	pNewFile->nSvrID = nSvrID;

	pNewFile->bStream = bStream;
	pNewFile->bRecording = bRecording;
	pNewFile->nFileOffset = nFileOffset;
	pNewFile->nChnMask = nChnMask;
	pNewFile->nAlarmInfo = nAlarmInfo;

	strncpy(pNewFile->szDevIDNO, m_strDevIDNO.GetBuffer(0), sizeof(pNewFile->szDevIDNO)-1);
	strncpy(pNewFile->szFile, strFile, sizeof(pNewFile->szFile));

	int nIndex = GetFileListIndex(pNewFile);
	m_lstSearch.InsertItem(nIndex, NULL);
	CString str;
	if (GPS_FILE_ATTRIBUTE_JPEG == m_cmbFileAttribute.GetItemData(m_cmbFileAttribute.GetCurSel()))
	{
		str = FormatSecond(pNewFile->uiBegintime);
	}
	else
	{
		str = FormatSecond(pNewFile->uiBegintime);
		str += " - ";
		str += FormatSecond(pNewFile->uiEndtime);
	}
	m_lstSearch.SetItemText(nIndex, 0, str);
	m_lstSearch.SetItemText(nIndex, 1, GetFileType(pNewFile->nFileType));

	CString strChn;
	//	GetDevAndChnName(pNewFile->szDevIDNO, pNewFile->nChn, strID, strDev, strChn);
	m_lstSearch.SetItemText(nIndex, 2, m_strDevIDNO);

	strChn = GetChannelName(pNewFile);
	//strChn.Format("Channel-%d", pNewFile->nChn+1);
	//	m_cmbSearchChannel.GetLBText(m_cmbSearchChannel.GetCurSel(), strChn);
	m_lstSearch.SetItemText(nIndex, 3, strChn);

	CString strLocation;
	m_cmbLocation.GetLBText(m_cmbLocation.GetCurSel(), strLocation);
	m_lstSearch.SetItemText(nIndex, 4, strLocation);
	m_lstSearch.SetItemText(nIndex, 5, GetFileSize(pNewFile->nFileLen));
	m_lstSearch.SetItemText(nIndex, 6, pNewFile->szFile);
	m_lstSearch.SetItemData(nIndex, (DWORD)pNewFile);
}

void COCXDemoDlg::OnRecSearchMsgEvent(long nMsg, long nParam)
{
//	if (NULL != m_pFileSearch && NULL != m_pFileSearch->GetHandle())
	{
		switch(nMsg)
		{
		case 1://GPS_DOWNLOAD_MSG_FAILED:
			{
				AfxMessageBox("失败");
			//	MSG_BOX_STR(LOADSTRINGEX(ID_STR_DLG_REC_SEARCH_FAILED) + GETErrorString(lParam));
			//	StopSearch();
			}
			break;
		case 3://GPS_DOWNLOAD_MSG_FINISHED:
			{
				AfxMessageBox("完成");
			//	StopSearch();
			}
			break;
		}
	}
	//	return 0;
}
#define GPS_DOWNLOAD_MSG_FAILED				1 //失败
#define GPS_DOWNLOAD_MSG_BEGIN				2 //开始
#define GPS_DOWNLOAD_MSG_FINISHED			3 //完成
#define GPS_DOWNLOAD_MSG_PROCESS			4 //进度(文件长度)
#define GPS_DOWNLOAD_MSG_PROCESS_EX			5 //进度(百分比)

#define GPS_ERR_FILE_EXT_ERR			61	//文件格式错误
#define GPS_ERR_FILE_NO_EXIST			62	//服务器上不存在此文件
#define GPS_ERR_FILE_DOWN_OK			63	//文件已全部下载完成
#define GPS_ERR_FILE_DOWN_ING			64	//文件正在下载
#define GPS_ERR_FILE_EMPTY				65	//没有搜索到录像文件
#define GPS_ERR_FILE_USED				66	//文件正在被使用

void COCXDemoDlg::OnDownFileEvent(long nMsg, long nParam)
{
	// 不响应此事件,响应代码在BetchDownFileEventOcxctrl;
	return;
	switch(nMsg)
	{
	case GPS_DOWNLOAD_MSG_BEGIN:
		{
			
		}
		break;
	case GPS_DOWNLOAD_MSG_FAILED:
		{
			if (GPS_ERR_FILE_DOWN_OK == nParam)
			{
				SetDlgItemText(IDC_ST_PROCESS, _T("文件下载成功"));
				TRACE("下载成功");
// 				DoDownFinished();
// 				StartDownNextFile();
			}
			else
			{
				AfxMessageBox("下载失败");
			}
		}
		break;
	case GPS_DOWNLOAD_MSG_FINISHED:
		{
			TRACE("下载成功");
// 			DoDownFinished();
// 			StartDownNextFile();
		}
		break;
	case GPS_DOWNLOAD_MSG_PROCESS:
		{
			double fPer = (nParam * 100.0) / m_nDownTotalLen;
			CString str;
			str.Format("文件下载进度:%0.2f%%", fPer);
		//	m_lstDown.SetItemText(GetDownIndex(), DOWN_PROCESS_SUB_ITEM, str);
		//	TRACE(str);
			SetDlgItemText(IDC_ST_PROCESS, str);
		}
		break;
	default :
		ASSERT(FALSE);
	}
}

void COCXDemoDlg::OnDownFileEventEx(long nMsg, long nParam)
{
	// 不响应此事件,响应代码在BetchDownFileEventOcxctrl;
	return;
	switch(nMsg)
	{
// 	case 0:	//消息
// 		if (nParam == 1)
// 		{
// 			//失败
// 			TRACE("下载失败 \n");
// 		}
// 		else if (nParam == 2)
// 		{
// 			//完成
// 			TRACE("下载完成 \n");
// 		}
// 		break;
	case GPS_DOWNLOAD_MSG_FAILED:
		TRACE("下载失败\n");

	case GPS_DOWNLOAD_MSG_BEGIN:	//下载速度，单位KB/S
		//nParam 为下载速度
		TRACE("下载完成 %d(KB/s)\n", nParam);
		break;
	case GPS_DOWNLOAD_MSG_FINISHED:	//下载时间
		//nParam 为下载的文件时间,单位秒
		//TRACE("下载完成 %d(s)\n", nParam);
		TRACE("下载完成");
		break;
	case GPS_DOWNLOAD_MSG_PROCESS:	//下载进度
		//nParam 为下载进度(0-100)
		//TRACE("下载进度 %d%%\n", nParam);
		{
			CString str;
			str.Format(_T("回放下载进度:%d%%"), nParam);
			SetDlgItemText(IDC_ST_PROCESS, str);
		}
		break;
	}
}

void COCXDemoDlg::OnRclickListFile(NMHDR* pNMHDR, LRESULT* pResult) 
{	
	
	*pResult = 0;
	POSITION pos = m_lstSearch.GetFirstSelectedItemPosition();
	
	if (pos)
	{
		int index = m_lstSearch.GetNextSelectedItem(pos);
		GPSFile_S* pFile = (GPSFile_S*)m_lstSearch.GetItemData(index);
		if (3 == pFile->nLocation)
		{
			return;
		}
		
		CMenu menu;
		menu.LoadMenu(IDR_MENU_POP);
		
		CMenu* pPopup = menu.GetSubMenu(0);
		if (pPopup)
		{
			POINT pt;
			GetCursorPos(&pt);
			pPopup->TrackPopupMenu(TPM_RIGHTBUTTON, pt.x, pt.y, this);
		}
	}
}
void PATHGetModulePath(HMODULE hModule, TCHAR* szPath)
{
	TCHAR	szTemp[MAX_PATH] = { NULL };
	//	System path
	TCHAR	szAppPath[MAX_PATH] = { NULL };
	TCHAR	szAppName[MAX_PATH] = { NULL };

	GetModuleFileName(hModule, szAppName, MAX_PATH);
	GetLongPathName(szAppName, szAppName, MAX_PATH);

	TCHAR*	szPos = _tcsrchr(szAppName, TEXT('\\'));
	_tcsncpy(szAppPath, szAppName, szPos - szAppName + 1);
	_tcscpy(szPath, szAppPath);
}

LPCTSTR PATHGetAppPath()
{
	static TCHAR sAPPPath[MAX_PATH] = {0};
	if (0 == _tcsclen(sAPPPath))
	{
		PATHGetModulePath(NULL, sAPPPath);
	}
	return sAPPPath;
}

void COCXDemoDlg::OnMenuRecsearchDown() 
{
	POSITION pos = m_lstSearch.GetFirstSelectedItemPosition();
	while (pos)
	{
		int nIndex = m_lstSearch.GetNextSelectedItem(pos);
		GPSFile_S* pFile = (GPSFile_S*)m_lstSearch.GetItemData(nIndex);
		if (pFile->bStream)
		{
			AfxMessageBox(_T("下载失败:流式文件不支持按文件下载!"));
			continue;
		}
		DATE dateB = 0;
		DATE dateE = 0;
		SecondToDate(pFile, dateB, dateE);
		SYSTEMTIME st;
		GetLocalTime(&st);
		CString strFile;
		
		// 批量下载任务
		for (int i=0; i<1; i++)
		{
			strFile.Format("%s%04d%02d%02d%02d%02d%02d_%d(%d).tmp", PATHGetAppPath(), st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute, st.wSecond, pFile->nChn, i+1);

			long nErr = m_OCX.StartDownFile(pFile->szDevIDNO, pFile->nChn, pFile->szFile, pFile->nFileLen,
				dateB, dateE, pFile->nLocation, pFile->nSvrID, pFile->nFileType, 
				m_cmbFileType.GetItemData(m_cmbFileType.GetCurSel()), strFile.GetBuffer(0));
			if (nErr == -1)
			{
				AfxMessageBox("失败");
			}
			else if (nErr == -2)
			{
				AfxMessageBox("正在下载,先停止再下");
			}
			else
			{
				m_nDownTotalLen = pFile->nFileLen;
			}
		}
	}
}

void COCXDemoDlg::OnMenuRecsearchPlay() 
{
	POSITION pos = m_lstSearch.GetFirstSelectedItemPosition();
	if (pos)
	{
		int nIndex = m_lstSearch.GetNextSelectedItem(pos);
		GPSFile_S* pFile = (GPSFile_S*)m_lstSearch.GetItemData(nIndex);
		DATE dateB = 0;
		DATE dateE = 0;
		SecondToDate(pFile, dateB, dateE);
		GPSFile_S File = *pFile;
		CheckFilePathAndChannel(File);
		m_OCX.StartPlaybackRec(File.szFile, dateB, dateE, File.szDevIDNO, File.nChn, File.nFileLen, File.nFileType, File.nLocation, File.nSvrID, 0, 0, FALSE);
	}
}

void COCXDemoDlg::OnMenuRecsearchDownEx()
{
	RecsearchDown(-1);
}

void COCXDemoDlg::OnMenuRecsearchDownChangeFile()
{
	RecsearchDown(1);
}

void COCXDemoDlg::OnMenuRecsearchDownNoChange()
{
	RecsearchDown(0);
}

void COCXDemoDlg::RecsearchDown(int nStream)
{
	POSITION pos = m_lstSearch.GetFirstSelectedItemPosition();
	if (pos)
	{
		int nIndex = m_lstSearch.GetNextSelectedItem(pos);
		GPSFile_S* pFile = (GPSFile_S*)m_lstSearch.GetItemData(nIndex);
		DATE dateB = 0;
		DATE dateE = 0;
		SecondToDate(pFile, dateB, dateE);
		//m_OCX.SetServerIP(_T("3gv10.gstech.com.tw"));
		//m_OCX.SetServerPort(6605);

		GPSFile_S File = *pFile;
		if (nStream == 0)				File.bStream = FALSE;
		else if (nStream == 1)			File.bStream = TRUE;

		CheckFilePathAndChannel(File);
		File.bStream = pFile->bStream;

		CString strRecName = m_OCX.MakeRecNameEx("testPlate", "testAlarm", dateB, dateE, File.nChn, File.nFileType, m_OCX.GetRecFileFormat());
		if (!strRecName.IsEmpty())
		{
			CString strDownPath;
			// 批量添加任务
			for (int i=0; i<1; i++)
			{
				strDownPath.Format(_T("%s(%d)%s"), PATHGetAppPath(), i+1, strRecName);
				m_OCX.StartDownFileEx(File.szFile, dateB, dateE, File.szDevIDNO, File.nChn, File.nFileLen
					, File.nFileType, File.nLocation, File.nSvrID, dateB, dateE, FALSE, strDownPath, FALSE);
			}
			AfxMessageBox(_T("下载文件保存路径是:") + strDownPath);
		}
		else
		{
			AfxMessageBox(_T("MakeRecNameEx 调用出错"));
		}
	}
}

void COCXDemoDlg::SecondToDate(GPSFile_S* pFile, DATE& dateB, DATE& dateE)
{
	COleDateTime oleDateStart, oleDateEnd;
	DWORD dwH, dwM, dwS;
	dwH = pFile->uiBegintime/3600;
	dwM = (pFile->uiBegintime%3600)/60;
	dwS = pFile->uiBegintime%60;
	oleDateStart.SetDateTime(pFile->nYear, pFile->nMonth, pFile->nDay, dwH, dwM, dwS);
	dateB = oleDateStart.m_dt;
	dwH = pFile->uiEndtime/3600;
	dwM = (pFile->uiEndtime%3600)/60;
	dwS = pFile->uiEndtime%60;
	oleDateEnd.SetDateTime(pFile->nYear, pFile->nMonth, pFile->nDay, dwH, dwM, dwS);
	dateE = oleDateEnd.m_dt;
}

// int	GetGpsDirection(int nDirection)
// {
// 	return ((nDirection + 22) / 45 ) & 0x7;
// }
// 
// CString FormatGpsDirection(int nDirection)
// {
// 	CString str;
// 	switch( GetGpsDirection(nDirection) )
// 	{
// 	case 0:
// 		str = LOADSTRINGEX(ID_STR_NORTH);
// 		break;
// 	case 1:
// 		str = LOADSTRINGEX(ID_STR_NORTH_EAST);
// 		break;
// 	case 2:
// 		str = LOADSTRINGEX(ID_STR_EAST);
// 		break;
// 	case 3:
// 		str = LOADSTRINGEX(ID_STR_SOUTH_EAST);
// 		break;
// 	case 4:
// 		str = LOADSTRINGEX(ID_STR_SOUTH);
// 		break;
// 	case 5:
// 		str = LOADSTRINGEX(ID_STR_SOUTH_WEST);
// 		break;
// 	case 6:
// 		str = LOADSTRINGEX(ID_STR_WEST);
// 		break;
// 	case 7:
// 		str = LOADSTRINGEX(ID_STR_NORTH_WEST);
// 		break;
// 	default:
// 		break;
// 	}
// 	return str;
// }

//字符串分割
typedef std::vector<CString> vecString;
void ParseString(LPCTSTR szSrc, TCHAR cSplit, vecString& vecStr)
{
	const TCHAR* pTemp = szSrc;
	TCHAR* pFind = (TCHAR*)_tcschr(szSrc, cSplit);
	while(pFind != NULL)
	{
		CString str(pTemp, pFind - pTemp);
		vecStr.push_back(str);
		pTemp = pFind + 1;
		pFind = (TCHAR*)_tcschr(pTemp, cSplit);
	}
	if (*pTemp != '\0')
	{
		CString str = pTemp;
		vecStr.push_back(str);
	}
	else if (!vecStr.empty())	//最后一个','
	{
		vecStr.push_back(_T(""));
	}
}

GPSTime_S ParseStrTime(LPCTSTR szTime)
{
	int nTemp[6] = {0};
	int nParam = _stscanf(szTime, _T("%d-%d-%d %d:%d:%d"), nTemp, nTemp+1, nTemp+2, nTemp+3, nTemp+4, nTemp+5);
	GPSTime_S Time = {nTemp[0]-2000, nTemp[1], nTemp[2], nTemp[3], nTemp[4], nTemp[5]};
	return Time;
}

void COCXDemoDlg::OnGpsStateEvent(BSTR devIDNO, DATE gpsTime, long speed, long youLiang, long huangXiang
								  , long status1, long status2, long status3, long status4
								  , long jingDu, long weiDu, long parkTime, BSTR reserve)
{
	//车辆状态,每位表示车辆的相关状态
	//uiStatus[0]共有32位
	//0位表示GPS定位状态		0无效1有效
	//1位表示ACC状态		0表示ACC关闭1表示ACC开启
	//2位表示左转状态		0无效1左转
	//3位表示右转状态		0无效1右转
	//4位表示刹车状态		0无效1刹车
	//5位表示正转状态		0无效1正转
	//6位表示反转状态		0无效1反转
	//7位表示GPS天线状态		0不存在1存在
	//8,9位为表示硬盘状态		0不存在，1存在，2断电
	//10,11,12位表示3G模块状态  0模块不存在，1无信号，2信号差，3信号一般，4信号好，5信号优
	//13位表示静止状态		1表示静止
	//14位表示超速状态		1表示超速
	//15位表示补传状态		1表示GPS补传
	//16位未使用
	//17位表示本日流量已经受限		1表示受限
	//18位表示本月流量已经超过90%警界	1表示报警
	//19位表示本月流量已经用完		1表示用完
	//关于停车未熄火，如果处理静止状态，并且处于ACC开启状态，则表示停车未熄火
	//20位表示IO1状态	1表示报警
	//21位表示IO2状态	1表示报警
	//22位表示IO3状态	1表示报警
	//23位表示IO4状态	1表示报警
	//24位表示IO5状态	1表示报警
	//25位表示IO6状态	1表示报警
	//26位表示IO7状态	1表示报警
	//27位表示IO8状态	1表示报警
	//28位表示盘符2状态	1表示有效
	//29、30位表示，硬盘2的状态		0不存在，1存在，2断电
	//31未使用
	//uiStatus[1]
	//0位表示进区域报警	
	//1位表示出区域报警	
	
	//2位表示区域内高速报警	
	//3位表示区域内低速报警	
	
	//4位表示区域外高速报警
	//5位表示区域外低速报警	
	
	//6位表示区域内停车报警	
	//7位表示区域外停车报警	
	
	//8位表示日流量预警
	//9位表示日流量超过
	//10位表示月流量预警
	//11位表示月流量超过
	
	//12位--主机掉电由后备电池供电
	//13位--车门开
	//14位--车辆设防
	//15位--电池电压过低
	//16位--电池坏
	//17位--发动机
	
// 	typedef struct _tagGPSVehicleGps
// 	{
// 		GPSTime_S Time;
// 		unsigned int uiSpeed:14;	//速度值 KM/S	9999 = 999.9 	范围(0-16384)
// 		unsigned int uiYouLiang:18;	//油量   升	9999 = 99.99 	范围(0-262100)
// 		unsigned int uiLiCheng;		//里程   公里	9999 = 9.999 	
// 		unsigned int uiHangXiang:9;	//地面航向，(0-360) 范围(0-512)
// 		unsigned int uiMapType:3;	//地图类型		1表示GOOGLE，2表示百度，0表示无效
// 		unsigned int uiReserve:20;  //保留位
// 		unsigned int uiStatus[4];		//目前只使用，每1个状态	0位表示GPS定位状态（0无效，1有效）
// 		short sTempSensor[4];	//温度传感器的状态
// 		int	nJingDu;		//经度	4字节 整数部分	9999999 = 9.999999 
// 		int nWeiDu;			//纬度	4字节 整数部分	9999999 = 9.999999
// 		int	nGaoDu;			//高度，暂时未使用
// 		int	nParkTime;		//停车时长 秒	在静止状态时有效
// 		int	nMapJingDu;		//通过地图模块获取的经度和纬度
// 		int	nMapWeiDu;		//通过地图模块获取的经度和纬度
// 		int	nReserve[2];		//保留参数
// 	}GPSVehicleGps_S;

	COleDateTime dt(gpsTime);

	CString str;
	str.Format(" devIdno:%s, time:%04d%02d%02d %02d:%02d:%02d gps:%d,%d", devIDNO
		, dt.GetYear(), dt.GetMonth(), dt.GetDay(), dt.GetHour(), dt.GetMinute(), dt.GetSecond()
		, jingDu, weiDu);
	SetDlgItemText(IDC_ST_GPS, str);
//	CString str;
//	str.Format("%d,%d",jingDu,weiDu);
//	AfxMessageBox(str);
}

void COCXDemoDlg::OnGpsStateEventEx(LPCTSTR szDevIDNO, LPCTSTR lpGPSInfo)
{
	TRACE("GPS信息------IDNO[%s]\n", szDevIDNO);
	TRACE("GPS信息[%s]\n", lpGPSInfo);
}

//GPS信息格式
//GPS时间,速度,油量,里程,航向,地图类型,保留,状态1,状态2,状态3,状态4,温度传感器1的状态,温度传感器2的状态,温度传感器3的状态,温度传感器4的状态
//经度,纬度,高度,停车时长,通过地图模块获取的经度,通过地图模块获取的纬度,保留参数1,保留参数2
//报警信息格式
//guid,报警时间,报警类型,报警信息,报警参数1,报警参数2,报警参数3,报警参数4,报警描述,源报警类型,保留参数,源报警时间,图片文件信息,szReserve
void COCXDemoDlg::OnDevAlarmEvent(LPCTSTR szDevIDNO, LPCTSTR lpAlarmInfo, LPCTSTR lpGPSInfo)
{
	TRACE("报警信息------IDNO[%s]\n", szDevIDNO);
	TRACE("报警信息[%s]\n", lpAlarmInfo);
	TRACE("GPS信息[%s]\n", lpGPSInfo);

	//1.分割字符串
	vecString vecStr;
	ParseString(lpAlarmInfo, ',', vecStr);

	//2.把字符串转换成GPSAlarmInfo_S结构体
	GPSAlarmInfo_S ArmInfo = {0};
	//do something
	if (vecStr.size() >= 14)
	{
		memcpy(ArmInfo.guid, CStringA(vecStr[0]), sizeof(ArmInfo.guid)-1);
		ArmInfo.Time = ParseStrTime(vecStr[1]);
		ArmInfo.AlarmType = _ttoi(vecStr[2]);
		ArmInfo.AlarmInfo = _ttoi(vecStr[3]);
		ArmInfo.Param[0] = _ttoi(vecStr[4]);
		ArmInfo.Param[1] = _ttoi(vecStr[5]);
		ArmInfo.Param[2] = _ttoi(vecStr[6]);
		ArmInfo.Param[3] = _ttoi(vecStr[7]);
		memcpy(ArmInfo.szDesc, CStringA(vecStr[8]), sizeof(ArmInfo.szDesc)-1);
		ArmInfo.srcAlarmType = _ttoi(vecStr[9]);
		ArmInfo.sReserve = _ttoi(vecStr[10]);
		ArmInfo.srcTime = ParseStrTime(vecStr[11]);
		memcpy(ArmInfo.szImgFile, CStringA(vecStr[12]), sizeof(ArmInfo.szImgFile)-1);
		memcpy(ArmInfo.szReserve, CStringA(vecStr[13]), sizeof(ArmInfo.szReserve)-1);
	}

	//3.解析报警信息
	CString strType, strDesc;
	FormatAlarm2String(ArmInfo, strType, strDesc);
	
}

void COCXDemoDlg::OnBtnGps()
{
	if (!m_bSubscribeGps)
	{
		if (!UpdateData())
		{
			return ;
		}

		CString str;
		GetDlgItem(IDC_ED_GPSDEV)->GetWindowText(str);
		str.TrimLeft(); str.TrimRight();
		if (str.IsEmpty())
		{
			AfxMessageBox("设备编号不得为空");
			return ;
		}

		m_OCX.StartSubscribeGps(str);
		m_OCX.StartSubscribeAlarm(str);
		m_bSubscribeGps = TRUE;
		SetDlgItemText(IDC_BTN_GPS, "停止订阅");
	}
	else
	{
		m_OCX.StopSubscribeGps();
		m_OCX.StopSubscribeAlarm();
		m_bSubscribeGps = FALSE;
		SetDlgItemText(IDC_BTN_GPS, "订阅GPS和报警信息");
	}
}

void COCXDemoDlg::OnChangeEdServer() 
{
	UpdateData(TRUE);	

	m_OCX.SetServerIP(m_strIP);
	m_OCX.SetServerPort(atoi(m_strPort));

}

void COCXDemoDlg::OnBtnOnline()
{
	UpdateData(TRUE);
	if (!m_strDevIDNO.IsEmpty())
	{
		if (0 == m_OCX.CheckOnline(m_strDevIDNO))
		{
			AfxMessageBox("Online");
		}
		else
		{
			AfxMessageBox("Offline");
		}
	}
}

void COCXDemoDlg::OnSnapshotDevEvent(LPCTSTR strDevIDNO, long nChannel, LPCTSTR strFilePath, long nError)
{
	CString str;
	if (nError == 0)
	{
		str.Format("snapshot success! %s-%d-%s", strDevIDNO, nChannel+1, strFilePath);
	}
	else
	{
		str.Format("snapshot falied! %s-%d-%d", strDevIDNO, nChannel+1, nError);
	}
	AfxMessageBox(str);
}

void COCXDemoDlg::OnGet3GInfo()
{
	UpdateData(TRUE);
	if(m_strDevIDNO.IsEmpty())
	{
		AfxMessageBox("please input device IDNO.");
	}
	else
	{
		m_OCX.GetDevNetFlowStatistics(m_strDevIDNO);
	}
}

void COCXDemoDlg::OnSet3GInfo()
{
	UpdateData(TRUE);
	if(m_strDevIDNO.IsEmpty())
	{
		AfxMessageBox("please input device IDNO.");
	}
	else
	{
		float fFlowUsedToday = 10.1f;
		float fFlowUsedMonth = 100.2f;
		long nIsOpenFlowCount = 1;
		long nIsOpenDayFlowRemind = 1;
		long nIsOpenMonthFlwRemind = 1;
		float fDayLimit = 20.3f;
		float fMonthLimit = 200.4f;
		long nDayRemind = 15;
		long nMonthRemind = 150;
		long nMonthTotleDay = 25;
		m_OCX.SetDevNetFlowStatistics(m_strDevIDNO, fFlowUsedToday, fFlowUsedMonth,
			nIsOpenFlowCount, nIsOpenDayFlowRemind, nIsOpenMonthFlwRemind,
			fDayLimit, fMonthLimit, nDayRemind, nMonthRemind, nMonthTotleDay);
	}
}

void COCXDemoDlg::OnGetDevNetFlowStatisticsEvent(LPCTSTR szDevIDNO, long nResult, float fFlowUsedToday
												 , float fFlowUsedMonth, long nStatisticsTime
												 , long nIsOpenFlowCount, long nIsOpenDayFlowRemind
												 , long nIsOpenMonthFlwRemind, float fDayLimit
												 , float fMonthLimit, long nDayRemind
												 , long nMonthRemind, long nMonthTotleDay)
{
	TRACE("设备IDNO:%s \n", szDevIDNO);
	TRACE("结果:%d \n", nResult);	// 0成功,其它失败
	if (nResult == 0)
	{
		TRACE("今日流量:%f \n", fFlowUsedToday);
		TRACE("本月已使用流量:%f \n", fFlowUsedMonth);
		TRACE("统计时间:%d \n", nStatisticsTime);
		TRACE("流量统计开关 0-关闭，1-开启:%d \n", nIsOpenFlowCount);
		TRACE("日流量提醒 0-不提醒 1-提醒:%d \n", nIsOpenDayFlowRemind);
		TRACE("月流量提醒 0-不提醒 1-提醒:%d \n", nIsOpenMonthFlwRemind);
		TRACE("日流量限制(MB):%f \n", fDayLimit);
		TRACE("月流量限制(MB):%f", fMonthLimit);
		TRACE("每天流量提醒（百分比），20%%即20:%d \n", nDayRemind);
		TRACE("每月流量提醒（百分比），20%%即20:%d \n", nMonthRemind);
		TRACE("月结日:%d", nMonthTotleDay);
	}
}
void COCXDemoDlg::OnSetDevNetFlowStatisticsEvent(LPCTSTR szDevIDNO, long nResult)
{
	TRACE("设备IDNO:%s \n", szDevIDNO);
	TRACE("结果:%d \n", nResult);	// 0成功,其它失败
}

void COCXDemoDlg::OnBroadcast()
{
	if (!m_bBroadcast)
	{
		if (!UpdateData())
		{
			return ;
		}
		
		CString str;
		GetDlgItem(IDC_ED_GPSDEV_BROADCAST)->GetWindowText(str);
		str.TrimLeft(); str.TrimRight();
		if (str.IsEmpty())
		{
			AfxMessageBox("设备编号不得为空");
			return ;
		}
		
		m_OCX.StartVoiceBroadcast(str);
		m_bBroadcast = TRUE;
		SetDlgItemText(IDC_BTN_BROADCAST, "停止广播");
	}
	else
	{
		m_OCX.StopVoiceBroadcast();
		m_bBroadcast = FALSE;
		SetDlgItemText(IDC_BTN_BROADCAST, "开始广播");
	}
}

void COCXDemoDlg::OnGetIDNO()
{
	UpdateData(TRUE);
	if (m_strPlateNum.IsEmpty())
	{
		AfxMessageBox("车牌号不能为空.");
		return;
	}
	if(m_OCX.GetDevIDNOForPlateNum(m_strPlateNum.GetBuffer(0)))
	{
		GetDlgItem(IDC_EDIT_PLATE_NUM)->EnableWindow(FALSE);
		GetDlgItem(IDC_BTN_GET_IDNO)->EnableWindow(FALSE);
		SetDlgItemText(IDC_EDIT_IDNO, "");
	}
	else
	{
		AfxMessageBox("正在获取中，稍后再试.");
	}
}

void COCXDemoDlg::OnGetDevIDNOForPlateNumEvent(LPCTSTR szDevIDNO)
{
	if (strlen(szDevIDNO) == 0)
	{
		//完成
		GetDlgItem(IDC_EDIT_PLATE_NUM)->EnableWindow(TRUE);
		GetDlgItem(IDC_BTN_GET_IDNO)->EnableWindow(TRUE);
	}
	else
	{
		SetDlgItemText(IDC_EDIT_IDNO, szDevIDNO);
	}
}

void COCXDemoDlg::TransparentConfigEvent( long iResult, LPCTSTR lpParam )
{
	int n = iResult;
	AfxMessageBox(lpParam);
}

void COCXDemoDlg::OnBnClickedBtnPresetSet()
{

}

void COCXDemoDlg::OnBnClickedButtonSetDevinfo()
{
	UpdateData();
	long lRet = m_OCX.SetDevInfo(m_strDevIDNO, m_strDevInfo);
	if ( lRet == S_OK )
	{
		AfxMessageBox(_T("设置成功"));
	}
	else
	{
		AfxMessageBox(_T("设置失败"));
	}
}

void COCXDemoDlg::OnBnClickedBtTransparent()
{
	static CDlgTransparent *pDlg = NULL;
	if ( pDlg == NULL )
	{
		pDlg = new CDlgTransparent;
		pDlg->Create(CDlgTransparent::IDD, this);
		pDlg->SetOCX(&m_OCX);
		pDlg->CenterWindow();
	}

	if ( pDlg )
	{
		pDlg->ShowWindow(!pDlg->IsWindowVisible());
	}
}

void COCXDemoDlg::OnCbnSelchangeComboWnd()
{
	m_OCX.SetnActiveWndIndex(m_cmbWnd.GetCurSel());
}

void COCXDemoDlg::OnCbnSelchangeComboFileAttribute()
{
	if (GPS_FILE_TYPE_ALARM == m_cmbFileAttribute.GetItemData(m_cmbFileAttribute.GetCurSel()))
	{
		GetDlgItem(IDC_STATIC_ALARM_TYPE)->EnableWindow(TRUE);
		GetDlgItem(IDC_COMBO_FILE_ALARM_TYPE)->EnableWindow(TRUE);
	}
	else
	{
		GetDlgItem(IDC_STATIC_ALARM_TYPE)->EnableWindow(FALSE);
		GetDlgItem(IDC_COMBO_FILE_ALARM_TYPE)->EnableWindow(FALSE);
	}
}

void COCXDemoDlg::OnDeviceRequestIntercom( LPCTSTR szDevIDNO )
{
	// 设备请求对讲
	CString strTip;
	strTip.Format(_T("%s 请求对讲,是否同意?"), szDevIDNO);
	if (IDOK == AfxMessageBox(strTip, MB_OKCANCEL))
	{
		if (m_bTalkBack)
		{
			m_OCX.StopTalkBack();
			m_bTalkBack = FALSE;
			//GetDlgItem(IDC_BUTTON_TALK_BACK, "开启对讲");
		}
		if (!m_bTalkBack)
		{
			m_OCX.StartTalkBack(szDevIDNO);
			m_bTalkBack = TRUE;
			SetDlgItemText(IDC_BUTTON_TALK_BACK, "关闭对讲");
		}
	}
}


void COCXDemoDlg::OnBnClickedBtnStopPlayback()
{
	long lRet = m_OCX.StopPlaybackRec();
	if (lRet == S_OK)
	{
		AfxMessageBox(_T("停止回放成功!"));
	}
	else
	{
		// 
		AfxMessageBox(_T("回放未开始,停止回放失败!"));
	}
}

// 转换回放中文件的路径和通道信息
void COCXDemoDlg::CheckFilePathAndChannel( GPSFile_S& File )
{
	if (File.nLocation == GPS_FILE_LOCATION_DEVICE)
	{
		if (File.nChnMask != 0)
		{
			// 当文件中包含多个通道的录像时,此处仅下载第一个有效通道
			File.nChn = 0;
			for (int i=0; i<8; i++)
			{
				if (BIT_GET(File.nChnMask, i))
				{
					File.nChn = i;
					break;
				}
			}
			File.nChnMask = 0;
		}
		else if (File.nChn == 98) //98表示所有通道
		{
			File.nChn = 0; //改为第一个通道
		}
		// 设备录像应根据协议添加通道,一般流式文件都需要
		if (File.bStream)
		{
			char szChn[8] = {0};
			sprintf(szChn, ";%d", File.nChn);
			strcat(File.szFile, szChn);
		}
	}
}

void COCXDemoDlg::OnBnClickedBtnRecFormat()
{
	m_OCX.SetRecFileFormat(m_cmbRecFileFormat.GetItemData(m_cmbRecFileFormat.GetCurSel()));
}


void COCXDemoDlg::OnBnClickedBtnRecSearch1078()
{
	if (m_pDlgRecSearch1078 == NULL)
	{
		m_pDlgRecSearch1078 = new CDlgRecSearch1078;
		m_pDlgRecSearch1078->Create(CDlgRecSearch1078::IDD, this);
	}

	if (m_pDlgRecSearch1078->GetSafeHwnd())
	{
		m_pDlgRecSearch1078->ShowWindow(SW_SHOW);
	}
}


void COCXDemoDlg::BetchDownFileEventOcxctrl(LPCTSTR strFilePath, long nMsg, long nParam)
{
	CString str;
	switch(nMsg)
	{
	case GPS_DOWNLOAD_MSG_BEGIN:
		{

		}
		break;
	case GPS_DOWNLOAD_MSG_FAILED:
		{
			if (GPS_ERR_FILE_DOWN_OK == nParam)
			{
				str.Format(_T("下载成功:%s"), strFilePath);
				SetDlgItemText(IDC_ST_PROCESS, str);
				TRACE("下载成功");
				// 				DoDownFinished();
				// 				StartDownNextFile();
			}
			else
			{
				str.Format(_T("下载失败:%s"), strFilePath);
				AfxMessageBox(str);
			}
		}
		break;
	case GPS_DOWNLOAD_MSG_FINISHED:
		{
			TRACE("下载成功");
			// 			DoDownFinished();
			// 			StartDownNextFile();
			str.Format(_T("下载成功:%s"), strFilePath);
			SetDlgItemText(IDC_ST_PROCESS, str);
		}
		break;
	case GPS_DOWNLOAD_MSG_PROCESS:
		{
			double fPer = (nParam * 100.0) / max(m_nDownTotalLen, 1);
			str.Format("[%0.2f%%]%s", fPer, strFilePath);
			//	m_lstDown.SetItemText(GetDownIndex(), DOWN_PROCESS_SUB_ITEM, str);
			//	TRACE(str);
			SetDlgItemText(IDC_ST_PROCESS, str);
		}
		break;
	case GPS_DOWNLOAD_MSG_PROCESS_EX:
		{
			str.Format("[%d%%]%s", nParam, strFilePath);
			//	m_lstDown.SetItemText(GetDownIndex(), DOWN_PROCESS_SUB_ITEM, str);
			//	TRACE(str);
			SetDlgItemText(IDC_ST_PROCESS, str);
		}
		break;
		break;
	default :
		ASSERT(FALSE);
	}
}


void COCXDemoDlg::OnBnClickedBtnUserSession()
{
	CDlgUserSession dlg;
	dlg.SetSession(m_OCX.GetUserSession());
	if (IDOK == dlg.DoModal())
	{
		m_OCX.SetUserSession(dlg.GetSession());
	}
}
