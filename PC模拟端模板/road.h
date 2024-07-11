#ifndef __ROAD_H
#define __ROAD_H

#include "common.h"

void initialRoad(struct object * pRoad);										//初始化对象
void drawRoad(struct object * pRoad);											//绘制图像
boolean collision(struct Car * pCar, struct Car *pObstacle);					//判断是否碰撞 
void changeRoadType(struct Car *pCar);											//改变赛道 
boolean isPointInRect(int x, int y, int x1, int y1, int width, int height);		//判断点是否在矩形范围内 
void sendData(struct Car *pObstacle);											//发送障碍车数据 
void recData(struct Car *pCar);													//接收控制车指令 

#endif 
