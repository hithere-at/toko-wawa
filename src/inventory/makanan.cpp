#include <iostream>
#include "inventori/inventori.hpp"
using namespace std;

void Makanan::setMakanan(string n, int s, int h, string k) {
    setBarang(n, s, h);
    this->kadaluarsa = k;

}

void Makanan::tampilkanMakanan() {
    tampilkanBarang();
    cout << "Tanggal Kadaluarsa : " << this->kadaluarsa << endl;
    cout << "Total Nilai Stok   : " << totalHarga() << endl;
    cout << "-----------------------------------------------" << endl;

}
