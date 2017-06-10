/*
	Question-1: Given an 32-bit signed integer. 
		(i) Return the reverse of the number.
		(ii) Return 0 if the reversed number overflows and for other invalid cases

	Example: 
		(i) INPUT: 123, OUTPUT: 321
		(ii) INPUT: -123, OUTPUT: -321

*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int reverseNumber(int x){
	int res[20], top = -1;
	while (x){
		res[++top] = x % 10;
		x /= 10;
	}
	int sum=0,i=0;
	while (top!=-1)
	{
		sum =sum+ (res[top--] * pow(10.0, i++));
		if (sum == 2147483648){
			return 0;
		}
	}
	return sum;
}