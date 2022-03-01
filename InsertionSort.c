#include <stdio.h>
int main()
{

    int i, j, temp;
    int angka[6] = {22, 10, 15, 3, 8, 2};
    int n = 6;

    for (i = 0; i < n; i++)

        for (i = 1; i < n; i++)
        {
            temp = angka[i];
            j = i - 1;
            while ((temp < angka[j]) && (j >= 0))
            {
                angka[j + 1] = angka[j];
                j = j - 1;
            }
            angka[j + 1] = temp;
        }

    for (i = 0; i < n; i++)
    {
        printf("%i\n", angka[i]);
    }

    return 0;
}