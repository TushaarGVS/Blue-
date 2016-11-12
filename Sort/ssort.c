#include<stdio.h>

#define MAX 100

void ssort(int a[], int n)
{
  int incr = n/2;
  while(incr > 0)
    {
      for(int i = incr; i < n; i++)
	{
	  int j = i-incr;
	  while(j >= 0 && a[j] > a[j+incr])
	    {
	      int temp = a[j];
	      a[j] = a[j+incr];
	      a[j+incr] = temp;

	      j = j-incr;
	    }
	}
      incr = incr/2;
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
  
  ssort(a, n);
  
  printf("\nAfter Sorting: ");
  for(int i = 0; i < n; i++)
    printf("%d ", a[i]);

  printf("\n");
}
