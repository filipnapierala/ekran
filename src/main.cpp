/*
 * main.cpp
 *
 *  Created on: Jul 31, 2017
 *      Author: robert
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
//#include <functional>

cv::Mat bg,b1,b2,b3;

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
				copy.at<cv::Vec3b>(x+i,y+j)[0]=fg.at<cv::Vec4b>(i,j)[0];
				copy.at<cv::Vec3b>(x+i,y+j)[1]=fg.at<cv::Vec4b>(i,j)[1];
				copy.at<cv::Vec3b>(x+i,y+j)[2]=fg.at<cv::Vec4b>(i,j)[2];
				copy.at<cv::Vec3b>(x+i,y+j)[3]=fg.at<cv::Vec4b>(i,j)[3];
			}
		}
	}

	copy.copyTo(bg);
}

void show_screen1()
{
	static int i=1;
	bg=cv::imread("./img/eng/bg.png",1);
	b1=cv::imread("./img/eng/b1.png",cv::IMREAD_UNCHANGED);
	b2=cv::imread("./img/eng/b2.png",cv::IMREAD_UNCHANGED);
	b3=cv::imread("./img/eng/b3.png",cv::IMREAD_UNCHANGED);

	char buffer[30];
	sprintf(buffer,"./img/eng/fan_%d.png",i);

	cv::Mat f=cv::imread(buffer,cv::IMREAD_UNCHANGED);

	copy_transparent(bg,b1,25,50);
	copy_transparent(bg,b2,150,150);
	copy_transparent(bg,b3,bg.rows-b3.rows,0);
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
	cv::namedWindow("test",CV_WINDOW_NORMAL);
	cv::setWindowProperty("test",CV_WND_PROP_FULLSCREEN,CV_WINDOW_FULLSCREEN);

	//std::thread t(&show_screen1);
	//t.join();

	//timer_start(show_screen1,1000);

	show_screen1();
	cv::VideoCapture capture("./img/test_video.mp4");

	while(1)
	{
		cv::Mat frame;
		capture>>frame;

		cv::resize(frame,frame,cv::Size(),0.2,0.2,CV_INTER_LINEAR);

		frame.copyTo(bg(cv::Rect(600,100,frame.cols,frame.rows)));
		cv::imshow("test",bg);
		if(cv::waitKey(1)=='a')
		{
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
