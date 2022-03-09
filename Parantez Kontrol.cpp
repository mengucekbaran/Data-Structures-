#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define Yboyut 10
typedef struct Yigin{
	int indis;
	char eleman[Yboyut];
}Yiginlar;
Yiginlar Yeni_Yigin;

int YiginBosMu(){
	if(Yeni_Yigin.indis==-1) return -1; //Yigin Bos
	return 1; //Yigin Bos Degil 
}
void YiginaEkle(char ekle){
	Yeni_Yigin.indis++;
	Yeni_Yigin.eleman[Yeni_Yigin.indis]=ekle;
}
int YigindanCikar(){
	if(YiginBosMu()==-1) return -1;
	else{
		Yeni_Yigin.indis--;
	}
}
int ParantezKontrol(char *islem){
	int i=0;
	while(i<strlen(islem)){
		if(islem[i]=='('){
			YiginaEkle(islem[i]);
		}
		else{
			if(islem[i]==')'){
				if(YiginBosMu()==-1) return -1; //Açma Parantezi Eksik
				YigindanCikar();
			}
		}
		i++;
	}
	if(YiginBosMu()==-1) return 0; //Parantez Hatasi Yok
	return 1; //Kapama Parantezi Eksik
}
int main(){
	//char *islem="((merhaba))))";
	char *islem;
	Yeni_Yigin.indis=-1;
	islem=(char*)malloc(sizeof(char));
	printf("Gir ");
	scanf("%s",islem);
	int sonuc=ParantezKontrol(islem);
	switch(sonuc){
		case -1: printf("Acma Parantezi Eksik"); break;
		case 0:  printf("Parantez Hatasi Yok"); break;
		case 1:  printf("Kapama Parantezi Eksik"); break;
		
	}
	
	}
