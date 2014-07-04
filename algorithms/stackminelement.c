//program to return the minimum element from the stack 
#include<stdio.h>
#include<stdlib.h>
#define bool int 
struct stack
{
	unsigned int capacity;
	int top;
	int *array;
};

/*struct twostack
{
	struct stack *stack1;
	struct stack *stack2;
};*/

void push(struct stack *s , int item);

struct stack *createstack(unsigned int capa)
{
	
	struct stack * s = (struct stack *)malloc(sizeof(struct stack));
	s->capacity = capa;
	s->top=-1;
	s->array = (int *)malloc(sizeof(int) * s->capacity);
	return s;
}


bool isfull(struct stack *s)
{
	return s->top == s->capacity;
	}
	
	void printstack(struct stack *s )
	{
		int i;
	 do
	{
		printf("%d \n",s->array[s->top--]);
	}while(s->top!=-1);
	
	}
	
	void findmin(struct stack *s1 ,struct stack *s2)
	{
	int i = s1->top;
	struct stack * s = s1;
	s->top = 0;
	push(s2,s->array[s->top]);
	
	while(s2->top != i)
	{
		if(s->array[++s->top] < s2->array[s2->top])
		push(s2,s->array[s->top]);
		else
		push(s2,s2->array[s2->top]);
		
	}
	
	printf("%d",s2->array[s2->top]);
	}
	
	
void push(struct stack *s , int item)
{
	if(s==NULL)
	return;
	if(isfull(s))
	printf("stack overflow");
	else
	s->array[++s->top] = item;
}

int main()
{
	struct stack * s1 = createstack(5);
	struct stack *s2 = createstack(5);
	
	push(s1,2);
	push(s1,1);
	push(s1,3);
	push(s1,7);
	push(s1,5);
	
//	printstack(s1);
	findmin(s1,s2);
return 0;
}
