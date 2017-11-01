/*
 * Touch.h
 *
 *  Created on: Nov 1, 2017
 *      Author: robert
 */

#ifndef TOUCH_H_
#define TOUCH_H_

#include <iostream>
#include "../inc/GUI.h"

struct Touch
{
	int x,y;
	std::string id;
	int event;
	int previous_event;
	int screen;
};

int main_touch(Touch touch);
int Screen0_callback(Touch touch);
int Screen1_callback(Touch touch);
int Screen2_callback(Touch touch);
int Screen3_callback(Touch touch);
int Screen4_callback(Touch touch);

#endif /* TOUCH_H_ */
