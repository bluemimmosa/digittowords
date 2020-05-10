/*
Niraj Khadka (c) 2020
Program to convet digits into words based on recursive function.
*/

#include <stdio.h>
#include <string.h>
void convert(char *s, unsigned int n);

const char units[][20] = {"", " one", " two", " three", " four", " five", " six", " seven", " eight", " nine", " ten", " eleven", " twelve", " thirteen", " fourteen", " fifteen", " sixteen", " seventeen", " eighteen", " nineteen"};
const char tens[][10] = {"", "", " twenty", " thirty", " fourty", " fifty", " sixty", " seventy", " eighty", " ninety"};
char words[100];

int main(){
	//only works up to double digit crore elements.
	
	int i;
	unsigned int num;
	printf("Enter a amount: ");
	scanf("%u", &num);
	convert(words, num);
	
	printf("\nThe above digits in words is: \n");
	puts(words);
	
	
	
	
	
	
	return 1;
}

void convert(char *s, unsigned int n){
	if(n<20){
		strcat(s, units[n]);
		return;
	}
	if(n<100){
		 strcat(words,tens[n/10]);
		 if(n%10 !=0){
		 	strcat(words, units[n%10]);
		 }
		 return;
	}
	if(n<1000){
		strcat(words, units[n/100]);
		strcat(words, " hundred");
		if(n%100 != 0){
			convert(words, n%100);
		}
		return;		
	}
	if(n<100000){
		convert(words, n/1000);
		strcat(words, " thousand");
		if(n%10000 != 0){
			convert(words, n%1000);
		}
		return;
	}
	if(n<10000000){
		convert(words, n/100000);
		strcat(words, " lakhs");
		if(n%100000 != 0){
			convert(words, n%100000);
		}
		return;
	}
	if(n<1000000000){
		convert(words, n/10000000);
		strcat(words, " crore");
		if(n%10000000 != 0){
			convert(words, n%10000000);
		}
		return;
	}
}
