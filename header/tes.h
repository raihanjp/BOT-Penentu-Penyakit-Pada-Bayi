/* 
header ini berisikan tentang pengolahan data pasien
didalam sistem
*/

//linked list untuk menyimpan data pasien.
struct Pasien {
	char nama[255];
	char gender[10];
	int tanggal;
	int bulan;
	int tahun;
	char status_pasien[50];
	struct Pasien *next;
};

typedef struct Pasien ptr;
typedef ptr *pasien;

pasien head=NULL;
	
int tes(){
	
	/* 
	fungsi ini berfungsi untuk menambahkan pasien baru kedalam sistem
	pasien yang di input datanya disini akan disimpan dalam sebuah text file
	yang nantinya dapat diakses kembali untuk memperbarui status pasien
	*/
	
	pasien temp;
	pasien jalan;

	system("cls");	// membersihkan console
	
	char nama[255], *jenis_kelamin, *status_pasien;
	int hari_lahir, bulan_lahir, tahun_lahir;
	int input_jk, input_stat, jenis_keluhan;
	
	printf("==========================="); printf("\n");
	printf("  Pendaftaran Pasien Baru  "); printf("\n");
	printf("==========================="); printf("\n \n");
	
	// Input Nama pasien
	fflush(stdin);
	printf(" Nama: "); scanf("%[^\n]s", nama);
	
	// input jenis kelamin pasien
	gender:
	printf("\n 1. Pria\n 2. Wanita\n");
	printf(" Jenis Kelamin: "); scanf("%d", &input_jk);
	switch(input_jk) {
		case 1: jenis_kelamin = "Pria"; break;
			
		case 2: jenis_kelamin = "Wanita"; break;
			
		default: fflush(stdin); printf(" Input Jenis Kelamin salah! Mohon Ulangi.");
		system("pause");
		goto gender;
	}
	
	// input tanggal lahir pasien
	printf("\n Tanggal Lahir:\n");
	hari:
	printf(" Tanggal (1-31): "); scanf("%d", &hari_lahir);
	if(hari_lahir>=1 && hari_lahir<=31) goto bulan; else goto hari;
	bulan:
	printf(" Bulan (1-12): "); scanf("%d", &bulan_lahir);
	if(bulan_lahir>=1 && bulan_lahir<=12) goto tahun; else goto bulan;
	tahun:
	printf(" Tahun (XXXX): "); scanf("%d", &tahun_lahir);
	
	system("cls");
	status_pasien = keluhan(&status_pasien); //mengambil data status pasien dari function keluhan().
	system("pause");			 //terdapat dalam header keluhan.h
	system("cls");
	
	// pengecekan ulang data pasien
	printf("\n========PENGECEKAN=========\n");
	
	printf(" Nama		: %s\n", nama);
	printf(" Jenis Kelamin  : %s\n", jenis_kelamin);
	printf(" Tanggal Lahir  : %d-%d-%d\n", hari_lahir, bulan_lahir, tahun_lahir);
	printf(" Status		: %s\n", status_pasien);

	char confm;
	printf("\n Apakah data sudah benar?(Y/N) "); scanf(" %c", &confm);
	//jika ya, maka lanjut ke if
	if(confm == 'y' || confm == 'Y') {
		temp= malloc(sizeof(struct Pasien));
		//copy data input dari variabel ke linked list
		strcpy(temp->nama, nama);
		strcpy(temp->gender, jenis_kelamin);
		strcpy(temp->status_pasien, status_pasien);
		temp->bulan=bulan_lahir;
		temp->tanggal=hari_lahir;
		temp->tahun=tahun_lahir;
		temp->next=NULL;
		if(head == NULL){
			head = temp;
		}
		else {
			jalan = head;
			while(1){
	            // kalau sudah bertemu akhir dari node linked list
				if(jalan->next == NULL){
					jalan->next = temp;
					break;
				}
				else{
					jalan = jalan->next;
				}		
		   	}
		}		
		save_data();	//function untuk menyimpan data. terdapat di header tes.h
		fflush(stdin);
		
		inputpasien:
		printf("\n Ingin input data pasien lagi?(Y/N) "); scanf(" %c", &confm);
		
		//jika user ingin memasukkan data kembali
		if(confm == 'y' || confm == 'Y') {
			tes(); //kembali ke function tes
		}
		//jika user tidak ingin memasukkan data kembali
		else if(confm == 'n' || confm == 'N') {
			main_menu(); // kembali ke menu

		}
		else { //error handling jika user memasukkan nilai yang tidak sesuai
			printf("\nMohon masukkan pilihan yang benar!");
			goto inputpasien;
		}
	} 
	//jika data yang telah dimasukkan terdapat salah, maka user memilih 'N'
	else if(confm == 'n' || confm == 'N') {
		printf("\n Mohon Masukkan Ulang Seluruh Data Pasien Dengan Benar!");
		system("pause");
		tes();

	}

	else { //error handling jika user memasukkan input yang tidak sesuai
		printf("\n Input yang dimasukkan salah! Mohon Ulangi Kembali!");
		system("pause");
		tes();

	}
}

int list_pasien() {
	/*
	fungsi ini berfungsi untuk menampilkan seluruh list pasien yang ada
	dalam sistem. data yang ditampilkan akan berupa nama, jenis kelamin,
	dan status penyakit yang diderita
	*/
	int line=0;
	pasien temp;
	system("cls");
	fflush(stdin);
	temp = head;
	while(temp!=NULL){
		printf("\n======================================\n");		
		printf("       	Pasien ke-%d       		\n", line+1); 
		printf("======================================  \n");
		printf(" Nama: %s				\n", temp->nama);
		printf(" Jenis Kelamin: %s	 	   	\n", temp->gender);
		printf(" Tanggal Lahir: %d-%d-%d   		\n", temp->tanggal, temp->bulan, temp->tahun);
		printf(" Status: %s				\n", temp->status_pasien);
		line++;		
		temp = temp->next;
	}
	
	fflush(stdin);
	system("pause");
        main_menu(); 	// kembali ke function main_menu() yang terdapat dalam header menu.h
}

int hapus_pasien(){
     /*
     fungsi ini berfungsi untuk menghapus data pasien yang ada
     kemudian akan menyimpan data terbaru di file pasien.txt
     */
    system("cls");
    char string_pasien[255], string_temp[255];
    char *str1, *str2;
    char *stripped;
    int choice;
    int line = 0, i = 0;
    int flag = 0;
    char temp_nama[255];
	
	printf("Masukkan nama pasien yang ingin dihapus: ");
	fflush(stdin); scanf("%[^\n]s", temp_nama);
	
	 pasien temp = head;
	 pasien sebelum;
	 pasien sesudah;
	
	while (temp != NULL) {
	        if(strcmpi(temp_nama,temp->nama) == 0) {
	            printf("\nPasien %s telah dihapus dari database!\n", temp->nama);
	            flag = 1;
	            if (temp == head) 
	            {
	                sesudah = temp->next;
	                head = sesudah;
	            }
	            else {
	                sesudah = temp->next;
	                sebelum->next = sesudah;
	            }
	        }
	        sebelum = temp;
	        temp = temp->next;
	    }
    if(flag == 0){
        printf("\nPasien %s tidak ada\n", temp_nama);
    }	
    save_data(); //melakukan save data dengan memanggil function save_data(). function terdapat dalam header tes.h
    system("pause");
    main_menu(); //kembali ke main_menu() yang terdapat dalam header menu.h
}

int load_data(){
	/*
	function untuk memuat data yang terdapat dalam file handling pasien.txt
	*/
	int count=0,i;
	char line;
	pasien temp;
	pasien jalan;
	FILE *fp = fopen("data/pasien.txt", "r");		// membuka FILE pasien.txt
	
	 while(!feof(fp)){
            line = fgetc(fp);
            if(line == '\n'){ //count jumlah data dalam file.
                count++;
            }
        }
        fclose(fp);
        
    fp = fopen("data/pasien.txt", "r");
    
    for(i=0;i<count;i++){
    	temp = malloc(sizeof(struct Pasien));
	//membaca data dalam file pasien.txt kemudian dimasukkan ke linked list
    	fscanf(fp, "%[^\t]\t%[^\t]\t%d\t%d\t%d\t%[^\n]\n", temp->nama, temp->gender, &temp->tanggal, &temp->bulan, &temp->tahun, temp->status_pasien);
	temp->next=NULL; 
	if(head == NULL){
		head = temp;
	}
	else {
		jalan = head;
		while(1){
		//kalau sudah bertemu akhir dari node linked list
			if(jalan->next == NULL){
				jalan->next = temp;
				break;
			}
			else{
				jalan = jalan->next;
			}	
		}
	}		
     }
     fclose(fp);	
}

int save_data(){
	/*
	function untuk menyimpan data dari linked list ke file handling
	*/
	FILE *fp;
	pasien temp = head;
	fp = fopen("data/pasien.txt", "w");
	while(1){
		if(temp!=NULL){
    			fprintf(fp, "%s\t%s\t%d\t%d\t%d\t%s\n", temp->nama, temp->gender, temp->tanggal, temp->bulan, temp->tahun, temp->status_pasien);
		}
		else{
			break;
		}
   		temp = temp->next;			
	}
	fclose(fp);
}

int hitung_pasien(){
    /*
    function untuk menghitung jumlah pasien yang terdapat di linked list.
    perhitungan dilakukan menggunakan metode parallel programming.
    */
    int i,sum = 0;
    system("cls");
    printf("=============================\n");
    printf("=         JUMLAH PASIEN     =\n");
    printf("=============================\n\n");
    pasien current;
    current = head;

    #pragma omp parallel
    {
        current = head;
        #pragma omp master
        {
            while (current){
            #pragma omp task firstprivate(current)
            {
                #pragma omp critical
                sum ++;
            }
            current = current->next;
            }
        }
    }
    printf("\nJumlah pasien: %d pasien\n\n", sum);	
    system("pause");
    system("cls");
    main_menu(); //kembali ke menu utama yang terdapat di header menu.h
}
