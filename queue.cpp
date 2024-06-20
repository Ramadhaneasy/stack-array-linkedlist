#include <iostream>
#include <string>

using namespace std;

int maksimal = 10; // ukuran array sebagai variabel
string antrianKereta[10]; // inisialisasi array dengan ukuran maksimal
int front = 0; // indeks depan antrian
int rear = 0; // indeks belakang antrian

bool apakahPenuh() {
    return rear == maksimal;
}

bool apakahKosong() {
    return front == rear;
}

void tambahPenumpang(string nama) {
    if (apakahPenuh()) {
        cout << "Antrian kereta penuh!" << endl;
    } else {
        antrianKereta[rear] = nama;
        rear++;
        cout << "Penumpang " << nama << " ditambahkan ke antrian." << endl;
    }
}

void ambilPenumpang() {
    if (apakahKosong()) {
        cout << "Antrian kereta kosong!" << endl;
    } else {
        cout << "Penumpang yang diambil: " << antrianKereta[front] << endl;
        // Geser elemen ke depan
        for (int i = 0; i < rear - 1; i++) {
            antrianKereta[i] = antrianKereta[i + 1];
        }
        rear--;
    }
}

void ubahPenumpang(string nama, int posisi) {
    if (apakahKosong()) {
        cout << "Antrian kereta kosong!" << endl;
    } else {
        int indeks = front + posisi - 1;
        if (indeks >= front && indeks < rear) {
            antrianKereta[indeks] = nama;
            cout << "Penumpang di posisi " << posisi << " diubah menjadi " << nama << endl;
        } else {
            cout << "Posisi tidak valid!" << endl;
        }
    }
}

void kosongkanAntrian() {
    front = 0;
    rear = 0;
    cout << "Antrian kereta sudah dikosongkan." << endl;
}

void cetakAntrian() {
    if (apakahKosong()) {
        cout << "Antrian kereta kosong!" << endl;
    } else {
        cout << "Daftar penumpang di antrian:" << endl;
        for (int i = front; i < rear; i++) {
            cout << "- " << antrianKereta[i] << endl;
        }
        cout << endl;
    }
}

int main() {
    tambahPenumpang("Budi");
    cetakAntrian();

    tambahPenumpang("Siti");
    tambahPenumpang("Ani");
    tambahPenumpang("Tono");
    tambahPenumpang("Joko");
    cetakAntrian();

    tambahPenumpang("Rina");
    cetakAntrian();

    ambilPenumpang();
    cetakAntrian();

    cout << "Apakah antrian kereta penuh? " << apakahPenuh() << endl;
    cout << "Apakah antrian kereta kosong? " << apakahKosong() << endl;
    cout << "Jumlah penumpang: " << (rear - front) << endl;

    ubahPenumpang("Dewi", 2);
    cetakAntrian();

    kosongkanAntrian();
    cout << "Apakah antrian kereta penuh? " << apakahPenuh() << endl;
    cout << "Apakah antrian kereta kosong? " << apakahKosong() << endl;

    return 0;
}
