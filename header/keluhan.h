//Shaniya Camita Farin 2006534865
/*
Header ini berisikan tentang gejala-gejala yang mungkin terjadi pada pasien,
yang kemudian akan ditanyakan pada user. Metode penentuan indikasi penyakit
menggunakan metode depth first search. Output dari function keluhan ini berupa
status pasien sesuai dengan pertanyaan yang telah dijawab sebelumnya.
*/
int keluhan(char *status_pasien){
	int q=0;
	
	//line 10-69 berisi list pertanyaan
	char g1[]="Apakah bayi mengalami ruam merah gelap yang tidak memudar\noleh tekanan?\n1. Ya\n2. Tidak\nJawab: ", 
		 g2[]="Apakah bayi menolak makan selama lebih dari 3 jam\n(pada bayi berusia di bawah 3 bulan) atau\nlebih dari 6 jam (pada bayi berusia di atas 3 bulan)?\n1. Ya\n2. Tidak\nJawab: ",
		 g3[]="Apakah bayi mengalami demam?\n1. Ya\n2. Tidak\nJawab: ",
		 g4[]="Apakah bayi mengalami muntah?\n1. Ya\n2. Tidak\nJawab: ",
		 g5[]="Apakah berat badan bayi surut tanpa penyebab yang jelas?\n1. Ya\n2. Tidak\nJawab: ",
		 g6[]="Apakah bayi sering kehausan?\n1. Ya\n2. Tidak\nJawab: ",
		 g7[]="Apakah bayi mengalami nyeri saat buang air kecil?\n1. Ya\n2. Tidak\nJawab: ",
		 g8[]="Apakah bayi sering buang air kecil?\n1. Ya\n2. Tidak\nJawab: ",
		 g9[]="Apakah urin bayi keruh atau berbau menyengat?\n1. Ya\n2. Tidak\nJawab: ",
		 g10[]="Apakah bayi mengeluh sakit perut dan menangis\nsambil menarik-narik kakinya?\n1. Ya\n2. Tidak\nJawab: ",
		 g11[]="Apakah bayi mengalami kantuk yang tidak wajar?\n1. Ya\n2. Tidak\nJawab: ",
		 g12[]="Apakah bayi mengalami mata cekung dan/atau kulit kering?\n1. Ya\n2. Tidak\nJawab: ",
		 g13[]="Apakah tinja bayi hitam atau bercak darah?\n1. Ya\n2. Tidak\nJawab: ",
		 g14[]="Apakah bayi mengalami gelisah?\n1. Ya\n2. Tidak\nJawab: ",
		 g15[]="Apakah bayi menangis berkepanjangan dan sulit\nuntuk menenangkannya agar mau tidur?\n1. Ya\n2. Tidak\nJawab: ",
		 g16[]="Apakah bayi menangis dengan cara yang tidak biasa?\n1. Ya\n2. Tidak\nJawab: ",
		 g17[]="Apakah bayi mengalami kenaikan berat badan yang tidak\nsesuai dengan yang diharapkan?\n1. Ya\n2. Tidak\nJawab: ",
		 g18[]="Apakah bayi mengalami kejang-kejang yang berlangsung\nlebih dari 5 menit?\n1. Ya\n2. Tidak\nJawab: ",
		 g19[]="Apakah bayi mengalami nafas yang cepat dan tidak wajar?\n1. Ya\n2. Tidak\nJawab: ",
		 g20[]="Apakah terdapat cairan bening dari hidung dan/atau bersin?\n1. Ya\n2. Tidak\nJawab: ",
		 g21[]="Apakah bayi mengalami letih yang berlebihan?\n1. Ya\n2. Tidak\nJawab: ",
		 g22[]="Apakah bayi mengompol walau sudah biasa menahan?\n1. Ya\n2. Tidak\nJawab: ",
		 g23[]="Apakah bayi mengalami ruam yang meradang dan mengelupas\n di dua atau lebih tempat(leher, belakang\ntelinga, wajah, selangkang, ketiak)?\n1. Ya\n2. Tidak\nJawab: ",
		 g24[]="Apakah terdapat kerak coklat kekuningan di kulit kepala bayi?\n1. Ya\n2. Tidak\nJawab: ",
		 g25[]="Apakah kulit bayi pecah atau berkudis?\n1. Ya\n2. Tidak\nJawab: ",
		 g26[]="Apakah bayi menolak disusui selama lebih dari 3 jam\n(pada bayi berusia di bawah 3 bulan) atau\nlebih dari 6 jam (pada bayi berusia di atas\n3 bulan)?\n1. Ya\n2. Tidak\nJawab: ",
		 g27[]="Apakah bayi merasa tidak nyaman?\n1. Ya\n2. Tidak\nJawab: ",
		 g28[]="Apakah bayi mengalami tumbuh gigi?\n1. Ya\n2. Tidak\nJawab: ",
		 g29[]="Apakah nafas bayi sesak ketika berolahraga?\n1. Ya\n2. Tidak\nJawab: ",
		 g30[]="Apakah kulit bayi lebih pucat dari normal?\n1. Ya\n2. Tidak\nJawab: ",
		 g31[]="Apakah sesekali bayi serasa mau pingsan?\n1. Ya\n2. Tidak\nJawab: ",
		 g32[]="Apakah bayi kurang tidur?\n1. Ya\n2. Tidak\nJawab: ",
		 g33[]="Apakah bayi sering terbangun di malam hari?\n1. Ya\n2. Tidak\nJawab: ",
		 g34[]="Apakah bayi tampak kurang sehat?\n1. Ya\n2. Tidak\nJawab: ",
		 g35[]="Apakah bayi menangis dan muntah setelah menyusu?\n1. Ya\n2. Tidak\nJawab: ",
		 g36[]="Apakah bayi menolak minum dari botol?\n1. Ya\n2. Tidak\nJawab: ",
		 g37[]="Apakah bayi tampak tidak sehat?\n1. Ya\n2. Tidak\nJawab: ",
		 g38[]="Apakah bayi tidak menghabiskan semua susu\ndi botolnya?\n1. Ya\n2. Tidak\nJawab: ",
		 p1[]="\nBayi Anda mengalami demam.\nTindakan yang dapat dilakukan diantaranya:\n1.Redakanlah demamnya\n2.Usahakan agar bayi banyak minum\n3.Atur suhu ruangan 15-20°C\n4.Tahan temperatur anak agar tetap rendah\n",
		 p2[]="\nBayi Anda mengalami rasa tidak sehat.\nTindakan yang dapat dilakukan diantaranya:\n1.Si anak mungkin mengalami infeksi saluran\n  kemih, dokter akan memeriksa contoh",
		 p2b[]="\n  urinnya dan dokter akan memberikan resep antibiotik\n2.Gejala ini mungkin akibat diabetes mellitus.\n  Kondisi ini disebabkan oleh kurangnya\n  produksi Hormon Insulin, dokter akan\n  mengambil contoh darah dan urin si anak",
		 p2c[]="\n  untuk mengukur tingkat darahnya. Jika\n  diagnosis ini benar, si anak mungkin memerlukan suntikan insulin selama\n  hidupnya.\n3.Mungkin menderita suatu penyakit\n  tersembunyi, misalnya infeksi saluran\n  kemih. Periksakanlah ke dokter yang akan",
		 p2d[]="\n  melakukan beberapa tes untuk mencari penyebab sebenarnya dan menetapkan\n  penanganan yang tepat. Si anak mungkin\n  akan dirujuk ke spesialis.\n",
		 p3[]="\nBayi Anda mengalami masalah kulit.\nTindakan yang dapat dilakukan diantaranya:\n1.Meningitis, peradangan selaput pembungkus\n  otak akibat infeksi harus dibawa ke rumah sakit.\n2.Beri perhatian ekstra saat membasuh dan",
		 p3b[]="\n  mengeringkan kulit di daerah yang terkena\n  infeksi, hindari penggunaan sabun, lotion\n  bayi ataupun larutan mandi bayi",
		 p4[]="\nBayi Anda mengalami muntah-muntah.\nTindakan yang dapat dilakukan diantaranya:\n1.Sterilkan semua peralatan makan dan dot\n2.Selalu menjaga kebersihan sebelum\n  menyiapkan susu dan makan untuk bayi.\n",
		 p5[]="\nBayi Anda mengalami diare.\nTindakan yang dapat dilakukan diantaranya:\n1.Senantiasa ikuti baik-baik instruksi di\n  ketnasan ketika menyiapkan makanan bayi\n  dan jangan menambahkan gula, sampai\n  diarenya hilang.\n",
		 p6[]="\nBayi Anda mengalami menangis berlebihan.\nTindakan yang dapat dilakukan diantaranya:\n1.Memberikan perhatian dan kenyamanan\n  fisik pada bayi. Jika karena tumbuhnya\n  gigi dapat diberikan benda-benda yang\n  bulat dan keras yang dapat digigit-gigit.",
		 p6b[]="\n2.Bila bayi demam setelah imunisasi,\n  berikanlah obat penurun panas begitu\n  selesai diimunisasi.\n3.Ciptakan suasana rumah seharmonis\n  dan senyaman mungkin.\n",
		 p7[]="\nBayi Anda mengalami keletihan.\nTindakan yang dapat dilakukan diantaranya:\n1.Si anak mungkin mengalami anemia yaitu\n  terlalu sedikit pigmen hemoglobin pembawa\n  oksigen dalam darah. Bila si anak\n  mengalami kekurangan zat besi, dokter akan",
		 p7b[]="\n  meresepkan suplemen zat besi.\n2.Anak-anak biasa mengorok ketika terserang\n  pilek dan tidak perlu dicemaskan. Namun\n  apabila si anak senantiasa mengorok\n  mungkin terjadi pembesaran tansil/adeneid",
		 p7c[]="\n  yang dapat menghalangi pernapasan saat\n  tidur. Periksalah ke dokter.\n3.Gejala asma/eskim yang tidak mengganggu\n  di siang hari, mungkin dapat mengganggu si\n  anak saat tidur. Dokter akan memeriksa dan\n  memberikan resep yang sesuai.",
		 p7d[]="\n4.Keletihan dapat merupakan gejala\n  kecemasan/depresi akibat kelelahan\n  sementara. Kecemasan/depresi ringan sering dapat dihapuskan dengan tambahan belaian\n  dan dukungan.\n",
		 p8[]="\nBayi Anda mengalami masalah tidur.\nTindakan yang dapat dilakukan diantaranya:\n1.Perbanyak tidur di siang hari\n2.Bayi tidur bersama orangtua\n3.Rendahkan temperatur kamar\n",
		 p9[]="\nBayi Anda mengalami masalah menyusu.\nTindakan yang dapat dilakukan diantaranya:\n1.pantau kenaikan berat badannya, kalau\n  tidak sesuai dengan diagram pertumbuhan,\n  konsultasikan dengan dokter.\n2.Menidurkan bayi menyamping dengan\n  kepala lebih tinggi.",
		 p9b[]="\n  Cobalah menggunakan cangkir bayi terlebih dahulu.\n",
		 p10[]="\nBayi Anda mengalami pertambahan berat badan kurang.\nTindakan yang dapat dilakukan diantaranya:\n1.Mungkin ada penyakit tersembunyi, coba\n  periksakan ke dokter.\n2.Cobalah beri ASI setiap kali bayi menangis\n  walau mungkin di saat ini tidak lapar, dan",
		 p10b[]="\n  tawarkan kedua puting susu secara bergantian.\n",
		 b1[]="\n==============KESIMPULAN & SOLUSI===============",
		 b2[]="================================================";
		 
	//algoritma metode depth first search
	g1: system("cls"); printf("%s", g1); scanf("%d", &q);
	if(q==1){
		g2: system("cls"); printf("%s", g2); scanf("%d", &q);
		if(q==1){
			g3: system("cls"); printf("%s", g3); scanf("%d", &q);
			if(q==1){
				g18: system("cls"); printf("%s", g18); scanf("%d", &q);
				if(q==1||q==2){
					g19: system("cls"); printf("%s", g19); scanf("%d", &q);
					if(q==1||q==2){
						g20: system("cls"); printf("%s", g20); scanf("%d", &q);
						if(q==1||q==2){
							printf("%s\n%s\n%s", b1, p1, b2);
							status_pasien="Demam";
						}else{
							fflush(stdin); printf("\nMasukkan pilihan yang benar!\n"); system("pause"); goto g20;
						}
					}else{
						fflush(stdin); printf("\nMasukkan pilihan yang benar!\n"); system("pause"); goto g19;
					}
				}else{
					fflush(stdin); printf("\nMasukkan pilihan yang benar!\n"); system("pause"); goto g18;
				}
			}else if(q==2){
				g11: system("cls"); printf("%s", g11); scanf("%d", &q);
				if(q==1||q==2){
					g12: system("cls"); printf("%s", g12); scanf("%d", &q);
					if(q==1||q==2){
						g13: system("cls"); printf("%s", g13); scanf("%d", &q);
						if(q==1||q==2){
							g14: system("cls"); printf("%s", g14); scanf("%d", &q);
							if(q==1||q==2){
								g16: system("cls"); printf("%s", g16); scanf("%d", &q);
								if(q==1||q==2){
									printf("%s\n%s\n%s",b1, p4, b2);
									status_pasien="Muntah";
								}else{
									fflush(stdin); printf("\nMasukkan pilihan yang benar!\n"); system("pause"); goto g16;
								}
							}else{
								fflush(stdin); printf("\nMasukkan pilihan yang benar!\n"); system("pause"); goto g14;
							}
						}else{
							fflush(stdin); printf("\nMasukkan pilihan yang benar!\n"); system("pause"); goto g13;
						}
					}else{
						fflush(stdin); printf("\nMasukkan pilihan yang benar!\n"); system("pause"); goto g12;
					}
				}else{
					fflush(stdin); printf("\nMasukkan pilihan yang benar!\n"); system("pause"); goto g11;
				}
			}else{
				fflush(stdin); printf("\nMasukkan pilihan yang benar!\n"); system("pause"); goto g3;
			}
		} else if(q==2){
			g4: system("cls"); printf("%s", g4); scanf("%d", &q);
			if(q==1){
				g5: system("cls"); printf("%s", g5); scanf("%d", &q);
				if(q==1||q==2){
					g6: system("cls"); printf("%s", g6); scanf("%d", &q);
					if(q==1||q==2){
						g7: system("cls"); printf("%s", g7); scanf("%d", &q);
						if(q==1||q==2){
							g8: system("cls"); printf("%s", g8); scanf("%d", &q);
							if(q==1||q==2){
								g9: system("cls"); printf("%s", g9); scanf("%d", &q);
								if(q==1||q==2){
									g10: system("cls"); printf("%s", g10); scanf("%d", &q);
									if(q==1||q==2){
										printf("%s\n%s%s%s%s\n%s", b1, p2,p2b,p2c,p2d, b2);
										status_pasien="Tidak Sehat";
									}else{
										fflush(stdin); printf("\nMasukkan pilihan yang benar!\n"); system("pause"); goto g10;
									}
								}else{
									fflush(stdin); printf("\nMasukkan pilihan yang benar!\n"); system("pause"); goto g9;
								}
							}else{
								fflush(stdin); printf("\nMasukkan pilihan yang benar!\n"); system("pause"); goto g8;
							}
						}else{
							fflush(stdin); printf("\nMasukkan pilihan yang benar!\n"); system("pause"); goto g7;
						}
					}else{
						fflush(stdin); printf("\nMasukkan pilihan yang benar!\n"); system("pause"); goto g6;
					}
				}else{
					fflush(stdin); printf("\nMasukkan pilihan yang benar!\n"); system("pause"); goto g5;
				}
			}else if(q==2){
				g23: system("cls"); printf("%s", g23); scanf("%d", &q);
				if(q==1||q==2){
					g24: system("cls"); printf("%s", g24); scanf("%d", &q);
					if(q==1||q==2){
						g25: system("cls"); printf("%s", g25); scanf("%d", &q);
						if(q==1||q==2){
							printf("%s\n%s%s\n%s",b1,p3,p3b,b2);
							status_pasien="Masalah Kulit";
						}else{
							fflush(stdin); printf("\nMasukkan pilihan yang benar!\n"); system("pause"); goto g25;
						}
					}else{
						fflush(stdin); printf("\nMasukkan pilihan yang benar!\n"); system("pause"); goto g24;
					}
				}else{
					fflush(stdin); printf("\nMasukkan pilihan yang benar!\n"); system("pause"); goto g23;
				}
			}else{
				fflush(stdin); printf("\nMasukkan pilihan yang benar!\n"); system("pause"); goto g4;
			}
		}else {
			fflush(stdin); printf("\nMasukkan pilihan yang benar!\n"); system("pause"); goto g2;
		}
	} else if(q==2){
		g2b: system("cls"); printf("%s", g2); scanf("%d", &q);
		if(q==1){
			g3b: system("cls"); printf("%s", g3); scanf("%d", &q);
			if(q==1||q==2){
				g4b: system("cls"); printf("%s", g4); scanf("%d", &q);
				if(q==1||q==2){
					g11b: system("cls"); printf("%s", g11); scanf("%d", &q);
					if(q==1||q==2){
						g12b: system("cls"); printf("%s", g12); scanf("%d", &q);
						if(q==1||q==2){
							g13b: system("cls"); printf("%s", g13); scanf("%d", &q);
							if(q==1||q==2){
								printf("%s\n%s\n%s", b1,p5,b2);
								status_pasien="Diare";
							}else{
								fflush(stdin); printf("\nMasukkan pilihan yang benar!\n"); system("pause"); goto g13b;
							}
						}else{
							fflush(stdin); printf("\nMasukkan pilihan yang benar!\n"); system("pause"); goto g12b;
						}
					}else{
						fflush(stdin); printf("\nMasukkan pilihan yang benar!\n"); system("pause"); goto g11b;
					}
				}else{
					fflush(stdin); printf("\nMasukkan pilihan yang benar!\n"); system("pause"); goto g4b;
				}
			}else{
				fflush(stdin); printf("\nMasukkan pilihan yang benar!\n"); system("pause"); goto g3b;
			}
		}else if(q==2){
			g3c: system("cls"); printf("%s", g3); scanf("%d", &q);
			if(q==1){
				g15: system("cls"); printf("%s", g15); scanf("%d", &q);
				if(q==1||q==2){
					g16b: system("cls"); printf("%s", g16); scanf("%d", &q);
					if(q==1||q==2){
						printf("%s\n%s%s\n%s", b1, p6, p6b, b2);
						status_pasien="Menangis Berlebihan";
					}else{
						fflush(stdin); printf("\nMasukkan pilihan yang benar!\n"); system("pause"); goto g16b;
					}
				}else{
					fflush(stdin); printf("\nMasukkan pilihan yang benar!\n"); system("pause"); goto g15;
				}
			}else if(q==2){
				g5b: system("cls"); printf("%s", g5); scanf("%d", &q);
				if(q==1){
					g6b: system("cls"); printf("%s", g6); scanf("%d", &q);
					if(q==1||q==2){
						g7b: system("cls"); printf("%s", g7); scanf("%d", &q);
						if(q==1||q==2){
							g8b: system("cls"); printf("%s", g8); scanf("%d", &q);
							if(q==1||q==2){
								g9b: system("cls"); printf("%s", g9); scanf("%d", &q);
								if(q==1||q==2){
									printf("%s\n%s%s%s%s\n%s", b1, p7, p7b, p7c, p7d, b2);
									status_pasien="Keletihan";
								}else{
									fflush(stdin); printf("\nMasukkan pilihan yang benar!\n"); system("pause"); goto g9b;
								}
							}else{
								fflush(stdin); printf("\nMasukkan pilihan yang benar!\n"); system("pause"); goto g8b;
							}
						}else{
							fflush(stdin); printf("\nMasukkan pilihan yang benar!\n"); system("pause"); goto g7b;
						}
					}else{
						fflush(stdin); printf("\nMasukkan pilihan yang benar!\n"); system("pause"); goto g6b;
					}
				}else if(q==2){
					g15b: system("cls"); printf("%s", g15); scanf("%d", &q);
					if(q==1){
						g33: system("cls"); printf("%s", g33); scanf("%d", &q);
						if(q==1||q==2){
							g34: system("cls"); printf("%s", g34); scanf("%d", &q);
							if(q==1||q==2){
								printf("%s\n%s\n%s", b1, p8, b2);
								status_pasien="Masalah Tidur";
							}else {
								fflush(stdin); printf("\nMasukkan pilihan yang benar!\n"); system("pause"); goto g34;
							}
						}else{
							fflush(stdin); printf("\nMasukkan pilihan yang benar!\n"); system("pause"); goto g33;
						}
					}else if(q==2){
						g17: system("cls"); printf("%s", g17); scanf("%d", &q);
						if(q==1||q==2){
							g35: system("cls"); printf("%s", g35); scanf("%d", &q);
							if(q==1){
								g36: system("cls"); printf("%s", g36); scanf("%d", &q);
								if(q==1||q==2){
									printf("%s\n%s%s\n%s", b1, p9, p9b, b2);
									status_pasien="Masalah Menyusu";
								}else{
									fflush(stdin); printf("\nMasukkan pilihan yang benar!\n"); system("pause"); goto g36;
								}
							}else if(q==2){
								g37: system("cls"); printf("%s", g37); scanf("%d", &q);
								if(q==1||q==2){
									g38: system("cls"); printf("%s", g38); scanf("%d", &q);
									if(q==1||q==2){
										printf("%s\n%s%s\n%s", b1, p10, p10b, b2);
										status_pasien="Berat Badan Kurang";
									}else{
										fflush(stdin); printf("\nMasukkan pilihan yang benar!\n"); system("pause"); goto g38;
									}
								}else{
									fflush(stdin); printf("\nMasukkan pilihan yang benar!\n"); system("pause"); goto g37;
								}
							}else{
								fflush(stdin); printf("\nMasukkan pilihan yang benar!\n"); system("pause"); goto g35;
							}
						}else{
							fflush(stdin); printf("\nMasukkan pilihan yang benar!\n"); system("pause"); goto g17;
						}
					}else{
						fflush(stdin); printf("\nMasukkan pilihan yang benar!\n"); system("pause"); goto g15b;
					}
				}else{
					fflush(stdin); printf("\nMasukkan pilihan yang benar!\n"); system("pause"); goto g5b;
				}
			}else{
				fflush(stdin); printf("\nMasukkan pilihan yang benar!\n"); system("pause"); goto g3c;
			}
		}else{
			fflush(stdin); printf("\nMasukkan pilihan yang benar!\n"); system("pause"); goto g2b;
		}
	} else {
		fflush(stdin); printf("\nMasukkan pilihan yang benar!\n"); system("pause"); goto g1;
	}
}
