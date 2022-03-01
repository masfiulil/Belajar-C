#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

struct perpustakaan
{
    char judul [25];
    char pengarang[25];
    int kode;
    int konvert_string;
}data_buku[10];

void interpolation();
void jumpsearch();

int main()
{
    data_buku[0].kode = 3031;
    strcpy(data_buku[0].judul, "C Programming");
    strcpy(data_buku[0].pengarang,"James Lee");

    data_buku[1].kode = 101;
    strcpy(data_buku[1].judul, "Wordpress Expert");
    strcpy(data_buku[1].pengarang,"Andrew Octa");

    data_buku[2].kode = 8812;
    strcpy(data_buku[2].judul, "Web From Zero to Hero");
    strcpy(data_buku[2].pengarang,"David Guetta");

    data_buku[3].kode = 790;
    strcpy(data_buku[3].judul, "Laravel");
    strcpy(data_buku[3].pengarang,"Hans Jackson");

    data_buku[4].kode = 66;
    strcpy(data_buku[4].judul, "Master Flutter");
    strcpy(data_buku[4].pengarang,"Ozur Haskels");

    data_buku[5].kode = 111;
    strcpy(data_buku[5].judul, "Codelgniter 4 the Guide");
    strcpy(data_buku[5].pengarang,"Gantz Patrick");

    data_buku[6].kode = 678;
    strcpy(data_buku[6].judul,"Raspberry Pi 4");
    strcpy(data_buku[6].pengarang,"Tony Watts");

    data_buku[7].kode = 901;
    strcpy(data_buku[7].judul,"Building Robotic AI");
    strcpy(data_buku[7].pengarang,"Leni Imelda");

    data_buku[8].kode = 303;
    strcpy(data_buku[8].judul,"Data Science");
    strcpy(data_buku[8].pengarang,"Ranya Sundar");

    data_buku[9].kode = 4089;
    strcpy(data_buku[9].judul,"Go Lang Introduction");
    strcpy(data_buku[9].pengarang,"Brian Macakzie");

    int pilih;
    printf("Nama : Masfi Ulil Affandi\n");
    printf("NPM : 20081010020\n");
    printf("Kelas : D081\n");
    printf("-----------------------------\n");
    printf("Data Buku\n");
    printf("Judul Buku & Kode buku :\n");
    printf("- C Programming (3031)\n"
            "- Wordpress Expert (101)\n"
            "- Web From Zero to Hero (8812)\n"
            "- Laravel (709)\n"
            "- Master Flutter (66)\n"
            "- Codelgniter 4 the Guide (111)\n"
            "- Raspberry Pi 4 (678)\n"
            "- Building Robotic AI (901)\n"
            "- Data Science (303)\n"
            "- Go Lang Introduction (4089)\n");
    printf("-----------------------------\n");
    printf("Pilih Metode pencarian\n");
    printf("1. interpolation search\n");
    printf("2. jump search\n");
    printf("Masukkan nomor pilihan anda : ");
    scanf("%i",&pilih);
    switch (pilih)
    {
    case 1:
        interpolation();
        break;
    case 2:
        jumpsearch();
        break;
    default:
        printf("Input yang anda ketika salah");
        break;
    }
    return 0;
}

void interpolation(){
    int g, h, i, j;
    int a = sizeof(data_buku)/sizeof(data_buku[0]);
    int length[a];
    for ( i = 0; i < a; i++){
        length[i] = strlen(data_buku[i].judul);
        
        for ( j = 0; j < length[i]; j++){
            data_buku[i].konvert_string += data_buku[i].judul[j];
        }
        printf("%d\n",data_buku[i].konvert_string);
    }
    
    char string_cari[50];
    int konvert_string = 0;
    printf("Masukkan Judul Buku yang ingin dicari : ");
    fflush(stdin); gets(string_cari);

    int  panjang = strlen(string_cari);
    for ( i = 0; i < panjang; i++){
        konvert_string += string_cari[i];
    }

    for ( g = 0; g < 10; g++){
        int temp;
        temp = data_buku[g].konvert_string;
        h = g-1;
            while (h>=0 && data_buku[h].konvert_string > temp){
                data_buku[h+1].konvert_string = data_buku[h].konvert_string;
                h = h-1;
            }
        data_buku[h+1].konvert_string = temp;
    }

    int low = 0;
    int high = a - 1;
    int position;

    while (low <= high){

        position = low+(((konvert_string-data_buku[low].konvert_string)/(data_buku[high].konvert_string-data_buku[low].konvert_string))*(high-low));

        if(data_buku[position].konvert_string == konvert_string){
            printf("Data Tersedia\n");
            break;
        }else if(data_buku[position].konvert_string > konvert_string){
            high = position - 1;
        }else{
            low = position + 1;
        }
    }
}


void jumpsearch(){
    int cari;
    printf("Masukkan Kode Buku yang dicari : ");
    scanf("%d", &cari);

    int i,j;
    int length = sizeof(data_buku)/sizeof(data_buku[0]);
    int jump = sqrt(length);

    for ( i = 0; i < 10; i++){
        int temp;
        temp = data_buku[i].kode;
        j = i-1;
            while (j>=0 && data_buku[j].kode > temp){
                data_buku[j+1].kode = data_buku[j].kode;
                j = j-1;
            }
        data_buku[j+1].kode = temp;
    }

    int prev = 0;
    while (data_buku[jump].kode <= cari && jump < length){
        prev = jump;
        jump+=jump;

        if (jump >= length+1){
            printf("Data tidak ketemu\n");
        }
    }
    int status = 0;
    for (int i = prev; i <= jump; i++){
        if (data_buku[i].kode == cari){
            status = 1;
            printf("Data %d ditemukan pada elemen ke-%d",cari,i);
        }
    }
}
