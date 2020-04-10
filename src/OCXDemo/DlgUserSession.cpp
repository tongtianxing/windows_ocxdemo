// DlgUserSession.cpp: 实现文件
//

#include "stdafx.h"
#include "OCXDemo.h"
#include "DlgUserSession.h"


// CDlgUserSession 对话框

IMPLEMENT_DYNAMIC(CDlgUserSession, CDialog)

CDlgUserSession::CDlgUserSession(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DLG_USER_SESSION, pParent)
{

}

CDlgUserSession::~CDlgUserSession()
{
}

void CDlgUserSession::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgUserSession, CDialog)
	ON_BN_CLICKED(IDOK, &CDlgUserSession::OnBnClickedOk)
END_MESSAGE_MAP()


// CDlgUserSession 消息处理程序


BOOL CDlgUserSession::OnInitDialog()
{
	CDialog::OnInitDialog();

	reinterpret_cast<CEdit*>(GetDlgItem(IDC_ED_SESSION))->LimitText(32);
	SetDlgItemText(IDC_ED_SESSION, m_strSession);
	GetDlgItem(IDC_ED_SESSION)->SetFocus();

	return FALSE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CDlgUserSession::OnBnClickedOk()
{
	int nLength = GetDlgItem(IDC_ED_SESSION)->GetWindowTextLength();
	if (nLength > 0)
	{
		if (nLength != 32)
		{
			AfxMessageBox(_T("用户会话号只支持32字节长度,其他值不支持!"));
			return;
		}
	}
	GetDlgItemText(IDC_ED_SESSION, m_strSession);

	CDialog::OnOK();
}
