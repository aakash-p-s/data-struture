#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *left,*right;
};
struct node* r;

struct node* newnode(int x)
{
struct node *temp= (struct node*)malloc(sizeof(struct node));
temp->data=x;
temp->left=temp->right=NULL;
return temp;
}

struct node* insert(struct node* r,int x)
{
if(r==NULL)
{
return newnode(x);
}
else if(x==r->data)
{
printf("\nValue already present");
}
else if(x>r->data)
{
r->right=insert(r->right,x);
}
else if(x<r->data)
{
r->left=insert(r->left,x);
}
return r;
}


void inorder(struct node* r)
{
if(r!=NULL)
{
inorder(r->left);
printf("%d ",r->data);
inorder(r->right);
}
}


struct node* search(struct node* r,int x)
{
if(r==NULL)
{
printf("\nElement not found");
}
else if(r->data==x)
{
printf("%d is found",r->data);
}
else
{
if(r->data<x)
return search(r->right,x);
else
return search(r->left,x);
}
return 0;
}


struct node* minval(struct node* r)
{
struct node*recent=r;
while(recent&&recent->left!=NULL)
recent=recent->left;
return recent;
}


struct node* del(struct node* r,int x)
{
struct node *temp=minval(r->right);
if(r==NULL)
return r;
if(x<r->data)
r->left=del(r->left,x);
else if(x>r->data)
r->right=del(r->right,x);
else
{
if(r->left==NULL)
{
struct node *ptr=r->right;
free(r);
return ptr;
}
else if(r->right==NULL)
{
struct node *ptr=r->left;
free(r);
return ptr;
}
r->data=temp->data;
r->right=del(r->right,temp->data);
}
return r;
}

int main()
{
int x,ch;
printf("Main Menu");
printf("\n1:Create new node");
printf("\n2:Insert");
printf("\n3:Inorder traversal");
printf("\n4:Search");
printf("\n5:Minimum value");
printf("\n6:Delete");
printf("\n7:Exit");
while(1)
{
printf("\nEnter your choice: ");
scanf("%d",&ch);
switch(ch)
{
case 1:printf("\nEnter the value: ");
scanf("%d",&x);
r=newnode(x);
break;
case 2:printf("\nEnter the value: ");
scanf("%d",&x);
r=insert(r,x);
break;
case 3:inorder(r);
break;
case 4:printf("\nEnter the value: ");
scanf("%d",&x);
search(r,x);
break;
case 5:minval(r);
break;
case 6:printf("\nEnter the value: ");
scanf("%d",&x);
del(r,x);
break;
case 7:exit(0);
break;
default:printf("\nInvalid choice");
}
}
return 0;
}
