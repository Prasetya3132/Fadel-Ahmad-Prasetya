#include <iostream>
#include <cstring>
using namespace std;

// Struktur Buku
struct Buku {
    int nomorAkses;
    char penulis[50];
    char judul[50];
    int jumlah;
    bool diterbitkan;
};

// Maksimal jumlah buku
const int MAX_BUKU = 100;
Buku perpustakaan[MAX_BUKU];
int jumlahBuku = 0;

// Fungsi untuk menampilkan semua buku
void tampilkanSemuaBuku() {
    if (jumlahBuku == 0) {
        cout << "Belum ada buku di perpustakaan.\n";
        return;
    }
    cout << "\n=== Daftar Buku ===\n";
    for (int i = 0; i < jumlahBuku; i++) {
        cout << "Nomor Akses : " << perpustakaan[i].nomorAkses << endl;
        cout << "Penulis     : " << perpustakaan[i].penulis << endl;
        cout << "Judul       : " << perpustakaan[i].judul << endl;
        cout << "Jumlah      : " << perpustakaan[i].jumlah << endl;
        cout << "Diterbitkan : " << (perpustakaan[i].diterbitkan ? "Ya" : "Tidak") << endl;
        cout << "-----------------------------\n";
    }
}

// Fungsi untuk menambahkan buku baru
void tambahBukuBaru() {
    if (jumlahBuku >= MAX_BUKU) {
        cout << "Kapasitas perpustakaan penuh.\n";
        return;
    }

    Buku b;
    b.nomorAkses = jumlahBuku + 1;
    cin.ignore(); // Membersihkan buffer
    cout << "Masukkan Nama Penulis : ";
    cin.getline(b.penulis, 50);
    cout << "Masukkan Judul Buku   : ";
    cin.getline(b.judul, 50);
    cout << "Masukkan Jumlah Buku  : ";
    cin >> b.jumlah;
    b.diterbitkan = false;

    perpustakaan[jumlahBuku++] = b;
    cout << "Buku berhasil ditambahkan.\n";
}

// Fungsi untuk menampilkan buku berdasarkan penulis
void tampilkanBukuPenulisTertentu() {
    if (jumlahBuku == 0) {
        cout << "Perpustakaan kosong.\n";
        return;
    }

    char cariPenulis[50];
    cin.ignore();
    cout << "Masukkan nama penulis yang dicari: ";
    cin.getline(cariPenulis, 50);

    bool ditemukan = false;
    for (int i = 0; i < jumlahBuku; i++) {
        if (strcmp(perpustakaan[i].penulis, cariPenulis) == 0) {
            cout << "\nBuku oleh " << perpustakaan[i].penulis << ":\n";
            cout << "Judul  : " << perpustakaan[i].judul << endl;
            cout << "Jumlah : " << perpustakaan[i].jumlah << endl;
            cout << "Diterbitkan : " << (perpustakaan[i].diterbitkan ? "Ya" : "Tidak") << endl;
            cout << "-----------------------------\n";
            ditemukan = true;
        }
    }

    if (!ditemukan)
        cout << "Buku oleh penulis tersebut tidak ditemukan.\n";
}

// Fungsi untuk menghitung jumlah buku dengan judul tertentu
void jumlahBukuDenganJudulTertentu() {
    if (jumlahBuku == 0) {
        cout << "Perpustakaan kosong.\n";
        return;
    }

    char cariJudul[50];
    cin.ignore();
    cout << "Masukkan judul buku yang dicari: ";
    cin.getline(cariJudul, 50);

    int total = 0;
    for (int i = 0; i < jumlahBuku; i++) {
        if (strcmp(perpustakaan[i].judul, cariJudul) == 0) {
            total += perpustakaan[i].jumlah;
        }
    }

    cout << "Jumlah total buku dengan judul \"" << cariJudul << "\": " << total << endl;
}

// Fungsi untuk menghitung jumlah total semua buku
void jumlahTotalSemuaBuku() {
    int total = 0;
    for (int i = 0; i < jumlahBuku; i++) {
        total += perpustakaan[i].jumlah;
    }
    cout << "Jumlah total semua buku di perpustakaan: " << total << endl;
}

// Fungsi untuk menerbitkan buku (mengurangi jumlah 1)
void terbitkanBuku() {
    if (jumlahBuku == 0) {
        cout << "Tidak ada buku untuk diterbitkan.\n";
        return;
    }

    int noAkses;
    cout << "Masukkan Nomor Akses Buku yang akan diterbitkan: ";
    cin >> noAkses;

    bool ditemukan = false;
    for (int i = 0; i < jumlahBuku; i++) {
        if (perpustakaan[i].nomorAkses == noAkses) {
            if (perpustakaan[i].jumlah > 0) {
                perpustakaan[i].jumlah--;
                perpustakaan[i].diterbitkan = true;
                cout << "Buku berhasil diterbitkan. Sisa: " << perpustakaan[i].jumlah << endl;
            } else {
                cout << "Buku habis, tidak bisa diterbitkan.\n";
            }
            ditemukan = true;
            break;
        }
    }

    if (!ditemukan)
        cout << "Nomor akses tidak ditemukan.\n";
}

// Main Program
int main() {
    int pilihan;

    do {
        cout << "\n=== MENU PERPUSTAKAAN ===\n";
        cout << "1 - Tampilkan Semua Informasi Buku\n";
        cout << "2 - Tambah Buku Baru\n";
        cout << "3 - Tampilkan Buku Berdasarkan Penulis\n";
        cout << "4 - Tampilkan Jumlah Buku Berdasarkan Judul\n";
        cout << "5 - Tampilkan Jumlah Total Semua Buku\n";
        cout << "6 - Terbitkan Buku\n";
        cout << "0 - Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: tampilkanSemuaBuku(); break;
            case 2: tambahBukuBaru(); break;
            case 3: tampilkanBukuPenulisTertentu(); break;
            case 4: jumlahBukuDenganJudulTertentu(); break;
            case 5: jumlahTotalSemuaBuku(); break;
            case 6: terbitkanBuku(); break;
            case 0: cout << "Terima kasih. Program selesai.\n"; break;
            default: cout << "Pilihan tidak valid.\n"; break;
        }
    } while (pilihan != 0);

    return 0;
}

