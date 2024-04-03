#include <stdio.h>

int main()
{
    printf("====================\n");
    printf("Nama : Eleazar\n");
    printf("====================\n");
    printf("NIM  : 672023129\n");
    printf("====================\n");
    printf("\n");

    int i,j;
    for(i=1; i<=4; i++)
    {
            for(j=1; j<=8;j++)
        {
                if(j>= 6-i && j<=4+i)
                    printf("* ");
                else
                    printf("  ");
        }
        printf("\n");
    }

     for(i=4; i>=1; i--)
        {
        for(j=1; j<=8; j++)
            {
                if(j>=6-i && j<=4+i)
                    printf("* ");
                else
                    printf("  ");
            }

        printf("\n");
        }
        printf("\n====================\n");
    return 0;
}

