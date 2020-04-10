// OCXDemoDlg.h : header file
//

#if !defined(AFX_OCXDEMODLG_H__94FB041F_DB86_4440_B3A6_861C457A0CF6__INCLUDED_)
#define AFX_OCXDEMODLG_H__94FB041F_DB86_4440_B3A6_861C457A0CF6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// COCXDemoDlg dialog
#include "cmsv6ocx.h"
#include "CxPTZButton.h"

#define GPS_PTZ_MOVE_LEFT				0
#define GPS_PTZ_MOVE_RIGHT				1
#define GPS_PTZ_MOVE_TOP				2
#define GPS_PTZ_MOVE_BOTTOM			3
#define GPS_PTZ_MOVE_LEFT_TOP			4
#define GPS_PTZ_MOVE_RIGHT_TOP			5
#define GPS_PTZ_MOVE_LEFT_BOTTOM		6
#define GPS_PTZ_MOVE_RIGHT_BOTTOM		7

#define GPS_PTZ_FOCUS_DEL				8
#define GPS_PTZ_FOCUS_ADD				9
#define GPS_PTZ_LIGHT_DEL				10
#define GPS_PTZ_LIGHT_ADD				11
#define GPS_PTZ_ZOOM_DEL				12
#define GPS_PTZ_ZOOM_ADD				13
#define GPS_PTZ_LIGHT_OPEN				14
#define GPS_PTZ_LIGHT_CLOSE			15
#define GPS_PTZ_WIPER_OPEN				16
#define GPS_PTZ_WIPER_CLOSE			17
#define GPS_PTZ_CRUISE					18
#define GPS_PTZ_MOVE_STOP				19

#define GPS_PTZ_PRESET_MOVE			21
#define GPS_PTZ_PRESET_SET				22
#define GPS_PTZ_PRESET_DEL				23

#define GPS_PTZ_SPEED_MIN				0
#define GPS_PTZ_SPEED_MAX				255
// typedef struct _tagGPSFile
// {
// 	char	szFile[256]; 	/*带路径的文件名*/
// 	int		nYear;
// 	int		nMonth;
// 	int		nDay;
// 	unsigned int uiBegintime;
// 	unsigned int uiEndtime;
// 	char	szDevIDNO[32];			//设备ID
// 	int		nChn;
// 	unsigned int nFileLen;
// 	int		nFileType;
// 	int		nLocation;		//位置，设备上的录像文件，还是存储服务上的录像文件
// 	int		nSvrID;			//存储服务器ID，在为存储服务器上的文件时有效
// }GPSFile_S, *LPGPSFile_S;
class COCXDemoDlg : public CDialog
{
// Construction
public:
	COCXDemoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(COCXDemoDlg)
	enum { IDD = IDD_OCXDEMO_DIALOG };
	//PTZ
	CButton	m_btnLight;
	CButton	m_btnWiper;
	CButton	m_btnAutoCruise;
	CCxPTZButton	m_btnZoomDel;
	CCxPTZButton	m_btnZoomAdd;
	CCxPTZButton	m_btnLightDel;
	CCxPTZButton	m_btnLightAdd;
	CCxPTZButton	m_btnFocusDel;
	CCxPTZButton	m_btnFocusAdd;
	CCxPTZButton	m_btnRightDown;
	CCxPTZButton	m_btnLeftDown;
	CCxPTZButton	m_btnDown;
	CCxPTZButton	m_btnLeft;
	CCxPTZButton	m_btnRight;
	CCxPTZButton	m_btnRightUp;
	CCxPTZButton	m_btnLeftUp;
	CCxPTZButton	m_btnUp;
	int		m_nPoint;
	CEdit m_edPoint;
	CSliderCtrl	m_sliSpeed;

	CComboBox	m_cmbWndShow;
	CComboBox	m_cmbVideoMode;
	CComboBox	m_cmbNoSpaceOperateType;
	CComboBox	m_cmbWndLayout;
	CComboBox	m_cmbWnd;
	CComboBox	m_cmbChannel;
	CComboBox	m_cmbViewSize;
	CComboBox	m_cmbViewArrangge;

	CString	m_strDevIDNO;
	CString	m_strIP;
	CString	m_strPort;
	CString	m_strSavePicturePath;
	CString	m_strAutoCloseTime;
	CString	m_strRecordSplitTime;
	CString	m_strReservedSpace;
	CCMSV6OCX	m_OCX;
//	CCMSV6OCX*	m_pOCX;
	CString	m_strTitle;

	CString m_strSearchDevIDNO;
	CComboBox m_cmbSearchChannel;
	CComboBox m_cmbLocation;
	CComboBox m_cmbFileType;
	CComboBox m_cmbFileAttribute;
	COleDateTime	m_DataBeg;
	CListCtrl m_lstSearch;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COCXDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(COCXDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	afx_msg void OnButtonFull();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnButtonStop();
	afx_msg void OnButtonPic();
	afx_msg void OnButtonPicAll();
	afx_msg void OnButtonPicDev();
	afx_msg void OnButtonOpenSound();
	afx_msg void OnButtonTalkBack();
	afx_msg void OnButtonMonitor();
	afx_msg void OnButtonStartRecord();
	afx_msg void OnButtonStopRecord();
	afx_msg void OnButtonAllPic();
	afx_msg void OnSelchangeComboWndLayout();
	afx_msg void OnButtonSelectPath();
	afx_msg void OnButtonAutoCloseTime();
	afx_msg void OnButtonRecSplitTime();
	afx_msg void OnButtonReservedSpace();
	afx_msg void OnButtonDiskNoSpace();
	afx_msg void OnButtonSavePicturePath();
	afx_msg void OnButtonOCXBK();
	afx_msg void OnButtonSetTitle();
	afx_msg void OnButtonSetActiveWnd();
	afx_msg void OnButtonGetActiveWnd();
	afx_msg void OnSelchangeComboVideoMode();
	afx_msg void OnSelchangeComboWndShow();
	afx_msg void OnSelchangeComboViewSize();
	afx_msg void OnSelchangeComboArrange();
	afx_msg void OnPTZLButton(WPARAM wParam, LPARAM lParam);
	afx_msg void OnBtnSearch();
	afx_msg void OnRclickListFile(NMHDR* pNMHDR, LRESULT* pResult);

	afx_msg void OnMenuRecsearchDown();
	afx_msg void OnMenuRecsearchPlay();

	afx_msg void OnBtnGps();

	afx_msg void OnChangeEdServer();
	afx_msg void OnBtnOnline();
	afx_msg void OnGet3GInfo();
	afx_msg void OnSet3GInfo();
	afx_msg void OnBroadcast();
	//}}AFX_MSG
	afx_msg void OnClickViewWndctrl(long nWindow, LPCTSTR strTitle);
	afx_msg void OnDBClickViewWndctrl(long nWindow, LPCTSTR strTitle);
	afx_msg void OnRClickViewWndctrl(long nWindow, LPCTSTR strTitle);
	afx_msg void OnRecSearchEvent(LPCTSTR strFile, DATE nStartTime, DATE nEndTime, long nFileLen, long nFileType, long nSvrID, long nLocation, long nChannel);
	afx_msg void OnRecSearchMsgEvent(long nMsg, long nParam);
	afx_msg void OnDownFileEvent(long nMsg, long nParam);
	afx_msg void OnGpsStateEvent(BSTR devIDNO, DATE gpsTime, long speed, long youLiang, long huangXiang
							, long status1, long status2, long status3, long status4
							, long jingDu, long weiDu, long parkTime, BSTR reserve);
	afx_msg void OnSnapshotDevEvent(LPCTSTR strDevIDNO, long nChannel, LPCTSTR strFilePath, long nError);
	afx_msg void OnGetDevNetFlowStatisticsEvent(LPCTSTR szDevIDNO, long nResult, float fFlowUsedToday, float fFlowUsedMonth, long nStatisticsTime, long nIsOpenFlowCount, long nIsOpenDayFlowRemind, long nIsOpenMonthFlwRemind, float fDayLimit, float fMonthLimit, long nDayRemind, long nMonthRemind, long nMonthTotleDay);
	afx_msg void OnSetDevNetFlowStatisticsEvent(LPCTSTR szDevIDNO, long nResult);
	afx_msg void OnDevAlarmEvent(LPCTSTR szDevIDNO, LPCTSTR lpAlarmInfo, LPCTSTR lpGPSInfo);
	afx_msg void OnGpsStateEventEx(LPCTSTR szDevIDNO, LPCTSTR lpGPSInfo);

	DECLARE_EVENTSINK_MAP()
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	static INT CALLBACK BrowseCallbackProc(HWND hwnd, UINT uMsg,
		LPARAM lp, LPARAM pData);
	void	DoBrowseInitialize(HWND hwnd);
	
	CString ChangeDownPath(CString& strOldPath);
	void PtzControl(int nCommand, int nParam = 0);
	int GetFileListIndex(GPSFile_S* pNewFile);
	void DelAllRecItem();
	void SecondToDate(GPSFile_S* pFile, DATE& dateB, DATE& dateE);

private:
	BOOL m_bOpenSound;
	BOOL m_bTalkBack;
	BOOL m_bMonitor;
	long m_nDownTotalLen;
	BOOL m_bSubscribeGps;
	BOOL m_bBroadcast;	//广播标志
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OCXDEMODLG_H__94FB041F_DB86_4440_B3A6_861C457A0CF6__INCLUDED_)
