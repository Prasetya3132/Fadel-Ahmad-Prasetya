#include <iostream>
using namespace std;

#define MAX 5  // Maksimum kapasitas queue

// Deklarasi class Double Ended Queue
class DQueue {
private:
    int front;
    int rear;
    int ele[MAX];

public:
    // Konstruktor: Inisialisasi nilai awal
    DQueue() {
        front = MAX / 2;
        rear = front - 1;
    }

    // Cek apakah queue kosong
    bool isEmpty() {
        return front > rear;
    }

    // Cek apakah queue penuh total
    bool isFull() {
        return front == 0 && rear == MAX - 1;
    }

    // Insert dari kanan (rear)
    void insertDQueueAtRear(int item) {
        if (rear < MAX - 1) {
            rear++;
            ele[rear] = item;
            cout << "Item dimasukkan dari kanan: " << item << " | FRONT: " << front << ", REAR: " << rear << endl;
        } else {
            cout << "Queue penuh dari kanan!" << endl;
        }
    }

    // Insert dari kiri (front)
    void insertDQueueAtFront(int item) {
        if (front > 0) {
            front--;
            ele[front] = item;
            cout << "Item dimasukkan dari kiri: " << item << " | FRONT: " << front << ", REAR: " << rear << endl;
        } else {
            cout << "Queue penuh dari kiri!" << endl;
        }
    }

    // Delete dari kiri (front)
    int deleteDQueueAtFront(int* item) {
        if (!isEmpty()) {
            *item = ele[front];
            front++;
            return 0;
        } else {
            cout << "Queue kosong!" << endl;
            return -1;
        }
    }

    // Delete dari kanan (rear)
    int deleteDQueueAtRear(int* item) {
        if (!isEmpty()) {
            *item = ele[rear];
            rear--;
            return 0;
        } else {
            cout << "Queue kosong!" << endl;
            return -1;
        }
    }
};

// Fungsi utama (main)
int main() {
    DQueue q;
    int item;

    // Masukkan beberapa item dari kanan
    q.insertDQueueAtRear(10);
    q.insertDQueueAtRear(20);
    q.insertDQueueAtRear(30);

    // Masukkan dari kiri
    q.insertDQueueAtFront(40);
    q.insertDQueueAtFront(50);

    // Gagal insert dari kiri (karena penuh kiri)
    q.insertDQueueAtFront(60);

    // Hapus dari kiri
    if (q.deleteDQueueAtFront(&item) == 0)
        cout << "Item dihapus dari kiri: " << item << endl;

    if (q.deleteDQueueAtFront(&item) == 0)
        cout << "Item dihapus dari kiri: " << item << endl;

    if (q.deleteDQueueAtFront(&item) == 0)
        cout << "Item dihapus dari kiri: " << item << endl;

    // Hapus dari kanan
    if (q.deleteDQueueAtRear(&item) == 0)
        cout << "Item dihapus dari kanan: " << item << endl;

    if (q.deleteDQueueAtRear(&item) == 0)
        cout << "Item dihapus dari kanan: " << item << endl;

    // Gagal hapus lagi (karena queue kosong)
    if (q.deleteDQueueAtRear(&item) == 0)
        cout << "Item dihapus dari kanan: " << item << endl;

    return 0;
}

