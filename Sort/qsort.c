#include<stdio.h>

#define MAX 100

int n;

int partition(int a[], int st, int ed)
{
  int j = st, i = j-1, pivot = a[ed], temp;

  for(; j < n; j++)
    if(a[j] < pivot)
      {
	i++;
	temp = a[i];
	a[i] = a[j];
	a[j] = temp;
      }
  
  temp = a[i+1];
  a[i+1] = a[ed];
  a[ed] = temp;

  return i+1;
}

void qsort(int a[], int st, int ed)
{
  int par;
  if(st < ed)
    {
      par = partition(a, st, ed);
      qsort(a, st, par-1);
      qsort(a, par+1, ed);
    }
}

void main()
{
  int a[MAX];
  
  printf("Elements? : ");
  scanf("%d", &n);

  printf("\nEnter Elements: ");
  for(int i = 0; i < n; i++)
    scanf("%d", &a[i]);
  
  qsort(a, 0, n-1);
  
  printf("\nAfter Sorting: ");
  for(int i = 0; i < n; i++)
    printf("%d ", a[i]);

  printf("\n");
}
