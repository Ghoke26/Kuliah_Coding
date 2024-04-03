#include <stdio.h>

int main ()
{
    printf("=========================\n");
    printf("Pilih yang kamu inginkan\n");
    printf("=========================\n");
    printf("\n1. Menjadi kaya\n");
    printf("2. Menjadi jahat\n");
    printf("3. Menjadi baik\n");
    printf("4. tidak menjadi apa2\n");

    int isi;
    printf("\npilih no yang kamu inginkan: ");
    scanf("&d", &isi);

    switch(isi){
case 1:
    printf("lakukan yang terbaik supaya dapat menjadi kaya");
    getch();
    system("cls");
    main();
    break;

default :
 printf("ngak ada menu yang seperti itu");
 getch();
 system("cls");
 main();
 break;

    }


    return 0;
}
