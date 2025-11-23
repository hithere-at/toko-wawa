#include <string>
#include "inventori/inventori.hpp"
#include "inventori/keranjang.hpp"
#include "audit/audit.hpp"

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
        Kasir(User &usr);
        void commit_transaction(User *usr, Keranjang *cart, Logger *audit);

};

class Manajer : public User {

    public:
        Manajer(User &usr);
        void manage_stock(Inventori **inv, int len, std::string action, Logger *audit);
        void add_new_stock(Inventori **inv, int len, Logger *audit);
        void print_stock(Inventori **inv, int len);

};

class Member : public User {

    public:
        Member(User &usr);
        char code;

};

#endif

