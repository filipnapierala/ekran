/*
 * main.cpp
 *
 *  Created on: Jul 31, 2017
 *  Author: robert
 */

#include <iostream>
#include <opencv/cv.hpp>
#include <opencv/highgui.h>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/videoio.hpp>
#include <thread>
#include <string>
#include <memory>
#include "inc/GUI.h"

auto gui=std::make_unique<GUI>("./data/config/config.yml","./data/img/");

void touch_callback(int event,int x,int y,int,void*)
{
	//std::cout<<x<<" "<<y<<std::endl;
	switch(event)
	{
	case CV_EVENT_LBUTTONUP:
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

		break;
	}
	case CV_EVENT_LBUTTONDOWN:
	{
		std::cout<<"right"<<std::endl;
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

	gui->add_screen();
	gui->add_screen();

	gui->actual_screen=0;

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
