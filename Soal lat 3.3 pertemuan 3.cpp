#include <iostream>
using namespace std;

struct Mahasiswa {
    int noUrut;
    char nama[50];
    int umur;
    char alamat[100];
    float nilai;
};

int main() {
    Mahasiswa mhs[15];

    for (int i = 0; i < 15; i++) {
        mhs[i].noUrut = i + 1;
        cout << "Data Mahasiswa ke-" << mhs[i].noUrut << endl;
        cin.ignore();
        cout << "Nama   : ";
        cin.getline(mhs[i].nama, 50);
        cout << "Umur   : ";
        cin >> mhs[i].umur;
        cin.ignore();
        cout << "Alamat : ";
        cin.getline(mhs[i].alamat, 100);
        cout << "Nilai  : ";
        cin >> mhs[i].nilai;
        cout << endl;
    }

    cout << "\n=== Data Seluruh Mahasiswa ===\n";
    for (int i = 0; i < 15; i++) {
        cout << "No Urut: " << mhs[i].noUrut << endl;
        cout << "Nama   : " << mhs[i].nama << endl;
        cout << "Umur   : " << mhs[i].umur << endl;
        cout << "Alamat : " << mhs[i].alamat << endl;
        cout << "Nilai  : " << mhs[i].nilai << "\n\n";
    }

    return 0;
}

