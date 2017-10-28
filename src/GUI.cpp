/*
 * GUI.cpp
 *
 *  Created on: Sep 27, 2017
 *      Author: robert
 */

#include "../inc/GUI.h"

GUI::GUI(std::string conf_path,std::string data_path) {
	parse(conf_path);
	this->path=data_path+config.language;

	this->actual_screen=-1;

	cv::namedWindow("",CV_WINDOW_NORMAL);
	cv::setWindowProperty("",CV_WND_PROP_FULLSCREEN,CV_WINDOW_FULLSCREEN);
}

GUI::~GUI() {
	// TODO Auto-generated destructor stub
}

void GUI::parse(std::string path)
{
	cv::FileStorage file(path,cv::FileStorage::READ);

	if(!file["language"].empty())
	{
		file["language"]>>config.language;
	}

	if(!file["custom_program"].empty())
	{
		file["custom_program"]>>config.custom_program_path;
	}

	file.release();
}

void GUI::add_screen()
{
	this->actual_screen++;
	screen_vector.push_back(std::make_unique<Screen>(this->path+"/s"+std::to_string(this->actual_screen),this->x_res,this->y_res));
}

void GUI::delete_screen()
{

}

void GUI::draw_screen()
{
	this->screen_vector[this->actual_screen]->Draw();
}


