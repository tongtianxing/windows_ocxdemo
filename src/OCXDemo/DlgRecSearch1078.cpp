// DlgRecSearch1078.cpp : 实现文件
//

#include "stdafx.h"
#include "OCXDemo.h"
#include "DlgRecSearch1078.h"
#include "OCXDemoDlg.h"


// CDlgRecSearch1078 对话框

IMPLEMENT_DYNAMIC(CDlgRecSearch1078, CDialog)

CDlgRecSearch1078::CDlgRecSearch1078(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgRecSearch1078::IDD, pParent)
{

}

CDlgRecSearch1078::~CDlgRecSearch1078()
{
}

void CDlgRecSearch1078::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CMB_CHANNEL, m_cmbChannel);
	DDX_Control(pDX, IDC_CMB_LOCATION, m_cmbLocation);
	DDX_Control(pDX, IDC_CMB_FILE_TYPE, m_cmbFileType);
	DDX_Control(pDX, IDC_CMB_MEDIA_TYPE, m_cmbMediaType);
	DDX_Control(pDX, IDC_CMB_CODESTREAM_TYPE, m_cmbCodeStreamType);
	DDX_Control(pDX, IDC_CMB_STOREGE_TYPE, m_cmbStorageType);
}


BEGIN_MESSAGE_MAP(CDlgRecSearch1078, CDialog)
	ON_BN_CLICKED(IDC_BTN_REC_SEARCH_1078, &CDlgRecSearch1078::OnBnClickedBtnRecSearch1078)
	ON_BN_CLICKED(IDC_CHK_ALARM_808_ALL, &CDlgRecSearch1078::OnBnClickedChkAlarm808All)
	ON_BN_CLICKED(IDC_CHK_ALARM_1078_ALL, &CDlgRecSearch1078::OnBnClickedChkAlarm1078All)
END_MESSAGE_MAP()


// CDlgRecSearch1078 消息处理程序


BOOL CDlgRecSearch1078::OnInitDialog()
{
	CDialog::OnInitDialog();


	CString strTemp;
	int nIndex = 0;
	for (int i=0; i<4; i++)
	{
		strTemp.Format(_T("通道%d"), i+1);
		m_cmbChannel.InsertString(nIndex++, strTemp);
	}
	m_cmbChannel.InsertString(nIndex++, _T("所有通道"));
	m_cmbChannel.SetCurSel(m_cmbChannel.GetCount() - 1);

	nIndex = 0;
	m_cmbLocation.InsertString(nIndex, _T("设备"));
	m_cmbLocation.SetItemData(nIndex++, GPS_FILE_LOCATION_DEVICE);
	m_cmbLocation.InsertString(nIndex, _T("存储服务器"));
	m_cmbLocation.SetItemData(nIndex++, GPS_FILE_LOCATION_STOSVR);
	m_cmbLocation.InsertString(nIndex, _T("下载服务器"));
	m_cmbLocation.SetItemData(nIndex++, GPS_FILE_LOCATION_DOWNSVR);
	m_cmbLocation.SetCurSel(0);

	nIndex = 0;
	m_cmbFileType.InsertString(nIndex, _T("录像"));
	m_cmbFileType.SetItemData(nIndex++, GPS_FILE_ATTRIBUTE_RECORD);
	m_cmbFileType.SetCurSel(0);

	// 0：音视频，1：音频，2：视频，3：视频或音视频
	nIndex = 0;
	m_cmbMediaType.InsertString(nIndex, _T("音视频"));
	m_cmbMediaType.SetItemData(nIndex++, 0);
	m_cmbMediaType.InsertString(nIndex, _T("视频"));
	m_cmbMediaType.SetItemData(nIndex++, 1);
	m_cmbMediaType.InsertString(nIndex, _T("音频"));
	m_cmbMediaType.SetItemData(nIndex++, 2);
	m_cmbMediaType.InsertString(nIndex, _T("视频或音视频"));
	m_cmbMediaType.SetItemData(nIndex++, 3);
	m_cmbMediaType.SetCurSel(0);

	// 0：所有码流，1：主码流，2：子码流
	nIndex = 0;
	m_cmbCodeStreamType.InsertString(nIndex, _T("所有码流"));
	m_cmbCodeStreamType.SetItemData(nIndex++, 0);
	m_cmbCodeStreamType.InsertString(nIndex, _T("主码流"));
	m_cmbCodeStreamType.SetItemData(nIndex++, 1);
	m_cmbCodeStreamType.InsertString(nIndex, _T("子码流"));
	m_cmbCodeStreamType.SetItemData(nIndex++, 2);
	m_cmbCodeStreamType.SetCurSel(0);


	// 0：所有存储器，1：主存储器，2：灾备存储器
	nIndex = 0;
	m_cmbStorageType.InsertString(nIndex, _T("所有存储器"));
	m_cmbStorageType.SetItemData(nIndex++, 0);
	m_cmbStorageType.InsertString(nIndex, _T("主存储器"));
	m_cmbStorageType.SetItemData(nIndex++, 1);
	m_cmbStorageType.InsertString(nIndex, _T("灾备存储器"));
	m_cmbStorageType.SetItemData(nIndex++, 2);
	m_cmbStorageType.SetCurSel(0);


	CheckDlgButton(IDC_CHK_ALARM_808_ALL, TRUE);
	OnBnClickedChkAlarm808All();

	CheckDlgButton(IDC_CHK_ALARM_1078_ALL, TRUE);
	OnBnClickedChkAlarm1078All();

	CString strAlarmTip;

	for (int i=0; i<32; i++)
	{
		CString strAlarm = theApp.Get808AlarmBitString(i);

		if (!strAlarm.IsEmpty())
		{
			strTemp.Format(_T("808 Check%d:%s\r\n"), i+1, strAlarm);
			strAlarmTip += strTemp;
		}
	}
	strAlarmTip += _T("\r\n\r\n\r\n\r\n");

	for (int i=0; i<32; i++)
	{
		CString strAlarm = theApp.Get1078VideoAlarmBitString(i);

		if (!strAlarm.IsEmpty())
		{
			strTemp.Format(_T("1078 Check%d:%s\r\n"), i+1, strAlarm);
			strAlarmTip += strTemp;
		}
	}

	SetDlgItemText(IDC_ED_ALARM_TIP, strAlarmTip);


	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

void CDlgRecSearch1078::OnBnClickedBtnRecSearch1078()
{

}

void CDlgRecSearch1078::OnBnClickedChkAlarm808All()
{
	static_assert((IDC_CHK_ALARM_808_32 - IDC_CHK_ALARM_808_1) == 31, "CDlgRecSearch1078::OnBnClickedBtnRecSearch1078()");
	BOOL bCheck = IsDlgButtonChecked(IDC_CHK_ALARM_808_ALL);
	for (int nID = IDC_CHK_ALARM_808_1; nID <= IDC_CHK_ALARM_808_32; nID++)
	{
		CheckDlgButton(nID, bCheck);
	}
}

void CDlgRecSearch1078::OnBnClickedChkAlarm1078All()
{
	static_assert((IDC_CHK_ALARM_1078_32 - IDC_CHK_ALARM_1078_1) == 31, "CDlgRecSearch1078::OnBnClickedChkAlarm808All()");
	BOOL bCheck = IsDlgButtonChecked(IDC_CHK_ALARM_1078_ALL);
	for (int nID = IDC_CHK_ALARM_1078_1; nID <= IDC_CHK_ALARM_1078_32; nID++)
	{
		CheckDlgButton(nID, bCheck);
	}
}
