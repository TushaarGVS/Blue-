#include<stdio.h>

#define MAX 100

void merge(int a[], int st, int md, int ed)
{
  int n1, n2;

  n1 = md - st + 1;
  n2 = ed - md;
  
  int a1[n1], a2[n2];

  for(int i = 0; i < n1; i++)
    a1[i] = a[st + i];
  
  for(int i = 0; i < n2; i++)
    a2[i] = a[md + i + 1];
  
  int x = 0, y = 0, z = st;
  while(x < n1 && y < n2)
    {
      if(a1[x] < a2[y])
	{
	  a[z] = a1[x];
	  x++;
	}
      else
	{
	  a[z] = a2[y];
	  y++;
	}
      z++;
    }

  while(x < n1)
    {
      a[z] = a1[x];
      x++;
      z++;
    }

   while(y < n2)
    {
      a[z] = a2[y];
      y++;
      z++;
    }
}

void msort(int a[], int st, int ed)
{
  if(st < ed)
    {
      int md = (st+ed)/2;
      msort(a, st, md);
      msort(a, md+1, ed);
      merge(a, st, md, ed);
    }
}

void main()
{
  int n, a[MAX];
  
  printf("Elements? : ");
  scanf("%d", &n);

  printf("\nEnter Elements: ");
  for(int i = 0; i < n; i++)
    scanf("%d", &a[i]);
  
  msort(a, 0, n-1);
  
  printf("\nAfter Sorting: ");
  for(int i = 0; i < n; i++)
    printf("%d ", a[i]);

  printf("\n");
}
