#include <iostream>
using namespace std;
struct tanggal
{
    int hari;
    int bulan;
    int tahun;
};

struct makanan
{
    int jumlah;
    string namamenu;
    tanggal tgl;
};
makanan takjil;
struct data
{
    int nim;
    string nama;
    string jurusan;
};
data pengambil;
void inputmakan(){
    cout<<"\tInput Takjil Masjid Sabrini\n";
    cout<<"Masukan tanggal :";cin>>takjil.tgl.hari;
    cout<<"masukan Bulan :";cin>>takjil.tgl.bulan;
    cout<<"masukan tahun :";cin>>takjil.tgl.tahun;

}
int main() {
    
    return 0;
}