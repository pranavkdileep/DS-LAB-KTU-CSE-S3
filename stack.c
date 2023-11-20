#include<stdio.h>

int a[10],TOP=-1,SIZE=10;

void pop()
{
if(TOP == -1)
{
printf("empty stack ....\n");
}
else
{
printf("\nthe element deleted is %d\n",a[TOP]);
TOP--;
}
}

void push(int ITEM)
{
if(TOP == (SIZE-1))
{
printf("stack is full\n");
}
else
{
TOP++;
a[TOP] = ITEM;
}
}
void display()
{
if(TOP ==  -1)
{
printf("empty\n");
}
else
{
for(int i = TOP;i>=0;i--)
{
printf("[%d]\n",a[i]);
}
}
}

int main()
{
int ITEM,Flag;

while(Flag != 4)
{
printf("1.POP\t2.PUSH\n3.DISPLAY\t4.EXIT\n");
scanf("%d",&Flag);
switch(Flag)
{
case 1:
	pop();
	break;
case 2:
	printf("enter item :");
	scanf("%d",&ITEM);
	push(ITEM);
	break;
case 3:
	display();
	break;
case 4:
	break;
default :
	printf("invalid input\n");
	break;
}
}
return 0;
}

