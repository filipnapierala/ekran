/*
 * main.cpp
 *
 *  Created on: Jul 31, 2017
 *  Author: robert
 */

#include <iostream>
#include <thread>
#include <string>
#include <memory>
#include <chrono>

#include "inc/Utils.h"
#include "inc/Touch.h"

bool move = false;
bool touch_flag = false;

auto gui = std::make_unique<GUI>("./data");

Touch touch;

void touch_callback(int event, int x, int y, int flags, void*) {
	if (event == 1) {
		touch.n_1 = touch.n;
		touch.id = gui->screen_vector[gui->actual_screen]->touch_callback(x, y,
				touch.n);
		touch.x = x;
		touch.y = y;
		touch.previous_event = touch.event;
		touch.event = event;
		touch.screen = gui->actual_screen;

		if (touch.id != " ") {
			gui->screen_vector[gui->actual_screen]->element_vector[touch.n]->pushed =
					!gui->screen_vector[gui->actual_screen]->element_vector[touch.n]->pushed;
		}
	}
	if (event == 4) {
		touch.n_1 = touch.n;
		touch.id = gui->screen_vector[gui->actual_screen]->touch_callback(x, y,
				touch.n);
		touch.x = x;
		touch.y = y;
		touch.previous_event = touch.event;
		touch.event = event;
		touch.screen = gui->actual_screen;

		if (touch.id == " ") {
			gui->screen_vector[gui->actual_screen]->element_vector[touch.n_1]->pushed =
					false;
		} else if (touch.id != " ") {
			gui->screen_vector[gui->actual_screen]->element_vector[touch.n]->pushed =
					!gui->screen_vector[gui->actual_screen]->element_vector[touch.n]->pushed;
			touch_flag = true;
		}
	}
}

void screen0() {
	gui->add_screen();

	gui->screen_vector[gui->actual_screen]->add_video("/intro", 0, 0, "intro");
}

void screen1() {
	gui->add_screen();

	gui->screen_vector[gui->actual_screen]->add_button("/crio", 50, 25, "crio");
	gui->screen_vector[gui->actual_screen]->add_button("/hot", 150, 250, "hot");
	gui->screen_vector[gui->actual_screen]->add_button("/manual", 340, 350,
			"manual");
	gui->screen_vector[gui->actual_screen]->add_button("/else", 0, 460, "else");
	gui->screen_vector[gui->actual_screen]->add_button("/diag", 1215, 35,
			"diag");
	gui->screen_vector[gui->actual_screen]->add_button("/reset", 1180, 700,
			"reset");

	gui->screen_vector[gui->actual_screen]->add_image("/alarm", 1170, 37,
			"alarm");

#define x 920
	gui->screen_vector[gui->actual_screen]->add_image("/fan", x - 220, 480,
			"fan");
	gui->screen_vector[gui->actual_screen]->add_image("/red", x - 75, 500,
			"red");
	gui->screen_vector[gui->actual_screen]->add_image("/blue", x + 25, 500,
			"blue");
	gui->screen_vector[gui->actual_screen]->add_image("/pr", x + 145, 480,
			"pr");

	gui->screen_vector[gui->actual_screen]->add_video("/vid", 600, 100, "video",
			640, 360);
}

void screen2() {
	gui->add_screen();
#undef x
#define x 640
#define y 400
	gui->screen_vector[gui->actual_screen]->add_button("/ret", 1130, 0, "ret");
	gui->screen_vector[gui->actual_screen]->add_button("/start", 0, 650,
			"start");

	gui->screen_vector[gui->actual_screen]->add_button("/minus", x - 490,
			y - 75, "minus1");
	gui->screen_vector[gui->actual_screen]->add_button("/minus", x - 490, y - 5,
			"minus2");
	gui->screen_vector[gui->actual_screen]->add_button("/minus", x - 490,
			y + 65, "minus3");
	gui->screen_vector[gui->actual_screen]->add_button("/plus", x + 460, y - 85,
			"plus1");
	gui->screen_vector[gui->actual_screen]->add_button("/plus", x + 460, y - 15,
			"plus2");
	gui->screen_vector[gui->actual_screen]->add_button("/plus", x + 460, y + 55,
			"plus3");

	gui->screen_vector[gui->actual_screen]->add_trackbar("/r1", "/s1", 240,
			y - 80, 255, "trackbar1");
	gui->screen_vector[gui->actual_screen]->add_trackbar("/r1", "/s1", 240,
			y - 10, 255, "trackbar2");
	gui->screen_vector[gui->actual_screen]->add_trackbar("/r1", "/s1", 240,
			y + 60, 255, "trackbar3");

	gui->screen_vector[gui->actual_screen]->add_image("/hot", 40, y - 85,
			"hot");
	gui->screen_vector[gui->actual_screen]->add_image("/cold", 40, y - 15,
			"cold");
	gui->screen_vector[gui->actual_screen]->add_image("/time", 40, y + 55,
			"time");
}

void screen3() {
	gui->add_screen();

	gui->screen_vector[gui->actual_screen]->add_button("/ret", 1130, 0, "ret");
#undef y
#define y 213
	gui->screen_vector[gui->actual_screen]->add_button("/on", x - 282, y,
			"on1");
	gui->screen_vector[gui->actual_screen]->add_button("/off", x - 187, y,
			"off1");
	gui->screen_vector[gui->actual_screen]->add_button("/on", x + 113, y,
			"on2");
	gui->screen_vector[gui->actual_screen]->add_button("/off", x + 213, y,
			"off2");
#undef y
#define y 613	
	gui->screen_vector[gui->actual_screen]->add_button("/on", x - 282, y,
			"on3");
	gui->screen_vector[gui->actual_screen]->add_button("/off", x - 187, y,
			"off3");
	gui->screen_vector[gui->actual_screen]->add_button("/push", x + 150, y - 13,
			"push");
#undef y
#define y 400
	gui->screen_vector[gui->actual_screen]->add_image("/blue", x - 225, y - 262,
			"blue");
	gui->screen_vector[gui->actual_screen]->add_image("/red", x + 175, y - 262,
			"red");
	gui->screen_vector[gui->actual_screen]->add_image("/fan", x - 225, y + 138,
			"fan");
	gui->screen_vector[gui->actual_screen]->add_image("/crio", x + 175, y + 138,
			"crio");
}

void screen4() {
	gui->add_screen();
#undef y
#define y 220
	gui->screen_vector[gui->actual_screen]->add_button("/ret", 1130, 0, "ret");
	gui->screen_vector[gui->actual_screen]->add_button("/pr1", x - 500, y,
			"pr1");
	gui->screen_vector[gui->actual_screen]->add_button("/pr2", x - 200, y,
			"pr2");
	gui->screen_vector[gui->actual_screen]->add_button("/pr3", x + 100, y,
			"pr3");
	gui->screen_vector[gui->actual_screen]->add_button("/pr4", x + 400, y,
			"pr4");
#undef y
#define y 480
	gui->screen_vector[gui->actual_screen]->add_button("/pr5", x - 500, y,
			"pr5");
	gui->screen_vector[gui->actual_screen]->add_button("/pr6", x - 200, y,
			"pr6");
	gui->screen_vector[gui->actual_screen]->add_button("/pr7", x + 100, y,
			"pr7");
	gui->screen_vector[gui->actual_screen]->add_button("/pr8", x + 400, y,
			"pr8");
}

int main() {
	cv::setMouseCallback("", touch_callback);

	screen0();
	screen1();
	screen2();
	screen3();
	screen4();

	gui->actual_screen = 0;

	//comment to disable intro
//	while(gui->screen_vector[gui->actual_screen]->element_vector[0]->is_end==0)
//	{
//		gui->draw_screen();
//		cv::waitKey(1);
//	}
	gui->actual_screen = 1;

while(1)
{
	std::chrono::steady_clock::time_point begin=std::chrono::steady_clock::now();
	gui->draw_screen();

	char key=cv::waitKey(1);
	if(key=='d')
	{
		gui->turnBoxes();
	}
	else if(key=='a')
	{
		break;
	}

	if(gui->actual_screen==1)
	{
		gui->screen_vector[gui->actual_screen]->change_value(7);
	}

	if(touch_flag==true)
	{
		touch_flag=false;
		main_touch(touch,gui);
	}
	std::chrono::steady_clock::time_point end=std::chrono::steady_clock::now();
	auto count=std::chrono::duration_cast<std::chrono::milliseconds>(end-begin).count();
	//std::cout<<"fps: "<<1000/double(count)<<std::endl;
}

//		if(frame.cols==0)
//		{
//			capture.set(CV_CAP_PROP_POS_AVI_RATIO,0);
//			capture>>frame;
//		}

return 0;
}
