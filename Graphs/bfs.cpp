#include<cstdio>
#include<queue>
#include<algorithm>
#include<iostream>

#define MAX 100

using namespace std;

int G[MAX][MAX], vst[MAX], n;

void bfs(int v)
{
  vst[v] = 1;
  queue<int> q;
  q.push(v);

  while(!q.empty())
    {
      int val = q.front();
      cout << val << " ";
      q.pop();
      for(int i = 0; i < n; i++)
	{
	  if(G[val][i] && !vst[i])
	    {
	      q.push(i);
	      vst[i] = 1;
	    }
	}
    }
}

int main()
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
  bfs(v);

  return 0;
}
