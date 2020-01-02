#if !defined(AFX_DLGDEV3GCONFIG_H__3C7B1747_0A7B_441A_B050_CCF26215E2ED__INCLUDED_)
#define AFX_DLGDEV3GCONFIG_H__3C7B1747_0A7B_441A_B050_CCF26215E2ED__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgDev3gConfig.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgDev3gConfig dialog
#include "resource.h"
class CDlgDev3gConfig : public CDialog
{
// Construction
public:
	CDlgDev3gConfig(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgDev3gConfig)
	enum { IDD = IDD_DLG_3G_FLOW_CONFIG };
	CComboBox	m_CmbEnableMonitorConfig;
	CString	m_strMonthUsed;
	CString	m_strDayUsed;
	CButton	m_checkDayRemind;
	CButton	m_checkMonthRemind;
	CButton m_btnClear;
	CButton m_btnCorrect;
	CButton m_btnOK;
	CButton m_btnReflesh;
	CButton m_btnCancel;
	CString	m_strPayDay;
	CString	m_strMonthLimit;
	CString	m_strDayLimit;
	CString	m_strDayRemind;
	CString	m_strMonthRemind;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgDev3gConfig)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgDev3gConfig)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnButClear();
	afx_msg void OnButCorrect();
	afx_msg void OnDestroy();
	afx_msg void OnReflesh();
	afx_msg void OnSelchangeComboEnableMonitor();
	//}}AFX_MSG
	afx_msg LRESULT OnGetDevice3gParameterMsg(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnSetDevice3gParameterMsg(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnClearDevice3gParameterMsg(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnAjustDevice3gParameterMsg(WPARAM wParam, LPARAM lParam);

	DECLARE_MESSAGE_MAP()
public:
	void         SetDevice(const char* szDevIDNO) { strncpy(m_szDevIDNO, szDevIDNO, sizeof(m_szDevIDNO)); }

protected:
	void         StartGet3GParmer();
// 	static void CALLBACK FUNMCMsgCBGet3gInfo(GPSMCMsg_S* pMsg, void* pUsr);
// 	void         DoMCMsgCBGet3gInfo(GPSMCMsg_S* pMsg);
// 
// 	static void CALLBACK FUNMCMsgCBSet3gInfo(GPSMCMsg_S* pMsg, void* pUsr);
// 	void         DoMCMsgCBSet3gInfo(GPSMCMsg_S* pMsg);
// 
// 	static void CALLBACK FUNMCMsgCBClear3gStatistic(GPSMCMsg_S* pMsg, void* pUsr);
// 	void         DoMCMsgCBClear3gStatistic(GPSMCMsg_S* pMsg);

//	static void CALLBACK FUNMCMsgCBAdjust3gStatistic(GPSMCMsg_S* pMsg, void* pUsr);
//	void         DoMCMsgCBAdjust3gStatistic(GPSMCMsg_S* pMsg);	

	BOOL         IsRunNian(int nYear);                                           // TRUE?闰年:平年
	int          GetDistanceDay(int nCurrentDay,int nMonthDay,int nYear);        //得到距离结算的天数 
	int          GetMonthDay(int nMonth,int nYear);                              //获取当月的天数。注意有平年、闰年的2月份区别
    void         EnabelCtrl(BOOL bIsEnable);

	void         Loadlanguage();

	void         StopSet3gInfo();
	void         StopClear3gStatistic();
	void         StopGet3gInfo();
	void		 EnableFlowConfig(BOOL bEnable);

private:
	char	 m_szDevIDNO[40];
	long         m_lDev3gInfoGet;           //获取3G信息
//	GPSNetFlowStatistics_S m_NetParam;      //配置信息
	long         m_lDev3gInfoSet;           //3G信息配置
	long         m_lDev3gClearStatistic;    //清空3G流量统计
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGDEV3GCONFIG_H__3C7B1747_0A7B_441A_B050_CCF26215E2ED__INCLUDED_)
