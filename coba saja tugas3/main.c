#include <stdio.h>
#include <stdlib.h>

int main()
{
int jenis_kelamin,tinggi,l,p,s;

    printf("===========================\n");
    printf("SELEKSI TINGGI BADAN\n");
    printf("===========================\n");
    printf("1. Peserta Laki-Laki \n");
    printf("2. peserta perempuan \n");
    printf("3. Exit\n");
    printf("===========================\n");
    printf("pilih menu peserta: ");
    scanf("%d",jenis_kelamin);

    if(tinggi>=200){
        l="tinggi peserta tidak normal";
    }
    else if(tinggi >180){
        p="tinggi peserta tidak normal";
    }
    else{
        p="diyatakan lulus";
        l="dinyatakan lulus";

    }
    switch(jenis_kelamin){
case 1:
    printf("hasilnya adalah %d",l,p);
    break;
case 2:
    printf("hasilnya adalah &d",l,p);
    }







/*    switch(tinggi)
  {
    case 1:
        printf("isi tinggi mu: \n");
        break;

    case 2:
        printf("isi tinggi mu:\n");

        break;

    case 3:
        printf("kamu akan kembali ke menu TYM\n");
        getch();
        system("cls");
        main();
        break;

    default:
        printf("pilihan mendaftar tidak tersedia\n");

    } */


    return 0;
}
