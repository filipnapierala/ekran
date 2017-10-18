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
	cv::imshow("",this->bg);
}

void Screen::draw_background()
{
	this->draw_background();
	cv::imshow("",this->bg);
}

void Screen::add_button()
{
	this->button_vector.push_back(this->path);
}
