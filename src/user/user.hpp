#include <string>

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

        void createTransaction();
        void addProduct()
        

}

#endif
