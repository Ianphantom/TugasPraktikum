#include <iostream>
#include <string.h>
using namespace std;

void enkripsi(){
	string plainteks, cipherteks;
	int i,k;
	char c;
	
	cout<< "ketikkan pesan: ";
	cin.ignore(); getline(cin, plainteks);
	cout<< "key : "; cin >> k; // menerima inputan plainteks
	cipherteks = ""; // inisiasi cipherteks dengan null string
	
	for(i=0; i< plainteks.length();i++){
		c = plainteks[i];
		if(isalpha(c)){ //hanya mengambil huruf alpabet saja
			c = toupper(c); // ubah menjadi huruf kapital
//			cout << "C to upper : " << c << endl;
			c = c - 65; // mengkodekan huruf ke angka 0 s/d 25
			c = (c+k) % 26; // enkripsi, geser sejauh k ke kanan
//			cout << "C: " << c << endl;
			c = c + 65; // kodekan kembali ke huruf semula
//			cout << "C akhir: " << c << endl;
		}
		cipherteks = cipherteks + c; // menyambungkan cipherteks
	}
	cout << "Chiperteks : "<< cipherteks <<endl; // output chiperteks
		
}

void deskripsi()
{
	string plainteks, cipherteks;
	int i,k;
	char c;
	
	cout << "Ketikkan pesan yang dienkripsi : ";
	cin.ignore(); getline(cin, cipherteks);
	cout << "Key  : "; cin >> k; //menerima input
	plainteks= ""; // inisiasi plainteks dengan null string
	
	for(i=0; i < cipherteks.length(); i++){
		c = cipherteks[i];
	//	cout << "C to upper : " << c << endl;
		if( isalpha(c) ){
			c = toupper(c); //mengubah ke huruf kapital
			//cout << "C to upper : " << c << endl;
			c = c - 65 ; // kodekan huruf ke angka 0 s/d 25
			if( c-k < 0){ //kasus pembagian bilangan negatif
				c = 26 + (c - k); //enkripsi bilangan negatif
			}else{
				c = (c-k) % 26; //enkripsi bilangan positif
			}
			c =c + 65; // kodekan ke huruf semula
			c = tolower(c); // plaintteks dinyatakan dengan huruf kecil
			//cout << "C akhir: " << c << endl;
		}
		plainteks = plainteks + c; //menyatukan plainteks
	}
	cout <<"Plainteks: " << plainteks << endl; //hasil output
}

main(){
	int pil;
	bool stop;
	stop = false;
	
	while(!stop){
		cout << "Menu: " << endl;
		cout << "1. Eknripsi "<<endl;
		cout << "2. Deskripsi "<<endl;
		cout << "3. Exit "<<endl;
		cout <<"Pilih Menu "; cin >> pil;
		switch(pil){
			case 1: enkripsi(); break;
			case 2: deskripsi(); break;
			case 3: stop = true; break;
		}
	}
}
