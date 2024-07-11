#ifndef __OBSTACLE_H
#define __OBSTACLE_H

#include "common.h"

void initialObstacle(struct Car * pObstacle);							//初始化对象
void drawObstacle(struct Car * pObstacle);								//绘制图像 
void obstacleMove(struct Car * pCar, struct Car *pObstacle);			//小车运动 

#endif 
