/*
 * Video.cpp
 *
 *  Created on: Oct 20, 2017
 *      Author: robert
 */

#include "../inc/Video.h"

Video::Video(std::string path,int x, int y, int res_x, int res_y) {
	this->x=x;
	this->y=y;
	this->path=path;
	this->capture=cv::VideoCapture(this->path+".avi");

	this->res_x=res_x;
	this->res_y=res_y;

	this->is_end=0;
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
		cv::resize(frame,frame,cv::Size(this->res_x,this->res_y),0,0,CV_INTER_CUBIC);
		frame.copyTo(bg(cv::Rect(this->x,this->y,frame.cols,frame.rows)));
	}
	else
	{
		this->is_end=1;
	}
}


void Video::changeValue(int x, int y)
{

}


