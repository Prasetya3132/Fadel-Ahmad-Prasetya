#include <iostream>
using namespace std;

struct Mahasiswa {
    int noUrut;
    char nama[50];
    int usia;
};

int main() {
    Mahasiswa mhs[5];

    for (int i = 0; i < 5; i++) {
        mhs[i].noUrut = i + 1;
        cout << "Masukkan Nama Mahasiswa " << mhs[i].noUrut << ": ";
        cin.ignore();
        cin.getline(mhs[i].nama, 50);
        cout << "Masukkan Usia Mahasiswa " << mhs[i].noUrut << ": ";
        cin >> mhs[i].usia;
    }

    cout << "\nData Mahasiswa No Urut 2:\n";
    cout << "Nama: " << mhs[1].nama << endl;
    cout << "Usia: " << mhs[1].usia << endl;

    return 0;
}

