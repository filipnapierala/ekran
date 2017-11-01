/*
 * Image.cpp
 *
 *  Created on: Oct 20, 2017
 *      Author: robert
 */

#include "../inc/Image.h"
#include <iostream>

Image::Image(std::string path, int x, int y, double resize) {
	this->resize=resize;
	this->state=0;
	this->path=path;
	this->x=x;
	this->y=y;

	this->img=cv::imread(this->path+"_"+std::to_string(this->state)+".png",cv::IMREAD_UNCHANGED);
	cv::resize(this->img,this->img,cv::Size(),resize,resize,CV_INTER_CUBIC);

	this->width=this->img.cols;
	this->height=this->img.rows;
}

Image::~Image() {
	// TODO Auto-generated destructor stub
}

void Image::draw(cv::Mat bg)
{
	this->copy_transparent(this->img,bg);
}

void Image::changeValue(int x, int y)
{

}

void Image::changeState()
{
	this->state++;
	this->img=cv::imread(this->path+"_"+std::to_string(this->state)+".png",cv::IMREAD_UNCHANGED);

	if(this->img.cols==0)
	{
		this->state=0;
		this->img=cv::imread(this->path+"_"+std::to_string(this->state)+".png",cv::IMREAD_UNCHANGED);
	}
}
