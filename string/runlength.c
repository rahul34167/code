#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_LEN 50
char *encode(char *str)
{
	int len = strlen(str);
	char count[MAX_LEN];
	int i,k;
	char *dest = (char*)malloc(sizeof(char) * (len*2) + 1);
	 int j=0;
	for(i=0;i<len;i++)
	{
		dest[j++] = str[i];
		
		int rlen=1;
		while(i+1 <len && str[i] == str[i+1]) 
		{
		rlen++;
		i++;
	    }
	    
	    sprintf(count,"%d",rlen);
	    
	    for(k=0;*(count+k);k++,j++)
	    {
	    	dest[j]=count[k];
	    }
	}
	    dest[j] = '\0';
	    return dest;
	
	
	
	
}



int main()
{
	char str[] = "aaabbc";
char * s =	encode(str);
printf("%s",s);
return 0;
}
