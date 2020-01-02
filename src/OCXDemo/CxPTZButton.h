#if !defined(AFX_CXPTZBUTTON_H__629975CD_C2AD_4869_97A0_CEC21547CBE0__INCLUDED_)
#define AFX_CXPTZBUTTON_H__629975CD_C2AD_4869_97A0_CEC21547CBE0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CxPTZButton.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCxPTZButton window
#define  WM_MSG_PTZ_BTN  WM_USER + 0x101
class CCxPTZButton : public CButton
{
// Construction
public:
	CCxPTZButton();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCxPTZButton)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CCxPTZButton();

	// Generated message map functions
protected:
	//{{AFX_MSG(CCxPTZButton)
		// NOTE - the ClassWizard will add and remove member functions here.
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);

	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CXPTZBUTTON_H__629975CD_C2AD_4869_97A0_CEC21547CBE0__INCLUDED_)
