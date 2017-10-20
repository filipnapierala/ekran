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
#include <stdio.h>
#include <unistd.h>
#include <thread>
#include <chrono>
#include <string>
#include <fstream>
#include <memory>
#include "inc/GUI.h"

cv::Mat bg,b1,b2,b3;
int screen1_flag=1,push=0;
std::string language;

void show_screen1(int push);

void touch_callback(int event,int x,int y,int,void*)
{
	//std::cout<<x<<" "<<y<<std::endl;
	switch(event)
	{
	case CV_EVENT_LBUTTONUP:
	{
		if((x>50&&x<50+b1.cols)&&(y>25&&y<25+b1.rows))
		{
			char buffer[20];
			sprintf(buffer,"./img/%s/s2_bg.png",language.c_str());
			bg=cv::imread(buffer,1);
			cv::imshow("test",bg);
			screen1_flag=0;
		}
		else if((x>220&&x<220+b2.cols)&&(y>150&&y<150+b2.rows))
		{
			char buffer[20];
			sprintf(buffer,"./img/%s/s3_bg.png",language.c_str());
			bg=cv::imread(buffer,1);
			cv::imshow("test",bg);
			screen1_flag=0;
		}
		else if((x>0&&x<0+b3.cols)&&(y>bg.rows-b3.rows&&y<bg.rows-b3.rows+b3.rows))
		{
			char buffer[20];
			sprintf(buffer,"./img/%s/s4_bg.png",language.c_str());
			bg=cv::imread(buffer,1);
			cv::imshow("test",bg);
			screen1_flag=0;
		}
		else if((x>950&&x<1400)&&(y>550&&y<850))
		{
			show_screen1(0);
		}
		break;
	}
	case CV_EVENT_LBUTTONDOWN:
	{
		if((x>50&&x<50+b1.cols)&&(y>25&&y<25+b1.rows))
		{
			show_screen1(0);
		}
		break;
	}
	}
}

void copy_transparent(cv::Mat bg,cv::Mat fg,int x,int y)
{
	cv::Mat copy=bg.clone();

	std::vector<cv::Mat> channels;
	cv::split(fg,channels);

	for(int i=0;i<fg.rows;i++)
	{
		for(int j=0;j<fg.cols;j++)
		{
			if(channels[3].at<uchar>(i,j)>=50)
			{
				copy.at<cv::Vec3b>(y+i,x+j)[0]=fg.at<cv::Vec4b>(i,j)[0];
				copy.at<cv::Vec3b>(y+i,x+j)[1]=fg.at<cv::Vec4b>(i,j)[1];
				copy.at<cv::Vec3b>(y+i,x+j)[2]=fg.at<cv::Vec4b>(i,j)[2];
				copy.at<cv::Vec3b>(y+i,x+j)[3]=fg.at<cv::Vec4b>(i,j)[3];
			}
		}
	}
	copy.copyTo(bg);
}

void show_screen1(int push)
{

}

int main()
{
	cv::setMouseCallback("test",touch_callback);

	//show_screen1(1);

	cv::VideoCapture capture("./img/sample.avi");

	auto gui=std::make_unique<GUI>("./data/config/config.yml","./data/img/");
	gui->add_screen();
	gui->screen_vector[gui->actual_screen]->add_button("/b1",50,25);
	gui->screen_vector[gui->actual_screen]->add_button("/b2",220,150);
	gui->screen_vector[gui->actual_screen]->add_button("/b3",0,264);

	gui->screen_vector[gui->actual_screen]->add_image("/fan",100,100);

	gui->draw_screen();

	cv::waitKey(0);

	//std::cout<<gui->config.language;

//	while(screen1_flag)
//	{
//		cv::Mat frame;
//		capture>>frame;
//
//		if(frame.cols==0)
//		{
//			capture.set(CV_CAP_PROP_POS_AVI_RATIO,0);
//			capture>>frame;
//		}
//
//		cv::resize(frame,frame,cv::Size(),0.3,0.3,CV_INTER_CUBIC);
//
//		frame.copyTo(bg(cv::Rect(600,100,frame.cols,frame.rows)));
//		cv::imshow("test",bg);
//		if(cv::waitKey(1)=='a')
//		{
//			break;
//		}
//	}
//
//	cv::waitKey(0);
	return 0;
}
