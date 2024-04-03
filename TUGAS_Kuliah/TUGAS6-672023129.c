#include <stdio.h>
#include <windows.h>

int main()
{
int tugas;
    printf("====================================\n");
    printf("\tEleazar\n");
    printf("====================================\n");
    printf("\tTugas Array\n\n");
    printf("1. Reversed Array\n");
    printf("2. Reversed Matrix\n");
    printf("3. keluar\n");
    printf("\n====================================\n");
       printf("Pilih Tugas => ");

  if (scanf("%d", &tugas) !=1) {
        printf("Mohon maaf, masukan angka bukan huruf\n");
        sleep(2);
        printf("tekan enter untuk kembali");

        while((getchar())!='\n');
        getch();
        system("cls");
        main();
    } else {
        switch (tugas) {
            case 1:
                system("cls");
                arry();
                break;
            case 2:
                system("cls");
                matrix();
                break;
            case 3:
                keluar();
                break;
            default:
                printf("Mohon maaf, menu tidak tersedia.\n");
                getch();
                system("cls");
                main();
                break;
        }
    }

    return 0;
}

void arry()
{
    int e;
    printf("masukan jumlah elemen yang diinginkan : ");
    scanf("%d",& e);

     int jumlah[e];

     printf("masukan elemennya : \n");
     for(int z = 0 ; z<e ; z++){
        scanf("%d", &jumlah[z]);
     }

     printf("\n=====================\n");
     printf("        Hasil\n");
     printf("=====================\n\n");
     for(int z = e-1; z>=0; z--)
     {
         printf(" %d ",jumlah[z]);
     }
     getch();
     system("cls");
     main();

}

void keluar ()
{
    exit(0);

    return 0;
}


void matrix()
{
    int matriks[3][3];

    printf("Masukkan elemen matriks 3x3: \n");

    for (int e = 2; e >= 0; e--) {
        for (int l = 2; l >= 0; l--) {
            scanf("%d", &matriks[e][l]);
        }
    }
    printf("\n===================================\n");
    printf("                Hasil  \n");
    printf("===================================\n");

    for (int e = 0; e < 3; e++) {
        for (int l = 0; l < 3; l++) {
            printf("%d \t", matriks[e][l]);
        }
        printf("\n");
    }
    getch();
    system("cls");
    main();
}







