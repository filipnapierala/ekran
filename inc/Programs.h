//
// Created by studiofigura on 13.02.18.
//

#ifndef OPERATOR_HMI_PROGRAMS_H
#define OPERATOR_HMI_PROGRAMS_H


#include <string>
#include <chrono>
#include <iostream>
#include <fstream>
#include <thread>


class Programs {

public:

    Programs();
    virtual ~Programs();

    std::string ProgramName;
    int ActualTime, FutureTime, OverallTime;
    bool isEnd;
    int Refresh();
    void SetProgram(std::string path);
    void Stop();
    void Start();

    struct Signals
    {
        bool blueActual;
        bool redActual;
        bool fan;

        bool blueFuture;
        bool redFuture;
    }signals;

private:

    void Parse();
    void Send();
    void ClearSignals();

    std::fstream file;
    std::chrono::steady_clock::time_point start,stop;
    std::string actualCommand, futureCommand;
};


#endif //OPERATOR_HMI_PROGRAMS_H
