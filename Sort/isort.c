#include<stdio.h>

#define MAX 100

void isort(int a[], int n)
{
  for(int i = 0; i < n; i++)
    {
      int j = i-1;
      int val = a[i];
      while(j >= 0 && a[j] > val)
	{
	  a[j+1] = a[j];
	  j = j-1;
	}
      a[j+1] = val;
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
  
  isort(a, n);
  
  printf("\nAfter Sorting: ");
  for(int i = 0; i < n; i++)
    printf("%d ", a[i]);

  printf("\n");
}
