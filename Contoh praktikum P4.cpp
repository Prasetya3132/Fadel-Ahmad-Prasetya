#include <iostream>
using namespace std;

#define MAX 100

class Stack {
    int top;
    int a[MAX]; // Array untuk menyimpan elemen stack

public:
    Stack() { top = -1; } // Konstruktor

    bool push(int x);
    int pop();
    int peek();
    bool isEmpty();
};

// Fungsi PUSH
bool Stack::push(int x) {
    if (top >= (MAX - 1)) {
        cout << "Stack Overflow\n";
        return false;
    } else {
        a[++top] = x;
        cout << x << " didorong ke dalam tumpukan\n";
        return true;
    }
}

// Fungsi POP
int Stack::pop() {
    if (top < 0) {
        cout << "Stack Underflow\n";
        return 0;
    } else {
        int x = a[top--];
        return x;
    }
}

// Fungsi PEEK
int Stack::peek() {
    if (top < 0) {
        cout << "Tumpukan Kosong\n";
        return 0;
    } else {
        return a[top];
    }
}

// Fungsi untuk mengecek apakah stack kosong
bool Stack::isEmpty() {
    return (top < 0);
}

// Fungsi MAIN
int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << s.pop() << " dikeluarkan dari tumpukan\n";

    return 0;
}

