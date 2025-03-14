// Latihan Quiz
#include <iostream>
using namespace std;

struct Menu
{
    int no_menu[6] = {1, 2, 3, 4, 5, 6};
    string nama_menu[6] = {"Nasi Goreng", "Magelangan", "Bakmie Goreng", "Bakmie Godhog", "Nasi Godhog", "Mie Lethek"};
    int harga_menu[6] = {15000, 20000, 18000, 18000, 15000, 25000};
};

struct ItemPesanan
{
    int no_menu;
    string nama_menu;
    int harga_menu;
};

struct Pemesanan
{
    string nama;
    ItemPesanan menu_dipesan[10];
} pesanan;

char pilih;
int menupil, menu_pesanan = 0, total_harga = 0;

void tampilkan_menu()
{
    cout << "# Program Kasir Warung Makan Kapal Lawud #" << endl;
    cout << "\t\t  Menu\t\t\t" << endl;
    cout << "-----------------------------------------" << endl;
    cout << "| Nama Menu\t\t| Harga\t\t|" << endl;
    cout << "-----------------------------------------" << endl;
    cout << "| 1. Nasi Goreng\t| Rp 15.000,-\t|" << endl;
    cout << "| 2. Magelangan\t\t| Rp 20.000,-\t|" << endl;
    cout << "| 3. Bakmie Goreng\t| Rp 18.000,-\t|" << endl;
    cout << "| 4. Bakmie Godhog\t| Rp 18.000,-\t|" << endl;
    cout << "| 5. Nasi Godhog\t| Rp 15.000,-\t|" << endl;
    cout << "| 6. Mie Lethek\t\t| Rp 25.000,-\t|" << endl;
    cout << "-----------------------------------------" << endl;
}

void nota()
{
    cout << "----------  Nota  ----------" << endl;
    cout << "Nama         : " << pesanan.nama << endl;
    for (int j = 0; j < menu_pesanan; j++)
    {
        cout << "Pesanan ke-" << j + 1 << " : " << pesanan.menu_dipesan[j].nama_menu << endl;
        cout << "Harga        : Rp " << pesanan.menu_dipesan[j].harga_menu << endl;
        total_harga = total_harga + pesanan.menu_dipesan[j].harga_menu;
    }
    cout << "----------------------------" << endl;
    cout << "Total\t     : Rp " << total_harga << endl;
    cout << "--------Terima Kasih--------" << endl;

    // mereset data ketika nota sudah keluar
    menu_pesanan = 0;
    total_harga = 0;
}

int main()
{
    Menu list_menu;
    do
    {
        system("cls");

        tampilkan_menu();
        // cin.ignore();
        cout << "Masukkan Nama Pemesan : ";
        getline(cin, pesanan.nama);

        char lanjut;

        do
        {
            // error handling ketika salah milih menu
            do
            {
                cout << "Masukkan Nomor Menu yang dipilih : ";
                cin >> menupil;
                if (menupil > 6 || menupil < 1)
                    cout << "Pilih menu dengan benar deks" << endl;
            } while (menupil > 6 || menupil < 1);

            // memasukkan data pada struct pesanan
            for (int i = 0; i < 6; i++)
            {
                if (list_menu.no_menu[i] == menupil)
                {
                    pesanan.menu_dipesan[menu_pesanan].no_menu = list_menu.no_menu[i];
                    pesanan.menu_dipesan[menu_pesanan].nama_menu = list_menu.nama_menu[i];
                    pesanan.menu_dipesan[menu_pesanan].harga_menu = list_menu.harga_menu[i];
                }
            }
            cout << "Ingin Pesan Lagi? : ";
            cin >> lanjut;
            // untuk melanjutkan index pada menu_dipesan
            menu_pesanan++;
        } while (lanjut == 'y');

        // ketika menu yang dipesan tidak ada lagi
        system("cls");
        nota();
        cout << "Apakah anda ingin menggunakan program lagi? :";
        cin >> pilih;
        cin.ignore();
    } while (pilih == 'y');

    return 0;
}