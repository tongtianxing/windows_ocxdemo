#ifndef _GPS_DATA_DEF_H_
#define _GPS_DATA_DEF_H_

#define GPS_DEV_ID_LEN						32
#define GPS_MAX_DEV_CHN_NUM					16
#define GPS_MAX_DEV_IO_NUM					8
#define GPS_MAX_TEMP_SENSOR_NUM				4

#define GPSSERVER_TYPE_LOGIN				1
#define GPSSERVER_TYPE_GATEWAY				2
#define GPSSERVER_TYPE_MEDIA				3
#define GPSSERVER_TYPE_USRMGR				4
#define GPSSERVER_TYPE_STORAGE				5
#define GPSSERVER_TYPE_WEB					6
#define GPSSERVER_TYPE_DOWN					7		//下载服务器
#define GPSSERVER_TYPE_MANAGER				99		//管理服务器

#define GPS_FILE_LOCATION_DEVICE			1
#define GPS_FILE_LOCATION_STOSVR			2
//客户端3被用做本地搜索，定义出现重复，3先不用
#define GPS_FILE_LOCATION_DOWNSVR			4		//下载服务器录像搜索


#define GPS_FILE_ATTRIBUTE_JPEG				1
#define GPS_FILE_ATTRIBUTE_RECORD			2

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

#define GPS_DOWN_CONFIG_DATA				1
#define GPS_DOWN_CONFIG_FAILED				2
#define GPS_DOWN_CONFIG_SUC					3
#define GPS_DOWN_MAP_MARKER					4		//地图标记信息
#define GPS_DOWN_MAP_LINE					5		//地图线路信息
#define GPS_DOWM_MAP_TAB_INFO				6		//地图标记属性


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


/*
//2位设备列表
#define GPS_DOWN_CONFIG_DEVICE				2
//3位报警屏蔽
#define GPS_DOWN_CONFIG_ALARM_SHIELD		3
//5位我的地图
#define GPS_DOWN_CONFIG_MY_MAP				5
*/

#define GPS_DOWNLOAD_MSG_FAILED				1
#define GPS_DOWNLOAD_MSG_BEGIN				2
#define GPS_DOWNLOAD_MSG_FINISHED			3
#define GPS_DOWNLOAD_MSG_PROCESS			4

#define GPS_UPLOAD_MSG_FAILED				1
#define GPS_UPLOAD_MSG_FINISHED				2
#define GPS_UPLOAD_MSG_PROCESS				3

const int GPS_CTRL_TYPE_OIL_STOP			= 1;	//断开油路
const int GPS_CTRL_TYPE_OIL_RESTORE			= 2;	//恢复油路
const int GPS_CTRL_TYPE_ELEC_STOP			= 3;	//断开电路
const int GPS_CTRL_TYPE_ELEC_RESTORE		= 4;	//恢复电路
const int GPS_CTRL_TYPE_REBOOT				= 5;	//重启机器 
const int GPS_CTRL_TYPE_RESET				= 6;	//设备复位
const int GPS_CTRL_TYPE_MOD_DEV_NUM_OR_GET_STATUS = 7;//修改设备号、获取设备状态
const int GPS_CTRL_TYPE_3G_REBOOT_IP       =8;     //IP,3G,重启

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
const int GPS_MNGCMD_SET_CONFIG				= 21;		//设置设备参数
const int GPS_MNGCMD_GET_CONFIG				= 22;		//获取设备参数
const int GPS_MNGCMD_SET_PARAM				= 23;		//设置单个类型的设备参数
const int GPS_MNGCMD_GET_PARAM				= 24;		//获取单个类型的设备参数

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

//存储路径定义，存储示例	"E:\\gStorage\\RECORD_FILE\\100001\\2012-07-03\\"
const char GPS_STORAGE_PATH[]				= "gStorage";
const char GPS_RECORD_PATH[]				= "RECORD_FILE";

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
#define GPS_USER_TYPE_COMMON	0	//普通用户
#define GPS_USER_TYPE_ADMIN		1	//管理员
#define GPS_USER_TYPE_TEST		2	//测试用户

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
	char	szIoInName[GPS_MAX_DEV_IO_NUM][16];
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
	char    szReserve[60];		//保留字段
}GPSDEVDevInfo_S, *LPGPSDEVDevInfo_S;

typedef struct _tagGPSMDVRInfo
{
	unsigned char ucIoInNum;			//IO 输入数目
	unsigned char ucTempSensorNum;	//温度传感器数目
	unsigned char szRes[2];
	char	szChnName[GPS_MAX_DEV_CHN_NUM][16];		
	char	szIoInName[GPS_MAX_DEV_IO_NUM][16];
	char	szTempSensorName[GPS_MAX_TEMP_SENSOR_NUM][16];
	
	char	szVehiColor[16];	//车辆颜色
	char	szVehiBand[16];		//车辆品牌
	char	szVehiType[16];		//车辆类型
	char	szVehiUse[16];		//车辆用途
	char	szVehiCampany[16];	//车辆公司
	char	szDriverName[16];	//司机名称
	char	szDriverTele[16];	//司机电话
	char    szReserve[60];		//保留字段
}GPSMDVRInfo_S, *LPGPSMDVRInfo_S;

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
}GPSMobileDevInfo_S, *LPGPSMobileDevInfo_S;

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
	char strReserve[29];			//保留
	union
	{
		GPSMDVRInfo_S gDVRInfo;
		GPSMobileDevInfo_S gMobileDevInfo;
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
	char	szRemarks[64];	//
}GPSDEVGroup_S, *LPGPSDEVGroup_S;

typedef struct _tagGPSAddrInfo
{
	char szLanIP[64];
	char szDeviceIP[64];
	char szClientIP[64];
	unsigned short usDevicePort;
	unsigned short usClientPort;
	unsigned short usReserve[2];
}GPSAddrInfo_S;

typedef struct _tagGPSServerInfo
{
	int nID;
	char szIDNO[32];
	char szName[32];
	long nGroup;
	GPSAddrInfo_S	Addr;
}GPSServerInfo_S, *LPGPSServerInfo_S;

typedef struct _tagGPSServerAddr
{
	int nSvrID;
	GPSAddrInfo_S Addr;
}GPSServerAddr_S, *LPGPSServerAddr_S;

typedef struct _tagGPSMEDIAFile
{
	char	szFile[256]; 	/*带路径的文件名*/
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
	char	szReserve[26];	//保留
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
	char	szReserver[30];
}GPSMapMarker_S, *LPGPSMapMarker_S;

typedef struct _tagGPSMapLine
{
	GPSMapMarker_S	Marker;		//其它参数与mapMarker保持一致
	char	szJingDu[110000];	//最多允许9999个轨迹点（每个轨迹点最多11个字符  113.134234）
	char	szWeiDu[110000];	//最多允许9999个轨迹点
}GPSMapLine_S, *LPGPSMapLine_S;

//区域围栏
typedef struct _tagGPSMapFence
{
	int		nID;			//围栏编号
	char	szDevIDNO[40];	//车辆编号
	int		nMarkerID;		//地图标记编号
	int		nAccessAlarm;	//访问区域报警（0不报警，1区域内报警，2区域外报警）
	int		nSpeedAlarm;	//速度报警（0不报警，1区域内报警，2区域外报警）
	int		nSpeedHigh;		//最高速度（单位公里  100 = 10.0公里）
	int		nSpeedLow;		//最低速度
	int		nParkAlarm;		//停车报警（0不报警，1区域内报警，2区域外报警）
	int		nParkTime;		//停车报警延时、最低60秒）单位秒
	int		nDoorAlarm;		//开门报警
	int		nBeginTime;		//开始时间、布防开始时间
	int		nEndTime;		//结束时间、布防结束时间
}GPSMapFence_S, *LPGPSMapFence_S;

//围栏
typedef struct _tagGPSMapFenceInfo
{
	GPSMapFence_S mapFence;
	GPSMapMarker_S mapMarker;
}GPSMapFenceInfo_S, *LPGPSMapFenceInfo_S;

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
	char	szWebApp[32];				//WEB App地址，如gpsweb，如果此参数为空，则不使用
	char	szVerUrl[128];				//版本描述链接		/product/gViewer/upgrade.html
										//说明访问地址为  http://szHost:nWebPort/szWebApp/szVerUrl	或者 http://用户服务器址:nWebPort/szVerUrl
	char	szReserve[32];				//保留参数
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


#pragma pack()

#endif