#pragma once


// CDlgUserSession 对话框

class CDlgUserSession : public CDialog
{
	DECLARE_DYNAMIC(CDlgUserSession)

public:
	CDlgUserSession(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDlgUserSession();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_USER_SESSION };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();

	afx_msg void OnBnClickedOk();
	DECLARE_MESSAGE_MAP()
public:
	CString GetSession() const { return m_strSession; }
	void SetSession(LPCTSTR szSession) { m_strSession = szSession; }
private:
	CString m_strSession;
};
