#include <stdio.h>
#include <stdlib.h>
#include "serial.h"			//���� 
#include <pthread.h>		//���߳� 
#include "common.h"
#include "ui.h"

int main()
{
	
	pthread_t th1;			//��������ͨ�����߳� 
	pthread_create(&th1, NULL, serial_test, NULL);
	
	m_ui.pInitial();		//UI��ʼ�� 
	
	while(1)
	{
		m_ui.pDrawUI();		//UI���� 
	}
	
	return 0;
}
