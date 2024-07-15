#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Barang {
    int id;
    string nama;
    int stok;
    string tanggalMasuk;
    string lokasiRak;
};

vector<Barang> inventori;

void tambahBarang();
void hapusBarang();
void menu(); // Deklarasi prototipe fungsi menu()

void tambahBarang() {
    Barang barangBaru;
    cout << "Masukkan ID barang: ";
    cin >> barangBaru.id;
    cout << "Masukkan nama barang: ";
    cin.ignore();
    getline(cin, barangBaru.nama);
    cout << "Masukkan jumlah stok: ";
    cin >> barangBaru.stok;
    cout << "Masukkan tanggal masuk (YYYY-MM-DD): ";
    cin.ignore();
    getline(cin, barangBaru.tanggalMasuk);
    cout << "Masukkan lokasi rak: ";
    getline(cin, barangBaru.lokasiRak);
    inventori.push_back(barangBaru);
    cout << "Barang berhasil ditambahkan!\n";
}

void hapusBarang() {
    int id;
    cout << "Masukkan ID barang yang ingin dihapus: ";
    cin >> id;
    for (auto it = inventori.begin(); it != inventori.end(); ++it) {
        if (it->id == id) {
            inventori.erase(it);
            cout << "Barang berhasil dihapus!\n";
            return;
        }
    }
    cout << "Barang tidak ditemukan.\n";
}

void menu() {
    int pilihan;
    do {
        cout << "\nSistem Manajemen Inventori\n";
        cout << "1. Tambah Barang\n";
        cout << "2. Hapus Barang\n";
        cout << "3. Perbarui Barang\n";
        cout << "4. Cek Stok\n";
        cout << "5. Daftar Semua Barang\n";
        cout << "6. Keluar\n";
        cout << "Masukkan pilihan Anda: ";
        cin >> pilihan;
        switch (pilihan) {
            case 1: tambahBarang(); break;
            case 2: hapusBarang(); break;
            case 3:
                // perbaruiBarang();
                break;
            case 4:
                // cekStok();
                break;
            case 5:
                // daftarBarang();
                break;
            case 6:
                cout << "Keluar dari sistem.\n";
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }
    } while (pilihan != 6);
}

int main() {
    menu();
    return 0;
}

