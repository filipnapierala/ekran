/*
 * Video.cpp
 *
 *  Created on: Oct 20, 2017
 *      Author: robert
 */

#include "../inc/Video.h"

Video::Video(std::string path,int x, int y, std::string id, int width, int height) {
	this->x=x;
	this->y=y;
	this->path=path;
	this->capture=cv::VideoCapture(this->path+".avi");

	this->width=width;
	this->height=height;

	this->is_end=0;
	this->id=id;
}

Video::~Video() {
	// TODO Auto-generated destructor stub
}

void Video::draw(cv::Mat bg)
{
	cv::Mat frame;
	this->capture>>frame;
	if(frame.cols!=0)
	{
		cv::resize(frame,frame,cv::Size(this->width,this->height),0,0,CV_INTER_CUBIC);
		frame.copyTo(bg(cv::Rect(this->x,this->y,frame.cols,frame.rows)));
	}
	else
	{
		this->is_end=1;
		this->capture=cv::VideoCapture(this->path+".avi");
	}
	cv::rectangle(bg,cv::Point(this->x,this->y),cv::Point(this->x+this->width,this->y+this->height), cv::Scalar(0,0,0),10);
}


void Video::changeValue(int x, int y)
{

}

void Video::changeState()
{

}
