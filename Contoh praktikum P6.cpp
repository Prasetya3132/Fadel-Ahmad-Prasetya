#include <iostream>
using namespace std;

#define MAX 5

class Queue {
private:
    int front, rear;
    int ele[MAX];

public:
    Queue() {
        front = 0;
        rear = -1;
    }

    int isFull();
    int isEmpty();
    void insertQueue(int item);
    int deleteQueue(int *item);
};

// Mengecek apakah queue penuh
int Queue::isFull() {
    return (rear == MAX - 1);
}

// Mengecek apakah queue kosong
int Queue::isEmpty() {
    return (front > rear);
}

// Menyisipkan elemen ke queue
void Queue::insertQueue(int item) {
    if (isFull()) {
        cout << "\nQueue Overflow" << endl;
        return;
    }
    ele[++rear] = item;
    cout << "\nNilai yang disisipkan: " << item;
}

// Menghapus elemen dari queue
int Queue::deleteQueue(int *item) {
    if (isEmpty()) {
        cout << "\nQueue Underflow" << endl;
        return -1;
    }
    *item = ele[front++];
    return 0;
}

int main() {
    int item = 0;
    Queue q;

    // Menyisipkan 6 item (lebih dari MAX)
    q.insertQueue(10);
    q.insertQueue(20);
    q.insertQueue(30);
    q.insertQueue(40);
    q.insertQueue(50);
    q.insertQueue(60);  // Akan gagal, karena antrian penuh

    // Menghapus item satu per satu
    if (q.deleteQueue(&item) == 0)
        cout << "\nItem dihapus: " << item;

    if (q.deleteQueue(&item) == 0)
        cout << "\nItem dihapus: " << item;

    if (q.deleteQueue(&item) == 0)
        cout << "\nItem dihapus: " << item;

    if (q.deleteQueue(&item) == 0)
        cout << "\nItem dihapus: " << item;

    if (q.deleteQueue(&item) == 0)
        cout << "\nItem dihapus: " << item;

    if (q.deleteQueue(&item) == 0)
        cout << "\nItem dihapus: " << item;

    cout << endl;
    return 0;
}

