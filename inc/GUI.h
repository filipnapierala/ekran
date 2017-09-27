/*
 * GUI.h
 *
 *  Created on: Sep 27, 2017
 *      Author: robert
 */

#ifndef GUI_H_
#define GUI_H_

#include <string>
#include <opencv/cv.hpp>

class GUI {
public:
	GUI(std::string path);
	virtual ~GUI();

	struct
	{
		std::string language;
		std::string custom_program_path;
	} config;

private:
	void parse(std::string path);
};

#endif /* GUI_H_ */
