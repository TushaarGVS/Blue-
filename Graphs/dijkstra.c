#include<stdio.h>

#define MAX 100
#define INF 10007

int G[MAX][MAX], vst[MAX] = {0};
  
void dijkstra(int sv, int n)
{
  int prev[MAX], dist[MAX];
  int cnt, nn, minDist;
    
  for(int i = 0; i < n; i++)
    {
      dist[i] = G[sv][i];
      prev[i] = sv;
    }

  vst[sv] = 1;
  dist[sv] = 0;
  cnt = 1;

  while(cnt < n-1)
    {
      minDist = INF;
      for(int i = 0; i < n; i++)
	if(!vst[i] && minDist > dist[i])
	  {
	    minDist = dist[i];
	    nn = i;
	  }

      vst[nn] = 1;

      for(int i = 0; i < n; i++)
	if(!vst[i])
	  if(minDist + G[nn][i] < dist[i])
	    {
	      dist[i] = minDist + G[nn][i];
	      prev[i] = nn;
	    }
      cnt++;
    }

  for(int i = 0; i < n; i++)
    {
      if(i != sv)
	{
	  printf("\nDistance of %d = %d", i, dist[i]); 
	  printf("\nPath : %d", i);
	  int j = i;
	  do
	    {
	      j = prev[j];
	      printf(" <- %d", j);
	    }
	  while(j != sv);
	}
    }
  printf("\n");
}

void main()
{
  int sv, n;
  
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

  printf("\nStarting-Vertex? : ");
  scanf("%d",&sv);
  
  dijkstra(sv, n);
}
