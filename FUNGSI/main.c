#include <stdio.h>

int main()
{
    char pilih;
    printf("==================\n");
    printf("MENU KALKULATOR\n");
    printf("==================\n");
    printf("1. Penjumlahan\n");
    printf("2. Pengurangan\n");
    printf("3. Perkalian\n");
    printf("4. Pembagian\n");
    printf("Input pilihan => \n");
    scanf("%d",&pilih);

switch (pilih){
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
	printf("Pilihan menu tidak tersedia");
	break;
}
}

int penjumlahan(int a, int b){
return a+b;
}

int pengurangan (int a, int b){
return a-b;
}

int perkalian(int a, int b){
return a*b;
}

int pembagian(int a, int b){
return a/b;
}

int hasil_penjumlahan(){
int angka1 =5;
int angka2 =10;
int jumlah= penjumlahan(angka1,angka2);

printf("hasil dari penjumlahan %d + %d adalah %d",angka1,angka2,jumlah);
getch();
system("cls");
main();
}
int hasil_pengurangan(){
int angka1 =10;
int angka2 =5;
int jumlah= pengurangan(angka1,angka2);

printf("hasil dari pengurangan %d - %d adalah %d",angka1,angka2,jumlah);
getch();
system("cls");
main();
}
int hasil_perkalian(){
int angka1 =5;
int angka2 =5;
int jumlah= perkalian(angka1,angka2);

printf("hasil dari perkalian %d x %d adalah %d",angka1,angka2,jumlah);
getch();
system("cls");
main();
}
int hasil_pembagian(){
int angka1 =10;
int angka2 =2;
int jumlah= pembagian(angka1,angka2);

printf("hasil dari pembagian %d : %d adalah %d",angka1,angka2,jumlah);
getch();
system("cls");
main();

return 0;
}






