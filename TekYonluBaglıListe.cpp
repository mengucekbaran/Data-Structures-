#include<stdio.h>
#include<stdlib.h>
typedef struct Liste{
	int numara;
	struct Liste *sonraki;
}BListe;

BListe *ilk=NULL,*son=NULL;

BListe *BilgiAl(int num){
	BListe *bilgi=(BListe *)malloc(sizeof (BListe));
	bilgi->numara=num;
	bilgi->sonraki=NULL;
	return bilgi;
}

void Ekle(BListe * bilgi){
	if(ilk==NULL){
		ilk=bilgi;
		son=ilk;
	}
	else{
		son->sonraki=bilgi;
		son=bilgi;
		
	}
}
int Listele(){
	BListe *gecici;
	gecici=ilk;
	if(gecici==NULL) return 0;
	else
	{
		while(gecici){
			printf("%d ",gecici->numara);
			gecici=gecici->sonraki;
		}
		return 1;
	}
}
BListe * Ara(int num){
	BListe *gecici;
	gecici=ilk;
	while(gecici){
		if(gecici->numara==num) return gecici;
		gecici=gecici->sonraki;
	}
	return NULL;
}
void Sil(int silnum){
	
	BListe *gecici,*bironceki;
	gecici=ilk;
	bironceki=NULL;
	while(gecici){
		if(gecici->numara==silnum) break;
		bironceki=gecici;
		gecici=gecici->sonraki;
	}
	if(gecici!=NULL){  // silinecek kayýt bulunduysa
		if(gecici==ilk){ //silinecek kayýt ilk kayýtsa
			if(ilk==son){
				ilk=NULL;
				son=NULL;
			}
			else{
				ilk=ilk->sonraki;
			}
		}
		else if(gecici==son){ //silinecek kayýt son kayýtsa
			bironceki->sonraki=NULL;
			son=bironceki;
		}
		else{ //silinecek kayýt aradaysa
			bironceki->sonraki=gecici->sonraki;
		}
	}
	free(gecici);
}
int main(){
	char secim;
	BListe * bul;
	int silnum;
	while(1==1){
	
	printf("Ekleme:e\nArama:a\nListeleme:l\nSilme:s\nCikis:c\n");
	secim=getchar();
	switch(secim){
		int numara,aranannum;
		case 'e': printf("Eklemek istediginiz numarayi giriniz");
				  scanf("%d",&numara); getchar();
				  Ekle(BilgiAl(numara)); break;
		case 'l': Listele();
				  getchar(); break;
		case 'a': printf("Aramak istediginiz numarayi giriniz"); 
				  scanf("%d",&aranannum); 
				  bul=Ara(aranannum);
				  if(bul!=NULL) printf("Aranan numara bulundu\n");
				  else printf("Aranan numara bulunamadi\n");
				  break;	
		case 's': printf("Silmek istediginiz numarayi giriniz");
				  scanf("%d",&silnum);getchar();
				  Sil(silnum);	break;
		case 'c': exit(0);
				  		
	}
	}
}
