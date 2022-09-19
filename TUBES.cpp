/*	Program Mesin Gambar Sederhana
	Tanggal : 18 April 2017
	Deskripsi : 
	Anthor : <3411161153>/<M. Rivaldi Irawan>
			 <3411161072>/<Ike Sri Rahayu>
			 <3411161023>/<Hilda Herlina S>
*/

#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include"boolean.h"
#define nMax 2842
#define nil NULL

//definsi tipe data baru
typedef struct{
				int x;
				int y;
			}Coord;

//kamus Global			
Coord C;
Coord saved[nMax+1];//menyimpan jumlah koordinat pada array 
int JumGambar = 0;//menyimpan jumlah gambar
int JumCoordSaved;//menyimpan jumlah koordinat yang telah dibuat

//Prototype
void gotoxy(int x, int y);
/* 	IS : X dan Y terdefinisi sebuah koordinat sembaranf tidak nol
	FS : X dan Y telah diciptakan di titik koordinat 0,0
*/
void DrawCoordxy();
/* 	IS : Dapat menggambar kode ASCII (237) pada koordinat (C.x,C.y)
	FS : Kode ASCII (237) telah digambar didalam box
*/
void EraseCoordxy(int CoordX, int CoordY, int Jumlah);
/* 	IS : Dapat menghapus kode ASCII (237) pada koordinat (C.x,C.y)
	FS : Kode ASCII (237) telah dihapus
*/
void FrameAwal();
/* 	IS : Membuat Frame untuk tampilan awal program dengan gotoxy
	FS : Frame untuk tampilan awal program telah dibuat
*/
void FrameMenu();
/* 	IS : Membuat Frame untuk tampilan menu program dengan gotoxy
	FS : Frame untuk tampilan menu program telah dibuat
*/
void MainFrame();
/* 	IS : Membuat Frame bagian luar untuk tampilan saat drawing dengan gotoxy
	FS : Frame bagian luar untuk tampilan saat drawing telah dibuat
*/
void box();
/* 	IS : Membuat Frame bagian dalam untuk tampilan saat drawing dengan gotoxy 
	FS : Frame bagian dalam untuk tampilan saat drawing telah dibuat
*/
void BoxLoad();
/* 	IS : Membuat Frame untuk tampilan Menu Load File 
	FS : Frame untuk tampilan Menu Load File telah dibuat
*/
void MainMenu();
/* 	IS : Membuat tampilan Menu Utama
	FS : Menu Utama telah dibuat
*/
void MenuNewFile();
/* 	IS : Membuat tampilan Menu New File dan menggambar
	FS : Menu New File dan gambar telah dibuat
*/
void MenuDirect();
/* 	IS : Membuat tampilan Menu Direct
	FS : Menu Direct telah dibuat
*/
void LoadFile();
/* 	IS : Memuat Tampilan Menu Load File yang berisi gambar yang telah dibuat di Menu New File
	FS : Gambar yang telah dibuat dapat ditampilkan
*/
void ClearBox(Coord ClearSaved[], int *JumSaved);
/* 	IS : Menghapus semua apa yang telah di gambar di dalam box
	FS : gambar yang telah dibuat telah dihapus seluruhnya
*/
void ClearCommandMenu();
/* 	IS : Menghapus inputan yang telah diinputkan di Menu Utama
	FS : Inputan pada Menu Utama telah dihapus
*/
void ClearBackMenu();
/* 	IS : Menghapus tampilan Back Menu
	FS : Tampilan Back Menu telah dihapus
*/
void ClearCommandLoad();
/* 	IS : Menghapus inputan yang telah diinputkan di Menu Load File
	FS : Inputan pada Menu Load File telah dihapus
*/
boolean BackMenu();
// Mengirim Nilai True atau False kepada Menu Back Menu
int GetJumGambar();
// Mengirim jumlah gambar yang telah disave pada file
boolean CekArray();
// Mengirim Nilai True atau False untuk menghapus titik yang telah dibuat

//main driver
int main(){
	//kamus
	char pilih;
	//algoritma
	system("MODE 135,39");
	FrameAwal();
	system("cls");	
	menu:
	JumGambar=GetJumGambar();
	FrameMenu();
	MainMenu();
	gotoxy(49,31);
	scanf("%c",&pilih);	
	while (pilih != '1' && pilih != '2' && pilih != '3'){//hapus perintah yang salah di command
		ClearCommandMenu();
		gotoxy(49,31);scanf("%c",&pilih);
		}
		system("cls");
		switch(pilih){

			case '1' :{
				MainFrame();
				MenuNewFile();
				goto menu;
				break;
			} 
				 		 
			case '2' :{
				BoxLoad();
				ClearBox(saved, &JumCoordSaved);
				LoadFile();
				goto menu;
				break;
			}
					 
			case '3':{
				goto end;
				break;
			}
					
		}
			
	getch();
	end:
	return 0;
}
	
//Realisasi Prototype

void gotoxy(int x, int y){
/* 	IS : X dan Y terdefinisi sebuah koordinat sembaranf tidak nol
	FS : X dan Y telah diciptakan di titik koordinat 0,0
*/
//kamus

//algoritma
	HANDLE handle;
	COORD coord;
	coord.X = x;
	coord.Y = y;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(handle,coord);
}

void DrawCoordxy(){
/* 	IS : Dapat menggambar kode ASCII (237) pada koordinat (C.x,C.y)
	FS : Kode ASCII (237) telah digambar didalam box
*/
//kamus

//algoritma
	printf("%c", 111);
	saved[JumCoordSaved].x=C.x;
	saved[JumCoordSaved].y=C.y;
	JumCoordSaved++;
}

void EraseCoordxy(int CoordX, int CoordY, int Jumlah){
/* 	IS : Dapat menghapus kode ASCII (237) pada koordinat (C.x,C.y)
	FS : Kode ASCII (237) yang telah dibuat telah dihapus
*/
//kamus
	int i,k,hasil;
	boolean ketemu;
//algoritma	
	printf(" ");
	i = 0;
	ketemu = false;
	while (i <= Jumlah && !ketemu){
		if (saved[i].x == CoordX && saved[i].y == CoordY) {
			saved[i].x = nil;
			saved[i].y = nil;
			
			ketemu = true;
			hasil = Jumlah;
			//menggeser koordinat yang telah dihapus
			for (k = i; k <= Jumlah; k++) {
				saved[k].x = saved[k+1].x;
				saved[k].y = saved[k+1].y;
			}
			Jumlah--;
		}
		//belum ketemu
		else {
			i++;
		}
	} 

}

void FrameAwal(){
/* 	IS : Membuat Frame untuk tampilan awal program dengan gotoxy
	FS : Frame untuk tampilan awal program telah dibuat
*/
//kamus
	int i;
//algoritma
	
	for(i=44 ; i<=88 ; i++){
		gotoxy(i,12);printf("%c", 205);//atas box horizontal
		gotoxy(i,24);printf("%c", 205);//bawah box horizontal
	}
		
	for(i=13 ; i<=23 ; i++){
		gotoxy(43,i);printf("%c", 186);//kiri box vertikal
		gotoxy(89,i);printf("%c", 186);//kanan box vertikal = kiri sidebar
	}
	
	//ruas kiri
	gotoxy(43,12);printf("%c", 201);//sudut atas
	gotoxy(43,24);printf("%c", 200);//sudut bawah
	
	//ruas kanan
	gotoxy(89,12);printf("%c", 187);//sudut atas
	gotoxy(89,24);printf("%c", 188);//sudut bawah
	
	gotoxy(53,14);printf("WELCOME TO THE DRAW MACHINE");
	gotoxy(61,16);printf("Created By : ");
	gotoxy(59,18);printf("M.RIVALDI IRAWAN");
	gotoxy(51,22);system("PAUSE");
}

void FrameMenu(){
/* 	IS : Membuat Frame untuk tampilan menu program dengan gotoxy
	FS : Frame untuk tampilan menu program telah dibuat
*/
//kamus
	int i;
//algoritma
	for(i=48;i<=86;i++){
		gotoxy(i,8);printf("%c", 205);//atas horizontal
		gotoxy(i,29);printf("%c", 205);//tengah horizontal
		gotoxy(i,33);printf("%c", 205);//bawah horizontal
	}
	
	for(i=9;i<=33;i++){
		gotoxy(47,i);printf("%c", 186);//kiri vertikal
		gotoxy(87,i);printf("%c", 186);//kanan vertikal
	}
	
	//ruas kiri
	gotoxy(47,8);printf("%c", 201);//sudut atas
	gotoxy(47,29);printf("%c", 204);//sudut segitiga tengah
	gotoxy(47,33);printf("%c", 200);//sudut bawah
	
	//ruas kanan
	gotoxy(87,8);printf("%c", 187);//sudut atas
	gotoxy(87,29);printf("%c", 185);//sudut segitiga tengah
	gotoxy(87,33);printf("%c", 188);//sudut bawah
	
	gotoxy(49,30);printf("Enter Your Choice");
	
}

void MainFrame(){
/* 	IS : Membuat Frame bagian luar untuk tampilan saat drawing dengan gotoxy
	FS : Frame bagian luar untuk tampilan saat drawing telah dibuat
*/
//kamus
	int i;
//algoritma
	box();
	for(i=1 ; i<=133 ; i++){
		gotoxy(i,0);printf("%c", 205);//atas frame horizontal
		gotoxy(i,35);printf("%c", 205);//bawah frame horizontal
	}
	
	for(i=1 ; i<=34 ; i++){
		gotoxy(0,i);printf("%c", 186);//kiri frame vertikal
		gotoxy(134,i);printf("%c", 186);//kanan frame vertikal	
	}
	
	//ruas kiri
	gotoxy(0,0);printf("%c", 201);//sudut atas
	gotoxy(0,35);printf("%c", 200);//sudut bawah
	
	//ruas kanan
	gotoxy(134,0);printf("%c", 187);//sudut atas
	gotoxy(134,35);printf("%c", 188);//sudut bawah
}

void box(){
/* 	IS : Membuat Frame bagian dalam untuk tampilan saat drawing dengan gotoxy 
	FS : Frame bagian dalam untuk tampilan saat drawing telah dibuat
*/
//kamus
	int i;
//algoritma
	
	for(i=30 ; i<=128 ; i++){
		gotoxy(i,2);printf("%c", 205);//atas box horizontal
		gotoxy(i,33);printf("%c", 205);//bawah box horizontal
	}
	//kiri
	for(i=5 ; i<=30 ; i++){
		gotoxy(i,2);printf("%c", 205);//atas sidebar horizontal
		gotoxy(i,33);printf("%c", 205);//bawah sidebar horizontal
	}
	//kanan
	for(i=75 ; i<=103 ; i++){
		gotoxy(i,2);printf("%c", 205);//atas sidebar horizontal
		gotoxy(i,33);printf("%c", 205);//bawah sidebar horizontal
	}
	//sidebar
	for(i=3 ; i<=32 ; i++){
		gotoxy(4,i);printf("%c", 186);//kiri sidebar kiri vertikal
		gotoxy(30,i);printf("%c", 186);//kiri box
		gotoxy(104,i);printf("%c", 186);//kanan box vertikal = kiri sidebar kanan
		gotoxy(129,i);printf("%c", 186);//kanan sidebar vertikal kanan
	}
	
	//ruas kiri
	gotoxy(4,2);printf("%c", 201);//sudut atas
	gotoxy(4,33);printf("%c", 200);//sudut bawah
	gotoxy(30,2);printf("%c", 203);//sudut segitiga sidebar atas
	gotoxy(104,2);printf("%c", 203);///sudut segitiga sidebar bawah
	
	//ruas kanan
	gotoxy(129,2);printf("%c", 187);//sudut atas
	gotoxy(129,33);printf("%c", 188);//sudut bawah
	gotoxy(30,33);printf("%c", 202);//sudut segitiga sidebar atas
	gotoxy(104,33);printf("%c", 202);//sudut segitiga sidebar bawah
}

void BoxLoad(){
/* 	IS : Membuat Frame untuk tampilan Menu Load File 
	FS : Frame untuk tampilan Menu Load File telah dibuat
*/
//kamus
	int i;
//algoritma
	
	for(i=30 ; i<=103 ; i++){
		gotoxy(i,2);printf("%c", 205);//atas box horizontal
		gotoxy(i,33);printf("%c", 205);//bawah box horizontal
	}
	//kiri
	for(i=5 ; i<=30 ; i++){
		gotoxy(i,2);printf("%c", 205);//atas sidebar horizontal
		gotoxy(i,33);printf("%c", 205);//bawah sidebar horizontal
	}
	
	for(i=5 ; i<=29 ; i++){
		gotoxy(i,30);printf("%c", 205);//tengah sidebar load horizontal
	}
	
	for(i=3 ; i<=32 ; i++){
		gotoxy(4,i);printf("%c", 186);//kiri sidebar kiri vertikal
		gotoxy(30,i);printf("%c", 186);//kiri box
		gotoxy(104,i);printf("%c", 186);//kanan box
	}
	
	//ruas kiri
	gotoxy(4,2);printf("%c", 201);//sudut atas
	gotoxy(4,30);printf("%c", 204);//sudut segitiga sidebar
	gotoxy(4,33);printf("%c", 200);//sudut bawah
	
	//ruas kanan
	gotoxy(104,2);printf("%c", 187);//sudut atas
	gotoxy(30,30);printf("%c", 185);//sudut segitiga sidebar
	gotoxy(104,33);printf("%c", 188);//sudut bawah
	
	//ruas atas
	gotoxy(30,2);printf("%c", 203);//sudut segitiga sidebar
	
	//ruas bawah
	gotoxy(30,33);printf("%c", 202);//sudut segitiga sidebar
	
	gotoxy(7,31);printf("Enter Your Choice");
}

void MainMenu(){
/* 	IS : Membuat tampilan Menu Utama
	FS : Menu Utama telah dibuat
*/
//kamus

//algoritma
	gotoxy(52,14);printf("1. New File");
	gotoxy(52,15);printf("2. Load File");
	gotoxy(52,16);printf("3. Exit");
}

void MenuNewFile(){
/* 	IS : Membuat tampilan Menu New File dan menggambar
	FS : Menu New File dan gambar telah dibuat
*/
//kamus
	boolean draw;
	boolean erase;
	boolean keluar;
	boolean ketemu;
	char tmp;
//algoritma
	//setting default
	draw=true;
	erase=false;
	
	//tampilan menu
	MenuDirect();
	gotoxy(110,6);printf("<MAIN CONTROL>");
	gotoxy(106,8);printf("[D] DRAW");
	gotoxy(106,9);printf("[E] ERASER");
	gotoxy(106,10);printf("[C] CLEAR");
	gotoxy(106,11);printf("[B] BACK TO MAIN MENU");
	
	//bar (on/off) di sidebar
	gotoxy(121,8);printf("[ON]");
	gotoxy(121,9);printf("[OFF]");
	
	//set koordinat di tengah
	gotoxy(68,16);
	C.x=68;
	C.y=16;
	JumCoordSaved=0;
	
	while(true){
		gotoxy(C.x,C.y);
		tmp=getch();
		switch(tmp){
		
		//draw	
		case 'd':{
			if(draw == true){
				draw = false;
				gotoxy(121,8);printf("[OFF]");
				gotoxy(C.x,C.y);
			}
			else{
				draw = true;
				erase = false;
				gotoxy(121,8);printf("[ON] ");
				gotoxy(121,9);printf("[OFF]");
				gotoxy(C.x,C.y);
			}	
			break;
				}
		
		//erase
		case 'e':{
			if(erase == true){
				erase = false;
				gotoxy(121,9);printf("[OFF]");
				gotoxy(C.x,C.y);
			}else{
				erase = true;
				draw = false;
				gotoxy(121,9);printf("[ON] ");
				gotoxy(121,8);printf("[OFF]");
				gotoxy(C.x,C.y);
				}
			break;
				}
				
		//clear
		case 'c':{
			ClearBox(saved, &JumCoordSaved);
			gotoxy(C.x, C.y);
			break;
		}
		
		//back to menu
		case 'b':{
				keluar=BackMenu();
				if(keluar){
					goto backmenu;
				}
			break;
				}

		//direction atas
		case'i':{
			if(C.y > 3){
					C.y--;
					gotoxy(C.x,C.y);
					}
				if(draw == true){
					DrawCoordxy();
					}
				if(erase == true){
					ketemu = CekArray();
						if(ketemu == true){
							EraseCoordxy(C.x, C.y, JumCoordSaved);
							JumCoordSaved--;
						}
					}
			break;
				}
				
		//direction bawah
		case 'k':{
			if(C.y < 32 ){
				C.y++;
				gotoxy(C.x,C.y);
					}
				if(draw == true){
					DrawCoordxy();
					}
				if(erase == true){
					ketemu = CekArray();
						if(ketemu == true){
							EraseCoordxy(C.x, C.y, JumCoordSaved);
							JumCoordSaved--;
						}
					}
			break;
				}
				
		//direction kanan		
		case 'l':{
			if(C.x < 103 ){
				C.x++;
				gotoxy(C.x,C.y);
					}
				if(draw == true){
					DrawCoordxy();
					}
				if(erase == true){
					ketemu = CekArray();
						if(ketemu == true){
							EraseCoordxy(C.x, C.y, JumCoordSaved);
							JumCoordSaved--;
						}
					}
			break;
				}
				
		//direction kiri
		case 'j':{
			if(C.x > 31 ){
				C.x--;
				gotoxy(C.x,C.y);
					}
				if(draw == true){
					DrawCoordxy();
					}
				if(erase == true){
					ketemu = CekArray();
						if(ketemu == true){
							EraseCoordxy(C.x, C.y, JumCoordSaved);
							JumCoordSaved--;
						}
					}
			break;
				}
				
		//diagonal kanan atas			
		case'o':{
				if(C.x < 103 && C.y > 3){
					C.x++;
					C.y--;
					gotoxy(C.x, C.y);
					}
					if(draw == true){
						DrawCoordxy();
					}
					if(erase == true){
						ketemu = CekArray();
							if(ketemu == true){
								EraseCoordxy(C.x, C.y, JumCoordSaved);
								JumCoordSaved--;
						}
					}	
			break;
				}
				
		//diagonal kanan bawah
		case'.':{
				if(C.x < 103 && C.y < 32){
					C.y++;
					C.x++;
					gotoxy(C.x, C.y);
					}
				if(draw == true){
					DrawCoordxy();
					}
				if(erase == true){
					ketemu = CekArray();
						if(ketemu == true){
							EraseCoordxy(C.x, C.y, JumCoordSaved);
							JumCoordSaved--;
						}
					}	
			break;
				}
				
		//diagonal kiri bawah
		case'm':{
				if(C.x > 31 && C.y < 32){
					C.x--;
					C.y++;
					gotoxy(C.x, C.y);
					}
				if(draw == true){
					DrawCoordxy();
					}
				if(erase == true){
					ketemu = CekArray();
						if(ketemu == true){
							EraseCoordxy(C.x, C.y, JumCoordSaved);
							JumCoordSaved--;
						}
					}	
			break;
				}
				
		//diagonal kiri atas
		case'u':{
				if(C.x > 31 && C.y > 3){
					C.y--;
					C.x--;
					gotoxy(C.x, C.y);
					}
				if(draw == true){
					DrawCoordxy();
					}
				if(erase == true){
					ketemu = CekArray();
						if(ketemu == true){
							EraseCoordxy(C.x, C.y, JumCoordSaved);
							JumCoordSaved--;
						}	
					}	
			break;
				}
				
			}//end swith
		}//end while
	//backmenu
	backmenu:
	FrameMenu();
	MainMenu();
}

void MenuDirect(){
/* 	IS : Membuat tampilan Menu Direct
	FS : Menu Direct telah dibuat
*/
//kamus

//algoritma
	gotoxy(8,6);printf("<CONTROL DIRECTION>");
	gotoxy(6,8);printf("[I] UP");
	gotoxy(6,9);printf("[J] LEFT");
	gotoxy(6,10);printf("[K] DOWN");
	gotoxy(6,11);printf("[L] RIGHT");
	gotoxy(6,12);printf("[O] DIAGONAL UP RIGHT");
	gotoxy(6,13);printf("[>] DIAGONAL DOWN RIGHT");
	gotoxy(6,14);printf("[U] DIAGONAL UP LEFT");
	gotoxy(6,15);printf("[M] DIAGONAL DOWN LEFT");
}

void LoadFile(){
/* 	IS : Memuat Tampilan Menu Load File yang berisi gambar yang telah dibuat di Menu New File
	FS : Gambar yang telah dibuat dapat ditampilkan
*/
//kamus
	int load;
	int i;
	int jumtitikfile,x,y;
	FILE *file;
	char buffer[32];
//algoritma
	gotoxy(7,6);printf("Load File %d", JumGambar);
	
	for (i = 1;i <= JumGambar; i++) {
		gotoxy(7,6 + i);printf("%d. Gambar %d",i, i);
	}
	
	gotoxy(7, 6 + JumGambar + 1);printf("999. kembali");
	
	while (load != 999) {
		ClearCommandLoad();
		gotoxy(7,32);scanf("%d", &load);
		
		if (load <= JumGambar) {
			ClearBox(saved, &JumCoordSaved);
			
			snprintf(buffer, sizeof(char) * 32, "gambar %i.txt", load);
		
			file = fopen (buffer, "r");
			fscanf(file,"%d",&jumtitikfile);
				
			for (i = 1; i <= jumtitikfile; i++ ) {
				fscanf(file,"%d %d/n",&x,&y);
				gotoxy(x,y);printf("%c", 111);
				}
		}
	}
	system("cls");
}

void ClearBox(Coord ClearSaved[] , int *JumSaved){
/* 	IS : Menghapus semua apa yang telah di gambar di dalam box
	FS : gambar yang telah dibuat telah dihapus seluruhnya
*/
//kamus
	int i,j;
//algoritma
	for(i=31 ; i< 104 ; i++){// coor x
		for(j=3; j<33 ; j++){// coor y
			gotoxy(i,j);printf(" ");
		}
	}
	
	//menghapus koordinat yang sudah di saved
	for(j = 0; j <= *JumSaved; j++) {
		ClearSaved[j].x = nil;
		ClearSaved[j].y = nil;
	}
	
	*JumSaved = 3;
	
	gotoxy(68,17);
	C.x = 68;
	C.y = 17;
	i = 0;
}

void ClearCommandMenu(){
/* 	IS : Menghapus inputan yang telah diinputkan di Menu Utama
	FS : Inputan pada Menu Utama telah dihapus
*/
//kamus
	int i;
//algoritma
	for(i=49 ; i<87 ; i++){
		gotoxy(i,31);printf(" ");	
	}
}

void ClearBackMenu(){
/* 	IS : Menghapus tampilan Back Menu
	FS : Tampilan Back Menu telah dihapus
*/
//kamus
	int i, j;
//algoritma
	for(i=106;i<=128;i++){
		for(j=20;j<=24;j++){
			gotoxy(i,j);printf(" ");
		}
	}
	gotoxy(C.x,C.y);
}

void ClearCommandLoad(){
/* 	IS : Menghapus inputan yang telah diinputkan di Menu Load File
	FS : Inputan pada Menu Load File telah dihapus
*/
//kamus
	int i;
//algoritma
	for(i=7 ; i< 30 ; i++){// coor x
		gotoxy(i,32);printf(" ");
	}	
}

boolean BackMenu(){
// Mengirim Nilai True atau False kepada Menu Back Menu
//kamus
	int i;
	char pilih;
	boolean keluar;
//algoritma
	gotoxy(106,20);printf("Do you want to save it?");
	gotoxy(106,21);printf("1. Yes");
	gotoxy(106,22);printf("2. No");
	gotoxy(106,23);printf("3. Cancel");
	gotoxy(C.x,C.y);
	while(true){
		pilih=getch();
		switch(pilih){
			case'1':{
						
				JumGambar++;
				
				FILE *fp;
				char buffer[32];
				
	    		snprintf(buffer, sizeof(char) * 32, "gambar %i.txt", JumGambar);
				
				fp = fopen (buffer, "w+");
				
				fprintf(fp, "%d\n", JumCoordSaved);
					
				for (i = 0 ; i < JumCoordSaved ; i++ ) {
					fprintf(fp, "%d %d\n",saved[i].x,saved[i].y);
				}
				
				fclose(fp);
				system("cls");
				keluar = true;
				return keluar;
				break;
					}
				
			case '2':{
				for(i = 0; i <= JumCoordSaved; i++) {
						saved[i].x = nil;
						saved[i].y = nil;
				}
				system("cls");
				keluar=true;
				return keluar;
				break;
					}
					
			case '3':{
				ClearBackMenu();
				keluar=false;
				return keluar;
				break;
			}
		}//end switch
	}//end while
}

int GetJumGambar(){
// Mengirim jumlah gambar yang telah disave pada file
//kamus
	int jumgbr;
	boolean akhir;
	char buffer[32];
	FILE *file;
//algoritma
	akhir = false;
	jumgbr=1;
	while (!akhir){
		snprintf(buffer, sizeof(char) * 32, "gambar %i.txt", jumgbr);
		file = fopen(buffer,"r");
		if( file !=nil) {
	        jumgbr++;
	        fclose(file);
		}   
	    else {
	    	akhir = true;
		}
	}
	return jumgbr-1;
}

boolean CekArray(){
// Mengirim Nilai True atau False untuk menghapus titik yang telah dibuat
//kamus	
	int i;
	boolean ketemu;
//algoritma
	ketemu = false;
	//periksa
	while(i <= JumCoordSaved && !ketemu) {
		if (C.x == saved[i].x && C.y == saved[i].y) {
			ketemu = true;
		}
		else {
			i++;	
		}
	}
	
	if (ketemu == true) {
		return true;
	}
	else {
		return false;
	}
}
