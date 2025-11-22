#include <iostream>
#include "inventori/inventori.hpp"
using namespace std;

void Peralatan::setPeralatan(string n, int s, int h, string k) {
    setBarang(n, s, h);
    this->kadaluarsa = k;

}

void Peralatan::tampilkanPeralatan() {
    tampilkanBarang();
    cout << "Kategori           : " << this->kategori << endl;
    cout << "Total Nilai Stok   : " << totalHarga() << endl;
    cout << "-----------------------------------------------" << endl;

}
