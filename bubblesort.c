#include <stdio.h>
//22 10 15 3 8 2
int main()
{
    int angka[6] = {22, 10, 15, 3, 8, 2};
    int i, j, temp;
    int n = 6;
    for (int i = 0; i < n; i++)
    {
        for (j = 0; j < n - 1; j++)
        {
            if (angka[j] > angka[j + 1])
            {
                temp = angka[j];
                angka[j] = angka[j + 1];
                angka[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%i \n", angka[i]);
    }
    return 0;
}