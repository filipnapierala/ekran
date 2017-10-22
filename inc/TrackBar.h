/*
 * TrackBar.h
 *
 *  Created on: Oct 20, 2017
 *      Author: robert
 */

#ifndef TRACKBAR_H_
#define TRACKBAR_H_

#include "../inc/Element.h"

class TrackBar:public Element {
public:
	TrackBar(std::string radial_path, std::string slider_path, int x, int y, int maxValue);
	virtual ~TrackBar();
	int value;

	void draw(cv::Mat bg);
	void changeState();
	void changeValue();
	virtual void changeValue(int x, int y);

private:
	cv::Mat radial;
	cv::Mat slider;

	int pushed;
	int maxValue;
};

#endif /* TRACKBAR_H_ */
