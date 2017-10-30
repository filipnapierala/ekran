/*
 * Screen.cpp
 *
 *  Created on: Sep 28, 2017
 *      Author: robert
 */

#include "../inc/Screen.h"

Screen::Screen(std::string data_path,int res_x,int res_y) {

	this->path=data_path;
	this->bg=cv::imread(this->path+"/bg.png",1);
	this->elements_num=0;

	this->res_x=res_x;
	this->res_y=res_y;
}

Screen::~Screen() {
	// TODO Auto-generated destructor stub
}

void Screen::Draw()
{
	cv::Mat bg_copy;
	bg_copy=this->bg.clone();

	for(auto i=0;i<this->element_vector.size();i++)
	{
		this->element_vector[i]->draw(bg_copy);
	}
	cv::imshow("",bg_copy);
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
	this->element_vector.push_back(std::make_unique<Image>(this->path+image_path,x,y,1));
}

void Screen::add_trackbar(std::string radial_path,std::string slider_path, int x, int y, int maxValue)
{
	this->element_vector.push_back(std::make_unique<TrackBar>(this->path+radial_path, this->path+slider_path, x, y, maxValue));
}

void Screen::add_video(std::string video_path, int x, int y, int res_x, int res_y)
{
	this->element_vector.push_back(std::make_unique<Video>(this->path+video_path,x,y,res_x,res_y));
}

int Screen::touch_callback(int x, int y)
{
	for(auto i=0;i<this->element_vector.size();i++)
	{
		auto offset_x=this->element_vector[i]->x;
		auto offset_y=this->element_vector[i]->y;

		if((x>offset_x&&x<offset_x+this->element_vector[i]->width)
				&&(y>offset_y&&y<offset_y+this->element_vector[i]->height))
		{
			return i;
		}
	}
	return -1;
}

void Screen::trackbarChangeValue(int x,int element)
{
	this->element_vector[element]->changeValue(x,1);
}
