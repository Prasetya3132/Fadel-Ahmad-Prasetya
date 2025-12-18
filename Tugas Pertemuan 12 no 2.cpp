#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string NIM;
    string Nama;
    float Nilai;
    Mahasiswa* next;
};

Mahasiswa* head = NULL;

// ==================== a. Tambah Data ====================
void tambahData() {
    Mahasiswa* baru = new Mahasiswa;
    cout << "\nMasukkan NIM   : ";
    cin >> baru->NIM;
    cout << "Masukkan Nama  : ";
    cin.ignore();
    getline(cin, baru->Nama);
    cout << "Masukkan Nilai : ";
    cin >> baru->Nilai;

    // Sisipkan secara terurut (ascending) berdasarkan Nilai
    if (head == NULL || baru->Nilai < head->Nilai) {
        baru->next = head;
        head = baru;
    } else {
        Mahasiswa* bantu = head;
        while (bantu->next != NULL && bantu->next->Nilai < baru->Nilai) {
            bantu = bantu->next;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }

    cout << "\n? Data berhasil ditambahkan!\n";
}

// ==================== b. Tampilkan data nilai = 90 ====================
void tampilkanNilai90() {
    if (head == NULL) {
        cout << "\nList kosong!\n";
        return;
    }

    bool ketemu = false;
    Mahasiswa* bantu = head;
    cout << "\nData Mahasiswa dengan Nilai = 90:\n";
    cout << "-----------------------------------------\n";
    while (bantu != NULL) {
        if (bantu->Nilai == 90) {
            cout << "NIM   : " << bantu->NIM << endl;
            cout << "Nama  : " << bantu->Nama << endl;
            cout << "Nilai : " << bantu->Nilai << endl;
            cout << "-----------------------------------------\n";
            ketemu = true;
        }
        bantu = bantu->next;
    }

    if (!ketemu) cout << "Tidak ada mahasiswa dengan nilai 90.\n";
}

// ==================== c. Tampilkan seluruh data ====================
void tampilkanSeluruh() {
    if (head == NULL) {
        cout << "\nList kosong!\n";
        return;
    }

    Mahasiswa* bantu = head;
    cout << "\nDaftar Seluruh Mahasiswa (Urut Nilai Naik):\n";
    cout << "-----------------------------------------\n";
    while (bantu != NULL) {
        cout << "NIM   : " << bantu->NIM << endl;
        cout << "Nama  : " << bantu->Nama << endl;
        cout << "Nilai : " << bantu->Nilai << endl;
        cout << "-----------------------------------------\n";
        bantu = bantu->next;
    }
}

// ==================== d. Hapus data berdasarkan NIM ====================
void hapusData(string targetNIM) {
    if (head == NULL) {
        cout << "\nList kosong!\n";
        return;
    }

    Mahasiswa* hapus;
    if (head->NIM == targetNIM) {
        hapus = head;
        head = head->next;
        delete hapus;
        cout << "\n? Data dengan NIM " << targetNIM << " berhasil dihapus.\n";
        return;
    }

    Mahasiswa* bantu = head;
    while (bantu->next != NULL && bantu->next->NIM != targetNIM) {
        bantu = bantu->next;
    }

    if (bantu->next == NULL) {
        cout << "\n? Data dengan NIM " << targetNIM << " tidak ditemukan.\n";
    } else {
        hapus = bantu->next;
        bantu->next = bantu->next->next;
        delete hapus;
        cout << "\n? Data dengan NIM " << targetNIM << " berhasil dihapus.\n";
    }
}

// ==================== e. Hitung nilai rata-rata ====================
void hitungRataRata() {
    if (head == NULL) {
        cout << "\nList kosong!\n";
        return;
    }

    int count = 0;
    float total = 0;
    Mahasiswa* bantu = head;

    while (bantu != NULL) {
        total += bantu->Nilai;
        count++;
        bantu = bantu->next;
    }

    cout << "\nRata-rata Nilai Kelas: " << total / count << endl;
}

// ==================== Menu ====================
int main() {
    int pilihan;
    string hapusNIM;

    do {
        cout << "\n=========== MENU LINKED LIST MAHASISWA ===========\n";
        cout << "1. Tambah Data Mahasiswa\n";
        cout << "2. Tampilkan Data Nilai = 90\n";
        cout << "3. Tampilkan Seluruh Data\n";
        cout << "4. Hapus Data (NIM = 2007140022)\n";
        cout << "5. Hitung Nilai Rata-rata Kelas\n";
        cout << "6. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tambahData(); break;
            case 2:
                tampilkanNilai90(); break;
            case 3:
                tampilkanSeluruh(); break;
            case 4:
                hapusData("2007140022"); break;
            case 5:
                hitungRataRata(); break;
            case 6:
                cout << "Keluar dari program...\n"; break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 6);

    return 0;
}

