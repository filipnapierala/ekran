/*
 * Touch.cpp
 *
 *  Created on: Nov 1, 2017
 *      Author: robert
 */

#include "../inc/Touch.h"

int main_touch(Settings settings,Touch touch, std::unique_ptr<GUI>&gui,std::unique_ptr<ConfigReader>&config) {
	int change = -1;
	switch (touch.screen) {
	case 0: {
		change = Screen0_callback(settings,touch, gui, config);
		break;
	}
	case 1: {
		change = Screen1_callback(settings,touch, gui,config);
		break;
	}
	case 2: {
		change = Screen2_callback(settings,touch, gui,config);
		break;
	}
	case 3: {
		change = Screen3_callback(settings,touch, gui,config);
		break;
	}
	case 4: {
		change = Screen4_callback(settings,touch, gui,config);
		break;
	}
	}
	return change;
}

int Screen0_callback(Settings settings,Touch touch, std::unique_ptr<GUI>&gui,std::unique_ptr<ConfigReader>&config) {
	std::cout << touch.id << std::endl;
	return 0;
}

int Screen1_callback(Settings settings,Touch touch, std::unique_ptr<GUI>&gui,std::unique_ptr<ConfigReader>&config) {
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
	return -1;
}

int Screen2_callback(Settings settings,Touch touch, std::unique_ptr<GUI>&gui,std::unique_ptr<ConfigReader>&config) {
	if (touch.id == "ret" || touch.id == "start") {
		gui->actual_screen = 1;
		return 0;
	} else if (touch.id == "plus1") {
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

int Screen3_callback(Settings settings,Touch touch, std::unique_ptr<GUI>&gui,std::unique_ptr<ConfigReader>&config) {
	if (touch.id == "ret") {
		gui->actual_screen = 1;
		return 0;
	} else if (touch.id == "on1") {
		settings.blue=100;
		SendFrame(config->config.usbPort,settings);
	} else if (touch.id == "off1") {
		settings.blue=0;
		SendFrame(config->config.usbPort,settings);
	} else if (touch.id == "on2") {
		settings.red=100;
		SendFrame(config->config.usbPort,settings);
	} else if (touch.id == "off2") {
		settings.red=0;
		SendFrame(config->config.usbPort,settings);
	} else if (touch.id == "on3") {
		settings.fan=1;
		SendFrame(config->config.usbPort,settings);
	} else if (touch.id == "off3") {
		settings.fan=0;
		SendFrame(config->config.usbPort,settings);
	}

	return -1;
}

int Screen4_callback(Settings settings,Touch touch, std::unique_ptr<GUI>&gui,std::unique_ptr<ConfigReader>&config) {
	if (touch.id == "ret") {
		gui->actual_screen = 1;
		return 0;
	} else {
		gui->screen_vector[1]->change_value(10);
		gui->actual_screen = 1;
		return 0;
	}
	return -1;
}

