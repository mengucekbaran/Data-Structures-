#include<stdio.h>
#include<stdlib.h>

#define Yboyut 16

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

void Cevir(int sayi){
	int digit; //kalan tutar
	while(sayi>0){
		digit=sayi%2;
		Ekle(digit);
		sayi=sayi/2;
	}
Listele();
}
int main(){
	Yeni_Yigin.indis=-1;
	int sayi;
	printf("Ikilige cevrilecek sayiyi giriniz"); 
	scanf("%d",&sayi);
	Cevir(sayi);
	
	
}
