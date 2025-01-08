#ifndef INVENTORYSYSTEM_H
#define INVENTORYSYSTEM_H

#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <stack>
#include "KTP.h"
#include "Item.h"
#include "Pembeli.h"

using namespace std;

const int MAX_KTP = 100;
const int MAX_INVENTORY = 100;

class InventorySystem {
private:
    KTP dataKTP[MAX_KTP];
    int jumlahKTP;
    stack<Item> itemStack;
    queue<Pembeli> pembeliQueue;
    Item inventory[MAX_INVENTORY];
    int jumlahInventory;

public:
    InventorySystem() {
        jumlahKTP = 0;
        jumlahInventory = 0;
    }

    void simpanKTP(const KTP& ktp) {
        if (jumlahKTP < MAX_KTP) {
            ofstream file("data_ktp.txt", ios::app);
            if (file.is_open()) {
                file << ktp.nik << endl;
                file << ktp.nama << endl;
                file << ktp.tempatLahir << endl;
                file << ktp.tanggalLahir << endl;
                file << ktp.jenisKelamin << endl;
                file << ktp.alamat << endl;
                file << ktp.agama << endl;
                file << ktp.statusPerkawinan << endl;
                file << ktp.pekerjaan << endl;
                file << ktp.kewarganegaraan << endl;
                file << "---" << endl;
                file.close();
                dataKTP[jumlahKTP++] = ktp;
            }
        } else {
            cout << "Penyimpanan KTP penuh!" << endl;
        }
    }

    void bacaDataKTP() {
        ifstream file("data_ktp.txt");
        if (file.is_open()) {
            string line;
            while (getline(file, line) && jumlahKTP < MAX_KTP) {
                KTP ktp;
                ktp.nik = line;
                getline(file, ktp.nama);
                getline(file, ktp.tempatLahir);
                getline(file, ktp.tanggalLahir);
                getline(file, ktp.jenisKelamin);
                getline(file, ktp.alamat);
                getline(file, ktp.agama);
                getline(file, ktp.statusPerkawinan);
                getline(file, ktp.pekerjaan);
                getline(file, ktp.kewarganegaraan);
                getline(file, line);
                dataKTP[jumlahKTP++] = ktp;
            }
            file.close();
        }
    }

    bool adminSignIn(string nik) {
        for (int i = 0; i < jumlahKTP; i++) {
            if (dataKTP[i].nik == nik) {
                return true;
            }
        }
        return false;
    }

    // Fungsi untuk mendaftar admin baru
    void adminSignUp(const KTP& ktp) {
        simpanKTP(ktp);
    }

    void tambahItem(const Item& item) {
        if (jumlahInventory < MAX_INVENTORY) {
            itemStack.push(item);
            inventory[jumlahInventory++] = item;
            cout << "Item berhasil ditambahkan ke inventori!" << endl;
        } else {
            cout << "Inventori penuh!" << endl;
        }
    }

    void tambahPembeli(const Pembeli& pembeli) {
        pembeliQueue.push(pembeli);
        cout << "Pembeli berhasil ditambahkan ke antrian!" << endl;
    }

    bool jualItem() {
        if (pembeliQueue.empty() || itemStack.empty()) {
            return false;
        }

        Pembeli pembeli = pembeliQueue.front();
        pembeliQueue.pop();

        Item item = itemStack.top();
        itemStack.pop();

        for (int i = 0; i < jumlahInventory; i++) {
            if (inventory[i].kodeItem == item.kodeItem && !inventory[i].terjual) {
                inventory[i].terjual = true;
                break;
            }
        }

        cout << "Item " << item.kodeItem << " terjual kepada pembeli dengan NIK: "
             << pembeli.nik << endl;
        return true;
    }

    void cetakDaftarBarang() {
        cout << "\nDaftar Barang dalam Inventori:\n";
        cout << "Kode Item    Tanggal Masuk\n";
        cout << "--------------------------------\n";

        for (int i = 0; i < jumlahInventory; i++) {
            if (!inventory[i].terjual) {
                cout << inventory[i].kodeItem;
                for (int j = 0; j < 12 - inventory[i].kodeItem.length(); j++) {
                    cout << " ";
                }
                cout << inventory[i].tanggalMasuk << endl;
            }
        }
    }

    void cetakKTP(const KTP& ktp) {
        cout << "\nPROVINSI JAWA TIMUR\n";
        cout << "KOTA SURABAYA\n\n";
        cout << "NIK            : " << ktp.nik << endl;
        cout << "Nama           : " << ktp.nama << endl;
        cout << "Tempat Lahir   : " << ktp.tempatLahir << endl;
        cout << "Tanggal Lahir  : " << ktp.tanggalLahir << endl;
        cout << "Jenis Kelamin  : " << ktp.jenisKelamin << endl;
        cout << "Alamat         : " << ktp.alamat << endl;
        cout << "Agama          : " << ktp.agama << endl;
        cout << "Status         : " << ktp.statusPerkawinan << endl;
        cout << "Pekerjaan      : " << ktp.pekerjaan << endl;
        cout << "Kewarganegaraan: " << ktp.kewarganegaraan << endl;
    }
};

#endif
