/*

	Question-2:	
		Given two integer numbers in string format of equal number of digits. 
		Return the number string which is the sum of given inputs

		Ex - 1: 
			INPUT-1:	"123"
			INPUT-2:	"111"
			OUTPUT:		"234"

		Ex - 2:
			INPUT-1:	"500"
			INPUT-2:	"500"
			OUTPUT:		"1000"

		First letter can be a sign (+,-) or an integer. Dont convert strings and store them in ints, It wont work for long numbers.
		Output string should only have sign character at first only if its negative.

		NOTES:
			1.	Write utility function for length, sign check etc to increase modularity
			2.	Dont use any header files like string.h etc
			3.  Numbers can be negative too.
			4.  Use malloc to create a new string.
*/

#include <stdio.h>
#include <stdlib.h>
int length(char *s){
	int c = 0;
	while (s[c] != '\0'){
		c++;
	}
	return c;
}
char * addNumberStrings(char *a, char *b){

	//  Write your logic here. Dont write any main function
	// Use malloc to create a new string and return it.
	if (a == NULL&&b==NULL){
		return NULL;
	}
	else if (a == NULL){
		return b;
	}
	else if (b == NULL){
		return a;
	}
	else{
		char *c;
		c = (char*)malloc(sizeof(char)*1000);
		if ((a[0] == '+'&&b[0] == '+') ||(a[0]>47&&b[0]>47)){
			int l = length(a);
			if (a[0] > 47 && b[0] > 47){
				c[l] = '\0';
				for (int i = l - 1; i >= 0; i--){
					c[i] = ((a[i] - '0') + (b[i] - '0')) + '0';
				}
				return c;
			}
			else{
				c[l-1] = '\0';
				for (int i = l - 1; i!= 0; i--){
					c[i-1] = ((a[i] - '0') + (b[i] - '0')) + '0';
				}
				return c;
			}
		}
		else if (a[0] == '-'&&b[0] == '-'){
			int l = length(a);
			c[l] = '\0';
			for (int i = l-1; i != 0; i--){
				c[i] = ((a[i] - '0') + (b[i] - '0')) + '0';
			}
			c[0] = '-';
		}
		else{
			int l = length(b);
			c[l] = '\0';
			for (int i = l-1; i >= 0; i--){
				c[i] = (abs(a[i+1] - '0') - abs(b[i] - '0')) + '0';
			}
			return c;
		}
	}
}




