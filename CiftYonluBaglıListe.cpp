#include<stdio.h>
#include<stdlib.h>
typedef struct Liste{
	int numara;
	struct Liste *sonraki;
	struct Liste *onceki;
}Bliste;
Bliste *ilk=NULL,*son=NULL;

Bliste *BilgiAl(int num){
	Bliste *bilgi=(Bliste *)malloc(sizeof(Bliste));
	bilgi->numara=num;
	bilgi->sonraki=NULL;
	bilgi->onceki=NULL;
	return bilgi;
}
void Ekle(Bliste *bilgi){
	if(ilk==NULL){
		ilk=bilgi;
		son=ilk;
	}
	else{
		son->sonraki=bilgi;
		bilgi->onceki=son;
		son=bilgi;
		
	}
}
void Listele(){
	Bliste *gecici=ilk;
	while(gecici){
		printf("%d\t",gecici->numara);
		gecici=gecici->sonraki;
	}
}
Bliste *Arama(int num){
	Bliste *gecici=ilk;
	while(gecici){
		if(gecici->numara==num){	
			return gecici;
		}
		gecici=gecici->sonraki;
	}
	return NULL;
}
void Sil(int num){
	Bliste *gecici;
	gecici=Arama(num);
	
	if(gecici!=NULL) { //silinecek kay�t bulunduysa
		if(gecici==ilk){ //silinecek kay�t ilk kay�tsa
			if(ilk==son){ // silinecek kay�t ilk ve tek kay�tsa
				ilk=NULL;
				son=NULL;
			}
			else{ // silinecek kay�t ilk ve birden �ok kay�t varsa
				ilk=gecici->sonraki;
			}
		
		}
		else{  //silinecek kay�t ilk kay�t degilse
			if(gecici!=son){ // silinecek kay�t son kay�t degilse
				gecici->onceki->sonraki=gecici->sonraki;
				gecici->sonraki->onceki=gecici->onceki;
			
		}
			else{ //silinecek kay�t son kay�tsa
				son=gecici->onceki;
				son->sonraki=NULL;
			
				}
		}
	}
	
}

int main(){
	
	int num;
	char secim;
	while(true){
		printf("\nArama:a\nListeleme:l\nEkleme:e\nSilme:s\nSecim= ");
		scanf("%c",&secim);
		switch(secim){
			
			case 'e': printf("Eklemek istediginiz numarayi giriniz"); 
					scanf("%d",&num); 
					getchar();
					Ekle(BilgiAl(num));
					
					break;
			
			case 'a': printf("Aramak istediginiz degeri giriniz"); 
					scanf("%d",&num);
					getchar();
					
						break;
			
			case 'l': 	getchar();
						Listele(); break;
			
			case 's': printf("Silmek istediginiz degeri giriniz");
					  scanf("%d",&num);
					  getchar();
					  Sil(num); break;
		}
	}
	
}
