#include <iostream>
#include "inventori/inventori.hpp"
using namespace std;

Peralatan::Peralatan(string n, int s, int h, string k) {
    this->nama = n;
    this->stok = s;
    this->harga = h;
    this->kategori = k;

}

void Peralatan::tampilkanBarang() {
    Inventori::tampilkanBarang();
    cout << "Kategori           : " << this->kategori << endl;
    cout << "Total Nilai Stok   : " << totalHarga() << endl;
    cout << "-----------------------------------------------" << endl;

}
