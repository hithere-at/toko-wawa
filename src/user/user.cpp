#include <iostream>
#include "user.hpp"

User::User () { this->balance = -1; }

User::User (std::string nama, std::string ttd, std::string status) {
    this->nama = nama;
    this->ttl = ttd;
    this->status = status;
    this->balance = 0;

}

User::User (std::string nama, std::string ttl, std::string status, std::string user_id, int balance, std::string hash, std::string salt) {
    this->nama = nama;
    this->ttl = ttl;
    this->status = status;
    this->user_id = user_id;
    this->balance = balance;
    this->hash = hash;
    this->salt = salt;

}

void User::print_info() {
    std::cout << "===== INFORMASI AKUN =====" << std::endl;
    std::cout << "Nama: " << this->nama << std::endl;
    std::cout << "Tempat / Tanggal Lahir: " << this->ttl << std::endl;
    std::cout << "Status: " << this->status << std::endl;
    std::cout << "Saldo: " << this->balance << std::endl;

}
