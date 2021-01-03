#include <stdio.h>
#include <stdlib.h>

typedef struct node {
int val;
struct node* next;
}node;
node* front = NULL;
node* rear = NULL;
void enqueue(int input) {
node* ptr = (node*) malloc((sizeof(node)));
ptr->next = NULL;
ptr -> val = input;
if(front==NULL&&rear==NULL)
{
front = rear = ptr;
}
else{
rear->next = ptr;
rear = ptr;
}
printf("\n\nEnqueued!\n\n");
}
void dequeue() {
if(front == NULL && rear == NULL){
printf("\n\nQueue is empty!\n\n");
return;
}
if(front -> next == NULL)
{

free(front);
front = rear = NULL;
printf("\n\nDequeued!\n\n");
return;
}
printf("\n\nDequeued element is %d",front->val);
front=front->next;
}
void display() {
if(front==NULL&&rear==NULL){
printf("\n\nQueue is empty\n\n");
return;
}
printf("Queue contains: ");
node* ptr = front;
do
{
printf("%d ", ptr->val);
ptr = ptr->next;
} while(ptr!=NULL);
printf("\n\n");
}
int main() {
int choice, input;
while(1) {
printf("\n1- Enqueue\n");
printf("2- Dequeue\n");
printf("3- Display\n");
printf("4- Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
if(choice == -1)
break;
switch(choice) {
case 1:

printf("Enter value to enqueue: ");
scanf("%d", &input);
enqueue(input);
break;
case 2:
dequeue();
break;
case 3:
display();
break;
default:
printf("\n\nWrong Input!\n\n");
}
}
return 0;
}
