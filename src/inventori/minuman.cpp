#include <iostream>
#include "inventori/inventori.hpp"
using namespace std;

Minuman::Minuman(string n, int s, int h, string k) {
    this->nama = n;
    this->stok = s;
    this->harga = h;
    this->kadaluarsa = k;

}

void Minuman::tampilkanBarang() {
    Inventori::tampilkanBarang();
    cout << "Tanggal Kadaluarsa : " << this->kadaluarsa << endl;
    cout << "Total Nilai Stok   : " << totalHarga() << endl;
    cout << "-----------------------------------------------" << endl;

}
