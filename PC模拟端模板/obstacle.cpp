#include "Obstacle.h"
#include "common.h"
#include "road.h"

struct Car obstacle={
	image 			: 	NULL,
	image_outline 	: 	NULL, 
	x 				: 	ROAD_TYPE_0_X,
	y 				: 	OBSTACLE_INITIAL_POSITION_Y,
	speed 			: 	OBSTACLE_INITIAL_SPEED,
	roadType 		: 	ROAD_TYPE_0, 
	pInitial 		: 	initialObstacle,
	pDraw 			: 	drawObstacle,
	pMove 			: 	obstacleMove 
};

void initialObstacle(struct Car * pObstacle)
{
	loadimage(&pObstacle->image, OBSTACLE_IMAGE);						//¼ÓÔØÍ¼Ïñ
	loadimage(&pObstacle->image_outline, OBSTACLE_OUTLINE_IMAGE);		//¼ÓÔØÍ¼Ïñ
	pObstacle->x = ROAD_TYPE_0_X;
	pObstacle->y = OBSTACLE_INITIAL_POSITION_Y;
	pObstacle->speed = OBSTACLE_INITIAL_SPEED;
	pObstacle->roadType = ROAD_TYPE_0;
}

void drawObstacle(struct Car * pObstacle)
{
	putimage(pObstacle->x, pObstacle->y, &pObstacle->image_outline, NOTSRCERASE);
	putimage(pObstacle->x, pObstacle->y, &pObstacle->image, SRCINVERT);
}

void obstacleMove(struct Car * pCar, struct Car *pObstacle)
{
	int speed = pCar->speed - pObstacle->speed;			//¼ÆËãËÙ¶È²î 
	pObstacle->y += speed;
	
	if(pObstacle->y > OBSTACLE_RESET_POSITION_Y) {
		pObstacle->y = OBSTACLE_INITIAL_POSITION_Y;
		pObstacle->roadType = rand() % 3;
		changeRoadType(pObstacle);
	}
}
