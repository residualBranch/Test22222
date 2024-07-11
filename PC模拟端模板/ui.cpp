#include "ui.h"
#include <stdlib.h> 

struct ui m_ui={
	speed : SPEED,
	pInitial : initialUI,
	pDrawUI : drawUI
};

void initialUI()
{
	initgraph(ROAD_WIDTH, ROAD_HEIGHT);
	setbkcolor(BACKGROUD);
	BeginBatchDraw();									//开始绘制 
	road.pInitial(&road);								//初始化公路
	car.pInitial(&car);									//初始化汽车 
	//学生补充代码						//初始化障碍汽车 
}

void drawUI()
{
	cleardevice();										//清空设备 
	 
	road.pDraw(&road);									//绘制公路 
	car.pDraw(&car);									//绘制汽车 
	//学生补充代码    						//绘制障碍汽车
	 
	//学生补充代码					       //障碍汽车运动
	road.pSendData(&obstacle);				 			//串口通信数据交换 
	
	if(road.pCollision(&car, &obstacle)) {				//判断汽车碰撞 
		setlinecolor(RGB(255, 0, 0));
		rectangle(obstacle.x, obstacle.y, 
					obstacle.x + CAR_WIDTH, obstacle.y + CAR_HEIGHT);
		setlinecolor(RGB(0, 255, 0));
		rectangle(car.x, car.y, car.x + CAR_WIDTH, car.y + CAR_HEIGHT);
		FlushBatchDraw();
		system("pause");
		initialUI();									//reset 重新开始 
	} 
		
	FlushBatchDraw();									//刷新设备 
	Sleep(m_ui.speed);									//控制移动速度 
}
