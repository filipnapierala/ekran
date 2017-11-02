/*
 * TrackBar.cpp
 *
 *  Created on: Oct 20, 2017
 *      Author: robert
 */

#include "../inc/TrackBar.h"
#include <iostream>

TrackBar::TrackBar(std::string radial_path, std::string slider_path, int x, int y, int maxValue,std::string id) {

	this->x=x;
	this->y=y;

	this->maxValue=maxValue;
	this->value=0;

	this->pushed=0;

	this->slider=cv::imread(slider_path+".png",cv::IMREAD_UNCHANGED);
	this->radial=cv::imread(radial_path+"_"+std::to_string(this->pushed)+".png",cv::IMREAD_UNCHANGED);

	this->width=this->slider.cols;
	this->height=this->slider.rows;

	this->id=id;
}

TrackBar::~TrackBar() {
	// TODO Auto-generated destructor stub
}

void TrackBar::draw(cv::Mat bg)
{
	this->copy_transparent(this->slider,bg);

	int position=(float(this->width)/float(this->maxValue))
					*this->value-this->radial.cols/2;
	this->copy_transparent(this->radial,bg,position,-(this->slider.rows/2));
}

void TrackBar::changeState()
{

}

void TrackBar::changeValue(int x, int y)
{
	this->value+=10;
	//this->value=float((float(x)-float(this->x))/float(this->width))*this->maxValue;
	this->value=std::min(std::max(this->value,0),255);
}

