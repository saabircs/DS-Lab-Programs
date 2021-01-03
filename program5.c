#include <stdio.h>
#define SIZE 5
#define SIZEE 5

void enQueue(int);
void enQueue2(int);
void deQueue();
void display();
void display2();
void divide();

int items[SIZE],front = -1, rear = -1;
int items2[SIZEE], front1=-1, rear1=-1;

int main() {
  enQueue(13983);
  enQueue(10080);
  enQueue(7113);
  enQueue(2520);
  enQueue(2500);

display();
  divide();
  display2();

  return 0;
}

void enQueue(int value) {
  if (rear == SIZE - 1)
    printf("\nQueue is Full!!");
  else {
    if (front == -1)
      front = 0;
    rear++;
    items[rear] = value;
    printf("\nInserted -> %d", value);
  }
}
void enQueue2(int value) {
  if (rear1 == SIZEE - 1)
    printf("\nQueue is Full!!");
  else {
    if (front1 == -1)
      front1 = 0;
    rear1++;
    items2[rear1] = value;
    printf("\nInserted -> %d\n", value);
  }
}

void deQueue() {
  if (front == -1)
    printf("\nQueue is Empty!!");
  else {
    printf("\nDeleted : %d", items[front]);
    front++;
    if (front > rear)
      front = rear = -1;
  }
}


void display() {
  if (rear == -1)
    printf("\nQueue is Empty!!!");
  else {
    int i;
    printf("\nQueue elements are:\n");
    for (i = front; i <= rear; i++)
      printf("%d  ", items[i]);
  }
  printf("\n");
}

void display2() {
  if (rear1 == -1)
    printf("\nQueue is Empty!!!");
  else {
    int i;
    printf("\nQueue elements are:\n");
    for (i = front1; i <= rear1; i++)
      printf("%d  ", items2[i]);
  }
  printf("\n");
}

void divide(){

  int i;

       for(i=front; i<=rear;i++)
       {
           if((items[i]%1==0) && (items[i]%2==0) && (items[i]%3==0) && (items[i]%4==0)&& (items[i]%5==0)&& (items[i]%6==0)&& (items[i]%7==0)&& (items[i]%8==0)&& (items[i]%9==0)&& (items[i]%10==0))
           {

               printf("the number is divisible by all numbers in range 1-10 is %d\n", items[i]);
               enQueue2(items[i]);

           }

      }

}

