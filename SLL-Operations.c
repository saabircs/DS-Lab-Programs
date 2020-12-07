#include <stdio.h>
#include <stdlib.h>

void putBeg(int value);
void put(int pos, int value);
void putEnd(int value);

void delFirst();
void delLast();
void delPos();
void display();
void inputValue(int *add);
void inputPos(int *add);

typedef struct node {
    int value;
    struct node* next;
}node;

node* head = NULL;

void putBeg(int value)
{
    node* ptr = (node*) malloc((sizeof(node)));
    ptr -> value = value;
    if(head==NULL){
        head = ptr;
        head->next=NULL;
        return;
    }
    ptr->next = head;
    head = ptr;
}
void put(int pos, int value)
{
    node* ptr = (node*) malloc((sizeof(node)));
    ptr -> value = value;
    if(head==NULL&&pos==0){
        head = ptr;
        return;
    }
    if(pos==0)
    {
        putBeg(value);
        return;
    }
    int i  = 0;
    node* tmp = head;
    while(i != pos-1 && tmp != NULL)
    {
        i++;
        tmp = tmp->next;
    }
    if(i!=pos-1)
    {
      printf("\n error!\n Please enter the correct index\n\n");
        return;
    }
    if((tmp->next)==NULL)
    {
        putEnd(value);
        free(ptr);
        return;
    }
    ptr->next = (tmp->next);
    tmp->next = ptr;
}

void putEnd(int value) {

    node* ptr = (node*) malloc((sizeof(node)));
    ptr -> value = value;
    ptr->next=NULL;
    if(head==NULL)
    {
        head=ptr;
        return;
    }
    node* tmp = head;
    for(;tmp->next!=NULL;tmp=tmp->next);
    tmp->next=ptr;
}
void display() {

    if(head==NULL){
        printf("\nThe Linked List is Empty\n");
        return;
    }
    printf("\nThe Linked List Contains: ");
    for(node* tmp=head;tmp!=NULL;tmp = tmp->next)
        printf("%d  ", tmp->value);
    printf("\n\n");
}

void delFirst() {
    if(head==NULL){
        printf("\nThe Linked List is Empty\n");
        return;
    }
    if(head->next==NULL)
    {
        free(head);
        head=NULL;
        return;
    }
    node *tmp = head->next;
    free(head);
    head = tmp;
}

void delLast() {
    if(head==NULL){
        printf("\nLinked List is Empty!\n");
        return;
    }
    if(head->next == NULL)
    {
        free(head);
        head=NULL;
        return;
    }
    node* tmp = head;
    for(;(tmp->next)->next!=NULL;tmp=tmp->next);
    node* tmp1 = tmp->next;
    tmp->next = NULL;
    free(tmp1);
}

void delPos(int pos){

    if(head==NULL){
        printf("\nLinked List is Empty\n");
        return;
    }
    if(pos==0)
    {
        delFirst();
        return;
    }
    int i  = 0;
    node* tmp = head;
    while(i!=pos-1&&tmp!=NULL)
    {
        i++;
        tmp = tmp->next;
    }
    if(i!=pos-1)
    {
        printf("\nERROR\nEnter the Correct Index!n");
        return;
    }
    if((tmp->next)->next==NULL)
    {
        delLast();
        return;
    }
    node* tmp1 = tmp->next;
    tmp->next = (tmp->next)->next;
    free(tmp1);
}
void inputValue(int *add)
{
    printf("Please enter the element to be added: ");
    scanf("%d", add);
}
void inputPos(int* add){
    printf("Please enter the index:");
    scanf("%d", add);
}
void main() {
    int choice = 0, input, pos;
    while(1)
    { 
        printf("**********************");
        printf("1 - Add at beginning\n");
        printf("2 - Add at end\n");
        printf("3 - Add at given index\n");
        printf("4 - Delete first element\n");
        printf("5 - Delete last element\n");
        printf("6 - Delete element at given index\n");
        printf("7 - Display\n");
        printf("8 - Exit\n");
        printf("**********************");
        printf("Please enter your choice: ");
        scanf("%d", &choice);
        if(choice==8)
            break;
        switch(choice)
        {
            case 1:
                inputValue(&input);
                putBeg(input);
                break;
            case 2:
                inputValue(&input);
                putEnd(input);
                break;
            case 3:
                inputValue(&input);
                inputPos(&pos);
                put(pos, input);
                break;
            case 4:
                delFirst();
                break;
            case 5:
                delLast();
                break;
            case 6:
                inputPos(&pos);
                delPos(pos);
                break;
            case 7:
                display();
                break;
            default:
                printf("\nInvalid Choice!\n");
                break;
        }
    }
    printf("\nCompleted!\n");
}
#include <stdio.h>
#include <stdlib.h>

void putBeg(int value);
void put(int pos, int value);
void putEnd(int value);

void delFirst();
void delLast();
void delPos();
void display();
void inputValue(int *add);
void inputPos(int *add);

typedef struct node {
    int value;
    struct node* next;
}node;

node* head = NULL;

void putBeg(int value)
{
    node* ptr = (node*) malloc((sizeof(node)));
    ptr -> value = value;
    if(head==NULL){
        head = ptr;
        head->next=NULL;
        return;
    }
    ptr->next = head;
    head = ptr;
}
void put(int pos, int value)
{
    node* ptr = (node*) malloc((sizeof(node)));
    ptr -> value = value;
    if(head==NULL&&pos==0){
        head = ptr;
        return;
    }
    if(pos==0)
    {
        putBeg(value);
        return;
    }
    int i  = 0;
    node* tmp = head;
    while(i != pos-1 && tmp != NULL)
    {
        i++;
        tmp = tmp->next;
    }
    if(i!=pos-1)
    {
        printf("\n\nerror!\nplease enter the correct Index\n\n");
        return;
    }
    if((tmp->next)==NULL)
    {
        putEnd(value);
        free(ptr);
        return;
    }
    ptr->next = (tmp->next);
    tmp->next = ptr;
}

void putEnd(int value) {

    node* ptr = (node*) malloc((sizeof(node)));
    ptr -> value = value;
    ptr->next=NULL;
    if(head==NULL)
    {
        head=ptr;
        return;
    }
    node* tmp = head;
    for(;tmp->next!=NULL;tmp=tmp->next);
    tmp->next=ptr;
}
void display() {

    if(head==NULL){
        printf("\nLinked List Empty!\n");
        return;
    }
    printf("\n\nLinked List Contains : ");
    for(node* tmp=head;tmp!=NULL;tmp = tmp->next)
        printf("%d  ", tmp->value);
    printf("\n\n");
}

void delFirst() {
    if(head==NULL){
        printf("\nLinked List Empty!\n");
        return;
    }
    if(head->next==NULL)
    {
        free(head);
        head=NULL;
        return;
    }
    node *tmp = head->next;
    free(head);
    head = tmp;
}

void delLast() {
    if(head==NULL){
        printf("\nLinked List is Empty!\n");
        return;
    }
    if(head->next == NULL)
    {
        free(head);
        head=NULL;
        return;
    }
    node* tmp = head;
    for(;(tmp->next)->next!=NULL;tmp=tmp->next);
    node* tmp1 = tmp->next;
    tmp->next = NULL;
    free(tmp1);
}

void delPos(int pos){

    if(head==NULL){
        printf("\n\nLinked List is Empty\n\n");
        return;
    }
    if(pos==0)
    {
        delFirst();
        return;
    }
    int i  = 0;
    node* tmp = head;
    while(i!=pos-1&&tmp!=NULL)
    {
        i++;
        tmp = tmp->next;
    }
    if(i!=pos-1)
    {
        printf("\nerror!\nplease enter the correct index!\n");
        return;
    }
    if((tmp->next)->next==NULL)
    {
        delLast();
        return;
    }
    node* tmp1 = tmp->next;
    tmp->next = (tmp->next)->next;
    free(tmp1);
}
void inputValue(int *add)
{
    printf("Enter element to be added : ");
    scanf("%d", add);
}
void inputPos(int* add){
    printf("Enter index : ");
    scanf("%d", add);
}
void main() {
    int choice = 0, input, pos;
    while(1)
    {
        printf("Enter 1 to add at beginning\n");
        printf("Enter 2 to add at end\n");
        printf("Enter 3 to add at given index\n");
        printf("Enter 4 to delete first element\n");
        printf("Enter 5 to delete last element\n");
        printf("Enter 6 to delete element at given index\n");
        printf("Enter 7 to display\n");
        printf("Enter -1 to quit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        if(choice==-1)
            break;
        switch(choice)
        {
            case 1:
                inputValue(&input);
                putBeg(input);
                break;
            case 2:
                inputValue(&input);
                putEnd(input);
                break;
            case 3:
                inputValue(&input);
                inputPos(&pos);
                put(pos, input);
                break;
            case 4:
                delFirst();
                break;
            case 5:
                delLast();
                break;
            case 6:
                inputPos(&pos);
                delPos(pos);
                break;
            case 7:
                display();
                break;
            default:
                printf("\nInvalid Choice!\n");
                break;
        }
    }
    printf("\nCompleted!\n");
}
