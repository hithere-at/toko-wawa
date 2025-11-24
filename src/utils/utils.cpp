#include <iostream>
#include <fstream>
#include "utils/utils.hpp"

int num_input(std::string prompt, int lower, int upper) {

    int input;

    while (true) {

        std::cout << prompt;
        std::cin >> input;

        if (input < lower || input > upper || std::cin.fail()) {
            std::cerr << "Input tidak valid. Mohon mengulangi" << std::endl << std::endl;
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            continue;

        }

        break;

    }

    return input;

}

int get_db_user_len() {

    std::fstream db_file("db.csv", std::ios::in);
    std::string line_buf;
    int count = 0;

    if (db_file.is_open()) {

        while (getline(db_file, line_buf)) {
            count++;

        }

    }

    return count;

}

void load_user_db_from_file(User *db) {

    std::fstream db_file("db.csv", std::ios::in);
    std::string line_buf;
    int user_len = 0;

    if (db_file.is_open()) {

        while (getline(db_file, line_buf)) {
            std::string::size_type found_idx = 0;
            std::string::size_type line_buf_len  = line_buf.size();
            std::string prop[7];
            int count = 0;

            while (found_idx <= line_buf_len) {
                std::string::size_type old_pos = found_idx;
                found_idx = line_buf.find(",", old_pos);
                std::string field;

                if (found_idx != std::string::npos) {

                    if (count == 0) {
                        field = line_buf.substr(0, found_idx);

                    } else {
                        field = line_buf.substr(old_pos, found_idx-old_pos);

                    }

                } else {
                    field = line_buf.substr(old_pos, line_buf_len);
                    found_idx = line_buf_len;

                }

                found_idx += 1;
                prop[count] = field;
                count += 1;

            }

            db[user_len] = User(prop[0], prop[1], prop[2], prop[3], std::stoi(prop[4]), prop[5], prop[6]);
            user_len++;

        }

    }

    db_file.close();

}

void read_everything_on_audit() {

    std::fstream transact_file("transact.aud", std::ios::in);
    std::string line_buf;

    if (transact_file.is_open()) {

        while (getline(transact_file, line_buf)) {
            std::cout << line_buf << std::endl;

        }

    }

    transact_file.close();

}

void write_transaction(std::string transact) {

    std::fstream transact_file("transact.aud", std::ios::out | std::ios::app);

    if (transact_file.is_open()) {
        transact_file << transact;

    }

    transact_file.close();

}

void write_user(User *usr, std::string uid, long balance) {

    std::fstream user_file("db.csv", std::ios::out | std::ios::app);

    if (user_file.is_open()) {
        user_file << usr->nama << ",";
        user_file << usr->ttl << ",";
        user_file << usr->status << ",";
        user_file << uid << ",";
        user_file << balance << ",";
        user_file << usr->hash << ",";
        user_file << usr->salt << std::endl;

    }

    user_file.close();

}
