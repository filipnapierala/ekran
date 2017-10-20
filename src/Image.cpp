/*
 * Image.cpp
 *
 *  Created on: Oct 20, 2017
 *      Author: robert
 */

#include "Image.h"
#include <iostream>

Image::Image(std::string path, int x, int y, double resize) {
	this->resize=resize;
	this->state=0;
	this->path=path;
	this->x=x;
	this->y=y;

	this->img=cv::imread(this->path+"_"+std::to_string(this->state)+".png",cv::IMREAD_UNCHANGED);
	cv::resize(this->img,this->img,cv::Size(),resize,resize,CV_INTER_CUBIC);
}

Image::~Image() {
	// TODO Auto-generated destructor stub
}

void Image::draw(cv::Mat bg)
{
	this->copy_transparent(this->img,bg);
}
