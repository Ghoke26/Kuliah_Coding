#include <stdio.h>

int main()
{
    float bilangan_satu,bilangan_kedua;

            printf("masukan angka satu: ");
            scanf("%f",&bilangan_satu);

        printf("masukan angka kedua: ");
        scanf("%f",&bilangan_kedua);

    //hasil dari bilangan pertama dan kedua
    float hasil = bilangan_satu * bilangan_kedua;
    printf("hasil dari perkalian tersebut adalah : %.lf\n",hasil);

    return 0;


}
