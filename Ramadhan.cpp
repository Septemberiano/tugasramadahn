#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <fstream>
using namespace std;
bool sorting;
int antrian[100], jumlahjamaah = 0, k = 0, viacari, metodecari, sortingmenurut, metodesort, urutan;
bool valid = false;

struct tanggal {
    int hari;
    int bulan;
    int tahun;
};

struct makanan {
    int jumlah;
    string namamenu;
    tanggal tgl;
} takjil;

struct data {
    int noantrian;
    int nim;
    string nama;
    string jurusan;
} pengambil[100], mentah[100];

int totalpenerima(int k){
    if (k < 0){
        return 0;
    } else {
        return antrian[k] + totalpenerima (k-1);
    }
}

void inputmakan(string namafile, string datakecilmentah) {
    cout << "\n\tSelamat datang di Program Berbagi Ramadhan Masjid Sabrini\n";
    cout<<"Silahkan pilih input data takjil!\n";
    cout<<"Note : Masukkan dalam bentuk angka\n";
    do {
        cout << "Masukan tanggal : ";
        cin >> takjil.tgl.hari;
        if (takjil.tgl.hari < 0 || takjil.tgl.hari > 31) {
            cout<<"Tanggal yang Anda masukkan tidak valid!\n";
            cout<<"Silahkan masukkan ulang tanggal!\n";
            valid = false;
        } else {
            valid = true;
        }
    } while (!valid);
    do{
        cout << "Masukan bulan : ";
        cin >> takjil.tgl.bulan;
        if (takjil.tgl.bulan < 0 || takjil.tgl.bulan > 12){
            cout<<"Bulan yang Anda masukkan tidak valid!\n";
            cout<<"Silahkan masukkan ulang bulan!\n";
            valid = false;
        } else {
            valid = true;
        }
    } while (!valid);
    do {
        cout << "Masukan tahun : ";
        cin >> takjil.tgl.tahun;
        if (takjil.tgl.tahun < 0) {
            cout<<"Tahun yang Anda masukkan tidak valid!\n";
            cout<<"Silahkan masukkan ulang tahun!\n";
        } else {
            valid = true;
        }
    } while (!valid);
   
    cout << "Masukan menu takjil : ";
    getline(cin>>ws, takjil.namamenu);
    do {
        cout << "Jumlah takjil : ";
        cin >> takjil.jumlah;
        if (takjil.jumlah < 0) {
            cout<<"Jumlah takjil yang Anda masukkan tidak valid!\n";
            cout<<"Silahkan masukkan ulang jumlah takjil!\n";
        } else {
            valid = true;
        }
    } while (!valid);
    ofstream datakecil (datakecilmentah);
    datakecil<<takjil.tgl.hari<<","<<takjil.tgl.bulan<<","<<takjil.tgl.tahun<<","<<takjil.namamenu<<","<<takjil.jumlah<<","<<jumlahjamaah<<","<<k<<"\n";
    datakecil.close();
    cout<<"[DATA TERSIMPAN]\n";
}

void inputjamaah(string namafile, string filementah, string datakecilmentah) {
    char inputlagi;
    do {
        cout << "\n[INPUT DATA JAMAAH PENERIMA TAKJIL]\n";
        cout << "Menu takjil : " << takjil.namamenu<<endl;
        cout << "Jumlah takjil tersisa : " << takjil.jumlah << endl;
        if (takjil.jumlah > 0) {
            do {
                cout << "Masukan jumlah pengambil : "; cin >> antrian[k];
                if (takjil.jumlah - antrian[k] < 0) {
                    cout<<"Takjil yang tersisa tidak cukup, silahkan input jumlah yang masih tersedia!\n";
                    valid = false;
                } else {
                    valid = true;
                    for (int i = jumlahjamaah; i < jumlahjamaah + antrian[k]; i++){
                        pengambil[i].noantrian = i+1;
                        mentah[i].noantrian = i+1;
                        cout<<"\nPenerima #"<<i+1<<endl;
                        cout << "Masukan Nama Penerima : ";
                        getline(cin >> ws, pengambil[i].nama);
                        mentah[i].nama = pengambil[i].nama;
                        cout << "Masukan NIM Penerima : ";
                        cin >> pengambil[i].nim;
                        mentah[i].nim = pengambil[i].nim;
                        cout << "Masukan Jurusan Penerima : ";
                        getline(cin >> ws, pengambil[i].jurusan);
                        mentah[i].jurusan = pengambil[i].jurusan;
                        ofstream databaru (namafile, ios::app);
                        databaru<<"| "<<left<<setfill(' ')<<setw(3)<<i+1<<"| "<<setw(11)<<pengambil[i].noantrian<<"| "<<setw(10)<<pengambil[i].nim<<"| "<<setw(25)<<pengambil[i].nama<<"| "<<setw(21)<<pengambil[i].jurusan<<"|"<<endl;
                        databaru.close();
                        ofstream datamentah (filementah);
                        datamentah<<pengambil[i].noantrian<<","<<pengambil[i].nim<<","<<pengambil[i].nama<<","<<pengambil[i].jurusan<<"\n";
                        datamentah.close();
                    }
                    jumlahjamaah = totalpenerima(k);
                    takjil.jumlah -= antrian[k];
                    k++;
                }
                ofstream datakecil (datakecilmentah);
                datakecil<<takjil.tgl.hari<<","<<takjil.tgl.bulan<<","<<takjil.tgl.tahun<<","<<takjil.namamenu<<","<<takjil.jumlah<<","<<jumlahjamaah<<","<<k<<"\n";
                datakecil.close();
            } while (!valid);
            cout<<"[DATA TERSIMPAN!]\n";
            cout << "\nApakah Anda akan melakukan input data lagi? (y/n) : "; cin>>inputlagi;
        } else {
            inputlagi = 'n';
            cout<<"Stok takjil yang tersisa telah habis.\n";
            system("pause");
        }
    } while (inputlagi == 'y' || inputlagi == 'Y');
}

void tampildatapengambil(){
    cout<<"+"<<setfill('-')<<setw(5)<<"+"<<setw(13)<<"+"<<setw(12)<<"+"<<setw(27)<<"+"<<setw(23)<<"+"<<endl;
    cout<<"|"<<left<<setfill(' ')<<setw(4)<<" No"<<"|"<<setw(12)<<" No Antrian"<<"|"<<setw(11)<<" NIM"<<"|"<<setw(26)<<" Nama Jamaah"<<"|"<<setw(22)<<" Jurusan"<<"|"<<endl;
    cout<<right<<"+"<<setfill('-')<<setw(5)<<"+"<<setw(13)<<"+"<<setw(12)<<"+"<<setw(27)<<"+"<<setw(23)<<"+"<<endl;
    for(int i = 0; i < jumlahjamaah; i++){
        cout<<"| "<<left<<setfill(' ')<<setw(3)<<i+1<<"| "<<setw(11)<<pengambil[i].noantrian<<"| "<<setw(10)<<pengambil[i].nim<<"| "<<setw(25)<<pengambil[i].nama<<"| "<<setw(21)<<pengambil[i].jurusan<<"|"<<endl;  
    }
    cout<<right<<"+"<<setfill('-')<<setw(5)<<"+"<<setw(13)<<"+"<<setw(12)<<"+"<<setw(27)<<"+"<<setw(23)<<"+"<<endl;
}

void datajamaah() {
    cout<<"[DATA JAMAAH PENERIMA TAKJIL]\n";
    cout<<"Data Jamaah Penerima Takjil pada "<<takjil.tgl.hari<<"/"<<takjil.tgl.bulan<<"/"<<takjil.tgl.tahun<<endl;
    cout << "Menu takjil : " << takjil.namamenu<<endl;
    cout << "Jumlah takjil tersisa : " << takjil.jumlah << "\n\n";
    if (jumlahjamaah == 0) {
        cout<<"Data yang masuk masih kosong.\n";
        cout<<"Silahkan input data terlebih dahulu.\n";
        system("pause");
    } else {
        cout<<"+"<<setfill('-')<<setw(5)<<"+"<<setw(13)<<"+"<<setw(12)<<"+"<<setw(27)<<"+"<<setw(23)<<"+"<<endl;
        cout<<"|"<<left<<setfill(' ')<<setw(4)<<" No"<<"|"<<setw(12)<<" No Antrian"<<"|"<<setw(11)<<" NIM"<<"|"<<setw(26)<<" Nama Jamaah"<<"|"<<setw(22)<<" Jurusan"<<"|"<<endl;
        cout<<right<<"+"<<setfill('-')<<setw(5)<<"+"<<setw(13)<<"+"<<setw(12)<<"+"<<setw(27)<<"+"<<setw(23)<<"+"<<endl;
        for(int i = 0; i < jumlahjamaah; i++){
            cout<<"| "<<left<<setfill(' ')<<setw(3)<<i+1<<"| "<<setw(11)<<mentah[i].noantrian<<"| "<<setw(10)<<mentah[i].nim<<"| "<<setw(25)<<mentah[i].nama<<"| "<<setw(21)<<mentah[i].jurusan<<"|"<<endl;  
        }
        cout<<right<<"+"<<setfill('-')<<setw(5)<<"+"<<setw(13)<<"+"<<setw(12)<<"+"<<setw(27)<<"+"<<setw(23)<<"+"<<endl;
    }

}
bool ditemukan;
void metodenourut(){
    ditemukan = false;
    int nourutjam,b,n,h;
    cout<<"[PENCARIAN DATA PENERIMA TAKJIL Terurut]\n";
    cout<<"Pilih metode pencarian :\n";
    cout<<"1. Metode Sequential Sentinel\n";
    cout<<"2. Metode Sequential Non-Sentinel\n";
    cout<<"3. Binary\n";
    cout<<"Pilih metode : "; cin>>metodecari;
    
    switch (metodecari)
    {
    case 1:
        cout<<"masukan nomor antrian\n";cin>>nourutjam;
        while (!ditemukan && mentah[b].noantrian<nourutjam)
            b++;
            if (nourutjam>jumlahjamaah)
            {
                   cout<<"data jamaah tidak ditemukan\n";
            }
            else{
                if (mentah[b].noantrian == nourutjam)
                {
                    cout<<"data ditemukan\n";
               cout<<"Nama Jamaah : "<<mentah[b].nama<<endl;
              cout<<"Jurusan Jamaah : "<< mentah[b].jurusan<<endl;
                }
                else cout<<"data jamaah tidak ditemukan\n";
            }
        break;
        case 2:
         while ((b<jumlahjamaah) && (!ditemukan) && (nourutjam>=mentah[b].noantrian))
        {
            if (mentah[b].noantrian == nourutjam)
            {
                ditemukan = true;
            }
            else{
                b++;
            }
            
        }
        if (ditemukan)
        {
            cout<<"data ditemukan\n";
               cout<<"Nama Jamaah : "<<mentah[b].nama<<endl;
            cout<<"Jurusan Jamaah : "<< mentah[b].jurusan<<endl;
        }
        else{
             cout<<"tidak ada data yang dicari";
        }
        break;
        case 3 :
        b=0;
        n=jumlahjamaah;
        while ((!ditemukan) && (b<= n))
        {
            h= (b+n) /2;
            if ( nourutjam == mentah[h].noantrian)
            {
                ditemukan = true;
            }
            else{
                if (nourutjam < mentah[h].noantrian)
                {
                    n=h-1;
                }
                else{
                    b=h+1;
                }
                
            }
        }
        if (ditemukan)
        {
            cout<<"data ditemukan\n";
               cout<<"Nama Jamaah : "<<mentah[b].nama<<endl;
            cout<<"Jurusan Jamaah : "<< mentah[b].jurusan<<endl;
        }
        else{
             cout<<"tidak ada data yang dicari";
        }

        break;
    default:
        break;
    }
}
void metodecarinimurut(){
    ditemukan = false;
    int j=0,t,l;
 cout<<"[PENCARIAN DATA PENERIMA TAKJIL Terurut]\n";
    cout<<"Pilih metode pencarian :\n";
    cout<<"1. Metode Sequential Sentinel\n";
    cout<<"2. Metode Sequential Non-Sentinel\n";
    cout<<"3.Binary\n";
    cout<<"Pilih metode : "; cin>>metodecari;
    switch (metodecari)
    {
    case 1:
     cout<<"Nim Jamaah : "; cin>>t;
     mentah[jumlahjamaah-1].nim == t;
        while (!ditemukan && mentah[t].nim <t)
           j++;
           if (t>jumlahjamaah)
           {
             cout<<"data jamaah tidak ditemukan\n";
           }
           else
           if (mentah[j].nim == t )
           {
            cout<<"data ditemukan\n";
               cout<<"Nama Jamaah : "<<mentah[j].nama<<endl;
            cout<<"Jurusan Jamaah : "<< mentah[j].jurusan<<endl;
           }
           else cout<<"tidak ada data yang dicari";
        break;
        case 2 :
        while ((j<jumlahjamaah) && (!ditemukan) && (t>=mentah[j].nim))
        {
            if (mentah[j].nim == t)
            {
                ditemukan = true;
            }
            else{
                j++;
            }
            
        }
        if (ditemukan)
        {
            cout<<"data ditemukan\n";
               cout<<"Nama Jamaah : "<<mentah[j].nama<<endl;
            cout<<"Jurusan Jamaah : "<< mentah[j].jurusan<<endl;
        }
        else{
             cout<<"tidak ada data yang dicari";
        }
        break;
    case 3 :
        j=0;
        l=jumlahjamaah;
        int v;
        while ((!ditemukan) && (j<= l))
        {
            v= (j+l) /2;
            if ( t == mentah[v].nim)
            {
                ditemukan = true;
            }
            else{
                if (t < mentah[v].nim)
                {
                    l=v-1;
                }
                else{
                    j=v+1;
                }
                
            }
        }
        if (ditemukan)
        {
            cout<<"data ditemukan\n";
               cout<<"Nama Jamaah : "<<mentah[j].nama<<endl;
            cout<<"Jurusan Jamaah : "<< mentah[j].jurusan<<endl;
        }
        else{
             cout<<"tidak ada data yang dicari";
        }

    break;
    default:
        break;
    }
}

void metodecarinimtidakurut(){
    bool found ;
    int i,y;
    cout<<"[PENCARIAN DATA PENERIMA TAKJIL]\n";
    cout<<"Pilih metode pencarian :\n";
    cout<<"1. Metode Sequential Sentinel\n";
    cout<<"2. Metode Sequential Non-Sentinel\n";
    
    cout<<"Pilih metode : "; cin>>metodecari;
    switch (metodecari) {
        case 1:
       cout<<"Nim Jamaah : "; cin>>y;
       pengambil[jumlahjamaah-1].nim == y;
        found = false;
        i=0;
        while (!found)
        {
            if (pengambil[i].nim == y)
            { found = true;
                
            }
            else{
                i=i++;
            }
           
        }
         if(i == jumlahjamaah) {cout<<"tidak ada jamaah dengan nim "<< y << "dalam data masjid "<<endl;}
            else{
            cout<<"data ditemukan \n";
            cout<<"Nama Jamaah : "<<pengambil[i].nama<<endl;
            cout<<"Jurusan Jamaah : "<< pengambil[i].jurusan<<endl;
            }
        
        break;

        case 2:
         found = false;
         i=0;
         while ( (i < jumlahjamaah) && (!found) )
         {
            if (pengambil[i].nim == y)
            {
                found = true;
            }
            else {
                i = i+1;
            }
         }
          if(!found) {cout<<"tidak ada jamaah dengan nim "<< y << "dalam data masjid "<<endl;}
            else{
            cout<<"data ditemukan \n";
            cout<<"Nama Jamaah : "<<pengambil[i].nama;
            cout<<"Jurusan Jamaah : "<< pengambil[i].jurusan;
            }
        break;


        default:
        break;
    }
}

void searchingjamaah(){
    int kondisi2;
    cout<<"[PENCARIAN DATA PENERIMA TAKJIL]\n";
    cout<<"Pilih Via Pencarian :\n";
    cout<<"1. Cari melalui Nomor Antrian penerima takjil\n";
    cout<<"2. Cari melalui NIM penerima takjil\n";
    cout<<"Pilihan Admin : "; cin>>viacari;
    switch(viacari){
        case 1:
        metodenourut();
        break;

        case 2:
        cout<<"pilih metode pencarian :\n";
        cout<<"1.Data terurutkan\n";
        cout<<"2. Data tidak Terurut";
       if (kondisi2 == 1 || kondisi2 <=2)
       {
          if (kondisi2 == 1)
        {
            metodecarinimurut();
        }
        else if (kondisi2 == 2)
        {
            metodecarinimtidakurut();
        }
        else{
            cout<<"Pilih kembali metode dengan benar";
        }
       }
      
        
        
        break;

        case 3:
        break;

        default:
        break;
    }
}

void antrianbubbleasc(){
    for (int i = 0; i < jumlahjamaah-1; i++){
        for (int j = 0; j < jumlahjamaah-i-1; j++){
            if (pengambil[j].noantrian > pengambil[j+1].noantrian){
                swap(pengambil[j+1].noantrian, pengambil[j].noantrian);
                swap(pengambil[j+1].nim, pengambil[j].nim);
                swap(pengambil[j+1].nama, pengambil[j].nama);
            }
        }
    }
}

void antrianbubbledesc(){
    for (int i = 0; i < jumlahjamaah-1; i++){
        for (int j = 0; j < jumlahjamaah-i-1; j++){
            if (pengambil[j].noantrian < pengambil[j+1].noantrian){
                swap(pengambil[j+1].noantrian, pengambil[j].noantrian);
                swap(pengambil[j+1].nim, pengambil[j].nim);
                swap(pengambil[j+1].nama, pengambil[j].nama);
            }
        }
    }
}

void antrianselectionasc(){
    for (int i = 0; i < jumlahjamaah-1; i++){
        int g = i;
        for (int j = i + 1; j < jumlahjamaah; j++){
            if (pengambil[g].noantrian > pengambil[j].noantrian){
                g = j;
            }
        }
        swap(pengambil[i].noantrian, pengambil[g].noantrian);
        swap(pengambil[i].nim, pengambil[g].nim);
        swap(pengambil[i].nama, pengambil[g].nama);
    }
}

void antrianselectiondesc(){
    for (int i = 0; i < jumlahjamaah-1; i++){
        int g = i;
        for (int j = i + 1; j < jumlahjamaah; j++){
            if (pengambil[g].noantrian < pengambil[j].noantrian){
                g = j;
            }
        }
        swap(pengambil[i].noantrian, pengambil[g].noantrian);
        swap(pengambil[i].nim, pengambil[g].nim);
        swap(pengambil[i].nama, pengambil[g].nama);
    }
}

void antrianinsertionasc(){
    for (int i = 0; i < jumlahjamaah; i++){
        int tempantrian = pengambil[i].noantrian;
        int tempnim = pengambil[i].nim;
        string tempnama = pengambil[i].nama;
        int j = i - 1;
        while (tempantrian < pengambil[j].noantrian && j >= 0){
            pengambil[j+1].noantrian = pengambil[j].noantrian;
            pengambil[j+1].nim = pengambil[j].nim;
            pengambil[j+1].nama = pengambil[j].nama;
            j--;
        }
        pengambil[j+1].noantrian= tempantrian;
        pengambil[j+1].nim= tempnim;
        pengambil[j+1].nama = tempnama;
    }
}

void antrianinsertiondesc(){
    for (int i = 0; i < jumlahjamaah; i++){
        int tempantrian = pengambil[i].noantrian;
        int tempnim = pengambil[i].nim;
        string tempnama = pengambil[i].nama;
        int j = i - 1;
        while (tempantrian > pengambil[j].noantrian && j >= 0){
            pengambil[j+1].noantrian = pengambil[j].noantrian;
            pengambil[j+1].nim = pengambil[j].nim;
            pengambil[j+1].nama = pengambil[j].nama;
            j--;
        }
        pengambil[j+1].noantrian= tempantrian;
        pengambil[j+1].nim= tempnim;
        pengambil[j+1].nama = tempnama;
    }
}

void antrianshellasc(){
    for (int i = jumlahjamaah / 2; i > 0; i = i / 2) {
        for (int j = i; j < jumlahjamaah; j++) {
            for (int g = j - i; g >= 0; g = g - i) {
                if (pengambil[g + i].noantrian < pengambil[g].noantrian) {
                    swap(pengambil[g].noantrian, pengambil[g+1].noantrian);
                    swap(pengambil[g].nim, pengambil[g+1].nim);
                    swap(pengambil[g].nama, pengambil[g+1].nama);
                }
            }
         }
     }  
}

void antrianshelldesc(){
    for (int i = jumlahjamaah / 2; i > 0; i = i / 2) {
        for (int j = i; j < jumlahjamaah; j++) {
            for (int g = j - i; g >= 0; g = g - i) {
                if (pengambil[g + i].noantrian > pengambil[g].noantrian) {
                    swap(pengambil[g].noantrian, pengambil[g+1].noantrian);
                    swap(pengambil[g].nim, pengambil[g+1].nim);
                    swap(pengambil[g].nama, pengambil[g+1].nama);
                }
            }
         }
     }  
}

int partitionasc(int awal, int akhir) {
    int i, pivot=pengambil[akhir].noantrian, ip=awal;
    for(i=awal; i<akhir; i++) {
        if(pengambil[i].noantrian <= pivot) {
            swap(pengambil[i].noantrian, pengambil[ip].noantrian);
            swap(pengambil[i].nim, pengambil[ip].nim);
            swap(pengambil[i].nama, pengambil[ip].nama);
            ip++;
        }
    }
    swap(pengambil[akhir].noantrian, pengambil[ip].noantrian);
    swap(pengambil[akhir].nim, pengambil[ip].nim);
    swap(pengambil[akhir].nama, pengambil[ip].nama);
    return ip;
}

int partitiondesc(int awal, int akhir) {
    int i, pivot=pengambil[akhir].noantrian, ip=awal;
    for(i=awal; i<akhir; i++) {
        if(pengambil[i].noantrian >= pivot) {
            swap(pengambil[i].noantrian, pengambil[ip].noantrian);
            swap(pengambil[i].nim, pengambil[ip].nim);
            swap(pengambil[i].nama, pengambil[ip].nama);
            ip++;
        }
    }
    swap(pengambil[akhir].noantrian, pengambil[ip].noantrian);
    swap(pengambil[akhir].nim, pengambil[ip].nim);
    swap(pengambil[akhir].nama, pengambil[ip].nama);
    return ip;
}

void antrianquickasc(int awal, int akhir) {
    if(awal < akhir){
        int ip=partitionasc(awal,akhir);
        antrianquickasc(awal,ip-1);
        antrianquickasc(ip+1,akhir); 
    }
}

void antrianquickdesc(int awal, int akhir) {
    if(awal < akhir){
        int ip=partitiondesc(awal,akhir);
        antrianquickasc(awal,ip-1);
        antrianquickasc(ip+1,akhir);
    }
}

void nimbubbleasc(){
    for (int i = 0; i < jumlahjamaah-1; i++){
        for (int j = 0; j < jumlahjamaah-i-1; j++){
            if (pengambil[j].nim > pengambil[j+1].nim){
                swap(pengambil[j+1].noantrian, pengambil[j].noantrian);
                swap(pengambil[j+1].nim, pengambil[j].nim);
                swap(pengambil[j+1].nama, pengambil[j].nama);
            }
        }
    }
}

void nimbubbledesc(){
    for (int i = 0; i < jumlahjamaah-1; i++){
        for (int j = 0; j < jumlahjamaah-i-1; j++){
            if (pengambil[j].nim < pengambil[j+1].nim){
                swap(pengambil[j+1].noantrian, pengambil[j].noantrian);
                swap(pengambil[j+1].nim, pengambil[j].nim);
                swap(pengambil[j+1].nama, pengambil[j].nama);
            }
        }
    }
}

void nimselectionasc(){
    for (int i = 0; i < jumlahjamaah-1; i++){
        int g = i;
        for (int j = i + 1; j < jumlahjamaah; j++){
            if (pengambil[g].nim > pengambil[j].nim){
                g = j;
            }
        }
        swap(pengambil[i].noantrian, pengambil[g].noantrian);
        swap(pengambil[i].nim, pengambil[g].nim);
        swap(pengambil[i].nama, pengambil[g].nama);
    } 
}

void nimselectiondesc(){
    for (int i = 0; i < jumlahjamaah-1; i++){
        int g = i;
        for (int j = i + 1; j < jumlahjamaah; j++){
            if (pengambil[g].nim < pengambil[j].nim){
                g = j;
            }
        }
        swap(pengambil[i].noantrian, pengambil[g].noantrian);
        swap(pengambil[i].nim, pengambil[g].nim);
        swap(pengambil[i].nama, pengambil[g].nama);
    }
}

void niminsertionasc(){
    for (int i = 0; i < jumlahjamaah; i++){
        int tempantrian = pengambil[i].noantrian;
        int tempnim = pengambil[i].nim;
        string tempnama = pengambil[i].nama;
        int j = i - 1;
        while (tempnim < pengambil[j].nim && j >= 0){
            pengambil[j+1].noantrian = pengambil[j].noantrian;
            pengambil[j+1].nim = pengambil[j].nim;
            pengambil[j+1].nama = pengambil[j].nama;
            j--;
        }
        pengambil[j+1].noantrian= tempantrian;
        pengambil[j+1].nim= tempnim;
        pengambil[j+1].nama = tempnama;
    }
}

void niminsertiondesc(){
    for (int i = 0; i < jumlahjamaah; i++){
        int tempantrian = pengambil[i].noantrian;
        int tempnim = pengambil[i].nim;
        string tempnama = pengambil[i].nama;
        int j = i - 1;
        while (tempnim > pengambil[j].nim && j >= 0){
            pengambil[j+1].noantrian = pengambil[j].noantrian;
            pengambil[j+1].nim = pengambil[j].nim;
            pengambil[j+1].nama = pengambil[j].nama;
            j--;
        }
        pengambil[j+1].noantrian= tempantrian;
        pengambil[j+1].nim= tempnim;
        pengambil[j+1].nama = tempnama;
    }
}

void nimshellasc(){
    for (int i = jumlahjamaah / 2; i > 0; i = i / 2) {
        for (int j = i; j < jumlahjamaah; j++) {
            for (int g = j - i; g >= 0; g = g - i) {
                if (pengambil[g + i].nim < pengambil[g].nim) {
                    swap(pengambil[g].noantrian, pengambil[g+1].noantrian);
                    swap(pengambil[g].nim, pengambil[g+1].nim);
                    swap(pengambil[g].nama, pengambil[g+1].nama);
                }
            }
         }
     }  
}

void nimshelldesc(){
    for (int i = jumlahjamaah / 2; i > 0; i = i / 2) {
        for (int j = i; j < jumlahjamaah; j++) {
            for (int g = j - i; g >= 0; g = g - i) {
                if (pengambil[g + i].nim > pengambil[g].nim) {
                    swap(pengambil[g].noantrian, pengambil[g+1].noantrian);
                    swap(pengambil[g].nim, pengambil[g+1].nim);
                    swap(pengambil[g].nama, pengambil[g+1].nama);
                }
            }
         }
     }  
}

int nimpartitionasc(int awal, int akhir) {
    int i, pivot=pengambil[akhir].nim, ip=awal;
    for(i=awal; i<akhir; i++) {
        if(pengambil[i].nim <= pivot) {
            swap(pengambil[i].noantrian, pengambil[ip].noantrian);
            swap(pengambil[i].nim, pengambil[ip].nim);
            swap(pengambil[i].nama, pengambil[ip].nama);
            ip++;
        }
    }
    swap(pengambil[akhir].noantrian, pengambil[ip].noantrian);
    swap(pengambil[akhir].nim, pengambil[ip].nim);
    swap(pengambil[akhir].nama, pengambil[ip].nama);
    return ip;
}

int nimpartitiondesc(int awal, int akhir) {
    int i, pivot=pengambil[akhir].nim, ip=awal;
    for(i=awal; i<akhir; i++) {
        if(pengambil[i].nim >= pivot) {
            swap(pengambil[i].noantrian, pengambil[ip].noantrian);
            swap(pengambil[i].nim, pengambil[ip].nim);
            swap(pengambil[i].nama, pengambil[ip].nama);
            ip++;
        }
    }
    swap(pengambil[akhir].noantrian, pengambil[ip].noantrian);
    swap(pengambil[akhir].nim, pengambil[ip].nim);
    swap(pengambil[akhir].nama, pengambil[ip].nama);
    return ip;
}

void nimquickasc(int awal, int akhir) {
    if(awal < akhir){
        int ip=nimpartitionasc(awal,akhir);
        nimquickasc(awal,ip-1);
        nimquickasc(ip+1,akhir); 
    }
}

void nimquickdesc(int awal, int akhir) {
    if(awal < akhir){
        int ip=nimpartitiondesc(awal,akhir);
        nimquickdesc(awal,ip-1);
        nimquickdesc(ip+1,akhir);
    }
}

void sortingjamaah(string namafile){
    cout<<"[SORTIR DATA PENERIMA TAKJIL]\n";
    cout<<"Pilihan menu sorting data penerima :\n";
    cout<<"1. Sorting menurut Nomor Antrian penerima\n";
    cout<<"2. Sorting menurut NIM penerima\n";
    cout<<"Pilihan sorting : "; cin>>sortingmenurut;
    cout<<"[SORTIR DATA PENERIMA TAKJIL]\n";
    switch (sortingmenurut) {
        case 1:
        cout<<"Pilihan metode sorting :\n";
        cout<<"1. Bubble Sort\n";
        cout<<"2. Straight Selection Sort\n";
        cout<<"3. Straight Insertion Sort\n";
        cout<<"4. Shell Sort\n";
        cout<<"5. Quick Sort\n";
        cout<<"Pilih metode : "; cin>>metodesort;
        cout<<"[SORTIR DATA PENERIMA TAKJIL]\n";
        switch(metodesort){
            case 1:
            cout<<"Urutkan berdasarkan :\n";
            cout<<"1. Terkecil ke terbesar (Ascending)\n";
            cout<<"2. Terbesar ke terkecil (Descending)\n";
            cout<<"Pilih urutan : "; cin>>urutan;
            switch (urutan){
                case 1:
                antrianbubbleasc();
                break;
                
                case 2:
                antrianbubbledesc();
                break;
                
                default:
                break;
            }
            break;
            
            case 2:
            cout<<"Urutkan berdasarkan :\n";
            cout<<"1. Terkecil ke terbesar (Ascending)\n";
            cout<<"2. Terbesar ke terkecil (Descending)\n";
            cout<<"Pilih urutan : "; cin>>urutan;
            switch (urutan){
                case 1:
                antrianselectionasc();
                break;
                
                case 2:
                antrianselectiondesc();
                break;
                
                default:
                break;
            }
            break;
            
            case 3:
            cout<<"Urutkan berdasarkan :\n";
            cout<<"1. Terkecil ke terbesar (Ascending)\n";
            cout<<"2. Terbesar ke terkecil (Descending)\n";
            cout<<"Pilih urutan : "; cin>>urutan;
            switch (urutan){
                case 1:
                antrianinsertionasc();
                break;
                
                case 2:
                antrianinsertiondesc();
                break;
                
                default:
                break;
            }
            break;
            
            case 4:
            cout<<"Urutkan berdasarkan :\n";
            cout<<"1. Terkecil ke terbesar (Ascending)\n";
            cout<<"2. Terbesar ke terkecil (Descending)\n";
            cout<<"Pilih urutan : "; cin>>urutan;
            switch (urutan){
                case 1:
                antrianshellasc();
                break;
                
                case 2:
                antrianshelldesc();
                break;
                
                default:
                break;
            }
            break;
            
            case 5:
            cout<<"Urutkan berdasarkan :\n";
            cout<<"1. Terkecil ke terbesar (Ascending)\n";
            cout<<"2. Terbesar ke terkecil (Descending)\n";
            cout<<"Pilih urutan : "; cin>>urutan;
            switch (urutan){
                case 1:
                antrianquickasc(0, jumlahjamaah-1);
                break;
                
                case 2:
                antrianquickdesc(0, jumlahjamaah-1);
                break;

                default:
                break;
            }
            break;
            
            default:
            break;
        }
        break;
        
        case 2:
        cout<<"Pilihan metode sorting :\n";
        cout<<"1. Bubble Sort\n";
        cout<<"2. Straight Selection Sort\n";
        cout<<"3. Straight Insertion Sort\n";
        cout<<"4. Shell Sort\n";
        cout<<"5. Quick Sort\n";
        cout<<"Pilih metode : "; cin>>metodesort;
        cout<<"[SORTIR DATA PENERIMA TAKJIL]\n";
        switch(metodesort){
            case 1:
            cout<<"Urutkan berdasarkan :\n";
            cout<<"1. Terkecil ke terbesar (Ascending)\n";
            cout<<"2. Terbesar ke terkecil (Descending)\n";
            cout<<"Pilih urutan : "; cin>>urutan;
            switch (urutan){
                case 1:
                nimbubbleasc();
                break;
                
                case 2:
                nimbubbledesc();
                break;
                
                default:
                break;
            }
            break;
            
            case 2:
            cout<<"Urutkan berdasarkan :\n";
            cout<<"1. Terkecil ke terbesar (Ascending)\n";
            cout<<"2. Terbesar ke terkecil (Descending)\n";
            cout<<"Pilih urutan : "; cin>>urutan;
            switch (urutan){
                case 1:
                nimselectionasc();
                break;
                
                case 2:
                nimselectiondesc();
                break;
                
                default:
                break;
            }
            break;
            
            case 3:
            cout<<"Urutkan berdasarkan :\n";
            cout<<"1. Terkecil ke terbesar (Ascending)\n";
            cout<<"2. Terbesar ke terkecil (Descending)\n";
            cout<<"Pilih urutan : "; cin>>urutan;
            switch (urutan){
                case 1:
                niminsertionasc();
                break;
                
                case 2:
                niminsertiondesc();
                break;
                
                default:
                break;
            }
            break;
            
            case 4:
            cout<<"Urutkan berdasarkan :\n";
            cout<<"1. Terkecil ke terbesar (Ascending)\n";
            cout<<"2. Terbesar ke terkecil (Descending)\n";
            cout<<"Pilih urutan : "; cin>>urutan;
            switch (urutan){
                case 1:
                nimshellasc();
                break;
                
                case 2:
                nimshelldesc();
                break;
                
                default:
                break;
            }
            break;
            
            case 5:
            cout<<"Urutkan berdasarkan :\n";
            cout<<"1. Terkecil ke terbesar (Ascending)\n";
            cout<<"2. Terbesar ke terkecil (Descending)\n";
            cout<<"Pilih urutan : "; cin>>urutan;
            switch (urutan){
                case 1:
                nimquickasc(0, jumlahjamaah-1);
                break;

                case 2:
                nimquickdesc(0, jumlahjamaah-1);
                break;

                default:
                break;
            }
            break;

            default:
            break;
        }
        break;

        default:
        break;
    }
    tampildatapengambil();
}

void menucreatedata(string namafile, string filementah, string datakecilmentah){
    int piladmin;
    jumlahjamaah = 0, k = 0;
    inputmakan(namafile, datakecilmentah);
    do {
        ofstream databaru (namafile);
        cout<<"\n[PROGRAM BERBAGI RAMADHAN MASJID SABRINI]\n";
        cout << "Takjil Masjid Sabrini pada tanggal "<< takjil.tgl.hari<<"/"<<takjil.tgl.bulan<<"/"<<takjil.tgl.tahun<<endl;
        cout << "Penerima Takjil Masjid Sabrini\n";
        cout << "1. Input Data Jamaah Penerima Takjil\n";
        cout << "2. Data Jamaah Penerima Takjil\n";
        cout << "3. Pencarian Data Penerima Takjil\n";
        cout << "4. Sortir Data Penerima Takjil\n";
        cout << "0. Keluar\n";
        cout << "Pilihan admin : ";
        cin >> piladmin;
        switch (piladmin) {
            case 1:
            inputjamaah(namafile, filementah, datakecilmentah);
            databaru.close();
            break;
                        
            case 2:
            datajamaah();
            system("pause");
            databaru.close();
            break;
        
            case 3:
            searchingjamaah();
            system("pause");
            databaru.close();
            break;
        
            case 4:
            sortingjamaah(namafile);
            system("pause");
            databaru.close();
            break;
        
            case 0:
            databaru<<"[DATA JAMAAH PENERIMA TAKJIL]\n";
            databaru<<"Data Jamaah Penerima Takjil pada "<<takjil.tgl.hari<<"/"<<takjil.tgl.bulan<<"/"<<takjil.tgl.tahun<<endl;
            databaru<< "Menu takjil : " << takjil.namamenu<<endl;
            databaru<< "Jumlah takjil tersisa : " << takjil.jumlah << "\n\n";
            databaru<<"+"<<setfill('-')<<setw(5)<<"+"<<setw(13)<<"+"<<setw(12)<<"+"<<setw(27)<<"+"<<setw(23)<<"+"<<endl;
            databaru<<"|"<<left<<setfill(' ')<<setw(4)<<" No"<<"|"<<setw(12)<<" No Antrian"<<"|"<<setw(11)<<" NIM"<<"|"<<setw(26)<<" Nama Jamaah"<<"|"<<setw(22)<<" Jurusan"<<"|"<<endl;
            databaru<<right<<"+"<<setfill('-')<<setw(5)<<"+"<<setw(13)<<"+"<<setw(12)<<"+"<<setw(27)<<"+"<<setw(23)<<"+"<<endl;
            for(int i = 0; i < jumlahjamaah; i++){
                databaru<<"| "<<left<<setfill(' ')<<setw(3)<<i+1<<"| "<<setw(11)<<mentah[i].noantrian<<"| "<<setw(10)<<mentah[i].nim<<"| "<<setw(25)<<mentah[i].nama<<"| "<<setw(21)<<mentah[i].jurusan<<"|"<<endl;  
            }
            databaru<<right<<"+"<<setfill('-')<<setw(5)<<"+"<<setw(13)<<"+"<<setw(12)<<"+"<<setw(27)<<"+"<<setw(23)<<"+"<<endl;
            databaru.close();
            exit(0);
            break;
        
            default:
            break;
            }
        } while (piladmin != 0);
}

void menueditdata(string namafile, string filementah, string datakecilmentah){
    int piladmin, index1 = 0, index2 = 0;
    string line1, line2;
    ifstream filelama(filementah);
    while (getline(filelama, line1)){
        stringstream ss(line1);
        string temp;
        getline(ss, temp, ','); pengambil[index1].noantrian = stoi(temp);
        getline(ss, temp, ','); pengambil[index1].nim = stoi(temp);
        getline(ss, temp, ','); pengambil[index1].nama = temp;
        getline(ss, temp, ','); pengambil[index1].jurusan = temp;
        mentah[index1].noantrian = pengambil[index1].noantrian;
        mentah[index1].nim = pengambil[index1].nim;
        mentah[index1].nama = pengambil[index1].nama;
        mentah[index1].jurusan = pengambil[index1].jurusan;
        index1++;
    }
    filelama.close();
    ifstream datakecil (datakecilmentah);
    while (getline(datakecil, line2)){
        stringstream ss(line2);
        string temp;
        getline(ss, temp, ','); takjil.tgl.hari = stoi(temp);
        getline(ss, temp, ','); takjil.tgl.bulan = stoi(temp);
        getline(ss, temp, ','); takjil.tgl.tahun = stoi(temp);
        getline(ss, temp, ','); takjil.namamenu = temp;
        getline(ss, temp, ','); takjil.jumlah = stoi(temp);
        getline(ss, temp, ','); jumlahjamaah = stoi(temp);
        getline(ss, temp, ','); k = stoi(temp);
        index2++;
    }
    do {
        cout<<"\n[PROGRAM BERBAGI RAMADHAN MASJID SABRINI]\n";
        cout << "Takjil Masjid Sabrini pada tanggal "<< takjil.tgl.hari<<"/"<<takjil.tgl.bulan<<"/"<<takjil.tgl.tahun<<endl;
        cout << "Penerima Takjil Masjid Sabrini\n";
        cout << "1. Input Data Jamaah Penerima Takjil\n";
        cout << "2. Data Jamaah Penerima Takjil\n";
        cout << "3. Pencarian Data Penerima Takjil\n";
        cout << "4. Sortir Data Penerima Takjil\n";
        cout << "0. Keluar\n";
        cout << "Pilihan admin : ";
        cin >> piladmin;
        switch (piladmin) {
            case 1:
            inputjamaah(namafile, filementah, datakecilmentah);
            break;
                        
            case 2:
            datajamaah();
            system("pause");
            break;
        
            case 3:
            searchingjamaah();
            system("pause");
            break;
        
            case 4:
            sortingjamaah(namafile);
            system("pause");
            break;
        
            case 0:
            exit(0);
            break;
        
            default:
            break;
            }
        } while (piladmin != 0);
}

void menufile(char *kembali){
    int menufile;
    string namafile, filementah, datakecilmentah;
    char buffer[256];
    FILE *log;
    cout<<"[PENDATAAN PENERIMA TAKJIL MASJID SABRINI]\n";
    cout<<"Silahkan input menu untuk mengakses dan menyimpan data jamaah :\n";
    cout<<"1. Lihat Riwayat Pendataan.\n";
    cout<<"2. Create Data Baru\n";
    cout<<"3. Edit Data\n";
    cout<<"0. Keluar\n";
    cout<<"Pilih menu : "; cin>>menufile;
    switch(menufile){
        case 1:
        log = fopen("log.txt", "r");
        if (log == NULL){
            printf("Belum ada riwayat file yang dibuat.\n");
            printf("Ingin kembali? (y/n) : "); cin>>*kembali;
            break;
        }
        cout<<"Berikut adalah nama-nama file yang sudah Anda buat sebelumnya :\n";
        while(fgets(buffer, sizeof(buffer), log)){
            printf("%s", buffer);
        }
        fclose(log);
        cout<<"\nKembali ke menu? (y/n) : "; cin>>*kembali;
        break;

        case 2:
        cout<<"[CREATE DATA]\n";
        cout<<"Silahkan masukkan nama file yang akan dibuat.\n";
        cout<<"(ex : haripertama)\n";
        cout<<"Nama file : ";
        log = fopen("log.txt", "a");
        if(log == NULL)
        {
           printf("Error!");   
           exit(1);             
        }
        cin>>namafile;
        filementah = "data" + namafile + ".csv";
        datakecilmentah = "datakecilmentah" + namafile + ".csv";
        namafile = namafile + ".txt";
        fputs((namafile + "\n").c_str(), log);
        fclose(log);
        menucreatedata(namafile, filementah, datakecilmentah);
        break;

        case 3:
        cout<<"[EDIT DATA]\n";
        cout<<"Silahkan input nama file yang telah dibuat sebelumnya.\n";
        cout<<"Note : Jika lupa nama file silahkan lihat di menu lihat riwayat pendatataan.\n";
        cout<<"(ex : haripertama)\n";
        cout<<"Masukkan nama file : "; cin>>namafile;
        filementah = "data" + namafile + ".csv"; 
        datakecilmentah = "datakecilmentah" + namafile + ".csv";
        namafile = namafile + ".txt";
        menueditdata(namafile, filementah, datakecilmentah);
        fclose(log);
        break;

        case 0:
        fclose(log);
        exit(0);
        break;

        default:
        break;
    }
}

int main() {
    system("cls");
    string username, pass;
    char kembali;
    bool login = false;
    int chance = 4, menu;
    do {
        cout<<"   Selamat Datang!    "<<endl;
        cout<<"     LOGIN ADMIN      "<<endl;
        cout<<"Username\t: "; cin>>username;
        cout<<"Password\t: "; cin>>pass;
        if (username == "admin" && pass == "123"){
            login = true;
            do {
                menufile(&kembali);
            } while (kembali == 'y' || kembali == 'Y');
        } else {
            cout<<"Maaf, username yang Anda masukkan salah."<<endl;
            cout<<"Kesempatan login yang tersisa adalah "<<chance-1<<"."<<endl<<endl;
            chance--;
        }
    } while ( chance > 0 && !login);
    return 0;
}