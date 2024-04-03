#include <stdio.h>



int main()
{
    int menu;

    printf("\n=========================");
    printf("\n    Latihan DDP SERU     ");
    printf("\n=========================");
    printf("\n1. Bilangan Kelipatan \n");
    printf("2. perulangan/looping\n");
    printf("3. selesai progran\n");
    printf("pilih soal =>");
    scanf("%d", &menu);

        switch(menu)
    {
    case 1 :
            system("cls");
            kosong1();

    case 2 :
        system("cls");
        kosong2();

    default :
        printf("mohon maaf menu tidak tersedia\n");
        getch();
        system("cls");
        main();

    }
}
void kosong1 ()
{
int e,f;
            printf("masukan angka maksimum =>");
            scanf("%d", & f);

            for(e=0; e<=f ; e++)
            {

            if (e % 3 == 0 && e % 5 == 0 )
                {
                printf("kelipatan tiga dan lima \n");
                }

                else if (e % 3 == 0)
                    {
                        printf("kelipatan tiga\n");
                    }

                else if (e % 5 == 0)
                    {
                    printf("kelipatan lima\n");
                    }
                else
                    {
                    printf("%d\n",e );
                    }

            }
}





void kosong2()
{

    int n ;
    int i,j;
    char kar;

    printf("masukan jumlah baris : ");
    scanf("%d", &n);

    printf("masukan karakter : ");
    scanf(" %c", &kar);

    for(i =n; i >= 1; i--)
    {
        for(j= 1; j <= i; j++)
        {
            printf(" %c",kar);
        }
        printf("\n");
    }
    system("cls");
 }

