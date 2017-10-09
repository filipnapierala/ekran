/*
 * Screen.cpp
 *
 *  Created on: Sep 28, 2017
 *      Author: robert
 */

#include "../inc/Screen.h"

Screen::Screen(std::string data_path) {

	this->path=data_path;
	this->bg=cv::imread(this->path+"/bg.png",1);
	this->elements_num=0;
}

Screen::~Screen() {
	// TODO Auto-generated destructor stub
}

void Screen::Draw()
{
	this->draw_background();
}

void Screen::draw_background()
{
	std::cout<<this->path<<std::endl;
	cv::imshow("",this->bg);
}
