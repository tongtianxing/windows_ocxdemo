#pragma once

// 计算机生成了由 Microsoft Visual C++ 创建的 IDispatch 包装类

// 注意: 不要修改此文件的内容。如果此类由
//  Microsoft Visual C++ 重新生成，您的修改将被覆盖。

/////////////////////////////////////////////////////////////////////////////
// CCMSV6OCX 包装类

class CCMSV6OCX : public CWnd
{
protected:
	DECLARE_DYNCREATE(CCMSV6OCX)
public:
	CLSID const& GetClsid()
	{
		static CLSID const clsid
			= { 0xDAB63197, 0x3FF9, 0x4236, { 0x92, 0x4C, 0xF8, 0x64, 0x10, 0x94, 0xDD, 0xFD } };
		return clsid;
	}
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle,
						const RECT& rect, CWnd* pParentWnd, UINT nID, 
						CCreateContext* pContext = NULL)
	{ 
		return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID); 
	}

    BOOL Create(LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, 
				UINT nID, CFile* pPersist = NULL, BOOL bStorage = FALSE,
				BSTR bstrLicKey = NULL)
	{ 
		return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID,
		pPersist, bStorage, bstrLicKey); 
	}

// 特性
public:


// 操作
public:

// _DCMSV6OCX

// Functions
//

	long StartVideo(LPCTSTR szDevIDNO, long nChannel, long nWindow)
	{
		long result;
		static BYTE parms[] = VTS_BSTR VTS_I4 VTS_I4 ;
		InvokeHelper(0x13, DISPATCH_METHOD, VT_I4, (void*)&result, parms, szDevIDNO, nChannel, nWindow);
		return result;
	}
	long StopVideo(long nWindow)
	{
		long result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x14, DISPATCH_METHOD, VT_I4, (void*)&result, parms, nWindow);
		return result;
	}
	void FullScreen()
	{
		InvokeHelper(0x15, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	long OpenSound(long nWindow)
	{
		long result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x16, DISPATCH_METHOD, VT_I4, (void*)&result, parms, nWindow);
		return result;
	}
	void CloseSound()
	{
		InvokeHelper(0x17, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	long CapturePicture(long nWindow)
	{
		long result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x18, DISPATCH_METHOD, VT_I4, (void*)&result, parms, nWindow);
		return result;
	}
	long StartTalkBack(LPCTSTR szDevIDNO)
	{
		long result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x19, DISPATCH_METHOD, VT_I4, (void*)&result, parms, szDevIDNO);
		return result;
	}
	void StopTalkBack()
	{
		InvokeHelper(0x1a, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	long StartMonitor(LPCTSTR szDevIDNO, long nChannel)
	{
		long result;
		static BYTE parms[] = VTS_BSTR VTS_I4 ;
		InvokeHelper(0x1b, DISPATCH_METHOD, VT_I4, (void*)&result, parms, szDevIDNO, nChannel);
		return result;
	}
	void CloseAllSound()
	{
		InvokeHelper(0x1c, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	void StopMonitor()
	{
		InvokeHelper(0x1d, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	long StartRecord(LPCTSTR szDevIDNO, long nChannel)
	{
		long result;
		static BYTE parms[] = VTS_BSTR VTS_I4 ;
		InvokeHelper(0x1e, DISPATCH_METHOD, VT_I4, (void*)&result, parms, szDevIDNO, nChannel);
		return result;
	}
	long StopRecord(LPCTSTR szDevINDO, long nChannel)
	{
		long result;
		static BYTE parms[] = VTS_BSTR VTS_I4 ;
		InvokeHelper(0x1f, DISPATCH_METHOD, VT_I4, (void*)&result, parms, szDevINDO, nChannel);
		return result;
	}
	long CaptureAllWindowPicture()
	{
		long result;
		InvokeHelper(0x20, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	void ExitFullScreen()
	{
		InvokeHelper(0x21, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	BOOL IsFullScreen()
	{
		BOOL result;
		InvokeHelper(0x22, DISPATCH_METHOD, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	long SetViewTitle(long nWindow, LPCTSTR strTitle)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_BSTR ;
		InvokeHelper(0x23, DISPATCH_METHOD, VT_I4, (void*)&result, parms, nWindow, strTitle);
		return result;
	}
	long PtzControl(long nWindow, long nCommand, long nSpeed, long nParam)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_I4 ;
		InvokeHelper(0x24, DISPATCH_METHOD, VT_I4, (void*)&result, parms, nWindow, nCommand, nSpeed, nParam);
		return result;
	}
	long StartRecSearch(LPCTSTR strDevIDNO, long nChannel, long nRecType, DATE nStartTime, DATE nEndTime, long nLocation, long nFileType)
	{
		long result;
		static BYTE parms[] = VTS_BSTR VTS_I4 VTS_I4 VTS_DATE VTS_DATE VTS_I4 VTS_I4 ;
		InvokeHelper(0x25, DISPATCH_METHOD, VT_I4, (void*)&result, parms, strDevIDNO, nChannel, nRecType, nStartTime, nEndTime, nLocation, nFileType);
		return result;
	}
	void StopRecSearch()
	{
		InvokeHelper(0x26, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	long StartPlaybackRec(LPCTSTR strFile, DATE nFileStartTime, DATE nFileEndTime, LPCTSTR strDevIDNO, long nChannel, long nFileLen, long nFileType, long nLocation, long nSvrID, DATE nPlayStartTime, DATE nPlayEndTime, BOOL bPlayOnlyIFrame)
	{
		long result;
		static BYTE parms[] = VTS_BSTR VTS_DATE VTS_DATE VTS_BSTR VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_DATE VTS_DATE VTS_BOOL ;
		InvokeHelper(0x27, DISPATCH_METHOD, VT_I4, (void*)&result, parms, strFile, nFileStartTime, nFileEndTime, strDevIDNO, nChannel, nFileLen, nFileType, nLocation, nSvrID, nPlayStartTime, nPlayEndTime, bPlayOnlyIFrame);
		return result;
	}
	long StartDownFile(LPCTSTR strDevIDNO, long nChannel, LPCTSTR strFile, long nFileLen, DATE nFileStartTime, DATE nFileEndTime, long nLocation, long nSvrID, long nFileType, long nFileAttr, LPCTSTR strFilePath)
	{
		long result;
		static BYTE parms[] = VTS_BSTR VTS_I4 VTS_BSTR VTS_I4 VTS_DATE VTS_DATE VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_BSTR ;
		InvokeHelper(0x28, DISPATCH_METHOD, VT_I4, (void*)&result, parms, strDevIDNO, nChannel, strFile, nFileLen, nFileStartTime, nFileEndTime, nLocation, nSvrID, nFileType, nFileAttr, strFilePath);
		return result;
	}
	long StopDownFile()
	{
		long result;
		InvokeHelper(0x29, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	long StartSubscribeGps(LPCTSTR szDevIDNO)
	{
		long result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x2a, DISPATCH_METHOD, VT_I4, (void*)&result, parms, szDevIDNO);
		return result;
	}
	long StopSubscribeGps()
	{
		long result;
		InvokeHelper(0x2b, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	long CheckOnline(LPCTSTR szDevIDNO)
	{
		long result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x2c, DISPATCH_METHOD, VT_I4, (void*)&result, parms, szDevIDNO);
		return result;
	}
	long SnapshotDev(LPCTSTR szDevIDNO, long nChannel)
	{
		long result;
		static BYTE parms[] = VTS_BSTR VTS_I4 ;
		InvokeHelper(0x2d, DISPATCH_METHOD, VT_I4, (void*)&result, parms, szDevIDNO, nChannel);
		return result;
	}
	long GetDevNetFlowStatistics(LPCTSTR szDevIDNO)
	{
		long result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x2e, DISPATCH_METHOD, VT_I4, (void*)&result, parms, szDevIDNO);
		return result;
	}
	long SetDevNetFlowStatistics(LPCTSTR szDevIDNO, float fFlowUsedToday, float fFlowUsedMonth, long nIsOpenFlowCount, long nIsOpenDayFlowRemind, long nIsOpenMonthFlwRemind, float fDayLimit, float fMonthLimit, long nDayRemind, long nMonthRemind, long nMonthTotleDay)
	{
		long result;
		static BYTE parms[] = VTS_BSTR VTS_R4 VTS_R4 VTS_I4 VTS_I4 VTS_I4 VTS_R4 VTS_R4 VTS_I4 VTS_I4 VTS_I4 ;
		InvokeHelper(0x2f, DISPATCH_METHOD, VT_I4, (void*)&result, parms, szDevIDNO, fFlowUsedToday, fFlowUsedMonth, nIsOpenFlowCount, nIsOpenDayFlowRemind, nIsOpenMonthFlwRemind, fDayLimit, fMonthLimit, nDayRemind, nMonthRemind, nMonthTotleDay);
		return result;
	}
	long StartSubscribeAlarm(LPCTSTR szDevIDNO)
	{
		long result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x30, DISPATCH_METHOD, VT_I4, (void*)&result, parms, szDevIDNO);
		return result;
	}
	long StopSubscribeAlarm()
	{
		long result;
		InvokeHelper(0x31, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	long StartVoiceBroadcast(LPCTSTR lpDevIDNO)
	{
		long result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x32, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lpDevIDNO);
		return result;
	}
	long StopVoiceBroadcast()
	{
		long result;
		InvokeHelper(0x33, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	void ShowWindowIndex(BOOL bShow)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x34, DISPATCH_METHOD, VT_EMPTY, NULL, parms, bShow);
	}
	long StartDownFileEx(LPCTSTR strFile, DATE nFileStartTime, DATE nFileEndTime, LPCTSTR strDevIDNO, long nChannel, long nFileLen, long nFileType, long nLocation, long nSvrID, DATE nDownStartTime, DATE nDownEndTime, BOOL bOnlyDownIFrame, LPCTSTR strSaveFile, BOOL bResumeDown)
	{
		long result;
		static BYTE parms[] = VTS_BSTR VTS_DATE VTS_DATE VTS_BSTR VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_DATE VTS_DATE VTS_BOOL VTS_BSTR VTS_BOOL ;
		InvokeHelper(0x35, DISPATCH_METHOD, VT_I4, (void*)&result, parms, strFile, nFileStartTime, nFileEndTime, strDevIDNO, nChannel, nFileLen, nFileType, nLocation, nSvrID, nDownStartTime, nDownEndTime, bOnlyDownIFrame, strSaveFile, bResumeDown);
		return result;
	}
	long StopDownFileEx()
	{
		long result;
		InvokeHelper(0x36, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	BOOL GetDevIDNOForPlateNum(LPCTSTR lpPlateNum)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x37, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, lpPlateNum);
		return result;
	}
	long TransparentConfig(LPCTSTR szDevIDNO, long nType, LPCTSTR szBuffer, long nLen)
	{
		long result;
		static BYTE parms[] = VTS_BSTR VTS_I4 VTS_BSTR VTS_I4 ;
		InvokeHelper(0x38, DISPATCH_METHOD, VT_I4, (void*)&result, parms, szDevIDNO, nType, szBuffer, nLen);
		return result;
	}
	long SetDevInfo(LPCTSTR szDevIDNO, LPCTSTR szDevName)
	{
		long result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR ;
		InvokeHelper(0x39, DISPATCH_METHOD, VT_I4, (void*)&result, parms, szDevIDNO, szDevName);
		return result;
	}
	void AboutBox()
	{
		InvokeHelper(DISPID_ABOUTBOX, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	long StopPlaybackRec()
	{
		long result;
		InvokeHelper(0x3a, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	long PausePlaybackRec(long nPause)
	{
		long result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x3b, DISPATCH_METHOD, VT_I4, (void*)&result, parms, nPause);
		return result;
	}
	long StartPlayRecFile(LPCTSTR strDevIDNO, long nChannel, LPCTSTR strFile, LPCTSTR strExtData, BOOL bPlayOnlyIFrame)
	{
		long result;
		static BYTE parms[] = VTS_BSTR VTS_I4 VTS_BSTR VTS_BSTR VTS_BOOL ;
		InvokeHelper(0x3d, DISPATCH_METHOD, VT_I4, (void*)&result, parms, strDevIDNO, nChannel, strFile, strExtData, bPlayOnlyIFrame);
		return result;
	}
	long StartDownRecFile(LPCTSTR strDevIDNO, long nChannel, LPCTSTR strFile, LPCTSTR strExtData, LPCTSTR strSaveFile, BOOL bResumeDown)
	{
		long result;
		static BYTE parms[] = VTS_BSTR VTS_I4 VTS_BSTR VTS_BSTR VTS_BSTR VTS_BOOL ;
		InvokeHelper(0x3e, DISPATCH_METHOD, VT_I4, (void*)&result, parms, strDevIDNO, nChannel, strFile, strExtData, strSaveFile, bResumeDown);
		return result;
	}
	long StartDownRecFileByPlay(LPCTSTR strDevIDNO, long nChannel, LPCTSTR strFile, LPCTSTR strExtData, BOOL bOnlyDownIFrame, LPCTSTR strSaveFile, BOOL bResumeDown)
	{
		long result;
		static BYTE parms[] = VTS_BSTR VTS_I4 VTS_BSTR VTS_BSTR VTS_BOOL VTS_BSTR VTS_BOOL ;
		InvokeHelper(0x3f, DISPATCH_METHOD, VT_I4, (void*)&result, parms, strDevIDNO, nChannel, strFile, strExtData, bOnlyDownIFrame, strSaveFile, bResumeDown);
		return result;
	}
	CString MakeRecNameEx(LPCTSTR szPlate, LPCTSTR szAlarmString, DATE BegDate, DATE EndDate, long nChn, long nRecType, long nFileFormat)
	{
		CString result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR VTS_DATE VTS_DATE VTS_I4 VTS_I4 VTS_I4 ;
		InvokeHelper(0x40, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, szPlate, szAlarmString, BegDate, EndDate, nChn, nRecType, nFileFormat);
		return result;
	}
	long StopBetchDownFile(LPCTSTR strFilePath)
	{
		long result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x41, DISPATCH_METHOD, VT_I4, (void*)&result, parms, strFilePath);
		return result;
	}
	long StartVideoEx(LPCTSTR szDevIDNO, long nChannel, long nWindow, long nStreamType)
	{
		long result;
		static BYTE parms[] = VTS_BSTR VTS_I4 VTS_I4 VTS_I4 ;
		InvokeHelper(0x42, DISPATCH_METHOD, VT_I4, (void*)&result, parms, szDevIDNO, nChannel, nWindow, nStreamType);
		return result;
	}

// Properties
//

CString GetServerIP()
{
	CString result;
	GetProperty(0x1, VT_BSTR, (void*)&result);
	return result;
}
void SetServerIP(CString propVal)
{
	SetProperty(0x1, VT_BSTR, propVal);
}
long GetServerPort()
{
	long result;
	GetProperty(0x2, VT_I4, (void*)&result);
	return result;
}
void SetServerPort(long propVal)
{
	SetProperty(0x2, VT_I4, propVal);
}
long GetPaneType()
{
	long result;
	GetProperty(0x3, VT_I4, (void*)&result);
	return result;
}
void SetPaneType(long propVal)
{
	SetProperty(0x3, VT_I4, propVal);
}
long GetLayout()
{
	long result;
	GetProperty(0x4, VT_I4, (void*)&result);
	return result;
}
void SetLayout(long propVal)
{
	SetProperty(0x4, VT_I4, propVal);
}
CString GetCaptureSavePath()
{
	CString result;
	GetProperty(0x5, VT_BSTR, (void*)&result);
	return result;
}
void SetCaptureSavePath(CString propVal)
{
	SetProperty(0x5, VT_BSTR, propVal);
}
long GetAutoCloseVideoTime()
{
	long result;
	GetProperty(0x6, VT_I4, (void*)&result);
	return result;
}
void SetAutoCloseVideoTime(long propVal)
{
	SetProperty(0x6, VT_I4, propVal);
}
long GetRecordPackTime()
{
	long result;
	GetProperty(0x7, VT_I4, (void*)&result);
	return result;
}
void SetRecordPackTime(long propVal)
{
	SetProperty(0x7, VT_I4, propVal);
}
long GetDiskNoSpaceOperateType()
{
	long result;
	GetProperty(0x8, VT_I4, (void*)&result);
	return result;
}
void SetDiskNoSpaceOperateType(long propVal)
{
	SetProperty(0x8, VT_I4, propVal);
}
long GetDiskReservedSpace()
{
	long result;
	GetProperty(0x9, VT_I4, (void*)&result);
	return result;
}
void SetDiskReservedSpace(long propVal)
{
	SetProperty(0x9, VT_I4, propVal);
}
unsigned long GetColorBK()
{
	unsigned long result;
	GetProperty(0xa, VT_UI4, (void*)&result);
	return result;
}
void SetColorBK(unsigned long propVal)
{
	SetProperty(0xa, VT_UI4, propVal);
}
unsigned long GetColorVideoBK()
{
	unsigned long result;
	GetProperty(0xb, VT_UI4, (void*)&result);
	return result;
}
void SetColorVideoBK(unsigned long propVal)
{
	SetProperty(0xb, VT_UI4, propVal);
}
unsigned long GetColorVideoTitleBK()
{
	unsigned long result;
	GetProperty(0xc, VT_UI4, (void*)&result);
	return result;
}
void SetColorVideoTitleBK(unsigned long propVal)
{
	SetProperty(0xc, VT_UI4, propVal);
}
unsigned long GetColorVideoBKActive()
{
	unsigned long result;
	GetProperty(0xd, VT_UI4, (void*)&result);
	return result;
}
void SetColorVideoBKActive(unsigned long propVal)
{
	SetProperty(0xd, VT_UI4, propVal);
}
CString GetstrVideoBKPicturePath()
{
	CString result;
	GetProperty(0xe, VT_BSTR, (void*)&result);
	return result;
}
void SetstrVideoBKPicturePath(CString propVal)
{
	SetProperty(0xe, VT_BSTR, propVal);
}
long GetVideoControl()
{
	long result;
	GetProperty(0xf, VT_I4, (void*)&result);
	return result;
}
void SetVideoControl(long propVal)
{
	SetProperty(0xf, VT_I4, propVal);
}
long GetShowWnd()
{
	long result;
	GetProperty(0x10, VT_I4, (void*)&result);
	return result;
}
void SetShowWnd(long propVal)
{
	SetProperty(0x10, VT_I4, propVal);
}
long GetnActiveWndIndex()
{
	long result;
	GetProperty(0x11, VT_I4, (void*)&result);
	return result;
}
void SetnActiveWndIndex(long propVal)
{
	SetProperty(0x11, VT_I4, propVal);
}
long GetWndArrange()
{
	long result;
	GetProperty(0x12, VT_I4, (void*)&result);
	return result;
}
void SetWndArrange(long propVal)
{
	SetProperty(0x12, VT_I4, propVal);
}
long GetRecFileFormat()
{
	long result;
	GetProperty(0x3c, VT_I4, (void*)&result);
	return result;
}
void SetRecFileFormat(long propVal)
{
	SetProperty(0x3c, VT_I4, propVal);
}
long GetRealAVUsePrivate()
{
	long result;
	GetProperty(0x43, VT_I4, (void*)&result);
	return result;
}
void SetRealAVUsePrivate(long propVal)
{
	SetProperty(0x43, VT_I4, propVal);
}
CString GetUserSession()
{
	CString result;
	GetProperty(0x44, VT_BSTR, (void*)&result);
	return result;
}
void SetUserSession(CString propVal)
{
	SetProperty(0x44, VT_BSTR, propVal);
}


};
