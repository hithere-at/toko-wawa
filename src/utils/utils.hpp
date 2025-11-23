#include <string>
#include "../user/user.hpp"

#ifndef _SHOP_UTILS_HPP_
#define _SHOP_UTILS_HPP_

int num_input(std::string prompt, int lower, int upper);
int get_db_user_len();
void load_user_db_from_file(User *db);
void read_everything_on_audit();
void write_transaction(std::string transact);
void write_user(User *usr, std::string uid, long balance);

#endif
