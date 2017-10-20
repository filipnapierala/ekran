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
#include "../inc/Button.h"
#include "../inc/TrackBar.h"
#include "../inc/Video.h"
#include "../inc/Image.h"

class Screen {
public:
	Screen(std::string data_path);
	virtual ~Screen();

	void add_button(std::string button_path, int x, int y);
	void add_trackbar();
	void add_video();
	void add_image(std::string image_path,int x, int y);

	void Draw();

private:

	std::string path;
	std::vector<std::unique_ptr<Button>> button_vector;
	std::vector<std::unique_ptr<Image>> image_vector;

	std::vector<std::unique_ptr<Element>> element_vector;

	//std::vector<Button> button_vector;

	int elements_num;
	void draw_background();
	void copy_transparent(Button button);

	cv::Mat bg;

};

#endif /* SCREEN_H_ */
