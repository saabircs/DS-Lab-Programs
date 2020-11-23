#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int data;
  struct node *link;
}node;

node *head=NULL;

void insert_end()
{
   node *temp;
   temp=(node *)malloc(sizeof(node));
   
   printf("Please enter the node element:\n");
   scanf("%d",&temp->data);
    temp->link=NULL;
   if(head==NULL)
  {
  head=temp;
  }
  else 
  {
    node *p=head;
    while(p->link!=NULL)
   {
    p=p->link;
   }
   p->link=temp;
  }
}

void insert_begin()
{
 node *temp;
temp=(node *)malloc(sizeof(node));
 printf("Please enter the node element:\n");
 scanf("%d",&temp->data);
 temp->link=NULL;

 if(head==NULL)
 {
     head=temp;
 }
 else
 {
  temp->link=head;
  head=temp;
 }
}

int length()
{
  node *p;
  p=head;
  int i=0;

  while(p!=NULL)
  {
   i++;
   p=p->link;
  }
return i;
}

void insert_after(){

node *p,*temp;
int loc,i=1;
printf("Please enter the location:");
scanf("%d",&loc);

if(loc>length())
{
  printf("incorrect location!. The list has %d nodes",length());
}
else 
{

p=head;
while(i<loc)
{
 p=p->link;
 i++;
}

temp=(node *)malloc(sizeof(node));
printf("Please enter the node element:\n");
scanf("%d",&temp->data);
temp->link=NULL;

temp->link=p->link;
p->link=temp;
}
}

void delete()
{
int loc;
node *temp;
printf("Please enter the locatin of node to be deleted:\n");
scanf("%d",&loc);

if (loc>length())
{
  printf("Invalid Node!\n");
}
else if (loc==1)
{
 temp=head;
head=temp->link;
temp->link=NULL;
free(temp);
}
else
{
node *p=head,*q;
int i=1;
while(i<loc-1)
{
  p=p->link;
  i++;
}
q=p->link;
p->link=q->link;
q->link=NULL;
free(q);
}
}


void display()
{
 node *temp=head;
 if(temp==NULL)
 {
   printf("No nodes in the list\n");
 }
 else
 {
   while(temp!=NULL)
   {
     printf("%d\n",temp->data);
     temp=temp->link;
   }
 }
}



int main()
{
 
 int op,len;
 while(1)
{ printf("**********MENU**********\n");
  printf("1. Insert in beginning\n");
  printf("2. Insert at end\n");
  printf("3. Insert after node\n");
  printf("4. Delete node\n");
  printf("5. Display\n");
  printf("6. Length of list\n");
  printf("7. Exit\n");
  printf("************************\n");
  printf("Please enter your choice:");
  scanf("%d",&op);
  switch (op)
  {
  case 1:insert_begin();
    break;
  case 2: insert_end();
    break;
  case 3: insert_after();
    break;
  case 4: delete();
    break;
  case 5: display();
    break;
  case 6: len=length();
          printf("The length is %d\n",len);
    break;
  case 7: exit(0);
     break;
  default: printf("Invalid choice!\n");
  }
 }
return 0;
}
