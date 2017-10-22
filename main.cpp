/*
 * main.cpp
 *
 *  Created on: Jul 31, 2017
 *  Author: robert
 */

#include <iostream>
#include <thread>
#include <string>
#include <memory>
#include "inc/GUI.h"

auto gui=std::make_unique<GUI>("./data/config/config.yml","./data/img/");

bool move=false;

void Screen0_callback(int x, int y, int event)
{
	if(event==0)
	{
		switch(gui->screen_vector[gui->actual_screen]->touch_callback(x,y))
		{
		case 0:
		{
			gui->actual_screen=1;
			break;
		}
		case 1:
		{
			gui->actual_screen=2;
			break;
		}
		case 2:
		{
			gui->actual_screen=3;
			break;
		}
		}
	}
}

void Screen1_callback(int x, int y, int event)
{
	if(event==0)
	{
	switch(gui->screen_vector[gui->actual_screen]->touch_callback(x,y))
	{
	case 0:
	{
		gui->actual_screen=0;
		break;
	}
	case 1:
	{
		//gui->actual_screen=0;
		break;
	}
	case 2:
	{
		gui->actual_screen=3;
		break;
	}
	}
	}

	else if(event==1)
	{
		switch(gui->screen_vector[gui->actual_screen]->touch_callback(x,y))
			{
			case 1:
			{
				move=true;
				break;
			}
			}
	}
}

void Screen2_callback(int x, int y, int event)
{

}

void Screen3_callback(int x, int y, int event)
{

}

void Screen4_callback(int x, int y, int event)
{

}


void touch_callback(int event,int x,int y,int flags,void*)
{
	if(event==CV_EVENT_MOUSEMOVE&&move==true)
	{
		gui->screen_vector[1]->trackbarChangeValue(x,1);
	}
	//std::cout<<x<<" "<<y<<std::endl;
	switch(event)
	{
	case CV_EVENT_LBUTTONUP:
	{
		move=false;

		switch(gui->actual_screen)
		{
		case 0:
		{
			Screen0_callback(x,y,0);
			break;
		}
		case 1:
		{
			Screen1_callback(x,y,0);
			break;
		}
		case 2:
		{
			Screen2_callback(x,y,0);
			break;
		}
		case 3:
		{
			Screen3_callback(x,y,0);
			break;
		}
		case 4:
		{
			Screen4_callback(x,y,0);
			break;
		}
		}
		break;
	}
	case CV_EVENT_LBUTTONDOWN:
	{
		switch(gui->actual_screen)
		{
		case 0:
		{
			Screen0_callback(x,y,1);
			break;
		}
		case 1:
		{
			Screen1_callback(x,y,1);
			break;
		}
		case 2:
		{
			Screen2_callback(x,y,1);
			break;
		}
		case 3:
		{
			Screen3_callback(x,y,1);
			break;
		}
		case 4:
		{
			Screen4_callback(x,y,1);
			break;
		}
		}
		break;
	}
	}
}

int main()
{
	cv::setMouseCallback("",touch_callback);

	gui->add_screen();
	gui->screen_vector[gui->actual_screen]->add_button("/b1",50,25);
	gui->screen_vector[gui->actual_screen]->add_button("/b2",220,150);
	gui->screen_vector[gui->actual_screen]->add_button("/b3",0,264);

	gui->screen_vector[gui->actual_screen]->add_image("/fan",100,100);

	gui->screen_vector[gui->actual_screen]->add_video("/vid",600,100);

	gui->add_screen();
	gui->screen_vector[gui->actual_screen]->add_video("/vid",600,100);
	gui->screen_vector[gui->actual_screen]->add_trackbar("/r1","/s1",200,100,255);

	gui->add_screen();
	gui->add_screen();

	gui->actual_screen=1;

	while(cv::waitKey(1)!='a')
	{
		gui->draw_screen();
	}

//		if(frame.cols==0)
//		{
//			capture.set(CV_CAP_PROP_POS_AVI_RATIO,0);
//			capture>>frame;
//		}

	return 0;
}
