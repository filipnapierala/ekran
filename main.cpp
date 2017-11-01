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
#include <chrono>

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

void screen0()
{
	gui->add_screen();

	gui->screen_vector[gui->actual_screen]->add_video("/intro",0,0);
}

void screen1()
{
	gui->add_screen();

	gui->screen_vector[gui->actual_screen]->add_button("/crio",50,25);
	gui->screen_vector[gui->actual_screen]->add_button("/hot",250,150);
	gui->screen_vector[gui->actual_screen]->add_button("/manual",350,350);
	gui->screen_vector[gui->actual_screen]->add_button("/else",0,460);
	gui->screen_vector[gui->actual_screen]->add_button("/auto",1180,50);
	gui->screen_vector[gui->actual_screen]->add_button("/reset",1180,700);

	gui->screen_vector[gui->actual_screen]->add_image("/alarm",1230,50);

#define x 25
	gui->screen_vector[gui->actual_screen]->add_image("/fan",650+x,480);
	gui->screen_vector[gui->actual_screen]->add_image("/red",790+x,500);
	gui->screen_vector[gui->actual_screen]->add_image("/blue",890+x,500);
	gui->screen_vector[gui->actual_screen]->add_image("/pr",1030+x,480);

	gui->screen_vector[gui->actual_screen]->add_video("/vid",600,100,600,300);
}

void screen2()
{
	gui->add_screen();

	gui->screen_vector[gui->actual_screen]->add_button("/ret",1130,0);
	gui->screen_vector[gui->actual_screen]->add_button("/start",0,650);

	gui->screen_vector[gui->actual_screen]->add_button("/minus",200,330);
	gui->screen_vector[gui->actual_screen]->add_button("/minus",200,400);
	gui->screen_vector[gui->actual_screen]->add_button("/minus",200,470);
	gui->screen_vector[gui->actual_screen]->add_button("/plus",1100,330);
	gui->screen_vector[gui->actual_screen]->add_button("/plus",1100,400);
	gui->screen_vector[gui->actual_screen]->add_button("/plus",1100,470);

	gui->screen_vector[gui->actual_screen]->add_trackbar("/r1","/s1",240,330,255);
	gui->screen_vector[gui->actual_screen]->add_trackbar("/r1","/s1",240,400,255);
	gui->screen_vector[gui->actual_screen]->add_trackbar("/r1","/s1",240,470,255);

	gui->screen_vector[gui->actual_screen]->add_image("/hot",100,330);
	gui->screen_vector[gui->actual_screen]->add_image("/cold",100,400);
	gui->screen_vector[gui->actual_screen]->add_image("/time",100,470);
}

void screen3()
{
	gui->add_screen();

	gui->screen_vector[gui->actual_screen]->add_button("/ret",1130,0);
	gui->screen_vector[gui->actual_screen]->add_button("/on",390,250);
	gui->screen_vector[gui->actual_screen]->add_button("/on",790,250);
	gui->screen_vector[gui->actual_screen]->add_button("/on",390,550);
	gui->screen_vector[gui->actual_screen]->add_button("/off",490,250);
	gui->screen_vector[gui->actual_screen]->add_button("/off",890,250);
	gui->screen_vector[gui->actual_screen]->add_button("/off",490,550);
	gui->screen_vector[gui->actual_screen]->add_button("/push",700,500);

	gui->screen_vector[gui->actual_screen]->add_image("/blue",340,150);
	gui->screen_vector[gui->actual_screen]->add_image("/red",840,150);
	gui->screen_vector[gui->actual_screen]->add_image("/fan",340,450);
	gui->screen_vector[gui->actual_screen]->add_image("/crio",700,400);
}

void screen4()
{
	gui->add_screen();

	gui->screen_vector[gui->actual_screen]->add_button("/ret",1130,0);
	gui->screen_vector[gui->actual_screen]->add_button("/pr1",140,220);
	gui->screen_vector[gui->actual_screen]->add_button("/pr2",440,220);
	gui->screen_vector[gui->actual_screen]->add_button("/pr3",740,220);
	gui->screen_vector[gui->actual_screen]->add_button("/pr4",1040,220);
	gui->screen_vector[gui->actual_screen]->add_button("/pr5",140,580);
	gui->screen_vector[gui->actual_screen]->add_button("/pr6",440,580);
	gui->screen_vector[gui->actual_screen]->add_button("/pr7",740,580);
	gui->screen_vector[gui->actual_screen]->add_button("/pr8",1040,580);
}

int main()
{
	cv::setMouseCallback("",touch_callback);

	screen0();
	screen1();
	screen2();
	screen3();
	screen4();

	gui->actual_screen=0;

	//comment to disable intro
//	while(gui->screen_vector[gui->actual_screen]->element_vector[0]->is_end==0)
//	{
//		gui->draw_screen();
//		cv::waitKey(1);
//	}
	gui->actual_screen=1;

	while(1)
	{
		std::chrono::steady_clock::time_point begin=std::chrono::steady_clock::now();
		gui->draw_screen();
		std::chrono::steady_clock::time_point end=std::chrono::steady_clock::now();

		auto count=std::chrono::duration_cast<std::chrono::milliseconds>(end-begin).count();
		std::cout<<"fps: "<<1000/double(count)<<std::endl;

		char key=cv::waitKey(1);
		if(key=='d')
		{
			gui->turnBoxes();
		}
		else if(key=='a')
		{
			break;
		}

		if(gui->actual_screen==1)
		{
			gui->screen_vector[gui->actual_screen]->change_value(7);
		}
	}

//		if(frame.cols==0)
//		{
//			capture.set(CV_CAP_PROP_POS_AVI_RATIO,0);
//			capture>>frame;
//		}

	return 0;
}
