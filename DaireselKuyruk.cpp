//DAÝRESEL KUYRUK YAPISI

//Dizi uzerinde kaydýrma gereksiz yere her alma isleminde kuyruktaki veri sayýsýndan bir eksik kaydýrma islemine gerek duyar
//Bu nedenle uzun kuyruk islemlerinde olumsuz sonuc verir.Dairesel kuyruk yapýsýnda dizinin son elemanýnýn 
//bir sonraki elemaný dizinin ilk elemanýdýr.Boylece kuyrukta bir daire varmýs gibi hareket edilebilir.
//Kaydýrma islemi yerine kuyruktaký ilk  elemaný gosteren ikinci bir degisken kullanýlýr.kuyruktan alma islemi bu degiskenin gösterdigi gozden yapýlýr

#include<stdio.h>
#include<stdlib.h>
#define Kboyut 5
typedef struct Kuyruk{
	int son; //eklemek için indis
	int bas; //çikarmak için indis
	int sayi; //eleman sayisi
	int eleman[Kboyut];
}kuyruklar;

kuyruklar newkuyruk;
int KuyrukBosMu(){
	if(newkuyruk.sayi==0)return -1; //Bos
	return 1; //Bosdegil
}
int KuyrukDoluMu(){
	if(newkuyruk.sayi==Kboyut)return -1; //Dolu
	return 1; //Doludegil
}
void KuyrugaEkle(int ekle){
	if(KuyrukDoluMu()==-1)
	printf("Kuyruk Dolu");
	else{
		newkuyruk.son=(newkuyruk.son+1)%Kboyut;
	newkuyruk.eleman[newkuyruk.son]=ekle;
	newkuyruk.sayi++;
	}
	
}
int KuyruktanCikar(){
	if(KuyrukBosMu()==-1){
		printf("Kuyruk Bos");
	}
	else{
		newkuyruk.bas=(newkuyruk.bas+1)%Kboyut;
	int cikaneleman=newkuyruk.eleman[newkuyruk.bas];
	newkuyruk.sayi--;
	return cikaneleman;
	}

}
void Listele(){
	for(int i=1;i<=newkuyruk.sayi;i++){
		printf("\n %d",newkuyruk.eleman[(newkuyruk.bas+i)%Kboyut]); //Diziden çýkarýlacak sýraya göre listeler
	}
}
int main(){
	char secim;
	int sayi,cikan;
	newkuyruk.son=-1;
	newkuyruk.bas=-1;
	newkuyruk.sayi=0;
	while(true){
		printf("\nEklemek:e\nSilmek:s\nListelemek:l\nCikis:c");
		secim=getchar();
		switch(secim){
			case 'e': printf("Eklemek istediginiz sayiyi giriniz"); scanf("%d",&sayi);
					  getchar();
					  KuyrugaEkle(sayi); break;
					  
			case 's': cikan=KuyruktanCikar(); getchar();
				      printf("Kuyruktan Cikarilan Eleman: %d\n",cikan); break;
				      
			case 'l': Listele(); getchar(); break;
			
			case 'c':exit(0);
		}
	}
}
