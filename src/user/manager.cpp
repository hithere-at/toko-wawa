#include <iostream>
#include "user/user.hpp"
#include "utils/utils.hpp"

Manajer::Manajer(User &usr) : User(usr) {}

void Manajer::add_new_stock(Inventori **inv, int len, Logger *audit) {

    std::string nama, stuff;
    long stok, harga;
    int tipe_barang;
    Inventori *barang;

    std::cout << "1. Makanan" << std::endl;
    std::cout << "2. Minuman" << std::endl;
    std::cout << "3. Peralatan" << std::endl;
    tipe_barang = num_input("Pilih tipe barang [1-3]: ", 1, 3);

    std::cout << "Masukkan nama barang: ";
    std::cin.ignore();
    std::getline(std::cin, nama);

    std::cout << "Masukkan harga barang: ";
    std::cin >> harga;

    std::cout << "Masukkan jumlah stok barang: ";
    std::cin >> stok;

    if (tipe_barang == 1) {
        std::cout << "Masukkan tanggal kadularsa barang (format DD/MM/YYYY): ";
        std::cin >> stuff;
        barang = new Makanan(nama, stok, harga, stuff);

    } else if (tipe_barang == 2) {
        std::cout << "Masukkan tanggal kadularsa barang (format DD/MM/YYYY): ";
        std::cin >> stuff;
        barang = new Minuman(nama, stok, harga, stuff);

    } else {
        std::cout << "Masukkan kategori barang: ";
        std::cin >> stuff;
        barang = new Peralatan(nama, stok, harga, stuff);

    }

    inv[len] = barang;

    std::string transact_desc = "Stok - Pembelian " + nama + " - Qty: " + std::to_string(stok);

    std::cout << std::endl << "Stok baru telah ditambahkan! ";
    std::cout << "Silahkan melakukan pembayaran di bawah ini" << std::endl;

    Transaction *transact = new Transaction("Out", transact_desc);
    audit->updateTransList(transact->addTransaction(harga * stok));
    delete transact;

}

void Manajer::manage_stock(Inventori **inv, int len, std::string action, Logger *audit) {

    std::cout << "===== INVENTORI =====" << std::endl;

    for (int i = 0; i < len; i++) {
        std::string nama = inv[i]->getNama();
        long stok = inv[i]->getStok();

        std::cout << i+1 << ". " << nama << " (Stok: " << stok << ")" << std::endl;

    }

    std::string prompt;
    long upper;

    if (action == "ADD") {
        prompt = "Pilih stok barang yang akan ditambahkan: ";

    } else if (action == "REMOVE") {
        prompt = "Pilih stok barang yang akan dikurangi: ";

    }

    int choice = num_input(prompt, 1, len);

    if (action == "ADD") {
        prompt = "Jumlah stok barang yang akan ditambahkan: ";
        upper = 99999;

    } else if (action == "REMOVE") {
        upper = inv[choice-1]->getStok();
        prompt = "Jumlah stok barang yang akan dikurangi: ";

    }

    int num_stok = num_input(prompt, 1, upper);
    long harga_stok = inv[choice-1]->getHarga();
    std::string transact_desc = "Stok - " + inv[choice-1]->getNama() + " - Qty: " + std::to_string(num_stok);
    std::string cash_flow;

    std::cout << std::endl;

    if (action == "ADD") {
        inv[choice-1]->tambahStok(num_stok);
        cash_flow = "Out";

    } else if (action == "REMOVE") {
        inv[choice-1]->kurangiStok(num_stok);
        cash_flow = "In";

    }

    std::cout << "Silahkan melakukan pembayaran di bawah ini" << std::endl;

    Transaction *transact = new Transaction(cash_flow, transact_desc);
    audit->updateTransList(transact->addTransaction(harga_stok * num_stok));
    delete transact;

}

void Manajer::print_stock(Inventori **inv, int len) {

    std::cout << "===== INVENTORI =====" << std::endl;

    for (int i = 0; i < len; i++) {
        std::string nama = inv[i]->getNama();
        long stok = inv[i]->getStok();

        std::cout << i+1 << ". " << nama << " (Stok: " << stok << ")" << std::endl;

    }

}
