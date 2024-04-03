#include <stdio.h>
#include <stdlib.h>

int main()
{
 for(int i =2;i <= 20; i+=2)
    {
        if(i==14 || i==18)
        {
        continue;
        }
        printf("\n=============================\n");
        printf("INI ANGKA: %d ",i);


    }
    return 0;
}
