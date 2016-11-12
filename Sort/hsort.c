#include<stdio.h>

#define MAX 100

void heapify(int a[], int n)
{
  for(int i = n/2-1; i >= 0; i--)
    {
      int k = i;
      int val = a[i];
      int heap = 0;

      while(!heap && 2*k+1 < n)
	{
	  int j = 2*k + 1;
	  if(j != n-1)
	    if(a[j] < a[j+1])
	      j = j+1;

	  if(val >= a[j])
	    {
	      heap = 1;
	      break;
	    }
	  else
	    {
	      a[k] = a[j];
	      k = j;
	    }
	  a[k] = val;
	}
    }
}

void hsort(int a[], int n)
{
  int t = 0, temp;
  
  while(t < n)
    {
      heapify(a, n-t);
      
      temp = a[0];
      a[0] = a[n-t-1];
      a[n-t-1] = temp;

      t++;
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
  
  hsort(a, n);
  
  printf("\nAfter Sorting: ");
  for(int i = 0; i < n; i++)
    printf("%d ", a[i]);

  printf("\n");
}
