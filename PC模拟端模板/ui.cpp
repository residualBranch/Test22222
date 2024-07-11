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
	BeginBatchDraw();									//��ʼ���� 
	road.pInitial(&road);								//��ʼ����·
	car.pInitial(&car);									//��ʼ������ 
	//ѧ���������						//��ʼ���ϰ����� 
}

void drawUI()
{
	cleardevice();										//����豸 
	 
	road.pDraw(&road);									//���ƹ�· 
	car.pDraw(&car);									//�������� 
	//ѧ���������    						//�����ϰ�����
	 
	//ѧ���������					       //�ϰ������˶�
	road.pSendData(&obstacle);				 			//����ͨ�����ݽ��� 
	
	if(road.pCollision(&car, &obstacle)) {				//�ж�������ײ 
		setlinecolor(RGB(255, 0, 0));
		rectangle(obstacle.x, obstacle.y, 
					obstacle.x + CAR_WIDTH, obstacle.y + CAR_HEIGHT);
		setlinecolor(RGB(0, 255, 0));
		rectangle(car.x, car.y, car.x + CAR_WIDTH, car.y + CAR_HEIGHT);
		FlushBatchDraw();
		system("pause");
		initialUI();									//reset ���¿�ʼ 
	} 
		
	FlushBatchDraw();									//ˢ���豸 
	Sleep(m_ui.speed);									//�����ƶ��ٶ� 
}
