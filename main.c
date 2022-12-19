#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
//Created By Enes Malik Yilmaz

  void cevap_anahtari_uret(char cevap_anahtari[ ], int S){

    int i, sayi;

    srand(time(NULL));

    for(i = 0 ; i < S ; i++)
    {
        sayi = rand() % 5;          // 0-4 kapali araliginda rastgele sayi uretiyor
        cevap_anahtari[i]=cevap_anahtari[sayi];
    }
    //puts(cevap_anahtari);      //Testini yaptigim uzere rastgele cevap anahtarini cevap_anahtari char dizisinde tutabiliyoruz.
}

  void cevap_anahtari_yazdir (char cevap_anahtari[ ], int S){

 int i;

    printf("Cevap anahtari:\n");

    for(i=0;i<S;i++){
            if(i==15)
            printf("\n");

    printf("%.3d:",i+1);     // 001 , 002 , 003 ...
    printf("%c",cevap_anahtari[i]);    // A, D, C...
    printf(" | ");
    }
    printf("\n\n\n");
}

  void sinavi_uygula(char ogrenci_cevaplari[ ][100], char cevap_anahtari[ ], int N, int S, double B,double D){

    int i,sayi,j;

    for(j=0;j<N;j++) {                   //j== Ogrencileri artiran
            for(i=0;i<S;i++)    // i== Sorulari artiran
            {

                sayi = rand() % 100;

                if ( (sayi>=0) && (sayi<(B*100)) )   //Bos birakma ihtimali

                    ogrenci_cevaplari[j][i]= 'X';

                else if ( (sayi>=(B*100)) && (sayi<((B*100)+(D*100))) )   //Dogru cevap cikma ihtimali

                    ogrenci_cevaplari[j][i]= cevap_anahtari[i];    // Ogrenci cevabina cevap anahtarindaki cevabi yani doğru olani atiyor

                else if ( (sayi>=((D*100)+(B*100))) && (sayi<100) ) {  //Yanlis olma ihtimali

                        if     (cevap_anahtari[i]=='A'){ // Cevap hangisiyse diger 4 siktan birisini rastgele ogrenci_cevaplari dizisine atiyor
                            int sayi1;
                            sayi1 = rand() % 4;
                                if (sayi1==0)
                                    ogrenci_cevaplari[j][i]='B';
                                else if (sayi1==1)
                                    ogrenci_cevaplari[j][i]='C';
                                else if (sayi1==2)
                                    ogrenci_cevaplari[j][i]='D';
                                else if (sayi1==3)
                                    ogrenci_cevaplari[j][i]='E';
                        }
                        else if(cevap_anahtari[i]=='B'){
                            int sayi2;
                            sayi2 = rand() % 4;
                            if (sayi2==0)
                                ogrenci_cevaplari[j][i]='A';
                            else if (sayi2==1)
                                ogrenci_cevaplari[j][i]='C';
                            else if (sayi2==2)
                                ogrenci_cevaplari[j][i]='D';
                            else if (sayi2==3)
                                ogrenci_cevaplari[j][i]='E';
                        }
                        else if(cevap_anahtari[i]=='C'){
                            int sayi3;
                            sayi3 = rand() % 4;
                            if (sayi3==0)
                                ogrenci_cevaplari[j][i]='B';
                            else if (sayi3==1)
                                ogrenci_cevaplari[j][i]='A';
                            else if (sayi3==2)
                                ogrenci_cevaplari[j][i]='D';
                            else if (sayi3==3)
                                ogrenci_cevaplari[j][i]='E';
                        }
                        else if(cevap_anahtari[i]=='D'){
                            int sayi4;
                            sayi4 = rand() % 4;
                            if (sayi4==0)
                                ogrenci_cevaplari[j][i]='B';
                            else if (sayi4==1)
                                ogrenci_cevaplari[j][i]='C';
                            else if (sayi4==2)
                                ogrenci_cevaplari[j][i]='A';
                            else if (sayi4==3)
                                ogrenci_cevaplari[j][i]='E';
                        }
                        else if(cevap_anahtari[i]=='E'){
                            int sayi5;
                            sayi5 = rand() % 4;
                            if (sayi5==0)
                                ogrenci_cevaplari[j][i]='B';
                            else if (sayi5==1)
                                ogrenci_cevaplari[j][i]='C';
                            else if (sayi5==2)
                                ogrenci_cevaplari[j][i]='D';
                            else if (sayi5==3)
                                ogrenci_cevaplari[j][i]='A';
                        }
                        else
                        printf("HATA");
                    }
          }
    }
}

  void ogrenci_cevabini_yazdir(char ogrenci_cevaplari[ ][100], int ogrenci_ID, int S){

    int i,j;

    for(j=0;j<ogrenci_ID;j++){

        printf("%.3d. ogrencinin cevaplari:\n",(1+j));     // 001. ogrencinin cevaplari,002. ogrencinin cevaplari,...


                for(i=0;i<S;i++){

                    printf("%.3d:",(1+i));     // 001: , 002: , 003: ...
                    printf("%c",ogrenci_cevaplari[j][i]);    // A, D, C...
                    printf(" | ");
                }
        printf("\n");
    }

    printf("\n");

}

  void ogrencileri_puanla(char ogrenci_cevaplari[ ][100], char cevap_anahtari[ ], double HBN[ ],int N, int S){

  int i,j;


    for(i=0;i<N;i++){    //Ogrenci sayisini artiran dongu
            HBN[i]=0;    // her i sayisi yani ogrenci sayisi arttiginda o ogrencinin baslangic HBN sini 0 yapıyorum

            for(j=0;j<S;j++){    //Soru sayisini artiran dongu

                if(cevap_anahtari[j]==ogrenci_cevaplari[i][j])        //Cevap dogruysa
                    HBN[i]=HBN[i]+(100.0/S);
                else if((cevap_anahtari[j]!=ogrenci_cevaplari[i][j])&&(ogrenci_cevaplari[i][j]!='X'))   //Cevap yanlissa
                    HBN[i]=HBN[i]-(100.0/(S*4));
                else if(ogrenci_cevaplari[i][j]=='X') //Cevap bos ise
                    ;
            }

        if(HBN[i]<=0)    // HBN eksi cikarsa
            HBN[i]=0;    // 0 atiyorum
    }
    //printf("%f",HBN[1]);   // Denemesini burda yaptigim uzere HBN dizisini basari ile doldurdum :)
  }


  double sinif_ortalamasi_hesapla(double HBN[ ], int N){

    int i;
    double Ort,Toplam;
    for(i=1;i<=N;i++)
        Toplam=Toplam+HBN[i-1];

    Ort=(Toplam/N);

    return Ort;

  }


  double standart_sapma_hesapla(double ortalama, double HBN[ ], int N){

    int i;
    double std,Toplam,gecici,standart,a;

    for(i=1;i<=N;i++){
        gecici=(HBN[i-1] - ortalama);
        Toplam =(Toplam + pow(gecici,2));
    }
    std=(Toplam/N);
    a=sqrt(std);
    return a;
  }

  void sinif_duzeyi(double ortalama){

  if((ortalama>80) && (ortalama<=100))
    printf("Sinif duzeyi: Ustun Basari");

  if((ortalama>70) && (ortalama<=80))
    printf("Sinif duzeyi: Mukemmel");

  if((ortalama>62.5) && (ortalama<=70))
    printf("Sinif duzeyi: Cok iyi");

  if((ortalama>57.5) && (ortalama<=62.5))
    printf("Sinif duzeyi: Iyi");

  if((ortalama>52.5) && (ortalama<=57.5))
    printf("Sinif duzeyi: Ortanin ustu");

  if((ortalama>47.5) && (ortalama<=52.5))
    printf("Sinif duzeyi: Orta");

  if((ortalama>42.5) && (ortalama<=47.5))
    printf("Sinif duzeyi: Zayif");

  if(ortalama<=42.5)
    printf("Sinif duzeyi: Kotu");
    printf("\n\n");
  }
  void T_skoru_hesapla(double ortalama, double HBN[ ], int N, double std, double T_skoru[ ]){

  int i;

  for(i=0;i<N;i++){

        T_skoru[i]=(60)+(10*((HBN[i]-ortalama)/std));
  }
  //printf("%lf",T_skoru[1]);   //Burda testini yaptigim uzere T_skoru nu dogru bir sekilde hesaplayabiliyoruz.
  }

  void yardimci_fonk(int x,int N,double T_skoru[],char harf_notu[]){ /* T_skoru nu bulmak icin harf_notunu_hesapla fonksiyonunun icindeki her if te
                                                                        bu for dongusunu kurmamak icin ayri bir fonksiyon acip her if te onu cagirdik.
*/
  int i;
  for(i=0;i<N;i++){

        if(T_skoru[i]>=x+35){
            harf_notu[i]='A';
            harf_notu[i+100]='A'; }
        if((T_skoru[i]<x+35) && (T_skoru[i]>=x+30)){
            harf_notu[i]='B';
            harf_notu[i+100]='A'; }
        if((T_skoru[i]<x+30) && (T_skoru[i]>=x+25)){
            harf_notu[i]='B';
            harf_notu[i+100]='B'; }
        if((T_skoru[i]<x+25) && (T_skoru[i]>=x+20)){
            harf_notu[i]='C';
            harf_notu[i+100]='B'; }
        if((T_skoru[i]<x+20) && (T_skoru[i]>=x+15)){
            harf_notu[i]='C';
            harf_notu[i+100]='C'; }
        if((T_skoru[i]<x+15) && (T_skoru[i]>=x+10)){
            harf_notu[i]='D';
            harf_notu[i+100]='C'; }
        if((T_skoru[i]<x+10) && (T_skoru[i]>=x+5)){
            harf_notu[i]='D';
            harf_notu[i+100]='D'; }
        if((T_skoru[i]<x+5) && (T_skoru[i]>=x)){
            harf_notu[i]='F';
            harf_notu[i+100]='D'; }
        if(T_skoru[i]<x){
            harf_notu[i]='F';
            harf_notu[i+100]='F'; }
    }
  }

  void harf_notu_hesapla(double ortalama,int N,double T_skoru[],char harf_notu[]){

  int i;

  if((ortalama>80) && (ortalama<=100))
    yardimci_fonk(32,N,T_skoru,harf_notu);

  if((ortalama>70) && (ortalama<=80))
    yardimci_fonk(34,N,T_skoru,harf_notu);

  if((ortalama>62.5) && (ortalama<=70))
    yardimci_fonk(36,N,T_skoru,harf_notu);

  if((ortalama>57.5) && (ortalama<=62.5))
    yardimci_fonk(38,N,T_skoru,harf_notu);

  if((ortalama>52.5) && (ortalama<=57.5))
    yardimci_fonk(40,N,T_skoru,harf_notu);

  if((ortalama>47.5) && (ortalama<=52.5))
    yardimci_fonk(42,N,T_skoru,harf_notu);

  if((ortalama>42.5) && (ortalama<=47.5))
    yardimci_fonk(44,N,T_skoru,harf_notu);

  if(ortalama<=42.5)
    yardimci_fonk(46,N,T_skoru,harf_notu);
  }

  void ogrenci_notlarini_yazdir(int N,double HBN[],double T_skoru[],char harf_notu[]){ // Ogrenci notlarini yazdirmak icin kurdugum fonksiyon

    int i;
    printf("Ogrenci notlari:\n");

    for(i=0;i<N;i++){

        printf("%.3d. ogrencinin HBN: %.2lf, T-skoru: %.2lf, harf notu:%c%c",i+1,HBN[i],T_skoru[i],harf_notu[i],harf_notu[i+100]);
        printf("\n");
    }
  }

  int main()
{
    int N,S;            //N ogrenci sayisi, S soru sayisi
    double B,D;         //B Herhangi bir sorunun bos birakma ihtimali,  D Herhangi bir sorunun dogru cevaplama ihtimali
    char secenekler[1000]="ABCDE";

    printf("Ogrenci sayisini giriniz (max 100): ");
    scanf("%d",&N);

    printf("Soru sayisini giriniz (max 100): ");
    scanf("%d",&S);

    printf("Bos birakma ihtimalini giriniz (0.0 ~ 1.0): ");
    scanf("%lf",&B);

    printf("Dogru cevap verme ihtimalini giriniz (0.0 ~ 1.0): ");
    scanf("%lf",&D);

    printf("\n");

    char gecici[1000][100],harf_notu[201];
    double Ortalama,Standart_sapma,T_skoru[1000],ham_basari_notu[1000];

    cevap_anahtari_uret(secenekler,S);
    cevap_anahtari_yazdir(secenekler,S);
    sinavi_uygula(gecici,secenekler,N,S,B,D);
    ogrenci_cevabini_yazdir(gecici,N,S);
    ogrencileri_puanla(gecici,secenekler,ham_basari_notu,N,S);
    Ortalama = sinif_ortalamasi_hesapla(ham_basari_notu,N);
    printf("Sinif ortalamasi: %.2lf, ",Ortalama);
    Standart_sapma = standart_sapma_hesapla(Ortalama,ham_basari_notu,N);
    printf("standart sapma: %.2lf\n",Standart_sapma);
    sinif_duzeyi(Ortalama);  //Benim ekledigim fonskiyon
    T_skoru_hesapla(Ortalama,ham_basari_notu,N,Standart_sapma,T_skoru);
    harf_notu_hesapla(Ortalama,N,T_skoru,harf_notu);   //Benim ekledigim fonksiyon
    ogrenci_notlarini_yazdir(N,ham_basari_notu,T_skoru,harf_notu);   //Benim ekledigim fonksiyon

    return 0;
}
