#ifndef _NET_DEVICE_DEF_H_
#define _NET_DEVICE_DEF_H_


//#include "hi_dataType.h"

#define GPS_FRM_TYPE_HEAD						1
#define GPS_FRM_TYPE_I							0x63643000
#define GPS_FRM_TYPE_P							0x63643100
#define GPS_FRM_TYPE_A							0x63643230
#define GPS_FRM_TYPE_INFO						0x63643939
#define GPS_FRM_TYPE_REC_HDR					2

#define GPS_RESOLUTION_QCIF				1	//分辨率
#define GPS_RESOLUTION_CIF				2	//分辨率
#define GPS_RESOLUTION_HD1				3	//分辨率
#define GPS_RESOLUTION_D1				4	//分辨率
#define GPS_RESOLUTION_720P				5	//分辨率
#define GPS_RESOLUTION_1080P			6	//分辨率

#define GPS_FILE_TYPE_NORMAL					0
#define GPS_FILE_TYPE_ALARM						1
#define GPS_FILE_TYPE_ALL						-1



#define GPS_CHANNEL_ALL							99

#define GPS_ALARM_TYPE_ALL						0		//所有报警

#define GPS_ALARM_TYPE_USEDEFINE				1		//自定义报警
#define GPS_ALARM_TYPE_URGENCY_BUTTON			2		//紧急按钮报警
#define GPS_ALARM_TYPE_SHAKE					3		//振动报警
#define GPS_ALARM_TYPE_VIDEO_LOST				4		//摄像头无信号报警
#define GPS_ALARM_TYPE_VIDEO_MASK				5		//摄像头遮挡报警
#define GPS_ALARM_TYPE_DOOR_OPEN_LAWLESS		6		//非法开门报警
#define GPS_ALARM_TYPE_WRONG_PWD				7		//三次密码错误报警
#define GPS_ALARM_TYPE_FIRE_LOWLESS				8		//非法点火报警
#define GPS_ALARM_TYPE_TEMPERATOR				9		//温度报警		AlarmInfo传感器编号（0表示传感器1，1表示传感器2）, param[0]温度类型（0表示超高温，1表示超低温）, param[1]当前温度10000=100度 
#define GPS_ALARM_TYPE_DISK_ERROR				10		//硬盘错误报警
#define GPS_ALARM_TYPE_OVERSPEED				11		//超速报警
#define GPS_ALARM_TYPE_BEYOND_BOUNDS			12		//越界报警
#define GPS_ALARM_TYPE_DOOR_ABNORMAL			13		//异常开关车门报警
#define GPS_ALARM_TYPE_PARK_TOO_LONG			14		//停车过长报警
#define GPS_ALARM_TYPE_MOTION					15		//移动侦测报警
#define GPS_ALARM_TYPE_ACC_ON					16		//ACC开启报警
#define GPS_ALARM_TYPE_DEV_ONLINE				17		//设备在线
#define GPS_ALARM_TYPE_GPS_SIGNAL_LOSS          18      //GPS讯号丢失开始
#define GPS_ALARM_TYPE_IO_1                     19      //IO_1报警
#define GPS_ALARM_TYPE_IO_2                     20      //IO_2报警
#define GPS_ALARM_TYPE_IO_3                     21      //IO_3报警
#define GPS_ALARM_TYPE_IO_4                     22      //IO_4报警
#define GPS_ALARM_TYPE_IO_5                     23      //IO_5报警
#define GPS_ALARM_TYPE_IO_6                     24      //IO_6报警
#define GPS_ALARM_TYPE_IO_7                     25		//IO_7报警
#define GPS_ALARM_TYPE_IO_8                     26      //IO_8报警
#define GPS_ALARM_TYPE_IN_FENCE		            27      //进入区域报警
#define GPS_ALARM_TYPE_OUT_FENCE		        28      //出区域报警
#define GPS_ALARM_TYPE_IN_FENCE_OVER_SPEED      29      //区域内高速报警
#define GPS_ALARM_TYPE_OUT_FENCE_OVER_SPEED     30      //区域外高速报警
#define GPS_ALARM_TYPE_IN_FENCE_LOW_SPEED       31      //区域内低速报警
#define GPS_ALARM_TYPE_OUT_FENCE_LOW_SPEED      32      //区域外低速报警
#define GPS_ALARM_TYPE_IN_FENCE_STOP			33      //区域内停车报警
#define GPS_ALARM_TYPE_OUT_FENCE_STOP			34      //区域外停车报警
#define GPS_ALARM_TYPE_FIRE                     35      //火警
#define GPS_ALARM_TYPE_PANIC                    36      //劫警
#define GPS_ALARM_TYPE_TASK_FINISHED			37		//调度任务完成
#define GPS_ALARM_TYPE_IMAGE_UPLOAD				38		//图片上传完成
#define GPS_ALARM_TYPE_DISK1_NO_EXIST			39		//硬盘1不存在
#define GPS_ALARM_TYPE_DISK2_NO_EXIST			40		//硬盘2不存在
#define GPS_ALARM_TYPE_IO_9                     41      //IO_9报警
#define GPS_ALARM_TYPE_IO_10                    42      //IO_10报警
#define GPS_ALARM_TYPE_IO_11                    43      //IO_11报警
#define GPS_ALARM_TYPE_IO_12                    44      //IO_12报警
#define GPS_ALARM_TYPE_GPS_UNENABLE				45		//GPS无效
#define GPS_ALARM_TYPE_REFUEL					46		//加油	AlarmInfo为加油的油量(9999=99.99升)，Param[0]为加油前油耗
#define GPS_ALARM_TYPE_STILL_FUEL				47		//偷油	AlarmInfo为偷油的油量(9999=99.99升)，Param[0]为偷油前油耗
#define GPS_ALARM_TYPE_URGENCY_BUTTON_5			48		//紧急按钮报警(5秒)
#define GPS_ALARM_TYPE_FATIGUE					49		//疲劳驾驶	AlarmInfo表示报警级别	0 , 没有， 1  一级报警 2 二级报警, 3 三级报警, 4 关注度报警



#define GPS_ALARM_TYPE_END_USEDEFINE			51		//自定义报警
#define GPS_ALARM_TYPE_END_URGENCY_BUTTON		52		//紧急按钮报警
#define GPS_ALARM_TYPE_END_SHAKE				53		//振动报警
#define GPS_ALARM_TYPE_END_VIDEO_LOST			54		//摄像头无信号报警
#define GPS_ALARM_TYPE_END_VIDEO_MASK			55		//摄像头遮挡报警
#define GPS_ALARM_TYPE_END_DOOR_OPEN_LAWLESS	56		//非法开门报警
#define GPS_ALARM_TYPE_END_WRONG_PWD			57		//三次密码错误报警
#define GPS_ALARM_TYPE_END_FIRE_LOWLESS			58		//非法点火报警
#define GPS_ALARM_TYPE_END_TEMPERATOR			59		//温度报警
#define GPS_ALARM_TYPE_END_DISK_ERROR			60		//硬盘错误报警
#define GPS_ALARM_TYPE_END_OVERSPEED			61		//超速报警
#define GPS_ALARM_TYPE_END_BEYOND_BOUNDS		62		//越界报警
#define GPS_ALARM_TYPE_END_DOOR_ABNORMAL		63		//异常开关车门报警
#define GPS_ALARM_TYPE_END_PARK_TOO_LONG		64		//停车过长报警
#define GPS_ALARM_TYPE_END_MOTION				65		//移动侦测报警
#define GPS_ALARM_TYPE_ACC_OFF					66		//ACC关闭报警
#define GPS_ALARM_TYPE_DEV_DISONLINE			67		//设备断线
#define GPS_ALARM_TYPE_END_GPS_SIGNAL_LOSS      68      //GPS讯号丢失结束
#define GPS_ALARM_TYPE_END_IO_1                 69      //IO_1报警
#define GPS_ALARM_TYPE_END_IO_2                 70      //IO_2报警
#define GPS_ALARM_TYPE_END_IO_3                 71      //IO_3报警
#define GPS_ALARM_TYPE_END_IO_4                 72      //IO_4报警
#define GPS_ALARM_TYPE_END_IO_5                 73      //IO_5报警
#define GPS_ALARM_TYPE_END_IO_6                 74      //IO_6报警
#define GPS_ALARM_TYPE_END_IO_7                 75      //IO_7报警
#define GPS_ALARM_TYPE_END_IO_8                 76      //IO_8报警
#define GPS_ALARM_TYPE_END_IN_FENCE		            77      //进入区域报警
#define GPS_ALARM_TYPE_END_OUT_FENCE		        78      //出区域报警
#define GPS_ALARM_TYPE_END_IN_FENCE_OVER_SPEED      79      //区域内高速报警
#define GPS_ALARM_TYPE_END_OUT_FENCE_OVER_SPEED     80      //区域外高速报警
#define GPS_ALARM_TYPE_END_IN_FENCE_LOW_SPEED       81      //区域内低速报警
#define GPS_ALARM_TYPE_END_OUT_FENCE_LOW_SPEED		82      //区域外低速报警
#define GPS_ALARM_TYPE_END_IN_FENCE_STOP			83      //区域内停车报警
#define GPS_ALARM_TYPE_END_OUT_FENCE_STOP			84      //区域外停车报警
#define GPS_ALARM_TYPE_END_GPS_UNENABLE				85		//GPS无效
//加油和偷油没有结束
#define GPS_ALARM_TYPE_END_REFUEL					86		//加油	AlarmInfo为加油的油量(9999=99.99升)，Param[0]为加油前油耗
#define GPS_ALARM_TYPE_END_STILL_FUEL				87		//偷油	AlarmInfo为偷油的油量(9999=99.99升)，Param[0]为偷油前油耗

#define GPS_ALARM_TYPE_END_IO_9				        91      //IO_9报警
#define GPS_ALARM_TYPE_END_IO_10			        92      //IO_10报警
#define GPS_ALARM_TYPE_END_IO_11					93      //IO_11报警
#define GPS_ALARM_TYPE_END_IO_12					94      //IO_12报.

#define GPS_ALARM_TYPE_END_FATIGUE					99		//疲劳驾驶	AlarmInfo表示报警级别	0 , 没有， 1  一级报警 2 二级报警, 3 三级报警, 4 关注度报警


#define GPS_EVENT_TYPE_PARK						101		//停车事件			Param[0]为停车秒数，Param[1]为停车前油耗(9999=99.99升)，Param[2]为停车后油耗
#define GPS_EVENT_TYPE_PARK_ACCON				102		//停车未熄火事件	Param[0]为停车秒数，Param[1]为停车前油耗(9999=99.99升)，Param[2]为停车后油耗
														//停车未熄火事件一般处于停车事件里面的一段时间内，11:00 - 11:20处于停车，11:00 - 11:05 处于停车未熄火
#define GPS_EVENT_TYPE_NET_FLOW					103		//流量	Param[0]为当前时间（单位秒，如：7206 = 当天02:06时 ），Param[1]为上行流量，Param[2]为下行流量
#define GPS_EVENT_TYPE_REFUEL					104		//加油	AlarmInfo为加油的油量(9999=99.99升)，Param[0]为加油前油耗
#define GPS_EVENT_TYPE_STILL_FUEL				105		//偷油	AlarmInfo为偷油的油量(9999=99.99升)，Param[0]为偷油前油耗
#define GPS_EVENT_TYPE_OVERSPEED				106		//超速事件	AlarmInfo为速度(999=99.9KM/H)，Param[0]超速的时间，Param[1]为超速类型（超高速或者超低速、暂时无效）
#define GPS_EVENT_TYPE_FENCE_ACCESS				107		//进出区域事件	 Param[0]区域编号，Param[1]出区域经度，Param[2]出区域纬度，Param[3]区域停留时间(秒）
#define GPS_EVENT_TYPE_FENCE_PARK				108		//区域停车事件	 Param[0]区域编号，Param[3]区域停车时间（秒）
#define GPS_EVENT_TYPE_FILE_UPLOAD				109		//图片文件或者录像文件上传
#define GPS_EVENT_TYPE_STATION_INFO				110		//报站信息
#define GPS_EVENT_TYPE_SEA_STATUS				111		//海船状态报警 1：出海 2：进港 3：外海滞留报警 4：外海滞留报警结束
//#define GPS_EVENT_TYPE_LOCK_STATUS				112		//电子锁状态					
#define GPS_ALARM_TYPE_CUSTOM					113		//自定义报警, AlarmInfo表示类型
										// param[0]表示参数1，param[1]表示参数2，param[2]表示参数3, param[3]表示参数4, 
										//szDesc表示内容，为字符串格式，中间不允许出现'\0'，最长为256个字节
#define GPS_EVENT_TYPE_OVERSPEED_WARNING		114		//超速预警
#define GPS_EVENT_TYPE_LOWSPEED_WARNING			115		//超速预警
#define GPS_EVENT_TYPE_DRIVER					116		//驾驶员信息采集上报 AlarmInfo：1表示登录，0表示退签，
														//szReserve 表示司机名称，szDesc 表示发证机关，szImgFile：用 ';' 分隔 ，身体证号;从业资格证编码
#define GPS_EVENT_TYPE_OVER_STATION				117		//过站报警 
#define GPS_EVENT_TYPE_EXCEED_STATION			118		//越站报警，param[0],param[1]前一个报站时间和站点

#define GPS_EVENT_TYPE_TASK_READ				121		//guid为对应的任务guid,人员已经查看了调度任务
#define GPS_EVENT_TYPE_TASK_REPLY				122		//guid为对应的任务guid,人员对调度任务进行了回复，szDesc，为回复内容
#define GPS_ALARM_TYPE_MOBILE_USEDEFINE			123		//自定义报警

#define GPS_ALARM_TYPE_TALK_BACK_REQ			127		//车辆主动对讲请求，以报警方式发送
#define GPS_ALARM_TYPE_DEVICE_INFO_CHANGE		128		//车辆信息发生变化，如用户修改设备信息
#define GPS_ALARM_TYPE_SNAPSHOT_FINISH			129		//存储服务器抓拍完成，以报警方式发送给客户端
#define GPS_ALARM_TYPE_DOWN_FINISH				130		//存储服务器文件任务下载完成，以报警方式发送给客户端
#define GPS_ALARM_TYPE_DEVICE_INFO_CHANGE_EX	131		//车辆信息发生变化，如用户修改设备信息
#define GPS_ALARM_TYPE_TRANS_PORT				132		//透传数据
#define GPS_ALAMT_TYPE_SWIPE_CARD				133		//刷卡记录 不同于司机考勤 alarminfo：-1表示无上下车表示， 0-上车， 1-下车 desc:卡号

#define GPS_ALARM_TYPE_NIGHT_DRIVING 			151		//夜间行驶报警
#define GPS_ALARM_TYPE_END_NIGHT_DRIVING		152
#define GPS_ALARM_TYPE_GATHERING				153		//聚众报警
#define GPS_ALARM_TYPE_END_GATHERING			154
#define GPS_ALARM_TYPE_USP_CUT		 			155		//UPS 剪线报警
#define GPS_ALARM_TYPE_END_USP_CUT				156
#define GPS_ALARM_TYPE_HDD_HIGH_TEMPERATURE		157		//硬盘超温报警
#define GPS_ALARM_TYPE_END_HDD_HIGH_TEMPERATURE	158
#define GPS_ALARM_TYPE_BEFORE_BOARD_OPENED		159		//前面板被撬开
#define GPS_ALARM_TYPE_END_BEFORE_BOARD_OPENED	160		
#define GPS_ALARM_TYPE_TURN_OFF					161		//关机上报	alarmInfo为原因: 1 ACC 无效关机,2定时关机,3软件重启, 4软件异常关机,5掉电关机,6硬盘锁打开关机
#define GPS_ALARM_TYPE_DISK_SPACE_WARNING		162		//硬盘空间报警		硬盘空间警告,alarmInfo为硬盘号,param[0]表示硬盘类型TTX_DISK_TYPE_SD, param[1]总空间, param[2]剩余空间,  16000表示空间为16000MB
#define GPS_ALARM_TYPE_END_DISK_SPACE_WARNING	163		//硬盘空间报警
#define GPS_ALARM_TYPE_GSENSOR					164		//GSENSOR报警
#define GPS_ALARM_TYPE_END_GSENSOR				165
#define GPS_ALARM_TYPE_SIM_LOST					166		//SIM卡丢失报警
#define GPS_ALARM_TYPE_END_SIM_LOST				167
#define GPS_ALARM_TYPE_TPMS						168		//胎压报警			//	胎压报警, alarmInfo  TPMS报警类型（1表示电池电压警告，2表示胎压异常报警，3表示温度异常）,
//			param[0] 当前温度 如: 200 = 20度
//			param[1] 当前胎压 如: 25 = 2.5P
//			param[2] 当前电压 如: 102=10.2V
//			param[3] 传感器编号（01表示TPMS左1，02表示TPMS左2，03表示TPMS左3，04表示TPMS左4，11表示TPMS右1，12表示TPMS右2，13表示TPMS右3，14表示TPMS右4）
#define GPS_ALARM_TYPE_END_TPMS					169		//胎压报警结束

#define GPS_ALARM_TYPE_FACE_WARNING				170		//面向警示
#define GPS_ALARM_TYPE_END_FACE_WARNING			171		//
#define GPS_ALARM_TYPE_CLOSE_EYE_WARNING		172		//闭眼警示
#define GPS_ALARM_TYPE_END_CLOSE_EYE_WARNING	173		//
#define GPS_ALARM_TYPE_PHONE_WARNING			174		//手机警示
#define GPS_ALARM_TYPE_END_PHONE_WARNING		175		//
#define GPS_ALARM_TYPE_SMOKE_WARNING			176		//抽烟警示
#define GPS_ALARM_TYPE_END_SMOKE_WARNING		177		//

//808部分报警
#define GPS_ALARM_TYPE_AREA_OVERSPEED					200		//区域超速报警
#define GPS_ALARM_TYPE_WARNING							201		//预警
#define GPS_ALARM_TYPE_GNSS_MOD_ERR						202		//GNSS模块故障
#define GPS_ALARM_TYPE_GNSS_WIRE_MISS					203		//GNSS天线未接或者剪断
#define GPS_ALARM_TYPE_GNSS_WIRE_SHORTAGE				204		//GNSS天线短路
#define GPS_ALARM_TYPE_VOLTAGE_LOW						205		//电源欠压
#define GPS_ALARM_TYPE_POWER_OFF						206		//电源掉电
#define GPS_ALARM_TYPE_LCD_ERR							207		//LCD或者显示器故障
#define GPS_ALARM_TYPE_TTS_MOD_ERR						208		//TTS模块故障
#define GPS_ALARM_TYPE_CAMERA_MOD_ERR					209		//摄像头故障
#define GPS_ALARM_TYPE_DIRVE_TIMEOUT					210		//累计驾驶超时
#define GPS_ALARM_TYPE_AREA_INOUT						211		//进出区域
#define GPS_ALARM_TYPE_LINE_INOUT						212		//进出线路
#define GPS_ALARM_TYPE_LINE_DRIVE_TIME					213		//路段行驶时间过长/过短
#define GPS_ALARM_TYPE_LINE_DEVIATE						214		//线路偏离
#define GPS_ALARM_TYPE_VSS_ERR							215		//VSS故障
#define GPS_ALARM_TYPE_OIL_ABNORMAL						216		//油量异常
#define GPS_ALARM_TYPE_STOLEN							217		//车辆被盗
#define GPS_ALARM_TYPE_MOVE_LAWLESS						218		//非法位移
#define GPS_ALARM_TYPE_COLLISION						219		//碰撞侧翻报警
#define GPS_ALARM_TYPE_PASSENGER_FORBID					220		//客运车辆禁止  param[0]当前超速限速值
#define GPS_ALARM_TYPE_MOUNTAIN_FORBID					221		//山区公路禁止  param[0]-位置类型 param[1]-区域或者线路ID param[2]当前超速限速值 
#define GPS_ALARM_TYPE_OVERSPEED_L1_FIVE_LESS		    222		//超速20%  5分钟内
#define GPS_ALARM_TYPE_OVERSPEED_L1_FIVE_TO_TEN			223		//超速20%  5(含)-10分钟
#define GPS_ALARM_TYPE_OVERSPEED_L1_TEN_MORE			224		//超速20%  10(含)分钟以上
#define GPS_ALARM_TYPE_OVERSPEED_L2_FIVE_LESS			225		//超速20-50%  5分钟内
#define GPS_ALARM_TYPE_OVERSPEED_L2_FIVE_TO_TEN			226		//超速20-50%  5(含)-10分钟
#define GPS_ALARM_TYPE_OVERSPEED_L2_TEN_MORE			227		//超速20-50%  10(含)分钟以上
#define GPS_ALARM_TYPE_OVERSPEED_L3_FIVE_LESS			228		//超速50%  5分钟内
#define GPS_ALARM_TYPE_OVERSPEED_L3_FIVE_TO_TEN			229		//超速50%  5(含)-10分钟
#define GPS_ALARM_TYPE_OVERSPEED_L3_TEN_MORE			230		//超速50%  10(含)分钟以上
#define GPS_ALARM_TYPE_OVERLAOD							231		//超载

#define GPS_ALARM_TYPE_END_AREA_OVERSPEED				250		//区域超速报警
#define GPS_ALARM_TYPE_END_WARNING						251		//预警
#define GPS_ALARM_TYPE_END_GNSS_MOD_ERR					252		//GNSS模块故障
#define GPS_ALARM_TYPE_END_GNSS_WIRE_MISS				253		//GNSS天线未接或者剪断
#define GPS_ALARM_TYPE_END_GNSS_WIRE_SHORTAGE			254		//GNSS天线未接或者剪断
#define GPS_ALARM_TYPE_END_VOLTAGE_LOW					255		//电源欠压
#define GPS_ALARM_TYPE_END_POWER_OFF					256		//电源掉电
#define GPS_ALARM_TYPE_END_LCD_ERR						257		//LCD或者显示器故障
#define GPS_ALARM_TYPE_END_TTS_MOD_ERR					258		//TTS模块故障
#define GPS_ALARM_TYPE_END_CAMERA_MOD_ERR				259		//TTS模块故障
#define GPS_ALARM_TYPE_END_DIRVE_TIMEOUT				260		//累计驾驶超时
#define GPS_ALARM_TYPE_END_AREA_INOUT					261		//进出区域
#define GPS_ALARM_TYPE_END_LINE_INOUT					262		//进出线路
#define GPS_ALARM_TYPE_END_LINE_DRIVE_TIME				263		//路段行驶时间过长/过短
#define GPS_ALARM_TYPE_END_LINE_DEVIATE					264		//线路偏离
#define GPS_ALARM_TYPE_END_VSS_ERR						265		//VSS故障
#define GPS_ALARM_TYPE_END_OIL_ABNORMAL					266		//油量异常
#define GPS_ALARM_TYPE_END_STOLEN						267		//车辆被盗
#define GPS_ALARM_TYPE_END_MOVE_LAWLESS					268		//非法位移
#define GPS_ALARM_TYPE_END_COLLISION					269		//碰撞侧翻报警
#define GPS_ALARM_TYPE_END_PASSENGER_FORBID				270		//客运车辆禁止  param[0]当前超速限速值
#define GPS_ALARM_TYPE_END_MOUNTAIN_FORBID				271		//山区公路禁止  param[0]-位置类型 param[1]-区域或者线路ID param[2]当前超速限速值 
#define GPS_ALARM_TYPE_END_OVERSPEED_L1_FIVE_LESS		272		//超速20%  5分钟内
#define GPS_ALARM_TYPE_END_OVERSPEED_L1_FIVE_TO_TEN		273		//超速20%  5(含)-10分钟
#define GPS_ALARM_TYPE_END_OVERSPEED_L1_TEN_MORE		274		//超速20%  10(含)分钟以上
#define GPS_ALARM_TYPE_END_OVERSPEED_L2_FIVE_LESS		275		//超速20-50%  5分钟内
#define GPS_ALARM_TYPE_END_OVERSPEED_L2_FIVE_TO_TEN		276		//超速20-50%  5(含)-10分钟
#define GPS_ALARM_TYPE_END_OVERSPEED_L2_TEN_MORE		277		//超速20-50%  10(含)分钟以上
#define GPS_ALARM_TYPE_END_OVERSPEED_L3_FIVE_LESS		278		//超速50%  5分钟内
#define GPS_ALARM_TYPE_END_OVERSPEED_L3_FIVE_TO_TEN		279		//超速50%  5(含)-10分钟
#define GPS_ALARM_TYPE_END_OVERSPEED_L3_TEN_MORE		280		//超速50%  10(含)分钟以上
#define GPS_ALARM_TYPE_END_OVERLAOD						281		//超载

#define GPS_ALARM_TYPE_CMS_AREA_OVERSPEED			300		//区域超速报警(平台产生) param[0]-位置类型 param[1]-区域或者线路ID param[2]-速度阀值
#define GPS_ALARM_TYPE_CMS_AREA_LOWSPEED			301		//区域低速报警(平台产生) param[0]-位置类型 param[1]-区域或者线路ID param[2]-速度阀值	
#define GPS_ALARM_TYPE_CMS_AREA_INOUT				302		//进出入区域(平台产生)	 param[0]-位置类型 param[1]-区域或者线路ID param[2]-0:进1:出
#define GPS_ALARM_TYPE_CMS_LINE_INOUT				303		//线路偏移(平台产生)	 param[0]-位置类型 param[1]-区域或者线路ID param[2]-0:进1:出
#define GPS_ALARM_TYPE_CMS_OVERSPEED				304		//时间段超速报警(平台产生) param[0]速度阀值
#define GPS_ALARM_TYPE_CMS_LOWSPEED					305		//时间段低速报警(平台产生) param[0]速度阀值
#define GPS_ALARM_TYPE_CMS_FATIGUE					306		//疲劳驾驶(平台产生)   
#define	GPS_ALARM_TYPE_CMS_PARK_TOO_LONG			307		//超时停车(平台产生)
#define GPS_ALARM_TYPE_CMS_AREA_POINT				308		//关键点监控报警(平台产生)	param[0]-位置类型 param[1]-区域或者线路ID param[2]-0:未到达1:未离开
#define GPS_ALARM_TYPE_CMS_LINE_OVERSPEED			309		//线路超速报警(平台产生) param[0]-位置类型 param[1]-线路ID param[2]-速度阀值
#define GPS_ALARM_TYPE_CMS_LINE_LOWSPEED			310		//线路低速报警(平台产生) param[0]-位置类型 param[1]-线路ID param[2]-速度阀值
#define GPS_ALARM_TYPE_CMS_ROAD_LVL_OVERSPEED		311		//道路等级超速报警(平台产生) param[0]-道路等级 param[1]-市标志 param[2]-速度阀值

#define GPS_ALARM_TYPE_END_CMS_AREA_OVERSPEED		350		//区域超速报警(平台产生) param[0]-位置类型 param[1]-区域或者线路ID param[2]-速度阀值	
#define GPS_ALARM_TYPE_END_CMS_AREA_LOWSPEED		351		//区域低速报警(平台产生) param[0]-位置类型 param[1]-区域或者线路ID param[2]-速度阀值
#define GPS_ALARM_TYPE_END_CMS_AREA_INOUT			352		//进出入区域(平台产生)	 param[0]-位置类型 param[1]-区域或者线路ID param[2]-0:进1:出	
#define GPS_ALARM_TYPE_END_CMS_LINE_INOUT			353		//线路偏移(平台产生)	 param[0]-位置类型 param[1]-区域或者线路ID param[2]-0:进1:出
#define GPS_ALARM_TYPE_END_CMS_OVERSPEED			354		//时间段超速报警(平台产生)
#define GPS_ALARM_TYPE_END_CMS_LOWSPEED				355		//时间段低速报警(平台产生)
#define GPS_ALARM_TYPE_END_CMS_FATIGUE				356		//疲劳驾驶(平台产生)
#define	GPS_ALARM_TYPE_END_CMS_PARK_TOO_LONG		357		//超时停车(平台产生)
#define GPS_ALARM_TYPE_END_CMS_AREA_POINT			358		//关键点监控报警(平台产生)	param[0]-位置类型 param[1]-区域或者线路ID param[2]-0:未到达1:未离开
#define GPS_ALARM_TYPE_END_CMS_LINE_OVERSPEED		359		//线路超速报警(平台产生) param[0]-位置类型 param[1]-线路ID param[2]-速度阀值
#define GPS_ALARM_TYPE_END_CMS_LINE_LOWSPEED		360		//线路低速报警(平台产生) param[0]-位置类型 param[1]-线路ID param[2]-速度阀值
#define GPS_ALARM_TYPE_END_CMS_ROAD_LVL_OVERSPEED	361		//道路等级超速报警(平台产生) param[0]-道路等级 param[1]-市标志 param[2]-速度阀值


//自定义报警类型子类型定义 GPS_ALARM_TYPE_CUSTOM(113)
#define CUSTOM_ALARM_TYPE_PLATE					1	//车牌图片抓拍
#define CUSTOM_ALARM_TYPE_PRESON				2	//人脸识别
#define CUSTOM_ALARM_TYPE_EMPTY_PASSENGER		3	//空载
#define CUSTOM_ALARM_TYPE_LOAD_PASSENGER		4	//负载
#define CUSTOM_ALARM_TYPE_FENCE_ACC_SPPED		5	//电子围栏外,AAC开,速度0,报警
#define CUSTOM_ALARM_TYPE_TTS_REPLY				6	//tts回复
#define CUSTOM_ALARM_TYPE_OFF_ROUTE				7	//偏离线路,PAD上传报警
#define CUSTOM_ALARM_TYPE_TASK_FAILED			8	//任务失败,PAD上传报警
#define CUSTOM_ALARM_TYPE_TASK_FINISHED			9	//任务完成,PAD上传报警
#define CUSTOM_ALARM_TYPE_ALARM_ACTION			10	//报警联动
#define CUSTOM_ALARM_TYPE_START_ACC_SPEED5		11	//ACC信号有效、车速低于5公里/小时 报警开始
#define CUSTOM_ALARM_TYPE_END_ACC_SPEED5		12	//ACC信号有效、车速低于5公里/小时 报警结束
#define CUSTOM_ALARM_TYPE_START_SPPED0_IO3		13	//ACC信号有效、车速为0时、搅拌车的滚筒状态反转(IO_3) 报警开始
#define CUSTOM_ALARM_TYPE_END_SPPED0_IO3		14	//ACC信号有效、车速为0时、搅拌车的滚筒状态反转(IO_3) 报警结束

#define CUSTOM_ALARM_TYPE_EVENT_REPORT			15	//808事件报告
#define CUSTOM_ALARM_TYPE_INFO_DEMAND			16	//808点播信息
#define CUSTOM_ALARM_TYPE_ELECTRONIC_WAYBILL	17	//808电子运单
#define CUSTOM_ALARM_TYPE_COMPRESS_DATA			18	//压缩数据
#define CUSTOM_ALARM_TYPE_OFL_TASK				19	//离线任务通知
#define CUSTOM_ALARM_TYPE_MEDIA_EVETN			20	//媒体事件

//809查岗消息需要在客户端弹框显示，收到用户反馈后，再返回到上级平台
//回复时需要将查岗消息ID回复到客户端
// 	GPSVehicleAlarm_S VehiAlarm = {0};
// 	STRINGGenerateGUID(VehiAlarm.Alarm.guid);
//	strncpy(VehiAlarm.szDevIDNO, NETLOGIN_GetIDNO(), sizeof(VehiAlarm.szDevIDNO) - 1);
//	VehiAlarm.Alarm.AlarmType = GPS_ALARM_TYPE_CUSTOM;
//	VehiAlarm.Alarm.AlarmInfo = nAlarmInfo;
//	VehiAlarm.Alarm.Param[0] = pInfo->nObjType;
//	VehiAlarm.Alarm.Param[1] = pInfo->nMsgID;
//	VehiAlarm.Alarm.Param[2] = strlen(pInfo->szContent);
//	strncpy(VehiAlarm.Alarm.szDesc, pInfo->szObjID, sizeof(VehiAlarm.Alarm.szDesc) - 1);
//	strncpy(VehiAlarm.Alarm.szImgFile, pInfo->szContent, sizeof(VehiAlarm.Alarm.szImgFile) - 1);
#define CUSTOM_ALARM_TYPE_809_PLATFORM_POST_QUERY	21	//809查岗信息
//		上级平台 ---》下级平台	平台查岗消息
//szDevIDNO：网关服务器编号
//Param1：查岗对象类型
//Param2：查网消息ID
//szDesc：营运证号
//szImgFile：查询信息内容
// 对象类型		
// 0x00  下级平台所属单一平台
// 0X01  当前连接的下级平台，由平台行政区划代码和平台唯一编码组成；
// 0X02  下级平台所属单一业户；为业户经营许可证号  
// 0X03  下级平台所属所有业户
// 0X04  下级平台所有平台
// 0X05  下级平台所有平台和业户
// 0X06  下级平台所有政府监管平台（含监控端）
// 0X07  下级平台所有企业监控平台
// 0X08  下级平台所有经营性企业监控平台
// 0X09  下级平台所有非经营性企业监控平台


//以下为809相关的事件，需要在客户端上显示
// 	GPSVehicleAlarm_S VehiAlarm = {0};
// 	STRINGGenerateGUID(VehiAlarm.Alarm.guid);
// 	strncpy(VehiAlarm.szDevIDNO, szDevIDNO, sizeof(VehiAlarm.szDevIDNO) - 1);		//设备编号
// 	VehiAlarm.Alarm.AlarmType = GPS_ALARM_TYPE_CUSTOM;				
// 	VehiAlarm.Alarm.AlarmInfo = nAlarmType;		对应 为  CUSTOM_ALARM_TYPE_809_EVENT_MONITOR_START_UP 等			
// 	VehiAlarm.Alarm.Param[0] = nColor;			对应的车牌颜色		
// 	VehiAlarm.Alarm.Param[1] = nParam2;
// 	VehiAlarm.Alarm.bSendOnly = 1;
// 	strncpy(VehiAlarm.Alarm.szDesc, NETLOGIN_GetIDNO(), sizeof(VehiAlarm.Alarm.szDesc) - 1);		//网关服务器的编号
// 	strncpy(VehiAlarm.Alarm.szImgFile, szContent, sizeof(VehiAlarm.Alarm.szImgFile) - 1);			//
#define CUSTOM_ALARM_TYPE_809_EVENT_RETURN_START_UP					22	
//		上级平台 ---》下级平台	启动车辆定位数据交换
//		事件内容：	上级平台启动车辆定位信息交换请求消息:车牌=%s, 颜色=%d,交换原因：%s
//		参数：		nParam2：	交换原因		0：车辆进入指定区域		1：人工指定交换		2：应急状态下的车辆定位数据回传，3：其它原因
#define CUSTOM_ALARM_TYPE_809_EVENT_RETURN_END						23	
//		上级平台 ---》下级平台	停止车辆定位数据交换
//		事件内容：	上级平台停止车辆定位信息交换请求消息:车牌=%s, 颜色=%d,结束原因：%s
//		参数：		nParam2：	停止原因		//0：车辆离开指定区域		1：人工停止交换		2：紧急监控完成		3：其它原因		4：其它原因
#define CUSTOM_ALARM_TYPE_809_EVENT_MONITOR_START_UP_ASK			24	
//		上级平台 ---》下级平台	启动车辆定位数据交换应答
//		事件内容：	申请交换制定车辆定位消息应答消息:车牌=%s, 颜色=%d,结果：%s
//		参数：		nParam2：	结果	0：申请成功，1：上级没有该车的信息，2：申请时间段错误，3：其它
#define CUSTOM_ALARM_TYPE_809_EVENT_MONITOR_END_ASK					25	
//		上级平台 ---》下级平台	取消车辆定位数据交换应答
//		事件内容：	取消申请交换制定车辆定位信息应答消息:车牌=%s, 颜色=%d,结果：%s
//		参数：		nParam2：	0：取消申请成功，1：之前没有对应的该车的信息，2：其它
#define CUSTOM_ALARM_TYPE_809_EVENT_APPLY_HISGNSSDATA_ASK			26
//		上级平台 ---》下级平台	下级平台请求补传车辆静态数据应答
//		事件内容：	补发车辆定位信息应答消息:车牌=%s, 颜色=%d,结果：%s
//		参数：		nParam2：	//0：成功，上级平台立刻补发，1：成功，上级平台择机补发，2：失败，上级平台无对应申请定位数据，3：失败，申请内容不正确，4：其它原因
#define CUSTOM_ALARM_TYPE_809_EVENT_CAR_INFO						27
//		上级平台 ---》下级平台	车辆静态数据
//		事件内容：	交换车辆静态信息消息:车牌=%s,颜色=%d, 车辆静态信息:%s
//		参数：		szContent为车辆静态信息
#define CUSTOM_ALARM_TYPE_809_PLATFORM_INFO							28	//平台报文
//		上级平台 ---》下级平台	平台报文
//		和 CUSTOM_ALARM_TYPE_809_PLATFORM  数据内容定义一样
//		事件内容：	下发平台报文, 报文类型=%d, 信息ID=%d, 营运证号=%s, 信息内容=%s
#define CUSTOM_ALARM_TYPE_809_WARN_URGE_TODO						29	//报警督办
//		上级平台 ---》下级平台	报警督办，客户端需要弹框进行回复
//		事件内容：	报警督办请求消息 车辆=%s, 信息ID=%d, 信息源=%s, 督办级别=%s， 报警类型=%s,报警时间=%s, 督办期限=%s  督办人=%s,督办电话=%s, 督办Email=%s
//		参数：		param1：	车牌颜色
//					param2：	低16位为  nWarnSrc报警源	1车载终端，2企业平台，3政府平台，9其它  
//							高16位为  usWarnType报警类型		
//								1  超速报警，2 疲劳驾驶报警，3 紧急报警，4 进入指定区域报警，5  离开指定区域报警	6  路段阻塞报警   7  危险路段报警	
//								8  越界		9 盗警		10  劫警	11   偏移路线    12  车辆移动    13  超时驾驶   FF  其它报警
//					param3：	uiSuporVisionID		督办ID
//					param4：	uiSuporVisionLeve	报警督办级别		0紧急，1一般
//					szDesc		督办人;督办电话;督办Email
//					srcTime		报警时间
//					Gps.Time	报警督办截止时间
#define CUSTOM_ALARM_TYPE_809_WARN_INFORMTIPS						30	//报警预警消息
//		上级平台 ---》下级平台	报警预警消息
//		事件内容：	报警预警消息 车辆=%s, 颜色=%d, 信息来源=%s, 报警时间=%s, 报信信息=%s:%s
//		参数：		param1：	车牌颜色
//					param2：	低16位为  nWarnSrc报警源	1车载终端，2企业平台，3政府平台，9其它  
//							高16位为  usWarnType报警类型	
//					srcTime		报警时间
//					szDesc		报警信息内容
#define CUSTOM_ALARM_TYPE_809_WARN_EXG_INFO							31	//报警交换消息
//		上级平台 ---》下级平台	报警交换消息
//		和 CUSTOM_ALARM_TYPE_809_WARN_INFORMTIPS  数据内容定义一样
//		事件内容：	实时交换报警信息 车辆=%s, 信息来源=%s, 报警时间=%s, 报信信息=%s:%s
#define CUSTOM_ALARM_TYPE_809_CONN_MSG_INFO							32	//与上级平台的连接信息
//		上级平台 《---》下级平台	连接信息
//		参数：		szImgFile		连接信息内容，直接做显示即可以


#define CUSTOM_ALARM_TYPE_MEDIA_INFO								40
//通知媒体信息(通知到下载服务器)


#define CUSTOM_ALARM_TYPE_QUESTION_ANSWER								41	//提问应答 param[0] 回复流水号 param[1]回复答案ID

#define CUSTOM_ALARM_TYPE_BARCODE_SCAN									42	//条形码扫描报警

#define CUSTOM_ALARM_TYPE_PLATFORM_TEXT									43  //平台互通，发送文本消息  param[0]发送方用户ID， param[1]接受方用户ID szDesc:发送内容

//银星:自定义报警
#define GPS_ALARM_TYPE_SIMUL_INFRARED_HILLFIRE      400     //同步银星：红外火源检测报警
#define GPS_ALARM_TYPE_SIMUL_ULTRAVIOLET_PHOTON     401     //同步银星：紫外线路电晕放电报警
#define GPS_ALARM_TYPE_SIMUL_IO                     402     //同步银星：IO报警
#define GPS_ALARM_TYPE_SIMUL_TEMPERATURE_OVERRUN    403     //同步银星：温度超限报警
#define GPS_ALARM_TYPE_SIMUL_WIND_SPEED_DIRECTION   404     //同步银星：风速风向报警
#define GPS_ALARM_TYPE_SIMUL_RAINFALL_OVERRUN       405     //同步银星：雨量超限报警


//道路等级定义
#define ROAD_LEVEL_UNKOWN				0	//未知
#define ROAD_LEVEL_HIGH_ROAD			1	//高速路
#define ROAD_LEVEL_CITYHIGH_ROAD		2	//都市高速路
#define ROAD_LEVEL_NATIONAL_ROAD		3	//国道
#define ROAD_LEVEL_PROVINICIAL_ROAD		4	//省道
#define ROAD_LEVEL_PREFECTURA_ROAD		5	//县道
#define ROAD_LEVEL_CONUTY_ROAD			6	//乡镇村道
#define ROAD_LEVEL_OTHER_ROAD			7	//其它道路
#define ROAD_LEVEL_NINE_ROAD			8	//九级路
#define ROAD_LEVEL_FERRY_ROAD			9	//轮渡
#define ROAD_LEVEL_PEDESTRIAN_ROAD		10	//行人道路


#define GPS_CNT_MSG_SUCCESS				0
#define GPS_CNT_MSG_FAILED				-1
#define GPS_CNT_MSG_DISCONNECT			-2
#define GPS_CNT_MSG_FINISHED			-3
#define GPS_CNT_MSG_USR_FULL_ERROR		-4
#define GPS_CNT_MSG_USR_ERROR			-5

#define GPS_NOTIFY_TYPE_AUDIO_COM		1

#define GPS_AUDIO_TYPE_HEAD				1
#define GPS_AUDIO_TYPE_DATA				2

#define GPS_SETUP_MODE_SEND_ONLY		1	//只发送指令，不等待反馈
#define GPS_SETUP_MODE_WAIT_RET			2	//发送指令，并等待反馈
#define GPS_SETUP_MODE_WAIT_ASYN		3	//发送指令，上层检查返回

#define GPS_GPS_VALID					1

#define GPS_DEV_TYPE_MDVR				1 //车载终端
#define GPS_DEV_TYPE_MOBILE				2 //手机终端
#define GPS_DEV_TYPE_DVR				3 //普通DVR
#define GPS_DEV_TYPE_PAD				4 //PAD类型

#define GPS_MOBILE_TYPE_ANDROID			1 //手机终端-Android
#define GPS_MOBILE_TYPE_IPHONE			2 //手机终端-Iphone

#define GPS_MDVR_TYPE_HI3512_4			1 //车载终端-3512
#define GPS_MDVR_TYPE_HI3515_4			2 //车载终端-3515-4
#define GPS_MDVR_TYPE_HI3515_8			3 //车载终端-3515-8

#define GPS_MOBILE_USER_POST_TEAM_MEMBER	1	//队员
#define GPS_MOBILE_USER_POST_TEAM_LEADER	2	//队长

#define GPS_MOBILE_USER_SEX_MAN				1	//男
#define GPS_MOBLIE_USER_SEX_WOMAN			2	//女

#define GPS_PTZ_MOVE_LEFT				0	//左
#define GPS_PTZ_MOVE_RIGHT				1	//右
#define GPS_PTZ_MOVE_TOP				2	//上
#define GPS_PTZ_MOVE_BOTTOM				3	//下
#define GPS_PTZ_MOVE_LEFT_TOP			4	//左上
#define GPS_PTZ_MOVE_RIGHT_TOP			5	//右上
#define GPS_PTZ_MOVE_LEFT_BOTTOM		6	//左下
#define GPS_PTZ_MOVE_RIGHT_BOTTOM		7	//右下

#define GPS_PTZ_FOCUS_DEL				8	//焦距变小
#define GPS_PTZ_FOCUS_ADD				9	//焦距变大
#define GPS_PTZ_LIGHT_DEL				10	//光圈变小
#define GPS_PTZ_LIGHT_ADD				11	//光圈变大
#define GPS_PTZ_ZOOM_DEL				12	//焦点后调(倍数)
#define GPS_PTZ_ZOOM_ADD				13	//焦点前调
#define GPS_PTZ_LIGHT_OPEN				14	//灯光
#define GPS_PTZ_LIGHT_CLOSE				15
#define GPS_PTZ_WIPER_OPEN				16	//雨刷
#define GPS_PTZ_WIPER_CLOSE				17
#define GPS_PTZ_CRUISE					18	//自动巡航
#define GPS_PTZ_MOVE_STOP				19	//停止

#define GPS_PTZ_PRESET_MOVE				21	//调用
#define GPS_PTZ_PRESET_SET				22	//设置
#define GPS_PTZ_PRESET_DEL				23	//删除

#define GPS_PTZ_SPEED_MIN				0
#define GPS_PTZ_SPEED_MAX				255

#define GPS_GPSINTERVAL_TYPE_DISTANCE	1	//按距离上报
#define GPS_GPSINTERVAL_TYPE_TIME		2	//按时间上报

//客户端查询车辆轨迹的选项
#define GPS_QUERY_TRACK_TYPE_GPS		1  //查询GPS数据
#define GPS_QUERY_TRACK_TYPE_GPSARLMR	2  //查询GPS和报警
#define GPS_QUERY_TRACK_TYPE_ALARM		3  //查询报警数据

//返回
#define GPS_TRACK_DATA_TYPE_GPS			1  //GPS数据
#define GPS_TRACK_DATA_TYPE_ALARM		2  //报警数据

//网络类型
#define GPS_NETWOKR_TYPE_3G				0	//3G类型
#define GPS_NETWOKR_TYPE_WIFI			1	//WIFI类型
#define GPS_NETWORK_TYPE_NET			2	//有线网络登录
#define GPS_NETWORK_TYPE_4G				3	//4G网络登录

//磁盘类型
#define GPS_DISK_TYPE_UNKOWN			0	//SD卡
#define GPS_DISK_TYPE_SD				1	//SD卡
#define GPS_DISK_TYPE_HDD				2	//硬盘
#define GPS_DISK_TYPE_SSD				3	//SSD


#define GPS_DISK_STATUS_UNKONW			0	
#define GPS_DISK_STATUS_NORMAL			1	//正常
#define GPS_DISK_STATUS_BAD				2	//坏了

//文件下载类型
#define GPS_DOWN_TYPE_OFFSET			1		//按文件偏移下载
#define GPS_DOWN_TYPE_TIME				2		//按时间偏移下载
#define GPS_DOWN_TYPE_SOURCE_SERVER		3		//从服务器主动下载，下载完成后，机器可以删除相应的文件

//协议类型cProtocol，1-15是通用版本
#define MDVR_PROTOCOL_TYPE_WKP			1
#define MDVR_PROTOCOL_TYPE_TTX			2
#define MDVR_PROTOCOL_TYPE_TQ			3
#define MDVR_PROTOCOL_TYPE_HANV			4
#define MDVR_PROTOCOL_TYPE_GOOME		5
#define MDVR_PROTOCOL_TYPE_JT808		6
#define MDVR_PROTOCOL_TYPE_RM			7
#define MDVR_PROTOCOL_TYPE_YD			8
#define MDVR_PROTOCOL_TYPE_UNIMV		9
#define MDVR_PROTOCOL_TYPE_BSJ			10
#define MDVR_PROTOCOL_TYPE_LHXY			11	//联合欣业


//厂家设备类型(WKP协议下的子类型)cFactoryType
#define WKP_FACTORY_TYPE_UNKOWN			0
#define WKP_FACTORY_TYPE_WKP			1		
#define WKP_FACTORY_TYPE_AUDS			2
#define WKP_FACTORY_TYPE_KX				3
#define WKP_FACTORY_TYPE_EST			4
#define WKP_FACTORY_TYPE_YXHD			5
#define WKP_FACTORY_TYPE_COOINT			6
#define WKP_FACTORY_TYPE_7				7
#define WKP_FACTORY_TYPE_8				8
#define WKP_FACTORY_TYPE_9				9
#define WKP_FACTORY_TYPE_10				10
#define WKP_FACTORY_TYPE_11				11
#define WKP_FACTORY_TYPE_12				12
#define WKP_FACTORY_TYPE_13				13
#define WKP_FACTORY_TYPE_14				14
#define WKP_FACTORY_TYPE_15				15
#define WKP_FACTORY_TYPE_16				16
#define WKP_FACTORY_TYPE_17				17
#define WKP_FACTORY_TYPE_18				18	
#define WKP_FACTORY_TYPE_19				19	
#define WKP_FACTORY_TYPE_20				20	
#define WKP_FACTORY_TYPE_21				21	
#define WKP_FACTORY_TYPE_22				22	
#define WKP_FACTORY_TYPE_23				23  
#define WKP_FACTORY_TYPE_24				24
#define WKP_FACTORY_TYPE_25				25
#define WKP_FACTORY_TYPE_26				26
#define WKP_FACTORY_TYPE_27				27
#define WKP_FACTORY_TYPE_28				28
#define WKP_FACTORY_TYPE_29				29

//GPS坐标类型定义
#define	GPS_COOR_TYPE_WSG84		0		//WSG84类型坐标
#define	GPS_COOR_TYPE_GCJ02		1		//火星坐标，高德地图使用
#define	GPS_COOR_TYPE_BD09		2		//百度坐标

//GPS定位类型定义
#define	GPS_LOC_TYPE_GPS			0		//GPS定位
#define	GPS_LOC_TYPE_WIFI			1		//WIFI定位

//客户端和设备数据透传类型
#define GPS_TPD_TYPE_DJWL_SET_TASK_FAIL_TIME	1	//大件物流设置任务失败时间
#define GPS_TPD_TYPE_DJWL_TASK_FAIL_CONFIRM		2	//大件物流任务失败确认
#define GPS_TPD_TYPE_DJWL_TASK_STOP				3	//大件物流手动点击任务完成或失败


#pragma pack(4)

typedef struct _tagGPSDeviceInfo
{
	char sVersion[64];///
	char sSerialNumber[32];  		
	char szDevIDNO[32];			///车辆编号  		
	short sDevType;				///设备类型
	char cFactoryType;			//厂家类型	
	char cFactoryDevType;		//厂家设备类型
	char cDiskNum;///硬盘数目	
	char cChanNum;///通道数目
	char cProtocol;				//协议类型
	unsigned char cAudioCodec:5;//音频解码器类型
	unsigned char cDiskType:3;	//0：SD，1：硬盘，2：SSD
	char cPlateNumber[34];		//车牌号
	char cPlateUnicode:1;		//0表示非unicode，1表示unicode
	char cPlateColor:7;			//车牌颜色 1-蓝2-黄3-黑4-白9-其他
	char bTimeZoneValid:1;		//时区是否有效
	char cTimeZone:7;			//时区
}GPSDeviceInfo_S, *LPGPSDeviceInfo_S;

typedef struct _tagGPSDeviceIDNO
{
	char szDevIDNO[32];
}GPSDeviceIDNO_S, *LPGPSDeviceIDNO_S;

typedef struct _tagGPSSvrAddr
{
	char	IPAddr[80];
	unsigned short usPort;
	unsigned short Reserve;
}GPSSvrAddr_S;

typedef struct _tagGPSFile
{
	char	szFile[242]; 	/*带路径的文件名*/	
	// 2016-3-16	243变为242， 增加流标识
	char	bStream;		//是否为流式文件，当为流式文件时，客户端会使用回放的方式进行文件下载
	// 2015-8-17	244变为243， 增加录像标识
	char	bRecording;		//是否正在录像的文件，0表示没有，1表示正在录像
	// 2015-4-30	248变为244， 增加文件偏移量
	unsigned int nFileOffset;	//文件偏移量
	//2015-04-08 原来是252，变为248，增加 nChnMask
	int		nChnMask;		//通道掩码，每个文件存在多个通道
	//2015-03-14 原来是256，变为252，增加 nAlarmInfo
	int		nAlarmInfo;		//报警信息，每个文件可能会有多个报警
	int		nYear;
	int		nMonth;
	int		nDay;
	unsigned int uiBegintime;
	unsigned int uiEndtime;
	char	szDevIDNO[32];			//设备ID
	int		nChn;
	unsigned int nFileLen;
	int		nFileType;
	int		nLocation;		//位置，设备上的录像文件，还是存储服务上的录像文件
	int		nSvrID;			//存储服务器ID，在为存储服务器上的文件时有效
}GPSFile_S, *LPGPSFile_S;

typedef struct _tagGPSRecFile
{
	char	szFile[230]; 	/*带路径的文件名*/		
	// 2016-3-16	231变为230， 增加流标识
	char	bStream;		//是否为流式文件，当为流式文件时，客户端会使用回放的方式进行文件下载
	//原来是232，取1个字节来用，afu：20150817
	char	bRecording;		//是否正在录像的文件，0表示没有，1表示正在录像
	//原来是236，取4个字节来用，afu：20150410
	int nChnMask;			//通道掩码
	//原来是240，取4个字节来用，afu：20150305
	int nAlarmInfo;	//每个文件可能会有多个报警
	//原来是256，取16个字节来用，afu：20140815
	unsigned char ucYear;		//跨天搜索用
	unsigned char ucMonth;		//跨天搜索用
	unsigned char ucDay;		//跨天搜索用
	char cReserve[13];		

	//char	szFile[256]; 	/*带路径的文件名*/

	unsigned int uiBegintime;
	unsigned int uiEndtime;
	int		nChn;
	unsigned int nFileLen;
	int		nRecType;
}GPSRecFile_S, *LPGPSRecFile_S;

//时间
typedef struct _tagGPSTime
{
	unsigned int ucYear:6;		//年(2000+ucYear) 范围(0-64)
	unsigned int ucMonth:4;		//月(1-12)	范围(0-16)
	unsigned int ucDay:5;		//日(1-31)  范围(0-32)
	unsigned int ucHour:5;		//时(0-23)	范围(0-32)
	unsigned int ucMinute:6;	//分(0-59)  范围(0-64)
	unsigned int ucSecond:6;	//秒(0-59)  范围(0-64)
}GPSTime_S;

//车辆状态,每位表示车辆的相关状态
//uiStatus[0]共有32位
//0位表示GPS定位状态		0无效1有效
//1位表示ACC状态		0表示ACC关闭1表示ACC开启
//2位表示左转状态		0无效1左转
//3位表示右转状态		0无效1右转
//4位表示刹车状态		0无效1刹车
//5位表示正转状态		0无效1正转
//6位表示反转状态		0无效1反转
//7位表示GPS天线状态		0不存在1存在
//8,9位为表示硬盘状态		0不存在，1存在，2断电
//10,11,12位表示3G模块状态  0模块不存在，1无信号，2信号差，3信号一般，4信号好，5信号优
//13位表示静止状态		1表示静止
//14位表示超速状态		1表示超速
//15位表示补传状态		1表示GPS补传
//16位低速状态
//17位表示夜间			0-表示日间 1-表示夜间 先判断超速才有效
//18位表示超载状态		0-正常 1-超载
//19位
//关于停车未熄火，如果处理静止状态，并且处于ACC开启状态，则表示停车未熄火
//20位表示IO1状态	1表示报警
//21位表示IO2状态	1表示报警
//22位表示IO3状态	1表示报警
//23位表示IO4状态	1表示报警
//24位表示IO5状态	1表示报警
//25位表示IO6状态	1表示报警
//26位表示IO7状态	1表示报警
//27位表示IO8状态	1表示报警
//28位表示盘符2状态	1表示有效
//29、30位表示，硬盘2的状态		0不存在，1存在，2断电
//31位硬盘状态（GPS设备时使用）	1、无效		0、有效，要再判断1，2的状态
//uiStatus[1]
//0位表示出区域报警	 （终端产生）
//1位表示出线路报警	 （终端产生）	

//2位表示区域内高速报警	
//3位表示区域内低速报警	

//4位表示区域外高速报警
//5位表示区域外低速报警	

//6位表示区域内停车报警	
//7位表示区域外停车报警	
	
//8位表示日流量预警
//9位表示日流量超过
//10位表示月流量预警
//11位表示月流量超过

/*  --- 删除 hw2016-8-18
//12位--主机掉电由后备电池供电
//13位--车门开
//14位--车辆设防
//15位--电池电压过低
//16位--电池坏
//17位--发动机
*/
//12: 作业状态: 1-作业中 0-空闲  平台产生(环卫车)
//13: 高峰作业: 1-高峰作业			 平台产生(环卫车)
//14~16: 环卫已作业遍数(0~7)	 平台产生(环卫车)

//18位--为最后一个有效的GPS信息，状态显示成定位无效，但GPS可以在地图上定位
//19位--0-空载状态 1-重载状态

//20：运营状态；1：停运状态(808)
//21：经纬度未加密；1：已加密(808)
//22：油路正常，1：油路断开(808)
//23：电路正常，1：电路断开(808)
//24：车门解锁，1：车门加锁(808)
//25：区域超速报警(平台产生)
//26：区域低速报警(平台产生)
//27：进区域报警(平台产生)	 
//28：线路偏移(平台产生)
//29：时间段超速报警(平台产生) 
//30：时间段低速报警(平台产生) 
//31：疲劳驾驶(平台产生)   

//uiStatus[2]
//0-7表示通道视频丢失状态
//8-15表示通道录像状态
//16-23表示IO输入9-16 状态
//24-27表示IO输出1-4 状态
//28-29 0表示GPS定位，1表示基站定位，2表示Wifi定位，  手机定位要显示这个定位信息
//30:异常行驶状态
//30:异常行驶状态 客运车禁止行驶 0表示正常1表示报警
//31:异常行驶状态 山区禁行 0表示正常1表示报警

//uiStatus[3]
//0-2表示定位类型	0表示WSG_84（标准的GPS坐标体系），1表示GCJ-02（火星坐标），2表示BD09（百度坐标）
//3：紧急报警
//4：区域超速报警
//5：疲劳驾驶报警
//6：预警
//7：GNSS模块故障
//8：GNSS天线未接或者剪断
//9：GNSS天线短路
//10：终端LCD或者显示器故障
//11：TTS模块故障
//12：摄像头故障
//13：当天累计驾驶超时
//14：超时停车
//15：进区域
//16：进路线
//17：路段行驶时间不足或过长
//18：路线偏离报警
//19：车辆VSS故障
//20：车辆油量异常
//21：车辆被盗
//22：车辆非法点火
//23：车辆非法位移
//24：碰撞侧翻报警
//25：超时停车(平台产生)
//26：关键点未到达报警(平台产生)
//27：线路超速报警(平台产生) 
//28：线路低速报警(平台产生) 
//29: 道路超速报警(平台产生)
//30: 表示出区域报警	 （平台产生）
//31: 表示关键点未离开报警	  （平台产生）	


typedef struct _tagGPSVehicleGps
{
	GPSTime_S Time;
	unsigned int uiSpeed:14;	//速度值 KM/S	9999 = 999.9 	范围(0-16384)
	unsigned int uiYouLiang:18;	//油量   升	9999 = 99.99 	范围(0-262100)
	unsigned int uiLiCheng;		//里程   公里	9999 = 9.999 	
	unsigned int uiHangXiang:9;	//地面航向，(0-360) 范围(0-512)
	unsigned int uiMapType:3;	//地图类型		1表示GOOGLE，2表示百度，0表示无效
	unsigned int uiNetWorkType:4;	//网络类型(3G类,WIFI,有线,4G)
	unsigned int uiTachographSpeed:14;  //速度值 KM/S	9999 = 999.9 	范围(0-16384) 行驶记录仪速度
	unsigned int uiReserve:2;  //保留位1
	unsigned int uiStatus[4];		//目前只使用，每1个状态	0位表示GPS定位状态（0无效，1有效）
	short sTempSensor[4];	//温度传感器的状态
	int	nJingDu;		//经度	4字节 整数部分	9999999 = 9.999999 
	int nWeiDu;			//纬度	4字节 整数部分	9999999 = 9.999999
	short nGaoDu;			//高度，暂时未使用
	unsigned short usSatellites:4;		//卫星数，大于0时显示，范围0-12
	unsigned short usReserve:12;		//保留字段
	int	nParkTime;		//停车时长 秒	在静止状态时有效
	unsigned int uiLineID:29;			//线路号(数据库中关联)
	unsigned int uiDirection:1;			//方向 0-上行， 1-下行
	unsigned int uiStationFlag:1;		//（0-站点 1-站场）
	unsigned int uiStationStatus:1;		//0-本站 1-下一站

	unsigned int uiODBVotage:9;		//OBD电池电压			123   = 12.3V		0-512			
	unsigned int uiODBJQTemp:7;		//燃油进气温度			33 = 33度			0 - 127			
	unsigned int uiODBStatus:6;		//第0位表示ACC 開關	1 離合器開關  2	煞車開關  3	PTO 開關	4  緊急剎車	
	unsigned int uiODBJQMPos:10;	//节气门位置			102 = 10.2 %		0-1024			

	unsigned int uiOBDRpm:14;		//发动机转速			1000 = 1000转		0-16384			
	unsigned int uiOBDSpeed:8;		//ODB速度				99 = 99公里			(0-256)			
	unsigned int uiODBReserve:2;	//保留字段		
	unsigned int uiPeopleCur:8;		//当前车上人数		范围(0-256)

	unsigned int uiPeopleUp:12;		//上车人数		范围(0-4096)
	unsigned int uiPeopleDown:12;	//下车人数		范围(0-4096)
	unsigned int uiStationIndex:8;	//站点索引
}GPSVehicleGps_S;
//注意目前总长度为72个字节，每次改变结构体变量时，必须都sizeof(GPSVehicleGps_S)判断下，避免更改出错的问题

typedef struct _GPSVehicleState
{
	char	szDevIDNO[32];
	GPSVehicleGps_S	Gps;
}GPSVehicleState_S;

typedef struct _GPSVehicleStatus
{
	char	szDevIDNO[32];
	BOOL	bOnline;
	int		nNetworkType;
	char	szNetworkName[32];
}GPSVehicleStatus_S;

typedef struct _tagGPSAlarmInfo
{
	char	guid[36];			//标识唯一的报警信息
	GPSVehicleGps_S Gps;		//报警时候的GPS信息
	GPSTime_S Time;				//报警时间
	short 	AlarmType;			//报警类型
	short 	AlarmInfo;			//报警信息
	int	Param[4];				//报警参数
	char szDesc[256];			//报警描述
	//说明srcAlarmType和srcTime，当报警类型为报警图片上传完成时有效，表示对应的报警参数信息，图片上传完成报警类型
	//报警类型为图片上传报警时，只使用AlarmType和szImgFile参数，其它参数表示对应报警参数
	short srcAlarmType;			//源报警类型
	short sReserve;				//保留参数 (V6版本报警联动用到)
	GPSTime_S srcTime;			//源报警时间
	char szImgFile[256];		//图片文件信息，用;分隔，为http地址路径，可以为多个图片信息
	//报警开始类型
	short AlarmStartType;
	char bSendOnly;				//1表示只发送，用在报警回掉中，防止再次把报警放入插件中处理
	char cHandleStatus;			//处理标志位，0位：0表示未处理， 1表示已处理； 1位：0表示未确认， 1表示已确认
	char szReserve[60];			//保留字段
}GPSAlarmInfo_S, *LPGPSAlarmInfo_S;

typedef struct _GPSVehicleAlarm
{
	char	szDevIDNO[32];
	GPSAlarmInfo_S	Alarm;
}GPSVehicleAlarm_S;

//809查岗信息
typedef struct _tagCheckPost_S 
{
	GPSVehicleAlarm_S Alarm;
	char szContent[256];		//处理内容
	GPSTime_S tmEndTime;		//查岗处理时间
}CheckPost_S , *LPCheckPost_S ;

//hw 2014/1/23 
//-- begin
typedef struct _tagGPSAlarmInfoEx
{
	char	guid[36];			//标识唯一的报警信息
	GPSVehicleGps_S Gps;		//报警时候的GPS信息
	GPSTime_S Time;				//报警时间
	short 	AlarmType;			//报警类型
}GPSAlarmInfoEx_S, *LPGPSAlarmInfoEx_S;

typedef struct _tagGPSConfigData
{
	int nLength;		//数据缓存长度
	char cBuffer[1024];	//数据内容
}GPSConfigData_S, *LPGPSConfigData_S;

typedef struct _tagGPSTransPortData
{
	int nType;					//类型
	GPSConfigData_S	Data;		//透传数据
}GPSTransPortData_S, *LPGPSTransPortData_S;

//透传转换报警
typedef struct tagGPSAlarmTPD 
{
	char	szDevIDNO[32];
	GPSAlarmInfoEx_S VehiAlarm;
	GPSTransPortData_S TPD;	
}GPSAlarmTPD_S, *LPGPSAlarmTPD_S;
//-- end

//报警日志数目
typedef struct _tagGPSAlarmCount
{
	int nCount;
	char szReserve[8];
}GPSAlarmCount_S, *LPGPSAlarmCount_S;

//车辆轨迹(包含GPS和报警)
typedef struct _tagGPSVehicleTrack
{
	int nType;					//标识该数据类型(GPS数据或者报警数据)
	GPSVehicleAlarm_S Alarm;	//报警数据(如果类型为GPS数据 则只有GPS字段数据有效)
}GPSVehicleTrack_S, *LPGPSVehicleTrack_S;

//轨迹点数目
typedef struct _tagGPSTrackCount
{
	int nCount;
	char szReserve[8];
}GPSTrackCount_S, *LPGPSTrackCount_S;

//设备轨迹点信息
typedef struct _tagGPSDevTrackCountInfo
{
	char szDevIDNO[32];	//设备编号
	int nGPSValid;		//GPS有效(0-无效 1-有效)
	int nCount;			//数目
	char szReserve[8];
}GPSDevTrackCountInfo_S, *LPGPSDevTrackCountInfo_S;

//设备轨迹点数目
typedef struct _tagGPSTrackDevCount
{
	int nDevCount;					//设备数目
	GPSDevTrackCountInfo_S Info[8];	//最大8个设备轨迹信息
}GPSTrackDevCount_S, *LPGPSTrackDevCount_S;


typedef struct _tagGPSTrackInFenceInfo
{
	int		nVehiID;				//车辆ID
	GPSTime_S BeginTime;		//开始时间
	GPSTime_S EndTime;			//结束时间
	int		nStartJingDu;		//进入区域经度	4字节 整数部分	9999999 = 9.999999 
	int		nStartWeiDu;		//进入区域纬度	4字节 整数部分	9999999 = 9.999999
	int		nEndJingDu;			//离开区域经度	4字节 整数部分	9999999 = 9.999999 
	int		nEndWeiDu;			//离开区域纬度	4字节 整数部分	9999999 = 9.999999
	char szRes[32];				//保留32
}GPSTrackInFenceInfo_S, *LPGPSTrackInFenceInfo_S;

const int GPS_VEHICLE_ALARM_LENGTH = sizeof(GPSVehicleAlarm_S);
const int GPS_ALARM_INFO_LENGTH = sizeof(GPSAlarmInfo_S);
const int GPS_VHIECLE_GPS_LENGTH = sizeof(GPSVehicleGps_S);
const int GPS_VHIECLE_RUN_LENGTH = sizeof(GPSVehicleState_S);
const int GPS_VEHICLE_STATUS_LENGTH = sizeof(GPSVehicleStatus_S);
const int GPS_VEHICLE_TRACK_LENGTH = sizeof(GPSVehicleTrack_S);

//透明串口数据
typedef struct _tagGPSTranPortData
{
	int nID;
	char szDevIDNO[32];	//车机编号
	int nType;			//类型
	SYSTEMTIME Time;		//时间
	int	nLength;		//长度
	char cData[1280];	//数据长度
}GPSTranPortData_S, *LPGPSTranPortData_S;

//透明串口数据数目
typedef struct _tagGPSTranPortDataCount
{
	int nCount;
	char szReserve[8];
}GPSTranPortDataCount_S, *LPGPSTranPortDataCount_S;

const int GPS_TRAN_PORT_DATA_LENGTH = sizeof(GPSTranPortData_S);

#define GPS_WLAN_TYPE_2G					0
#define GPS_WLAN_TYPE_3G_EVDO				1
#define GPS_WLAN_TYPE_3G_WCDMA				2
#define GPS_WLAN_TYPE_TD_WCDMA				3
#define GPS_WLAN_TYPE_TD_LED				4
#define GPS_WLAN_TYPE_FDD					5

typedef struct _tagGPSWLanStatus
{
	int nWLanActive;	//
	int	nWLanType;		////0：表示2G;1：表示3G-EVDO; 2：表示3G-WCDMA 
	int nWLanQuantity;	//信号值	不显示
	char szWLanAddr[32];//网络地址
}GPSWLanStatus_S, *LPGPSWLanStatus_S;

typedef struct _tagGPSWifiStatus
{
	int nWifiActive;
	char szWifiAP[32];	//hide
	int nWifiQuantity;	//hide
	char szWifiAddr[32];//
}GPSWifiStatus_S, *LPGPSWifiStatus_S;

typedef struct _tagGPSDiskInfo
{
//	int nAllVolume;		//15923	表示159.23	G //总容量
	int nAllVolume:24;	//15923	表示159.23	G //总容量
	int nDiskType:8;	//硬盘类型
	int nLeftVolume;	//同上  ///剩余容量
}GPSDiskInfo_S, *LPGPSDiskInfo_S;

const int GPS_DISK_INFO_COUNT			= 8;	//最多硬盘数目为8个

typedef struct _tagGPSDeviceStatus
{
	//硬盘序列号, 以 | 分隔，共有硬盘数目序列号			
		//DevInfo.sSerialNumber、DevInfo.szDevID用于存储硬盘序列号
	GPSDeviceInfo_S	DevInfo;	//设备信息
	GPSWLanStatus_S	WLanInfo;	//3G状态
	GPSWifiStatus_S	WifiInfo;	//WIFI信息
	GPSDiskInfo_S	DiskInfo[GPS_DISK_INFO_COUNT];	//硬盘信息
	int	nVideoLost;		//视频丢失状态  1表示该视频丢失
	int nRecord;		//录像状态 0：没有录像，1录像
	int nVideoTran;		//视频传输数目
	long l3GFlow;		//KB为单位，从月结日开始算，累加
	long l4GFlow;		//KB为单位，从月结日开始算，累加
	char cDiskNum;		//硬盘数目
	char cNetType;		//网络类型	0,3g,1 wifi, 2 net, 3 4g
	char cVersion;		//为1时，cNetType有效  devinfo里面的cPlateNumber为imei信息
	char cReserve;	//保留参数
	int nReserve;	//保留参数
}GPSDeviceStatus_S, *LPGPSDeviceStatus_S;

const int GPS_MOTION_MASK = 9;

typedef struct _tagGPSMotionParam
{
	int	nMask[GPS_MOTION_MASK];	//低11位表示移动侦测
	BOOL bEnable;	//是否启用
	int	nSensitive;	//灵敏度
}GPSMotionParam_S, *LPGPSMotionParam_S;

typedef struct _tagGPSVideoColor
{
	int nExposure;		//爆光度
	int	nBrightness;	
	int	nConstract;	
	int	nHue;				
	int	nSaturate;			 
}GPSVideoColor_S, *LPGPSVideoColor_S;

//////////////////////////////////////////////////////////////////////////
//hw 2012-11-07
//网络流量参数
typedef struct _tagGPSNetFlowParam
{
	int nIsOpenFlowCount;		//流量统计开关 0-关闭，1-开启
	int nIsOpenDayFlowRemind;	//日流量提醒 0-不提醒 1-提醒
	int nIsOpenMonthFlwRemind;	//月流量提醒 0-不提醒 1-提醒
	float fDayLimit;			//日流量限制(MB)
	float fMonthLimit;			//月流量限制(MB)
	int nDayRemind;				//每天流量提醒（百分比），20%即20
	int nMonthRemind;			//每月流量提醒（百分比），20%即20
	int nMonthTotleDay;			//月结日
	char szRes[32];				//保留32
}GPSNetFlowParam_S, *LPGPSNetFlowParam_S;

//网络流量统计
typedef struct _tagGPSNetFlowStatistics
{
	GPSNetFlowParam_S	FlowParam;	//流量参数
	float fFlowUsedToday;			//今日流量
	float fFlowUsedMonth;			//本月已使用流量
	int nStatisticsTime;			//统计时间
	char szRes[32];					//保留32
}GPSNetFlowStatistics_S, *LPGPSNetFlowStatistics_S;	
//end
//////////////////////////////////////////////////////////////////////////

//调度指令
typedef struct _tabGPSDispatchCommand
{
	char szGuid[40];		//指令GUID
	int nMapType;			//目的地，地图类型，1表示GOOGLE，2表示百度
	int nJingDu;			//经度
	int nWeiDu;				//纬度
	char szCommand[256];	//命令字
}GPSDispatchCommand_S, *LPGPSDispatchCommand_S;


typedef union _tagUNCfg
{
// 	HI_S_Video cfgVideo;				/* 视频参数 */
// 	HI_S_Audio cfgAudio;				/* 音频参数 */
// 	HI_E_AudioInput cfgAudioInput;		/* 音频输入参数 */
// 	HI_S_PTZ cfgPTZ;					/* 云台参数 */
}GPSCfg, *LPGPSCfg;

//文件信息
typedef struct _tagGPSRecHead_S
{
	int	nYear;			//年	2013
	int	nMonth;			//月	5
	int nDay;			//日	29
	int nBegHour;		//开始时间
	int nBegMinute;		
	int nBegSecond;
	unsigned __int64 u64BegPts;	//文件起始的时间戳
	unsigned int uiTotalMinSecond;	//文件总时长，毫秒
	unsigned int uiAudioCodec;		//音频解码器类型	TTX_AUDIO_CODEC_G726_40KBPS
	unsigned int uiAudioChannel;		//音频通道
	unsigned int uiAudioSamplesPerSec;	//音频采样率
	unsigned int uiAudioBitPerSamples;	//音频每个取样所需的位元数
	unsigned int uiInfoCodec;		//信息帧解码器	TTX_INFO_CODEC_WKP
	unsigned int uiVideoCodec;		//视频帧解码器	TTX_VIDEO_CODEC_H264
	unsigned char ucResolution;		//分辨率		TTX_RESOLUTION_720P
	char szReserve[59];		//保留字段
} GPSRecHead_S, *LPGPSRecHead_S;

typedef struct _tagGPSUsrLog
{
	int nUsrID;
	int nMainType;
	int nSubType;
	char szDevIDNO[40];
	char szParam1[256];
	char szParam2[256];
	char szParam3[256];
	char szParam4[256];
	GPSTime_S time;
	char szReserve[64];
}GPSUsrLog_S, *LPGPSUsrLog_S;

//用户基本信息
typedef struct _tagUserBasicInfo
{
	int nUserID;				//用户ID		
	char szUserName[32];		//用户名称
	int nGroupID;				//分组ID
	char cOnline;				//在线状态
	char szReserve[27];			//保留32
}UserBasicInfo_S, *LPUserBasicInfo_S;


//用户日志数目
typedef struct _tagGPSUsrLogCount
{
	int nCount;
	char szReserve[8];
}GPSUsrLogCount_S, *LPGPSUsrLogCount_S;


//联系人
typedef struct _tagContactInfo
{
	char szName[32];			//姓名
	char szPhone[16];			//手机
	char szTel[16];				//电话
	char szReserve[16];			//保留16
}ContactInfo_S, *LPContactInfo_S;

//学生信息
typedef struct _tagStudentInfo
{
	char szCarNum[32];			//卡号
	char szName[32];			//学生姓名
	int nStudySection;			//0-未知 1-幼儿园 2-小学 3-初中 4-高中 5-大学
	int nGrade;					//0-未知，1-1年级，2-2年级
	int nClass;					//0-未知，1-1班 2-2班
	ContactInfo_S Contact1;		//联系人1
	ContactInfo_S Contact2;		//联系人2
	char szEmail[64];			//email
	char szAddress[256];		//地址
	char szRemark[256];			//备注
	char szReserve[256];		//保留256
}StudentInfo_S, *LPStudentInfo_S;


typedef struct _tagDeviceDevIPInfo
{
	GPSDeviceIDNO_S DevIDNO;
	int nPort;
	char szIP[16];
	char szReserve[16];
}DeviceDevIPInfo_S, *LPDeviceDevIPInfo_S;


typedef struct _tagGPSPictureDataInfo
{
	unsigned char cDataPackIndex;		//图像数据是第N个包
	unsigned char cChannel;				//通道号0 开始
	unsigned char cPictureIndex;		//表示图片序号,范围：0~8
	unsigned char cStatus;				//主机状态:0x01 表示劫警，0x02表示自定义高，0x03表示自定义低，0x04表示定时回传图像，0x05表示捕捉图像回传
	unsigned char cCountPack;			//总包数
	char nResult;						//结果 0：成功/确认；1：失败；2：消息有误；3：不支持；4：报警确认处理
	char bMediaFinished;				//是否完成
	char cReserve;						//保留
}GPSPictureDataInfo_S, *LPGPSPictureDataInfo_S;

//设备要下载的文件信息
typedef struct _tagGPSDownFileInfo
{
	int nFileType;		//文件类型，1图片文件，2表示升级文件
	char szParam[256];	//中间使用逗号(,)分隔
	int nFileID;		//文件ID
	char szFile[256];	//文件路径
	char szIP[64];		//服务器IP
	unsigned short usPort;	//端口
	unsigned short usReserve;
	char szMd5[40];		//MD5校验
	char szReserve[32];	//保留参数
}GPSDownFileInfo_S;

//JT808媒体数据
typedef struct _tagGPSMediaDataInfo
{
	unsigned int uiMediaID;				//媒体ID
	unsigned char ucMediaType;			//媒体类型 0-图片;1-音频;2-视频
	unsigned char ucCodeFormat;			//编码格式 0-JPEG;1-TIF;2-MP3;3-WAV;4-WMV	
	unsigned char ucEventType;			//事件项 0-平台下发指令;1-定时动作;2-抢劫报警触发;4-碰撞侧翻报警触发;其他保留
	unsigned char ucChannel;			//通道ID
	unsigned short usTotal;				//总包数
	unsigned short usIndex;				//包序号，从1开始
	char nReserve[32];					//保留
}GPSMediaDataInfo_S, *LPGPSMediaDataInfo_S;

typedef struct _tagGPS808TerminalInfo
{
	unsigned short	usProvince;		//省际ID
	unsigned short  usCity;			//市际ID
	char szFactory[12];				//制造商编码
	char szTerminalType[24];		//终端型号
	char szTerminalID[24];			//终端ID
	unsigned char  ucPlateColor;	//车牌颜色
	char szPlate[31];				//车牌号
	char cRegisterFlag;				//注册标志位
	char szFactoryAsc[11];			//制造商ASC
	char szReserve[52];				//保留参数
}GPS808TerminalInfo_S, *LPGPS808TerminalInfo_S;


//设备报警录像报警类型定义
typedef enum
{
	FILE_ALARM_INFO_URGENCY_BUTTON  =0 ,		//紧急按钮报警
	FILE_ALARM_INFO_OVERSPEED 		=1 ,		//超速报警
	FILE_ALARM_INFO_LOWSPEED 		=2 ,		//低速报警
	FILE_ALARM_INFO_SHARK			=3 ,		//振动报警
	FILE_ALARM_INFO_TEMPERATOR 		=4 ,		//温度报警
	FILE_ALARM_INFO_TMOTION			=5 ,		//移动侦测报警
	FILE_ALARM_INFO_UPS_CUT			=6 ,		//UPS剪断报警
	FILE_ALARM_INFO_COLLISION		=7 ,		//碰撞侧翻
	FILE_ALARM_INFO_FATIGUE			=8 ,		//疲劳驾驶
	FILE_ALARM_INFO_IO1				=9 ,		//IO1报警
	FILE_ALARM_INFO_IO2				=10, 		//IO2报警
	FILE_ALARM_INFO_IO3				=11,		//IO3报警
	FILE_ALARM_INFO_IO4				=12, 		//IO4报警
	FILE_ALARM_INFO_IO5				=13, 		//IO5报警
	FILE_ALARM_INFO_IO6				=14, 		//IO6报警
	FILE_ALARM_INFO_IO7				=15, 		//IO7报警
	FILE_ALARM_INFO_IO8				=16, 		//IO8报警
	FILE_ALARM_INFO_RAPID_ACCELERATION =17,		//急加速告警 华宝定制
	FILE_ALARM_INFO_RAPID_DECELERATION =18,		//急减速告警 华宝定制
	FILE_ALARM_INFO_REVERSING		 =19,		//倒车告警 华宝定制
	FILE_ALARM_INFO_CUS_OVER_SPEED	 =20,		//超速告警 华宝定制
}GPS_ALARM_REC_TYPE_E;


//报站信息
const char REPORT_FALG_GPS = 0;			//GPS
const char REPORT_FALG_STATION = 1;		//站点
typedef struct _tagGPSStation_S
{
	GPSTime_S	Time;						//报站时间
	GPSVehicleGps_S	Gps;					//GPS位置
	char szJobNum[32];						//司机工号
	char szLineName[32];					//线路名称
	unsigned short usReportType;			//上报类型(0-GPS 1-过站)
// 	char szStationName[32];					//站点名称 最长20个字节的字符
	unsigned short uiLimitSpeed;			//限速 （为0则无效）
	char cSendOnly;							//只发送不存储
	unsigned char cReserve[31];				//保留字段
}GPSStation_S, *LPGPSStation_S;

typedef struct _tagGPSVehicleStation_S
{
	char szDevIDNO[32];
	GPSStation_S Station;
}GPSVehicleStation_S, *LPGPSVehicleStation_S;

//设备扩展数据
#define  GPS_EXDATA_TYPE_808_ALARM  1

typedef struct _tagGPSVehicleStateExData
{
	char szDevIDNO[32];
	GPSTime_S Time;
	int nDataType;
	char cData[512];
}GPSVehicleStateExData_S;

typedef struct _tagGPSVehicleStateAlarmParam
{
	int nParam[4];
}GPSVehicleStateAlarmParam_S;


//第0位 区域超速报警
//第1位 进出线路报警
//第2位 路段行驶时间不足/过长报警
//第3位 异常行驶报警:客运车禁止行驶
//第4位 异常行驶报警：山区禁行
typedef struct _tagGPSVehicleStateExDataAlarm
{
	int nAlarmFlag;								//报警标志位
	GPSVehicleStateAlarmParam_S ArmParam[16];		//报警参数
}GPSVehicleStateExDataAlarm_S;


const int GPS_VHIECLE_STATE_EXDATA_LENGTH = sizeof(GPSVehicleStateExData_S);

#pragma pack()

#endif	
