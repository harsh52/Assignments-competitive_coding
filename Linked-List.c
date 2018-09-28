//Programme to show middle element of Link-list
#include<stdio.h>
#include<stdlib.h>
struct node 
{
int data;
struct node *link;
};
struct node *head=NULL;

int middle2(struct node *head)
{
	struct node *slow=head;
	struct node *fast=head;
	if(head!=NULL)
		{
		while(fast!=NULL&&fast->link!=NULL)
			{
			fast=fast->link->link;
			slow=slow->link;
			}
		}
	else printf("Link-list is empty");

	printf("\nValue of middle element is: %d\n\n",slow->data);
}
//creating dynamic nodes of link list
void create_node(struct node **temp,int num)
{
	int i;
	struct node *new_node;
	new_node=(struct node *)malloc(sizeof(struct node));
	printf("Enter data in 1st node");
	scanf("%d",&new_node->data);
	*temp=new_node;

	for(i=1;i<num;i++)
	{	//struct node *new_node;
		new_node->link=(struct node *)malloc(sizeof(struct node));
		
		printf("Enter data in %d node",i+1);
		scanf("%d",&(new_node->link->data));
		new_node->link->link=NULL;
		new_node=new_node->link;
		
	
	}
}

//insert node at beginning

int insert_first()
{
	struct node *new_node;
	new_node=(struct node *)malloc(sizeof(struct node));
	printf("Enter data in new node");
	scanf("%d",&(new_node->data));
	new_node->link=head;
	head=new_node;
	printf("\nData inserted successfully\n");

}
void insert_last(struct node **head)
{
	struct node *tail;
	struct node *new_node;
	tail=*head;
	new_node=(struct node *)malloc(sizeof(struct node));
	printf("\nEnter data in last node:\n");
	scanf("%d",&(new_node->data));
	if(tail==NULL)
	{
		tail->link=new_node;
	}
	else
	{
	while(tail->link!=NULL)
	{
		tail=tail->link;
	}
	tail->link=new_node;
	new_node->link=NULL;
	}
}
void reverse(struct node **head)
{
	struct node *curr=*head;
	struct node *prev=NULL;
	struct node *next=NULL;
	if(curr==NULL)
		{
			printf("linked-list is empty");
		}
	else 
		{
			while(curr!=NULL)
			{
				next = curr->link;
				curr->link=prev;
				prev=curr;
				curr=next;
			}
		*head=prev;
		}
}

//Display nodes of Link-list
int Display(struct node *head)
{	
	struct node *temp;
	if(head!=NULL)
	{
		temp=head;
		while(temp!=NULL)
		{
			printf("nodes are: %d\n",temp->data);
			temp=temp->link;	
		}
	}
	else
	{
		printf("Link-list is empty");
	}
}

int main()
{	int mid,num,choice=-1;
	
	/*printf("Enter no of nodes you want to create: \n");
	scanf("%d",&num);
	create_node(&head,num);

	printf("Insert node at beginning\n");
	insert_first(head);
	Display(head);
	middle2(head);*/

	while(choice!=0)
		{
		printf("Choose the following options\n");
		printf("1.create nodes\n2.Insert node at beginning \n3.Find middle element\n4.Insert node at last\n5.Display\n\n6.Reverse linked-list\n0.Exit\n");
		scanf("%d",&choice);
		switch(choice)
			{
				case 1:
					printf("Enter no of nodes you want to create: \n");
					scanf("%d",&num);
					create_node(&head,num);	
					break;

				case 2:
					//printf("Insert node at beginning\n");
					insert_first();
					break;
 
				case 3:
					middle2(head);
					break;
				case 4:
					insert_last(&head);
					break;
				case 5:
					Display(head);
					break;	
				case 6:
					reverse(&head);	
			}
		}
}











