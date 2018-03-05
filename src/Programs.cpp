//
// Created by studiofigura on 13.02.18.
//

#include "../inc/Programs.h"

Programs::Programs(std::string path)
{
    this->path=path;
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
    this->Refresh();
}
void Programs::Stop()
{
    this->isEnd=true;
    this->file.close();
    this->OverallTime=0;
    this->ActualTime=1;

    this->actualCommand="";
    this->futureCommand="";

    this->ClearSignals();
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

void Programs::SetProgramID(int ID)
{
    switch(ID)
    {
        case 1:
        {
            this->actualProgram=this->path+"hot";
            break;
        }
        case 2:
        {
            this->actualProgram=this->path+"crio";
            break;
        }
        case 3:
        {
            this->actualProgram=this->path+"manual";
            break;
        }
        case 4:
        {
            this->actualProgram=this->path+"pr1";
            break;
        }
        case 5:
        {
            this->actualProgram=this->path+"pr2";
            break;
        }
        case 6:
        {
            this->actualProgram=this->path+"pr3";
            break;
        }
        case 7:
        {
            this->actualProgram=this->path+"pr4";
            break;
        }
        case 8:
        {
            this->actualProgram=this->path+"pr5";
            break;
        }
        case 9:
        {
            this->actualProgram=this->path+"pr6";
            break;
        }
        case 10:
        {
            this->actualProgram=this->path+"pr7";
            break;
        }
        case 11:
        {
            this->actualProgram=this->path+"pr8";
            break;
        }
    }
    this->file.close();
    this->SetProgram(this->actualProgram);
}