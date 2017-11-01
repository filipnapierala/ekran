/*
 * Touch.cpp
 *
 *  Created on: Nov 1, 2017
 *      Author: robert
 */

#include "../inc/Touch.h"

int main_touch(Touch touch)
{
	int change=-1;
	switch(touch.screen)
	{
	case 0:
	{
		change=Screen0_callback(touch);
		break;
	}
	case 1:
	{
		change=Screen1_callback(touch);
		break;
	}
	case 2:
	{
		change=Screen2_callback(touch);
		break;
	}
	case 3:
	{
		change=Screen3_callback(touch);
		break;
	}
	case 4:
	{
		change=Screen4_callback(touch);
		break;
	}
	}
	return change;
}

int Screen0_callback(Touch touch)
{
	std::cout<<touch.id<<std::endl;
	return 0;
}

int Screen1_callback(Touch touch)
{
	if(touch.id=="diag")
	{
		return 3;
	}
	else if(touch.id=="manual")
	{
		return 2;
	}
	else if(touch.id=="else")
	{
		return 4;
	}
	return -1;
}

int Screen2_callback(Touch touch)
{
	if(touch.id=="ret"||touch.id=="start")
	{
		return 1;
	}
	return -1;
}

int Screen3_callback(Touch touch)
{
	if(touch.id=="ret")
	{
		return 1;
	}
	return -1;
}

int Screen4_callback(Touch touch)
{
	if(touch.id=="ret")
	{
		return 1;
	}
	return -1;
}


