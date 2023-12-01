#include<stdio.h>
#include<stdlib.h>
void enqueue(int);
void dequeue();
void display();
struct node{
int data;
struct node *link;
}*front=NULL,*rear=NULL,*ptr=NULL,*prev=NULL,*curr=NULL;
void main()
{
 int a,c;
 do{
   printf("\n1.Enqueue\n2.Dequeue\n3.DISPLAY\n4.EXIT\n");
   printf("Enter your choice : ");
   scanf("%d",&c);
   switch(c){
   case 1 : printf("Enter the data to be insert : ");
            scanf("%d",&a);
            enqueue(a);
            break;
   case 2 : dequeue();
            break;
   case 3 : display();
            break;
   case 4 : break;
           
   default: printf("Enter valid choice \n");
   }
   }while(c!=4);
   
  }
  
  void enqueue(int d)
  {
   struct node *new;
   if(rear==NULL&&front==NULL)
   {
    new=(struct node*)malloc(sizeof(struct node));
    new->data=d;
    new->link=NULL;
    rear=new;
    front=new;
   }
   else
   {
    new=(struct node*)malloc(sizeof(struct node));
    new->data=d;
    new->link=NULL;
    ptr=rear;
    while(ptr->link!=NULL)
    {
     ptr=ptr->link;
    }
    ptr->link=new;
    rear=new;
   }
  }
  
  void dequeue()
  {
   struct node *temp;
   if(front==NULL&&rear==NULL)
   {
    printf("No item found in the list");
   }
   else if(front==rear)
    {
     printf("The deleted element is %d",front->data);
     front=NULL;
     rear=NULL;
    }
    else
   {
    temp=front;
    front=front->link;
    temp->link=NULL;
   }
  }
  
  void display()
  {
   if(front==NULL&&rear==NULL)
   {
    printf("No item found in the list");
   }
   else
   {
    ptr=front;
    while(ptr!=NULL)
    {
     printf("%d\t",ptr->data);
     ptr=ptr->link;
    }
    
   }
  } 
