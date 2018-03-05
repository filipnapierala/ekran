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

    Programs(std::string path);
    virtual ~Programs();

    std::string ProgramName;
    int ActualTime, FutureTime, OverallTime;
    bool isEnd;
    int Refresh();

    void SetProgramID(int ID);
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
    void SetProgram(std::string path);

    std::fstream file;
    std::string actualCommand, futureCommand, actualProgram;
    std::string path;
};


#endif //OPERATOR_HMI_PROGRAMS_H
