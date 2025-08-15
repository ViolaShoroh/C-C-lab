#include <stdio.h>
#include <string.h>
#define N 7

char mas[N][20]; 

int main() 
{
    int i, j;
    
    strcpy(mas[0], "Ночь,");
    strcpy(mas[1], "ледяная");
    strcpy(mas[2], "рябь");
    strcpy(mas[3], "канала,");
    strcpy(mas[4], "Аптека,");
    strcpy(mas[5], "улица,");
    strcpy(mas[6], "фонарь.");
    

    for(i = 0; i < N-1; i++)
    {
        for(j = 0; j < N-i-1; j++)
        {
            if(strcmp(mas[j], mas[j+1]) > 0)
            {
                char temp[20];
                strcpy(temp, mas[j]);
                strcpy(mas[j], mas[j+1]);
                strcpy(mas[j+1], temp);
            }
        }
    }
    

    for(i = 0; i < N; i++)
    {
        printf("%s\n", mas[i]);
    }
    
    return 0;
}