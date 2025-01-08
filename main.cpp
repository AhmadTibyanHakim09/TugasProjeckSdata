#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <stack>
#include "KTP.h"
#include "Item.h"
#include "Pembeli.h"
#include "InventorySystem.h"

using namespace std;

int main() {
    InventorySystem sistem;
    sistem.bacaDataKTP();
    int pilihan;
    string adminNIK;
    bool isAdminLoggedIn = false;

    while (true) {
        if (!isAdminLoggedIn) {
            cout << "\nSilakan login sebagai admin\n";
            cout << "1. Login\n";
            cout << "2. Sign Up\n";
            cout << "Pilihan: ";
            cin >> pilihan;

            if (pilihan == 1) {
                cout << "Masukkan NIK: ";
                cin >> adminNIK;
                if (sistem.adminSignIn(adminNIK)) {
                    isAdminLoggedIn = true;
                    cout << "Login berhasil!\n";
                } else {
                    cout << "NIK tidak ditemukan!\n";
                }
            } else if (pilihan == 2) {
                KTP newAdmin;
                cout << "Masukkan NIK: ";
                cin >> newAdmin.nik;
                cin.ignore();
                cout << "Masukkan Nama: ";
                getline(cin, newAdmin.nama);
                cout << "Masukkan Tempat Lahir: ";
                getline(cin, newAdmin.tempatLahir);
                cout << "Masukkan Tanggal Lahir: ";
                getline(cin, newAdmin.tanggalLahir);
                cout << "Masukkan Jenis Kelamin: ";
                getline(cin, newAdmin.jenisKelamin);
                cout << "Masukkan Alamat: ";
                getline(cin, newAdmin.alamat);
                cout << "Masukkan Agama: ";
                getline(cin, newAdmin.agama);
                cout << "Masukkan Status Perkawinan: ";
                getline(cin, newAdmin.statusPerkawinan);
                cout << "Masukkan Pekerjaan: ";
                getline(cin, newAdmin.pekerjaan);
                cout << "Masukkan Kewarganegaraan: ";
                getline(cin, newAdmin.kewarganegaraan);
                sistem.adminSignUp(newAdmin);
                cout << "Admin baru berhasil didaftarkan!\n";
            } else {
                cout << "Pilihan tidak valid!\n";
                continue;
            }
        }

        cout << "\nMenu:\n";
        cout << "1. Entri data KTP\n";
        cout << "2. Entri item barang\n";
        cout << "3. Catat pembeli\n";
        cout << "4. Jual item barang\n";
        cout << "5. Cetak daftar barang\n";
        cout << "6. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        if (pilihan == 1) {
            KTP ktp;
            cout << "Masukkan NIK: ";
            cin >> ktp.nik;
            cin.ignore();
            cout << "Masukkan Nama: ";
            getline(cin, ktp.nama);
            cout << "Masukkan Tempat Lahir: ";
            getline(cin, ktp.tempatLahir);
            cout << "Masukkan Tanggal Lahir: ";
            getline(cin, ktp.tanggalLahir);
            cout << "Masukkan Jenis Kelamin: ";
            getline(cin, ktp.jenisKelamin);
            cout << "Masukkan Alamat: ";
            getline(cin, ktp.alamat);
            cout << "Masukkan Agama: ";
            getline(cin, ktp.agama);
            cout << "Masukkan Status Perkawinan: ";
            getline(cin, ktp.statusPerkawinan);
            cout << "Masukkan Pekerjaan: ";
            getline(cin, ktp.pekerjaan);
            cout << "Masukkan Kewarganegaraan: ";
            getline(cin, ktp.kewarganegaraan);
            sistem.simpanKTP(ktp);
        }
        else if (pilihan == 2) {
            Item item;
            cout << "Masukkan Kode Item: ";
            cin >> item.kodeItem;
            cout << "Masukkan Tanggal Masuk (YYYY-MM-DD): ";
            cin >> item.tanggalMasuk;
            item.terjual = false;
            sistem.tambahItem(item);
        }
        else if (pilihan == 3) {
            Pembeli pembeli;
            cout << "Masukkan NIK Pembeli: ";
            cin >> pembeli.nik;
            cout << "Masukkan Waktu Kedatangan (HH:MM): ";
            cin >> pembeli.waktuKedatangan;
            cout << "Masukkan Kode Item yang Dibeli: ";
            cin >> pembeli.kodeItem;
            sistem.tambahPembeli(pembeli);
        }
        else if (pilihan == 4) {
            if (sistem.jualItem()) {
                cout << "Penjualan berhasil!\n";
            } else {
                cout << "Tidak ada pembeli dalam antrian atau stok habis!\n";
            }
        }
        else if (pilihan == 5) {
            sistem.cetakDaftarBarang();
        }
        else if (pilihan == 6) {
            cout << "Terima kasih telah menggunakan sistem ini!\n";
            break;
        }
        else {
            cout << "Pilihan tidak valid!\n";
        }
    }

    return 0;
}
