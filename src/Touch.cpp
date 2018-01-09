/*
 * Touch.cpp
 *
 *  Created on: Nov 1, 2017
 *      Author: robert
 */

#include "../inc/Touch.h"

int main_touch(Touch touch,std::unique_ptr<GUI>&gui)
{
	int change=-1;
	switch(touch.screen)
	{
	case 0:
	{
		change=Screen0_callback(touch,gui);
		break;
	}
	case 1:
	{
		change=Screen1_callback(touch,gui);
		break;
	}
	case 2:
	{
		change=Screen2_callback(touch,gui);
		break;
	}
	case 3:
	{
		change=Screen3_callback(touch,gui);
		break;
	}
	case 4:
	{
		change=Screen4_callback(touch,gui);
		break;
	}
	}
	return change;
}

int Screen0_callback(Touch touch,std::unique_ptr<GUI>&gui)
{
	std::cout<<touch.id<<std::endl;
	return 0;
}

int Screen1_callback(Touch touch,std::unique_ptr<GUI>&gui)
{
	if(touch.id=="diag")
	{
		gui->actual_screen=3;
		return 0;
	}
	else if(touch.id=="manual")
	{
		gui->actual_screen=2;
		return 0;
	}
	else if(touch.id=="else")
	{
		gui->actual_screen=4;
		return 0;
	}
	return -1;
}

int Screen2_callback(Touch touch,std::unique_ptr<GUI>&gui)
{
	if(touch.id=="ret"||touch.id=="start")
	{
		gui->actual_screen=1;
		return 0;
	}
	else if(touch.id=="plus1")
	{
		gui->screen_vector[gui->actual_screen]->element_vector[8]->changeValue(1,1);;
		return 0;
	}
	else if(touch.id=="plus2")
	{
		gui->screen_vector[gui->actual_screen]->element_vector[9]->changeValue(1,1);;
		return 0;
	}
	else if(touch.id=="plus3")
	{
		gui->screen_vector[gui->actual_screen]->element_vector[10]->changeValue(1,1);;
		return 0;
	}
	return -1;
}

int Screen3_callback(Touch touch,std::unique_ptr<GUI>&gui)
{
	if(touch.id=="ret")
	{
		gui->actual_screen=1;
		return 0;
	}
	else if(touch.id=="on1")
	{
		int fd = open_port("/dev/ttyACM0");
		initport(fd);
		char buffer[20];

		for(int i=0;i<101;i++)
		{
			int length = sprintf(buffer, "NASTAWA%03d:%03d:%01d:%01d\r\n", 90, i,
					0, 1);
			write(fd, buffer, length);
			usleep(10000);
		}

		close(fd);
	}
	else if(touch.id=="off1")
	{
		int fd = open_port("/dev/ttyACM0");
		initport(fd);
		char buffer[20];

		for(int i=100;i>=0;--i)
		{
			int length = sprintf(buffer, "NASTAWA%03d:%03d:%01d:%01d\r\n", 90, i,
					0, 1);
			write(fd, buffer, length);
			usleep(10000);
		}

		close(fd);
	}

	return -1;
}

int Screen4_callback(Touch touch,std::unique_ptr<GUI>&gui)
{
	if(touch.id=="ret")
	{
		gui->actual_screen=1;
		return 0;
	}
	else
	{
		gui->screen_vector[1]->change_value(10);
		gui->actual_screen=1;
		return 0;
	}
	return -1;
}


