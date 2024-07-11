#include "Car.h"
#include "common.h"

struct Car car={
	image 			: 	NULL,
	image_outline 	: 	NULL, 
	x 				: 	ROAD_TYPE_1_X,
	y 				: 	CAR_INITIAL_POSITION_Y,
	speed 			: 	CAR_INITIAL_SPEED,
	roadType 		: 	ROAD_TYPE_1, 
	pInitial 		: 	initialCar,
	pDraw 			: 	drawCar,
	pMove 			: 	carMove
};

void initialCar(struct Car * pCar)
{
	loadimage(&pCar->image, CAR_IMAGE);						//¼ÓÔØÍ¼Ïñ
	loadimage(&pCar->image_outline, CAR_OUTLINE_IMAGE);		//¼ÓÔØÍ¼Ïñ
	pCar->x = ROAD_TYPE_1_X;
	pCar->y = CAR_INITIAL_POSITION_Y;
	pCar->speed = CAR_INITIAL_SPEED;
	pCar->roadType = ROAD_TYPE_1;
}

void drawCar(struct Car *pCar)
{
	putimage(pCar->x, pCar->y, &pCar->image_outline, NOTSRCERASE);
	putimage(pCar->x, pCar->y, &pCar->image, SRCINVERT);
}

void carMove(struct Car * pCar, struct Car *pObstacle)
{
	//int speed = pObstacle->speed - pCar->speed;			//¼ÆËãËÙ¶È²î 
	//pObstacle->y += speed;
}

void CarPos(struct Car *car)
{
/*	 switch(car->road_type)
	{
		case ROAD_TYPE_0:
			car->x = CAR_X_POSITION_ROAD_TYPE_0; 
			break;
		case ROAD_TYPE_1:
			car->x = CAR_X_POSITION_ROAD_TYPE_1;
			break;
		case ROAD_TYPE_2:
			car->x = CAR_X_POSITION_ROAD_TYPE_2;
			break;
		default:
			break;		
	}
	*/
}
