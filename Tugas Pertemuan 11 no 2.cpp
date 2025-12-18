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

Mahasiswa* top = NULL;

void push() {
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

    baru->next = top;
    top = baru;
    cout << "\nData berhasil dimasukkan ke Stack!\n";
}

void pop() {
    if (top == NULL) {
        cout << "Stack kosong!\n";
        return;
    }
    Mahasiswa* hapus = top;
    cout << "\nData teratas (" << hapus->nama << ") berhasil dihapus.\n";
    top = top->next;
    delete hapus;
}

void display() {
    if (top == NULL) {
        cout << "Stack kosong!\n";
        return;
    }

    Mahasiswa* bantu = top;
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
        cout << "\n=== PROGRAM STACK LINKED LIST TANPA HEAD ===\n";
        cout << "1. INSERT DATA\n";
        cout << "2. HAPUS DATA\n";
        cout << "3. CETAK DATA\n";
        cout << "4. EXIT\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: display(); break;
            case 4: cout << "Keluar dari program.\n"; break;
            default: cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 4);

    return 0;
}

