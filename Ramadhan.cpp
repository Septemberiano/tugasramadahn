#include <iostream>
#include <iomanip>
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

void inputmakan() {
    cout << "\n\tSelamat datang di Program Berbagi Ramadhan Masjid Sabrini\n";
    cout<<"Silahkan pilih input data takjil!\n";
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
    cout<<"[DATA TERSIMPAN]\n";
}

void inputjamaah() {
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
                        pengambil[i].noantrian = i;
                        mentah[i].noantrian = i;
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
                    }
                    jumlahjamaah = totalpenerima(k);
                    takjil.jumlah -= antrian[k];
                    k++;
                }
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
            cout<<"Nama Jamaah : "<<pengambil[i].nama;
            cout<<"Jurusan Jamaah : "<< pengambil[i].jurusan;
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
          if(found) {cout<<"tidak ada jamaah dengan nim "<< y << "dalam data masjid "<<endl;}
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
    cout<<"[PENCARIAN DATA PENERIMA TAKJIL]\n";
    cout<<"Pilih Via Pencarian :\n";
    cout<<"1. Cari melalui Nomor Antrian penerima takjil\n";
    cout<<"2. Cari melalui NIM penerima takjil\n";
    cout<<"Pilihan Admin : "; cin>>viacari;
    switch(viacari){
        case 1:
       
        break;

        case 2:
        metodecarinimtidakurut();
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
                int tempantrian = pengambil[j+1].noantrian;
                int tempnim = pengambil[j+1].nim;
                string tempnama = pengambil[j+1].nama;
                pengambil[j+1].noantrian = pengambil[j].noantrian;
                pengambil[j+1].nim = pengambil[j].nim;
                pengambil[j+1].nama = pengambil[j].nama;
                pengambil[j].noantrian = tempantrian;
                pengambil[j].nim = tempnim;
                pengambil[j].nama = tempnama;
            }
        }
    }
}

void antrianbubbledesc(){
    for (int i = 0; i < jumlahjamaah-1; i++){
        for (int j = 0; j < jumlahjamaah-i-1; j++){
            if (pengambil[j].noantrian < pengambil[j+1].noantrian){
                int tempantrian = pengambil[j+1].noantrian;
                int tempnim = pengambil[j+1].nim;
                string tempnama = pengambil[j+1].nama;
                pengambil[j+1].noantrian = pengambil[j].noantrian;
                pengambil[j+1].nim = pengambil[j].nim;
                pengambil[j+1].nama = pengambil[j].nama;
                pengambil[j].noantrian = tempantrian;
                pengambil[j].nim = tempnim;
                pengambil[j].nama = tempnama;
            }
        }
    }
}

void antrianselectionasc(){
    for (int i = 0; i < jumlahjamaah-1; i++){
        int tempantrian = pengambil[i].noantrian;
        int tempnim = pengambil[i].nim;
        string tempnama = pengambil[i].nama;
        int g = i;
        for (int j = i + 1; j < jumlahjamaah; j++){
            if (pengambil[g].noantrian > pengambil[j].noantrian){
                g = j;
            }
        }
        pengambil[i].noantrian = pengambil[g].noantrian;
        pengambil[i].nim = pengambil[g].nim;
        pengambil[i].nama = pengambil[g].nama;
        pengambil[g].noantrian = tempantrian;
        pengambil[g].nim = tempnim;
        pengambil[g].nama = tempnama;
    }
}

void antrianselectiondesc(){
    for (int i = 0; i < jumlahjamaah-1; i++){
        int tempantrian = pengambil[i].noantrian;
        int tempnim = pengambil[i].nim;
        string tempnama = pengambil[i].nama;
        int g = i;
        for (int j = i + 1; j < jumlahjamaah; j++){
            if (pengambil[g].noantrian < pengambil[j].noantrian){
                g = j;
            }
        }
        pengambil[i].noantrian = pengambil[g].noantrian;
        pengambil[i].nim = pengambil[g].nim;
        pengambil[i].nama = pengambil[g].nama;
        pengambil[g].noantrian = tempantrian;
        pengambil[g].nim = tempnim;
        pengambil[g].nama = tempnama;
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
                    int tempantrian = pengambil[g].noantrian;
                    int tempnim = pengambil[g].nim;
                    string tempnama = pengambil[g].nama;
                    pengambil[g].noantrian = pengambil[g+1].noantrian;
                    pengambil[g].nim = pengambil[g+1].nim;
                    pengambil[g].nama = pengambil[g+1].nama;
                    pengambil[g+1].noantrian= tempantrian;
                    pengambil[g+1].nim= tempnim;
                    pengambil[g+1].nama = tempnama;
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
                    int tempantrian = pengambil[g].noantrian;
                    int tempnim = pengambil[g].nim;
                    string tempnama = pengambil[g].nama;
                    pengambil[g].noantrian = pengambil[g+1].noantrian;
                    pengambil[g].nim = pengambil[g+1].nim;
                    pengambil[g].nama = pengambil[g+1].nama;
                    pengambil[g+1].noantrian= tempantrian;
                    pengambil[g+1].nim= tempnim;
                    pengambil[g+1].nama = tempnama;
                }
            }
         }
     }  
}

int partitionasc(int awal, int akhir) {
    int i, pivot=pengambil[akhir].noantrian, ip=awal;
    for(i=awal; i<akhir; i++) {
        if(pengambil[i].noantrian <= pivot) {
            int tempantrian = pengambil[i].noantrian;
            int tempnim = pengambil[i].nim;
            string tempnama = pengambil[i].nama;
            pengambil[i].noantrian = pengambil[ip].noantrian;
            pengambil[i].nim = pengambil[ip].nim;
            pengambil[i].nama = pengambil[ip].nama;
            pengambil[ip].noantrian= tempantrian;
            pengambil[ip].nim= tempnim;
            pengambil[ip].nama = tempnama;
            ip++;
        }
    }
    int tempantrian = pengambil[akhir].noantrian;
    int tempnim = pengambil[akhir].nim;
    string tempnama = pengambil[akhir].nama;
    pengambil[akhir].noantrian = pengambil[ip].noantrian;
    pengambil[akhir].nim = pengambil[ip].nim;
    pengambil[akhir].nama = pengambil[ip].nama;
    pengambil[ip].noantrian= tempantrian;
    pengambil[ip].nim= tempnim;
    pengambil[ip].nama = tempnama;
    return ip;
}

int partitiondesc(int awal, int akhir) {
    int i, pivot=pengambil[akhir].noantrian, ip=awal;
    for(i=awal; i<akhir; i++) {
        if(pengambil[i].noantrian >= pivot) {
            int tempantrian = pengambil[i].noantrian;
            int tempnim = pengambil[i].nim;
            string tempnama = pengambil[i].nama;
            pengambil[i].noantrian = pengambil[ip].noantrian;
            pengambil[i].nim = pengambil[ip].nim;
            pengambil[i].nama = pengambil[ip].nama;
            pengambil[ip].noantrian= tempantrian;
            pengambil[ip].nim= tempnim;
            pengambil[ip].nama = tempnama;
            ip++;
        }
    }
    int tempantrian = pengambil[akhir].noantrian;
    int tempnim = pengambil[akhir].nim;
    string tempnama = pengambil[akhir].nama;
    pengambil[akhir].noantrian = pengambil[ip].noantrian;
    pengambil[akhir].nim = pengambil[ip].nim;
    pengambil[akhir].nama = pengambil[ip].nama;
    pengambil[ip].noantrian= tempantrian;
    pengambil[ip].nim= tempnim;
    pengambil[ip].nama = tempnama;
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

void sortingjamaah(){

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
        switch(metodesort){
            case 1:
            cout<<"Urutkan berdasarkan :\n";
            cout<<"1. Terkecil ke terbesar (Ascending)\n";
            cout<<"2. Terbesar ke terkecil (Descending)\n";
            cout<<"Pilih urutan : "; cin>>urutan;
            switch (urutan){
                case 1:
                break;
                
                case 2:
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
                break;
                
                case 2:
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
                break;
                
                case 2:
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
                break;
                
                case 2:
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
                break;

                case 2:
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
}


int main() {
    system("cls");
    string username, pass;
    bool login = false;
    int chance = 4, menu, piladmin;
    do {
        cout<<"   Selamat Datang!    "<<endl;
        cout<<"     LOGIN ADMIN      "<<endl;
        cout<<"Username\t: "; cin>>username;
        cout<<"Password\t: "; cin>>pass;
        if (username == "admin" && pass == "123"){
            login = true;
            inputmakan();
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
                    inputjamaah();
                    break;
                    
                    case 2:
                    datajamaah();
                    break;
    
                    case 3:
                    searchingjamaah();
                    break;
    
                    case 4:
                    sortingjamaah();
                    break;
    
                    case 0:
                    exit(0);
                    break;
    
                    default:
                    break;
                }
            } while (piladmin != 0);
        } else {
            cout<<"Maaf, username yang Anda masukkan salah."<<endl;
            cout<<"Kesempatan login yang tersisa adalah "<<chance-1<<"."<<endl<<endl;
            chance--;
        }
    } while ( chance > 0 && !login);
    return 0;
}