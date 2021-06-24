#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
// semua header yang diinclude disini dapat dilihat di folder header
#include "header/login.h"
#include "header/menu.h"
#include "header/tes.h"
#include "header/staff_man.h"
#include "header/register.h"
#include "header/keluhan.h"

/*
default user dan admin id dan pass
ID: admin
pass: admin
*/

int main() {										//Main program meminta input login & ada panduan
	load_data();
	system("cls");
	
    int fspage = 0;
    printf("================================	"); printf("\n");
    printf(" BOT PENENTU PENYAKIT PADA BAYI		"); printf("\n");
    printf("================================	"); printf("\n \n");
    printf(" 1. Login    				   		"); printf("\n");
    printf(" 2. Help    				   		"); printf("\n\n");
    printf("================================	"); printf("\n");
    printf(" + Input: "); scanf("%d", &fspage);

    switch(fspage) {

        case 1:										 // jika input 1
            system("cls");
            printf("==================================================="); printf("\n");
            printf("\t\tSTAFF LOGIN    								   "); printf("\n");
            printf("==================================================="); printf("\n");

            if(!login_page(0, "data/staff.txt")) {  // memanggil function login_page di header "login.h", untuk menginput data login
                fflush(stdin);
                printf(" Login Gagal!");
                system("pause");
                main();
            }
            if(1) {                                // jika return 1 maka akan lanjut ke menu utama di function main_menu
				system("cls");
				printf("=====================================================\n\n	");
				printf("	 LOGIN BERHASIL										\n\n");
				printf("=====================================================\n		");
				system("pause");
				main_menu();
            }
            break;
	
        case 2:										// jika input 2, akan ada panduan program
            printf("\n");
            printf("============================================================"); printf("\n");
			printf("                            HELP                            "); printf("\n");
			printf("============================================================"); printf("\n \n");
            printf(" Program ini berfungsi untuk mendiagnosa penyakit\
            \n umum pada bayi.\n");
            printf("============================================================"); printf("\n");
            system("pause");
            system("cls");
            fflush(stdin);
            main();
        
        default :									// error handling jika input selain 1/2
            printf("Masukkan pilihan yang benar!\n");
            system("pause");
            fflush(stdin);
            system("cls");
            main();

    }
}
