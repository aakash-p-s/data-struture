#include<stdio.h>
#include<stdlib.h>
#define max 5
int cq[max],front=-1,rear=-1,item;

void enqueue()
{
printf("enter item");
scanf("%d",&item);
if((front==0 && rear==max-1)||(front==rear+1))
{
printf("overflow");
return;
}
if(front==-1)
{
front=rear=0;
}
else
{
if(rear==max-1)
rear=0;
else
rear=rear+1;}
cq[rear]=item;
}
 
void dequeue()
{
if(front==-1)
{
printf("underflow");
return;
}
printf("the deleted element is %d",cq[front]);
if(front==rear)
{
front=-1;
rear=-1;
}
else
{
if(front==max-1)
front=0;
else
front=front+1;
}
}

void display()
{
int fpos=front,rpos=rear;
if(front==-1)
{
printf("queue is empty");
return;
}
printf("queue elements:\n");
if(fpos<=rpos)
while(fpos<=rpos)
{
printf("%d",cq[fpos]);
fpos++;
}
else
{
while(fpos<=max-1)
{
printf("%d",cq[fpos]);
fpos=0;}
while(fpos<rpos)
{
printf("%d",cq[fpos]);
fpos++;
}
}
printf("\n");
}

int main()
{
int c;
while(1)
{
printf("\n 1.enqueue \n 2.dequeue \n 3.display \n 4.exit \n enter your choice");
scanf("%d",&c);
switch(c)
{
case 1:enqueue();
break;
case 2:dequeue();
break;
case 3:display();
break;
case 4:exit(0);
default:printf("invalid choice");
}
}
return 0;
}
