#include <stdio.h>
#include <stdlib.h>

void main()
{
    int tinggi, lebar;
    printf("##Program C##\n\n");
    printf("\n======================\n");

    printf("Tinggi:\t");
    scanf(" %d",&tinggi);

    printf("lebar: \t");
    scanf(" %d",&lebar);

    printf("\n");

    for(int e=0; e< tinggi; e++){
        for(int j= 0; j < lebar; j++){
            printf("*");
        }
        printf("\n");
    }

printf("\n======================\n");
    return 0;
}
