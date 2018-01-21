/*
 * Utils.h
 *
 *  Created on: Jan 2, 2018
 *      Author: robert
 */

#ifndef UTILS_H_
#define UTILS_H_


#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <termios.h>
#include <iostream>

int Initport(int fd);
int OpenPort(std::string port);

void SendFrame(std::string port);

struct
{
	int red, blue, fan, crio;
} settings;

#endif /* UTILS_H_ */
