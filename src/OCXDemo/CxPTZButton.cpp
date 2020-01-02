// CxPTZButton.cpp : implementation file
//

#include "stdafx.h"
#include "OCXDemo.h"
#include "CxPTZButton.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCxPTZButton

CCxPTZButton::CCxPTZButton()
{
}

CCxPTZButton::~CCxPTZButton()
{
}


BEGIN_MESSAGE_MAP(CCxPTZButton, CButton)
	//{{AFX_MSG_MAP(CCxPTZButton)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCxPTZButton message handlers

void CCxPTZButton::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	GetParent()->SendMessage(WM_MSG_PTZ_BTN, GetDlgCtrlID(), WM_LBUTTONDOWN);
	CButton::OnLButtonDown(nFlags, point);
}

void CCxPTZButton::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	GetParent()->SendMessage(WM_MSG_PTZ_BTN, GetDlgCtrlID(), WM_LBUTTONUP);
	CButton::OnLButtonUp(nFlags, point);
}