/*
 * Button.h
 *
 *  Created on: Oct 18, 2017
 *      Author: robert
 */

#ifndef BUTTON_H_
#define BUTTON_H_

#include <string>

class Button {
public:
	Button(std::string path);
	virtual ~Button();

	void draw();
};

#endif /* BUTTON_H_ */
