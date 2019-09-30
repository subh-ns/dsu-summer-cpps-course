#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
};
void begining();
struct node *read();
int length();
void display();
void end();
void position();
void delete();
struct node *start;
void main()
{
	int ch;
	do
	{
		printf("\n1.BEGINING INSERTION\n2.DISPLAY\n3.END INSERTION\n4.POSTION INSERTION\n5.DELETE\n6.EXIT\n");
		scanf("%d", &ch);
		switch(ch)
		{
		case 1: begining();
			break; 
		case 2: display();
			break;
		case 3: end();
			break;
		case 4: position();
			break;
		case 5: delete();
			break;
		case 6: exit(1);
		}
	}while(ch!=6);
}
void begining()
{	
	struct node *p,*q;
	int item;
	/*temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter the item\n");
	scanf("%d",&item);
	temp->data=item;
	temp->link=NULL;*/
	p=read();
	q=start;
	if(start==NULL)
	{
		start=p;
	}
	else
	{
		p->link=q;
start=p;
	}
}
struct node *read()
{
	int item;
	struct node *temp,*details;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter the value\n");
	scanf("%d", &item);
	temp->data=item;
	temp->link=NULL;
	details=temp;
	return details;
}
void display()
{
	struct node *q=start;
	int len=length();
	if(q==NULL)
	{
		printf("Linked list is empty\n");
	}
	else
	{
		while(q!=NULL)
		{
			printf("%d\t", q->data);
			q=q->link;
		}
	printf("The length of the linked list is:%d\n",len);
}
}
 int length()
{
	int count=0;
	struct node *q;
	q=start;
	while(q!=NULL)
	{
		count++;
		q=q->link;
	}
	return count;
}
void end()
{
	struct node *p, *q;
	p=read();
	q=start;
if(start==NULL)
{
start=p;
}
else
{
	while(q->link!=NULL)
	{	
		q=q->link;
	}
		start->link=p;
}}
void position()
{
	int loc;
	int len=length();
	struct node *p,*q;
	printf("Enter the location\n");
	scanf("%d", &loc);
	if(loc>len)
	{
		printf("Invalid location\n");
	}
	else
	{
		p=read();
		q=start;
		int i=1;
		while(i<len-1)
	{	
		q=q->link;
		i++;
	}
		p->link=q->link;
		q->link=p;
	}
}
void delete()
{
	int loc;
	int len=length();
	printf("Enter the location\n");
	scanf("%d", &loc);
	if(loc>len)
	{
		printf("Invalid\n");
	}
	else if(loc==1)
	{
	struct node *q;
	q=start;
	start=q->link;
	q->link=NULL;
	free(q);
	}
	else
	{
	int i=1;
	struct node *t,*q;
	q=start;
	while(i<loc-1)
		{
		q=q->link;
		i++;
		}
	t=q->link;
	q->link=t->link;
	t->link=NULL;
	free(t);
	}
	}











