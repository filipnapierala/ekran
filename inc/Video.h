/*
 * Video.h
 *
 *  Created on: Oct 20, 2017
 *      Author: robert
 */

#ifndef VIDEO_H_
#define VIDEO_H_

#include "../inc/Element.h"

class Video:public Element {
public:
	Video(std::string path,int x, int y, int res_x, int res_y);
	virtual ~Video();

	cv::VideoCapture capture;

	std::string path;

	void draw(cv::Mat bg);
	void changeValue(int x, int y);

private:
	int res_x,res_y;
};

#endif /* VIDEO_H_ */
