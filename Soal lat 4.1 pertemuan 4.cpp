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
    top++;
    stack[top] = data;
    cout << "PUSH: " << data << " ke stack\n";
}

void pop() {
    cout << "POP: " << stack[top] << " dari stack\n";
    top--;
}

int main() {
    int data;

    while (true) {
        cout << "Masukkan data (999 untuk selesai): ";
        cin >> data;

        if (data == 999) break;

        if (data >= 60) {
            if (!isFull()) {
                push(data);
            } else {
                cout << "Stack Penuh\n";
                break;
            }
        } else {
            if (!isEmpty()) {
                pop();
            } else {
                cout << "Stack Kosong\n";
                break;
            }
        }
    }

    return 0;
}

