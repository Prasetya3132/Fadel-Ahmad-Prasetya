#include <iostream>
using namespace std;

const int MAX = 10;
int stack[MAX];
int top = -1;

bool isFull() {
    return top == MAX - 1;
}

bool isEmpty() {
    return top == -1;
}

void push(int data) {
    stack[++top] = data;
}

int pop() {
    return stack[top--];
}

int main() {
    int data;

    // PUSH proses
    cout << "Masukkan data ke stack (999 untuk selesai):\n";
    while (true) {
        cin >> data;
        if (data == 999 || isFull()) break;
        push(data);
    }

    if (isFull()) {
        cout << "Stack Penuh\n";
    }

    // POP proses
    cout << "\nMengeluarkan data dari stack:\n";
    while (!isEmpty()) {
        cout << pop() << endl;
    }

    return 0;
}

