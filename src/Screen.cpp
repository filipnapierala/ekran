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
	std::cout<<button_vector.size();
	for(auto i=0;i<this->button_vector.size();i++)
	{
		copy_transparent(*button_vector[i]);
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
	this->button_vector.push_back(std::make_unique<Button>(this->path+button_path,x,y));
}

void Screen::add_image()
{
	this->image_vector.push_back(std::make_unique<Image>());
}

void Screen::add_trackbar()
{
	//this->element_vector.push_back(std::make_unique<TrackBar>());
}

void Screen::add_video()
{
	//this->element_vector.push_back(std::make_unique<Video>());
}

void Screen::copy_transparent(Button button)
{
	std::vector<cv::Mat> channels;
	cv::split(button.img ,channels);

	for(int i=0;i<button.img.rows;i++)
	{
		for(int j=0;j<button.img.cols;j++)
		{
			if(channels[3].at<uchar>(i,j)>=50)
			{
				this->bg.at<cv::Vec3b>(button.y+i,button.x+j)[0]=button.img.at<cv::Vec4b>(i,j)[0];
				this->bg.at<cv::Vec3b>(button.y+i,button.x+j)[1]=button.img.at<cv::Vec4b>(i,j)[1];
				this->bg.at<cv::Vec3b>(button.y+i,button.x+j)[2]=button.img.at<cv::Vec4b>(i,j)[2];
				this->bg.at<cv::Vec3b>(button.y+i,button.x+j)[3]=button.img.at<cv::Vec4b>(i,j)[3];
			}
		}
	}
	//copy.copyTo(this->bg);
}
