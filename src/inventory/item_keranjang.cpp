#include <iostream>
#include "inventori/inventori.hpp"
using namespace std;

ItemKeranjang::ItemKeranjang(Inventori* b, int j) {
    this->barang = b;
    this->jumlahBeli = j;

}

long ItemKeranjang::totalHarga() {
    return barang->totalHarga() / (barang->getStok() * jumlahBeli);

}

void ItemKeranjang::tampil() {
    this->barang->tampilkanBarang();
    cout << "Jumlah dibeli      : " << jumlahBeli << endl;
    cout << "Total harga        : " << totalHarga() << endl;

}
