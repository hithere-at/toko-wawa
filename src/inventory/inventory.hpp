#include <string>

#ifndef _SHOP_INVENTORY_HPP_
#define _SHOP_INVENTORY_HPP_

class Inventori {

    protected:
        std::string nama;
        long stok;
        long harga;

    public:
        void setBarang(std::string nama, int stock, int price);
        std::string getNama();
        long getStok();
        void tampilkanBarang();
        void totalHarga();
        void kurangiStok(int jumlah);
        void tambahStok(int jumlah);

};

class Makanan : public Inventori {

    private:
        string kadaluarsa;

    public:
        void setMakanan(std::string n, int s, int h, std::string k);
        void tampilkanMakanan();

};

class Minuman : public Inventori {

    private:
        string kadaluarsa;

    public:
        void setMinuman(std::string n, int s, int h, std::string k);
        void tampilkanMinuman();

};

class Peralatan : public Inventori {

    private:
        string kategori;

    public:
        void setPeralatan(std::string n, int s, int h, std::string k);
        void tampilkanPeralatan();

};

#endif
