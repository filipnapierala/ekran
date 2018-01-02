/*
 * GUI.h
 *
 *  Created on: Sep 27, 2017
 *      Author: robert
 */

#ifndef GUI_H_
#define GUI_H_

#include <string>
#include "../inc/Screen.h"

class GUI {
public:
	GUI(std::string data_path);
	virtual ~GUI();

	struct
	{
		std::string language;
		std::string custom_program_path;
	} config;

	int actual_screen;

	void add_screen();
	void delete_screen(int number);
	void draw_screen();
	void turnBoxes();

	std::vector<std::unique_ptr<Screen>> screen_vector;

private:
	std::string path;
	void parse(std::string path);
	int x_res;
	int y_res;
};

#endif /* GUI_H_ */
