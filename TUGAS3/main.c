#include <stdio.h>
#include <stdlib.h>

int main()
{
    int tinggi,menu;

    printf("===========================\n");
    printf("SELEKSI TINGGI BADAN\n");
    printf("===========================\n");
    printf("1. Peserta Laki-Laki \n");
    printf("2. peserta perempuan \n");
    printf("3. Exit\n");
    printf("===========================\n");

    printf("Pilih no yang sesuai: ");
    scanf("%d",&menu);


    switch(menu){
        //LAKI-LAKI
case 1:
    printf("===========================");
    printf("\nisi tinggi badanmu: ");
    scanf("%d", &tinggi);

    if(tinggi >=175 && tinggi <= 200)
        {
        printf("\n== Selamat anda lulus seleksi tahap ini! ==\n");
        }
    else if(tinggi >=200 )
        {
        printf("tinggi peserta tidak normal");
        }
    else{
        printf("Maaf, anda dinyatakan tidak lulus seleksi ini\n");
        }
    getch();
    system("cls");
    main();
    break;

    //PEREMPUAN
case 2:
    printf("===========================\n");
    printf("isi tinggi badanmu: ");
    scanf("%d", &tinggi);

    if(tinggi >=165 && tinggi <=180)
    {
        printf("\n== Selamat anda lulus seleksi tahap ini! ==\n");
    }
    else if(tinggi >=180)
    {
        printf("tinggi peserta tidak normal\n");
    }
    else
    {
        printf("Maaf, anda dinyatakan tidak lulus seleksi ini\n");
    }
    getch();
    system("cls");
    main();
    break;

case 3:
    printf("Terima kasih");
    getch();
    system("cls");
    main();
    break;

default:
    printf("Pilihan Mendaftar Tidak Tersedia\n");
    getch();
    system("cls");
    main();
    break;
    }



    return 0;
}
