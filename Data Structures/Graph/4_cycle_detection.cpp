/*
  DETECTIING A CYCLE IN A GRAPH THROUGH DFS.
  Tree : A graph that does not have any cyles, i.e, there exists only a single
         unique path between any 2 vertices.

  Presence of a cycle no longer deems the graph as a tree.

  --------------------------- Solving Approach ---------------------------------

  1. Pass the information of the parent in the dfs function parameter.
  2. While exploring adj vertices, check if an already visited node connected to the
     current vertix is the parent or not, if not then there exists a cycle.
*/

#include<bits/stdc++.h>
#define N 3000
using namespace std;
int adj[N][N];
bool dfsCycle(int vertix, int parent, int visited[], int n)
{
  visited[vertix] = 1;
  for(int i=1; i<=n; i++)
  {
    if(adj[vertix][i] == 1 && !visited[i])
    {
      dfsCycle(i, vertix, visited, n);
    }
    else if(adj[vertix][i] == 1 && visited[i])
    {
      if(i != parent)
        return true;
    }
  }
  return false;
}
int main()
{
  int n, e;
  cin >> n >> e;
  int visited[n+1] = {0};
  fill(*adj, *adj + N*N, 0);
  for(int i=0; i<e; i++)
  {
    int vertix1, vertix2;
    cin >> vertix1 >> vertix2;
    adj[vertix1][vertix2] = 1;
    adj[vertix2][vertix1] = 1;
  }

  bool isCycle = false;
  for(int i=1; i<=n; i++)
  {
    if(!visited[i])
    {
        if(dfsCycle(i, 0, visited, n))
        {
            isCycle = true;
            break;
        }
    }
  }
  if(isCycle) cout << "There exists a cycle in the graph.";
  else cout << "There is no cycle in the graph.";
  return 0;
}
