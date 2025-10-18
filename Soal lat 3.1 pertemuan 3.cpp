#include <iostream>
using namespace std;

struct Mahasiswa {
    int noUrut;
    char nama[50];
    int usia;
    float nilai;
};

int main() {
    Mahasiswa m;

    cout << "Masukkan No Urut: ";
    cin >> m.noUrut;
    cin.ignore(); 
    cout << "Masukkan Nama: ";
    cin.getline(m.nama, 50);
    cout << "Masukkan Usia: ";
    cin >> m.usia;
    cout << "Masukkan Nilai: ";
    cin >> m.nilai;

    cout << "\nData Mahasiswa:\n";
    cout << "No Urut: " << m.noUrut << endl;
    cout << "Nama: " << m.nama << endl;
    cout << "Usia: " << m.usia << endl;
    cout << "Nilai: " << m.nilai << endl;

    return 0;
}

