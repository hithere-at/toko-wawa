#include <iostream>
#include "utils/utils.hpp"
#include "utils/hash.hpp"
#include "user/user.hpp"
#include "inventori/inventori.hpp"
#include "inventori/keranjang.hpp"
#include "audit/audit.hpp"

void print_current_stok(Inventori **inv, int len) {

    for (int i = 0; i < len; i++) {
        std::string nama = inv[i]->getNama();
        long stok = inv[i]->getStok();

        std::cout << i+1 << ". " << nama << " (Stok: " << stok << ")" << std::endl;

    }

}

int main() {

    // init
    Logger *audit = new Logger();
    User *main_user = nullptr;
    Manajer *manajer = nullptr;
    Kasir *kasir = nullptr;
    Member *member = nullptr;

    int users_len = get_db_user_len();
    User *users = new User[100];
    load_user_db_from_file(users);

    int stok_len = 6;
    Inventori **inv = new Inventori* [100];
    inv[0] = new Makanan("Mi Instan", 100, 3000, "19/09/2027");
    inv[1] = new Makanan("Roti", 50, 6000, "12/12/2025");
    inv[2] = new Minuman("Minuman Soda", 50, 5000, "25/10/2027");
    inv[3] = new Minuman("Teh Botol", 100, 4000, "25/10/2027");
    inv[4] = new Peralatan("Sapu", 15, 30000, "Rumah Tangga");
    inv[5] = new Peralatan("Sabun", 20, 4000, "Kesehatan");

    while (true) {

        std::cout << "===== TOKO WAWA  =====" << std::endl;
        std::cout << "1. Login" << std::endl;
        std::cout << "2. Register" << std::endl;
        std::cout << "3. Keluar" << std::endl;

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

                    } else if (status == "Member") {
                        member = new Member(users[i]);

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
            member = new Member(*main_user);
            users[users_len] = *main_user;
            users_len++;
            write_user(main_user, user_id, 100000);

        } else {
            break;

        }

        if (main_user->status == "Manajer") {
            std::cout << std::endl << "Selamat datang, " << manajer->nama << std::endl;

            while (true) {
                int stock_option;

                std::cout << "1. Tambahkan stok yang ada" << std::endl;
                std::cout << "2. Tambahkan stok baru" << std::endl;
                std::cout << "3. Kurangi stok yang ada" << std::endl;
                std::cout << "4. Tampilkan stok saat ini" << std::endl;
                std::cout << "5. Lihat semua transaksi hari ini" << std::endl;
                std::cout << "6. Lihat semua transaksi semua waktu" << std::endl;
                std::cout << "7. Logout" << std::endl;
                stock_option = num_input("Apa yang anda pilih [1-7]: ", 1, 7);
                std::cout << std::endl;

                if (stock_option == 1) {
                    manajer->manage_stock(inv, stok_len, "ADD", audit);

                } else if (stock_option == 2) {
                    manajer->add_new_stock(inv, stok_len, audit);
                    stok_len++;

                } else if (stock_option == 3) {
                    manajer->manage_stock(inv, stok_len, "REMOVE", audit);

                } else if (stock_option == 4) {
                    manajer->print_stock(inv, stok_len);

                } else if (stock_option == 5) {
                    audit->getTransList();

                } else if (stock_option == 6) {
                    std::cout << "----------------------------------TRANSAKSI SELAMA INI----------------------------------" << std::endl;
                    read_everything_on_audit();

                } else {
                    break;

                }

                std::cout << std::endl;

            }

        } else if (main_user->status == "Member") {
            std::cout << std::endl << "Selamat datang, " << member->nama;
            Keranjang *cart = new Keranjang();

            while (true) {
                int pilihan;

                std::cout << std::endl << "1. Beli barang" << std::endl;
                std::cout << "2. Lihat harga barang" << std::endl;
                std::cout << "3. Finalisasi pembayaran" << std::endl;
                std::cout << "4. Lihat keranjang" << std::endl;
                std::cout << "5. Logout" << std::endl;
                pilihan = num_input("Apa yang anda pilih [1-5]: ", 1, 5);

                if (pilihan == 1) {
                    std::cout << std::endl;
                    print_current_stok(inv, stok_len);

                    int barang_dipilih = num_input("Pilih barang: ", 1, stok_len);
                    int banyak_barang = num_input("Banyak barang: ", 1, inv[barang_dipilih-1]->getStok());

                    std::cout << std::endl;

                    inv[barang_dipilih-1]->kurangiStok(banyak_barang);
                    cart->tambahBarang(inv[barang_dipilih-1], banyak_barang);

                } else if (pilihan == 2) {
                    std::cout << std::endl;
                    print_current_stok(inv, stok_len);

                    int barang_dipilih = num_input("Pilih barang: ", 1, stok_len);
                    inv[barang_dipilih-1]->tampilkanBarang();

                } else if (pilihan == 3) {

                    if (!cart) {
                        std::cerr << "Keranjang kosong!" << std::endl;
                        continue;

                    } else {
                        User user_kasir("Kasir General", "01/01/1970", "Kasir");
                        kasir = new Kasir(user_kasir);

                        std::cout << std::endl;
                        kasir->commit_transaction(main_user, cart, audit);
                        cart = new Keranjang();

                        std::cout << std::endl << "Pembayaran berhasil!" << std::endl;

                    }

                } else if (pilihan == 4) {

                    if (!cart) {
                        std::cerr << "Keranjang kosong!" << std::endl;
                        continue;

                    } else {
                        cart->tampilkanKeranjang();

                    }

                } else {
                    std::cout << std::endl;
                    break;

                }

            }

        }

    }

    free_everything:
    for (int i = 0; i < 100; i++) {
        delete inv[i];

    }

    delete[] inv;
    delete[] users;
    delete manajer;
    delete kasir;
    delete member;
    delete audit;

    return 0;

}
