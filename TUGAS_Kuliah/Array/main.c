#include <stdio.h>
#include <stdlib.h>

void main()
{
    int angka;
    char hari [7] [6] = {"Senin", "Selasa", "Rabu", "Kamis", "Jumat","Sabtu", "Minggu"};// 7 = isi baris 6= batas kata
    printf("Hari dalam satu minggu:  ?\n\n");

    printf("Input hari (1-7) :");
    scanf("%i", &angka);

    printf("Hari ke-%i adalah hari %s",angka,hari[angka-1]);
    getch();
    system("cls");
    main();

}
