#include <iostream>
#include <string>
#include "audit/audit.hpp"

std::string Transaction::addTransaction(long amount) {

    std::cout << "Metode Pembayaran:\n1. Debit\n2. QRIS\n3. Cash\nPilih: ";
    std::cin >> this->transactionmethod;

    cashflow = amount;

    if (transactiontype == "Out") {
        totalcash -= cashflow;

    } else {
        totalcash += cashflow;

    }

    switch (this->transactionmethod) {

        case 1: {

            std::string a, b, c;
            std::cout << "Masukkan ID Kartu Pembayar (16 digit) : ";
            std::cin >> a;
            std::cout << "Masukkan Nama Bank Penyedia : ";
            std::cin >> b;
            std::cout << "Masukkan Kode Sekuritas (3 digit di belakang kartu) : ";
            std::cin >> c;

            Debit* newtrans = new Debit(a, b, c, cashflow, transactiontype, transactiondetails);
            return newtrans->getLog();

            break;

		}

		case 2: {

            std::string a, b, c;
            std::cout<<"Masukkan kode QRIS dari QR-Code : ";
            std::cin>>a;
            std::cout<<"Masukkan Nama Bank Penyedia : ";
            std::cin>>b;
            std::cout<<"Masukkan Nomor Akun Pembayar : ";
            std::cin>>c;

            Qris* newtrans = new Qris(a, b, c, cashflow, transactiontype, transactiondetails);
            return newtrans->getLogs();

            break;

        }

        default: {
            return "Cash / ----- / ----- / " + formatCash(std::to_string(cashflow), transactiontype) + " / " + getDetails() + " / " + currenttime;
            break;
        }

    }

}

Transaction::Transaction() : Audit() {}

Transaction::Transaction(std::string type, std::string details) : Audit() {
    transactiontype = type;
    transactiondetails = details;

}
