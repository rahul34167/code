#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void revers(char *a , char *b);
void reversewords(char * str)
{
	char *beg = str;
	char *end = str;
	
	while(*end)
	{
		end++;
		
		if(*(end) == '\0')
		revers(beg,end-1);
		
		if(*(end) == ' ')
		{
		revers(beg , end-1);
		beg=end+1;
		}
		
	}
	beg = str;
	revers(beg , end-1);
}



void revers(char *a , char *b)
{
char temp;	
	while(a < b)
{
temp =  *a;
*a++ = *b;
*b-- = temp;
}
}

int main()
{
	char str[] = " a fox quickly jumps";
	char * s = str;
	reversewords(s);
	printf("%s",s);
	return 0;
}
