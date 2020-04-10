// OCXDemoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "OCXDemo.h"
#include "OCXDemoDlg.h"
#include "AlarmTypeParse.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


#define AVDEC_STREAM_MODE_REAL			2
#define AVDEC_STREAM_MODE_SMOOTH			3

#define GPS_FILE_TYPE_NORMAL					0
#define GPS_FILE_TYPE_ALARM						1
#define GPS_FILE_TYPE_ALL						-1

#define GPS_FILE_LOCATION_DEVICE			1
#define GPS_FILE_LOCATION_STOSVR			2
//客户端3被用做本地搜索，定义出现重复，3先不用
#define GPS_FILE_LOCATION_DOWNSVR			4		//下载服务器录像搜索

#define GPS_FILE_ATTRIBUTE_JPEG				1
#define GPS_FILE_ATTRIBUTE_RECORD			2


#define VIEW_SIZE_UNDEFINE			-1
#define VIEW_SIZE_FULL				0
#define VIEW_SIZE_4_3				1
#define VIEW_SIZE_16_9				2

#define CLIENT_LAYOUT_COUNT			4

#define VIEW_WND_TETRIS				0		//九宫格
#define VIEW_WND_VERTICAL			1		//竖排
#define VIEW_WND_HORIZONTAL			2		//横排

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
{
	//{{AFX_DATA_INIT(COCXDemoDlg)
	m_strDevIDNO = _T("3001");
	m_strSearchDevIDNO = _T("2001");
	m_strIP = _T("127.0.0.1");
	m_strPort = _T("6605");
	m_strSavePicturePath = _T("");
	m_strAutoCloseTime = _T("0");
	m_strRecordSplitTime = _T("60");
	m_strReservedSpace = _T("2048");
	m_bOpenSound = FALSE;
	m_bTalkBack = FALSE;
	m_bMonitor = FALSE;
	m_strTitle = _T("");
	m_DataBeg = COleDateTime::GetCurrentTime();
	m_nDownTotalLen = 0;
	m_bBroadcast = FALSE;
//	m_pOCX = NULL;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_bSubscribeGps = FALSE;
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

	DDX_Text(pDX, IDC_EDIT_DEV_IDNO, m_strSearchDevIDNO);
	DDX_Control(pDX, IDC_COMBO_SEARCH_CHANNEL, m_cmbSearchChannel);
	DDX_Control(pDX, IDC_COMBO_LOCATION, m_cmbLocation);
	DDX_Control(pDX, IDC_COMBO_FILE_TYPE, m_cmbFileType);
	DDX_Control(pDX, IDC_COMBO_FILE_ATTRIBUTE, m_cmbFileAttribute);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER_SEARCH_TIME, m_DataBeg);
	DDX_Control(pDX, IDC_LIST_FILE, m_lstSearch);
	
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(COCXDemoDlg, CDialog)
	//{{AFX_MSG_MAP(COCXDemoDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_FULL, OnButtonFull)
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

	ON_BN_CLICKED(IDC_BTN_GPS, OnBtnGps)

	ON_EN_CHANGE(IDC_EDIT_SERVER_IP, OnChangeEdServer)
	ON_EN_CHANGE(IDC_EDIT_SERVER_PORT, OnChangeEdServer)

	ON_BN_CLICKED(IDC_BTN_ONLINE, OnBtnOnline)
	ON_BN_CLICKED(IDC_BUTTON_3G_NET, OnGet3GInfo)
	ON_BN_CLICKED(IDC_BUTTON_3G_NET_SET, OnSet3GInfo)
	ON_MESSAGE(WM_MSG_PTZ_BTN, OnPTZLButton)
	ON_BN_CLICKED(IDC_BTN_BROADCAST, OnBroadcast)

	
	//}}AFX_MSG_MAP
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
	
	m_cmbChannel.SetCurSel(0);
	m_cmbWnd.SetCurSel(0);

	for (i = 1; i < 6; ++i)
	{
		str.Format("%d", i);
		m_cmbWndLayout.AddString(str);
	}
	m_cmbWndLayout.SetCurSel(m_OCX.GetLayout()-1);

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

	nIndex = m_cmbFileType.AddString("录像");
	m_cmbFileType.SetItemData(nIndex, GPS_FILE_ATTRIBUTE_RECORD);
// 	nIndex = m_cmbFileType.AddString("图片");
// 	m_cmbFileType.SetItemData(nIndex, GPS_FILE_ATTRIBUTE_JPEG);
	m_cmbFileType.SetCurSel(0);

	nIndex = m_cmbFileAttribute.AddString("常规");
	m_cmbFileAttribute.SetItemData(nIndex, GPS_FILE_TYPE_NORMAL);
	nIndex = m_cmbFileAttribute.AddString("报警");
	m_cmbFileAttribute.SetItemData(nIndex, GPS_FILE_TYPE_ALARM);
	nIndex = m_cmbFileAttribute.AddString("所有");
	m_cmbFileAttribute.SetItemData(nIndex, GPS_FILE_TYPE_ALL);
	m_cmbFileAttribute.SetCurSel(0);

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

	UpdateData(FALSE);
	
	m_OCX.SetServerIP(m_strIP);
	m_OCX.SetServerPort(atoi(m_strPort));


// 	m_pOCX = new CCMSV6OCX;
// 	m_pOCX->SetServerIP(m_strIP);
// 	m_pOCX->SetServerPort(atoi(m_strPort));


// 	char m_szModuleFile[MAX_PATH] = {0};
// 	strncpy(m_szModuleFile, szModule, sizeof(m_szModuleFile) - 1);
	str = "Z:\\project\\1010gps\\Bin\\Client\\CMSV6OCX\\bin\\client.dll";
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
		AfxMessageBox("输入错误.");
		return;
	}

	m_OCX.SetServerIP(m_strIP);
	m_OCX.SetServerPort(atoi(m_strPort));

	long nErr = m_OCX.StartVideo(m_strDevIDNO.GetBuffer(0), m_cmbChannel.GetCurSel(), m_cmbWnd.GetCurSel());

//	CDialog::OnOK();
}

void COCXDemoDlg::OnButtonFull() 
{
	// TODO: Add your control notification handler code here
	m_OCX.FullScreen();
	
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
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if (m_cmbWnd.GetCurSel() != CB_ERR)
	{
		m_OCX.StopVideo(m_cmbWnd.GetCurSel());
	}
}

void COCXDemoDlg::OnButtonPic() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if (m_cmbWnd.GetCurSel() != CB_ERR)
	{
		m_OCX.CapturePicture(m_cmbWnd.GetCurSel());
	}
}

void COCXDemoDlg::OnButtonPicAll() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	m_OCX.CaptureAllWindowPicture();
}

void COCXDemoDlg::OnButtonPicDev() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if (m_cmbChannel.GetCurSel() != CB_ERR && m_strDevIDNO.IsEmpty() == FALSE)
	{
		m_OCX.SnapshotDev(m_strDevIDNO, m_cmbChannel.GetCurSel());
	}
}

void COCXDemoDlg::OnButtonOpenSound() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if (m_bOpenSound)
	{
		m_OCX.CloseSound();
		m_bOpenSound = FALSE;
		GetDlgItem(IDC_BUTTON_OPEN_SOUND)->SetWindowText("打开声音");
	}
	else
	{
		if (m_cmbWnd.GetCurSel() != CB_ERR)
		{
			if(m_OCX.OpenSound(m_cmbWnd.GetCurSel()) == S_OK)
			{
				m_bOpenSound = TRUE;
				GetDlgItem(IDC_BUTTON_OPEN_SOUND)->SetWindowText("关闭声音");
			}
		}
	}
}

void COCXDemoDlg::OnButtonTalkBack() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if (m_bTalkBack)
	{
		m_OCX.StopTalkBack();
		m_bTalkBack = FALSE;
		GetDlgItem(IDC_BUTTON_TALK_BACK)->SetWindowText("开启对讲");
	}
	else
	{
		if (!m_strDevIDNO.IsEmpty())
		{
			m_OCX.StartTalkBack(m_strDevIDNO);
			m_bTalkBack = TRUE;
			GetDlgItem(IDC_BUTTON_TALK_BACK)->SetWindowText("关闭对讲");
		}
	}
}

void COCXDemoDlg::OnButtonMonitor() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if (m_bMonitor)
	{
		m_OCX.StopMonitor();
		m_bMonitor = FALSE;
		GetDlgItem(IDC_BUTTON_MONITOR)->SetWindowText("开启监听");
	}
	else
	{
		if (!m_strDevIDNO.IsEmpty() && m_cmbChannel.GetCurSel() != CB_ERR)
		{
			long nErr = m_OCX.StartMonitor(m_strDevIDNO, m_cmbChannel.GetCurSel());
			m_bMonitor = TRUE;
			GetDlgItem(IDC_BUTTON_MONITOR)->SetWindowText("关闭监听");
		}
	}
}

void COCXDemoDlg::OnButtonStartRecord() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if (!m_strDevIDNO.IsEmpty() && m_cmbChannel.GetCurSel() != CB_ERR)
	{
		m_OCX.StartRecord(m_strDevIDNO, m_cmbChannel.GetCurSel());
	}
}

void COCXDemoDlg::OnButtonStopRecord() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if (!m_strDevIDNO.IsEmpty() && m_cmbChannel.GetCurSel() != CB_ERR)
	{
		m_OCX.StopRecord(m_strDevIDNO, m_cmbChannel.GetCurSel());
	}
}

void COCXDemoDlg::OnButtonAllPic() 
{
	// TODO: Add your control notification handler code here
	m_OCX.CaptureAllWindowPicture();
}

void COCXDemoDlg::OnSelchangeComboWndLayout() 
{
	// TODO: Add your control notification handler code here
	if (m_cmbWndLayout.GetCurSel() != CB_ERR)
	{
		m_OCX.SetLayout(m_cmbWndLayout.GetCurSel()+1);
	}
}

void COCXDemoDlg::OnButtonSelectPath() 
{
	// TODO: Add your control notification handler code here
	m_strSavePicturePath = ChangeDownPath(m_strSavePicturePath);
	UpdateData(FALSE);
}

void COCXDemoDlg::OnButtonAutoCloseTime() 
{
	// TODO: Add your control notification handler code here
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
	// TODO: Add your control notification handler code here
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
	// TODO: Add your control notification handler code here
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
	// TODO: Add your control notification handler code here
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
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if (!m_strSavePicturePath.IsEmpty())
	{
		m_OCX.SetCaptureSavePath(m_strSavePicturePath);
	}
}

void COCXDemoDlg::OnButtonOCXBK()
{
	m_OCX.SetColorBK(RGB(255,0,0));
	m_OCX.SetColorVideoBK(RGB(0,255,0));
	m_OCX.SetColorVideoTitleBK(RGB(0,0,255));
	m_OCX.SetColorVideoBKActive(RGB(255,255,0));
	m_OCX.SetStrVideoBKPicturePath("dlg_voip_sound.jpg");
}


void COCXDemoDlg::OnClickViewWndctrl(long nWindow, LPCTSTR strTitle) 
{
	// TODO: Add your control notification handler code here
	CString str;
	str.Format("左键单击击视频窗口事件 %d--%s\n", nWindow, strTitle);
	TRACE(str);
//	AfxMessageBox(str);
}

void COCXDemoDlg::OnDBClickViewWndctrl(long nWindow, LPCTSTR strTitle) 
{
	// TODO: Add your control notification handler code here
	CString str;
	str.Format("双击视频窗口事件 %d--%s\n", nWindow, strTitle);
	TRACE(str);
//	AfxMessageBox(str);
	
}

void COCXDemoDlg::OnRClickViewWndctrl(long nWindow, LPCTSTR strTitle) 
{
	// TODO: Add your control notification handler code here
	CString str;
	str.Format("右键视频窗口事件 %d--%s\n", nWindow, strTitle);
	TRACE(str);
//	AfxMessageBox(str);

}

void COCXDemoDlg::OnButtonSetTitle() 
{
	// TODO: Add your control notification handler code here
	UpdateData(FALSE);
	int nIndex = m_cmbWnd.GetCurSel();
	if (nIndex != CB_ERR)
	{
		m_OCX.SetViewTitle(nIndex, "123");
	}
}
void COCXDemoDlg::OnButtonSetActiveWnd()
{
	m_OCX.SetNActiveWndIndex(m_cmbChannel.GetCurSel());
}
void COCXDemoDlg::OnButtonGetActiveWnd()
{
	CString str;
	str.Format("active windows is  %d", m_OCX.GetNActiveWndIndex()+1);
	AfxMessageBox(str);
}
void COCXDemoDlg::OnSelchangeComboVideoMode() 
{
	// TODO: Add your control notification handler code here
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
void COCXDemoDlg::OnPTZLButton(WPARAM wParam, LPARAM lParam)
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

	if (m_strSearchDevIDNO.IsEmpty() 
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
	m_OCX.StartRecSearch(m_strSearchDevIDNO.GetBuffer(0), 
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
void COCXDemoDlg::OnRecSearchEvent(LPCTSTR strFile, DATE nStartTime, DATE nEndTime, long nFileLen, long nFileType, long nSvrID, long nLocation, long nChannel)
{
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

	strncpy(pNewFile->szDevIDNO, m_strSearchDevIDNO.GetBuffer(0), sizeof(pNewFile->szDevIDNO)-1);
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
	CString strDev;
	CString strID;
//	GetDevAndChnName(pNewFile->szDevIDNO, pNewFile->nChn, strID, strDev, strChn);
	m_lstSearch.SetItemText(nIndex, 2, m_strSearchDevIDNO);
	
//	strChn = GetChannelName(pNewFile);
	strChn.Format("Channel-%d", pNewFile->nChn+1);
//	m_cmbSearchChannel.GetLBText(m_cmbSearchChannel.GetCurSel(), strChn);
	m_lstSearch.SetItemText(nIndex, 3, strChn);
	m_cmbLocation.GetLBText(m_cmbLocation.GetCurSel(), strChn);
	m_lstSearch.SetItemText(nIndex, 4, strChn);
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
#define GPS_DOWNLOAD_MSG_FAILED				1
#define GPS_DOWNLOAD_MSG_BEGIN				2
#define GPS_DOWNLOAD_MSG_FINISHED			3
#define GPS_DOWNLOAD_MSG_PROCESS			4

#define GPS_ERR_FILE_EXT_ERR			61	//文件格式错误
#define GPS_ERR_FILE_NO_EXIST			62	//服务器上不存在此文件
#define GPS_ERR_FILE_DOWN_OK			63	//文件已全部下载完成
#define GPS_ERR_FILE_DOWN_ING			64	//文件正在下载
#define GPS_ERR_FILE_EMPTY				65	//没有搜索到录像文件
#define GPS_ERR_FILE_USED				66	//文件正在被使用

void COCXDemoDlg::OnDownFileEvent(long nMsg, long nParam)
{
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
			str.Format("%0.2f%%", fPer);
		//	m_lstDown.SetItemText(GetDownIndex(), DOWN_PROCESS_SUB_ITEM, str);
			TRACE("下载进度 %s\n", str);
		}
		break;
	default :
		ASSERT(FALSE);
	}
}

void COCXDemoDlg::OnRclickListFile(NMHDR* pNMHDR, LRESULT* pResult) 
{	
	// TODO: Add your control notification handler code here
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
void COCXDemoDlg::OnMenuRecsearchDown() 
{
	// TODO: Add your command handler code here
	POSITION pos = m_lstSearch.GetFirstSelectedItemPosition();
	while (pos)
	{
		int nIndex = m_lstSearch.GetNextSelectedItem(pos);
		GPSFile_S* pFile = (GPSFile_S*)m_lstSearch.GetItemData(nIndex);
		DATE dateB = 0;
		DATE dateE = 0;
		SecondToDate(pFile, dateB, dateE);
		SYSTEMTIME st;
		GetLocalTime(&st);
		CString strFile;
		strFile.Format("c:/%d%d%d%d%d%d.tmp", st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute, st.wSecond);

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

void COCXDemoDlg::OnMenuRecsearchPlay() 
{
	// TODO: Add your command handler code here
	POSITION pos = m_lstSearch.GetFirstSelectedItemPosition();
	while (pos)
	{
		int nIndex = m_lstSearch.GetNextSelectedItem(pos);
		GPSFile_S* pFile = (GPSFile_S*)m_lstSearch.GetItemData(nIndex);
	//	PlayBackRecord(pFile, pFile->File.nChn, 0, FALSE);
		DATE dateB = 0;
		DATE dateE = 0;
		SecondToDate(pFile, dateB, dateE);
		m_OCX.StartPlaybackRec(pFile->szFile, dateB, dateE, pFile->szDevIDNO, pFile->nChn, pFile->nFileLen, pFile->nFileType, pFile->nLocation, pFile->nSvrID, 0, 0, FALSE);
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
	GetDlgItem(IDC_ST_GPS)->SetWindowText(str);
//	CString str;
//	str.Format("%d,%d",jingDu,weiDu);
//	AfxMessageBox(str);
}

void COCXDemoDlg::OnGpsStateEventEx(LPCTSTR szDevIDNO, LPCTSTR lpGPSInfo)
{
	TRACE("GPS信息------IDNO[%s]\n", szDevIDNO);
	TRACE("GPS信息[%s]\n", lpGPSInfo);
}

//报警信息格式
//GPS时间,速度,油量,里程,航向,地图类型,保留,状态1,状态2,状态3,状态4,温度传感器1的状态,温度传感器2的状态,温度传感器3的状态,温度传感器4的状态
//经度,纬度,高度,停车时长,通过地图模块获取的经度,通过地图模块获取的纬度,保留参数1,保留参数2
//GPS信息格式
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
		GetDlgItem(IDC_BTN_GPS)->SetWindowText("停止订阅");
	}
	else
	{
		m_OCX.StopSubscribeGps();
		m_OCX.StopSubscribeAlarm();
		m_bSubscribeGps = FALSE;
		GetDlgItem(IDC_BTN_GPS)->SetWindowText("订阅GPS和报警信息");
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
		float fFlowUsedToday = 10.1;
		float fFlowUsedMonth = 100.2;
		long nIsOpenFlowCount = 1;
		long nIsOpenDayFlowRemind = 1;
		long nIsOpenMonthFlwRemind = 1;
		float fDayLimit = 20.3;
		float fMonthLimit = 200.4;
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
		TRACE("每天流量提醒（百分比），20%即20:%d \n", nDayRemind);
		TRACE("每月流量提醒（百分比），20%即20:%d \n", nMonthRemind);
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
		GetDlgItem(IDC_BTN_BROADCAST)->SetWindowText("停止广播");
	}
	else
	{
		m_OCX.StopVoiceBroadcast();
		m_bBroadcast = FALSE;
		GetDlgItem(IDC_BTN_BROADCAST)->SetWindowText("开始广播");
	}
}