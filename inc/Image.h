/*
 * Image.h
 *
 *  Created on: Oct 20, 2017
 *      Author: robert
 */

#ifndef IMAGE_H_
#define IMAGE_H_

#include "../inc/Element.h"

#include <opencv/cv.hpp>
#include <opencv/highgui.h>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/videoio.hpp>

class Image:public Element {
public:
	Image(std::string path, int x, int y, double resize);
	virtual ~Image();

	void draw(cv::Mat bg);

	int state;

	void changeState();

	cv::Mat img;
	std::string path;
};

#endif /* IMAGE_H_ */
