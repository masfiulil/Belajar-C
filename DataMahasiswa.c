#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <unistd.h>
#include <windows.h>

#define maks 3
typedef char string[100];
struct data_mahasiswa
{
    string nama;
    string npm;
    string jurusan;
};
data_mahasiswa mhs[50];
int a, b, c, d;

void tambah()
{
    printf("--Jumlah data yang ingin diinput : ");
    scanf("%i", &b);
    d = 0;
    for (c = 0; c < b; c++)
    {
        d = d + 1;
        printf("masukkan npm  :  ");
        scanf("%s", &mhs[a].npm);
        printf("masukkan nama  :  ");
        scanf("%s", &mhs[a].nama);
        printf("masukkan jurusan  :  ");
        scanf("%s", &mhs[a].jurusan);
        a++;
    }
}

void tampil()
{
    int i, j;
    j = 0;
    for (i = 0; i < a; i++)
    {
        printf("data mahasiswa ke--%i\n", i + 1);
        printf("NPM : %s\n", mhs[i].npm);
        printf("Nama : %s\n", mhs[i].nama);
        printf("Jurusan : %s\n", mhs[i].jurusan);
        printf("\n");
    }
}

void npmass(data_mahasiswa total[])
{
    int f, g, min;
    data_mahasiswa temp;
    for (f = 0; f < a; f++)
    {
        min = f;
        for (g = f; g < a; g++)
        {
            if ((strcmp((total + min)->npm, (total + g)->npm)) > 0)
            {
                min = g;
            }
            temp = total[f];
            total[f] = total[min];
            total[min] = temp;
        }
    }
}

void npmdess(data_mahasiswa total[])
{
    int f, g, min;
    data_mahasiswa temp;
    for (f = 0; f < a; f++)
    {
        min = f;
        for (g = f; g < a; g++)
        {
            if ((strcmp((total + min)->npm, (total + g)->npm)) < 0)
            {
                min = g;
            }
            temp = total[f];
            total[f] = total[min];
            total[min] = temp;
        }
    }
}

void namaass(data_mahasiswa total[])
{
    int f, g, min;
    data_mahasiswa temp;
    for (f = 0; f < a; f++)
    {
        min = f;
        for (g = f; g < a; g++)
        {
            if ((strcmp((total + min)->nama, (total + g)->nama)) > 0)
            {
                min = g;
            }
            temp = total[f];
            total[f] = total[min];
            total[min] = temp;
        }
    }
}
void namadess(data_mahasiswa total[])
{
    int f, g, min;
    data_mahasiswa temp;
    for (f = 0; f < a; f++)
    {
        min = f;
        for (g = f; g < a; g++)
        {
            if ((strcmp((total + min)->nama, (total + g)->nama)) < 0)
            {
                min = g;
            }
            temp = total[f];
            total[f] = total[min];
            total[min] = temp;
        }
    }
}

void selectionass(data_mahasiswa total[])
{
    int f, g, min;
    data_mahasiswa temp;
    for (f = 0; f < a; f++)
    {
        for (f = 0; f < a - 1; f++)
        {
            min = f;
            for (g = f + 1; a < g; g++)
                ;
            if ((strcmp((total + min)->npm, (total + g)->npm)) > 0)
            {
                min = g;
                {
                    if (min > g)
                        ;
                    {
                        min = g;
                    }
                }
                temp = total[f];
                total[f] = total[min];
                total[min] = temp;
            }
        }
    }
}

void selectiondess(data_mahasiswa total[])
{
    int f, g, min;
    data_mahasiswa temp;
    for (f = 0; f < a; f++)
    {
        for (f = 0; f < a - 1; f++)
        {
            min = f;
            for (g = f + 1; a < g; g++)
                ;
            if ((strcmp((total + min)->npm, (total + g)->npm)) < 0)
            {
                min = g;
                {
                    if (min > g)
                        ;
                    {
                        min = g;
                    }
                }
                temp = total[f];
                total[f] = total[min];
                total[min] = temp;
            }
        }
    }
}

void insertionass(data_mahasiswa total[])
{
    int f, g, min;
    data_mahasiswa temp;
    for (f = 0; f < a; f++)
    {
        g = f;
        while (g > 0 && (strcmp((total + min)->npm, (total + g)->npm) > 0))
        {
            temp = total[g];
            total[g] = total[g - 1];
            total[g - 1] = temp;
            g--;
        }
    }
}

void insertiondess(data_mahasiswa total[])
{
    int f, g, min;
    data_mahasiswa temp;
    for (f = 0; f < a; f++)
    {
        g = f;
        while (g > 0 && (strcmp((total + min)->npm, (total + g)->npm) < 0))
        {
            temp = total[g];
            total[g] = total[g - 1];
            total[g - 1] = temp;
            g--;
        }
    }
}

void urutdata_bubblesort()
{
    int pilih;
    printf("Masukkan metode pengurutan\n");
    printf("1. npm asscending\n");
    printf("2. npm desscending\n");
    printf("3. nama asscending\n");
    printf("4. nama desscending\n");
    printf("masukkan pilihan : ");
    scanf("%d", &pilih);
    switch (pilih)
    {
    case 1:
        npmass(mhs);
        printf("data sudah diurutkan\n");
        break;
    case 2:
        npmdess(mhs);
        printf("data sudah diurutkan\n");
        break;
    case 3:
        namaass(mhs);
        printf("data sudah diurutkan\n");
        break;
    case 4:
        namadess(mhs);
        printf("data sudah diurutkan\n");
        break;
    }
}

void urutdata_selectionsort()
{
    int pilih;
    printf("Masukkan metode pengurutan\n");
    printf("1. SelectionSort Asscending\n");
    printf("2. SelectionSort Desscending\n");
    printf("masukkan pilihan : ");
    scanf("%d", &pilih);
    switch (pilih)
    {
    case 1:
        selectionass(mhs);
        printf("data sudah diurutkan\n");
        break;
    case 2:
        selectiondess(mhs);
        printf("data sudah diurutkan\n");
        break;
    }
}

void urutdata_insertionsort()
{
    int pilih;
    printf("Masukkan metode pengurutan\n");
    printf("1. InsertionSort Asscending\n");
    printf("2. InsertionSort Desscending\n");
    printf("masukkan pilihan : ");
    scanf("%d", &pilih);
    switch (pilih)
    {
    case 1:
        insertionass(mhs);
        printf("data sudah diurutkan\n");
        break;
    case 2:
        insertiondess(mhs);
        printf("data sudah diurutkan\n");
        break;
    }
}

void exit();

int main()
{
    system("cls");
    do
    {
        system("cls");
        puts("Nama : Masfi Ulil Affandi");
        puts("NPM : 20081010020\n\n");
        puts("Program Data Mahasiswa\n\n");
        puts("1. Tambah Data\n");
        puts("2. Menampilkan Data\n");
        puts("3. Urutan data Metode BubbleSort\n");
        puts("4. Urutan data Metode SelectionSort\n");
        puts("5. Urutan data Metode InsertionSort\n");
        puts("6. Keluar Program\n");
        puts("Pilih salah satu");
        switch (getch())
        {
        case '1':
            tambah();
            break;
        case '2':
            tampil();
            break;
        case '3':
            urutdata_bubblesort();
            break;
        case '4':
            urutdata_selectionsort();
            break;
        case '5':
            urutdata_insertionsort();
            break;
        case '6':
            exit(0);
        }
    } while (getch() != 27);
    return 0;
}
