#include <stdio.h>
#include <stdlib.h>


void menunya();
void harga();
void best();
void cabang();
void menukeluar();

int main()
{
    int menu; // menunya

    printf("\n|==========================|\n");
    printf("|Selamat Datang di Cafe EL |");
    printf("\n|==========================|\n");

    printf("\n1. Lihat Menu\n");
    printf("2. Lihat Harga\n");
    printf("3. Menu Best Seller\n");
    printf("4. Lihat Cabang\n");
    printf("5. Keluar\n");
    printf("Input Pilihanmu => ");
    scanf(" %d", &menu); // memilih menu dari switch

    switch(menu)
    { // ini pilihan dari menu
    case 1 :
            system("cls");
            menunya();
            main();
            break;
    case 2 :
            system("cls");
            harga();
            main();
            break;
    case 3 :
            system("cls");
            best();
            main();
            break;
    case 4 :
            system("cls");
            cabang();
            main();
            break;
    case 5 :
            system("cls");
            menukeluar();
            break;
    default :
        printf("Menu tidak tersedia");
        getch();
        system("cls");
        main();
        break;
    }
    return 0;
}

void menunya() // isi dari pilihan no 1
{
    int pilih;
    char menunya1;
    char memilih;

    char no1[]  ="Green Tea";
    char no2[]  ="Es Krim Campina";
    char no3[]  ="Es Krim Magnum";
    char no4[]  ="Lemon Tea Sakit Hati";
    char no5[]  ="Milk Shake";
    char no6[]  ="Caramel Macchiato";
    char no7[]  ="Matcha Frappe";

    printf("\n1. %s\n",no1);
    printf("2. %s\n",no2);
    printf("3. %s\n",no3);
    printf("4. %s\n",no4);
    printf("5. %s\n",no5);
    printf("6. %s\n",no6);
    printf("7. %s\n",no7);


    printf("\napakah ingin memesan Y/N: "); // scanf apakah ingin memesan ?
    scanf(" %c", &menunya1);

            if(menunya1== 'Y' || menunya1 == 'y') // membuat bisa huruf kecil atau besar tetapi hanya y dan Y
                {
                printf("\nisi pilihan anda: ");
                scanf("\n%d", &pilih); // memilih no berapa pada Menu

                    switch(pilih) //ini yang akan di print jika udah memilih
                    {
                    case 1 :
                        system("cls");
                        printf("\nTerima kasih telah membeli %s pesanan anda segera di antarkan ",no1);
                        break;

                    case 2 :
                        system("cls");
                        printf("Terima kasih telah membeli %s pesanan anda segera di antarkan ",no2);
                         break;

                    case 3 :
                        system("cls");
                        printf("Terima kasih telah membeli %s pesanan anda segera di antarkan ",no3);
                        break;

                    case 4 :
                        system("cls");
                        printf("\nTerima kasih telah membeli %s pesanan anda segera di antarkan ",no4);
                        break;
                    case 5 :
                        system("cls");
                        printf("\nTerima kasih telah membeli %s pesanan anda segera di antarkan ",no5);
                        break;
                    case 6 :
                        system("cls");
                        printf("\nTerima kasih telah membeli %s pesanan anda segera di antarkan ",no6);
                        break;
                    case 7 :
                        system("cls");
                        printf("\nTerima kasih telah membeli %s pesanan anda segera di antarkan ",no7);
                        break;

                    default : // ini akan print jika typo ataupun tidak sesuai
                        printf("mohon maaf pilihan hanya no 1-7 ");
                        getch();
                        system("cls");
                        menunya();
                         break;
                    }
                    getch(); // untuk enter
                    system("cls"); // menghapus jika salah pada menu pilihan anda
                }
                        else if (menunya1 == 'N' || menunya1 == 'n') // buat n dan N
                        {
                         printf("\nterima kasih telah melihat menu kami tekan enter untuk kembali ");
                         getch();
                         system("cls");
                        }
                                else // jika typo saat isi pilihan anda
                                    {
                                    printf("Menu tidak tersedia\n");
                                    printf("\nsilahkan tekan enter untuk kembali");

                                    getch();
                                    system("cls");
                                    menunya();

                                    }


}

void harga() // menu harga
{
    printf("\n1. 10k\n");
    printf("2. 8k\n");
    printf("3. 12k\n");
    printf("4. 12k\n");
    printf("5. 10k\n");
    printf("6. 20k\n");
    printf("7. 15k\n");
    printf("\nTekan Enter untuk kembali ");
    getch();
    system("cls");
    main();

}

void best() // menu best seller
{
    int pilih;
    char menunya1;
    char no1[]  ="Milk Shake";
    char no2[]  ="Caramel Macchiato";
    char no3[]  ="Matcha Frappe";

    printf("\n1. %s\n",no1);
    printf("2. %s\n",no2);
    printf("3. %s\n",no3);
    printf("\napakah ingin memesan Y/N: ");
    scanf(" %c", &menunya1);


            if(menunya1== 'Y' || menunya1 == 'y')
                {
                printf("\nisi pilihan anda: ");
                scanf("\n%d", &pilih);


                    switch(pilih)
                    {
                    case 1 :
                        system("cls");
                        printf("\nTerima kasih telah membeli %s pesanan anda segera di antarkan ",no1);

                         break;

                    case 2 :
                        system("cls");
                        printf("Terima kasih telah membeli %s pesanan anda segera di antarkan ",no2);
                         break;

                    case 3 :
                        system("cls");
                        printf("Terima kasih telah membeli %s pesanan anda segera di antarkan ",no3);
                        break;

                    default :
                        printf("mohon maaf menu tidak tersedia");
                        getch();
                        system("cls");
                        best();
                    }
                      getch();
                    system("cls");

                }else if (menunya1 == 'N' || menunya1 == 'n')
                {
                    printf("\n Baiklah, silahkan melihat menu-menu lainnya");
                    getch();
                    system("cls");
                    main();
                }

                else
                {
                printf("Mohon maaf menu tidak tersedia  tekan enter untuk mengulang.");
                getch();
                system("cls");
                best();
                }


}

void cabang() // menu cabang
{
    printf("\nBelum ada cabang tersedia \n");
    printf("\n====TEKAN ENTER UNTUK KEMBALI KE MENU==== \n");
    getch();
    system("cls");

}

void menukeluar()
{

    printf("\n              Terima Kasih Telah melihat");
    sleep(2);//tidur dalam 2 detik

    system("cls");

    for(int e = 0; e<=10; e++){
         printf("\n      ==== Kasih nilai yang bagus Kak hehe ^_^ ====");

    }
    sleep(2);
    system("cls");

    printf("\n       walaupun banyak kurangnya mohon maaf");

    sleep(2);
    system("cls");

    printf("\n       Semangat ngajarnya dan kuliahnya Kak %c %c ",2,3); //kode ASCII



}








