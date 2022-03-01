#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>


struct buku{

    char judul[50];
    char pengarang[50];
    int kode_buku;
    int convert_string;

}data_buku[10];

void JumpSearch();
void InterpolationSearch();

int main(){

    //Data Buku 1
    strcpy(data_buku[0].judul,"C Programming");
    strcpy(data_buku[0].pengarang,"James Lee");
    data_buku[0].kode_buku = 3031;
    //Data Buku 2
    strcpy(data_buku[1].judul,"Wordpress Expert");
    strcpy(data_buku[1].pengarang,"Andrew Octa");
    data_buku[1].kode_buku = 101;
    //Data Buku 3
    strcpy(data_buku[2].judul,"Web From Zero to Hero");
    strcpy(data_buku[2].pengarang,"David Guetta");
    data_buku[2].kode_buku = 8812;
    //Data Buku 4
    strcpy(data_buku[3].judul,"Laravel");
    strcpy(data_buku[3].pengarang,"Hans Jackson");
    data_buku[3].kode_buku = 790;
    //Data Buku 5
    strcpy(data_buku[4].judul,"Master Flutter");
    strcpy(data_buku[4].pengarang,"Ozur Haskels");
    data_buku[4].kode_buku = 66;
    //Data Buku 6
    strcpy(data_buku[5].judul,"Codelgniter 4 the Guide");
    strcpy(data_buku[5].pengarang,"Gantz Patrick");
    data_buku[5].kode_buku = 111;
    //Data Buku 7
    strcpy(data_buku[6].judul,"Raspberry Pi 4");
    strcpy(data_buku[6].pengarang,"Tony Watts");
    data_buku[6].kode_buku = 678;
    //Data Buku 8
    strcpy(data_buku[7].judul,"Building Robotic AI");
    strcpy(data_buku[7].pengarang,"Leni Imelda");
    data_buku[7].kode_buku = 901;
    //Data Buku 9
    strcpy(data_buku[8].judul,"Data Science");
    strcpy(data_buku[8].pengarang,"Ranya Sundar");
    data_buku[8].kode_buku = 303;
    //Data Buku 10
    strcpy(data_buku[9].judul,"Go Lang Introduction");
    strcpy(data_buku[9].pengarang,"Brian Macakzie");
    data_buku[9].kode_buku = 4089;

    int pilih;
    printf("Masukkan Pilihan Anda : ");
    scanf("%i",&pilih);
    switch (pilih){
    case 1:

        JumpSearch();
        break;
    
    case 2:
        
        InterpolationSearch();
        break;
    
    default:
        printf("Inputan anda salah!\n");
        break;
    }

    return 0;
}

void JumpSearch(){
    
    int cari;
    printf("Masukkan Kode Buku yang ingin dicari : ");
    scanf("%d", &cari);

    int c,d;
    int length = sizeof(data_buku)/sizeof(data_buku[0]);
    int jump = sqrt(length);

    for ( c = 0; c < 10; c++){
        int temp;
        temp = data_buku[c].kode_buku;
        d = c-1;
            while (d>=0 && data_buku[d].kode_buku > temp){
                data_buku[d+1].kode_buku = data_buku[d].kode_buku;
                d = d-1;
            }
        data_buku[d+1].kode_buku = temp;
    }

    int prev = 0;
    while (data_buku[jump].kode_buku <= cari && jump < length){
        prev = jump;
        jump+=jump;

        if (jump >= length+1){
            printf("Data tidak ketemu\n");
        }
    }
    
    int status = 0;
    for (int i = prev; i <= jump; i++){
        if (data_buku[i].kode_buku == cari){
            status = 1;
            printf("Data %d ditemukan pada elemen ke-%d",cari,i);
        }
    }
    
}

void InterpolationSearch(){
    
    int i,c,d,j;
    int a = sizeof(data_buku)/sizeof(data_buku[0]);
    int length[a];
    for ( i = 0; i < a; i++){
        length[i] = strlen(data_buku[i].judul);
        
        for ( j = 0; j < length[i]; j++){
            data_buku[i].convert_string += data_buku[i].judul[j];
        }
        printf("%d\n",data_buku[i].convert_string);
    }
    
    char string_cari[50];
    int convert_string = 0;
    printf("Masukkan Judul Buku yang ingin dicari : ");
    fflush(stdin); gets(string_cari);

    int  panjang = strlen(string_cari);
    for ( i = 0; i < panjang; i++){
        convert_string += string_cari[i];
    }

    for ( c = 0; c < 10; c++){
        int temp;
        temp = data_buku[c].convert_string;
        d = c-1;
            while (d>=0 && data_buku[d].convert_string > temp){
                data_buku[d+1].convert_string = data_buku[d].convert_string;
                d = d-1;
            }
        data_buku[d+1].convert_string = temp;
    }

    int low = 0;
    int high = a - 1;
    int position;

    while (low <= high){

        position = low+(((convert_string-data_buku[low].convert_string)/(data_buku[high].convert_string-data_buku[low].convert_string))*(high-low));

        if(data_buku[position].convert_string == convert_string){
            printf("Data Ketemu\n");
            break;
        }else if(data_buku[position].convert_string > convert_string){
            high = position - 1;
        }else{
            low = position + 1;
        }

    }
}