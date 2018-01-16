/*
 * Screen.h
 *
 *  Created on: Sep 28, 2017
 *      Author: robert
 */

#ifndef SCREEN_H_
#define SCREEN_H_

#include <memory>
#include <vector>
#include <string>
#include <iostream>

#include "../inc/Element.h"
#include "../inc/Button.h"
#include "../inc/TrackBar.h"
#include "../inc/Video.h"
#include "../inc/Image.h"

#define X 1332
#define Y 780

class Screen {
public:
	Screen(std::string data_path,int rex_x,int res_y,std::string WindowName);
	virtual ~Screen();

	void add_button(std::string button_path, int x, int y, std::string id);
	void add_trackbar(std::string radial_path,std::string slider_path,
			int x, int y, int maxValue,std::string id);
	void add_video(std::string video_path, int x, int y,std::string id, int res_x=X, int res_y=Y);
	void add_image(std::string image_path,int x, int y, std::string id);

	void Draw();

	std::string touch_callback(int x, int y, int& n);

	void trackbarChangeValue(int x,int element);

	void change_value(int element);

	std::vector<std::unique_ptr<Element>> element_vector;

	bool debug;

private:

	std::string path;
	std::string WinName;

	int elements_num;
	void draw_background();
	//void copy_transparent(Button button);

	cv::Mat bg;

	int res_x,res_y;
};

#endif /* SCREEN_H_ */
