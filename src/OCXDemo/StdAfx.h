// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__CBF03BC0_CF6C_449A_AA20_F2F052166647__INCLUDED_)
#define AFX_STDAFX_H__CBF03BC0_CF6C_449A_AA20_F2F052166647__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#include <afxdisp.h>        // MFC Automation classes
#include <afxdtctl.h>		// MFC support for Internet Explorer 4 Common Controls
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.
#pragma warning(disable : 4996)
#pragma warning(disable : 4786)
#include <map>
#include <list>
#include <vector>

#include "GPSDeviceDef.h"


//一个位的设置、清除、获取宏   
#define   BIT_SET(var, bit) ((var) |= (1<<(bit)))
#define   BIT_CLEAR(var, bit) ((var) &= ~(1<<(bit)))
#define   BIT_GET(var, bit) (((var)>>(bit)) & 0x01)

#endif // !defined(AFX_STDAFX_H__CBF03BC0_CF6C_449A_AA20_F2F052166647__INCLUDED_)
