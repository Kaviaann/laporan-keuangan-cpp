#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <thread> // Diperlukan untuk std::this_thread::sleep_for

using namespace std;

// Struktur untuk merepresentasikan transaksi
struct Transaction {
    string description;
    double amount;
};

// Fungsi untuk menampilkan menu utama
void displayMenu() {
    cout << "\n\n";
    cout << "=== Aplikasi Pemantau Keuangan ===" << endl;
    cout << "1. Tambah Transaksi" << endl;
    cout << "2. Lihat Saldo" << endl;
    cout << "3. Lihat Laporan Keuangan" << endl;
    cout << "4. Keluar" << endl;
    cout << "Pilih menu (1/2/3/4): ";
}

int main() {
    vector<Transaction> transactions;
    double saldo = 0.0;
    int choice;
    Transaction newTransaction;

    do {
        // Menambahkan jeda selama 5 detik
        std::this_thread::sleep_for(std::chrono::seconds(1));
        
        displayMenu();
        
        if (cin >> choice) {
            switch (choice) {
                case 1: // Tambah Transaksi
                    cout << "Deskripsi transaksi: ";
                    cin.ignore();
                    getline(cin, newTransaction.description);
                    cout << "Jumlah: ";
                    cin >> newTransaction.amount;
                    transactions.push_back(newTransaction);
                    saldo += newTransaction.amount;
                    break;
                case 2: // Lihat Saldo
                    cout << "\n";
                    cout << "Saldo saat ini: " << saldo << endl;
                    break;
                case 3: // Lihat Laporan Keuangan
                    cout << "\n";
                    cout << "=== Laporan Keuangan ===" << endl;
                    for (const Transaction& t : transactions) {
                        cout << t.description << ": " << t.amount << endl;
                    }
                    cout << "Saldo saat ini: " << saldo << endl;
                    cout << "\n";
                    break;
                case 4: // Keluar
                    cout << "Terima kasih telah menggunakan aplikasi ini." << endl;
                    break;
                default:
                    cout << "Pilihan tidak valid. Silakan pilih lagi." << endl;
                    break;
            }
        } else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Input tidak valid. Silakan masukkan angka." << endl;
        }
    } while (choice != 4);

    return 0;
}
