/*
 * Touch.cpp
 *
 *  Created on: Nov 1, 2017
 *      Author: robert
 */

#include "../inc/Touch.h"

int main_touch(std::unique_ptr<Control>&control,Touch touch, std::unique_ptr<GUI>&gui,std::unique_ptr<ConfigReader>&config) {
	int change = -1;
	switch (touch.screen) {
	case 0: {
		change = Screen0_callback(control,touch, gui, config);
		break;
	}
	case 1: {
		change = Screen1_callback(control,touch, gui,config);
		break;
	}
	case 2: {
		change = Screen2_callback(control,touch, gui,config);
		break;
	}
	case 3: {
		change = Screen3_callback(control,touch, gui,config);
		break;
	}
	case 4: {
		change = Screen4_callback(control,touch, gui,config);
		break;
	}
	}
	return change;
}

int Screen0_callback(std::unique_ptr<Control>&control,Touch touch, std::unique_ptr<GUI>&gui,std::unique_ptr<ConfigReader>&config) {
	std::cout << touch.id << std::endl;
	return 0;
}

int Screen1_callback(std::unique_ptr<Control>&control,Touch touch, std::unique_ptr<GUI>&gui,std::unique_ptr<ConfigReader>&config) {
	if (touch.id == "diag") {
		gui->actual_screen = 3;
		return 0;
	} else if (touch.id == "manual") {
		gui->actual_screen = 2;
		return 0;
	} else if (touch.id == "else") {
		gui->actual_screen = 4;
		return 0;
	}
	else if (touch.id == "hot") {
		gui->screen_vector[1]->trackbarChangeValue(1,10);
		return 0;
	}
	else if (touch.id == "crio") {
		gui->screen_vector[1]->trackbarChangeValue(0,10);
		return 0;
	}
	return -1;
}

int Screen2_callback(std::unique_ptr<Control>&control,Touch touch, std::unique_ptr<GUI>&gui,std::unique_ptr<ConfigReader>&config) {
	if (touch.id == "ret") {
		gui->actual_screen = 1;
		return 0;
	}
	else if (touch.id == "start") {
		gui->actual_screen = 1;
		gui->screen_vector[1]->trackbarChangeValue(2,10);
		return 0;
	}
	else if (touch.id == "plus1") {
		gui->screen_vector[gui->actual_screen]->element_vector[8]->changeValue(
				1, 1);
		;
		return 0;
	} else if (touch.id == "plus2") {
		gui->screen_vector[gui->actual_screen]->element_vector[9]->changeValue(
				1, 1);
		;
		return 0;
	} else if (touch.id == "plus3") {
		gui->screen_vector[gui->actual_screen]->element_vector[10]->changeValue(
				1, 1);
		;
		return 0;
	}
	return -1;
}

int Screen3_callback(std::unique_ptr<Control>&control,Touch touch, std::unique_ptr<GUI>&gui,std::unique_ptr<ConfigReader>&config) {
	if (touch.id == "ret") {
		gui->actual_screen = 1;
		SendFrame(config->config.usbPort,0,0,0,0,5);
		control->red=0;
		control->blue=0;
		control->fan=0;
		control->crio=0;

		return 0;
	} else if (touch.id == "on1") {
		control->red=100;
	} else if (touch.id == "off1") {
		control->red=0;
	} else if (touch.id == "on2") {
		control->blue=100;
	} else if (touch.id == "off2") {
		control->blue=0;
	} else if (touch.id == "on3") {
		control->fan=1;
	} else if (touch.id == "off3") {
		control->fan=0;
	} else if (touch.id == "push") {
		control->crio=1;
	}
	SendFrame(config->config.usbPort,control->blue,control->red,control->fan,control->crio,5);
	control->crio=0;

	return -1;
}

int Screen4_callback(std::unique_ptr<Control>&control,Touch touch, std::unique_ptr<GUI>&gui,std::unique_ptr<ConfigReader>&config) {
	if (touch.id == "ret") {
		gui->actual_screen = 1;
		return 0;
	} else {
		gui->screen_vector[1]->trackbarChangeValue(3,10);
		gui->actual_screen = 1;
		return 0;
	}
	return -1;
}

