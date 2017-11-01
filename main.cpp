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
#include "inc/Touch.h"
#include <chrono>

bool move=false;
bool touch_flag=false;

auto gui=std::make_unique<GUI>("./data/config/config.yml","./data/img/");

Touch touch;

void touch_callback(int event,int x,int y,int flags,void*)
{
	if(event==1)
	{
		touch.id=gui->screen_vector[gui->actual_screen]->touch_callback(x,y);
		touch.x=x;
		touch.y=y;
		touch.previous_event=touch.event;
		touch.event=event;
		touch.screen=gui->actual_screen;

		if(touch.id!=" ")
		{
			gui->screen_vector[gui->actual_screen]->change_value(0);
		}
	}
	if(event==4)
	{
		touch.id=gui->screen_vector[gui->actual_screen]->touch_callback(x,y);
		touch.x=x;
		touch.y=y;
		touch.previous_event=touch.event;
		touch.event=event;
		touch.screen=gui->actual_screen;

		if(touch.id!=" ")
		{
			touch_flag=true;
		}
	}
}

void screen0()
{
	gui->add_screen();

	gui->screen_vector[gui->actual_screen]->add_video("/intro",0,0,"intro");
}

void screen1()
{
	gui->add_screen();

	gui->screen_vector[gui->actual_screen]->add_button("/crio",50,25,"crio");
	gui->screen_vector[gui->actual_screen]->add_button("/hot",250,150,"hot");
	gui->screen_vector[gui->actual_screen]->add_button("/manual",350,350,"manual");
	gui->screen_vector[gui->actual_screen]->add_button("/else",0,460,"else");
	gui->screen_vector[gui->actual_screen]->add_button("/diag",1180,50,"diag");
	gui->screen_vector[gui->actual_screen]->add_button("/reset",1180,700,"reset");

	gui->screen_vector[gui->actual_screen]->add_image("/alarm",1230,50,"alarm");

#define x 25
	gui->screen_vector[gui->actual_screen]->add_image("/fan",650+x,480,"fan");
	gui->screen_vector[gui->actual_screen]->add_image("/red",790+x,500,"red");
	gui->screen_vector[gui->actual_screen]->add_image("/blue",890+x,500,"blue");
	gui->screen_vector[gui->actual_screen]->add_image("/pr",1030+x,480,"pr");

	gui->screen_vector[gui->actual_screen]->add_video("/vid",600,100,"video",640,360);
}

void screen2()
{
	gui->add_screen();

	gui->screen_vector[gui->actual_screen]->add_button("/ret",1130,0,"ret");
	gui->screen_vector[gui->actual_screen]->add_button("/start",0,650,"start");

	gui->screen_vector[gui->actual_screen]->add_button("/minus",200,330,"minus1");
	gui->screen_vector[gui->actual_screen]->add_button("/minus",200,400,"minus2");
	gui->screen_vector[gui->actual_screen]->add_button("/minus",200,470,"minus3");
	gui->screen_vector[gui->actual_screen]->add_button("/plus",1100,330,"plus1");
	gui->screen_vector[gui->actual_screen]->add_button("/plus",1100,400,"plus2");
	gui->screen_vector[gui->actual_screen]->add_button("/plus",1100,470,"plus3");

	gui->screen_vector[gui->actual_screen]->add_trackbar("/r1","/s1",240,330,255,"trackbar1");
	gui->screen_vector[gui->actual_screen]->add_trackbar("/r1","/s1",240,400,255,"trackbar2");
	gui->screen_vector[gui->actual_screen]->add_trackbar("/r1","/s1",240,470,255,"trackbar3");

	gui->screen_vector[gui->actual_screen]->add_image("/hot",100,330,"hot");
	gui->screen_vector[gui->actual_screen]->add_image("/cold",100,400,"cold");
	gui->screen_vector[gui->actual_screen]->add_image("/time",100,470,"time");
}

void screen3()
{
	gui->add_screen();

	gui->screen_vector[gui->actual_screen]->add_button("/ret",1130,0,"ret");
	gui->screen_vector[gui->actual_screen]->add_button("/on",390,250,"on1");
	gui->screen_vector[gui->actual_screen]->add_button("/on",790,250,"on2");
	gui->screen_vector[gui->actual_screen]->add_button("/on",390,550,"on3");
	gui->screen_vector[gui->actual_screen]->add_button("/off",490,250,"off1");
	gui->screen_vector[gui->actual_screen]->add_button("/off",890,250,"off2");
	gui->screen_vector[gui->actual_screen]->add_button("/off",490,550,"off3");
	gui->screen_vector[gui->actual_screen]->add_button("/push",700,500,"push");

	gui->screen_vector[gui->actual_screen]->add_image("/blue",340,150,"blue");
	gui->screen_vector[gui->actual_screen]->add_image("/red",840,150,"red");
	gui->screen_vector[gui->actual_screen]->add_image("/fan",340,450,"fan");
	gui->screen_vector[gui->actual_screen]->add_image("/crio",700,400,"crio");
}

void screen4()
{
	gui->add_screen();

	gui->screen_vector[gui->actual_screen]->add_button("/ret",1130,0,"ret");
	gui->screen_vector[gui->actual_screen]->add_button("/pr1",140,220,"pr1");
	gui->screen_vector[gui->actual_screen]->add_button("/pr2",440,220,"pr2");
	gui->screen_vector[gui->actual_screen]->add_button("/pr3",740,220,"pr3");
	gui->screen_vector[gui->actual_screen]->add_button("/pr4",1040,220,"pr4");
	gui->screen_vector[gui->actual_screen]->add_button("/pr5",140,580,"pr5");
	gui->screen_vector[gui->actual_screen]->add_button("/pr6",440,580,"pr6");
	gui->screen_vector[gui->actual_screen]->add_button("/pr7",740,580,"pr7");
	gui->screen_vector[gui->actual_screen]->add_button("/pr8",1040,580,"pr8");
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

		if(touch_flag==true)
		{
			touch_flag=false;
			main_touch(touch,gui);
		}
		std::chrono::steady_clock::time_point end=std::chrono::steady_clock::now();
		auto count=std::chrono::duration_cast<std::chrono::milliseconds>(end-begin).count();
		std::cout<<"fps: "<<1000/double(count)<<std::endl;
	}

//		if(frame.cols==0)
//		{
//			capture.set(CV_CAP_PROP_POS_AVI_RATIO,0);
//			capture>>frame;
//		}

	return 0;
}
