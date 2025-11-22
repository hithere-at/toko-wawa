#include "inventori/inventori.hpp"

#ifndef _SHOP_KERANJANG_HPP_
#define _SHOP_KERANJANG_HPP_

class ItemKeranjang {

    public:
        Inventori *barang;
        int jumlahBeli;

        ItemKeranjang(Inventori *b, int j);
        long totalHarga();
        void tampil();

};

class Keranjang : public ItemKeranjang {

    private:
        ItemKeranjang *items[100];
        int jumlah;

    public:
        Keranjang();
        void tambahBarang(Inventori *b, int qty);
        void tampilkanKeranjang();
        long totalBelanja();

};

#endif
