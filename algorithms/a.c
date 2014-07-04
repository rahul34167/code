#include<stdio.h>
int main()
{
char* ptr= {"samsung","electronics","india"};
char** ptr1;
ptr1=ptr;

printf("%c",++*ptr1);
return 0;
}
