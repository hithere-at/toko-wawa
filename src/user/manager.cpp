#include <iostream>
#include "user.hpp"
#include "utils/utils.hpp"

void Manajer::manage_stock(Inventori *inv, int len, std::string action) {

    std::cout << "===== INVENTORI =====" << std::endl;

    for (int i = 0; i < len; i++) {
        std::string nama = inv[i]->getNama();
        long stok = inv[i]->getStok();

        std::cout << i+1 << ". " << nama << " (Stok: " << stok << ")" << std::endl;

    }

    std::string prompt;
    long upper;

    if (action == "ADD") {
        prompt = "Pilih stok barang yang akan ditambahkan [1-" + len + "]: ";

    } else if (action == "REMOVE") {
        prompt = "Pilih stok barang yang akan dikurangi [1-" + len + "]: ";

    }

    int choice = num_input(prompt, 1, len);

    if (action == "ADD") {
        prompt = "Jumlah stok barang yang akan ditambahkan: ";
        upper = 99999;

    } else if (action == "REMOVE") {
        upper = inv[choice-1]->getStok();
        prompt = "Jumlah stok barang yang akan dikurangi [1-" + upper + "]: ";

    }

    int num_stok = num_input(prompt, 1, upper)

    if (action == "ADD") {
        inv[i]->tambahStok(num_stok);

    } else if (action == "REMOVE") {
        inv[i]->kurangiStok(num_stok);

    }


}

