#include "common.h"
#include "road.h"

struct object road = {
	image      : 	NULL,
	x 	       : 	ROAD_INITIAL_POSITION_X,
	y          : 	ROAD_INITIAL_POSITION_Y,
	speed      : 	ROAD_SPEED_INITIAL,
	pInitial   : 	initialRoad, 
	pDraw      : 	drawRoad,
	pCollision : 	collision,
	pSendData  :	sendData,
	pRecData   :	recData
};

void initialRoad(struct object * pRoad)		//初始化对象
{
	loadimage(&pRoad->image, ROAD_IMAGE);		//加载图像 
	pRoad->x = ROAD_INITIAL_POSITION_X;
	pRoad->y = ROAD_INITIAL_POSITION_Y;
	pRoad->speed = ROAD_SPEED_INITIAL;
}

void drawRoad(struct object * pRoad)			//绘制图像 
{
	//移动背景图
	if (pRoad->speed < ROAD_INITIAL_POSITION_Y) {
		pRoad->speed += ROAD_SPEED;
	} else {
		pRoad->speed = ROAD_SPEED_INITIAL;
	}
		
	putimage(pRoad->x, pRoad->speed, &pRoad->image);
	putimage(pRoad->x, pRoad->speed - pRoad->y, &pRoad->image);
}

void changeRoadType(struct Car *pCar)
{
	switch(pCar->roadType)
	{
	case ROAD_TYPE_0:
		pCar->x = ROAD_TYPE_0_X;
		break;
	case ROAD_TYPE_1:
		pCar->x = ROAD_TYPE_1_X;
		break;
	case ROAD_TYPE_2:
		pCar->x = ROAD_TYPE_2_X;
		break;
	default:
		break;			
	}
}

boolean collision(struct Car * pCar, struct Car *pObstacle)
{
	//判断左上角
	if (isPointInRect(pCar->x, pCar->y, 
		pObstacle->x, pObstacle->y, CAR_WIDTH, CAR_HEIGHT)) {
		return TRUE;
	}
	
	//判断右上角
	//学生补充
	
	//判断左下角 
	//学生补充
	
	//判断右下角 
	//学生补充		
	
	return FALSE;				
}

boolean isPointInRect(int x, int y, int x1, int y1, int width, int height)
{
	if((x >= x1) && (x <= x1 + width) && 
		(y >= y1) && (y <= y1 + height)){
		return TRUE;
	} else {
		return FALSE;
	}
}

void sendData(struct Car *pObstacle)
{
	//串口发送帧设置:
	//学生重新自定义
	//0-2byte-障碍车x坐标，3byte-结束符\0 
	//4-6byte-障碍车y坐标，7byte-结束符\0  
	sendBuff[0]	= Soft_command_beging;
	itoa(pObstacle->x, &sendBuff[1], DATA_OCT);
	sendBuff[4]	= Soft_command_return;
	itoa(pObstacle->y, &sendBuff[5], DATA_OCT);	
	sendBuff[8]	= Soft_command_end;
}

void recData(struct Car *pCar)
{
	//串口接收帧设置:
                //学生重新自定义
	//0-2byte-汽车x坐标，3byte-结束符\0 
	//4-6byte-汽车y坐标，7byte-结束符\0 
	
	if(recBuff[0] == Soft_command_beging)
	{
		pCar->x = atoi(&recBuff[1]); 
		pCar->y = atoi(&recBuff[5]);
	}
	 
}
 
