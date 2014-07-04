#include<stdio.h>
#include<stdlib.h>



int turnoff(int n , int k)
{
	return (n &  ~(1<<(k-1)));	
}


int main()
{
	int n =15;
	int k =4;
	int x =10;
	printf("%d \n", x>>3);
	printf("%d",turnoff(n,k));
	return 0;
	
}
