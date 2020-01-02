// OCXDemo.h : main header file for the OCXDEMO application
//

#if !defined(AFX_OCXDEMO_H__BDEF234C_0A2F_4608_B43D_D9B09F8D8790__INCLUDED_)
#define AFX_OCXDEMO_H__BDEF234C_0A2F_4608_B43D_D9B09F8D8790__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// COCXDemoApp:
// See OCXDemo.cpp for the implementation of this class
//

class COCXDemoApp : public CWinApp
{
public:
	COCXDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COCXDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(COCXDemoApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

public:
	//808
	//  JT/T 808-2011 表 18 报警标志位定义
	// 解析报警位,0~31
	CString Get808AlarmBitString(int nBitPos);
	// 解析多个报警位
	CString Get808AlarmMaskString(DWORD dwAlarmMask);

	//1078
	// JTT 1078-2016 表 13 报警关键字
	// 解析报警位,0~31
	CString Get1078VideoAlarmBitString(int nBitPos);
	// 解析多个报警位
	CString Get1078VideoAlarmMaskString(DWORD dwAlarmMask);
};
extern COCXDemoApp theApp;;


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OCXDEMO_H__BDEF234C_0A2F_4608_B43D_D9B09F8D8790__INCLUDED_)
