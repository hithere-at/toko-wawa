#include <iostream>
#include "inventori.hpp"
using namespace std;

void Inventori::setBarang(string name, int stock, int price){
    stok = stock;
    nama = name;
    harga = price;

}
string Inventori::getNama() {
    return nama;

}

long Inventori::getStok() {
    return stok;

}

long Inventori::getHarga() {
    return harga;

}

void Inventori::tampilkanBarang(){
    cout << "Nama Barang        : " << nama << endl;
    cout << "Stock Barang       : " << stok << endl;
    cout << "Harga Per pcs      : " << harga << endl;

}

long Inventori::totalHarga(){
    long total;
    total = harga * stok;
    return total;

}

void Inventori::kurangiStok(int jumlah) {

    if (jumlah <= stok) {
        stok -= jumlah;

    } else {
        cout << "Stok tidak cukup!" << endl;
    }

}

void Inventori::tambahStok(int jumlah) {
    stok += jumlah;

}

/*
int main(){
	makanan mk1;
	makanan mk2;

	minuman mn1;
	minuman mn2;

	peralatan p1;
	peralatan p2;

	mk1.setMakanan("Indomie", 100 , 3000, "19/09/2027");
	mk2.setMakanan("Roti ", 50 , 8000, "25/11/2025");
	cout<<"-----------MAKANAN------------"<<endl;
	mk1.tampilkanMakanan();
	mk2.tampilkanMakanan();
	cout<<endl;
	cout<<endl;

	mn1.setMinuman("Sprite", 50 , 5000 , "25/10/2027");
	mn2.setMinuman("Teh Pucuk", 100 , 4000 , "25/10/2027");
	cout<<"-----------Minuman------------"<<endl;
	mn1.tampilkanMinuman();
	mn2.tampilkanMinuman();
	cout<<endl;
	cout<<endl;

	p1.setPeralatan("Sapu", 15 , 30000, "Rumah Tangga");
	p2.setPeralatan("Sabun", 20, 4000, "Kesehatan");
	cout<<"----------Peralatan----------"<<endl;
	p1.tampilkanPeralatan();
	p2.tampilkanPeralatan();
	cout<<endl;
	cout<<endl;
	int d;
	cin>>d;
}
*/
