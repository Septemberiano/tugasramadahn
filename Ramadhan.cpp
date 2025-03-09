#include <iostream>
using namespace std;
struct tanggal
{
    int hari;
    int bulan;
    int tahun;
};
int antrian = 0;
int jumlahjamaah;
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
data pengambil[100];
void inputmakan(){
    cout<<"\tInput Takjil Masjid Sabrini\n";
    cout<<"Masukan tanggal :";cin>>takjil.tgl.hari;
    cout<<"masukan Bulan :";cin>>takjil.tgl.bulan;
    cout<<"masukan tahun :";cin>>takjil.tgl.tahun;
    cout<<"masukan menu takjil : ";cin>>takjil.namamenu;
    cout<<"jumlah takjil : "; cin>>takjil.jumlah;

}

void datajamaah(){
    string keputusanj;
   do
   { cout<<"Input data jamaah penerima takjil\n";
    cout<<"Jumlah takjil tersisa :"<<takjil.jumlah<<endl;
    cout<<"Menu takjil :"<<takjil.namamenu;
    if (takjil.jumlah >0)
    {
        cout<<"masukan Jumlah pengambil :"; cin>>antrian;
    jumlahjamaah += antrian;
    for (int i = 0; i < jumlahjamaah ; i++)
    {
        cout<<"masukan nama penerima :"; getline(cin>>ws,pengambil[i].nama);
        cout<<"masukan nim penerima :"; cin>>pengambil[i].nim;
        cout<<"masukan jurusan penerima :"; getline(cin>>ws,pengambil[i].jurusan);
        
    } takjil.jumlah- antrian;
   
    }
    else {
        
    }



     antrian = 0;
    cout<<"apakah anda akan melakukan input data kembali?";
   
   } while (keputusanj != "y");
   
   
    


}
int main() {
    string username ;
    string pass,pilihanutama;
    int pilihan,piladmin;
    bool kondisi = false; 
    while (kondisi != true)
    {
    cout<<"Login admin \n";
    cout<<"Username :"; cin>>username;
    cout<<"Password :"; cin>> pass;
    if (username == "admin" && pass == "123")
    {
        kondisi = true;
    }
     else{
        cout<<"Maaf Username atau Password yang di inputkan salah\n";
     }
    }
    do
    {  cout<<"\tSelamat datang di Program berbagi Ramadhan masjid Sabrini\n";
    cout<<"1. input takjil masjid sabrini\n";
    cout<<"2.penerimaan takjil masjid sabrini\n";
    cout<<"3.Keluar Program\n";
    cout<<"Pilihan admin :"; cin>>pilihan;
    switch (pilihan)
    {
    case 1:
        inputmakan();
        break;
    case 2 :
    cout<<"Penerima Takjil Masjid Sabrini";
    cout<<"1. Input data jamaah penerima takjil\n";
    cout<<"2. Data Jamaah Penerima Takjil\n";
    cout<<"3. Pencarian Data Penerima takjil\n";
    cout<<"4. Sortir Data Penerima takjil\n";
    cout<<"tentukan pilihan admin :"; cin>>piladmin;
    switch (piladmin)
    {
    case 1:
        datajamaah();
        break;
    default:
        break;
    }
    case 3 :
    break;
    default:
        break;
    }
    cout<<"balik ke menu utama :"; cin>>pilihanutama;
        
    } while (pilihanutama == "y");
    
  
        
}