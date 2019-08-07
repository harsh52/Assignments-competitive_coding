#include<stdio.h>
#include<stdlib.h>

//structure of stack
struct stack
{
	int top;
	int capacity;
	int *array;
};
struct stack *head=NULL;

void create_stack(struct stack **head,int num)
{
	struct stack *temp;
	temp=(struct stack *)malloc(sizeof(struct stack));
	*head=temp;
	temp->top=-1;
	temp->capacity=num;
	temp->array=(int *)malloc((temp->capacity)*sizeof(int));
	printf("\nstack created successfully\n");

}

//function to check stack is full or not

int isfull()
{
	if(head->top==(head->capacity)-1)
	{
		//printf("Satck is FULL");
		return 0;
	}
}

//function to check stack is empty or not
int isempty()
{
	if(head->top == -1)
		return 1;
	
}

//Function to insert an item into stack
void push(int item)
{
	if(isfull())
	{
		head->top = (head->top) + 1;
		head->array[head->top] = item;
		printf("\n %d item is pushed\n",item);
	}
	else
	{
		printf("\n\nStack is already FULL\n\n");
	}
}

//function to remove top element from stack
void pop()
{	
	if(head->top==0)
	{
		printf("Stack is empty");
	}
	else
	{
		printf("\n%d element id poped out\n",head->array[head->top]);
		head->top=(head->top) - 1;
	}
	
}

void Display(int element)
{
	
	int temp=0;
	
	while(temp != (head->top)+1)
	{
		printf("\nElements are:%d\n",head->array[temp]);
		temp++;
	}

}

int main()
{
	unsigned int num,item;
	int i;
	int choice=-1;

	while(choice !=0)
	{
		printf("\n\nEnter your choice\n\n");
		printf("1.Create stack\n2.Push element into the node\n3.Pop an item\n4.Display an item\n0.EXIT\n");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				printf("Enter capacity of stack");
				scanf("%u",&num);
				create_stack(&head,num);
				break;

			case 2:
				printf("\nEnter how many element you want to push: \n");
				scanf("%u",&num);
				for(i=0;i<num;i++)
				{
					printf("Enter %d element to push",i+1);
					scanf("%u",&item);
					push(item);
				}
				break;

			case 3:
				pop();
				break;

			case 4:
				Display(num);	
				break;
		}
	}
	
} 