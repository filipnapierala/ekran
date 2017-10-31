/*
 * Element.h
 *
 *  Created on: Oct 7, 2017
 *      Author: robert
 */

#ifndef ELEMENT_H_
#define ELEMENT_H_

#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>

class Element {
public:
	Element();
	virtual ~Element();

	int resize;
	int x,y;
	int width,height;
	int is_end;

	virtual void draw(cv::Mat bg)=0;
	//virtual void changeState(int i)=0;
	virtual void changeValue(int x, int y)=0;

	void copy_transparent(cv::Mat img, cv::Mat bg, int offset=0);
	void draw_boundingBox(cv::Mat bg);
};

#endif /* ELEMENT_H_ */
