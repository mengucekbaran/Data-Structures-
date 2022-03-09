#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

#define Yboyut 5

typedef struct Yigin{
	int indis;
	int eleman[Yboyut];
}Yiginlar;

Yiginlar Yeni_Yigin;


int YiginDoluMu(){

	if(Yeni_Yigin.indis>=Yboyut-1) return -1;
	else return 1;
}
int YiginBosMu(){
	if(Yeni_Yigin.indis==-1) return -1;
	else return 1;
}
void Ekle(int sayi){
	if(YiginDoluMu()==-1){
		printf("Yigin Dolu");
	}
	else{
		Yeni_Yigin.indis++;
		Yeni_Yigin.eleman[Yeni_Yigin.indis]=sayi;
	}
}
int Cikar(){
	if(YiginBosMu()==-1){
		printf("Yigin Bos Cikarma Yapilamaz"); return 0;
	}
	else{
		int cikan_eleman=Yeni_Yigin.eleman[Yeni_Yigin.indis];
		Yeni_Yigin.indis--;
		return cikan_eleman;
		
	}
}
void Listele(){
	for(int i=Yeni_Yigin.indis;i>=0;i--){
		printf("%d\t",Yeni_Yigin.eleman[i]);
	}
}
int main(){
	char secim;
	int sayi;
	Yeni_Yigin.indis=-1;
	while(true){
	printf("\nYigina Ekleme:e\nYigindan Cikarma:s\nListeleme:l\nCikis:c\n Secim= "); scanf("%c",&secim);
		switch(secim){
			case 'e':
				printf("Eklemek istediginiz elemani giriniz"); 
				scanf("%d",&sayi); getchar();
				Ekle(sayi);
				break;
			
			case 's': if(Cikar()!=0)
				printf("Cikan eleman=%d",Cikar()); getchar(); break;
			
			case 'l': Listele(); getchar(); break;
			
			case 'c': exit(0);
			    
				
			
		}
	}
	
}
