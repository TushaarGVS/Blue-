#include<stdio.h>

#define MAX 100

int findSet(int, int);
void doUnion(int, int);

struct edge
{
  int v1, v2, wt;
};

int a[MAX], n, e;

void main()
{
  int flag = 0, sum = 0;
  
  printf("Vertices, Edges? : ");
  scanf("%d%d",&n,&e);

  struct edge ed[MAX];
  struct edge temp;
  
  printf("Data: Vertex-1 Vertex-2 Weight? : \n");
  for(int i = 0; i < e; i++)
    {
      scanf("%d%d%d", &ed[i].v1, &ed[i].v2, &ed[i].wt);
    }

  //Sort Out!
  for(int i = 0; i < e-1; i++)
    for(int j = i+1; j < e; j++)
      if(ed[i].wt > ed[j].wt)
	{
	  temp = ed[i];
	  ed[i] = ed[j];
	  ed[j] = temp;
	}

  //Copy Vertices into array:
  for(int i = 0; i < n; i++)
    a[i] = i+1;

  //findSet and doUnion:
  for(int i = 0; i < e; i++)
    {
      flag = findSet(ed[i].v1, ed[i].v2);
      if(!flag)
	{
	  doUnion(ed[i].v1, ed[i].v2);
	  sum += ed[i].wt;
	}
    }
  printf("\nTotal Distance: %d\n", sum);
}

int findSet(int v1, int v2)
{
  if(a[v1-1] == a[v2-1])
    return 1;
  else
    return 0;
}

void doUnion(int v1, int v2)
{
  printf("%d - %d\t", v1, v2);
  int temp = a[v1-1];
  for(int i = 0; i < n; i++)
    if(a[i] == temp)
      a[i] = a[v2-1];
}
