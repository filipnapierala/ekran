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

void SendFrame(std::string port,int red,int blue, int fan, int crio);

#endif /* UTILS_H_ */
