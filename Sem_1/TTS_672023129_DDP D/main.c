#include <stdio.h>
#include <stdlib.h>


void biodata();
void kalkulator();
void looping();
void ASDOS();
void keluar();

int main()
{

    int menu;
    printf("============================\n");
     printf("Tes tengah Semester\n");
      printf("===========================\n");


       printf("1. Operasi Matematika\n");
       printf("2. perulangan/ looping\n");
       printf("3. Biodata mahasiswa\n");
       printf("4. nama lengkap Kak Asdos\n");
       printf("5. Exit\n");

    printf("pilih soal=> ");
    scanf("%d", &menu);


    switch(menu)
    {
    case 1:
            system("cls");
            kalkulator();
            getch();
            main();
            break;

    case 2:
        system("cls");
        looping();
        getch();
        main();
        break;

    case 3:
        system("cls");
        biodata();
        getch();
        main();
        break;

    case 4:
        system("cls");
        ASDOS();
        getch();
        main();
        break;

    case 5:
        system("cls");
        keluar();
        getch();
        main();
        break;

    default :
        printf("mohon maaf menu tidak tersedia");
        getch();
        system("cls");
        main();
        break;

    }


       return 0 ;
}

int penjumlahan(int a, int b){
return a + b;
}

int pengurangan(int a, int b){
return a - b;
}

int perkalian(int a, int b){
return a * b;
}

int pembagian(int a, int b){
return a / b;
}

int hasil_penjumlahan(){
float angka1 = 7;
float angka2 = 10;
float jumlah = penjumlahan(angka1, angka2);

printf("Hasil dari penjumlahan %.2f + %.2f adalah %.2f ", angka1, angka2, jumlah);
getch();
system("cls");
main();
}

int hasil_pengurangan(){
float angka1 = 10.0;
float angka2 = 7.0;
float kurang = pengurangan(angka1, angka2);

printf("Hasil dari pengurangan %.2f - %.2f adalah %.2f ", angka1, angka2, kurang);
getch();
system("cls");
main();
}

int hasil_perkalian(){
float angka1 = 8.0;
float angka2 = 9.0;
float kali = perkalian(angka1, angka2);

printf("Hasil dari perkalian %.2f X %.2f adalah %.2f ", angka1, angka2, kali);
getch();
system("cls");
main();
}

int hasil_pembagian(){
float angka1 = 10.4;
float angka2 = 5.4;
float bagi = pembagian(angka1, angka2);

printf("Hasil dari pembagian %.2f / %.2f adalah %.2f ", angka1, angka2, bagi);
getch();
system("cls");
main();
}



void looping()
{
    int n = 7;
    int i,j;
    char karakter;

    printf("masukan karakter : ");
    scanf(" %c", &karakter);

    for(i =1; i <= n; i++)
    {
        for(j= 1; j <= i; j++)
        {
            printf(" %c",karakter);
        }
        printf("\n");
    }
    getch();
    system("cls");
    main();
}



void biodata()
{
    printf("Nama   : Eleazar Abdiel Hasiholan Simbolon\n");
    printf("NIM    : 672023129\n");
    printf("Asal   : Kalimantan Timur\n");
    printf("Status : Mahasiswa\n");
    getch();
    system("cls");
    main();

}

void ASDOS()
{
    printf("Nama   : Shelmond Euguene Bimantara \n");
    printf("NIM    : 672022300\n");
    printf("\n");
    printf("Nama   : Ignatius Marchel Sadanahensa\n");
    printf("NIM    : 672022018\n");
    getch();
    system("cls");
    main();

}

void kalkulator()
{

char pilih;
    printf("======================\n");
    printf("Menu Kalkulator\n");
    printf("======================\n");
    printf("1. Penjumlahan\n");
    printf("2. Pengurangan\n");
    printf("3. Perkalian\n");
    printf("4. Pembagian\n");
    printf("Input Pilihan => ");
    scanf("%d", &pilih);

    switch(pilih){

case 1:
    system("cls");
    hasil_penjumlahan();
    break;
case 2:
    system("cls");
    hasil_pengurangan();
    break;
case 3:
    system("cls");
    hasil_perkalian();

    break;
case 4:
    system("cls");
    hasil_pembagian();
    break;

default:
    printf("Pilihan Tidak Tersedia");
    getch();
    main();
    break;
}


}

void keluar()
{
    system("cls");
    printf("        TERIMA KASIH ATAS TTS NYA");
    sleep(2);
    system("cls");
    printf("        SEMOGA DAPAT YANG TERBAIK AMIN");
    sleep(3);
    system("cls");
}

