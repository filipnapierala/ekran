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
#include "inc/ConfigReader.h"
#include "inc/Control.h"
#include "inc/Programs.h"

#define FrameTime 40
//#define intro

bool move = false;
bool touch_flag = false;

auto config = std::make_unique<ConfigReader>("./data/config/config.yml");
auto control = std::make_unique<Control>();
auto programs = std::make_unique<Programs>();


auto gui2 = std::make_unique<GUI>("./data/Screen2/img/"+config->config.language,"2",1280,0);
auto gui1 = std::make_unique<GUI>("./data/Screen1/img/"+config->config.language,"1",0,0);


Touch touch;

void touch_callback(int event, int x, int y, int flags, void*) {

	if (event == 1) {
		touch.n_1 = touch.n;
		touch.id = gui1->screen_vector[gui1->actual_screen]->touch_callback(x, y,
				touch.n);
		touch.x = x;
		touch.y = y;
		touch.previous_event = touch.event;
		touch.event = event;
		touch.screen = gui1->actual_screen;

		if (touch.id != " ") {
			gui1->screen_vector[gui1->actual_screen]->element_vector[touch.n]->pushed =
					true;
		}
	}
	if (event == 4) {
		touch.n_1 = touch.n;
		touch.id = gui1->screen_vector[gui1->actual_screen]->touch_callback(x, y,
				touch.n);
		touch.x = x;
		touch.y = y;
		touch.previous_event = touch.event;
		touch.event = event;
		touch.screen = gui1->actual_screen;

        gui1->screen_vector[gui1->actual_screen]->element_vector[touch.n_1]->pushed =
                false;
        gui1->screen_vector[gui1->actual_screen]->element_vector[touch.n]->pushed =
                false;

     if (touch.id != " ") {
			touch_flag = true;
		}
	}
}

void screen0() {
	gui1->add_screen();

	gui1->screen_vector[gui1->actual_screen]->add_video("/intro", 0, 0, "intro",1280,800);
}

void screen1() {
	gui1->add_screen();

	gui1->screen_vector[gui1->actual_screen]->add_button("/crio", 50, 25, "crio");
	gui1->screen_vector[gui1->actual_screen]->add_button("/hot", 150, 250, "hot");
	gui1->screen_vector[gui1->actual_screen]->add_button("/manual", 340, 350,
			"manual");
	gui1->screen_vector[gui1->actual_screen]->add_button("/else", 0, 460, "else");
	gui1->screen_vector[gui1->actual_screen]->add_button("/diag", 1215, 35,
			"diag");
	gui1->screen_vector[gui1->actual_screen]->add_button("/reset", 1180, 700,
			"reset");

	gui1->screen_vector[gui1->actual_screen]->add_image("/alarm", 1170, 37,
			"alarm");

#define x 920
	gui1->screen_vector[gui1->actual_screen]->add_image("/fan", x - 220, 480,
			"fan");
	gui1->screen_vector[gui1->actual_screen]->add_image("/red", x - 75, 500,
			"red");
	gui1->screen_vector[gui1->actual_screen]->add_image("/blue", x + 25, 500,
			"blue");
	gui1->screen_vector[gui1->actual_screen]->add_image("/pr", x + 145, 480,
			"pr");

	gui1->screen_vector[gui1->actual_screen]->add_video("/vid", 600, 100, "video", 640, 360, true);
}

void screen2() {
	gui1->add_screen();
#undef x
#define x 640
#define y 400
	gui1->screen_vector[gui1->actual_screen]->add_button("/ret", 1130, 0, "ret");
	gui1->screen_vector[gui1->actual_screen]->add_button("/start", 0, 650,
			"start");

	gui1->screen_vector[gui1->actual_screen]->add_button("/minus", x - 490,
			y - 75, "minus1");
	gui1->screen_vector[gui1->actual_screen]->add_button("/minus", x - 490, y - 5,
			"minus2");
	gui1->screen_vector[gui1->actual_screen]->add_button("/minus", x - 490,
			y + 65, "minus3");
	gui1->screen_vector[gui1->actual_screen]->add_button("/plus", x + 460, y - 85,
			"plus1");
	gui1->screen_vector[gui1->actual_screen]->add_button("/plus", x + 460, y - 15,
			"plus2");
	gui1->screen_vector[gui1->actual_screen]->add_button("/plus", x + 460, y + 55,
			"plus3");

	gui1->screen_vector[gui1->actual_screen]->add_trackbar("/r1", "/s1", 240,
			y - 80, 255, "trackbar1");
	gui1->screen_vector[gui1->actual_screen]->add_trackbar("/r1", "/s1", 240,
			y - 10, 255, "trackbar2");
	gui1->screen_vector[gui1->actual_screen]->add_trackbar("/r1", "/s1", 240,
			y + 60, 255, "trackbar3");

	gui1->screen_vector[gui1->actual_screen]->add_image("/hot", 40, y - 85,
			"hot");
	gui1->screen_vector[gui1->actual_screen]->add_image("/cold", 40, y - 15,
			"cold");
	gui1->screen_vector[gui1->actual_screen]->add_image("/time", 40, y + 55,
			"time");
}

void screen3() {
	gui1->add_screen();

	gui1->screen_vector[gui1->actual_screen]->add_button("/ret", 1130, 0, "ret");
#undef y
#define y 213
	gui1->screen_vector[gui1->actual_screen]->add_button("/on", x - 282, y,
			"on1");
	gui1->screen_vector[gui1->actual_screen]->add_button("/off", x - 187, y,
			"off1");
	gui1->screen_vector[gui1->actual_screen]->add_button("/on", x + 113, y,
			"on2");
	gui1->screen_vector[gui1->actual_screen]->add_button("/off", x + 213, y,
			"off2");
#undef y
#define y 613	
	gui1->screen_vector[gui1->actual_screen]->add_button("/on", x - 282, y,
			"on3");
	gui1->screen_vector[gui1->actual_screen]->add_button("/off", x - 187, y,
			"off3");
	gui1->screen_vector[gui1->actual_screen]->add_button("/push", x + 150, y - 13,
			"push");
#undef y
#define y 400
	gui1->screen_vector[gui1->actual_screen]->add_image("/blue", x - 225, y - 262,
			"blue");
	gui1->screen_vector[gui1->actual_screen]->add_image("/red", x + 175, y - 262,
			"red");
	gui1->screen_vector[gui1->actual_screen]->add_image("/fan", x - 225, y + 138,
			"fan");
	gui1->screen_vector[gui1->actual_screen]->add_image("/crio", x + 175, y + 138,
			"crio");
}

void screen4() {
	gui1->add_screen();
#undef y
#define y 220
	gui1->screen_vector[gui1->actual_screen]->add_button("/ret", 1130, 0, "ret");
	gui1->screen_vector[gui1->actual_screen]->add_button("/pr1", x - 500, y,
			"pr1");
	gui1->screen_vector[gui1->actual_screen]->add_button("/pr2", x - 200, y,
			"pr2");
	gui1->screen_vector[gui1->actual_screen]->add_button("/pr3", x + 100, y,
			"pr3");
	gui1->screen_vector[gui1->actual_screen]->add_button("/pr4", x + 400, y,
			"pr4");
#undef y
#define y 480
	gui1->screen_vector[gui1->actual_screen]->add_button("/pr5", x - 500, y,
			"pr5");
	gui1->screen_vector[gui1->actual_screen]->add_button("/pr6", x - 200, y,
			"pr6");
	gui1->screen_vector[gui1->actual_screen]->add_button("/pr7", x + 100, y,
			"pr7");
	gui1->screen_vector[gui1->actual_screen]->add_button("/pr8", x + 400, y,
			"pr8");
}


void screen5() {
	gui2->add_screen();
	gui2->screen_vector[gui2->actual_screen]->add_video("/intro", 0, 0, "intro",1280,800);
}

void screen6() {
	gui2->add_screen();
	gui2->screen_vector[gui2->actual_screen]->add_video("/vid", 0, 0, "video", 1280, 800);
}

void ProgramTimer()
{
    for(;;)
    {
        std::this_thread::sleep_for(std::chrono::seconds(programs->ActualTime));
        if(programs->isEnd==false) {
            programs->Refresh();
        }
    }
}

int main() {


    system("./data/scripts/config.sh");

	cv::setMouseCallback("1", touch_callback);

	screen0();
	screen1();
	screen2();
	screen3();
	screen4();

	screen5();
	screen6();

	gui1->actual_screen = 0;
	gui2->actual_screen = 0;

#ifdef intro
	//comment to disable intro
	system(("mplayer -vo null "+gui1->path+"/s0/intro.avi &").c_str());
	while(gui1->screen_vector[gui1->actual_screen]->element_vector[0]->is_end==0)
	{
		std::chrono::steady_clock::time_point begin=std::chrono::steady_clock::now();
		gui1->draw_screen();
		gui2->draw_screen();
		cv::waitKey(1);
		std::chrono::steady_clock::time_point end=std::chrono::steady_clock::now();
		auto count=std::chrono::duration_cast<std::chrono::milliseconds>(end-begin).count();
		if(count<FrameTime)
		{
			cv::waitKey(FrameTime-count);
		}
	}
#endif
	gui1->actual_screen = 1;
	gui2->actual_screen = 1;

    programs->SetProgram(config->config.custom_program_path+"crio");

    std::thread(ProgramTimer).detach();

while(1)
{
	std::chrono::steady_clock::time_point begin=std::chrono::steady_clock::now();
	gui2->draw_screen();

	gui1->draw_screen();

	char key=cv::waitKey(1);
	if(key=='d')
	{
		gui1->turnBoxes();
	}
	else if(key=='a')
	{
		break;
	}

	if(gui1->actual_screen==1)
	{
		gui1->screen_vector[gui1->actual_screen]->change_value(7);
	}

	if(touch_flag==true)
	{
		touch_flag=false;
		main_touch(control,touch,gui1,config);
	}
	std::chrono::steady_clock::time_point end=std::chrono::steady_clock::now();
	auto count=std::chrono::duration_cast<std::chrono::milliseconds>(end-begin).count();
	if(count<FrameTime)
	{
		cv::waitKey(FrameTime-count);
	}
	//std::cout<<"fps: "<<1000/double(count)<<std::endl;
}

//		if(frame.cols==0)
//		{
//			capture.set(CV_CAP_PROP_POS_AVI_RATIO,0);
//			capture>>frame;
//		}

return 0;
}
