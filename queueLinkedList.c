#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
} *front=NULL,*rear=NULL;
void enqueue();
void dequeue();
int isempty();
void traverse();
void main()
{
	int ch;
	printf("  QUEUE OPERATION USING LINKED LIST\n");
	printf("-------------------------------------\n");
	printf("enter\n1.insert\n2.delete\n3.display\n4.exit\n");
	do
	{
		printf("\nenter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: enqueue();
				break;
			case 2: if(isempty()==1)
				{
					printf("the list is empty\n");
				}
				else
					dequeue();
				break;
			case 3:traverse();
				break;
			case 4:exit(0);
				break;
			default: printf("wrong input\n");
		}
	}
	while(1>0);
}
void enqueue()
{
	struct node *temp,*p;
	temp= (struct node *)malloc(sizeof(struct node));
	printf("enter the element to insert\n");
	scanf("%d",&temp->data);
	temp->link=NULL;
	if(front==NULL&&rear==NULL)
	{
		rear=front=temp;
	}
	else
	{
		rear->link=temp;
		rear=temp;
	}
}
int isempty()
{
	if(front==NULL&&rear==NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void dequeue()
{
	struct node *temp;
		temp=front;
		printf("the deleted element is %d\n",temp->data);
		front=front->link;
		temp->link=NULL;
		free(temp);
}
void traverse()
{
	struct node *temp;
	if(front==NULL&&rear==NULL)
	{
		printf("list is empty\n");
	}
	else
	{
		temp=front;
		while(temp!=NULL)
		{
			printf("%d\t",temp->data);
			temp=temp->link;
		}
	}
}
