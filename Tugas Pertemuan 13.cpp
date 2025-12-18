#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    string gender;
    float nilai;
    Mahasiswa* next;
    Mahasiswa* prev;
};

Mahasiswa* head = nullptr;
Mahasiswa* tail = nullptr;

void insertData() {
    Mahasiswa* baru = new Mahasiswa;
    cout << "\nMasukkan Nama   : ";
    cin.ignore();
    getline(cin, baru->nama);
    cout << "Masukkan NIM    : ";
    getline(cin, baru->nim);
    cout << "Masukkan Gender : ";
    getline(cin, baru->gender);
    cout << "Masukkan Nilai  : ";
    cin >> baru->nilai;

    baru->next = nullptr;
    baru->prev = nullptr;

    // Jika list kosong
    if (!head) {
        head = tail = baru;
        return;
    }

    // Jika NIM lebih kecil dari head
    if (baru->nim < head->nim) {
        baru->next = head;
        head->prev = baru;
        head = baru;
        return;
    }

    // Sisipkan secara terurut
    Mahasiswa* bantu = head;
    while (bantu->next && bantu->next->nim < baru->nim) {
        bantu = bantu->next;
    }

    baru->next = bantu->next;
    baru->prev = bantu;
    if (bantu->next) {
        bantu->next->prev = baru;
    } else {
        tail = baru;
    }
    bantu->next = baru;
}

void hapusData() {
    if (!head) {
        cout << "\nData masih kosong!\n";
        return;
    }

    string target;
    cout << "\nMasukkan NIM yang ingin dihapus: ";
    cin.ignore();
    getline(cin, target);

    Mahasiswa* bantu = head;
    while (bantu && bantu->nim != target) {
        bantu = bantu->next;
    }

    if (!bantu) {
        cout << "Data dengan NIM " << target << " tidak ditemukan!\n";
        return;
    }

    if (bantu == head) {
        head = head->next;
        if (head) head->prev = nullptr;
    } else if (bantu == tail) {
        tail = tail->prev;
        tail->next = nullptr;
    } else {
        bantu->prev->next = bantu->next;
        bantu->next->prev = bantu->prev;
    }

    delete bantu;
    cout << "Data berhasil dihapus!\n";
}

void cetakData() {
    if (!head) {
        cout << "\nData masih kosong!\n";
        return;
    }

    Mahasiswa* bantu = head;
    cout << "\n=== DATA MAHASISWA ===\n";
    while (bantu) {
        cout << "Nama   : " << bantu->nama << endl;
        cout << "NIM    : " << bantu->nim << endl;
        cout << "Gender : " << bantu->gender << endl;
        cout << "Nilai  : " << bantu->nilai << endl;
        cout << "------------------------\n";
        bantu = bantu->next;
    }
}

int main() {
    int pilihan;
    do {
        cout << "\n==============================\n";
        cout << "  LINEAR DOUBLY LINKED LIST\n";
        cout << "==============================\n";
        cout << "1. INSERT DATA\n";
        cout << "2. HAPUS DATA\n";
        cout << "3. CETAK DATA\n";
        cout << "4. EXIT\n";
        cout << "Pilihan (1 - 4): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: insertData(); break;
            case 2: hapusData(); break;
            case 3: cetakData(); break;
            case 4: cout << "Program selesai.\n"; break;
            default: cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 4);

    return 0;
}

