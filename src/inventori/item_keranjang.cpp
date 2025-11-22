#include <iostream>
#include "inventori/keranjang.hpp"
using namespace std;

ItemKeranjang::ItemKeranjang(Inventori* b, int j) {
    barang = b;
    jumlahBeli = j;

}

long ItemKeranjang::totalHarga() {
    return barang->totalHarga() / (barang->getStok() * jumlahBeli);

}

void ItemKeranjang::tampil() {
    barang->tampilkanBarang();
    cout << "Jumlah dibeli      : " << jumlahBeli << endl;
    cout << "Total harga        : " << totalHarga() << endl;

}
