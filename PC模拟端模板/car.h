#ifndef __CAR_H
#define __CAR_H

#include "common.h"

void initialCar(struct Car * pCar);							//��ʼ������
void drawCar(struct Car * pCar);							//����ͼ�� 
void carMove(struct Car * pCar, struct Car *pObstacle);		//С���˶� 

#endif 
