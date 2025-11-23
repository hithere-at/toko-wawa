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
        long getHarga();
        virtual void tampilkanBarang();
        long totalHarga();
        void kurangiStok(int jumlah);
        void tambahStok(int jumlah);

};

class Makanan : public Inventori {

    private:
        std::string kadaluarsa;

    public:
        Makanan(std::string n, int s, int h, std::string k);
        void tampilkanBarang() override;

};

class Minuman : public Inventori {

    private:
        std::string kadaluarsa;

    public:
        Minuman(std::string n, int s, int h, std::string k);
        void tampilkanBarang() override;

};

class Peralatan : public Inventori {

    private:
        std::string kategori;

    public:
        Peralatan(std::string n, int s, int h, std::string k);
        void tampilkanBarang() override;

};

#endif
