#include <stdio.h>
#include <stdlib.h>

int main()
{
    int menu,tinggi;

    printf("pilih menu seleksi\n");
    printf("===================\n");
    printf("1. Laki-Laki\n");
    printf("2. Perempuan\n");
    printf("===================\n");
    printf("pili no berapa: ");
    scanf("%d", &menu);

    switch(menu)
    {
    case 1:
        printf("isikan tinggimu: ");
        scanf("%d",& tinggi);

        if(tinggi >=175 && tinggi <=200)
            {
            printf("selamat anda dinyatakan lulus");
            }
        else if (tinggi >=200)
            {
            printf("tinggi anda tidak normal");
            }
        else
            {
            printf("mohon maaf anda tidak lulus seleksi");
            }
        break;

    case 2:
        printf("isikan tinggimu: ");
        scanf("%d",& tinggi);

        if(tinggi >=165 && tinggi <=180)
            {
            printf("selamat anda dinyatakan lulus");
            }
        else if(tinggi >=180)
            {
            printf("tinggi anda tidak normal");
            }

        else
            {
            printf("mohon maaf anda tidak lulus seleksi");
            }
        break;

    default:
        printf("mohon maaf menu tidak tersedia");
    }

    return 0;
}
