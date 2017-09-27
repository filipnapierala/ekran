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
#include "GUI.h"
//#include <functional>

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
	static int i=1;

	char buffer[20];
	sprintf(buffer,"./img/%s/bg.png",language.c_str());
	bg=cv::imread(buffer,1);
	if(push==1)
	{
		sprintf(buffer,"./img/%s/b1.png",language.c_str());
	}
	else
	{
		sprintf(buffer,"./img/%s/b1_p.png",language.c_str());
	}
	b1=cv::imread(buffer,cv::IMREAD_UNCHANGED);
	sprintf(buffer,"./img/%s/b2.png",language.c_str());
	b2=cv::imread(buffer,cv::IMREAD_UNCHANGED);
	sprintf(buffer,"./img/%s/b3.png",language.c_str());
	b3=cv::imread(buffer,cv::IMREAD_UNCHANGED);

	sprintf(buffer,"./img/%s/fan_%d.png",language.c_str(),i);

	cv::Mat f=cv::imread(buffer,cv::IMREAD_UNCHANGED);

	copy_transparent(bg,b1,50,25);
	copy_transparent(bg,b2,220,150);
	copy_transparent(bg,b3,0,bg.rows-b3.rows);
	cv::resize(f,f,cv::Size(),0.5,0.5,CV_INTER_CUBIC);
	copy_transparent(bg,f,350,600);

	cv::imshow("test",bg);
	if(i>3)
	{
		i=1;
	}
}

void timer_start(std::function<void(void)> func,unsigned int interval)
{
	std::thread([func,interval]()
			{
				while(1)
					{
						func();
						std::this_thread::sleep_for(std::chrono::microseconds(interval));
					}
			}).detach();
}

int main()
{


	//std::system("sudo rmmod psmouse");

	std::fstream file_stream("./config.txt");
	std::getline(file_stream,language);

	int first=language.find("\"");
	int last=language.find_last_of("\"");

	language=language.substr(first+1,last-first-1);


	cv::namedWindow("test",CV_WINDOW_NORMAL);

	cv::setWindowProperty("test",CV_WND_PROP_FULLSCREEN,CV_WINDOW_FULLSCREEN);



	char buffer[20];
	sprintf(buffer,"./img/%s/bg.png",language.c_str());
//	if(fopen(buffer[0],"r")==NULL)
//	{
//		std::cout<<"no such language implemented!\r\n";
//		return 0;
//	}

	//std::thread t(&show_screen1);
	//t.join();

	//timer_start(show_screen1,1000);

	cv::setMouseCallback("test",touch_callback);


	show_screen1(1);

	cv::VideoCapture capture("./img/sample.avi");

	auto gui=std::make_unique<GUI>("./data/config/config.yml");
	//GUI gui("./data/config/config.yml");

	std::cout<<gui->config.language;

	while(screen1_flag)
	{
		cv::Mat frame;
		capture>>frame;

		if(frame.cols==0)
		{
			capture.set(CV_CAP_PROP_POS_AVI_RATIO,0);
			capture>>frame;
		}

		cv::resize(frame,frame,cv::Size(),0.3,0.3,CV_INTER_CUBIC);

		frame.copyTo(bg(cv::Rect(600,100,frame.cols,frame.rows)));
		cv::imshow("test",bg);
		if(cv::waitKey(1)=='a')
		{
			//std::system("sudo modprobe psmouse");
			break;
		}
	}

//	while(1)
//	{
//		cv::waitKey(10);
//		show_screen1(1);
//		cv::waitKey(10);
//		show_screen1(2);
//		cv::waitKey(10);
//		show_screen1(3);
//		if(cv::waitKey(100)=='a')
//		{
//			break;
//		}
//	}
	cv::waitKey(0);
	return 0;
}
