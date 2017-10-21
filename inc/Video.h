/*
 * Video.h
 *
 *  Created on: Oct 20, 2017
 *      Author: robert
 */

#ifndef VIDEO_H_
#define VIDEO_H_

#include "../inc/Element.h"

#include <opencv/cv.hpp>
#include <opencv/highgui.h>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/videoio.hpp>

class Video:public Element {
public:
	Video(std::string path,int x, int y);
	virtual ~Video();

	cv::VideoCapture capture;

	std::string path;

	void draw(cv::Mat bg);
	void changeValue(int x, int y);
};

#endif /* VIDEO_H_ */
