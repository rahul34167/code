#include<stdio.h>
#include<stdlib.h>

void reverse(char *str)
{

if(*(str))
{
reverse(str+1);
printf("%c",*(str));
}

}


int main()
{
char str[] = "rahul";
reverse(str);
return 0;
}
