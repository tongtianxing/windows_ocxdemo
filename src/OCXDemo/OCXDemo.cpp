// OCXDemo.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "OCXDemo.h"
#include "OCXDemoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COCXDemoApp

BEGIN_MESSAGE_MAP(COCXDemoApp, CWinApp)
	//{{AFX_MSG_MAP(COCXDemoApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COCXDemoApp construction

COCXDemoApp::COCXDemoApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only COCXDemoApp object

COCXDemoApp theApp;

/////////////////////////////////////////////////////////////////////////////
// COCXDemoApp initialization

BOOL COCXDemoApp::InitInstance()
{
	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif
// 	HMODULE m_hModule = LoadLibraryEx("Z:\\project\\1010gps\\Bin\\Client\\CMSV6OCX\\bin\\client.dll", NULL, LOAD_WITH_ALTERED_SEARCH_PATH);	
// 	int nErr = GetLastError();

	COCXDemoDlg dlg;
	m_pMainWnd = &dlg;
	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}

CString COCXDemoApp::Get808AlarmBitString(int nBitPos)
{
	CString strAlarm;
	switch (nBitPos)
	{
	case  0:			strAlarm = _T("紧急报警");				break;
	case  1:			strAlarm = _T("超速报警");				break;
	case  2:			strAlarm = _T("疲劳驾驶");				break;
	case  3:			strAlarm = _T("预警");					break;
	case  4:			strAlarm = _T("GNSS模块发生故障");		break;
	case  5:			strAlarm = _T("GNSS模块未接或被剪断");	break;
	case  6:			strAlarm = _T("GNSS天线短路");			break;
	case  7:			strAlarm = _T("终端主电源欠压");			break;
	case  8:			strAlarm = _T("终端主电源掉电");			break;
	case  9:			strAlarm = _T("终端LCD或显示器故障");	break;
	case 10:			strAlarm = _T("TTS模块故障");			break;
	case 11:			strAlarm = _T("摄像头故障");				break;
	case 12:
	case 13:
	case 14:
	case 15:
	case 16:
	case 17:			strAlarm = _T("12-17 保留");				break;
	case 18:			strAlarm = _T("当天累计驾驶超时");		break;
	case 19:			strAlarm = _T("超时停车");				break;
	case 20:			strAlarm = _T("进出区域");				break;
	case 21:			strAlarm = _T("进出线路");				break;
	case 22:			strAlarm = _T("路线行驶时间不足/过长");	break;
	case 23:			strAlarm = _T("路线偏离报警");			break;
	case 24:			strAlarm = _T("车辆VSS故障");			break;
	case 25:			strAlarm = _T("车辆油量异常");			break;
	case 26:			strAlarm = _T("车辆被盗");				break;
	case 27:			strAlarm = _T("车辆非法点火");			break;
	case 28:			strAlarm = _T("车辆非法位移");			break;
	case 29:			strAlarm = _T("碰撞侧翻报警");			break;
	case 30:
	case 31:			strAlarm = _T("30-31 保留");				break;
	}
	return strAlarm;
}

CString COCXDemoApp::Get808AlarmMaskString(DWORD dwAlarmMask)
{
	CString str;
	for (int i=0; dwAlarmMask; i++)
	{
		if (BIT_GET(dwAlarmMask, 0))
		{
			CString strTemp = Get808AlarmBitString(i);
			if (!str.IsEmpty())
			{
				str += _T(",");
			}
			str += strTemp;
		}
		dwAlarmMask /= 2;
	}
	return str;
}

CString COCXDemoApp::Get1078VideoAlarmBitString(int nBitPos)
{
	CString strAlarm;
	switch (nBitPos)
	{
	case  0:			strAlarm = _T("视频信号丢失报警");				break;
	case  1:			strAlarm = _T("视频信号遮挡报警");				break;
	case  2:			strAlarm = _T("存储单元故障报警");				break;
	case  3:			strAlarm = _T("其他视频设备故障报警");			break;
	case  4:			strAlarm = _T("客车超员报警");					break;
	case  5:			strAlarm = _T("异常驾驶行为报警");				break;
	case  6:			strAlarm = _T("特殊报警录像达到存储阀值报警");	break;
	case  7:
	case  8:
	case  9:
	case 10:
	case 11:
	case 12:
	case 13:
	case 14:
	case 15:
	case 16:
	case 17:
	case 18:
	case 19:
	case 20:
	case 21:
	case 22:
	case 23:
	case 24:
	case 25:
	case 26:
	case 27:
	case 28:
	case 29:
	case 30:
	case 31:			strAlarm = _T("7-31 预留");						break;
	}
	return strAlarm;
}

CString COCXDemoApp::Get1078VideoAlarmMaskString(DWORD dwAlarmMask)
{
	CString str;
	for (int i=0; dwAlarmMask; i++)
	{
		if (BIT_GET(dwAlarmMask, 0))
		{
			CString strTemp = Get1078VideoAlarmBitString(i);
			if (!str.IsEmpty())
			{
				str += _T(",");
			}
			str += strTemp;
		}
		dwAlarmMask /= 2;
	}
	return str;
}
