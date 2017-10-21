/*
 * Element.h
 *
 *  Created on: Oct 7, 2017
 *      Author: robert
 */

#ifndef ELEMENT_H_
#define ELEMENT_H_

#include <opencv/cv.hpp>
#include <opencv/highgui.h>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/videoio.hpp>

class Element {
public:
	Element();
	virtual ~Element();

	int resize;
	int x,y;
	int width,height;

	virtual void draw(cv::Mat bg)=0;
	//virtual void changeState(int i)=0;
	virtual void changeValue(int x, int y)=0;

	void copy_transparent(cv::Mat img, cv::Mat bg, int offset=0);

};

#endif /* ELEMENT_H_ */
