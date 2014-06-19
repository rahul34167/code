#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define NO_OF_CHAR 256

int *getcount(char *s)
{
    int *count = (int*)calloc(sizeof(int) , NO_OF_CHAR);
    int i;
    for(i=0;*(s+i);i++)
    {
        count[*(s+i)]++;               
         }
    return count;
    }

void deletemask(char *str , char *mask)
{
    int *count =  getcount(mask);
     int i=0 ,j=0;
     while(*(str+i))
     { char temp = *(str+i);
     if(count[temp] == 0)
     {
                    *(str+j)=*(str+i);
                    j++;
                    }
      i++;              
                    }
     *(str+j) = '\0';
     printf("%s",str);
     }



int main()
{
    char str[] = "geeks";
    char mask[] = "ek";
    deletemask(str,mask);
    return 0;
    
    }
