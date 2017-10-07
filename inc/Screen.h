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
#include <opencv/cv.hpp>
#include <opencv/highgui.h>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/videoio.hpp>
#include "../inc/Element.h"

class Screen {
public:
	Screen(std::string data_path);
	virtual ~Screen();

	void add_button();
	void add_trackbar();
	void add_video();
	void add_image();

	void Draw();

private:

	std::string path;
	std::vector<Element> element_vector;
	int elements_num;
	void draw_background();

	cv::Mat bg;

};

#endif /* SCREEN_H_ */
