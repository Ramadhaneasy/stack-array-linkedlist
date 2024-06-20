#include <iostream>
#include <string>

using namespace std;

struct Node {
    string nama;
    Node* next;
};

class Stack {
private:
    Node* top;
    int size;
public:
    Stack() {
        top = nullptr;
        size = 0;
    }

    bool apakahKosong() {
        return top == nullptr;
    }

    void tambahItem(string nama) {
        Node* newNode = new Node();
        newNode->nama = nama;
        newNode->next = top;
        top = newNode;
        size++;
        cout << nama << " telah dimasukkan ke antrian." << endl;
    }

    void ambilItem() {
        if (apakahKosong()) {
            cout << "antrian kosong!" << endl;
        } else {
            Node* temp = top;
            cout << "Tiket yang diambil: " << top->nama << endl;
            top = top->next;
            delete temp;
            size--;
        }
    }

    void cetakStack() {
        if (apakahKosong()) {
            cout << "antrian kosong!" << endl;
        } else {
            Node* temp = top;
            cout << "Daftar orang dalam antrian:" << endl;
            while (temp != nullptr) {
                cout << "- " << temp->nama << endl;
                temp = temp->next;
            }
            cout << endl;
        }
    }

    int getSize() {
        return size;
    }

    void kosongkanStack() {
        while (!apakahKosong()) {
            ambilItem();
        }
        cout << "antrian sudah dikosongkan." << endl;
    }
};

int main() {
    Stack stackTiket;

    // Daftar nama yang sudah ditentukan
    string namaList[] = {"Yanto", "Bagas", "Nina", "Ilham", "Riski", "Brodi"};

    // Tambahkan nama-nama ke stack
    for (int i = 0; i < 6; ++i) {
        stackTiket.tambahItem(namaList[i]);
    }

    stackTiket.cetakStack();

    stackTiket.ambilItem();
    stackTiket.cetakStack();

    cout << "Apakah antrian kosong? " << stackTiket.apakahKosong() << endl;
    cout << "Jumlah orang dalam antrian: " << stackTiket.getSize() << endl;

    stackTiket.kosongkanStack();
    cout << "Apakah antrian kosong? " << stackTiket.apakahKosong() << endl;
    return 0;
}
