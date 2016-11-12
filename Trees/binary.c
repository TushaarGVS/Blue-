#include<stdio.h>

#define MAX 100

int a[MAX], n;

void preorder(int i)
{
  printf("%d  ",a[i]);
  if(2*i+1 < n)
    preorder(2*i+1);
  if(2*i+2 < n)
    preorder(2*i+2);
}

void inorder(int i)
{
  if(2*i+1 < n)
    inorder(2*i+1);
  printf("%d  ",a[i]);
  if(2*i+2 < n)
    inorder(2*i+2);
}

void postorder(int i)
{
  if(2*i+1 < n)
    postorder(2*i+1);
  if(2*i+2 < n)
    postorder(2*i+2);
  printf("%d  ", a[i]);
}

void main()
{
  printf("Nodes? : ");
  scanf("%d", &n);

  printf("\nTree? : ");
  for(int i = 0; i < n; i++)
    scanf("%d", &a[i]);

  printf("\nPre-Order Traversal:  ");
  preorder(0);

  printf("\nIn-Order Traversal:  ");
  inorder(0);
  
  printf("\nPost-Order Traversal:  ");
  postorder(0);
  printf("\n");
}
