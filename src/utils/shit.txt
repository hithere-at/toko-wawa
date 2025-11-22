        User login(std::string uid, std::string passwd, User usr_cmp) {
            User user;

            for (int i = 0; i < 6; i++) {

                if (uid == USER_DB[i].user_id && passwd == USER_DB[i].password) {
                    user = USER_DB[i];
                    break;

                }

            }

            return user;

        }

        void login_as_guest() {

            std::cout << std::endl << "Masukkan nama anda: ";
            std::getline(std::cin, this->nama);

            std::cout << "Masukkan tempat tanggal lahir anda (<LOKASI>, <dd/mm/yyyy>): ";
            std::getline(std::cin, this->ttl);

            this->status = "Pelanggan";

        }

        void login_prompt () {

            std::string uid, passwd;
            int pilihan;

            std::cout << "Selamat datang di minimarket!" << std::endl;
            int will_login = num_input("Apa yang anda mau lakukan?\n1. Login\n2. Register\n3. Masuk sebagai pelanggan baru\nPilihan [1-3]: ", 1, 3);

            if (will_login == 1) {

                while (true) {
                    std::cout << "Silahkan melakukan login." << std::endl;
                    std::cout << "Username: ";
                    std::cin >> uid;

                    std::cout << "Password: ";
                    std::cin >> passwd;

                    User user_logged_in = login(uid, passwd);

                    if (user_logged_in.balance == -1) {
                        std::cout << "User tidak ditemukan. Apakah anda mau mengulang?" << std::endl;
                        std::cout << "1. Ya" << std::endl;
                        std::cout << "2. Tidak" << std::endl;

                        int will_login_guest = num_input("Pilihan [1-2]: ", 1, 2);
                        (will_login_guest == 1) ? continue : login_as_guest();

                    }

                }

            } else if (will_login == 2) {

                std::cout << "Masukkan nama anda: ";
                std::getline(std::cin, this->nama);

                std::cout << "Masukkan tempat tanggal lahir anda (<LOKASI>, <dd/mm/yyyy>): ";
                std::getline(std::cin, this->ttl);

                this->status = "Pelanggan";

                std::cout << "Masukkan username anda: ";
                std::cin >> this->user_id;

                std::cout << "Masukkan password anda: ";
                std::cin >> this->password;

                this->balance = 100000;

                std::cout << "Registrasi selesai. Sekarang anda mempunyai saldo 100.000" << std::endl;

            } else if (will_login == 3) {
                login_as_guest();

            }

        }
