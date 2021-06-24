//Shaniya Camita Farin 2006534865
/* 
header ini berisikan menu dari program
*/
void panduan();

int main_menu(){
	/* 
	function main_menu adalah tampilan utama untuk user berinteraksi dengan program
	disini user dapat memilih salah satu dari beberapa pilihan yang ada untuk menambahkan,
	mengurangkan, dan melihat list pasien.
	*/

    system("cls");	// membersihkan console
    fflush(stdin);	// membersihkan standard input
	int input;
	
	printf("=====================================================\n\n");
	printf("	  		MENU			\n\n");
	printf("	1. LAKUKAN TES			\n");
	printf("	2. DATA PASIEN			\n");
	printf("	3. HITUNG PASIEN		\n");
	printf("	4. HAPUS DATA			\n");
	printf("	5. MANAGE STAFF			\n");
	printf("	6. PANDUAN				\n");
	printf("	7. KELUAR				\n\n");
	printf("=====================================================\n\n");	
	
	printf("	INPUT: "); 
	scanf("%d", &input);
	
	switch(input){
		case 1:
			tes();
			break;
		
		case 2:
			list_pasien();
			break;

		case 3:
			hitung_pasien();
			break;

		case 4:
			hapus_pasien();
			break;
		
		case 5:
			manage_staff();
			break;
		
		case 6:
			panduan();
			break;
		
		case 7:
			exit(1);
			break;
			
		default: {
			printf("MASUKKAN PILIHAN YANG BENAR!");
            system("pause");
            fflush(stdin);
            system("cls");
            main();
		}
	}
	
	return 0;
}

void panduan(){
	system("cls");
  	printf("============================================================"); printf("\n");
	printf("                            HELP                            "); printf("\n");
	printf("============================================================"); printf("\n \n");
	printf(" 1. Silahkan pilih menu yang anda lakukan	\n");
	printf(" 2. Pilih menu 1 untuk melakukan tes pada keluhan anda			\n");
	printf(" 3. Pilih menu 2 untuk mengisi data identitas diri pasien			\n");
	printf(" 4. Pilih menu 3 untuk menghitung pasien yang sudah terdaftar		\n");
	printf(" 5. Pilih menu 4 untuk menghapus data pasien			\n");
	printf(" 6. Pilih menu 5 KHUSUS UNTUK STAFF untuk mengubah data pada staff			\n");
	printf(" 7. Pilih menu 7 untuk keluar dari prgoram		\n\n");
	printf("============================================================"); printf("\n");
	system("pause");
	system("cls");
	fflush(stdin);
	main_menu();
}
