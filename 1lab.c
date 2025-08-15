#include <stdio.h>
#include <math.h>
#define N 20

int main() 
{
    int i, j, g;
    int massive[] = {-6, 71, 99, 2, 13, 82, 56, -160, 23, -203, 469, 439, -233, 2346, 844, 11, -9, 0, -23, 27};
    for (i = 0; i < N; i++)
    {
        for (g = i+1; g < N; g++)
    {
    if ( massive[i] > massive[g] )
    {
        j=massive[i];
        massive[i]=massive[g];
        massive[g]=j;
    }
    }
    printf("%d\n", massive[i]);
    }
    return 0;
}