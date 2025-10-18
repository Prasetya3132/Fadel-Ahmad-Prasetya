#include <iostream>
using namespace std;

// Struktur node untuk stack (linked list)
struct Node {
    int data;
    Node* link;
};

// Pointer ke atas stack
Node* top = NULL;

// Fungsi PUSH – Menambahkan elemen ke stack
void push(int data) {
    Node* temp = new Node();

    if (!temp) {
        cout << "\nHeap Overflow";
        exit(1);
    }

    temp->data = data;
    temp->link = top;
    top = temp;
}

// Fungsi untuk mengecek apakah stack kosong
bool isEmpty() {
    return top == NULL;
}

// Fungsi untuk melihat elemen paling atas
int peek() {
    if (!isEmpty()) {
        return top->data;
    } else {
        cout << "Stack kosong!\n";
        exit(1);
    }
}

// Fungsi POP – Menghapus elemen paling atas
void pop() {
    if (isEmpty()) {
        cout << "\nStack Underflow\n";
        return;
    }

    Node* temp = top;
    top = top->link;
    delete temp;
}

// Fungsi untuk menampilkan semua elemen dalam stack
void display() {
    if (isEmpty()) {
        cout << "\nStack kosong\n";
        return;
    }

    Node* temp = top;
    cout << "Isi Stack: ";
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->link;
    }
    cout << "NULL\n";
}

// Program utama
int main() {
    // PUSH elemen ke stack
    push(11);
    push(22);
    push(33);
    push(44);

    display();  // Output: 44 -> 33 -> 22 -> 11 -> NULL

    // Menampilkan elemen paling atas
    cout << "Elemen Top adalah: " << peek() << endl;  // Output: 44

    // POP dua elemen
    pop(); // Hapus 44
    pop(); // Hapus 33

    display();  // Output: 22 -> 11 -> NULL

    // Menampilkan elemen paling atas setelah POP
    cout << "Elemen Top adalah: " << peek() << endl;  // Output: 22

    return 0;
}

