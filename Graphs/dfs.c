#include<stdio.h>

#define MAX 100

int G[MAX][MAX], n, vst[MAX] = {0};

void dfs(int v)
{
  int i;
  printf("%d ",v);
  vst[v] = 1;

  for(int i = 0; i < n; i++)
    if(!vst[i] && G[v][i])
      dfs(i);
}

void main()
{
  int cnt = 0, v = 0;
  
  printf("Vertices? : ");
  scanf("%d",&n);

  printf("\nAdjacency-Matrix? : \n");
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      scanf("%d",&G[i][j]);

  printf("\nStarting-Vertex? : ");
  scanf("%d", &v);
  dfs(v);

  for(int i = 0; i < n; i++)
    if(vst[i])
      cnt++;

  if(cnt == n)
    printf("\nConnected Graph!\n");
  else
    {
      printf("\nDis-Connected Graph!\n");
      dfs(cnt);
    }
}
