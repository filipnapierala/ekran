/*
 * GUI.cpp
 *
 *  Created on: Sep 27, 2017
 *      Author: robert
 */

#include "../inc/GUI.h"

GUI::GUI(std::string path) {
	// TODO Auto-generated constructor stub
	parse(path);
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

