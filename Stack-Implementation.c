#include<stdio.h>
#define SIZE 5
int top = -1;
int stack[SIZE];
void push(int ele) {
  if (isFull()) {
    printf("stack overflow!\n");
  } else {
    top++;
    stack[top] = ele;
  }
}
int pop() {
  if (isEmpty()) {
    return 0;
  } else {
    return stack[top--];
  }
}
int isEmpty() {
  if (top == -1)
    return 1;
  else
    return 0;
}
int isFull() {
  if (top == SIZE - 1)
    return 1;
  else
    return 0;
}
void display() {
  if (isEmpty())
    printf("Stack underflow!\n");
  else {
    printf("The elements are:\n");
    for (int i = 0; i <= top; i++) {
      printf("%d\n", stack[i]);
    }
  }
}
int main() {
  int c, d, p;
  while (1) {
    printf("Enter Choice\n**********\n \n1- Push\n2- Pop\n3- Display\n");
    scanf("%d", & c);
    switch (c) {
    case 1:
      printf("Enter an element:\n");
      scanf("%d", & d);
      push(d);
      break;
    case 2:
      p = pop();
      if (p == 0)
        printf("Stack underflow!\n");
      else
        printf("Element deleted succesfully!\n");
      break;
    case 3:
      display();
      break;
    case 4:
      exit(0);
    default:
      printf("Invalid input!\n");
    }
   return 0;
}
