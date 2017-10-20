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

//void touch_callback(int event,int x,int y,int,void*)
//{
//	//std::cout<<x<<" "<<y<<std::endl;
//	switch(event)
//	{
//	case CV_EVENT_LBUTTONUP:
//	{
//		if((x>50&&x<50+b1.cols)&&(y>25&&y<25+b1.rows))
//		{
//			char buffer[20];
//			sprintf(buffer,"./img/%s/s2_bg.png",language.c_str());
//			bg=cv::imread(buffer,1);
//			cv::imshow("test",bg);
//			screen1_flag=0;
//		}
//		else if((x>220&&x<220+b2.cols)&&(y>150&&y<150+b2.rows))
//		{
//			char buffer[20];
//			sprintf(buffer,"./img/%s/s3_bg.png",language.c_str());
//			bg=cv::imread(buffer,1);
//			cv::imshow("test",bg);
//			screen1_flag=0;
//		}
//		else if((x>0&&x<0+b3.cols)&&(y>bg.rows-b3.rows&&y<bg.rows-b3.rows+b3.rows))
//		{
//			char buffer[20];
//			sprintf(buffer,"./img/%s/s4_bg.png",language.c_str());
//			bg=cv::imread(buffer,1);
//			cv::imshow("test",bg);
//			screen1_flag=0;
//		}
//		else if((x>950&&x<1400)&&(y>550&&y<850))
//		{
//			//show_screen1(0);
//		}
//		break;
//	}
//	case CV_EVENT_LBUTTONDOWN:
//	{
//		if((x>50&&x<50+b1.cols)&&(y>25&&y<25+b1.rows))
//		{
//			//show_screen1(0);
//		}
//		break;
//	}
//	}
//}

int main()
{
	//cv::setMouseCallback("test",touch_callback);

	auto gui=std::make_unique<GUI>("./data/config/config.yml","./data/img/");
	gui->add_screen();
	gui->screen_vector[gui->actual_screen]->add_button("/b1",50,25);
	gui->screen_vector[gui->actual_screen]->add_button("/b2",220,150);
	gui->screen_vector[gui->actual_screen]->add_button("/b3",0,264);

	gui->screen_vector[gui->actual_screen]->add_image("/fan",100,100);

	gui->screen_vector[gui->actual_screen]->add_video("/vid",600,100);

	gui->draw_screen();

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
