#ifndef _GPS_DATA_DEF_H_
#define _GPS_DATA_DEF_H_

#define GPS_DEV_ID_LEN						32
//#define GPS_MAX_DEV_CHN_NUM					16
#define GPS_MAX_DEV_CHN_NUM					12		//IO数目增加为12个，通道数目由16变为12个
#define GPS_MAX_DEV_IO_NUM_OLD				8
#define GPS_MAX_DEV_IO_NUM_NEW				12
#define GPS_MAX_TEMP_SENSOR_NUM				4

#define GPSSERVER_TYPE_LOGIN				1
#define GPSSERVER_TYPE_GATEWAY				2
#define GPSSERVER_TYPE_MEDIA				3
#define GPSSERVER_TYPE_USRMGR				4
#define GPSSERVER_TYPE_STORAGE				5
#define GPSSERVER_TYPE_WEB					6
#define GPSSERVER_TYPE_DOWN					7		//下载服务器
#define GPSSERVER_TYPE_MYSQL				8		//mysql服务 hw 2013/12/27
#define GPSSERVER_TYPE_LICENSE				9		//授权服务器
#define GPSSERVER_TYPE_MANAGER				99		//管理服务器

#define GPS_FILE_LOCATION_DEVICE			1		//设备
#define GPS_FILE_LOCATION_STOSVR			2		//存储服务器
#define GPS_FILE_LOCATION_LOCAL				3		//客户端本地
#define GPS_FILE_LOCATION_DOWNSVR			4		//下载服务器

#define GPS_FILE_ATTRIBUTE_JPEG				1
#define GPS_FILE_ATTRIBUTE_RECORD			2
///#define GPS_FILE_ATTRIBUTE_ALL			3		//搜索时使用表示搜索所有录像文件
#define GPS_FILE_ATTRIBUTE_LOG				4			
#define GPS_FILE_ATTRIBUTE_AUDIO			5

#define GPS_FILE_SOURCE_PLAN				1		//存储计划生成
#define GPS_FILE_SOURCE_UPLOAD				2		//设备主动上传的

#define GPS_LOGIN_SUC						0		//Login direction server success
#define GPS_LOGIN_FAILED					1		//Login direction server failed
#define	GPS_LOGIN_DISCNT					2		//Login direction server disconnect
#define	GPS_LOGIN_NAME_ERR					3		//Login direction server user name error
#define	GPS_LOGIN_PWD_ERR					4		//Login direction server user pwd error
#define	GPS_LOGIN_FULL_ERR					5		//Login direction server （用户服务器用户满）
#define	GPS_LOGIN_VER_ERR					6		//Login direction server version error
#define	GPS_LOGIN_USR_CHANGE				7		//Login direction server （用户在其它位置进行登录）
#define GPS_LOGIN_USR_DEL					8		//Login direction server （用户被删除）
#define	GPS_LOGIN_EXPIRED					9		//Login direction server use expired
#define	GPS_LOGIN_SERVER_EMPTY				10		//Login direction server （或者不存在用户服务器信息）
#define GPS_LOGIN_PRIVILEGE_CHANGE			11		//用户权限发送变化
#define	GPS_LOGIN_SVR_CONFIG_CHANGE			12		//服务器配置信息发送变化

#define GPS_LOGIN_TYPE_GPS_CLIENT			1

#define GPS_DEV_DOWN_DEV					0
#define GPS_DEV_DOWN_GROUP					1
#define GPS_DEV_DOWN_FAILED					2
#define GPS_DEV_DOWN_SUC					3
#define GPS_DEV_DOWN_RELATION				4
#define GPS_DEV_DOWN_DATA					5

#define GPS_DOWN_CONFIG_DATA				1
#define GPS_DOWN_CONFIG_FAILED				2
#define GPS_DOWN_CONFIG_SUC					3
#define GPS_DOWN_MAP_MARKER					4		//地图标记信息
#define GPS_DOWN_MAP_LINE					5		//地图线路信息
#define GPS_DOWM_MAP_TAB_INFO				6		//地图标记属性

//hw 
#define GPS_VERSION_6_14_X_X				0		//6.14
#define GPS_VERSION_6_15_X_X				1		//6.15.X.X版本,修改了传输UFT8格式数据
#define GPS_VERSION_CUR		GPS_VERSION_6_15_X_X	//当前版本

#define GPS_VERSION_EX_X_X					0		//6.18.0.2之前版本版本
#define GPS_VERSION_EX_6_18_0_2				1		//6.18.0.2版本,修改了TTS传输1024长度
#define GPS_VERSION_EX_7_0_0_12				2		//7.0.0.12版本,地图从服务器加载 
#define GPS_VERSION_EX_7_6_0_4				3		//7.6.0.4版本,客户端识别服务器版本(修改获取地图标签为UTF8)
#define GPS_VERSION_EX_7_6_0_5				5		//7.6.0.5版本,客户端识别服务器版本(修改发送TTS为UTF8)
#define GPS_VERSION_EX_CUR		GPS_VERSION_EX_7_6_0_5	//当前版本

//服务器版本类型定义 zjt 2014-01-05
#define GPS_SVR_VERSION_DEFUALT				0	//CMS服务器
#define GPS_SVR_VERSION_DJWL				1	//CMS服务器(DJWL)
#define GPS_SVR_VERSION_JT808				2	//JT808服务器


//hw 2013/1/19
//连接服务器的网络类型 0-使用局域网IP， 1-使用广域网IP
#define GPS_NET_TYPE_LAN		0
#define GPS_NET_TYPE_WAN		1

//客户端下载信息位定义
//0位服务器配置
#define GPS_DOWN_CONFIG_SVR_CONFIG			0
//1位用户权限
#define GPS_DOWN_CONFIG_PRIVILEG			1
//2位地图配置
#define GPS_DOWN_CONFIG_MAP_CONFIG			2
//3位用户信息
#define GPS_DOWN_CONFIG_USER_INFO			3
//4位用户类型
#define	GPS_DWON_CONFIG_USER_TYPE			4
//5位客户端功能配置
#define	GPS_DWON_CONFIG_CLIENT_FUNCTION		5

#define GPS_DOWNLOAD_MSG_FAILED				1
#define GPS_DOWNLOAD_MSG_BEGIN				2
#define GPS_DOWNLOAD_MSG_FINISHED			3
#define GPS_DOWNLOAD_MSG_PROCESS			4

#define GPS_UPLOAD_MSG_FAILED				1
#define GPS_UPLOAD_MSG_FINISHED				2
#define GPS_UPLOAD_MSG_PROCESS				3

//设备模块位定义
#define GPS_DEV_MOUDLE_VIDEO			0	//视频
#define GPS_DEV_MODULE_OIL_CONTROL		1	//油路控制
#define GPS_DEV_MODULE_POWER_CONTROL	2	//电路控制
#define GPS_DEV_MODULE_TTS				3	//tts语音
#define GPS_DEV_MODULE_BK_TALK			4	//数字对讲
#define GPS_DEV_MOUDLE_SNAPSHOT			5	//抓拍
#define GPS_DEV_MOUDLE_MONITOR			6	//监听
#define GPS_DEV_MOUDLE_OIL_SEN			7	//油量传感器
#define GPS_DEV_MOUDLE_TALK				8	//对讲
#define GPS_DEV_MOUDLE_ODB				9	//ODB外设
#define GPS_DEV_MOUDLE_COUNT_PEOPLE		10	//人数统计模块

//老服务器油量模块定义
#define GPS_DEV_MOUDLE_OIL_SEN_V6		0	//V6版本油量模块

//浏览器类型
#define GPS_BROWSER_TYPE_IE				0
#define GPS_BROWSER_TYPE_WEBKIT			1




const int GPS_CTRL_TYPE_OIL_STOP			= 1;	//断开油路
const int GPS_CTRL_TYPE_OIL_RESTORE			= 2;	//恢复油路
const int GPS_CTRL_TYPE_ELEC_STOP			= 3;	//断开电路
const int GPS_CTRL_TYPE_ELEC_RESTORE		= 4;	//恢复电路
const int GPS_CTRL_TYPE_REBOOT				= 5;	//重启机器 
const int GPS_CTRL_TYPE_RESET				= 6;	//设备复位
const int GPS_CTRL_TYPE_MOD_DEV_NUM_OR_GET_STATUS = 7;//修改设备号、获取设备状态
const int GPS_CTRL_TYPE_3G_REBOOT_IP       =8;     //IP,3G,重启

const int  GPS_CTRL_TYPE_SLEEP				= 7;	//休眠
const int  GPS_CTRL_TYPE_WAKE				= 8;	//唤醒
//录像的通道号0表示通道1，1表示通道2     98表示所有通道(TTX_CHANNEL_ALL)
const int  GPS_CTRL_TYPE_START_RECORD		= 9;	//开始录像	//高两字节为录像的通道号，低两字节为指令
const int  GPS_CTRL_TYPE_STOP_RECORD		= 10;	//停止录像	//高两字节为录像的通道号，低两字节为指令
const int  GPS_CTRL_TYPE_START_CRUISE		= 11;	//客户端开始对此通道进行轮询，高两字节为通道号，低两字节为指令
const int  GPS_CTRL_TYPE_STOP_CRUISE		= 12;	//客户端停止对此通道进行轮询，高两字节为通道号，低两字节为指令
const int  GPS_CTRL_TYPE_WRITE_LOG		= 13;	//启动记录日志功能	高两个字节大于0表示写日志，0表示不写日志
const int  GPS_CTRL_TYPE_FORMAT_HDD		= 14;	//格式化硬盘(高位表示硬盘号,硬盘号从0开始,低位表示命令号)
const int  GPS_CTRL_TYPE_MILEAGE_CLEARED 	= 15;	//里程清零	
const int  GPS_CTRL_TYPE_FLIP_HORIZONTAL 	= 16;	//水平翻转	//高两字节为通道号，低两字节为指令
const int  GPS_CTRL_TYPE_FLIP_VERTICAL 		= 17;	//垂直翻转	//高两字节为通道号，低两字节为指令
const int  GPS_CTRL_TYPE_CLEAR_ALARM		= 18;	//清除报警

const int GPS_MNGCMD_SEND_SMS				= 1;    //发送短消息
const int GPS_MNGCMD_SEND_TEXT				= 2;    //发送TTS，设备上进行播放发送的文件
const int GPS_MNGCMD_SEND_PTZ				= 3;    //PTZ控制指令
const int GPS_MNGCMD_SEND_CTRL				= 4;    //发送控制指令，如断油、断电等
const int GPS_MNGCMD_READ_STATUS			= 5;    //获取车辆状态
const int GPS_MNGCMD_CHANGE_USR_PWD			= 6;    //修改用户密码
const int GPS_MNGCMD_SET_GPS_INTERVAL		= 7;    //设置GPS间隔时间
const int GPS_MNGCMD_CHECK_CTRL_USR			= 8;	//发送控制命令前校验用户
const int GPS_MNGCMD_READ_MOTION_PARAM		= 9;	//获取移动侦测参数
const int GPS_MNGCMD_SET_MOTION_PARAM		= 10;   //配置移动侦测参数
const int GPS_MNGCMD_READ_NETFLOW_STATISTICS	= 11;   //获取流量信息
const int GPS_MNGCMD_SET_NETFLOW_PARAM			= 12;	//配置流量参数
const int GPS_MNGCMD_CLEAR_NETFLOW_STATISTICS	= 13;   //清空流量统计
const int GPS_MNGCMD_ADJUST_NETFLOW_STATISTICS	= 14;	//调整流量统计
const int GPS_MNGCMD_SET_USR_ALARMSHIELD	= 15;		//配置报警屏蔽
const int GPS_MNGCMD_ADD_MAP_MARKER			= 16;		//添加地图标记信息
const int GPS_MNGCMD_DEL_MAP_MARKER			= 17;		//删除地图标记信息
const int GPS_MNGCMD_SEND_DISPATCH_COMMAND	= 18;		//发送调度指令信息
const int GPS_MNGCMD_ADD_MAP_MARKERINFO		= 19;		//添加地图标记属性
const int GPS_MNGCMD_SET_USER_MAP_CONFIG	= 20;		//设置用户地图配置
const int GPS_MNGCMD_TRANSPARENT_DATA		= 24;		//透传数据
const int GPS_MNGCMD_TRANSPARENT_CONFIG		= 25;		//参数透传功能
const int GPS_MNGCMD_FREE_PRESET_GET		= 26;		//获取空闲预置位
const int GPS_MNGCMD_SET_VIDEO_COLOR		= 27;		//设置颜色
const int GPS_MNGCMD_GET_VIDEO_COLOR		= 28;		//获取颜色
const int GPS_MNGCMD_SET_DEV_FIX_GPS		= 29;		//设置设备的GPS位置
const int GPS_MNGCMD_SET_DEV_OIL_RESISTANCE	= 30;		//设置设备的油量刻度值
const int GPS_MNGCMD_SET_DEV_HANDLE_ALARM   = 31;		//设备报警处理
const int GPS_MNGCMD_ACK_809_PLATFORM		= 32;		//809查岗信息应答
const int GPS_MNGCMD_JT809_BUSINESS_PLATFORM	= 33;	//809相关业务

// const int GPS_MNGCMD_SET_VIDEO_CONFIG		= 21;		//设置设备视频参数
// const int GPS_MNGCMD_SET_AUDIO_CONFIG		= 22;		//设置设备音频参数
// const int GPS_MNGCMD_SET_PTZ_CONFIG			= 23;		//设置设备云台参数
// const int GPS_MNGCMD_GET_VIDEO_CONFIG		= 24;		//获取设备视频参数
// const int GPS_MNGCMD_GET_AUDIO_CONFIG		= 25;		//获取设备音频参数
// const int GPS_MNGCMD_GET_PTZ_CONFIG			= 26;		//获取设备云台参数

const int GPS_MAPMARKER_TYPE_POINT			= 1;		//点
const int GPS_MAPMARKER_TYPE_RECTANGLE		= 2;		//矩形
const int GPS_MAPMARKER_TYPE_POLYGON		= 3;		//多边形
const int GPS_MAPMARKER_TYPE_LINE			= 4;		//路线
const int GPS_MAPMARKER_TYPE_CIRCLE			= 10;		//圆

#include <tchar.h>
//存储路径定义，存储示例	"E:\\gStorage\\RECORD_FILE\\100001\\2012-07-03\\"
const TCHAR GPS_STORAGE_PATH[]				= _T("gStorage");
const TCHAR GPS_RECORD_PATH[]				= _T("RECORD_FILE");
const TCHAR GPS_JPEG_PATH[]					= _T("JPEG_FILE");

//0位-电子围栏
//1位-短信
//2位-自动下载
//3位-3g流量统计
//4位-手机客户端
//5位-点播
//6位-中心存储
//7位-人员定位
#define GPS_SVR_CONFIG_FENCE			0
#define GPS_SVR_CONFIG_SMS				1
#define GPS_SVR_CONFIG_AUTO_DONW		2
#define GPS_SVR_CONFIG_FLOW				3
#define GPS_SVR_CONFIG_PHONE			4
#define GPS_SVR_CONFIG_PLAYBACK			5
#define GPS_SVR_CONFIG_CENTER_STORAGE	6
#define GPS_SVR_CONFIG_TRACKER			7

//用户类型定义
#define GPS_USER_TYPE_SYS_ADMIN		-1	//管理员
#define GPS_USER_TYPE_COMMON		0	//普通用户
#define GPS_USER_TYPE_ADMIN			1	//企业管理员
#define GPS_USER_TYPE_TEST			2	//测试用户

//下载任务状态定义
#define GPS_DOWNTASK_STATUS_INIT		1		//处于未分配状态
#define GPS_DOWNTASK_STATUS_ALLOC		2		//已经分配，表示正在下载
#define GPS_DOWNTASK_STATUS_FAILED		3		//下载失败
#define GPS_DOWNTASK_STATUS_SUC			4		//下载成功

#define GPS_DOWNTASK_DOWNTYPE_FILE			1		//下载类型，文件下载
#define GPS_DOWNTASK_DOWNTYPE_RANGE			2		//分段下载

#pragma pack(4)

typedef struct _tagGPSDEVDevInfo
{
	int		nID;				//Device Index
	char	szName[32];			//Device Name
	char	szIDNO[32];			//Device id
	int		nType;				//0 :Encoder, 1 :Decoder
	unsigned char ucChanNum;			//Channel Number
	unsigned char ucIoInNum;			//IO 输入数目
	unsigned char ucTempSensorNum;	//温度传感器数目
	unsigned char ucIcon;	//车辆图标
	char	szChnName[GPS_MAX_DEV_CHN_NUM][16];		
	char	szIoInExtent[4][16];	//增加4个IO定义		2013-06-22，变为12个IO
	char	szIoInName[GPS_MAX_DEV_IO_NUM_OLD][16];
	char	szTempSensorName[GPS_MAX_TEMP_SENSOR_NUM][16];
	int		nGroup;				//Device Group Index
	int		nOnline;			//Device Online Status
	
	char	szSIMCard[16];		//SIM卡号
	char	szVehiColor[16];	//车辆颜色
	char	szVehiBand[16];		//车辆品牌
	char	szVehiType[16];		//车辆类型
	char	szVehiUse[16];		//车辆用途
	char	szVehiCampany[16];	//车辆公司
	char	szDriverName[16];	//司机名称
	char	szDriverTele[16];	//司机电话
	unsigned int uiModule;		//模块参数

	//hw2013/11/14
	char cPayEnable;			//是否启用缴费功能
	char cPayPeriod;			//合约期限（以月为单位）
	char cPayMonth;				//已付费
	char cPayDelayDay;			//宽限天数
	unsigned int uiPayBegin;	//合约开始日
	
	char    szReserve[52];		//保留字段	60
}GPSDEVDevInfo_S, *LPGPSDEVDevInfo_S;

//此结构体和GPSDEVDevInfo_S一致，去除保留的52字节
//hw2013/11/14
typedef struct _tagGPSDEVDevInfoEx
{
	int		nID;				//Device Index
	char	szName[32];			//Device Name
	char	szIDNO[32];			//Device id
	int		nType;				//0 :Encoder, 1 :Decoder
	unsigned char ucChanNum;			//Channel Number
	unsigned char ucIoInNum;			//IO 输入数目
	unsigned char ucTempSensorNum;	//温度传感器数目
	unsigned char ucIcon;	//车辆图标
	char	szChnName[GPS_MAX_DEV_CHN_NUM][16];		
	char	szIoInExtent[4][16];	//增加4个IO定义		2013-06-22，变为12个IO
	char	szIoInName[GPS_MAX_DEV_IO_NUM_OLD][16];
	char	szTempSensorName[GPS_MAX_TEMP_SENSOR_NUM][16];
	int		nGroup;				//Device Group Index
	int		nOnline;			//Device Online Status
	
	char	szSIMCard[16];		//SIM卡号
	char	szVehiColor[16];	//车辆颜色
	char	szVehiBand[16];		//车辆品牌
	char	szVehiType[16];		//车辆类型
	char	szVehiUse[16];		//车辆用途
	char	szVehiCampany[16];	//车辆公司
	char	szDriverName[16];	//司机名称
	char	szDriverTele[16];	//司机电话
	unsigned int uiModule;		//模块参数

	char cPayEnable;			//是否启用缴费功能
	char cPayPeriod;			//合约期限（以月为单位）
	char cPayMonth;				//已付费
	char cPayDelayDay;			//宽限天数
	unsigned int uiPayBegin;	//合约开始日

}GPSDEVDevInfoEx_S, *LPGPSDEVDevInfoEx_S;

typedef struct _tagGPSMDVRInfo
{
	unsigned char ucIoInNum;			//IO 输入数目
	unsigned char ucTempSensorNum;	//温度传感器数目
	unsigned char ucPlateColor;		//车牌颜色	808用到	afu 2014-04-28
	unsigned char szRes;
	char	szChnName[GPS_MAX_DEV_CHN_NUM][16];		
	char	szIoInExtent[4][16];
	char	szIoInName[GPS_MAX_DEV_IO_NUM_OLD][16];
	char	szTempSensorName[GPS_MAX_TEMP_SENSOR_NUM][16];
	
	char	szVehiColor[16];	//车辆颜色
	char	szVehiBand[16];		//车辆品牌
	char	szVehiType[16];		//车辆类型
	char	szVehiUse[16];		//车辆用途 
	char	szVehiCampany[16];	//车辆公司
	char	szDriverName[16];	//司机名称
	char	szDriverTele[16];	//司机电话
	char	szSerialNumber[16];	//设备序列号
	int		nDriverID;			//司机ID
	char    szReserve[40];		//保留字段//保留 44->40 zjt-2016/04/08
}GPSMDVRInfo_S, *LPGPSMDVRInfo_S;	//总大小624字节

typedef struct _tagGPSDVSInfo_S
{
	char	szChnName[16][16];								//16个通道名称
	char	szIoInName[GPS_MAX_DEV_IO_NUM_NEW][16];			//12个IO名称
	char	szTempSensorName[GPS_MAX_TEMP_SENSOR_NUM][16];	//温度传感器名称
	char	szContactName[16];			//联系人名称
	char	szContactTel[16];			//联系人电话
	unsigned char ucIoInNum;			//IO 输入数目
	unsigned char ucTempSensorNum;		//温度传感器数目
	char    szReserve[78];				//保留78字段
}GPSDVSInfo_S, *LPGPSDVSInfo_S;			//总大小624字节


typedef struct _tagGPSMobileDevInfo
{
	unsigned char nSex;			//性别
	char strIDCar[19];			//身份证18位
	char strUserNumber[16];		//编号15
	char strGroupName[64];		//所属队名
	char strAddress[256];		//住址
	int nUserPost;				//职位
	int	nEquip;					//一位表示一种装备
	char szReserve[64];			//保留64字段
}GPSMobileDevInfo_S, *LPGPSMobileDevInfo_S;	//总大小428

typedef struct _tagGPSDevInfo
{
	int nID;
	char szIDNO[32];				//Device id
	char szName[32];				//Device Name
	char szSIMCard[16];				//电话
	int nDevType;					//设备主类型		MDVR、MOBILE、
	int	nDevSubType;				//设备子类型		普通GPS，通道数目需要配置为0个
	int	nGroup;						//Device Group Index
	int nOnline;					//Device Online Status
	unsigned int uiModule;			//模块参数
	unsigned char ucChanNum;		//Channel Number
	unsigned char ucIcon;			//车辆图标
	char strRemark[94];				//备注		//原来为126
	char cProtocol;					//协议类型
	char cAudioCodec;				//音频解码器类型，请求对讲时，使用此参数
	char cDiskType;					//磁盘类型
	char cFactoryType;				//厂家定义设备类型	在WKP协议下使用	
	char cFactoryDevType;			//未用
	char cRes;						//保留一个字节
	unsigned char ucMapValid;		//设置的位置是否有效
	unsigned char ucMapType;		//地图类型
	int	nJingDu;					//经度	4字节 整数部分	9999999 = 9.999999 
	int nWeiDu;						//纬度	4字节 整数部分	9999999 = 9.999999
	char cPayEnable;				//是否启用缴费功能
	char cPayPeriod;				//合约期限（以月为单位）
	char cPayMonth;					//已付费
	char cPayDelayDay;				//宽限天数
	unsigned int uiPayBegin;		//合约开始日
	char cDevStatus;				//设备维修状态 0-正常 1-维修
	char strReserve[7];				//保留 8->7 hw2014/07/23 16->8 hw2013/11/12, 27->16 hw2013/8/1
	union
	{
		GPSMDVRInfo_S gDVRInfo;
		GPSMobileDevInfo_S gMobileDevInfo;
		GPSDVSInfo_S DVSInfo;
	};
}GPSDevInfo_S, *LPGPSDevInfo_S;

typedef struct _tagGPSChnName
{
	char szName[16];		// Channel Name
}GPSChnName_S, *LPGPSChnName_S;

typedef GPSChnName_S GPSIOName_S;

typedef struct _tagGPSDEVGroup
{
	int		nID;			//Group Index
	char	szName[32];		//Group Name
	int		nParent;		//Parent Group,  -1 : no Parent
	char	szRemarks[48];	//2016-2-23，从64位改为48位
	char	cLevel;			//级别,1为普通公司,2为车队 3-线路
	char	cReserve[15];	//备用字段
}GPSDEVGroup_S, *LPGPSDEVGroup_S;

//公司信息
typedef struct _tagCompanyInfo
{
	int  nID;
	char szName[32];
	int  nParent;	
	char cLevel;				//级别,1为普通公司,2为车队, 3-线路
	int  nStationCount[2];		//站点个数, 级别为3时才有效
}CompanyInfo_S, *LPCompanyInfo_S;

//司机信息
typedef struct _tagGPSDriverInfo
{
	int		nID;				// ID, 唯一
	char	szJobNum[32];		//工号, 唯一
	char	szName[32];			//名称
	int		nCompanyID;			//所属公司ID
	int		nSex;				//性别,1男2女
	char	IDNumber[32];		//身份证号
	char	szLicenseType[32];	//行驶证类型
	SYSTEMTIME tmValid;			//有效时间
	int nRemindDay;				//到期提醒天数
	char	cReserve[32];		//备用字段
}GPSDriverInfo_S, *LPGPSDriverInfo_S;

//车辆设备关联
typedef struct _tagGPSVehiDevRelation
{
	int		nID;					//ID
	char	szVehiIDNO[32];			//车牌号
	char	szDevIDNO[32];			//设备号
	char	szSIMCard[16];			//电话
	char	szChnAttr[40];			//通道属性 用,分隔  如:0,1 表示通道1,通道2
	char	szIOInAttr[40];			//IO输入属性
	char	szIOOutAttr[40];		//IO输出属性
	char	szTempAttr[40];			//温度传感器属性
	int		nMoudle;				//车辆外设属性, 每一位表示一种外设,第一位视频,第二位抓拍,第三位监听,第四位对讲
	int		nDevType;				//设备主类型		MDVR、MOBILE、
	int		nDevSubType;			//设备子类型		普通GPS，通道数目需要配置为0个
	char	cMainDevFlag;			//主设备标识,非0表示主设备
	char	cProtocol;				//协议类型
	char	cAudioCodec;			//音频解码器类型，请求对讲时，使用此参数
	char	cDiskType;				//磁盘类型
	char	cFactoryType;			//厂家定义设备类型	在WKP协议下使用	
	char	cFactoryDevType;		//未用
	unsigned char ucMapValid;		//设置的位置是否有效
	unsigned char ucMapType;		//地图类型
	int nOnline;					//Device Online Status
	int		nJingDu;				//经度	4字节 整数部分	9999999 = 9.999999 
	int		nWeiDu;					//纬度	4字节 整数部分	9999999 = 9.999999
	union
	{
		GPSMDVRInfo_S gDVRInfo;
		GPSMobileDevInfo_S gMobileDevInfo;
		GPSDVSInfo_S DVSInfo;
	};
	char	szRemarks[60];			//
}GPSVehiDevRelation_S, *LPGPSVehiDevRelation_S;

typedef struct _tagGPSAddrInfoEx
{
	char szLanIP[64];
	char szDeviceIP1[32];		//afu  2013-06-16	增加多个地址配置
	char szDeviceIP2[32];
	char szClientIP1[32];
	char szClientIP2[32];
	unsigned short usDevicePort;
	unsigned short usClientPort;
//	unsigned short usReserve[2];
	unsigned short usSvrVersion;	//服务器版本 说明:v6和之前的版本为0,v7为7,参考LOGIN_SERVER_VERSION_V7定义 hw2014-12-04 
	unsigned short usReserve;
}GPSAddrInfoEx_S;

typedef struct _tagGPSAddrInfo
{
	char szLanIP[64];
	char szDeviceIP1[32];		//afu  2013-06-16	增加多个地址配置
	char szDeviceIP2[32];
	char szClientIP1[32];
	char szClientIP2[32];
	unsigned short usDevicePort;
	unsigned short usClientPort;
	//	unsigned short usReserve[2];
	unsigned short usSvrVersion;	//服务器版本 说明:v6和之前的版本为0,v7为7,参考LOGIN_SERVER_VERSION_V7定义 hw2014-12-04 
	unsigned short usReserve;
}GPSAddrInfo_S;

typedef struct _tagGPSServerInfo
{
	int nID;
	char szIDNO[32];
	char szName[32];
	long nGroup;
	GPSAddrInfo_S	Addr;
}GPSServerInfo_S, *LPGPSServerInfo_S;

typedef struct _tagGPSServerInfoEx
{
	GPSServerInfo_S svrInfo;
	char szClientOtherPort[128];	//其它端口
	char szReserve[32];				//保留字段
}GPSServerInfoEx_S, *LPGPSServerInfoEx_S;

typedef struct _tagGPSServerAddr
{
	int nSvrID;
	GPSAddrInfo_S Addr;
}GPSServerAddr_S, *LPGPSServerAddr_S;

typedef struct _tagGPSMEDIAFile
{
	char	szFile[238]; 	/*带路径的文件名*/  // 2015-03-14  256变为252，增加uiAlarmType;1个文件可能有多个类型的报警
							// 2015-04-08  252变为244，增加nChnMask通道掩码
							// 2015-4-30	244变为240， 增加文件偏移量
							// 2015-8-17	240变为239， 增加录像标识
							// 2016-3-16	239变为238， 增加流标识
	char	bStream;		//是否为流式文件，当为流式文件时，客户端会使用回放的方式进行文件下载
	char	bRecording;		//是否正在录像的文件，0表示没有，1表示正在录像
	unsigned int nFileOffset;	//文件偏移量
	unsigned char ucYear;	// 14表示  14年
	unsigned char ucMonth;
	unsigned char ucDay;	
	unsigned char ucReserve;
	int nChnMask;			//通道掩码
	int nAlarmInfo;			//当文件为报警时有效
	unsigned int uiBegintime;
	unsigned int uiEndtime;
	char	szDevID[GPS_DEV_ID_LEN];			//设备ID
	int		nChn;
	unsigned int nFileLen;
	int		nFileType;
	int		nLocation;		//位置，设备上的录像文件，还是存储服务上的录像文件
	int		nSvrID;			//存储服务器ID，在为存储服务器上的文件时有效
}GPSMEDIAFile_S, *LPGPSMEDIAFile_S;

typedef struct _tagGPSDEVUpgradeFile
{
	char szVersion[32];
	int	nDevType;
	int nFileLength;
}GPSDEVUpgradeFile_S, *LPGPSDEVUpgradeFile_S;

typedef struct _tagGPSFile2SvrMD5
{
	char szFileName[128];
	int	nFileLength;
	char szMd5[64];
	int nFileType;
	char cReserve[32];
}GPSFile2SvrMD5_S, *LPGPSFile2SvrMD5_S;

//离线文件类型定义
#define GPS_OLF_TYPE_PICTURE	    1	//图片文件
#define GPS_OLF_TYPE_UPGRADE	    2	//升级文件
#define GPS_OLF_TYPE_DEV_CONF	    3	//设备参数配置
#define GPS_OLF_TYPE_WIFI_LOCATION	4	//wifi围栏开关

#define GPS_DEV_FILE_TASK_STATUS_CREATE		0	//未执行
#define GPS_DEV_FILE_TASK_STATUS_ING		1	//任务中
#define GPS_DEV_FILE_TASK_STATUS_SUCCESS	2	//成功
#define GPS_DEV_FILE_TASK_STATUS_FAIL		3	//失败

typedef struct _tagGPSFile2SvrMD5Ex
{
	char szFileName[64];	//文件名称
	int	nFileLength;		//文件长度
	char szMd5[40];			//文件MD5值
	int nFileType;			//文件类型 1 - 升级文件 
	char nProtocol;			//协议类型 0表示所有
	char nFactoryType;		//厂家类型 0表示所有
	char nDevType;			//设备类型 0表示所有
	char nDevSubType;		//设备子类型 0表示所有
	char szParam[116];		//文件参数信息,多个参数用|分隔(升级文件参数:版本号,版本名称)
}GPSFile2SvrMD5Ex_S, *LPGPSFile2SvrMD5Ex_S;

//屏蔽报警类型
typedef struct _tagGPSAlarmShield
{
	int		nAlarmType;			//报警类型		
}GPSAlarmShield_S, *LPGPSAlarmShield_S;

//地图标记的属性
typedef struct _tagGPSMarkerInfo
{
	int nID;				//数据库ID索引
	int nMarkerID;			//GPSMapMarker_S结构体的nID
	unsigned char nType;	//设备类型
	unsigned char nDevNum;	//数目(如nType为灭火器时候，nNum为灭火器的数目)
	unsigned char nMapType;	//地图类型，参照 mapapi.h 内的定义
	char	szReserve[25];	//保留
}GPSMarkerInfo_S, *LPGPSMarkerInfo_S;

//地图标记
typedef struct _tagGPSMapMarker
{
	int		nID;
	int		nMarkerType;		//标记类型，形状类型(点线面)
	int		nType;				//工厂，码头，物流园等
	int		nCreator;			//创建此标记的用户
	BOOL	bShare;				//是否允许共享，共享则公司所有用户都可以看到此标记信息
	char	szName[32];			//标记名称
	char	szJingDu[256];		//经度字符串,可包含多个经度由形状类型决定
	char	szWeiDu[256];		//纬度字符串,和经度字符串一一对应
	char	szColor[10];		//颜色
	char	szRemark[64];		//备注
	unsigned short	nExtinguisherNum;	//灭火器数量
	unsigned short 	nMapType;		//地图类型	MAP_GPS_TYPE_GOOGLE
	unsigned char nUpdate;			//0新增1更新已存在的记录
	char	cImageSuffix[4];		//图片后缀名（最多4个字节）
	unsigned short nHighRadius;		//半径高位,兼容老版本
	char	szReserver[21];			//2016-07-19 从23备用到21
}GPSMapMarker_S, *LPGPSMapMarker_S;

//行政区域
typedef struct _tagAdministrativeRegions 
{
	int nID;					//ID
	int nParentID;				//上级ID
	TCHAR szName[32];			//名称
	TCHAR szAreaName[128];		//区域名称
}AdministrativeRegions_S, *LPAdministrativeRegions_S;

typedef struct _tagGPSMapLine
{
	GPSMapMarker_S	Marker;		//其它参数与mapMarker保持一致
	char	szJingDu[110000];	//最多允许9999个轨迹点（每个轨迹点最多11个字符  113.134234）
	char	szWeiDu[110000];	//最多允许9999个轨迹点
}GPSMapLine_S, *LPGPSMapLine_S;

//扩展区域类型,客户端使用,保证线路和区域为同一类型
typedef struct _tagGPSMapMarkerEx
{
	GPSMapMarker_S	Marker;		//区域
	char*			pJingDu;	//经度
	char*			pWeiDu;		//纬度
}GPSMapMarkerEx_S, *LPGPSMapMarkerEx_S;

//区域围栏
typedef struct _tagGPSMapFence
{
	int		nID;					//围栏编号
	char	szDevIDNO[40];			//车辆编号
	int		nMarkerID;				//地图标记编号
	int		nAccessAlarm;			//访问区域报警（0不报警，1区域内报警，2区域外报警）
	int		nSpeedAlarm;			//速度报警（0不报警，1区域内报警，2区域外报警）
	int		nSpeedHigh;				//最高速度（单位公里  100 = 10.0公里）
	int		nSpeedLow;				//最低速度
	int		nParkAlarm;				//停车报警（0不报警，1区域内报警，2区域外报警）
	int		nParkTime;				//停车报警延时、最低60秒）单位秒
	int		nDoorAlarm;				//开门报警
	int		nBeginTime;				//开始时间、布防开始时间
	int		nEndTime;				//结束时间、布防结束时间
	int		nSpeedHighWarn;			//高速预警速度
	int		nSpeedLowWarn;			//低速预警速度
	char	szSpeedHighTts[128];	//高速TTS
	char	szSpeedHighWarnTts[128];//高速预警TTS
	char	szSpeedLowTts[128];		//低速TTS
	char	szSpeedLowWarnTts[128];	//低速预警TTS
}GPSMapFence_S, *LPGPSMapFence_S;

//围栏
typedef struct _tagGPSMapFenceInfo
{
	GPSMapFence_S mapFence;
	GPSMapMarker_S mapMarker;
}GPSMapFenceInfo_S, *LPGPSMapFenceInfo_S;

//线路
typedef struct _tagGPSMapLineInfo
{
	GPSMapFence_S mapFence;
	GPSMapLine_S mapLine;
}GPSMapLineInfo_S, *LPGPSMapLineInfo_S;

//客户端升级用到的信息
typedef struct _tagGPSUPFileInfo
{
	char	szModuleName[32];
	char	szVersion[128];
	char 	szPath[128];
	char	szSHA1[128];
	int		nFileLength;
	char	szReserve[32];	//保留
}GPSUPFileInfo_S, *LPGPSUPFileInfo_S;

typedef struct _tagGPSUPVersion
{
	char	szVersion[32];
	char	szDate[32];
	char	szSHA1[128];
	char	szKeyModule[32];
	char	szReserve[32];	//保留
}GPSUPVersion_S, *LPGPSUPVersion_S;

//客户端登录时、从服务器中获取客户端APP信息
typedef struct _tagGPSAppInfo
{
	int		nAppVersion;				//客户端版本	6.1.1.1	=  6 * 1000000 + 1 * 10000 + 1 * 100 + 1	每个版本最多两个数字
	int		nWebPort;					//WEB服务器端口
	char	szHost[128];				//地址，如  192.168.1.100，如果此参数为空则直接使用用户服务器的ip
	char	szWebApp[32];				//网关设备地址1
	char	szVerUrl[128];				//版本描述链接		/product/gViewer/upgrade.html
										//说明访问地址为  http://szHost:nWebPort/szWebApp/szVerUrl	或者 http://用户服务器址:nWebPort/szVerUrl
	char	cVersionChange;				//0:6.15.x.x之前的版本,1:6.15.x.x版本,依次增加,以后新老服务器不兼容,通过配置此参数来区别服务器的版本hw2013/11/21
	char	cVersionChangeEx;			//hw2014/8/13 cVersionChange版本客户端判断有问题,所以增加一个版本,以后cVersionChange不再改变,用此字段
	char	szRes[2];					//保留2个字节
	int		nAppVersionEx;				//新的版本号
	UINT	nAppMainVer;				//企业版本（新增，主要是界面不同，通过打包脚本添加上去, 通用版本用0）
	UINT	nAppFunVer;					//功能定制版本（客户端内部使用版本标志，通过此版本区分不同的功能, 通用版本用0）
	UINT	nAppFunSunVer;				//功能定制子版本, 通用版本用0
	char	szReserve[8];				//保留参数	30->8  hw 2015/3/27 
}GPSAppInfo_S;

//用户地图配置信息
typedef struct _tagUserMapConfig
{
	int nMapType;		//地图类型
	int	nJingDu;		//经度	4字节 整数部分	9999999 = 9.999999 
	int nWeiDu;			//纬度	4字节 整数部分	9999999 = 9.999999
	int nZoom;			//缩放级别
	char szReserve[128];
}UserMapConfig_S, *LPUserMapConfig_S;

//服务器配置信息
typedef struct _tagSvrConfig
{
	unsigned long lSvrConfig;
}SvrConfig_S, *LPSvrConfig_S;

//用户信息
typedef struct _tagClientUserInfo
{
	char szCompanyLogoFile[MAX_PATH];		//公司logo文件路径
	SYSTEMTIME timeCompanyLogoUpdate;		//公司logo更新时间
	char szUserLogoFile[MAX_PATH];			//用户logo文件路径
	SYSTEMTIME timeUserLogoUpdate;			//用户logo更新时间
}ClientUserInfo_S, *LPClientUserInfo_S;

//客户端功能
typedef struct _tagClientFunction
{
	unsigned char nMDVRValid;				//MDVR
	unsigned char nDVSValid;				//DVS
	unsigned char nMoblieValid;				//Moblie
	unsigned char nWifiSvrValid;			//自动下载服务器
	unsigned char nTarckBackValid;			//轨迹回放
	unsigned char nMapValid;				//地图	
	unsigned char nPTZValid;				//云台
	unsigned char nColorValid;				//色彩
	unsigned char nTalkbackValid;			//对讲
	unsigned char nAudioMonitorValid;		//监听
	unsigned char nBroadcastValid;			//广播
	unsigned char nReportValid;				//报表查询
	unsigned char nBusMgr;					//校车管理
	unsigned char nDevStatus;				//设备状态
	char szReserve[14];						//保留14
}ClientFunction_S, *LPClientFunction_S;

typedef struct _tagDevFixGPS
{
	char szDevIDNO[32];
	unsigned char ucMapValid;			//设置的位置是否有效
	unsigned char ucMapType;			//地图类型
	int	nJingDu;						//经度	4字节 整数部分	9999999 = 9.999999 
	int nWeiDu;							//纬度	4字节 整数部分	9999999 = 9.999999
}DevFixGPS_S, *LPDevFixGPS_S;

//电阻值对应油量
typedef struct _tagOilResistance
{
	char szDevIDNO[32];
	int nTimeCount;				//单位时间(秒)
	int nChangeOil;				//油量变化值(L)
	char szResistance[512];		//电阻值
	char szOil[512];			//油量	
}OilResistance_S, *LPOilResistance_S;


#define GPS_SNAPSHOT_PLAN_TIME_COUNT		2		//抓拍时间段数目
#define GPS_SNAPSHOT_PLAN_DAY_COUNT			7		//抓拍计划天数

#define GPS_SNAPSHOT_MODE_LOOP				1		//1表示通道循环抓拍(抓完通道1后,间隔时间后再抓拍通道2)
#define GPS_SNAPSHOT_MODE_ALL				2		//2表示独立进行抓拍，同时抓拍所有通道
//时间
typedef struct _tagGPSSnapshotDay						//抓拍每日计划
{	
	int	nBegin[GPS_SNAPSHOT_PLAN_TIME_COUNT];		//以秒为单位(时*3600+分*60+秒)
	int nEnd[GPS_SNAPSHOT_PLAN_TIME_COUNT];			//同上
}GPSSnapshotDay_S, *LPGPSSnapshotDay_S;
//抓拍计划
typedef struct _tagGPSSnapshotPlan						//抓拍计划
{	
	GPSSnapshotDay_S	Day[GPS_SNAPSHOT_PLAN_DAY_COUNT]; //0-周日,1-周一,...
	int nSpan;										//抓拍间隔 单位秒
	int	nSnapshotMode;								//1表示通道循环抓拍(抓完通道1后,间隔时间后再抓拍通道2)，2表示独立进行抓拍
	int nChannel;									//抓拍的通道号，0位-表示通道0，1位-表示通道1，依次类推
}GPSSnapshotPlan_S, *LPGPSSnapshotPlan_S;

//设备抓拍计划
typedef struct _tagGPSDevSnapshotPlan
{
	char szDevIDNO[32];								//设备IDNO
	GPSSnapshotPlan_S Plan;							//计划
}GPSDevSnapshotPlan_S, *LPGPSDevSnapshotPlan_S;

//报警处理
const int HANLEWAY_TYPE_PROCESSING = -1;	//处理中
const int HANLEWAY_TYPE_OVERTIME = 0;		//超时未处理
const int HANLEWAY_TYPE_MMS = 1;			//发送彩信
const int HANLEWAY_TYPE_IGNORE = 2;			//不处理
typedef struct _tagDevHandleAlarm
{
	char guid[40];			//报警guid
	char szAccount[40];		//登陆账户
	char szHandleInfo[256];	//处理方法
	int nHandleWay;
	char szDevIDNO[32];
	char szParam[92];		//保留92
}DevHandleAlarm_S, *LPDevHandleAlarm_S;

//报警查询
const int QUERY_ALARMINO_ALL = - 1;
typedef struct _tagAlarmQueryParam
{
	int nArmType;		//报警类型
	int nArmInfo;		//报警信息(为-1则忽略该参数)
}AlarmQueryParam_S, *LPAlarmQueryParam_S;

//离线文件信息
typedef struct _tagGPSOflFileInfo
{
	int nID;
	GPSFile2SvrMD5Ex_S FileInfo;
	int nSvrID;					//存储服务器的ID
	SYSTEMTIME dtUploaded;		//文件上传时间
}GPSOflFileInfo_S, *LPGPSOflFileInfo_S;

//设备离线任务
typedef struct _tagGPSDevOflTask
{
	int nID;				//数据库索引
	char szDevIDNO[40];		//设备ID
	int nFileType;			//文件类型，1表示升级文件
	int nFileID;			//文件ID
	SYSTEMTIME dtCreate;	//任务创建时间
	char szReserve[32];		//保留参数
}GPSDevOflTask_S, *LPGPSDevOflTask_S;

//录像类型
#define AUTODOWN_DOWN_TYPE_ALL				1		//1下载所有，2下载录像，3下载图片
#define AUTODOWN_DOWN_TYPE_RECORD			2		
#define AUTODOWN_DOWN_TYPE_JPEG				3		
#define AUTODOWN_DOWN_TYPE_RECORD_ALARM		4		
#define AUTODOWN_DOWN_TYPE_JPEG_ALARM		5
//设备下载计划
#define TASK_STATUS_ALL			-1
#define TASK_STATUS_NO_FINISH	0
#define TASK_STATUS_SUCCESS		1
#define TASK_STATUS_FAIL		2
typedef struct _tagGPSDevDloadTask
{
	int nID;				//数据库索引
	char szIDNO[64];		//设备编号或者车牌号
	int  nChannle;			//通道号(单个通道号或者全部通道号)
	int  nType;				//类型(1-所有 2-录像 3-图片 4-报警录像 5-报警图片);
	SYSTEMTIME BegTime;		//开始时间
	SYSTEMTIME EndTime;		//开始时间
	int	nStatus;			//状态
	char szLable[256];		//标签
	char szRemark[256];		//备注
	int  nAlarmInfo;		//4-报警录像 5-报警图片时，下载的文件类型	
							//REC_IOALARM = 0,	// IO 报警	REC_SPEED_H = 1,	// 超速报警	REC_SPEED_L = 2,	// 低速报警		REC_GSENSOR = 3,	// GSensor 
							//REC_TEMP = 4,      // 温度报警		REC_MD = 5,	   // 移动侦测		REC_UPSACT = 6,	 // UPS 报警
	char szReserve[60];		//保留参数
}GPSDevDloadTask_S, *LPGPSDevDloadTask_S;



//809查岗确认信息
typedef struct _tagAck809Platform
{
	char szSvrIDNO[40];			//服务器IDNO
	unsigned int uiInfoID;		//信息ID	当为报警督办ID，表示报警督办ID
	char szinfoContent[512];	//信息类容
	unsigned int uiType;		//1表示查岗，2表示报警督办应答，报警督办时，szSvrIDNO表示设备编号
	unsigned int uiResult;		//报警处理结果，0处理中，1处理完必，2不处理，3将来处理
	BYTE  nObjType;				// 查岗对象类型;
	char szObjectID[15];		//营运证号
	char szReserve[16];
}Ack809Platform_S, *LPAck809Platform_S;

//809相关业务
typedef struct _tagGPSJT809Business
{
	int	nType;				//类型
	char szDevIDNO[GPS_DEV_ID_LEN];	//设备编号
	SYSTEMTIME begTime;		//开始时间
	SYSTEMTIME endTime;		//结束时间
	char szReserve[512];	//保留数据
}GPSJT809Business_S, *LPGPSJT809Business_S;

//车辆动态信息交换业务
#define JT809_BUSINESS_TYPE_HISTORY_LOCATION			1			//下级平台 ---》  上级平台		自动补报车辆历史位置		设备编号，开始时间和结束时间
#define JT809_BUSINESS_TYPE_MONITOR_START_UP			2			//下级平台 ---》  上级平台		申请交换车辆定位信息		主动监视上级平台车辆信息时使用		设备编号，开始时间和结束时间
#define JT809_BUSINESS_TYPE_MONITOR_END				3				//下级平台 ---》  上级平台		取消申请交换车辆定位信息	车牌号
#define JT809_BUSINESS_TYPE_HISGNSSDATA				4				//下级平台 ---》  上级平台		补发车辆定位信息请求		设备编号，开始时间和结束时间	

//暂缓
#define JT809_BUSINESS_TYPE_ADPT_TODO_INF			5				//下级平台 ---》  上级平台		主动上报报警处理消息		设备编号，报警ID、处理结果	(0x00：处理中；0x01：已处理完毕；0x02：不作处理；0x03：将来处理。)

#define JT809_BUSINESS_TYPE_MAIN_LINK_CONNECT		6				//登录主链路，会与上级平台建立通信链路，并发送登录包
#define JT809_BUSINESS_TYPE_MAIN_LINK_DISCONN		7				//注销主链路，会与上级平台发送注销包，并断开连接
#define JT809_BUSINESS_TYPE_LINK_STATUS				8				//查看与上级监管平台的连接状态


//车辆驾驶状态
typedef struct _tagGPSVehiDriveStatus
{
	char szVehiIDNO[32];		//车牌号
	char szDirverName[64];		//姓名
	char szCardNO[32];			//身份证
	char szLicense[64];			//从业资格证编码
	char szOrgName[256];		//发证机构名称
	char szWaybill[512];		//运单信息
	char szReserve[128];		//保留参数
}GPSVehiDriveStatus_S, *LPGPSVehiDriveStatus;

//规则
#define RULE_TYPE_UNDEFINE		0		//未定义
#define RULE_TYPE_FATIGUE		1		//疲劳规则
#define RULE_TYPE_AREAIN		2		//禁入规则
#define RULE_TYPE_AREAOUT		3		//禁出规则
#define RULE_TYPE_AREASPEED		4		//区域低速超速规则
#define RULE_TYPE_TIMESPEED		5		//时间段低速超速规则
#define RULE_TYPE_PARK			6		//停车时间过长规则
#define RULE_TYPE_LINE			7		//线路规则
#define RULE_TYPE_SNAP			8		//定时拍照
#define RULE_TYPE_RECORD		9		//录像规则
#define RULE_TYPE_WIFIDLOAD		10		//WIFI下载规则
#define RULE_TYPE_SECTIONSPEED	11		//分段限速
#define RULE_TYPE_POINT			12		//关键点监控
#define RULE_TYPE_ALARM_ACTION	13		//报警联动
#define RULE_TYPE_ROAD			14		//道路规则

//规则通用参数
typedef struct _tagGPSRuleParam 
{
	char szVehiIDNO[32];	//车牌号
	int	 nType;				//类型
	int  nBeginTime;		//开始时间(秒)
	int  nEndTime;			//结束时间(秒)
	int  nAlarmType;		//报警类型
}GPSRuleParam_S, *LPGPSRuleParam_S;

//规则
typedef struct _tagGPSRuleLink
{
	char szText[1024];		//tts
	int  nSnapFlag;			//拍照标志(0-不拍照)
	char cSnapChn[8];		//拍照通道
	int  nRecordTime;		//录像时间	
	char cRecpChn[8];		//录像通道
	char szPhone[256];		//电话;分隔
	char szEmail[256];		//邮件;分隔
}GPSRuleLink_S, *LPGPSRuleLink_S;

//存储在数据库中的规则参数
typedef struct _tagGPSRuleDB
{
	int nID;				//规则ID
	GPSRuleParam_S	Param;	//参数
	char szText[1024];		//tts
	char szParam[1024];		//字符参数
	SYSTEMTIME UpdateTime;	//更新时间
}GPSRuleDB_S, *LPGPSRuleDB_S;

//疲劳规则
typedef struct _tagGPSVehiRuleFatigue
{
	GPSRuleParam_S Param;	//参数
	GPSRuleLink_S	Link;	//联动
	int		nDriveTime;		//行驶时间	
	int		nRestTime;		//休息时间
	int		nMinSpeed;		//最低速度
}GPSVehiRuleFatigue_S, *LPGPSVehiRuleFatigue_S;

//禁入规则
typedef struct _tagGPSVehiRuleAreaIn
{
	GPSRuleParam_S Param;	//参数
	GPSRuleLink_S	Link;	//联动
	int nAreaID;			//区域ID
}GPSVehiRuleAreaIn_S, *LPGPSVehiRuleAreaIn_S;

//禁出规则
typedef struct _tagGPSVehiRuleAreaOut
{
	GPSRuleParam_S Param;	//参数
	GPSRuleLink_S	Link;	//联动
	int nAreaID;			//区域ID
}GPSVehiRuleAreaOut_S, *LPGPSVehiRuleAreaOut_S;

//区域低速超速规则
typedef struct _tagGPSVehiRuleAreaSpeed
{
	GPSRuleParam_S Param;	//参数
	GPSRuleLink_S	Link;	//联动
	int nAreaID;			//区域ID
	int nMinSpeed;			//最低速度
	int nMaxSpeed;			//最高速度
}GPSVehiRuleAreaSpeed_S, *LPGPSVehiRuleAreaSpeed_S;

//时间段低速超速规则
typedef struct _tagGPSVehiRuleTimeSpeed
{
	GPSRuleParam_S Param;	//参数
	GPSRuleLink_S	Link;	//联动
	int nMinSpeed;			//最低速度
	int nMaxSpeed;			//最高速度
}GPSVehiRuleTimeSpeed_S, *LPGPSVehiRuleTimeSpeed_S;

//停车时间过长规则
typedef struct _tagGPSVehiRulePark
{
	GPSRuleParam_S Param;	//参数
	GPSRuleLink_S	Link;	//联动
	int nParkTime;			//停车时长
}GPSVehiRulePark_S, *LPGPSVehiRulePark_S;

//线路规则
typedef struct _tagGPSVehiRuleLine
{
	GPSRuleParam_S Param;	//参数
	GPSRuleLink_S	Link;	//联动
	int nAreaID;			//区域ID
	int nMinSpeed;			//最低速度
	int nMaxSpeed;			//最高速度
	int nWidth;				//宽度
}GPSVehiRuleLine_S, *LPGPSVehiRuleLine_S;

//定时拍照规则
typedef struct _tagGPSVehiRuleSnap
{
	GPSRuleParam_S Param;	//参数
	int nCondition;			//拍照条件(0-行驶停车拍照 1-行驶拍照 2-停车拍照)
//	int nCount;				//张数 大于1小于5
	int nIntervalSec;		//间隔(秒) 大于5分钟小于60分钟
	char cChnFlag[8];		//通道标志(1表示该通道拍照)
}GPSVehiRuleSnap_S, *LPGPSVehiRuleSnap_S;

//定时录像规则
typedef struct _tagGPSVehiRuleRecord
{
	GPSRuleParam_S Param;	//参数
	char cChnFlag[8];		//通道标志(1表示该通道录像)
}GPSVehiRuleRecord_S, *LPGPSVehiRuleRecord_S;

//WIFI下载规则
typedef struct _tagGPSVehiRuleWifiDLoad
{
	GPSRuleParam_S Param;	//参数
	char cChnFlag[8];		//通道标志(1表示下载该通道)
}GPSVehiRuleWifiDLoad_S, *LPGPSVehiRuleWifiDLoad_S;


//关键点监控
typedef struct _tagGPSVehiRulePoint
{
	GPSRuleParam_S Param;
	GPSRuleLink_S	Link;	//联动
	int nAreaID;			//区域ID
	int nAreaType;			//区域类型(map_marker类型 1-点, 4-线路)
	char szJingDu[32];		//经度
	char szWeiDu[32];		//维度
	int nWidth;				//宽度
	int nMonitorType;		//0:未到达1:未离开
}GPSVehiRulePoint_S, *LPGPSVehiRulePoint_S;

//分段限速
typedef struct _tagGPSVehiRuleSectionSpeed
{
	GPSRuleParam_S Param;
	GPSRuleLink_S	Link;	//联动
	int nAreaID;			//区域ID
	char szJingDuS[32];		//开始经度
	char szWeiDuS[32];		//结束纬度
	char szJingDuE[32];		//开始经度
	char szWeiDuE[32];		//结束纬度
	int nMinSpeed;			//最低速度
	int nMaxSpeed;			//最高速度
	int nWidth;				//宽度
}GPSVehiRuleSectionSpeed_S, *LPGPSVehiRuleSectionSpeed_S;

//报警联动
typedef struct _tagGPSVehiRuleArmAction
{
	GPSRuleParam_S Param;
	GPSRuleLink_S	Link;	//联动
}GPSVehiRuleArmAction_S, *LPGPSVehiRuleArmAction_S;

//道路规则
typedef struct _tagGPSVehiRuleRoad
{
	GPSRuleParam_S Param;
	GPSRuleLink_S	Link;		//联动
	int		nSpeedLimit[8];		//道路等级限速
}GPSVehiRuleRoad_S, *LPGPSVehiRuleRoad_S;


//规则联合体
typedef union _tagGPSVehiRule
{
	GPSVehiRuleFatigue_S	Fatigue;
	GPSVehiRuleAreaIn_S		AreaIn;
	GPSVehiRuleAreaOut_S	AreaOut;
	GPSVehiRuleAreaSpeed_S	AreaSpeed;
	GPSVehiRuleTimeSpeed_S	TimeSpeed;
	GPSVehiRulePark_S		Park;
	GPSVehiRuleLine_S		Line;
	GPSVehiRuleSnap_S		Snap;
	GPSVehiRuleRecord_S		Record;
	GPSVehiRuleWifiDLoad_S	WifiDLoad;
	GPSVehiRuleSectionSpeed_S SectionSpeed;
	GPSVehiRulePoint_S		Point;	
	GPSVehiRuleArmAction_S ArmAction;
	GPSVehiRuleRoad_S		Road;
}GPSVehiRule_S, *LPGPSVehiRule_S;

//规则
typedef struct _tagGPSVehiRuleInfo
{
	int nType;
	GPSVehiRule_S Rule;
}GPSVehiRuleInfo_S, *LPGPSVehiRuleInfo_S;


const int REAMIND_TYPE_TIMESTAMP = 0;
const int REAMIND_TYPE_VEHI_INSURANCE = 1;
const int REAMIND_TYPE_VEHI_TRANSPORTATION = 2;
const int REAMIND_TYPE_VEHI_LICENSE = 3;
const int REAMIND_TYPE_DIRVER = 4;

//车辆保险
typedef struct _tagGPSVehiInsuranceInfo
{
	int nVehiID;				//车辆ID
	char szCompany[64];			//保险公司
	char szTyp[64];				//保险类型
	char szNumber[64];			//单号
	int	 nAmount;				//保险金额单位0.01元
	char szClaimStatus[64];		//理赔状态
	SYSTEMTIME tmStart;			//开始时间
	SYSTEMTIME tmEnd;			//结束时间
	int nRemindDay;				//到期提醒天数
}GPSVehiInsuranceInfo_S, *LPGPSVehiInsuranceInfo_S;

//车辆运输证
typedef struct _tagGPSVehiTransportationInfo
{
	int nVehiID;				//车辆ID
	char szBusinessLicense[64];	//经营许可证号
	char szBusinessScope[64];	//经营范围
	SYSTEMTIME tmStart;			//开始时间
	SYSTEMTIME tmEnd;			//结束时间
	int nRemindDay;				//到期提醒天数
}GPSVehiTransportationInfo_S, *LPGPSVehiTransportationInfo_S;

//车辆行驶证
typedef struct _tagGPSVehiLicenseInfo
{
	int nVehiID;				//车辆ID
	char szIDCode[64];			//识别代码
	char szEngineCode[64];		//发动机代码
	char szLicense[64];			//行驶证
	char szUseNature[64];		//使用性质
	char szBrandModel[64];		//品牌型号
	SYSTEMTIME tmStart;			//开始时间
	SYSTEMTIME tmEnd;			//结束时间
	int nRemindDay;				//到期提醒天数
}GPSVehiLicenseInfo_S, *LPGPSVehiLicenseInfo_S;



#pragma pack()

#endif