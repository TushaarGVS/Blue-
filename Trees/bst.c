#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node *rc;
  struct node *lc;
};

struct node *root = NULL;

void insert(struct node *temp, int data)
{
  struct node *temp1 = (struct node *)malloc(sizeof(struct node)), *temp2;
  temp1->data = data;
  temp1->rc = NULL;
  temp1->lc = NULL;

  if(root == NULL)
    root = temp1;
  else
    {
      if(temp1->data < temp->data)
	if(temp->lc == NULL)
	  temp->lc = temp1;
	else
	  insert(temp->lc, data);
      else
	if(temp->rc == NULL)
	  temp->rc = temp1;
	else
	  insert(temp->rc, data);
    }
}

void delete(struct node *temp, int ele)
{
  
}

void search(struct node *temp, int ele)
{
  if(temp != NULL)
    {
      if(temp->data == ele)
	printf("Found!");
      else
	{
	  if(ele < temp->data)
	    search(temp->lc, ele);
	  else if(ele > temp->data)
	    search(temp->rc, ele);
	}
    }
  else
    printf("Not-Found!");
}

void inorder(struct node *temp)
{
  if(temp != NULL)
    {
      inorder(temp->lc);
      printf("%d ",temp->data);
      inorder(temp->rc);
    }
}

void main()
{
  int op, data, ele;
  do
    {
      printf("\n\n1.Ins   2.Del   3.Search   4.Traverse   5.Quit? : ");
      scanf("%d", &op);
      printf("\n");
      
      switch(op)
	{
	case 1:
	  printf("Data: ");
	  scanf("%d",&data);
	  insert(root, data);
	  break;

	case 3:
	  printf("Search Element: ");
	  scanf("%d", &ele);
	  search(root, ele);
	  break;
	  
	case 4:
	  printf("In-Order Traversal: ");
	  inorder(root);
	  break;
	}
    }
  while(op != 5);
}
