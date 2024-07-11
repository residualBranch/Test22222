#ifndef __ROAD_H
#define __ROAD_H

#include "common.h"

void initialRoad(struct object * pRoad);										//��ʼ������
void drawRoad(struct object * pRoad);											//����ͼ��
boolean collision(struct Car * pCar, struct Car *pObstacle);					//�ж��Ƿ���ײ 
void changeRoadType(struct Car *pCar);											//�ı����� 
boolean isPointInRect(int x, int y, int x1, int y1, int width, int height);		//�жϵ��Ƿ��ھ��η�Χ�� 
void sendData(struct Car *pObstacle);											//�����ϰ������� 
void recData(struct Car *pCar);													//���տ��Ƴ�ָ�� 

#endif 
