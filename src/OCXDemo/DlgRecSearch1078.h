#pragma once


// CDlgRecSearch1078 对话框

class CDlgRecSearch1078 : public CDialog
{
	DECLARE_DYNAMIC(CDlgRecSearch1078)

public:
	CDlgRecSearch1078(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgRecSearch1078();

// 对话框数据
	enum { IDD = IDD_DLG_REC_SEARCH_1078 };
	CComboBox m_cmbChannel;
	CComboBox m_cmbLocation;
	CComboBox m_cmbFileType;
	CComboBox m_cmbMediaType;
	CComboBox m_cmbCodeStreamType;
	CComboBox m_cmbStorageType;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();

	afx_msg void OnBnClickedBtnRecSearch1078();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedChkAlarm808All();
	afx_msg void OnBnClickedChkAlarm1078All();
};
