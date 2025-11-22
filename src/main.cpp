#include <iostream>
#include "utils/utils.hpp"
#include "utils/hash.hpp"
#include "user/user.hpp"
#include "audit/audit.hpp"

int main() {

    // init
    Logger *audit = new Logger();
    User *main_user = nullptr;
    Manajer *manajer = nullptr;
    Kasir *kasir = nullptr;;

    int users_len = get_db_user_len();
    User *users = new User[users_len];
    load_user_db_from_file(users);

    Inventori **inv = new Inventori* [100];
    inv[0] = new Makanan("Mi Instan", 100, 3000, "19/09/2027");
    inv[1] = new Makanan("Roti", 50, 6000, "12/12/2025");
    inv[2] = new Minuman("Minuman Soda", 50, 5000, "25/10/2027");
    inv[3] = new Minuman("Teh Botol", 100, 4000, "25/10/2027");
    inv[4] = new Peralatan("Sapu", 15, 30000, "Rumah Tangga");
    inv[5] = new Peralatan("Sabun", 20, 4000, "Kesehatan");

    std::cout << "===== TOKO WAWA  =====" << std::endl;
    std::cout << "1. Login" << std::endl;
    std::cout << "2. Register" << std::endl;

    int login_type = num_input("Apa yang anda lakukan [1-3]: ", 1, 3);

    if (login_type == 1) {
        std::string user_id, password;
        bool auth;

        std::cout << std::endl << "===== LOGIN =====" << std::endl;
        std::cout << "User ID: ";
        std::cin >> user_id;

        std::cout << "Password: ";
        std::cin >> password;

        for (int i = 0; i < users_len; i++) {
            std::string salt = users[i].salt;
            std::string hash = users[i].hash;
            std::string status = users[i].status;
            std::string input_hash = pw_hash(user_id + password, salt);

            if (input_hash == hash) {

                main_user = &users[i];

                if (status == "Manajer") {
                    manajer = new Manajer(users[i]);

                } else if (status == "Kasir") {
                    kasir = new Kasir(users[i]);

                }

                auth = true;
                break;

            } else {
                auth = false;

            }

        }

        if (auth == false) {
            std::cerr << std::endl << "Login gagal" << std::endl;
            goto free_everything;

        }

    } else if (login_type == 2) {
        std::string user_id ,password, nama, hash, salt, ttl;

        std::cout << std::endl << "===== REGISTRASI =====" << std::endl;

        std::cout << "Username: ";
        std::cin >> user_id;

        std::cout << "Password: ";
        std::cin >> password;
        std::cin.ignore();

        std::cout << "Nama orang: ";
        std::getline(std::cin, nama);

        std::cout << "Tempat tanggal lahir (format: DD/MM/YYYY): ";
        std::cin >> ttl;

        salt = gen_salt(8);
        hash = pw_hash(user_id + password, salt);

        main_user = new User(nama, ttl, "Member", user_id, 100000, hash, salt);
        write_user(main_user, user_id, 100000);

    }

    if (main_user->status == "Manajer") {
        int stock_option;

        std::cout << std::endl << "Selamat datang, " << manajer->nama << std::endl;
        std::cout << "1. Tambahkan Stok" << std::endl;
        std::cout << "2. Kurangi stok" << std::endl;
        std::cout << "Apa yang anda pilih [1-2]: ";
        std::cin >> stock_option;

        if (stock_option == 1) {
            manajer->manage_stock(inv, 6, "ADD");

        } else {
            manajer->manage_stock(inv, 6, "REMOVE");

        }

    }

    free_everything:
    for (int i = 0; i < 100; i++) {
        delete inv[i];

    }

    delete[] inv;
    delete[] users;
    delete main_user;
    delete manajer;
    delete kasir;

    return 0;

}
