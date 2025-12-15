#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    string ulangi;
    do {
        system("cls");
    char customerType;
    string nama, kelamin;
    int usia;
    string nisn;
    
    cout << "=== ARSport-GYM ===\n";
    // PILIH KATEGORI
    cout << "A) Siswa / Mahasiswa\n";
    cout << "B) Umum\n";
    cout << "Pilih kategori (A/B): ";
    cin >> customerType;
    cin.ignore();

    // INPUT DATA DIRI
    if (customerType == 'A' || customerType == 'a') {
        cout << "\n=== DATA PELAJAR ===\n";
        cout << "Nama           : ";
        getline(cin, nama);
        cout << "Usia           : ";
        cin >> usia;
        cin.ignore();
        cout << "Jenis Kelamin  : ";
        getline(cin, kelamin);
        cout << "NISN/NIM       : ";
        cin >> nisn;
    } 
    else if (customerType == 'B' || customerType == 'b') {
        cout << "\n=== DATA UMUM ===\n";
        cout << "Nama           : ";
        getline(cin, nama);
        cout << "Usia           : ";
        cin >> usia;
        cin.ignore();
        cout << "Jenis Kelamin  : ";
        getline(cin, kelamin);
    } 
    else {
        cout << "Kategori tidak valid!";
        system("pause");
        continue;
    }

    // HARGA DASAR
    double hargaHarian = 40000;
    double hargaBulanan = 1200000;
    double hargaTahunan = 14600000;

    // DISKON
    double diskonBulanan = 0;
    double diskonTahunan = 0;

    if (customerType == 'A' || customerType == 'a') {
        diskonBulanan = 0.20;   // 20%
        diskonTahunan = 0.25;   // 25%
    } else {
        diskonBulanan = 0.15;   // 15%
        diskonTahunan = 0.20;   // 20%
    }

    // MENU LAYANAN
    cout << "\n=== PILIH PAKET ===\n";
    cout << "1. Paket Harian (Rp 40.000)\n";
    cout << "2. Paket Bulanan (Rp  1.200.000)\n" ;
    cout << "- A. Diskon siswa / mahasiswa 20%\n";
    cout << "- B. Diskon umum 15%\n";
    cout << "3. Paket Tahunan (Rp 14.600.000)\n";
    cout << "- A. Diskon siswa / mahasiswa 25%\n";
    cout << "- B. Diskon umum 20%\n";
    cout << "4. Exit\n";

    int choice;
    cout << "Masukkan pilihan (1-4): ";
    cin >> choice;

    if (choice == 4) {
        cout << "Terima kasih!\n";
        return 0;
    }

    int jumlah;
    double subtotal = 0, total = 0, potongan = 0;

    // PERHITUNGAN SESUAI KETENTUAN
    if (choice == 1) {
        cout << "Input jumlah hari: ";
        cin >> jumlah;
        subtotal = jumlah * hargaHarian;
        total = subtotal;
    }
    else if (choice == 2) {
        cout << "Jumlah bulan: ";
        cin >> jumlah;
        subtotal = jumlah * hargaBulanan;
        potongan = subtotal * diskonBulanan;
        total = subtotal - potongan;
    }
    else if (choice == 3) {
        cout << "Jumlah tahun: ";
        cin >> jumlah;
        subtotal = jumlah * hargaTahunan;
        potongan = subtotal * diskonTahunan;
        total = subtotal - potongan;
    }
    else {
        cout << "Pilihan tidak valid!";
        system("pause");
        continue;
    }

    // Total & Diskon pembayaran
    cout << fixed << setprecision(0);  // untuk mengubah default cout yg awalnya notasi ilmiah 
    cout << "\n=== PEMBAYARAN ===\n";
    cout << "Subtotal     : Rp " << subtotal << endl;
    if (potongan > 0)
    cout << "Diskon       : Rp " << potongan << endl;
    cout << "TOTAL BAYAR  : Rp " << total << endl;
    
    // PEMBAYARAN
    double uang;
    cout << "Masukkan uang anda: Rp ";
    cin >> uang;
    double kembalian = uang - total;

    if (kembalian < -1) {
        cout << "\nUang tidak cukup! Kurang Rp " << kembalian * -1 << endl;
        return 0;
    } else {

    // STRUK PEMBAYARAN 
    cout << fixed << setprecision(0);
    cout << "\n=== STRUK PEMBAYARAN ===\n";
    cout << "Nama         : " << nama << endl;
    cout << "Usia         : " << usia << endl;
    cout << "Kelamin      : " << kelamin << endl;

    if (customerType == 'A' || customerType == 'a')
        cout << "NISN/NIM     : " << nisn << endl;

    if (choice == 1) cout << "Layanan      : Paket Harian\n";
    if (choice == 2) cout << "Layanan      : Paket Bulanan\n";
    if (choice == 3) cout << "Layanan      : Paket Tahunan\n";

    cout << "Subtotal     : Rp " << subtotal << endl;
    if (potongan > 0)
    cout << "Diskon       : Rp " << potongan << endl;
    cout << "TOTAL BAYAR  : Rp " << total << endl;
    cout << "Uang Anda    : Rp " << uang << endl;
    cout << "Kembalian    : Rp " << kembalian << endl;
    }
    cout << "\nApakah ingin mendaftar lagi? (iya/tidak): ";
    cin >> ulangi;
    } while (ulangi == "iya" || ulangi == "IYA");
    cout << "--- Terima kasih telah menggunakan ARSport-GYM ---\n";
    return 0;
}

