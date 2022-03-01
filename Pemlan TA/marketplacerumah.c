#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <math.h>

void inputpenjual();
void ubahrumah();
void close();
void hapusrumah();
void lihatpenjual();
void sorttipe();
void sortalamat();
void sortkamtid();
void sortkamdi();
void sortharga();
void cariTIPE();
void cariALAMAT();
void cariHARGA();
void lihatJUAL();
void beliRUMAH();

struct rumah{
    int id,tipe;
    char alamat[60];
    int kamar_mandi;
    int kamar_tidur;
    int lantai;
    double harga;
	char nama[30];
    double NIK;
}rmh, cek, hapus, update[100], del[100], sorts[100], sorts2[100], jual[100], temp;
int min;

void resetMemory(){
    memset(&sorts, 0, sizeof(sorts));
    memset(&sorts2, 0, sizeof(sorts2));
}

void sortingharga(int min, int mid, int maxx){
	int x, y, i = 0;
	for(x = min, y = mid + 1, i = min; x <= mid && y <= maxx; i++){
		if(sorts[x].harga < sorts[y].harga){
			sorts2[i] = sorts[x];
			x++;
		}
		else{
			sorts2[i] = sorts[y];
			y++;
		}
	}
	while(x <= mid){
		sorts2[i] = sorts[x];
		x++;
		i++;
	}
	while(y <= maxx){
		sorts2[i] = sorts[y];
		y++;
		i++;
	}
	for(i = min; i <= maxx; i++){
		sorts[i] = sorts2[i];
	}
}

void mergesortharga(int min, int maxx){
    int mid;
    if(min < maxx){
        mid = (min + maxx)/2;
        mergesortharga(min, mid);
        mergesortharga(mid+1, maxx);
        sortingharga(min, mid, maxx);
    }
    else{
        return;
    }
}

void jumpHarga(struct rumah *sorts, int total, double cariharga){
    int jump = sqrt(total);
    int jumper = jump;
    int prev = 0, simpan;
    int i, flag = 0;

    if((cariharga < sorts[0].harga) || (cariharga > sorts[total].harga)){
        printf("\n==> Harga tidak ditemukan!");
        return;
    }
    else{
        while((sorts[jumper].harga <= cariharga) && jumper < total){
            prev = jumper;
            jumper += jump;
            
            if(jumper >= total + total){
                printf("Harga Not Found!");
            }
        }

        for(i = prev; i <= jumper; i++){
            if(sorts[i].harga == cariharga){
                flag = 1;
                simpan = i;
            }
        }

        if(flag == 1){
            printf("%d\t%d\t%s\t%d\t%d\t%d\t%.lf \n", sorts[simpan].id, sorts[simpan].tipe, sorts[simpan].alamat, sorts[simpan].kamar_tidur , sorts[simpan].kamar_mandi, sorts[simpan].lantai, sorts[simpan].harga);
        }
        else{
            printf("Hargaa Not Found!");
        }
    }
}

int main(){
    int pilih;
    menu:

    system("cls");
        printf("\n ======   PERUMAHAN TADIKA MESRA    ======\n");
        printf("\n[1] Penjual");
        printf("\n[2] Pembeli");
        printf("\n\n ==> Masukkan Pilihan : ");
        scanf("%d", &pilih);
        if(pilih == 1){
            penjual:
            system("cls");
            printf("\n ======   PERUMAHAN TADIKA MESRA    ======\n");
            printf("\n[1] Input Rumah");
            printf("\n[2] Lihat Rumah");
            printf("\n[3] Ubah Rumah");
            printf("\n[4] Hapus Rumah");
            printf("\n[5] Lihat Urut");
            printf("\n[6] Cari Rumah");
            printf("\n[7] Lihat Rumah Terjual");
            printf("\n[0] Exit");
            printf("\n\n ==> Masukkan Pilihan : ");
            scanf("%d", &pilih);
            if(pilih == 1){
                inputpenjual();
                goto menu;
            }
            else if(pilih == 2){
                lihatpenjual();
            }
            else if(pilih == 3){
                ubahrumah();
            }
            else if(pilih == 4){
                hapusrumah();
            }
            else if(pilih == 5){
                system("cls");
                printf("\n ======   PERUMAHAN TADIKA MESRA    ======\n");
                printf("\n[1] Urut Tipe");
                printf("\n[2] Urut Alamat");
                printf("\n[3] Urut Kamar Tidur");
                printf("\n[4] Urut Kamar Mandi");
                printf("\n[5] Urut Harga");
                printf("\n[0] Exit");
                printf("\n\n ==> Masukkan Pilihan : ");
                scanf("%d", &pilih);
                if(pilih == 1){
                    sorttipe();
                }
				else if(pilih == 2){
					sortalamat();
				}
				else if(pilih == 3){
					sortkamtid();
				}
				else if(pilih == 4){
					sortkamdi();
				}
				else if(pilih == 5){
					sortharga();
				}
                else{
                    goto penjual;
                }
            }
			else if(pilih == 6){
				system("cls");
                printf("\n ======   PERUMAHAN TADIKA MESRA    ======\n");
                printf("\n[1] Cari Tipe");
                printf("\n[2] Cari Alamat");
                printf("\n[3] Cari Harga");
                printf("\n[0] Exit");
                printf("\n\n ==> Masukkan Pilihan : ");
                scanf("%d", &pilih);
                if(pilih == 1){
                    cariTIPE();
                }
                else if(pilih == 2){
                    cariALAMAT();
                }
                else if(pilih == 3){
                    cariHARGA();
                }
                else if(pilih == 0){
                    exit(0);
                }
                else{
                    goto penjual;
                }
			}
            else if(pilih == 7){
                lihatJUAL();
            }
            else if(pilih == 0){
                exit(0);
            }
        }
        else if(pilih == 2){
			pembeli:
            system("cls");
            printf("\n ======   PERUMAHAN TADIKA MESRA    ======\n");
            printf("\n[1] Lihat Rumah");
            printf("\n[2] Lihat Urut");
            printf("\n[3] Cari Rumah");
            printf("\n[4] Beli Rumah");
            printf("\n[0] Exit");
            printf("\n\n ==> Masukkan Pilihan : ");
            scanf("%d", &pilih);
			if(pilih == 1){
				lihatpenjual();
			}
			else if(pilih == 2){
				 system("cls");
                printf("\n ======   PERUMAHAN TADIKA MESRA    ======\n");
                printf("\n[1] Urut Tipe");
                printf("\n[2] Urut Alamat");
                printf("\n[3] Urut Kamar Tidur");
                printf("\n[4] Urut Kamar Mandi");
                printf("\n[5] Urut Harga");
                printf("\n[0] Exit");
                printf("\n\n ==> Masukkan Pilihan : ");
                scanf("%d", &pilih);
                if(pilih == 1){
                    sorttipe();
                }
				else if(pilih == 2){
					sortalamat();
				}
				else if(pilih == 3){
					sortkamtid();
				}
				else if(pilih == 4){
					sortkamdi();
				}
				else if(pilih == 5){
					sortharga();
				}
                else{
                    goto pembeli;
                }
			}
			else if(pilih == 3){
                system("cls");
                printf("\n ======   PERUMAHAN TADIKA MESRA    ======\n");
                printf("\n[1] Cari Tipe");
                printf("\n[2] Cari Alamat");
                printf("\n[3] Cari Harga");
                printf("\n[0] Exit");
                printf("\n\n ==> Masukkan Pilihan : ");
                scanf("%d", &pilih);
                if(pilih == 1){
                    cariTIPE();
                }
                else if(pilih == 2){
                    cariALAMAT();
                }
                else if(pilih == 3){
                    cariHARGA();
                }
                else if(pilih == 0){
                    exit(0);
                }
                else{
                    goto pembeli;
                }
            }
			else if(pilih == 4){
                beliRUMAH();
            }
			else if(pilih == 0){
				exit(0);
			}
        }
		else{
			printf("Input Salah!");
			erase_valid:
		    printf("\nInput 1 untuk ke menu utama and 0 untuk keluar :");
            switch(getch()){
                case '1': 
                    main();
                    break;
                case '0': 
                    close();
                    break;
                default:printf("\nMaaf Kesalahan Input !");
                    getche();
                    goto erase_valid;
            }
		}
}

void inputpenjual(){
    FILE *fptr, *fptr1;
    int count=0;
    
    fptr=fopen("TADIKAMESRA.txt","a");
    system("cls");
    fptr1=fopen("TADIKAMESRA.txt","r");
    while (fscanf(fptr1,"%d %d %[^;]; %d %d %d %lf",&rmh.id,&rmh.tipe,rmh.alamat,&rmh.kamar_tidur,&rmh.kamar_mandi, &rmh.lantai, &rmh.harga)!=EOF)
		{
			rmh.id++;	
		}
		cek.id = rmh.id;
		fclose(fptr1);
		printf("\n ======   PERUMAHAN TADIKA MESRA    ======\n");
		printf ("\nMasukan Tipe Rumah	: ");fflush(stdin);
		scanf ("%d", &rmh.tipe);
		printf ("\nMasukan Alamat		: ");fflush(stdin);
		gets(rmh.alamat);
		printf("\nJumlah Kamar Tidur	: ");fflush(stdin);
		scanf("%d", &rmh.kamar_tidur);
        printf("\nJumlah Kamar Mandi	: ");
		scanf("%d", &rmh.kamar_mandi);
        printf("\nJumlah Lantai Rumah	: ");
		scanf("%d", &rmh.lantai);
        printf("\nHarga Total Bangunan	: ");
		scanf("%lf", &rmh.harga);
		fprintf(fptr,"%d %d %s; %d %d %d %lf \n",rmh.id,rmh.tipe,rmh.alamat,rmh.kamar_tidur,rmh.kamar_mandi,rmh.lantai,rmh.harga);
		fclose(fptr);
		printf("\n\nData Telah Disimpan !");
		add_invalid:
		printf("\n\n\tEnter 1 untuk menu utama dan 0 untuk keluar : ");
		switch(getch()){
    		case '1': 
				main();
        		break;
        	case '0': 
				close();
        		break;
        	default:printf("\nMaaf Kesalahan Input !");
        		getche();
        		goto add_invalid;
 		}
}

void lihatpenjual(){
	system("cls");
    FILE *view;
	int test=0;
	view=fopen("TADIKAMESRA.txt","r");
	printf("\n================   PERUMAHAN TADIKA MESRA    ================\n\n");
	printf("%s\t%s\t%s\t\t%s\t%s\t%s\t%s \n\n", "ID","Tipe", "Alamat", "K.Tidur", "K.Mandi", "Lantai", "Harga");
	while(fscanf(view,"%d %d %[^;]; %d %d %d %lf",&rmh.id, &rmh.tipe, rmh.alamat, &rmh.kamar_tidur ,&rmh.kamar_mandi, &rmh.lantai, &rmh.harga)!=EOF)
		{
			printf("%d\t%d\t%s\t%d\t%d\t%d\t%.lf \n", rmh.id, rmh.tipe, rmh.alamat, rmh.kamar_tidur ,rmh.kamar_mandi, rmh.lantai, rmh.harga);
			test++;
		}
	printf("\n");
	printf("\nBanyak Rumah Yang Tersedia : %d ", test);
	fclose(view);
		if(test==0)
	{
		system("cls");
		printf ("\nData Kosong ! \n");
	}
	list_invalid:
    printf("\n\nEnter 1 untuk menu utama dan 0 untuk keluar : ");
    switch(getch()){
    	case '1': main();
        	break;
        case '0': close();
        	break;
        default:printf("\nMaaf Kesalahan Input !");
        	getche();
        	goto list_invalid;
 	}
}

void close(){
}

void ubahrumah(){
    int pilih,test=0, count = 0, i = 0, j;
	FILE *lama,*baru;
	lama = fopen("TADIKAMESRA.txt","r");
	baru = fopen("TADIKABARU.txt","w");
	system("cls");
	printf("\n ======   PERUMAHAN TADIKA MESRA    ======\n");
	printf ("\nMasukan ID Rumah Yang Akan Diubah : ");
	scanf ("%d",&cek.id);
	while(fscanf(lama, "%d %d %[^;]; %d %d %d %lf",&rmh.id, &rmh.tipe, rmh.alamat, &rmh.kamar_tidur ,&rmh.kamar_mandi, &rmh.lantai, &rmh.harga)!=EOF){
		update[count].tipe = rmh.tipe;
		update[count].kamar_mandi = rmh.kamar_mandi;
		update[count].kamar_tidur = rmh.kamar_tidur;
		update[count].id = rmh.id;
		update[count].harga = rmh.harga;
		update[count].lantai = rmh.lantai;
		strcpy(update[count].alamat ,rmh.alamat);
		count++;
	}

	while(i <= count){
		if(update[i].id == cek.id){
			test=1;
			ganti:
				system("cls");
				printf("\n ======   PERUMAHAN TADIKA MESRA    ======\n");
				printf("\nRUMAH DENGAN ID : %d AKAN DIUPDATE!", update[i].id);
				printf("\n\nData yang akan diganti : ");
				printf("\n[1] Tipe");
				printf("\n[2] Alamat");
				printf("\n[3] Kamar Tidur");
                printf("\n[4] Kamar Mandi");
                printf("\n[5] Lantai Bangunan");
                printf("\n[6] Harga Rumah");
				printf("\nInput Pilihan : ");
				scanf("%d",&pilih);
				
				if(pilih == 1){
					printf ("\nMasukan Tipe Rumah	: ");fflush(stdin);
					scanf ("%d", &cek.tipe);
					update[i].tipe = cek.tipe;
					for(j = 0; j < count; j++){
						fprintf(baru, "%d %d %s; %d %d %d %lf \n",update[j].id, update[j].tipe ,update[j].alamat,update[j].kamar_tidur,update[j].kamar_mandi,update[j].lantai,update[j].harga);
					}
					printf ("\nPerubahan Sudah Disimpan !");
					break;
				}
				else if(pilih == 2){
					printf("\nMasukan Alamat Rumah	: ");fflush(stdin);
					gets(cek.alamat);
					strcpy(update[i].alamat, cek.alamat);
					for(j = 0; j < count; j++){
						fprintf(baru, "%d %d %s; %d %d %d %lf \n",update[j].id, update[j].tipe ,update[j].alamat,update[j].kamar_tidur,update[j].kamar_mandi,update[j].lantai,update[j].harga);
					}
					printf ("\nPerubahan Sudah Disimpan !");
					break;
				}
				else if(pilih == 3){
					printf ("\nMasukan Kamar Tidur	: ");fflush(stdin);
					scanf ("%d", &cek.kamar_tidur);
					update[i].kamar_tidur = cek.kamar_tidur;
					for(j = 0; j < count; j++){
						fprintf(baru, "%d %d %s; %d %d %d %lf \n",update[j].id, update[j].tipe ,update[j].alamat,update[j].kamar_tidur,update[j].kamar_mandi,update[j].lantai,update[j].harga);
					}
					printf ("\nPerubahan Sudah Disimpan !");
					break;
				}
				else if(pilih == 4){
					printf ("\nMasukan Kamar Mandi	: ");fflush(stdin);
					scanf ("%d", &cek.kamar_mandi);
					update[i].kamar_mandi = cek.kamar_mandi;
					for(j = 0; j < count; j++){
						fprintf(baru, "%d %d %s; %d %d %d %lf \n",update[j].id, update[j].tipe ,update[j].alamat,update[j].kamar_tidur,update[j].kamar_mandi,update[j].lantai,update[j].harga);
					}
					printf ("\nPerubahan Sudah Disimpan !");
					break;
				}
				else if(pilih == 5){
					printf ("\nMasukan Lantai Rumah	: ");fflush(stdin);
					scanf ("%d", &cek.lantai);
					update[i].lantai = cek.lantai;
					for(j = 0; j < count; j++){
						fprintf(baru, "%d %d %s; %d %d %d %lf \n",update[j].id, update[j].tipe ,update[j].alamat,update[j].kamar_tidur,update[j].kamar_mandi,update[j].lantai,update[j].harga);
					}
					printf ("\nPerubahan Sudah Disimpan !");
					break;
				}
				else if(pilih == 6){
					printf ("\nMasukan Harga Rumah	: ");fflush(stdin);
					scanf ("%lf", &cek.harga);
					update[i].harga = cek.harga;
					for(j = 0; j < count; j++){
						fprintf(baru, "%d %d %s; %d %d %d %lf \n",update[j].id, update[j].tipe ,update[j].alamat,update[j].kamar_tidur,update[j].kamar_mandi,update[j].lantai,update[j].harga);
					}
					printf ("\nPerubahan Sudah Disimpan !");
					break;
				}
				else{
					printf("\n\nInput Anda Salah !");
                    printf("\nKlik Enter untuk mengulang");
                    getche();
				}
		}
		else if(cek.id > sizeof(rmh) || cek.id < update[0].id){
			for(j = 0; j < count; j++){
				fprintf(baru, "%d %d %s; %d %d %d %lf \n",update[j].id, update[j].tipe ,update[j].alamat,update[j].kamar_tidur,update[j].kamar_mandi,update[j].lantai,update[j].harga);
			}
			break;
		}
        else if(cek.id != update[i].id && i == count){
            for(j = 0; j < count; j++){
				fprintf(baru, "%d %d %s; %d %d %d %lf \n",update[j].id, update[j].tipe ,update[j].alamat,update[j].kamar_tidur,update[j].kamar_mandi,update[j].lantai,update[j].harga);
			}
			break;
        }
		else{
			i++;
		}
	}

	memset(&update, 0, sizeof(update));
	fclose(lama);
	fclose(baru);
	remove("TADIKAMESRA.txt");
	rename("TADIKABARU.txt","TADIKAMESRA.txt");
	if(test!=1){   
		system("cls");
        printf("\nData tidak ditemukan !\a\a\a");
        edit_invalid:
        printf("\nInput 0 untuk mencoba lagi, 1 untuk ke menu utama dan 2 untuk keluar :");
        switch(getch()){
            case '0': ubahrumah();
            	break;
            case '1': main();
            	break;
            case '2': close();
            	break;
            default:printf("\nMaaf Kesalahan Input !");
            	getche();
            	goto edit_invalid;
        }
    }
    else{
    	edit_valid:
		printf("\n\n\nInput 1 untuk ke menu utama, 2 untuk update lagi, dan 0 untuk keluar :");
        switch(getch()){
        	case '1': main();
        		break;
			case '2': ubahrumah();
				break;
        	case '0': close();
        		break;
        	default:printf("\nMaaf Kesalahan Input !");
        		getche();
        		goto edit_valid;
        }
    }
}

void hapusrumah(){
    FILE *lama, *baru;
    int test=0, count = 0;
    lama = fopen("TADIKAMESRA.txt","r");
	baru = fopen("TADIKABARU.txt","w");
    system("cls");
    printf("Input No.Id Rumah yang mau dihapus : ");
    scanf("%d", &hapus.id);
    while(fscanf(lama,"%d %d %[^;]; %d %d %d %lf",&rmh.id, &rmh.tipe, rmh.alamat, &rmh.kamar_tidur ,&rmh.kamar_mandi, &rmh.lantai, &rmh.harga)!=EOF){
        if(rmh.id != hapus.id){
            del[count].id = rmh.id;
            del[count].tipe = rmh.tipe;
            strcpy(del[count].alamat, rmh.alamat);
            del[count].kamar_tidur = rmh.kamar_tidur;
            del[count].kamar_mandi = rmh.kamar_mandi;
            del[count].lantai = rmh.lantai;
            del[count].harga = rmh.harga;
            fprintf(baru,"%d %d %s; %d %d %d %lf\n",del[count].id, del[count].tipe, del[count].alamat, del[count].kamar_tidur, del[count].kamar_mandi, del[count].lantai, del[count].harga);
            count++;
        }
        else{
            test++;
            printf("\nData Rumah No ID : %d dengan Alamat : %s\n",rmh.id,rmh.alamat);
			printf("\nBerhasil dihapus dari Daftar !");
            count++;
        }
    }
    memset(&del, 0, sizeof(del));
    fclose(lama);
	fclose(baru);
	remove("TADIKAMESRA.txt");
	rename("TADIKABARU.txt","TADIKAMESRA.txt");
	if(test==0){   
		system("cls");
        printf("\nData tidak ditemukan !\a\a\a");
        edit_invalid:
        printf("\nInput 0 untuk mencoba lagi, 1 untuk ke menu utama dan 2 untuk keluar :");
        switch(getch()){
            case '0': hapusrumah();
            	break;
            case '1': main();
            	break;
            case '2': close();
            	break;
            default:printf("\nMaaf Kesalahan Input !");
            	getche();
            	goto edit_invalid;
        }
    }else{
    	edit_valid:
		printf("\n\n\nInput 1 untuk ke menu utama, 2 hapus lagi, dan 0 untuk keluar :");
        switch(getch()){
        	case '1': main();
        		break;
            case '2': hapusrumah();
                break;
        	case '0': close();
        		break;
        	default:printf("\nMaaf Kesalahan Input !");
        		getche();
        		goto edit_valid;
        }
    }
}

void sorttipe(){
	system("cls");
	FILE *sortdata;
	int count=0,i,j,test=0,pilih;
	system("cls");
	sortdata=fopen("TADIKAMESRA.txt","r");
	while(fscanf(sortdata,"%d %d %[^;]; %d %d %d %lf",&rmh.id, &rmh.tipe, rmh.alamat, &rmh.kamar_tidur ,&rmh.kamar_mandi, &rmh.lantai, &rmh.harga)!=EOF) {
		sorts[count].tipe = rmh.tipe;
		sorts[count].kamar_mandi = rmh.kamar_mandi;
		sorts[count].kamar_tidur = rmh.kamar_tidur;
		sorts[count].id = rmh.id;
		sorts[count].harga = rmh.harga;
		sorts[count].lantai = rmh.lantai;
		strcpy(sorts[count].alamat ,rmh.alamat);
		count++;
		test=1;
	}	
	
	printf("\n================   PERUMAHAN TADIKA MESRA    ================\n\n");
	printf("%s\t%s\t%s\t\t%s\t%s\t%s\t%s \n\n", "ID","Tipe", "Alamat", "K.Tidur", "K.Mandi", "Lantai", "Harga");
	for(i = 0; i < count; i++){
		for(j = i + 1; j < count; j++){
			if(sorts[i].tipe > sorts[j].tipe){
				temp = sorts[j];
				sorts[j] = sorts[i];
				sorts[i] = temp;
			}
		}
	}
	for(i=0;i<count;i++){
		printf("%d\t%d\t%s\t%d\t%d\t%d\t%.lf \n", sorts[i].id, sorts[i].tipe, sorts[i].alamat, sorts[i].kamar_tidur ,sorts[i].kamar_mandi, sorts[i].lantai, sorts[i].harga);
	}
	
    resetMemory();
	fclose(sortdata);
	if(test==0){
            printf("\nData tidak ditemukan !\a\a\a");
            erase_invalid:
            printf("\nInput 0 untuk mencoba lagi, 1 untuk ke menu utama and 2 untuk keluar :");
			switch(getch()){
            	case '0': 
					sorttipe();
            		break;
            	case '1': 
					main();
            		break;
            	case '2': 
					close();
            		break;
            	default:printf("\nMaaf Kesalahan Input !");
            		getche();
            		goto erase_invalid;
			}
    } else {
    	erase_valid:
		printf("\nInput 1 untuk ke menu utama and 0 untuk keluar :");
        switch(getch()){
       		case '1': 
			   	main();
       			break;
       		case '0': 
			   	close();
       			break;
       		default:printf("\nMaaf Kesalahan Input !");
        		getche();
        		goto erase_valid;
        }
    }

}

void sortalamat(){
	system("cls");
	FILE *alamat;
	int count=0,i,j,test=0,pilih;
	system("cls");
	alamat=fopen("TADIKAMESRA.txt","r");
	while(fscanf(alamat,"%d %d %[^;]; %d %d %d %lf",&rmh.id, &rmh.tipe, rmh.alamat, &rmh.kamar_tidur ,&rmh.kamar_mandi, &rmh.lantai, &rmh.harga)!=EOF) {
		sorts[count].tipe = rmh.tipe;
		sorts[count].kamar_mandi = rmh.kamar_mandi;
		sorts[count].kamar_tidur = rmh.kamar_tidur;
		sorts[count].id = rmh.id;
		sorts[count].harga = rmh.harga;
		sorts[count].lantai = rmh.lantai;
		strcpy(sorts[count].alamat ,rmh.alamat);
		count++;
		test=1;
	}	

	for(i = 1; i <= count; i++){
		sorts2[i] = sorts[i];
    	j = i - 1;
        while(j >= 0 && (strcmp(sorts[j].alamat, sorts2[i].alamat) > 0)){
                sorts[j+1] = sorts[j];
                j--;
        }
		sorts[j+1] = sorts2[i];
    }
	printf("\n================   PERUMAHAN TADIKA MESRA    ================\n\n");
	printf("%s\t%s\t%s\t\t%s\t%s\t%s\t%s \n\n", "ID","Tipe", "Alamat", "K.Tidur", "K.Mandi", "Lantai", "Harga");
	for(i = 1; i <= count; i++){
		printf("%d\t%d\t%s\t%d\t%d\t%d\t%.lf \n", sorts[i].id, sorts[i].tipe, sorts[i].alamat, sorts[i].kamar_tidur ,sorts[i].kamar_mandi, sorts[i].lantai, sorts[i].harga);
	}

    resetMemory();
	fclose(alamat);
	if(test==0){
            printf("\nData tidak ditemukan !\a\a\a");
            erase_invalid:
            printf("\nInput 0 untuk mencoba lagi, 1 untuk ke menu utama and 2 untuk keluar :");
			switch(getch()){
            	case '0': 
					sortalamat();
            		break;
            	case '1': 
					main();
            		break;
            	case '2': 
					close();
            		break;
            	default:printf("\nMaaf Kesalahan Input !");
            		getche();
            		goto erase_invalid;
			}
    } else {
    	erase_valid:
		printf("\nInput 1 untuk ke menu utama and 0 untuk keluar :");
        switch(getch()){
       		case '1': 
			   	main();
       			break;
       		case '0': 
			   	close();
       			break;
       		default:printf("\nMaaf Kesalahan Input !");
        		getche();
        		goto erase_valid;
        }
    }
}

void sortkamtid(){
	system("cls");
	FILE *sorttidur;
	int count=0,i,j,test=0;
	system("cls");
	sorttidur=fopen("TADIKAMESRA.txt","r");
	while(fscanf(sorttidur,"%d %d %[^;]; %d %d %d %lf",&rmh.id, &rmh.tipe, rmh.alamat, &rmh.kamar_tidur ,&rmh.kamar_mandi, &rmh.lantai, &rmh.harga)!=EOF) {
		sorts[count].tipe = rmh.tipe;
		sorts[count].kamar_mandi = rmh.kamar_mandi;
		sorts[count].kamar_tidur = rmh.kamar_tidur;
		sorts[count].id = rmh.id;
		sorts[count].harga = rmh.harga;
		sorts[count].lantai = rmh.lantai;
		strcpy(sorts[count].alamat ,rmh.alamat);
		count++;
		test=1;
	}	

	for(i = 1; i <= count; i++){
		sorts2[i] = sorts[i];
    	j = i - 1;
        while(j >= 0 && sorts[j].kamar_tidur > sorts2[i].kamar_tidur){
                sorts[j+1] = sorts[j];
                j--;
        }
		sorts[j+1] = sorts2[i];
    }
	printf("\n================   PERUMAHAN TADIKA MESRA    ================\n\n");
	printf("%s\t%s\t%s\t\t%s\t%s\t%s\t%s \n\n", "ID","Tipe", "Alamat", "K.Tidur", "K.Mandi", "Lantai", "Harga");
	for(i = 1; i <= count; i++){
		printf("%d\t%d\t%s\t%d\t%d\t%d\t%.lf \n", sorts[i].id, sorts[i].tipe, sorts[i].alamat, sorts[i].kamar_tidur ,sorts[i].kamar_mandi, sorts[i].lantai, sorts[i].harga);
	}

    resetMemory();
	fclose(sorttidur);
	if(test==0){
            printf("\nData tidak ditemukan !\a\a\a");
            erase_invalid:
            printf("\nInput 0 untuk mencoba lagi, 1 untuk ke menu utama and 2 untuk keluar :");
			switch(getch()){
            	case '0': 
					sortkamtid();
            		break;
            	case '1': 
					main();
            		break;
            	case '2': 
					close();
            		break;
            	default:printf("\nMaaf Kesalahan Input !");
            		getche();
            		goto erase_invalid;
			}
    } else {
    	erase_valid:
		printf("\nInput 1 untuk ke menu utama and 0 untuk keluar :");
        switch(getch()){
       		case '1': 
			   	main();
       			break;
       		case '0': 
			   	close();
       			break;
       		default:printf("\nMaaf Kesalahan Input !");
        		getche();
        		goto erase_valid;
        }
    }
}

void sortkamdi(){
	system("cls");
	FILE *kamandi;
	int count=0,i,j,min,test=0;
	system("cls");
	kamandi=fopen("TADIKAMESRA.txt","r");
	while(fscanf(kamandi,"%d %d %[^;]; %d %d %d %lf",&rmh.id, &rmh.tipe, rmh.alamat, &rmh.kamar_tidur ,&rmh.kamar_mandi, &rmh.lantai, &rmh.harga)!=EOF) {
		sorts[count].tipe = rmh.tipe;
		sorts[count].kamar_mandi = rmh.kamar_mandi;
		sorts[count].kamar_tidur = rmh.kamar_tidur;
		sorts[count].id = rmh.id;
		sorts[count].harga = rmh.harga;
		sorts[count].lantai = rmh.lantai;
		strcpy(sorts[count].alamat ,rmh.alamat);
		count++;
		test=1;
	}	

	for(i = 0; i <= count; i++){
    	min = i;
        for(j = 1+i; j <= count; j++){
			if(sorts[j].kamar_mandi < sorts[min].kamar_mandi){
				min = j;
			}
        }
		sorts2[i] = sorts[i];
		sorts[i] = sorts[min];
		sorts[min] = sorts2[i];
    }
	printf("\n================   PERUMAHAN TADIKA MESRA    ================\n\n");
	printf("%s\t%s\t%s\t\t%s\t%s\t%s\t%s \n\n", "ID","Tipe", "Alamat", "K.Tidur", "K.Mandi", "Lantai", "Harga");
	for(i = 1; i <= count; i++){
		printf("%d\t%d\t%s\t%d\t%d\t%d\t%.lf \n", sorts[i].id, sorts[i].tipe, sorts[i].alamat, sorts[i].kamar_tidur ,sorts[i].kamar_mandi, sorts[i].lantai, sorts[i].harga);
	}

    resetMemory();
	fclose(kamandi);
	if(test==0){
            printf("\nData tidak ditemukan !\a\a\a");
            erase_invalid:
            printf("\nInput 0 untuk mencoba lagi, 1 untuk ke menu utama and 2 untuk keluar :");
			switch(getch()){
            	case '0': 
					sortkamdi();
            		break;
            	case '1': 
					main();
            		break;
            	case '2': 
					close();
            		break;
            	default:printf("\nMaaf Kesalahan Input !");
            		getche();
            		goto erase_invalid;
			}
    } else {
    	erase_valid:
		printf("\nInput 1 untuk ke menu utama and 0 untuk keluar :");
        switch(getch()){
       		case '1': 
			   	main();
       			break;
       		case '0': 
			   	close();
       			break;
       		default:printf("\nMaaf Kesalahan Input !");
        		getche();
        		goto erase_valid;
        }
    }
}

void sortharga(){
	system("cls");
	FILE *hargaa;
	int count=0,i,j,test=0,pilih;
	system("cls");
	hargaa=fopen("TADIKAMESRA.txt","r");
	while(fscanf(hargaa,"%d %d %[^;]; %d %d %d %lf",&rmh.id, &rmh.tipe, rmh.alamat, &rmh.kamar_tidur ,&rmh.kamar_mandi, &rmh.lantai, &rmh.harga)!=EOF) {
		sorts[count].tipe = rmh.tipe;
		sorts[count].kamar_mandi = rmh.kamar_mandi;
		sorts[count].kamar_tidur = rmh.kamar_tidur;
		sorts[count].id = rmh.id;
		sorts[count].harga = rmh.harga;
		sorts[count].lantai = rmh.lantai;
		strcpy(sorts[count].alamat ,rmh.alamat);
		count++;
		test=1;
	}	

	mergesortharga(0, count);
	
	printf("\n================   PERUMAHAN TADIKA MESRA    ================\n\n");
	printf("%s\t%s\t%s\t\t%s\t%s\t%s\t%s \n\n", "ID","Tipe", "Alamat", "K.Tidur", "K.Mandi", "Lantai", "Harga");
	for(i = 1; i <= count; i++){
		printf("%d\t%d\t%s\t%d\t%d\t%d\t%.lf \n", sorts[i].id, sorts[i].tipe, sorts[i].alamat, sorts[i].kamar_tidur ,sorts[i].kamar_mandi, sorts[i].lantai, sorts[i].harga);
	}
    resetMemory();
	fclose(hargaa);
	if(test==0){
            printf("\nData tidak ditemukan !\a\a\a");
            erase_invalid:
            printf("\nInput 0 untuk mencoba lagi, 1 untuk ke menu utama and 2 untuk keluar :");
			switch(getch()){
            	case '0': 
					sortharga();
            		break;
            	case '1': 
					main();
            		break;
            	case '2': 
					close();
            		break;
            	default:printf("\nMaaf Kesalahan Input !");
            		getche();
            		goto erase_invalid;
			}
    } else {
    	erase_valid:
		printf("\nInput 1 untuk ke menu utama and 0 untuk keluar :");
        switch(getch()){
       		case '1': 
			   	main();
       			break;
       		case '0': 
			   	close();
       			break;
       		default:printf("\nMaaf Kesalahan Input !");
        		getche();
        		goto erase_valid;
        }
    }
}

void cariTIPE(){
    system("cls");
	FILE *cartip;
	int count=0,i,j = 0,test=0, caritipe, flag = 0;
	system("cls");
	cartip=fopen("TADIKAMESRA.txt","r");
	while(fscanf(cartip,"%d %d %[^;]; %d %d %d %lf",&rmh.id, &rmh.tipe, rmh.alamat, &rmh.kamar_tidur ,&rmh.kamar_mandi, &rmh.lantai, &rmh.harga)!=EOF) {
		sorts[count].tipe = rmh.tipe;
		sorts[count].kamar_mandi = rmh.kamar_mandi;
		sorts[count].kamar_tidur = rmh.kamar_tidur;
		sorts[count].id = rmh.id;
		sorts[count].harga = rmh.harga;
		sorts[count].lantai = rmh.lantai;
		strcpy(sorts[count].alamat ,rmh.alamat);
        count++;
		test=1;
	}
    int simpan[count];	
	
	printf("==============   PENCARIAN DATA   =============\n\n");
    printf("\nMasukkan TIPE yang Dicari : ");
    scanf("%d", &caritipe);
	
    for(i = 0; i < count; i++){
        if(sorts[i].tipe == caritipe){
            simpan[j] = i;
            flag = 1;
            j++;
        }
    }
    printf("\n%s\t%s\t%s\t\t%s\t%s\t%s\t%s \n\n", "ID","Tipe", "Alamat", "K.Tidur", "K.Mandi", "Lantai", "Harga");
    if(flag == 1){
        for(i = 0; i <= j-1; i++){
            printf("%d\t%d\t%s\t\t%d\t%d\t%d\t%.lf \n", sorts[simpan[i]].id, sorts[simpan[i]].tipe, sorts[simpan[i]].alamat, sorts[simpan[i]].kamar_tidur , sorts[simpan[i]].kamar_mandi, sorts[simpan[i]].lantai, sorts[simpan[i]].harga);
        }
    }
    else{
        printf("Data Tipe Not Found!");
    }
	
    resetMemory();
	fclose(cartip);
	if(test==0){
            printf("\nData tidak ditemukan !\a\a\a");
            erase_invalid:
            printf("\nInput 0 untuk mencoba lagi, 1 untuk ke menu utama and 2 untuk keluar :");
			switch(getch()){
            	case '0': 
					cariTIPE();
            		break;
            	case '1': 
					main();
            		break;
            	case '2': 
					close();
            		break;
            	default:printf("\nMaaf Kesalahan Input !");
            		getche();
            		goto erase_invalid;
			}
    }
    else {
    	erase_valid:
		printf("\nInput 1 untuk ke menu utama, 2 untuk coba lagi, and 0 untuk keluar :");
        switch(getch()){
       		case '1': 
			   	main();
       			break;
            case '2':
                cariTIPE();
                break;
       		case '0': 
			   	close();
       			break;
       		default:printf("\nMaaf Kesalahan Input !");
        		getche();
        		goto erase_valid;
        }
    }
}

void cariALAMAT(){
    system("cls");
	FILE *alamatt;
	int count=0,i,j,test=0;
    char carialamat[60];
	system("cls");
	alamatt = fopen("TADIKAMESRA.txt","r");
	while(fscanf(alamatt,"%d %d %[^;]; %d %d %d %lf",&rmh.id, &rmh.tipe, rmh.alamat, &rmh.kamar_tidur ,&rmh.kamar_mandi, &rmh.lantai, &rmh.harga)!=EOF) {
		sorts[count].tipe = rmh.tipe;
		sorts[count].kamar_mandi = rmh.kamar_mandi;
		sorts[count].kamar_tidur = rmh.kamar_tidur;
		sorts[count].id = rmh.id;
		sorts[count].harga = rmh.harga;
		sorts[count].lantai = rmh.lantai;
		strcpy(sorts[count].alamat ,rmh.alamat);
		count++;
		test=1;
	}	

	for(i = 1; i <= count; i++){
		sorts2[i] = sorts[i];
    	j = i - 1;
        while(j >= 0 && (strcmp(sorts[j].alamat, sorts2[i].alamat) > 0)){
                sorts[j+1] = sorts[j];
                j--;
        }
		sorts[j+1] = sorts2[i];
    }
	
    fflush(stdin);
    printf("==============   PENCARIAN DATA   =============\n\n");
    printf("\nMasukkan Alamat yang Dicari : ");
    gets(carialamat);
    int mid, low = 0, flag =0, high = count;
    while(low <= high && flag == 0){
        mid = (low + high)/2;
        if((strcmp(sorts[mid].alamat, carialamat) == 0)){
            flag = 1;
        }
        else if((strcmp(carialamat, sorts[mid].alamat) > 0)){
            high = high;
            low = mid + 1;
        }
        else{
            low = low;
            high = mid - 1;
        }
    }
    printf("\n%s\t%s\t%s\t\t%s\t%s\t%s\t%s \n\n", "ID","Tipe", "Alamat", "K.Tidur", "K.Mandi", "Lantai", "Harga");
    if(flag == 1){
        printf("%d\t%d\t%s\t\t%d\t%d\t%d\t%.lf \n", sorts[mid].id, sorts[mid].tipe, sorts[mid].alamat, sorts[mid].kamar_tidur , sorts[mid].kamar_mandi, sorts[mid].lantai, sorts[mid].harga);
    }
    else{
        printf("Data Alamat Rumah Not Found!");
    }

    resetMemory();
	fclose(alamatt);
	if(test==0){
            printf("\nData tidak ditemukan !\a\a\a");
            erase_invalid:
            printf("\nInput 0 untuk mencoba lagi, 1 untuk ke menu utama and 2 untuk keluar :");
			switch(getch()){
            	case '0': 
					cariALAMAT();
            		break;
            	case '1': 
					main();
            		break;
            	case '2': 
					close();
            		break;
            	default:printf("\nMaaf Kesalahan Input !");
            		getche();
            		goto erase_invalid;
			}
    }
    else{
    	erase_valid:
		printf("\nInput 1 untuk ke menu utama, 2 coba lagi, and 0 untuk keluar :");
        switch(getch()){
       		case '1': 
			   	main();
       			break;
            case '2':
                cariALAMAT();
                break;
       		case '0': 
			   	close();
       			break;
       		default:printf("\nMaaf Kesalahan Input !");
        		getche();
        		goto erase_valid;
        }
    }
}

void cariHARGA(){
    system("cls");
	double cariharga;
	FILE *hargaaa;
	int count=0,i,j,pilih;
	system("cls");
	hargaaa=fopen("TADIKAMESRA.txt","r");
	while(fscanf(hargaaa,"%d %d %[^;]; %d %d %d %lf",&rmh.id, &rmh.tipe, rmh.alamat, &rmh.kamar_tidur ,&rmh.kamar_mandi, &rmh.lantai, &rmh.harga)!=EOF) {
		sorts[count].tipe = rmh.tipe;
		sorts[count].kamar_mandi = rmh.kamar_mandi;
		sorts[count].kamar_tidur = rmh.kamar_tidur;
		sorts[count].id = rmh.id;
		sorts[count].harga = rmh.harga;
		sorts[count].lantai = rmh.lantai;
		strcpy(sorts[count].alamat ,rmh.alamat);
		count++;
	}	
	mergesortharga(0, count);
    printf("==============   PENCARIAN DATA   =============\n\n");
    printf("\nMasukkan Harga yang Dicari : ");
    scanf("%lf", &cariharga);
    printf("\n%s\t%s\t%s\t\t%s\t%s\t%s\t%s \n\n", "ID","Tipe", "Alamat", "K.Tidur", "K.Mandi", "Lantai", "Harga");
	jumpHarga(sorts, count, cariharga);
    resetMemory();
	fclose(hargaaa);
    if(count == 0){
            printf("\nData tidak ditemukan !\a\a\a");
            erase_invalid:
            printf("\nInput 0 untuk mencoba lagi, 1 untuk ke menu utama and 2 untuk keluar :");
			switch(getch()){
            	case '0': 
					cariHARGA();
            		break;
            	case '1': 
					main();
            		break;
            	case '2': 
					close();
            		break;
            	default:printf("\nMaaf Kesalahan Input !");
            		getche();
            		goto erase_invalid;
			}
    } else {
    	erase_valid:
		printf("\nInput 1 untuk ke menu utama, 2 untuk ulang, and 0 untuk keluar :");
        switch(getch()){
       		case '1': 
			   	main();
       			break;
            case '2':
                cariHARGA();
                break;
       		case '0': 
			   	close();
       			break;
       		default:printf("\nMaaf Kesalahan Input !");
        		getche();
        		goto erase_valid;
        }
    }
}

void lihatJUAL(){
    system("cls");
    FILE *lihatjual;
	int test=0;
	lihatjual = fopen("TADIKAJUAL.txt","r");
	printf("\n================   PERUMAHAN TADIKA MESRA    ================\n\n");
	printf("%s\t%s\t%s\t\t%s\t%s\t%s\t%s\t%s\t\t%s \n\n", "ID","Tipe", "Alamat", "K.Tidur", "K.Mandi", "Lantai", "Harga", "Nama", "NIK");
	while(fscanf(lihatjual,"%d %d %[^;]; %d %d %d %lf %[^;]; %lf",&rmh.id, &rmh.tipe, rmh.alamat, &rmh.kamar_tidur ,&rmh.kamar_mandi, &rmh.lantai, &rmh.harga, rmh.nama, &rmh.NIK)!=EOF){
            printf("%d\t%d\t%s\t%d\t%d\t%d\t%.lf\t%s\t%.lf\n", rmh.id, rmh.tipe, rmh.alamat, rmh.kamar_tidur ,rmh.kamar_mandi, rmh.lantai, rmh.harga, rmh.nama, rmh.NIK);
            test++;
		}
	printf("\n");
	printf("\nBanyak Rumah Yang Terjual : %d ", test);
	fclose(lihatjual);

    memset(&rmh, 0, sizeof(rmh));
	if(test==0){
		system("cls");
		printf ("\nData Kosong ! \n");
	}
	list_invalid:
    printf("\n\nEnter 1 untuk menu utama dan 0 untuk keluar : ");
    switch(getch()){
    	case '1': main();
        	break;
        case '0': close();
        	break;
        default:printf("\nMaaf Kesalahan Input !");
        	getche();
        	goto list_invalid;
 	}
}

void beliRUMAH(){
    FILE *lama, *baru, *jual;
    int test=0, count = 0;
    lama = fopen("TADIKAMESRA.txt","r");
	baru = fopen("TADIKABARU.txt","w");
    jual = fopen("TADIKAJUAL.txt", "a");
    system("cls");
    printf("=============== BELI RUMAH ===============\n\n");
    printf("Input No.Id Rumah yang akan dibeli : ");
    scanf("%d", &hapus.id);
    while(fscanf(lama,"%d %d %[^;]; %d %d %d %lf",&rmh.id, &rmh.tipe, rmh.alamat, &rmh.kamar_tidur ,&rmh.kamar_mandi, &rmh.lantai, &rmh.harga)!=EOF){
        if(rmh.id != hapus.id){
            del[count].id = rmh.id;
            del[count].tipe = rmh.tipe;
            strcpy(del[count].alamat, rmh.alamat);
            del[count].kamar_tidur = rmh.kamar_tidur;
            del[count].kamar_mandi = rmh.kamar_mandi;
            del[count].lantai = rmh.lantai;
            del[count].harga = rmh.harga;
            fprintf(baru,"%d %d %s; %d %d %d %lf\n",del[count].id, del[count].tipe, del[count].alamat, del[count].kamar_tidur, del[count].kamar_mandi, del[count].lantai, del[count].harga);
            count++;
        }
        else if(rmh.id == hapus.id){
            fflush(stdin);
            printf("\nMasukkan Nama : ");
            gets(del[count].nama);
            printf("\nMasukkan NIK  : ");
            scanf("%lf", &del[count].NIK);
            del[count].id = rmh.id;
            del[count].tipe = rmh.tipe;
            strcpy(del[count].alamat, rmh.alamat);
            del[count].kamar_tidur = rmh.kamar_tidur;
            del[count].kamar_mandi = rmh.kamar_mandi;
            del[count].lantai = rmh.lantai;
            del[count].harga = rmh.harga;
            fprintf(jual,"%d %d %s; %d %d %d %lf %s; %lf\n",del[count].id, del[count].tipe, del[count].alamat, del[count].kamar_tidur, del[count].kamar_mandi, del[count].lantai, del[count].harga, del[count].nama, del[count].NIK);
            count++;
            test++;
            printf("Rumah Telah Dibeli!");
		}
        else{
            test++;
            printf("\nData Rumah No ID : %d dengan Alamat : %s\n",rmh.id,rmh.alamat);
			printf("\nBerhasil dihapus dari Daftar !");
            count++;
        }
    }
    memset(&del, 0, sizeof(del));
    fclose(jual);
    fclose(lama);
	fclose(baru);
	remove("TADIKAMESRA.txt");
	rename("TADIKABARU.txt","TADIKAMESRA.txt");
	if(test==0){   
		system("cls");
        printf("\nData tidak ditemukan !\a\a\a");
        edit_invalid:
        printf("\nInput 0 untuk mencoba lagi, 1 untuk ke menu utama dan 2 untuk keluar :");
        switch(getch()){
            case '0': beliRUMAH();
            	break;
            case '1': main();
            	break;
            case '2': close();
            	break;
            default:printf("\nMaaf Kesalahan Input !");
            	getche();
            	goto edit_invalid;
        }
    }else{
    	edit_valid:
		printf("\n\n\nInput 1 untuk ke menu utama, 2 beli lagi, dan 0 untuk keluar :");
        switch(getch()){
        	case '1': main();
        		break;
            case '2': beliRUMAH();
                break;
        	case '0': close();
        		break;
        	default:printf("\nMaaf Kesalahan Input !");
        		getche();
        		goto edit_valid;
        }
    }
}