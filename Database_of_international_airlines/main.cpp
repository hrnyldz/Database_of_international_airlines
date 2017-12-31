#include <iostream>
#include <windows.h>
#include <mysql.h>
#include <string>
#include <sstream>
#include <cstring>
#include <stdio.h>

using namespace std;


    MYSQL_RES* sonuc;
    MYSQL* baglanti;
    int durum;
    MYSQL_ROW sira;


    void baglan(){
        baglanti=mysql_init(0);
        baglanti=mysql_real_connect(baglanti,"localhost","root","","airlines",0,NULL,0);
}

string yolcularekle(){
    string tckno;
    string  isim;
    string adres;
    string eposta;
    string sehir;
 if(baglanti){

        cout<<"TCKNO: ";
        cin>>tckno;
        cout<<endl<<"ad/soyad :  ";
        cin>>isim;
        cout<<"adres:  ";
        cin>>adres;
        cout<<"yasadiginiz sehir:  ";
        cin>>sehir;
        cout<<"e-posta: ";
        cin>>eposta;

        string query="insert into yolcular(TCKNO,Isim,Adres,Eposta,Sehir) values('"+tckno+"','"+isim+"','"+adres+"','"+eposta+"','"+sehir+"')";
        const char* q = query.c_str();
        durum = mysql_query(baglanti,q);
    }
return tckno;
}


void yolcularlistele(){
 durum = mysql_query(baglanti,"SELECT * FROM yolcular");
        if(!durum)
        {
        sonuc=mysql_store_result(baglanti);
        while(sira=mysql_fetch_row(sonuc)){
                    cout <<"TCKNO :"<<sira[0]<<" "
                    <<"Isim :"<<sira[1]<<" "
                    <<"Adres :"<<sira[2]<<" "
                    <<"Eposta:"<<sira[3]<<" "
                    <<"Sehir :"<<sira[4]<<" "
                    <<endl;

                }
        }
}

void ucakekle(){
        string modeli,kno,kapasite;

        if(baglanti){
            cout<<"UKNO: "<<endl;
            cin>>kno;
            cout<<"Modeli :  "<<endl;
            cin>>modeli;
            cout<<"Kapasite : "<<endl;
            cin>>kapasite;

            string query="insert into ucaklar(kno,kapasite,modeli) values ('"+kno+"','"+kapasite+"','"+modeli+"')";
            const char* q = query.c_str();
            durum = mysql_query(baglanti,q);
    }
}

void ucaklistele(){
        durum = mysql_query(baglanti,"SELECT * FROM ucaklar");
            if(!durum)
            {
                sonuc=mysql_store_result(baglanti);
                    while(sira=mysql_fetch_row(sonuc)){
                            cout <<"KNO :"<<sira[0]<<" "
                            <<"Kapasitesi :"<<sira[1]<<" "
                            <<"Modeli :"<<sira[2]<<" "
                            <<endl;
                    }
            }
}

string dizi[4];
void seferekle(){
        string bn,bin,saat,tarih,ukno;
        if(baglanti){
            cout<<"Baslangic noktasi: "<<endl;
            cin>>bn;
            cout<<"Bitis noktasi:  "<<endl;
            cin>>bin;
            cout<<"Saat : "<<endl;
            cin>>saat;
            cout<<"Tarih : "<<endl;
            cin>>tarih;
            cout<<"Kuyruk no : "<<endl;
            cin>>ukno;
            dizi[0]=tarih;
            dizi[1]=bn;
            dizi[2]=bin;
            dizi[3]=ukno;

                string query="insert into seferler(bn,bin,saat,tarih,ukno) values('"+bn+"','"+bin+"','"+saat+"','"+tarih+"','"+ukno+"')";
                const char* q = query.c_str();
                durum = mysql_query(baglanti,q);
    }
}
void seferlistele(){
        durum = mysql_query(baglanti,"SELECT * FROM seferler");

        if(!durum)
        {
            sonuc=mysql_store_result(baglanti);
                while(sira=mysql_fetch_row(sonuc)){
                        cout <<"Baslangic noktasi : "<<sira[0]<<" "
                        <<"Bitis noktasi : "<<sira[1]<<" "
                        <<"Saat : "<<sira[2]<<" "
                        <<"Tarih : "<<sira[3]<<" "
                        <<"UKNO : "<<sira[4]<<" "
                        <<endl;
                                                  }
        }
}

void yolculisteleme(){
        durum = mysql_query(baglanti,"SELECT * FROM yolcu");
        if(!durum)
        {
            sonuc=mysql_store_result(baglanti);
                while(sira=mysql_fetch_row(sonuc)){
                    cout <<"Tarih :"<<sira[0]<<" "
                    <<"UKNO :"<<sira[1]<<" "
                    <<"TCKNO :"<<sira[2]<<" "
                    <<"BN :"<<sira[3]<<" "
                    <<"BIN :"<<sira[4]<<" "
                    <<endl;
                }
        }
}

int main()
{

baglan();

/**TABLO OLUSTURMA KODLARI*/

    mysql_query(baglanti, "CREATE TABLE yolcular(TCKNO BIGINT(12)  , Isim TEXT, Adres TEXT , Eposta TEXT, Sehir TEXT)");
    mysql_query(baglanti,"ALTER TABLE  yolcular DROP PRIMARY KEY ADD PRIMARY  KEY(TCKNO)  ");

    mysql_query(baglanti, "CREATE TABLE ucaklar(kno VARCHAR(11) , kapasite TEXT, modeli TEXT)");
    mysql_query(baglanti,"ALTER TABLE  ucaklar DROP PRIMARY KEY ADD PRIMARY  KEY(kno) ");

    mysql_query(baglanti, "CREATE TABLE seferler(bn VARCHAR(11) , bin VARCHAR(11) , saat VARCHAR(11), tarih VARCHAR(11), ukno VARCHAR(11))");
    mysql_query(baglanti,"ALTER TABLE  seferler DROP PRIMARY KEY ADD PRIMARY KEY(bn,bin,tarih,ukno) ");

    mysql_query(baglanti, "CREATE TABLE yolcu(tarih INT , kno VARCHAR(11)  , TCKNO BIGINT(12)  , bn INT   , bin INT  )");
    mysql_query(baglanti,"ALTER TABLE  yolcu DROP PRIMARY KEY ADD PRIMARY KEY(tarih,kno,TCKNO,bn,bin ");

        cout<<"Yolcular tablosuna eklemek icin 1 e basiniz."<<endl;
        cout<<"Yolcular tablosunu listelemek icin 2 e basiniz."<<endl;
        cout<<"Ucak tablosuna eklemek icin 3 e basiniz."<<endl;
        cout<<"Ucak tablosunu listelemek icin 4 e basiniz."<<endl;
        cout<<"Seferler tablosuna eklemek icin 5 e basiniz."<<endl;
        cout<<"Seferler tablosunu listelemek icin 6 e basiniz."<<endl;
        cout<<"Yolcu tablosu listelemek icin 7 e basiniz."<<endl;
        cout<<"1.sorgu ->Yeni sefer tanimlama (sefer tablosu) icin 8 e basin"<<endl;
        cout<<"3.sorgu ->Yolcu sorgulama icin 9 e basin"<<endl;
        cout<<"5.sorgu ->Bilet iptali icin 10 a basin"<<endl;
        cout<<"6.sorgu ->Sefer sorgulama icin 11 e basin"<<endl;

string tckno1;

int secim;
while(true){
    cin>>secim;
    switch(secim){
        case 1:{
        tckno1=yolcularekle();
        break;
        }
        case 2:{
        yolcularlistele();
        break;
        }
        case 3:{
        ucakekle();
        break;
        }
        case 4:{
        ucaklistele();
        break;
        }
        case 5:{
        seferekle();

        string query="insert into yolcu(tarih,kno,TCKNO,bn,bin) values('"+dizi[0]+"','"+dizi[3]+"','"+tckno1+"','"+dizi[1]+"','"+dizi[2]+"')";
        const char* q = query.c_str();
        durum = mysql_query(baglanti,q);
        break;
        }
        case 6:{
        seferlistele();
        break;
        }
        case 7:{
        yolculisteleme();
        break;
        }

        case 8:{
        cout<<"Yeni sefer ekleyiniz"<<endl;
        seferekle();
        seferlistele();
        break;
        }
        case 9:{
        string tcno;
        cout<<"TC Kimlik No' ya gore ucuslar listelenecektir."<<endl;
        cout<<"TC Kimlik No giriniz."<<endl;
        cin>>tcno;
        std::string s="SELECT * FROM yolcu WHERE TCKNO="+tcno;
        durum=mysql_query(baglanti,s.c_str());

        if(!durum)
        {
            sonuc=mysql_store_result(baglanti);
                while(sira=mysql_fetch_row(sonuc)){
                    cout <<"Tarih :"<<sira[0]<<" "
                    <<"UKNO :"<<sira[1]<<" "
                    <<"TCKNO :"<<sira[2]<<" "
                    <<"BN :"<<sira[3]<<" "
                    <<"BIN :"<<sira[4]<<" "
                    <<endl;
                }

        }
        break;
        }
        case 10:{
        cout<<"Bilet iptali icin TCKN, tarih ve ucak kuyruk numarasi giriniz."<<endl;
        string tno,trh1,uckkno;
        cout<<"TCKNO :"<<endl;
        cin>>tno;
        cout<<"Tarih :"<<endl;
        cin>>trh1;
        cout<<"Ucus kuyruk no:"<<endl;
        cin>>uckkno;

        std::string srg="DELETE FROM yolcu WHERE tarih="+trh1+" AND kno='"+uckkno+"' AND TCKNO="+tno+"";
        durum=mysql_query(baglanti,srg.c_str());

        break;
        }
        case 11:{
        cout<<"Verilen tarih ve kuyruk numarasina gore o ucusta yer alacak yolcularin tum bilgileri listelenecektir."<<endl;
        cout<<"Tarihi giriniz."<<endl;
        string trh;
        cin>>trh;
        cout<<"Kuyruk nosunu giriniz."<<endl;
        string no;
        cin>>no;
        std::string sorgu="SELECT * FROM yolcu WHERE tarih="+trh+" AND kno='"+no+"'";
        durum=mysql_query(baglanti,sorgu.c_str());

        if(!durum)
        {
            sonuc=mysql_store_result(baglanti);
                while(sira=mysql_fetch_row(sonuc)){
                    cout <<"Tarih :"<<sira[0]<<" "
                    <<"UKNO :"<<sira[1]<<" "
                    <<"TCKNO :"<<sira[2]<<" "
                    <<"BN :"<<sira[3]<<" "
                    <<"BIN :"<<sira[4]<<" "
                    <<endl;
                }
        }
        break;
        }

        default:{
        cout<<"Belirtilen aralikta sayi giriniz"<<endl;
        break;
        }

}}
    return 0;
}
