#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    string gender;
    float nilai;
    Mahasiswa* next;
};

Mahasiswa* head = NULL;

void insertData() {
    Mahasiswa* baru = new Mahasiswa;
    cout << "Masukkan Nama: ";
    cin.ignore();
    getline(cin, baru->nama);
    cout << "Masukkan NIM: ";
    cin >> baru->nim;
    cout << "Masukkan Gender: ";
    cin >> baru->gender;
    cout << "Masukkan Nilai Struktur Data: ";
    cin >> baru->nilai;

    baru->next = head;
    head = baru;
    cout << "\nData berhasil dimasukkan ke Stack!\n";
}

void hapusData() {
    if (head == NULL) {
        cout << "Stack kosong!\n";
        return;
    }
    Mahasiswa* hapus = head;
    head = head->next;
    cout << "\nData teratas (" << hapus->nama << ") berhasil dihapus.\n";
    delete hapus;
}

void cetakData() {
    if (head == NULL) {
        cout << "Stack kosong!\n";
        return;
    }

    Mahasiswa* bantu = head;
    cout << "\nData Mahasiswa dalam Stack:\n";
    cout << "---------------------------------------------\n";
    while (bantu != NULL) {
        cout << "Nama   : " << bantu->nama << endl;
        cout << "NIM    : " << bantu->nim << endl;
        cout << "Gender : " << bantu->gender << endl;
        cout << "Nilai  : " << bantu->nilai << endl;
        cout << "---------------------------------------------\n";
        bantu = bantu->next;
    }
}

int main() {
    int pilihan;
    do {
        cout << "\n=== PROGRAM STACK LINKED LIST (ADA HEAD) ===\n";
        cout << "1. INSERT DATA\n";
        cout << "2. HAPUS DATA\n";
        cout << "3. CETAK DATA\n";
        cout << "4. EXIT\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: insertData(); break;
            case 2: hapusData(); break;
            case 3: cetakData(); break;
            case 4: cout << "Keluar dari program.\n"; break;
            default: cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 4);

    return 0;
}

