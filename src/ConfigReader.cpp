/*
 * ConfigReader.cpp
 *
 *  Created on: Jan 21, 2018
 *      Author: robert
 */

#include "../inc/ConfigReader.h"

ConfigReader::ConfigReader(std::string path) {
	// TODO Auto-generated constructor stub
	this->crioPath=path+"/usedCrio";
	this->Parse(path+"/config.yml");
}

ConfigReader::~ConfigReader() {
	// TODO Auto-generated destructor stub
}

void ConfigReader::Parse(std::string path)
{
	cv::FileStorage file(path,cv::FileStorage::READ);

	if(!file["language"].empty())
	{
		file["language"]>>config.language;
	}
	if(!file["customProgram"].empty())
	{
		file["customProgram"]>>config.custom_program_path;
	}
	if(!file["usbPort"].empty())
	{
		file["usbPort"]>>config.usbPort;
	}
	if(!file["criovolume"].empty())
	{
		file["criovolume"]>>config.crioVolume;

		std::fstream file;
		file.open(this->crioPath);

		std::string number;
		getline(file,number);

		config.crioVolume-=std::stoi(number);
		file.close();
	}
	file.release();
}

void ConfigReader::saveCrio(int number,std::string path)
{
	cv::FileStorage file(path,cv::FileStorage::APPEND);
	if(!file["criovolume"].empty())
	{
		//file<<"criovolume"<<number;
	}
	file.release();
}