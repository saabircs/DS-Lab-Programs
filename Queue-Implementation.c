#include <stdio.h>
#define MAX 5
void insert();
void delete();
void display();

int queue_array[MAX];
int rear = - 1;
int front = - 1;

int main()
{
int option;
 while (1)
  {
    printf("Menu\n");
    printf("***********\n");
    printf("1- Insert \n");
    printf("2- Delete\n");
    printf("3- Display\n");
    printf("4- Exit \n");
    printf("***********\n");
    printf("Enter your option: ");
    scanf("%d", &option);
        switch (option)
       {
            case 1:
            insert();
            break;
            case 2:
            delete();
            break;
            case 3:
            display();
            break;
            case 4:
            exit(1);
            default:
            printf("Invalid Option \n");
         } 
    } 
} 
void insert()
{
 int add_item;
 if (rear == MAX - 1)
 printf("Queue Overflow \n");
 else
  {
   if (front == - 1)
   front = 0;
    printf("Enter the element to insert: ");
    scanf("%d", &add_item);
    rear = rear + 1;
    queue_array[rear] = add_item;
    }
} 
void delete()
{
  if (front == - 1 || front > rear)
    {
     printf("Queue Underflow \n");
     return ;
    }
    else
    {
    printf("deleted element from queue is : %d\n", queue_array[front]);
    front = front + 1;
    }
} 
void display()
{
  int i;
  if (front == - 1)
   printf("Queue is empty \n");
    else
    {
  printf("Elements in the Queue are:\n");
  for (i = front; i <= rear; i++)
  printf("%d ", queue_array[i]);
  printf("\n");
    }
}
