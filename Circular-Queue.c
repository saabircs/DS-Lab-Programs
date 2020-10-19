#include<stdio.h>
#define SIZE 5

void enQueue(int);
void deQueue();
void display();

int cQueue[SIZE], front = -1, rear = -1;

int main()
{
   int choice, value;
   while(1){
      printf("\n****** MENU ******\n");
      printf("1. Insert\n2. Delete\n3. Display\n4. Exit");
      printf("\n******************\n");
      printf("Enter your choice: ");
      scanf("%d",&choice);
      printf("\n------------------\n");
      switch(choice){
	 case 1: printf("\nEnter the value to be insert:  ");
		 scanf("%d",&value);
		 enQueue(value);
		 break;
	 case 2: deQueue();
		 break;
	 case 3: display();
		 break;
	 case 4: printf("\n Program Exit Successful\n");
   exit(0);
	 default: printf("\nPlease select the correct choice!!!\n");
      }
   }
}
void enQueue(int value)
{
   if((front == 0 && rear == SIZE - 1) || (front == rear+1))
      printf("\nCircular Queue Overflow, insertion not possible!\n");
   else{
      if(rear == SIZE-1 && front != 0)
	 rear = -1;
      cQueue[++rear] = value;
      printf("\nInsertion Success!!\n");
      if(front == -1)
	 front = 0;
   }
}
void deQueue()
{
   if(front == -1 && rear == -1)
      printf("\nCircular Queue Underflow, deletion not possible!\n");
   else{
      printf("\nDeleted element : %d\n",cQueue[front++]);
      if(front == SIZE)
	 front = 0;
      if(front-1 == rear)
	 front = rear = -1;
   }
}
void display()
{
   if(front == -1)
      printf("\nCircular Queue is Empty!\n");
   else{
      int i = front;
      printf("\nElements in Circular Queue are:\n");
      if(front <= rear){
	 while(i <= rear)
	    printf("%d\t",cQueue[i++]);
      }
      else{
	 while(i <= SIZE - 1)
	    printf("%d\t", cQueue[i++]);
	 i = 0;
	 while(i <= rear)
	    printf("%d\t",cQueue[i++]);
      }
   }
}
