/*
  Single Source Shortest Path (DFS & Tree) : Process to find the shortest path to all the vertices
  from a given source 'i'. The algorithm only works on a single connected component.

  ------------------------------ Solving Aproach -------------------------------
  1. Run DFS from the source with a distance parameter that track the current distance
     travelled by the algorithm.
              dfs(i, d)   where : i = vertix to explore
                                  d = distance travelled so far.

  2. Keep saving the distance travelled before reaching a perticular vertix (say i)
     in an array (say distance[]).
              distance[i] = d

  Note : starting value of d from the source would be 0.
*/
#include <bits/stdc++.h>
#define N 1000
using namespace std;
int adj[N][N];
void dfs(int vertix, int d, int visited[], int distance[], int n)
{
  visited[vertix] = 1;
  for(int i=1; i<=n; i++)
  {
    if(adj[vertix][i] == 1 && !visited[i])  // vertix that is unexplored.
    {
        distance[i] = d+1;  // distance from that source to unexplored vertix (Saving the distance of vertix).
        dfs(i, d+1, visited, distance, n); // run dfs on unexplored vertix.
    }
  }
}
int main()
{
  int n;  // number of vertices/nodes 1 based indexing
  int e;  // number of edges
  cin >> n;
  e = n-1;
  fill(*adj, *adj + N*N, 0);
  int visited[n+1] = {0};
  int distance[n+1] = {0};
  for(int i=0; i<e; i++)  // connections between vertices.
  {
    int vertix1, vertix2;
    cin >> vertix1;
    cin >> vertix2;
    adj[vertix1][vertix2] = 1;
    adj[vertix2][vertix1] = 1;
  }
  int source;
  cin >> source;
  distance[source] = 0; // initial distance of the source is 0.
  dfs(source, 0, visited, distance, n);

  for(int i=1; i<=n ; i++)
    cout << distance[i] << " ";
  return 0;
}
