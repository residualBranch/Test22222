#ifndef __OBSTACLE_H
#define __OBSTACLE_H

#include "common.h"

void initialObstacle(struct Car * pObstacle);							//��ʼ������
void drawObstacle(struct Car * pObstacle);								//����ͼ�� 
void obstacleMove(struct Car * pCar, struct Car *pObstacle);			//С���˶� 

#endif 
