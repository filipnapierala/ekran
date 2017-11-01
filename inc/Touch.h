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

int main_touch(Touch touch,std::unique_ptr<GUI>&gui);
int Screen0_callback(Touch touch,std::unique_ptr<GUI>&gui);
int Screen1_callback(Touch touch,std::unique_ptr<GUI>&gui);
int Screen2_callback(Touch touch,std::unique_ptr<GUI>&gui);
int Screen3_callback(Touch touch,std::unique_ptr<GUI>&gui);
int Screen4_callback(Touch touch,std::unique_ptr<GUI>&gui);

#endif /* TOUCH_H_ */
