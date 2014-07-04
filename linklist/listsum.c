//program to add two nos using link list
//it inserts nos at the end of list 

#include<stdio.h>
#include<stdlib.h>

struct node 
{
	int data;
	struct node * next;
	int count;
};

void printlist(struct node *head);
struct node * push(struct node *head , int item)
{    
	struct node *newnode = (struct node *)malloc(sizeof(struct node));
	
	if(newnode == NULL)
	{
		printf("memory not allocated for the node");
	}
	newnode->data = item;
	
	if(head == NULL)
	{
		head = newnode;
		head->next = NULL;
		
	}
	
	else if(head->next == NULL)
	{
		
		head->next = newnode;
		newnode->next = NULL;

	}
	else
	{
		struct node *current = head;
		
		while(current->next!=NULL)
		{
			current = current->next;	
		}
		current->next= newnode;
		newnode->next = NULL;
	}
	return head;
}


struct node * reverse(struct node **headref)
{
	
	struct node *prev =NULL;
	struct node *current = *headref;
	struct node *next;
	while(current!=NULL)
	{
		next = current->next;
		current->next = prev;
		prev=current;
		current = next;
	}
	
	*headref = prev;
	return (*headref);
}

void findsum(struct  node *list1 , struct node *list2, int count1 , int count2)
{
	int sum = 0;
	int carry =0;
	struct node *current1 = list1;
	struct node *current2 = list2;
	struct node * head3=NULL;
	if(count1 == count2)
	{
	while(current1!=NULL)
		{
			sum = current1->data + current2->data  +carry;
			if(sum<=9)
	{
head3=push(head3,sum);
	current1=current1->next;
	current2 = current2->next;
}
            else 
                {    carry = sum / 10;
                    sum = sum%10;
               head3= push(head3,sum);
	               current1= current1->next;
	               current2 = current2->next;
	
                }

	}
	if(carry == 1)
head3 =	push(head3,carry);
	}
	
struct node *h = reverse(&head3);
	printlist(h);
}


void insertintolist(int num1 , int num2)
{
	int n1 = num1;
	int n2 = num2;
	int count1=0;
	int count2 = 0;
 struct node *head1=NULL;
struct node *head2=NULL;
	while(n1!=0 )
		{
		int x = n1%10;
		n1 = n1/10;
	 head1 =push(head1,x);
		count1++;
	}
	
	printlist(head1);
//	printf("%d",count1);
		while(n2 !=0)
	{
		
		int y = n2%10;
		n2= n2/10;
head2 =	push(head2,y);
		count2++;
	}
	printlist(head2);
//printf("%d",count2);


  findsum(head1,head2,count1,count2);

}


void printlist(struct node *head)
{
	
	struct node *current = head;
	while(current!=NULL)
	{
		printf("%d \t",current->data);
		current= current->next;
	}
	printf("\n");
}



int main()
{
	
	int num1 = 65;
	int num2 = 65;
	
	insertintolist(num1, num2);
	
return 0;	
}
