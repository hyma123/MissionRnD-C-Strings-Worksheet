/*
OVERVIEW: Given a float number ,Convert it into a string 

INPUTS: A Float,Final string ,How many digits after decimal has to be displayed .
Its zero for integers.


OUTPUT: No need to output anything ,Modify the str in function parameter such that it
now holds the string format of the float number specified

Example : number_to_str(345,str,0);
Should copy "345\0" in the str;
number_to_str(345.342,str,2);
Should copy "345.34" in the str;
-----------+
NOTES: Don't create new string.

*/
#include <stdio.h>
#include<math.h>
int reverse(int n)
{
	int rev = 0;
	while (n>0)
	{
		rev = rev * 10 + n % 10;
		n /= 10;
	}
	return rev;
}
void number_to_str(float number, char *str, int afterdecimal){
	int i = 0, f, b;
	if (number < 0)
	{
		number *= -1;
		*(str + i) = '-';
		i++;
	}
	f = number;
	b = (number - f)*pow(10.0, afterdecimal);
	f = reverse(f);
	b = reverse(b);
	while (f>0)
	{
		*(str + i) = f % 10 + 48;
		f = f / 10;
		i++;
	}
	if (afterdecimal > 0)
	{
		*(str + i) = '.';
		i++;
		while (b > 0)
		{
			*(str + i) = b % 10 + 48;
			b = b / 10;
			i++;
		}
	}
	*(str + i) = '\0';
}


