#ifndef __CAR_H
#define __CAR_H

#include "common.h"

void initialCar(struct Car * pCar);							//初始化对象
void drawCar(struct Car * pCar);							//绘制图像 
void carMove(struct Car * pCar, struct Car *pObstacle);		//小车运动 

#endif 
