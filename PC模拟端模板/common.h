#ifndef __COMMON_H
#define __COMMON_H

#include <graphics.h>
//**************************�������********************************************
#define  COM_BAUD			9600						//������ 
#define	 COM_PORT			3							//�˿ں� 
#define  COM_BITS			8							//����λ 
#define  COM_STOPBITS		1 							//ֹͣλ 
#define	 COM_PARITY			0							//��żУ��λ 

#define  COM_TIME			5							//����ͨ��ʱ��������λms 
#define	 COM_BUF_SIZE		20							//���ڷ��ͻ������ڴ� 
#define	 DATA_OCT			10							//ʮ���� 

#define Soft_command_beging        	'%'                	//ָ�ʼ 
#define Soft_command_end           	'$'                	//ָ����� 
#define	Soft_command_return			'\0'				//ָ��� 
//**************************�������******************************************** 
#define ROAD_IMAGE			"Image/road1.png"			//��������ͼ
#define CAR_IMAGE  			"Image/Car.png"				//����ͼ 
#define CAR_OUTLINE_IMAGE	"Image/Car0.png"			//��������ͼ 
#define OBSTACLE_IMAGE		"Image/Car2.png"			//�ϰ�����ͼ 
#define OBSTACLE_OUTLINE_IMAGE "Image/Car01.png"		//�ϰ���������ͼ 

#define BACKGROUD			RGB(255, 255, 255)			//����ɫ 
#define ROAD_WIDTH			350							//·�� 
#define ROAD_HEIGHT			600							//·�� 
#define CAR_WIDTH			98							//������� 
#define CAR_HEIGHT			180							//�������� 
#define SPEED				16.6						//��֡60֡,1000ms/60=16.6..

#define ROAD_TYPE_0			0							//��·0 
#define ROAD_TYPE_1			1							//��·1 
#define ROAD_TYPE_2			2							//��·2 
#define ROAD_TYPE_0_X		10							//��·0�У�����X���� 
#define ROAD_TYPE_1_X		130							//��·1�У�����X����
#define ROAD_TYPE_2_X		240							//��·2�У�����X����

//*********************����_ROAD******************************* 
#define ROAD_INITIAL_POSITION_X		0					//������ʼ��x���� 
#define ROAD_INITIAL_POSITION_Y		610					//������ʼ��y���� 
#define ROAD_SPEED_INITIAL			0					//�����ƶ��ٶȳ�ʼֵ 
#define ROAD_SPEED					5					//�����ƶ��ٶ� 
//************************************************************* 

//*********************����_CAR******************************** 
#define CAR_INITIAL_POSITION_Y		420					//С����ʼλ��y
#define CAR_INITIAL_SPEED			10					//С����ʼ�ٶ� 

//*****************�ϰ�����_OBSTACLE**************************** 
#define OBSTACLE_INITIAL_POSITION_Y		-100			//�ϰ�������ʼλ��y
#define OBSTACLE_RESET_POSITION_Y		610				//�ϰ���������λ��y
#define OBSTACLE_INITIAL_SPEED			9				//�ϰ�������ʼ�ٶ� 

struct Car;												//ǰ������ 

struct object {
	IMAGE image;										//�����Ӧ��ͼƬ
	int x;												//�����Ӧ��x���� 
	int y;												//�����Ӧ��y���� 
	int speed;											//�����Ӧ���ٶ�  
	
	void (*pInitial) (struct object *);					//��ʼ������
	void (*pDraw) (struct object *);					//����ͼ��
	boolean (*pCollision) (struct Car *, struct Car *);	//��ײ���
	void (*pSendData) (struct Car *pObstacle);			//�����ϰ�������	
	void (*pRecData) (struct Car *pCar);				//���տ��Ƴ�״̬ 
}; 

struct Car {
	IMAGE image;										//�����Ӧ��ͼƬ
	IMAGE image_outline;								//��Ӧ���Ӧ������ 
	int x;												//�����Ӧ��x���� 
	int y;												//�����Ӧ��y���� 
	int speed;											//�����Ӧ���ٶ�
	int roadType;										//���ڹ�· 
	
	void (*pInitial) (struct Car *);					//��ʼ������
	void (*pDraw) (struct Car *);						//����ͼ��
	void (*pMove) (struct Car *, struct Car *);			//С���˶� 
}; 

extern struct object road;
extern struct Car car;
extern struct Car obstacle;

extern char sendBuff[COM_BUF_SIZE];
extern char recBuff[COM_BUF_SIZE];

#endif 
