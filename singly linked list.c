#include<stdio.h>
#include<stdlib.h>

int main()
{
    struct node
    {
        int data;
        struct node *next;
    };
    struct node *head,*newnode,*ptr;
    head=0;
    int choice=1;
    while(choice)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d",&newnode->data);
        newnode->next=0;
        if(head==0)
        {
            head=newnode;
        }
        else
        {
            ptr=head;
            while(ptr->next!=0)
            {
                ptr=ptr->next;
            }
            ptr->next=newnode;
        }
        printf("Do you want to continue(0,1): ");
        scanf("%d",&choice);
    }
    ptr=head;
    while(ptr->next!=0)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    return 0;
}