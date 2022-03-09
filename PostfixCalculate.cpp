#include<stdio.h>
#include<string.h>

#define Slen 30
//Inf�xden Postfixe donusum
// infix:   a+b
// postfix: ab+
//prefix:   +ab

//KURALLAR
//Yaln�zca operandlar y�g�na eklenir,
//1-Y�g�na g�nderilen operat�r�n onceligi y�g�n icindekinden buyukse ise y�g�na eklenir, kucuk veya esit ise y�g�ndan c�kar�l�r
//2-Kapama parantezi ile kar��la��ld�g�nda acma parantezine kadar olan t�m y�g�ndaki ifadeler y�g�ndan ��kar�larak sonuca yaz�ll�r.
//3- Tum ifadeler islendiginde(�slem bittiginde) y�g�n bos deg�lse y�g�nda kalan tum operatorler y�g�ndan c�kar�larak sonuca yaz�l�r
 
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
		if(str[i]<58 && str[i]>47){ //Eger say�ysa(0-9)
			int number=str[i]-'0'; //char sayiyi ayn� int say�ya donusturur
								   //(exmp: char sayi='9'  sayi-'0' ==> int 9 donusumudur
			push(number);
		}
		else{  //eger operator ise (*,-,+,/)
		int operand2=pop();  //y�g�n�n ustundeki saga 
		int operand1=pop(); //bir alt�ndaki sola koyulup gerekl� �slem yap�l�r
		char oprtr=str[i]; 
		int value=calculate(operand1,oprtr,operand2);	
		push(value);
		}
	}
	int result=pop();
	printf("Sonuc:%d",result);
	
}



