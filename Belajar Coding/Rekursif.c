#include <stdio.h>

int PangkatIterasi(int a, int b)
{
    int hasil = 1;
    for (int i = 1; i <= b; i++)
    {
        hasil = hasil * a;
    }
    return hasil;
}
int PangkatRekursif(int a, int b)
{
    if (b == 0)
    {
        return 1;
    }
    else
    {
        return a * PangkatRekursif(a, (b - 1));
    }
}
int main()
{
    int a, b;
    printf("Masukkan angka :");
    scanf("%i", &a);
    printf("masukkan pangkat :");
    scanf("%i", &b);
    printf("Hasil Iterasi : %i\n", PangkatIterasi(a, b));
    printf("Hasil Rekursif : %i", PangkatRekursif(a, b));

    return 0;
}