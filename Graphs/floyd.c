#include<stdio.h>

#define MAX 100

int G[MAX][MAX];
  
void floyd(int n)
{
  for(int k = 0; k < n; k++)
    for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++)
	if(G[i][k] != 0 && G[k][j] != 0 && i != j)
	  if(G[i][k]+G[k][j] < G[i][j] || G[i][j] == 0)
	    G[i][j] = G[i][k] + G[k][j];
}

void main()
{
  int n;
  
  printf("Vertices? : ");
  scanf("%d",&n);
  
  printf("\nAdjacency Matrix? : \n");
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      scanf("%d", &G[i][j]);

  floyd(n);

  printf("\nOptimized Matrix? : \n");
  for(int i = 0; i < n; i++)
    {
      for(int j = 0; j < n; j++)
	printf("%d ", G[i][j]);
      printf("\n");
    }
}
