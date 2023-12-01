#include<stdio.h>
#include<stdlib.h>
void push(int);
void pop();
void display();
struct node{
int data;
struct node *link;
}*head=NULL,*ptr=NULL,*prev=NULL,*curr=NULL;
void main()
{
 int a,c;
 do{
   printf("\n1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\n");
   printf("Enter your choice : ");
   scanf("%d",&c);
   switch(c){
   case 1 : printf("Enter the data to be insert : ");
            scanf("%d",&a);
            push(a);
            break;
   case 2 : pop();
            break;
   case 3 : display();
            break;
   case 4 : break;
           
   default: printf("Enter valid choice \n");
   }
   }while(c!=4);
   
  }
  
  void push(int d)
  {
   struct node *new;
   if(head==NULL)
   {
    new=(struct node*)malloc(sizeof(struct node));
    new->data=d;
    new->link=NULL;
    head=new;
   }
   else
   {
    new=(struct node*)malloc(sizeof(struct node));
    new->data=d;
    new->link=NULL;
    ptr=head;
    while(ptr->link!=NULL)
    {
     ptr=ptr->link;
    }
    ptr->link=new;
   }
  }
  
  void pop()
  {
   if(head==NULL)
   {
    printf("No item found in the list");
   }
   else
   {
    prev=head;
    curr=head;
    while(curr->link!=NULL)
    {
     prev=curr;
     curr=curr->link;
    }
    prev->link=NULL;
   }
  }
  
  void display()
  {
   if(head==NULL)
   {
    printf("No item found in the list");
   }
   else
   {
    ptr=head;
    while(ptr!=NULL)
    {
     printf("%d\t",ptr->data);
     ptr=ptr->link;
    }
    
   }
  } 
