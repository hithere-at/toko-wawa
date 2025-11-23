#include <iostream>
#include "inventori/keranjang.hpp"
using namespace std;

Keranjang::Keranjang() : ItemKeranjang(nullptr, 0) {
    jumlah = 0;

}

void Keranjang::tambahBarang(Inventori *b, int qty) {

    if (jumlah < 100) {
        items[jumlah] = new ItemKeranjang(b, qty);
        jumlah++;
        cout << "Barang berhasil ditambahkan ke keranjang!\n";

    } else {
        cout << "Keranjang penuh!\n";

    }

}

void Keranjang::tampilkanKeranjang() {

    cout << "\n=== ISI KERANJANG ===\n";

    if (jumlah == 0) {
        cout << "Keranjang masih kosong.\n";
        return;

    }

    for (int i = 0; i < jumlah; i++) {
        cout << "\nBarang ke-" << i+1 << endl;
        items[i]->tampil();

    }

}

long Keranjang::totalBelanja() {

    long total = 0;

    for (int i = 0; i < jumlah; i++) {
        total += items[i]->totalHarga();

    }

    return total;

}

/*
int main() {
    Keranjang cart;

    makanan mk1, mk2;
    minuman mn1, mn2;
    peralatan p1, p2;

    mk1.setMakanan("Indomie", 100, 3000, "19/09/2027");
    mk2.setMakanan("Roti", 50, 8000, "25/11/2025");
    mn1.setMinuman("Sprite", 50, 5000, "25/10/2027");
    mn2.setMinuman("Teh Pucuk", 100, 4000, "25/10/2027");
    p1.setPeralatan("Sapu", 15, 30000, "Rumah Tangga");
    p2.setPeralatan("Sabun", 20, 4000, "Kesehatan");

    int pilihan;

    while (true) {
        cout << "\n=== Masukkan ke Keranjang ===\n";
        cout << "1. Masukkan Indomie\n";
        cout << "2. Masukkan Roti\n";
        cout << "3. Masukkan Sprite\n";
        cout << "4. Masukkan Teh Pucuk\n";
        cout << "5. Masukkan Sapu\n";
        cout << "6. Masukkan Sabun\n";
        cout << "7. Lihat keranjang\n";
        cout << "8. Total belanja\n";
        cout << "9. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;

        int jml;

        if (pilihan >= 1 && pilihan <= 6) {
            cout << "Masukkan jumlah yang ingin dibeli: ";
            cin >> jml;

            if (jml <= 0) {
                cout << "Jumlah tidak valid!\n";
                continue;
            }
        }

        if (pilihan == 1) { mk1.kurangiStok(jml); cart.tambahBarang(&mk1, jml); }
        else if (pilihan == 2) { mk2.kurangiStok(jml); cart.tambahBarang(&mk2, jml); }
        else if (pilihan == 3) { mn1.kurangiStok(jml); cart.tambahBarang(&mn1, jml); }
        else if (pilihan == 4) { mn2.kurangiStok(jml); cart.tambahBarang(&mn2, jml); }
        else if (pilihan == 5) { p1.kurangiStok(jml); cart.tambahBarang(&p1, jml); }
        else if (pilihan == 6) { p2.kurangiStok(jml); cart.tambahBarang(&p2, jml); }
        else if (pilihan == 7) cart.tampilkanKeranjang();
        else if (pilihan == 8) cout << "Total belanja: " << cart.totalBelanja() << endl;
        else if (pilihan == 9) break;
        else cout << "Pilihan tidak valid!\n";
    }

    return 0;
}
*/
