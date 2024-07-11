#ifndef __COMMON_H
#define __COMMON_H

#include <graphics.h>
//**************************串口相关********************************************
#define  COM_BAUD			9600						//波特率 
#define	 COM_PORT			3							//端口号 
#define  COM_BITS			8							//数据位 
#define  COM_STOPBITS		1 							//停止位 
#define	 COM_PARITY			0							//奇偶校验位 

#define  COM_TIME			5							//串口通信时间间隔，单位ms 
#define	 COM_BUF_SIZE		20							//串口发送缓冲区内存 
#define	 DATA_OCT			10							//十进制 

#define Soft_command_beging        	'%'                	//指令开始 
#define Soft_command_end           	'$'                	//指令结束 
#define	Soft_command_return			'\0'				//指令换行 
//**************************汽车相关******************************************** 
#define ROAD_IMAGE			"Image/road1.png"			//赛道背景图
#define CAR_IMAGE  			"Image/Car.png"				//汽车图 
#define CAR_OUTLINE_IMAGE	"Image/Car0.png"			//汽车轮廓图 
#define OBSTACLE_IMAGE		"Image/Car2.png"			//障碍汽车图 
#define OBSTACLE_OUTLINE_IMAGE "Image/Car01.png"		//障碍汽车轮廓图 

#define BACKGROUD			RGB(255, 255, 255)			//背景色 
#define ROAD_WIDTH			350							//路宽 
#define ROAD_HEIGHT			600							//路长 
#define CAR_WIDTH			98							//汽车宽度 
#define CAR_HEIGHT			180							//汽车长度 
#define SPEED				16.6						//锁帧60帧,1000ms/60=16.6..

#define ROAD_TYPE_0			0							//道路0 
#define ROAD_TYPE_1			1							//道路1 
#define ROAD_TYPE_2			2							//道路2 
#define ROAD_TYPE_0_X		10							//道路0中，车的X坐标 
#define ROAD_TYPE_1_X		130							//道路1中，车的X坐标
#define ROAD_TYPE_2_X		240							//道路2中，车的X坐标

//*********************赛道_ROAD******************************* 
#define ROAD_INITIAL_POSITION_X		0					//赛道初始化x坐标 
#define ROAD_INITIAL_POSITION_Y		610					//赛道初始化y坐标 
#define ROAD_SPEED_INITIAL			0					//赛道移动速度初始值 
#define ROAD_SPEED					5					//赛道移动速度 
//************************************************************* 

//*********************汽车_CAR******************************** 
#define CAR_INITIAL_POSITION_Y		420					//小车初始位置y
#define CAR_INITIAL_SPEED			10					//小车初始速度 

//*****************障碍汽车_OBSTACLE**************************** 
#define OBSTACLE_INITIAL_POSITION_Y		-100			//障碍汽车初始位置y
#define OBSTACLE_RESET_POSITION_Y		610				//障碍汽车重置位置y
#define OBSTACLE_INITIAL_SPEED			9				//障碍汽车初始速度 

struct Car;												//前置声明 

struct object {
	IMAGE image;										//对象对应的图片
	int x;												//对象对应的x坐标 
	int y;												//对象对应的y坐标 
	int speed;											//对象对应的速度  
	
	void (*pInitial) (struct object *);					//初始化对象
	void (*pDraw) (struct object *);					//绘制图像
	boolean (*pCollision) (struct Car *, struct Car *);	//碰撞检测
	void (*pSendData) (struct Car *pObstacle);			//发送障碍车数据	
	void (*pRecData) (struct Car *pCar);				//接收控制车状态 
}; 

struct Car {
	IMAGE image;										//对象对应的图片
	IMAGE image_outline;								//对应相对应的轮廓 
	int x;												//对象对应的x坐标 
	int y;												//对象对应的y坐标 
	int speed;											//对象对应的速度
	int roadType;										//所在公路 
	
	void (*pInitial) (struct Car *);					//初始化对象
	void (*pDraw) (struct Car *);						//绘制图像
	void (*pMove) (struct Car *, struct Car *);			//小车运动 
}; 

extern struct object road;
extern struct Car car;
extern struct Car obstacle;

extern char sendBuff[COM_BUF_SIZE];
extern char recBuff[COM_BUF_SIZE];

#endif 
