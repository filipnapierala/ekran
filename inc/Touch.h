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
#include "../inc/Utils.h"
#include "../inc/ConfigReader.h"

struct Touch
{
	int x,y,n,n_1;
	std::string id;
	int event;
	int previous_event;
	int screen;
};

int main_touch(Settings settings, Touch touch,std::unique_ptr<GUI>&gui,std::unique_ptr<ConfigReader>&config);
int Screen0_callback(Settings settings,Touch touch,std::unique_ptr<GUI>&gui,std::unique_ptr<ConfigReader>&config);
int Screen1_callback(Settings settings,Touch touch,std::unique_ptr<GUI>&gui,std::unique_ptr<ConfigReader>&config);
int Screen2_callback(Settings settings,Touch touch,std::unique_ptr<GUI>&gui,std::unique_ptr<ConfigReader>&config);
int Screen3_callback(Settings settings,Touch touch,std::unique_ptr<GUI>&gui,std::unique_ptr<ConfigReader>&config);
int Screen4_callback(Settings settings,Touch touch,std::unique_ptr<GUI>&gui,std::unique_ptr<ConfigReader>&config);

#endif /* TOUCH_H_ */
