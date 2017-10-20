/*
 * Button.cpp
 *
 *  Created on: Oct 18, 2017
 *      Author: robert
 */

#include "../inc/Button.h"

#include <iostream>

Button::Button(std::string path,int x, int y) {

	this->pushed=0;
	this->path=path;
	this->img=cv::imread(this->path+"_"+std::to_string(this->pushed)+".png",cv::IMREAD_UNCHANGED);
	this->x=x;
	this->y=y;
}

Button::~Button() {
	// TODO Auto-generated destructor stub
}

void Button::draw(cv::Mat bg)
{
	std::cout<<"wchodzi";

	this->copy_transparent(this->img,bg);
	//this->copy_transparent(this->img,&bg);
}

void Button::changeState()
{
	this->pushed=(this->pushed+1)%2;
	this->img=cv::imread(this->path+"_"+std::to_string(this->pushed)+".png",cv::IMREAD_UNCHANGED);
}
