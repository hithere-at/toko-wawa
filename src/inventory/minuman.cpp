#include <iostream>
#include "inventori/inventori.hpp"
using namespace std;

void Minuman::setMinuman(string n, int s, int h, string k) {
    setBarang(n, s, h);
    this->kadaluarsa = k;

}

void Minuman::tampilkanMinuman() {
    tampilkanBarang();
    cout << "Tanggal Kadaluarsa : " << this->kadaluarsa << endl;
    cout << "Total Nilai Stok   : " << totalHarga() << endl;
    cout << "-----------------------------------------------" << endl;

}
