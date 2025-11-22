#include <string>
#include "audit/audit.hpp"

Debit::Debit(std::string num, std::string bank, std::string code, int cash, std::string type, std::string details) : Audit(){
    this->cardnumber = num;
    this->bank = bank;
	this->securitycode = code;
	cashflow = cash;
	transactiontype = type;
	transactiondetails = details;

}

std::string Debit::getLog(){
    this->finished = "Debit / " + this->cardnumber + "-" + this->securitycode + " / " + this->bank + " / " + formatCash(std::to_string(cashflow), transactiontype) + " / " + getDetails() + " / " + currenttime;
    return this->finished;

}
