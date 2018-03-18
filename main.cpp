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

bool touch_flag = false;

bool fan=false;

auto config = std::make_unique<ConfigReader>("./data/config");
auto control = std::make_unique<Control>();
auto programs = std::make_unique<Programs>(config->config.custom_program_path,config->config.usbPort);

auto gui2 = std::make_unique<GUI>("./data/Screen2/"+config->config.language,"2",1280,0);
auto gui1 = std::make_unique<GUI>("./data/Screen1/"+config->config.language,"1",0,0);

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
	gui1->screen_vector[gui1->actual_screen]->add_button("/stop", 1180, 700,
			"stop");

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
//nowe
	gui1->screen_vector[gui1->actual_screen]->add_button("/pause", 1120, 700,
			"pause");
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
			y - 300, "minus1");//do usuniecia
	gui1->screen_vector[gui1->actual_screen]->add_button("/minus", x - 490, 
			y - 160, "minus2");
	gui1->screen_vector[gui1->actual_screen]->add_button("/minus", x - 490,
			y + 140, "minus3");
	gui1->screen_vector[gui1->actual_screen]->add_button("/plus", x + 460, y - 300,
			"plus1");//do usuniecia
	gui1->screen_vector[gui1->actual_screen]->add_button("/plus", x + 460, y - 175,
			"plus2");
	gui1->screen_vector[gui1->actual_screen]->add_button("/plus", x + 460, y + 125,
			"plus3");

	gui1->screen_vector[gui1->actual_screen]->add_trackbar("/r1", "/s1", 240,
			y - 300, 100, "trackbar1");//do usuniecia
	gui1->screen_vector[gui1->actual_screen]->add_trackbar("/r1", "/s1", 240,
			y - 160, 100, "trackbar2");
	gui1->screen_vector[gui1->actual_screen]->add_trackbar("/r1", "/s1", 240,
			y + 140, 100, "trackbar3");

	gui1->screen_vector[gui1->actual_screen]->add_image("/hot", 40, y - 165,
			"hot");
	gui1->screen_vector[gui1->actual_screen]->add_image("/cold", 1190, y - 165,
			"cold");
	gui1->screen_vector[gui1->actual_screen]->add_image("/time", 40, y + 135,
			"time");
//nowe
//hot/cold
	//gui1->screen_vector[gui1->actual_screen]->add_image("/podz", x-400, y - 175, "podz1");
	gui1->screen_vector[gui1->actual_screen]->add_image("/podz", x-300, y - 175, "podz2");
	gui1->screen_vector[gui1->actual_screen]->add_image("/podz", x-200, y - 175, "podz3");
	gui1->screen_vector[gui1->actual_screen]->add_image("/podz", x-100, y - 175, "podz4");
	gui1->screen_vector[gui1->actual_screen]->add_image("/podz", x, y - 175, "podz5");
	gui1->screen_vector[gui1->actual_screen]->add_image("/podz", x+100, y - 175, "podz6");
	gui1->screen_vector[gui1->actual_screen]->add_image("/podz", x+200, y - 175, "podz7");
	gui1->screen_vector[gui1->actual_screen]->add_image("/podz", x+300, y - 175, "podz8");
	//gui1->screen_vector[gui1->actual_screen]->add_image("/podz", x+400, y - 175, "podz9");
//time
	//gui1->screen_vector[gui1->actual_screen]->add_image("/podz", x-400, y + 125, "podz10");
	gui1->screen_vector[gui1->actual_screen]->add_image("/podz", x-240, y + 125, "podz11");
	gui1->screen_vector[gui1->actual_screen]->add_image("/podz", x-80, y + 125, "podz12");
	gui1->screen_vector[gui1->actual_screen]->add_image("/podz", x+80, y + 125, "podz13");
	gui1->screen_vector[gui1->actual_screen]->add_image("/podz", x+240, y + 125, "podz14");
	//gui1->screen_vector[gui1->actual_screen]->add_image("/podz", x+400, y + 125, "podz16");
//napisy
	gui1->screen_vector[gui1->actual_screen]->add_image("/max", x-440, y - 120, "max1");
	gui1->screen_vector[gui1->actual_screen]->add_image("/max", x+360, y - 120, "max2");
	gui1->screen_vector[gui1->actual_screen]->add_image("/5050", x-50, y - 120, "5050");
	gui1->screen_vector[gui1->actual_screen]->add_image("/7030", x-250, y - 120, "7030");
	gui1->screen_vector[gui1->actual_screen]->add_image("/3070", x+150, y - 120, "3070");

	gui1->screen_vector[gui1->actual_screen]->add_image("/5", x-425, y + 180, "5");
	gui1->screen_vector[gui1->actual_screen]->add_image("/10", x-265, y + 180, "10");
	gui1->screen_vector[gui1->actual_screen]->add_image("/15", x-105, y + 180, "15");
	gui1->screen_vector[gui1->actual_screen]->add_image("/20", x+55, y + 180, "20");
	gui1->screen_vector[gui1->actual_screen]->add_image("/25", x+215, y + 180, "25");
	gui1->screen_vector[gui1->actual_screen]->add_image("/30", x+375, y + 180, "30");
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
	gui1->screen_vector[gui1->actual_screen]->add_button("/reset", 1180, 700,
			"reset");

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
//nowe
	gui1->screen_vector[gui1->actual_screen]->add_image("/video", x - 525, y -262,
			"video");
	gui1->screen_vector[gui1->actual_screen]->add_button("/v1", x - 537, y-162,
			"v1");
	gui1->screen_vector[gui1->actual_screen]->add_button("/v2", x - 537, y-62,
			"v2");
	gui1->screen_vector[gui1->actual_screen]->add_button("/v3", x - 537, y+38,
			"v3");
	gui1->screen_vector[gui1->actual_screen]->add_button("/v4", x - 537, y+138,
			"v4");
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
	//gui2->screen_vector[gui2->actual_screen]->add_video("/intro", 0, 0, "intro",1280,800);
}

void screen6() {
	gui2->add_screen();
	gui2->screen_vector[gui2->actual_screen]->add_video("/vid", 0, 0, "video", 1280, 800);

    gui2->screen_vector[gui2->actual_screen]->add_image("/blue", 1100, 30,
                                                        "blue");
    gui2->screen_vector[gui2->actual_screen]->add_image("/red", 1200, 30,
                                                        "red");
    gui2->screen_vector[gui2->actual_screen]->add_image("/digit", 600, 700,
                                                        "digit1");
    gui2->screen_vector[gui2->actual_screen]->add_image("/digit", 620, 700,
                                                        "digit2");
    gui2->screen_vector[gui2->actual_screen]->add_image("/sep", 640, 700,
                                                        "separator");
    gui2->screen_vector[gui2->actual_screen]->add_image("/digit", 660, 700,
                                                        "digit3");
    gui2->screen_vector[gui2->actual_screen]->add_image("/digit", 680, 700,
                                                        "digit4");
}

void setClock(int seconds, std::unique_ptr<GUI>&gui)
{
    int minutesDecimal, minutesUnit, secondsDecimal, secondsUnit;

    minutesDecimal=(seconds/60)/10;
    minutesUnit=(seconds/60)%10;

    secondsDecimal=(seconds-((10*minutesDecimal+minutesUnit)*60))/10;
    secondsUnit=(seconds-((10*minutesDecimal+minutesUnit)*60))-(secondsDecimal*10);

	gui->screen_vector[1]->setImage(minutesDecimal,3);
	gui->screen_vector[1]->setImage(minutesUnit,4);
	gui->screen_vector[1]->setImage(secondsDecimal,6);
	gui->screen_vector[1]->setImage(secondsUnit,7);
}

void Clock()
{
    for(;;) {

        if (gui1->enable == true) {
            gui2->screen_vector[1]->setImage(0,1);
            gui2->screen_vector[1]->setImage(0,2);std::this_thread::sleep_for(std::chrono::microseconds(1));
        } else {
            if (programs->isEnd == false) {
                std::this_thread::sleep_for(std::chrono::seconds(1));
                int time = programs->GetTime();
                if (time >= 0) {
                    setClock(time, gui2);
                }
            }
        }
    }
}

void ProgramTimer()
{
    for(;;) {
        if (gui1->enable == true) {
            std::this_thread::sleep_for(std::chrono::microseconds(1));
        } else {

            for(int i=0;i<(programs->ActualTime-2)*2;i++)
            {
                if (programs->isEnd == false) {
                    std::this_thread::sleep_for(std::chrono::milliseconds(500));
                }
            }

            if (programs->signals.redFuture == true) {
                gui2->screen_vector[1]->setImage(1, 2);
            }
            if (programs->signals.blueFuture == true) {
                gui2->screen_vector[1]->setImage(1, 1);
            }

            for(int i=0;i<4;i++)
            {
                if (programs->isEnd == false) {
                    std::this_thread::sleep_for(std::chrono::milliseconds(500));
                }
            }
            //std::this_thread::sleep_for(std::chrono::seconds(2));

            if (programs->isEnd == false) {

                programs->Refresh();

                gui1->screen_vector[1]->setImage(0, 8);
                gui1->screen_vector[1]->setImage(0, 9);

                gui2->screen_vector[1]->setImage(0, 1);
                gui2->screen_vector[1]->setImage(0, 2);
                fan = false;

                if (programs->signals.redActual == true) {
                    gui1->screen_vector[1]->setImage(1, 8);
                }
                if (programs->signals.blueActual == true) {
                    gui1->screen_vector[1]->setImage(1, 9);
                }
                if (programs->signals.fan == true) {
                    fan = true;
                }
            }
        }
    }
}

int main() {

    int f=system("./data/scripts/config.sh");

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
    gui1->screen_vector[0]->VideoStart(0);
    gui2->screen_vector[0]->VideoStart(0);
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

    std::thread(ProgramTimer).detach();
    std::thread(Clock).detach();

    if(config->config.crioVolume<0)
    {
        gui1->screen_vector[1]->setImage(1,6);
    }

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

	if(gui1->actual_screen==1&&fan==true)
    {
		gui1->screen_vector[gui1->actual_screen]->change_value(7);
	}

	if(touch_flag==true)
	{
		touch_flag=false;
		int signal=main_touch(control,touch,gui1,config);

        if(signal==12)
        {
			gui1->screen_vector[gui1->actual_screen]->element_vector[0]->active =
					true;
			gui1->screen_vector[gui1->actual_screen]->element_vector[1]->active =
					true;
			gui1->screen_vector[gui1->actual_screen]->element_vector[2]->active =
					true;
			gui1->screen_vector[gui1->actual_screen]->element_vector[3]->active =
					true;
			gui1->screen_vector[gui1->actual_screen]->element_vector[4]->active =
					true;

            gui1->enable=true;

            gui1->screen_vector[1]->setImage(0,8);
            gui1->screen_vector[1]->setImage(0,9);

            gui2->screen_vector[1]->setImage(0,1);
            gui2->screen_vector[1]->setImage(0,2);

            gui1->screen_vector[1]->setImage(0,10);

            fan=false;
            programs->Stop();
            setClock(0,gui2);
        }
		else if(signal==13)
		{
			programs->Pause();
			gui1->screen_vector[1]->VideoToggle(11);
			gui2->screen_vector[1]->VideoToggle(0);
		}

        else if((signal>=1&&signal<=11)&&gui1->enable==true)
        {
            gui1->enable=false;
            programs->SetProgramID(signal);
            gui1->screen_vector[1]->VideoStart(11);
            gui2->screen_vector[1]->VideoStart(0);

			gui1->screen_vector[gui1->actual_screen]->element_vector[0]->active =
					false;
			gui1->screen_vector[gui1->actual_screen]->element_vector[1]->active =
					false;
			gui1->screen_vector[gui1->actual_screen]->element_vector[2]->active =
					false;
			gui1->screen_vector[gui1->actual_screen]->element_vector[3]->active =
					false;
			gui1->screen_vector[gui1->actual_screen]->element_vector[4]->active =
					false;
		}
	}

    if(programs->isEnd==true){
        gui1->enable=true;
        programs->Stop();

        gui1->screen_vector[1]->VideoStop(11);
        gui2->screen_vector[1]->VideoStop(0);

        gui1->screen_vector[1]->setImage(0,10);
    }

	std::chrono::steady_clock::time_point end=std::chrono::steady_clock::now();
	auto count=std::chrono::duration_cast<std::chrono::milliseconds>(end-begin).count();
	if(count<FrameTime)
	{
		cv::waitKey(FrameTime-count);
	}
	//std::cout<<"fps: "<<1000/double(count)<<std::endl;
}

return 0;
}
