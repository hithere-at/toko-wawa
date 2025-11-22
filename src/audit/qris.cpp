#include <string>
#include "audit/audit.hpp"

Qris::Qris(std::string qris, std::string bank, std::string account, int cash, std::string type, std::string details) : Audit(){
    this->qriscode = qris;
    this->bank = bank;
    this->accountnumber = account;
    cashflow = cash;
    transactiontype = type;
    transactiondetails = details;

}

std::string Qris::getLogs(){
    this->finished = "QRIS / " + this->qriscode + " / " + this->accountnumber + " / " + this->bank + " / " + formatCash(std::to_string(cashflow), transactiontype) + " / " + getDetails() + " / " + currenttime;
    return finished;

}
