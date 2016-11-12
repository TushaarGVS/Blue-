#include<stdio.h>

#define MAX 100
#define INF 10007

int n, ne = 1, vst[MAX] = {0}, G[MAX][MAX];

void main()
{
  int minDist, u, v, dist = 0;
    
  printf("Vertices? : ");
  scanf("%d",&n);

  printf("\nAdjacency-Matrix? : \n");
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      {
	scanf("%d",&G[i][j]);
	if(G[i][j] == 0)
	  G[i][j] = INF;
      }
  
  vst[0] = 1;
  while(ne < n)
    {
      minDist = INF;
      for(int i = 0; i < n; i++)
	for(int j = 0; j < n; j++)
	  if(vst[i] && G[i][j] < minDist)
	    {
	      minDist = G[i][j];
	      u = i;
	      v = j;
	    }
      
      if(!vst[u] || !vst[v])
	{
	  printf("%d - %d\t", u, v);
	  vst[v] = 1;
	  dist += minDist;
	  ne++;
	}
      G[u][v] = G[v][u] = INF;
    }
  printf("\nTotal Distance: %d\n", dist);
}
