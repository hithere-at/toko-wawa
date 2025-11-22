#include <iostream>
#include <string>
#include <vector>
#include "audit/audit.hpp"

Logger::Logger() : Transaction() {}

void Logger::updateTransList(std::string adder){

    translog.push_back(adder);
    this->findsize = this->translog.size();

    std::cout<< this->translog[totaltrans];

    totaltrans++;

};

void Logger::getTransList(){

    this->findsize = translog.size();
    std::cout<<"\n----------------------------------TRANSAKSI SELAMA INI----------------------------------\n\n";

    for (int i = 0; i < this->findsize; i++){
        std::cout<<this->translog[i];

    }

    std::cout<<"\nKas tersedia sekarang : "<<formatCash(std::to_string(totalcash), "null")<<"\n";

}
