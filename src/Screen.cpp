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
	std::cout<<element_vector.size();
	for(auto i=0;i<this->element_vector.size();i++)
	{
		//copy_transparent(*button_vector[i]);
		this->element_vector[i]->draw(this->bg);
	}
	cv::imshow("",this->bg);
}

void Screen::draw_background()
{
	this->draw_background();
	cv::imshow("",this->bg);
}

void Screen::add_button(std::string button_path,int x, int y)
{
	this->element_vector.push_back(std::make_unique<Button>(this->path+button_path,x,y));
}

void Screen::add_image(std::string image_path,int x, int y)
{
	this->element_vector.push_back(std::make_unique<Image>(this->path+image_path,x,y,0.5));
}

void Screen::add_trackbar()
{
	//this->element_vector.push_back(std::make_unique<TrackBar>());
}

void Screen::add_video()
{
	//this->element_vector.push_back(std::make_unique<Video>());
}

