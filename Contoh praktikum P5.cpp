#include <iostream>
using namespace std;

#define MAX 5

// Deklarasi kelas Double Stack
class DStack {
private:
    int top1;
    int top2;
    int ele[MAX];

public:
    DStack();                    // Konstruktor (Inisialisasi)
    void pushA(int item);       // Push ke Stack1
    void pushB(int item);       // Push ke Stack2
    int popA(int *item);        // Pop dari Stack1
    int popB(int *item);        // Pop dari Stack2
};

// Inisialisasi Double Stack
DStack::DStack() {
    top1 = -1;
    top2 = MAX;
}

// Push ke Stack1
void DStack::pushA(int item) {
    if (top2 == top1 + 1) {
        cout << "\nStack Overflow Stack1";
        return;
    }
    ele[++top1] = item;
    cout << "\nItem disisipkan ke Stack1: " << item;
}

// Push ke Stack2
void DStack::pushB(int item) {
    if (top2 == top1 + 1) {
        cout << "\nStack Overflow Stack2";
        return;
    }
    ele[--top2] = item;
    cout << "\nItem disisipkan ke Stack2: " << item;
}

// Pop dari Stack1
int DStack::popA(int *item) {
    if (top1 == -1) {
        cout << "\nStack Underflow Stack1";
        return -1;
    }
    *item = ele[top1--];
    return 0;
}

// Pop dari Stack2
int DStack::popB(int *item) {
    if (top2 == MAX) {
        cout << "\nStack Underflow Stack2";
        return -1;
    }
    *item = ele[top2++];
    return 0;
}

// Fungsi utama
int main() {
    DStack ds;
    int item;

    // Push ke Stack1
    ds.pushA(10);
    ds.pushA(20);
    ds.pushA(30);

    // Push ke Stack2
    ds.pushB(40);
    ds.pushB(50);
    ds.pushB(60); // Ini akan menyebabkan overflow

    // Pop dari Stack1
    if (ds.popA(&item) == 0) cout << "\nItem dihapus dari Stack1: " << item;
    if (ds.popA(&item) == 0) cout << "\nItem dihapus dari Stack1: " << item;
    if (ds.popA(&item) == 0) cout << "\nItem dihapus dari Stack1: " << item;
    if (ds.popA(&item) == 0) cout << "\nItem dihapus dari Stack1: " << item; // Underflow

    // Pop dari Stack2
    if (ds.popB(&item) == 0) cout << "\nItem dihapus dari Stack2: " << item;
    if (ds.popB(&item) == 0) cout << "\nItem dihapus dari Stack2: " << item;
    if (ds.popB(&item) == 0) cout << "\nItem dihapus dari Stack2: " << item; // Underflow

    return 0;
}

