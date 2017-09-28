/*
 * Screen.h
 *
 *  Created on: Sep 28, 2017
 *      Author: robert
 */

#ifndef SCREEN_H_
#define SCREEN_H_

#include "../inc/GUI.h"

class Screen {
public:
	Screen();
	virtual ~Screen();

	void add_button();
	void add_trackbar();
	void add_video();
	void add_image();

	void Draw();

private:
	int elements_num;
};

#endif /* SCREEN_H_ */
