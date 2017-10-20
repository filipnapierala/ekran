/*
 * Video.cpp
 *
 *  Created on: Oct 20, 2017
 *      Author: robert
 */

#include "../inc/Video.h"

Video::Video(std::string path,int x, int y) {
	this->x=x;
	this->y=y;
	this->path=path;
	this->capture=cv::VideoCapture(this->path+".avi");

}

Video::~Video() {
	// TODO Auto-generated destructor stub
}

void Video::draw(cv::Mat bg)
{
	cv::Mat frame;
	this->capture>>frame;
	cv::resize(frame,frame,cv::Size(),0.3,0.3,CV_INTER_CUBIC);

	frame.copyTo(bg(cv::Rect(600,100,frame.cols,frame.rows)));
}



