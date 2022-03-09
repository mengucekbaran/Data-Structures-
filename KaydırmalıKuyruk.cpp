//Kaydýrmalý Kuyruk Yapýsý

#include<stdio.h>
#include<stdlib.h>
#define Kboyut 10

typedef struct Kuyruk{
	int son;//indis degiskeni
	int eleman[Kboyut];
}Kuyruklar;

Kuyruklar newkuyruk;


void Ekle(int sayi){
	if(newkuyruk.son<Kboyut-1){
		newkuyruk.son++;
		newkuyruk.eleman[newkuyruk.son]=sayi;
	}
	else{
		printf("Kuyruk Dolu\n");
	}	
}

void Sil(){
		if(newkuyruk.son==-1){
		printf("Kuyruk Bos\n");
		}
	else
	{
		for(int i=0;i<=newkuyruk.son;i++){
		newkuyruk.eleman[i]=newkuyruk.eleman[i+1];
		
		}
		newkuyruk.son--;
	}
}

void Listele(){
	for(int i=0;i<=newkuyruk.son;i++){
		printf("%d\t",newkuyruk.eleman[i]);
	}
}

int main(){
	char secim;
	int sayi;
	newkuyruk.son=-1;
	while(true){
		printf("Ekle:e\nCikar:s\nListele:l\nCikis:c\n");
		secim=getchar();
		switch(secim){
			case 'e': printf("Kuyruga eklemek istediginiz sayiyi giriniz");
					  scanf("%d",&sayi); getchar(); Ekle(sayi); break;
			
			case 's': Sil(); getchar(); break;
			
			case 'l': Listele(); getchar(); break;
			
			case 'c': exit(0);
		}
	}
}
