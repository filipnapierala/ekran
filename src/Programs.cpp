//
// Created by studiofigura on 13.02.18.
//

#include "../inc/Programs.h"

Programs::Programs()
{
    this->isEnd=true;
    this->ActualTime=1;

    this->actualCommand="";
    this->futureCommand="";
    this->ClearSignals();
}

Programs::~Programs() {}

void Programs::ClearSignals()
{
    this->signals.blueActual=false;
    this->signals.redActual=false;
    this->signals.fan=false;

    this->signals.redFuture=false;
    this->signals.blueFuture=false;
}

int Programs::Refresh()
{
//    this->stop=std::chrono::steady_clock::now();
//    auto count=std::chrono::duration_cast<std::chrono::seconds>(this->stop-this->start).count();
//    std::cout<<"Time is: "<<this->OverallTime+count<<std::endl;
//
//    if(count>=this->ActualTime)
//    {
            this->actualCommand=this->futureCommand;

            getline(this->file, this->futureCommand);
            std::cout << this->actualCommand << std::endl;
            std::cout << this->futureCommand << std::endl;

            std::string line;

            getline(this->file, line);
            std::cout << line << std::endl;

            this->Parse();

            if(this->futureCommand=="")
            {
                this->isEnd=true;
                this->file.close();
                return 0;
            }

            this->ActualTime = std::stoi(line);

        //this->OverallTime+=count;
        //this->start=this->stop;
    //}
}
void Programs::SetProgram(std::string path)
{
    this->isEnd=false;
    std::cout<<path;

    this->file.open(path);

    //this->start= std::chrono::steady_clock::now();
    std::string line;
    getline(this->file,line);
    std::cout<<line<<std::endl;
    this->OverallTime=std::stoi(line);
}
void Programs::Stop()
{

}
void Programs::Start() {

}

void Programs::Parse()
{
    this->ClearSignals();
    int red,blue,fan,t1,t2,crio;
    sscanf(this->actualCommand.c_str(),"NASTAWA%03d-%01d:%03d-%01d:%01d:%01d", &red,&t1,&blue,&t2,&fan,&crio);

    if(red>0)
    {
        this->signals.redActual=true;
    }
    if(blue>0)
    {
        this->signals.blueActual=true;
    }
    if(fan>0)
    {
        this->signals.fan=true;
    }

    sscanf(this->futureCommand.c_str(),"NASTAWA%03d-%01d:%03d-%01d:%01d:%01d", &red,&t1,&blue,&t2,&fan,&crio);

    if(red>0)
    {
        this->signals.redFuture=true;
    }
    if(blue>0)
    {
        this->signals.blueFuture=true;
    }

    if(this->actualCommand=="")
    {
        this->signals.blueActual=false;
        this->signals.redActual=false;
        this->signals.fan=false;
    }

    std::cout<<this->signals.redActual<<","<<this->signals.blueActual<<","<<this->signals.fan<<","<<this->signals.redFuture<<","<<this->signals.blueFuture<<std::endl;
}