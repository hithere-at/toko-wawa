#include <string>
#include "inventori/inventori.hpp"

#ifndef _SHOP_USER_HPP_
#define _SHOP_USER_HPP_

class User {

    protected:
        std::string user_id;
        long balance;

    public:
        std::string hash;
        std::string salt;
        std::string nama;
        std::string ttl;
        std::string status;

        User();
        User (std::string nama, std::string ttd, std::string status);
        User (std::string nama, std::string ttd, std::string status, std::string user_id, int balance, std::string hash, std::string salt);

        void print_info();

};

class Kasir : public User {

    private:
        long sales;

    public:
        void create_transaction();
        void commit_transaction();

}

class Manager : public User {

    public:
        void manage_stock(Inventori *inv, int len);

}

#endif
