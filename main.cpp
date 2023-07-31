#include <stdio.h>
#include <cstring>

int main()
{
    printf("Input array index: ");
    int MXN = 100;
    int ara[MXN] = {1, 2, 3, 4, 5};

    printf("Displaying integers: ");
    for (int i = 0; i < MXN; i++)
    {
        printf("%d ", ara[i]);
    }
    memset(ara, 0, sizeof ara);
    return 0;
}