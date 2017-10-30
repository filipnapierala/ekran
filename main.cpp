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
	case 3:
	{
		gui->actual_screen=0;
		break;
	}
	}
	}

	else if(event==1)
	{
		switch(gui->screen_vector[gui->actual_screen]->touch_callback(x,y))
			{
			case 0:
			{
				move=true;
				break;
			}
			}
	}
}

void Screen2_callback(int x, int y, int event)
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
	}
	}
}

void Screen3_callback(int x, int y, int event)
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
	}
	}
}

void Screen4_callback(int x, int y, int event)
{

}


void touch_callback(int event,int x,int y,int flags,void*)
{
	if(event==CV_EVENT_MOUSEMOVE&&move==true)
	{
		gui->screen_vector[1]->trackbarChangeValue(x,0);
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
	gui->screen_vector[gui->actual_screen]->add_video("/intro",0,0);

	gui->add_screen();
	gui->screen_vector[gui->actual_screen]->add_button("/b1",50,25);
	gui->screen_vector[gui->actual_screen]->add_button("/b2",250,150);
	gui->screen_vector[gui->actual_screen]->add_button("/b3",340,350);
	gui->screen_vector[gui->actual_screen]->add_button("/b4",0,460);
	gui->screen_vector[gui->actual_screen]->add_button("/b5",1180,50);
	gui->screen_vector[gui->actual_screen]->add_button("/b6",1180,700);

	gui->screen_vector[gui->actual_screen]->add_image("/alarm",1230,50);

#define x 25
	gui->screen_vector[gui->actual_screen]->add_image("/fan",650+x,480);
	gui->screen_vector[gui->actual_screen]->add_image("/red",790+x,500);
	gui->screen_vector[gui->actual_screen]->add_image("/blue",890+x,500);
	gui->screen_vector[gui->actual_screen]->add_image("/pr",1030+x,480);

	gui->screen_vector[gui->actual_screen]->add_video("/vid",600,100,600,300);

	gui->add_screen();

	gui->screen_vector[gui->actual_screen]->add_trackbar("/r1","/s1",500,200,255);
	gui->screen_vector[gui->actual_screen]->add_trackbar("/r1","/s1",500,400,255);
	gui->screen_vector[gui->actual_screen]->add_trackbar("/r1","/s1",500,600,255);
	gui->screen_vector[gui->actual_screen]->add_button("/ret",1267,0);

	gui->add_screen();

	gui->screen_vector[gui->actual_screen]->add_button("/ret",1267,0);

	gui->screen_vector[gui->actual_screen]->add_button("/on",100,100);
	gui->screen_vector[gui->actual_screen]->add_button("/on",600,100);
	gui->screen_vector[gui->actual_screen]->add_button("/on",100,500);

	gui->screen_vector[gui->actual_screen]->add_button("/off",300,100);
	gui->screen_vector[gui->actual_screen]->add_button("/off",800,100);
	gui->screen_vector[gui->actual_screen]->add_button("/off",300,500);

	gui->screen_vector[gui->actual_screen]->add_button("/push",700,500);

	gui->add_screen();

	gui->screen_vector[gui->actual_screen]->add_button("/ret",1267,0);
	gui->screen_vector[gui->actual_screen]->add_button("/pr1",100,100);
	gui->screen_vector[gui->actual_screen]->add_button("/pr1",300,100);
	gui->screen_vector[gui->actual_screen]->add_button("/pr1",500,100);
	gui->screen_vector[gui->actual_screen]->add_button("/pr1",700,100);
	gui->screen_vector[gui->actual_screen]->add_button("/pr1",100,500);
	gui->screen_vector[gui->actual_screen]->add_button("/pr1",300,500);
	gui->screen_vector[gui->actual_screen]->add_button("/pr1",500,500);
	gui->screen_vector[gui->actual_screen]->add_button("/pr1",700,500);

	gui->actual_screen=0;

	//comment to disable intro
//	while(gui->screen_vector[gui->actual_screen]->element_vector[0]->is_end==0)
//	{
//		gui->draw_screen();
//		cv::waitKey(1);
//	}
	clock_t start,stop;
	gui->actual_screen=1;

	while(cv::waitKey(1)!='a')
	{
		start=clock();
		gui->draw_screen();
		stop=clock();
		std::cout<<"fps: "<<int(1/(double((stop-start))/CLOCKS_PER_SEC))<<std::endl;
	}

//		if(frame.cols==0)
//		{
//			capture.set(CV_CAP_PROP_POS_AVI_RATIO,0);
//			capture>>frame;
//		}

	return 0;
}
