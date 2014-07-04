#include<stdio.h>
#include<stdlib.h>

void countsetbit(int n)
{
	
	int j;
	int count=0;
	for(j=0;j<4;j++)
	{ int i=1;
        i=i<<j;	
		if((n& i) == i)
		count++;
		
		
	}
printf("%d",count);
}


int main()
{
	
	
	int num = 15;
	countsetbit(num);
	return 0;
}
