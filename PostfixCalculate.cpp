#include<stdio.h>
#include<string.h>

#define Slen 30
//Infýxden Postfixe donusum
// infix:   a+b
// postfix: ab+
//prefix:   +ab

//KURALLAR
//Yalnýzca operandlar yýgýna eklenir,
//1-Yýgýna gönderilen operatörün onceligi yýgýn icindekinden buyukse ise yýgýna eklenir, kucuk veya esit ise yýgýndan cýkarýlýr
//2-Kapama parantezi ile karþýlaþýldýgýnda acma parantezine kadar olan tüm yýgýndaki ifadeler yýgýndan çýkarýlarak sonuca yazýllýr.
//3- Tum ifadeler islendiginde(ýslem bittiginde) yýgýn bos degýlse yýgýnda kalan tum operatorler yýgýndan cýkarýlarak sonuca yazýlýr
 
typedef struct stack{
	int index;
	char element[Slen];
}Stack;

Stack numbers;
int StackIsEmpty(){
	if(numbers.index==-1) return -1;
	else return 1;
}
int StackIsFull(){
	if(numbers.index==(Slen-1))return -1;
	else return 1;
}
void push(int number){
	if(StackIsFull()==Slen-1)
	printf("Yigin Dolu\n");
	else{
		numbers.index++;
		numbers.element[numbers.index]=number;
	
	}
}
int pop(){
	if(numbers.index==-1){
		printf("Yigin bos\n");
	}
	else
	{
		int outStack=numbers.element[numbers.index];
		numbers.index--;
		return outStack;
	}

}
int calculate(int number1,char oprtr,int number2){
	switch(oprtr){
		int sonuc;
		case '+': sonuc=number1+number2;
		return sonuc; break; 
		case '-': sonuc=number1-number2;
		return sonuc; break;
		case '*': sonuc=number1*number2; return sonuc; break;
		case '/': sonuc=number1/number2;
		return sonuc; break;
	}
}
int main(){
	
	numbers.index=-1;
	char str[20];
	printf("Postfix bir ifade giriniz");
	gets(str);
	int len=strlen(str);
	for(int i=0;i<len;i++){
		if(str[i]<58 && str[i]>47){ //Eger sayýysa(0-9)
			int number=str[i]-'0'; //char sayiyi ayný int sayýya donusturur
								   //(exmp: char sayi='9'  sayi-'0' ==> int 9 donusumudur
			push(number);
		}
		else{  //eger operator ise (*,-,+,/)
		int operand2=pop();  //yýgýnýn ustundeki saga 
		int operand1=pop(); //bir altýndaki sola koyulup gereklý ýslem yapýlýr
		char oprtr=str[i]; 
		int value=calculate(operand1,oprtr,operand2);	
		push(value);
		}
	}
	int result=pop();
	printf("Sonuc:%d",result);
	
}



