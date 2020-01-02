#pragma once


// CDlgTransparent 对话框
class CCMSV6OCX;
class CDlgTransparent : public CDialog
{
	DECLARE_DYNAMIC(CDlgTransparent)

public:
	CDlgTransparent(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgTransparent();

// 对话框数据
	enum { IDD = IDD_TRANSPARENT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
	CCMSV6OCX *m_pOCX;
public:
	afx_msg void OnBnClickedOk();
	CString m_strParam;
	CString m_strResult;
	void SetOCX(CCMSV6OCX * pOCX) { m_pOCX = pOCX; }
};
