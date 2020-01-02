// DlgTransparent.cpp : 实现文件
//

#include "stdafx.h"
#include "OCXDemo.h"
#include "DlgTransparent.h"
//#include "afxdialogex.h"
#include "cmsv6ocx.h"
#include "OCXDemoDlg.h"


// CDlgTransparent 对话框

IMPLEMENT_DYNAMIC(CDlgTransparent, CDialog)

CDlgTransparent::CDlgTransparent(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgTransparent::IDD, pParent)
	, m_strParam(_T(""))
	, m_strResult(_T(""))
{
	m_pOCX = NULL;
}

CDlgTransparent::~CDlgTransparent()
{
}

void CDlgTransparent::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_ET_PARAM, m_strParam);
	DDX_Text(pDX, IDC_ET_PARAM2, m_strResult);
}


BEGIN_MESSAGE_MAP(CDlgTransparent, CDialog)
	ON_BN_CLICKED(IDOK, OnBnClickedOk)
END_MESSAGE_MAP()


// CDlgTransparent 消息处理程序


void CDlgTransparent::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	//CDialog::OnOK();


	COCXDemoDlg *pDlg = reinterpret_cast<COCXDemoDlg *>(AfxGetMainWnd());
	if ( m_pOCX != NULL && pDlg != NULL )
	{
		UpdateData();
		
		long lRet = m_pOCX->TransparentConfig(pDlg->m_strDevIDNO, 0, m_strParam, m_strParam.GetLength());
		if ( lRet == 0 )
		{
			m_strResult = _T("操作成功");
		}
		else
		{
			m_strResult.Format(_T("操作失败:%d"), lRet);
		}
		UpdateData(FALSE);

	}
}
