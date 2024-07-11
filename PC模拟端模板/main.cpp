#include <stdio.h>
#include <stdlib.h>
#include "serial.h"			//串口 
#include <pthread.h>		//多线程 
#include "common.h"
#include "ui.h"

int main()
{
	
	pthread_t th1;			//创建串口通信子线程 
	pthread_create(&th1, NULL, serial_test, NULL);
	
	m_ui.pInitial();		//UI初始化 
	
	while(1)
	{
		m_ui.pDrawUI();		//UI绘制 
	}
	
	return 0;
}
