#ifndef __UI_H
#define __UI_H

#include "common.h"

struct ui {
	int speed; 
	void (*pInitial)();
	void (*pDrawUI)(); 
};

extern struct ui m_ui;

void initialUI();
void drawUI();

#endif
