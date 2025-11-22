#include <string>
#include <ctime>
#include "audit/audit.hpp"

std::string Audit::formatCash(std::string cash, std::string type) {

    std::string formatted;

    if (type == "Out") {
        formatted += "- Rp. ";

    } else if (type == "In") {
        formatted += "+ Rp. ";

    } else {
        formatted += "Rp. ";

    }

    int length = cash.length();
    int counter = 3 - length % 3;

    if (counter >= 3) {
        counter = 0;

	}

    for (int x = 0; x < length; x++) {
        formatted += cash[x];

		if (counter == 2){
            formatted += ".";
            counter == 0;

        }

		counter++;

	}

    formatted += ".00";
	return formatted;

}

Audit::Audit() {
    time_t ct = time(0);
    this->currenttime = (ctime(&ct));

}

std::string Audit::getTime() {
    return "Tanggal Transaksi : " + this->currenttime;

}

std::string Audit::getDetails() {
    return this->transactiontype + " / " + this->transactiondetails;

}
