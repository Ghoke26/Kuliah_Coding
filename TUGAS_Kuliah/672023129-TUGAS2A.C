#include <stdio.h>

int main ()
{
    int e;
        for(e=1; e<=35;  e++)
        {
            //kelipatan tiga dan 5
            if (e % 3 == 0 && e % 5 == 0 )
            {

                printf("kelipatan tiga dan lima \n");
            }
               // kalimat kelipatan 3
                else if (e % 3 == 0)
                {
                    printf("kelipatan tiga\n");
                }
                // kalimat kelipatan 5
                else if (e % 5 == 0)
                {
                printf("kelipatan lima\n");
                }
                // jika tidak kelipatan 3 dan 5 maka hanya angka selain kelipatan 3 dan 5
                else
                {
                printf("%d\n",e );
                }
        }



}



