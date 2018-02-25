/*
 * Touch.cpp
 *
 *  Created on: Nov 1, 2017
 *      Author: robert
 */

#include "../inc/Touch.h"
#include "../inc/ConfigReader.h"

int main_touch(std::unique_ptr<Control>&control,Touch touch, std::unique_ptr<GUI>&gui,std::unique_ptr<ConfigReader>&config) {
	int change = -1;
	switch (touch.screen) {
	case 0: {
		change = Screen0_callback(control,touch, gui, config);
		break;
	}
	case 1: {
		change = Screen1_callback(control,touch, gui,config);
		break;
	}
	case 2: {
		change = Screen2_callback(control,touch, gui,config);
		break;
	}
	case 3: {
		change = Screen3_callback(control,touch, gui,config);
		break;
	}
	case 4: {
		change = Screen4_callback(control,touch, gui,config);
		break;
	}
	}
	return change;
}

int Screen0_callback(std::unique_ptr<Control>&control,Touch touch, std::unique_ptr<GUI>&gui,std::unique_ptr<ConfigReader>&config) {
	std::cout << touch.id << std::endl;
	return 0;
}

int Screen1_callback(std::unique_ptr<Control>&control,Touch touch, std::unique_ptr<GUI>&gui,std::unique_ptr<ConfigReader>&config) {
	if (touch.id == "diag"&&gui->enable==true) {
		gui->actual_screen = 3;
		return 0;
	} else if (touch.id == "manual"&&gui->enable==true) {
		gui->actual_screen = 2;
		return 0;
	} else if (touch.id == "else"&&gui->enable==true) {
		gui->actual_screen = 4;
		return 0;
	}
	else if (touch.id == "hot"&&gui->enable==true) {
		gui->screen_vector[1]->trackbarChangeValue(1,10);
		return 1;
	}
	else if (touch.id == "crio"&&gui->enable==true) {
		gui->screen_vector[1]->trackbarChangeValue(4,10);
        return 2;
	}
    else if (touch.id == "reset") {
        return 12;
    }
	return -1;
}

int Screen2_callback(std::unique_ptr<Control>&control,Touch touch, std::unique_ptr<GUI>&gui,std::unique_ptr<ConfigReader>&config) {

    static int time=0;
    static int red=0;
    static int blue=0;

	if (touch.id == "ret") {
		gui->actual_screen = 1;
        time=0;
        red=0;
        blue=0;
		return 0;
	}

	else if (touch.id == "start") {
		gui->actual_screen = 1;
		gui->screen_vector[1]->trackbarChangeValue(2,10);
        gui->screen_vector[1]->trackbarChangeValue(0,11);

        time=std::min(std::max(time,0),100);
        red=std::min(std::max(red,0),100);
        blue=std::min(std::max(blue,0),100);

        std::fstream file;

        file.open(config->config.custom_program_path+"manual");
        std::string buffer=std::to_string(time*10)+"\r\n";
        file.write(buffer.c_str(),buffer.size());

        std::vector<std::string>signals;

        int timeRed;
        if(blue!=0) {
            timeRed = (red / blue) * time ;
        }
        else
        {
            timeRed=100;
        }

        int timeBlue = time - timeRed;

        for(int i=0;i<10;i++)
        {
            char buf[30];
            sprintf(buf,"NASTAWA%03d-%02d:%03d-%02d:%01d:%01d\r\n",100,5,0,5,0,0);
            signals.push_back(buf);
            signals.push_back(std::to_string(timeRed)+"\r\n");
            sprintf(buf,"NASTAWA%03d-%02d:%03d-%02d:%01d:%01d\r\n",0,5,100,5,1,1);
            signals.push_back(buf);
            signals.push_back(std::to_string(timeBlue)+"\r\n");
        }
        for(int i=0;i<signals.size();i++)
        {
            file.write(signals[i].c_str(),signals[i].size());
        }

        file.close();

        return 3;
	}
	else if (touch.id == "plus1") {
        red+=10;
        blue=100-red;
        red=std::min(std::max(red,0),100);
        blue=std::min(std::max(blue,0),100);

        gui->screen_vector[gui->actual_screen]->element_vector[8]->changeValue(
				red, 1);
		;
        gui->screen_vector[gui->actual_screen]->element_vector[9]->changeValue(
                blue, 1);
        ;
		return 0;
	} else if (touch.id == "plus2"){
        blue+=10;
        red=100-blue;
        red=std::min(std::max(red,0),100);
        blue=std::min(std::max(blue,0),100);

        gui->screen_vector[gui->actual_screen]->element_vector[9]->changeValue(
				blue, 1);
		;
        gui->screen_vector[gui->actual_screen]->element_vector[8]->changeValue(
                red, 1);
        ;
		return 0;
	} else if (touch.id == "plus3") {
        time+=10;
		gui->screen_vector[gui->actual_screen]->element_vector[10]->changeValue(
				time, 1);
		;
		return 0;
	}
    else if (touch.id == "minus1") {
        red-=10;
        blue=100-red;
        red=std::min(std::max(red,0),100);
        blue=std::min(std::max(blue,0),100);

        gui->screen_vector[gui->actual_screen]->element_vector[8]->changeValue(
                red, 1);
        ;
        gui->screen_vector[gui->actual_screen]->element_vector[9]->changeValue(
                blue, 1);
        ;
        return 0;
    } else if (touch.id == "minus2") {
        blue-=10;
        red=100-blue;
        red=std::min(std::max(red,0),100);
        blue=std::min(std::max(blue,0),100);

        gui->screen_vector[gui->actual_screen]->element_vector[9]->changeValue(
                blue, 1);
        ;
        gui->screen_vector[gui->actual_screen]->element_vector[8]->changeValue(
                red, 1);
        ;
        return 0;
    } else if (touch.id == "minus3") {
        time-=10;
        gui->screen_vector[gui->actual_screen]->element_vector[10]->changeValue(
                time, 1);
        ;
        return 0;
    }
	return -1;
}

int Screen3_callback(std::unique_ptr<Control>&control,Touch touch, std::unique_ptr<GUI>&gui,std::unique_ptr<ConfigReader>&config) {
	if (touch.id == "ret") {
		gui->actual_screen = 1;
		SendFrame(config->config.usbPort,0,0,0,0,5);
		control->red=0;
		control->blue=0;
		control->fan=0;
		control->crio=0;

		return 0;
	} else if (touch.id == "on1") {
		control->red=100;
	} else if (touch.id == "off1") {
		control->red=0;
	} else if (touch.id == "on2") {
		control->blue=100;
	} else if (touch.id == "off2") {
		control->blue=0;
	} else if (touch.id == "on3") {
		control->fan=1;
	} else if (touch.id == "off3") {
		control->fan=0;
	} else if (touch.id == "push") {
		control->crio=1;

        std::fstream file;
        file.open(config->crioPath);

        std::string number;
        getline(file,number);

        int num=std::stoi(number);
        file.close();
        num++;

        file.open(config->crioPath);

        std::string out=std::to_string(num);

        file.write(out.c_str(),out.size());
        file.close();

    }
	SendFrame(config->config.usbPort,control->blue,control->red,control->fan,control->crio,5);
	control->crio=0;

	return -1;
}

int Screen4_callback(std::unique_ptr<Control>&control,Touch touch, std::unique_ptr<GUI>&gui,std::unique_ptr<ConfigReader>&config) {
	if (touch.id == "ret") {
		gui->actual_screen = 1;
		return 0;
	} else {
		gui->screen_vector[1]->trackbarChangeValue(3,10);
        gui->screen_vector[1]->trackbarChangeValue(0,11);
        gui->actual_screen = 1;
	}

    if(touch.id == "pr1")
    {
        return 4;
    }
    else if(touch.id == "pr2")
    {
        return 5;
    }
    else if(touch.id == "pr3")
    {
        return 6;
    }
    else if(touch.id == "pr4")
    {
        return 7;
    }
    else if(touch.id == "pr5")
    {
        return 8;
    }
    else if(touch.id == "pr6")
    {
        return 9;
    }
    else if(touch.id == "pr7")
    {
        return 10;
    }
    else if(touch.id == "pr8")
    {
        return 11;
    }
	return -1;
}

