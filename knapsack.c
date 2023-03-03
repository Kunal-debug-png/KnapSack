#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#define NULL 0
typedef struct node
{
	float value;
	float weight;
	float ratio;
	struct node *next;
}node;
node *first=NULL;
node *createNode(float x,float y)
{
	node *pnode;
	pnode = (node*)malloc(sizeof(node));
	if(pnode==NULL)
		return NULL;
	pnode->value=x;
	pnode->weight=y;
	pnode->ratio=x/y;
	return pnode;
}
void insertAtBegg()
{
	float n1,n2;


	printf("\nEnter the value");
	scanf("%f",&n1);
	printf("\nEnter the weight");
	scanf("%f",&n2);
	node *pnode;
	pnode=createNode(n1,n2);
	if(pnode==NULL)
	{
		printf("memory overflow");
		return;
	}

	if(first==NULL)
	{
		first=pnode;
	}
	else
	{
		pnode->next=first;
		first=pnode;
	}
	printf("\n Node Inserted");
}
void display()
{
	node *current=first;

	while(current->next!=NULL)
	{
		printf(" %f ",current->value);
		printf(" %f ",current->weight);
		printf(" %f ",current->ratio);
		printf("\n");
		current=current->next;

	}

}




void sort()
{
	node *current=first,*current1=NULL;
	float temp;

	float v,w,r;
	while(current!=NULL)
	{
		current1=current->next;
		while(current1!=NULL)
		{

		if(current->ratio < current1->ratio)
		{
			//temp   , temp=A
		       v=current->value;
		       w=current->weight;
		       r=current->ratio;


			//a=b
			current->value=current1->value;
			current->weight=current1->weight;
			current->ratio=current1->ratio;


			//b=temp
			current1->weight=w;
			current1->value=v;
			current1->ratio=r;



		}
		current1=current1->next;

		}
		current=current->next;
	 }
}


void knapsack(int n)
{
	node *current=first;
	node *current1=first;
	int c1=1;
	int temp;
	float profit=0;
	int max=n;
	int count=0;
	int count1=0;
	while(current!=NULL)
	{
		count1=count1+current->weight;
		if(count1 < max)
		{
			count=count+current->weight;
			profit=profit+current->value;
		}
		else
		{
		     if(c1<2)
		     {
			temp=max-count;

			printf(" %f",current->value);
			profit= profit +(temp*current->value)/current->weight+0.0 ;
			c1++;
		     }
		}
		current=current->next;
	}

	
	printf(" %f",profit);
}




void main()
{


int n;
int arr[100];
int j;
printf("\n How many items you want to insert in a knapsack");
scanf("%d",&n);
printf("\n Enter the bag weight");
scanf("%d",&j);
for(int i=0;i<n;i++)
{
	insertAtBegg();
}

printf("\n");
sort();
display();
printf("\n");
knapsack(j);
getch();
}

