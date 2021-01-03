#include <stdio.h>
typedef struct node {
  int data;
  struct node * left;
  struct node * right;
}
node;
node * create() {
  node * temp;
  temp = (node * ) malloc(sizeof(node));
  printf("Enter the new data\n");
  scanf("%d", & temp -> data);
  temp -> right = temp -> left = NULL;
  return temp;
}
void insert(node * root, node * temp) {
  if (temp -> data < root -> data) {
    if (root -> left != NULL)
      insert(root -> left, temp);
    else
      root -> left = temp;
  } else {
    if (root -> right != NULL)
      insert(root -> right, temp);
    else
      root -> right = temp;
  }
}
void preorder(node * root) {
  if (root != NULL) {
    printf("%d\t", root -> data);
    preorder(root -> left);
    preorder(root -> right);
  }
}
void inorder(node * root) {
  if (root != NULL) {
    inorder(root -> left);
    printf("%d\t", root -> data);
    inorder(root -> right);
  }
}
void postorder(node * root) {
  if (root != NULL) {
    postorder(root -> left);
    postorder(root -> right);
    printf("%d\t", root -> data);
  }
}
void main() {
  int ch;
  node * temp, * root = NULL;
  while (1) {
    printf("Menu\n***************\n1- Insert \n2- Preorder Display\n3- Inorder Display\n4- Postorder Display\n5- Exit\n***************\n");
    scanf("%d", & ch);
    switch (ch) {
    case 1:
      temp = create();
      if (root == NULL)
        root = temp;
      else
        insert(root, temp);
      printf("Element inserted successfully!\n");
      break;
    case 2:
      if (root == NULL) {
        printf("Tree is empty!\n");
      } else {
        printf("Preorder Display:\n");
        preorder(root);
        printf("\n");
      }
      break;
    case 3:
      if (root == NULL) {
        printf("tree is empty!\n");
      } else {
        printf("Inorder Display:\n");
        inorder(root);
        printf("\n");
      }
      break;
    case 4:
      if (root == NULL) {
        printf("Tree is empty!\n");
      } else {
        printf("Postorder Display::\n");
        postorder(root);
        printf("\n");
      }
      break;
    case 5:
      exit(0);
    default:
      printf("invalid choice!\n");
    }
  }
}

