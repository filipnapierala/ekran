//
// Created by studiofigura on 13.02.18.
//

#include "../inc/Programs.h"

Programs::Programs()
{
    this->ActualTime=0;
}

Programs::~Programs() {}

int Programs::Refresh()
{
    this->stop=std::chrono::steady_clock::now();
    auto count=std::chrono::duration_cast<std::chrono::seconds>(this->stop-this->start).count();
    std::cout<<"Time is: "<<this->OverallTime+count<<std::endl;

    if(count>=this->ActualTime)
    {
        if(!this->file.good())
        {
            return 0;
        }

        std::string line;
        getline(this->file,line);
        std::cout<<line<<std::endl;

        getline(this->file,line);
        std::cout<<line<<std::endl;
        this->ActualTime=std::stoi(line);

        this->OverallTime+=count;
        this->start=this->stop;
    }
}
void Programs::SetProgram(std::string path)
{
    std::cout<<path;

    this->file.open(path);

    this->start= std::chrono::steady_clock::now();
    std::string line;
    getline(this->file,line);
    std::cout<<line<<std::endl;
}
void Programs::Stop()
{

}
void Programs::Start()
{

}