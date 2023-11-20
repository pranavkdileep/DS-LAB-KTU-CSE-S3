#include<stdio.h>

int a[10], FRONT = -1, REAR = -1, SIZE = 4;

void DEQUEUE()
{
if (FRONT == -1)
{
printf("empty QUEUE ....\n");
}
else if (FRONT == REAR)
{
printf("the element deleted is %d\n", a[FRONT]);
FRONT = -1;
REAR = -1;
}
else
{
printf("the element deleted is %d\n", a[FRONT]);
FRONT = (FRONT + 1) % SIZE;
}
}

void ENQUEUE(int ITEM)
{
if (FRONT == (REAR + 1) % SIZE)
{
printf("QUEUE is full\n");
}
else if (FRONT == -1 && REAR == -1)
{
FRONT = 0;
REAR = 0;
a[REAR] = ITEM;
}
else
{
REAR = (REAR + 1) % SIZE;
a[REAR] = ITEM;
}
}

void display()
{
if (FRONT == -1)
{
printf("empty\n");
}
else if (FRONT <= REAR)
{
for (int i = FRONT; i <= REAR; i++)
{
printf("[%d]", a[i]);
}
}
else
{
for (int i = FRONT; i < SIZE; i++)
{
printf("[%d]", a[i]);
}
for (int i = 0; i <= REAR; i++)
{
printf("[%d]", a[i]);
}
}
printf("\n");
}

int main()
{
int ITEM, Flag = 0; 

while (Flag != 4)
{
printf("1.DEQUEUE\t2.ENQUEUE\t3.DISPLAY\t4.EXIT\n");scanf("%d", &Flag);
        switch (Flag)
        {
        case 1:
            DEQUEUE();
            break;
        case 2:
            printf("enter item :");
            scanf("%d", &ITEM);
            ENQUEUE(ITEM);
            break;
        case 3:
            display();
            break;
        case 4:
            break;
        default:
            printf("invalid input\n");
            break;
        }
    }
    return 0;
}
