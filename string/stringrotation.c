#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define bool int
bool checkrotation(char *str1 ,char *str2)
{
int size1 = strlen(str1);
int size2 = strlen(str2);
if(size1!=size2)
return 0;
char * temp = (char *)malloc(sizeof(char) * (size1*2 +1));
temp[0] = '\0';
strcat(temp , str1);
strcat(temp , str1);

if(strstr(temp,str2))
return 1;
else 
return 0;
}


int main()
{
char str[]  = "ABCD";
char chkstr[] = "BCAA";

if(checkrotation(str,chkstr))
printf("they are rotation of each other");
else
printf("not a rotation string");
return 0;
}
