/*
 * Button.h
 *
 *  Created on: Oct 18, 2017
 *      Author: robert
 */

#ifndef BUTTON_H_
#define BUTTON_H_

#include <string>
#include "../inc/Element.h"

#include <opencv/cv.hpp>
#include <opencv/highgui.h>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/videoio.hpp>

class Button:public Element {
public:
	Button(std::string path, int x, int y);
	virtual ~Button();

	void draw(cv::Mat bg);
	void changeValue(int x, int y);

private:
	int resize=0;
	int pushed;

	void changeState();

	cv::Mat img;
	std::string path;
};

#endif /* BUTTON_H_ */
