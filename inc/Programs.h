//
// Created by studiofigura on 13.02.18.
//

#ifndef OPERATOR_HMI_PROGRAMS_H
#define OPERATOR_HMI_PROGRAMS_H


#include <string>
#include <chrono>
#include <iostream>
#include <fstream>

class Programs {

public:

    Programs();
    virtual ~Programs();

    std::string ProgramName;
    int ActualTime,OverallTime;
    int Refresh();
    void SetProgram(std::string path);
    void Stop();
    void Start();

private:

    std::fstream file;
    std::chrono::steady_clock::time_point start,stop;
};


#endif //OPERATOR_HMI_PROGRAMS_H
