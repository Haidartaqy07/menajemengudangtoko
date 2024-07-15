#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

struct Barang {
    int id;
    string nama;
    int stok;
    string tanggalMasuk;
    string lokasiRak;
};

vector<Barang> inventori;

void tambahBarang() {
    Barang barangBaru;
    cout << "Masukkan ID barang: ";
    while (!(cin >> barangBaru.id)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Input tidak valid. Masukkan ID barang: ";
    }
    cout << "Masukkan nama barang: ";
    cin.ignore();
    getline(cin, barangBaru.nama);
    cout << "Masukkan jumlah stok: ";
    while (!(cin >> barangBaru.stok)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Input tidak valid. Masukkan jumlah stok: ";
    }
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

void perbaruiBarang() {
    int id;
    cout << "Masukkan ID barang yang ingin diperbarui: ";
    cin >> id;
    for (auto &barang : inventori) {
        if (barang.id == id) {
            cout << "Masukkan nama barang baru: ";
            cin.ignore();
            getline(cin, barang.nama);
            cout << "Masukkan jumlah stok baru: ";
            while (!(cin >> barang.stok)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Input tidak valid. Masukkan jumlah stok baru: ";
            }
            cout << "Masukkan tanggal masuk baru (YYYY-MM-DD): ";
            cin.ignore();
            getline(cin, barang.tanggalMasuk);
            cout << "Masukkan lokasi rak baru: ";
            getline(cin, barang.lokasiRak);
            cout << "Barang berhasil diperbarui!\n";
            return;
        }
    }
    cout << "Barang tidak ditemukan.\n";
}

void cekStok() {
    int id;
    cout << "Masukkan ID barang untuk mengecek stok: ";
    cin >> id;
    for (const auto &barang : inventori) {
        if (barang.id == id) {
            cout << "Barang: " << barang.nama << "\nStok: " << barang.stok
                 << "\nTanggal Masuk: " << barang.tanggalMasuk << "\nLokasi Rak: " << barang.lokasiRak << endl;
            return;
        }
    }
    cout << "Barang tidak ditemukan.\n";
}

void daftarBarang() {
    if (inventori.empty()) {
        cout << "Inventori kosong.\n";
    } else {
        cout << "Daftar inventori:\n";
        for (const auto &barang : inventori) {
            cout << "ID: " << barang.id << "\nNama: " << barang.nama << "\nStok: " << barang.stok
                 << "\nTanggal Masuk: " << barang.tanggalMasuk << "\nLokasi Rak: " << barang.lokasiRak << endl << endl;
        }
    }
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
            case 1:
                tambahBarang();
                break;
            case 2:
                hapusBarang();
                break;
            case 3:
                perbaruiBarang();
                break;
            case 4:
                cekStok();
                break;
            case 5:
                daftarBarang();
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
