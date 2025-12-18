#include <iostream>
using namespace std;

int main() {
    int data[] = {5, 7, 12, 15, 17, 19, 22, 25, 27, 32};
    int n = sizeof(data) / sizeof(data[0]);
    int cari;

    cout << "Masukkan nilai yang ingin dicari: ";
    cin >> cari;

    int kiri = 0;
    int kanan = n - 1;
    int tengah;
    int iterasi = 0;
    bool ketemu = false;

    while (kiri <= kanan) {
        iterasi++;
        tengah = (kiri + kanan) / 2;

        cout << "Iterasi ke-" << iterasi
             << " | Indeks tengah: " << tengah
             << " | Nilai: " << data[tengah] << endl;

        if (data[tengah] == cari) {
            ketemu = true;
            break;
        } else if (cari < data[tengah]) {
            kanan = tengah - 1;
        } else {
            kiri = tengah + 1;
        }
    }

    if (ketemu) {
        cout << "\nNilai " << cari
             << " ditemukan pada iterasi ke-" << iterasi
             << " di indeks " << tengah << endl;
    } else {
        cout << "\nNilai " << cari << " tidak ditemukan dalam data." << endl;
    }

    return 0;
}

