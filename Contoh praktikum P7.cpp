#include <iostream>
using namespace std;

#define MAX 5

// Deklarasi Circular Queue
class CirQueue {
private:
    int front;
    int rear;
    int count;
    int ele[MAX];

public:
    CirQueue();
    int isFull();
    int isEmpty();
    void insertQueue(int item);
    int deleteQueue(int *item);
};

// Inisialisasi Circular Queue
CirQueue::CirQueue() {
    front = 0;
    rear = -1;
    count = 0;
}

// Mengecek apakah queue penuh
int CirQueue::isFull() {
    return (count == MAX);
}

// Mengecek apakah queue kosong
int CirQueue::isEmpty() {
    return (count == 0);
}

// Menambahkan item ke antrian
void CirQueue::insertQueue(int item) {
    if (isFull()) {
        cout << "\nQueue Overflow";
        return;
    }

    rear = (rear + 1) % MAX;
    ele[rear] = item;
    count++;

    cout << "\nItem dimasukkan: " << item;
}

// Menghapus item dari antrian
int CirQueue::deleteQueue(int *item) {
    if (isEmpty()) {
        cout << "\nQueue Underflow";
        return -1;
    }

    *item = ele[front];
    front = (front + 1) % MAX;
    count--;

    return 0;
}

// Program utama
int main() {
    int item;
    CirQueue q;

    // Insert 6 item (1 lebih dari kapasitas MAX = 5)
    q.insertQueue(10);
    q.insertQueue(20);
    q.insertQueue(30);
    q.insertQueue(40);
    q.insertQueue(50);
    q.insertQueue(60); // Harusnya gagal (overflow)

    // Delete 5 item
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

    // Insert setelah delete (harus berhasil karena circular)
    q.insertQueue(60);

    // Delete 2 item lagi
    if (q.deleteQueue(&item) == 0)
        cout << "\nItem dihapus: " << item;

    if (q.deleteQueue(&item) == 0)
        cout << "\nItem dihapus: " << item;

    cout << endl;
    return 0;
}

