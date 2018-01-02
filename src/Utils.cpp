/*
 * Utils.cpp
 *
 *  Created on: Jan 2, 2018
 *      Author: robert
 */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <termios.h>
#include <iostream>
#include "../inc/Utils.h"

int initport(int fd) {
	struct termios options;
	// Get the current options for the port...
	tcgetattr(fd, &options);
	// Set the baud rates to 115200...
	cfsetospeed(&options, B2000000);
	// Enable the receiver and set local mode...
	options.c_cflag |= (CLOCAL | CREAD);

	//disable hardware flow control
	options.c_cflag &= ~CRTSCTS;

	//disable software flow control
	options.c_iflag &= ~(IXON | IXOFF | IXANY);

	//raw input
	options.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG);

	//raw output
	options.c_oflag &= ~OPOST;

	//No parity - 8N1
	options.c_cflag &= ~PARENB;
	options.c_cflag &= ~CSTOPB;
	options.c_cflag &= ~CSIZE;
	options.c_cflag |= CS8;

	// Set the new options for the port...
	tcsetattr(fd, TCSANOW, &options);

	return 1;
}

int open_port(char* dev) {

	int fd = open(dev, O_RDWR | O_NOCTTY | O_NDELAY);
	if (fd == -1) {
		perror("open_port: Unable to open /dev/ttyUSB0");
		std::cout << "!!!error!!!" << std::endl;
	} else
		fcntl(fd, F_SETFL, 0);

	return (fd);
}
