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

int initport(int fd);
int open_port(std::string port);

#endif /* UTILS_H_ */
