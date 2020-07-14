/*
----------------------------- PROBLEM STATEMENT --------------------------------
Finding the number of connected components in a graph.

CONNECTED COMPONENTS / WEAKLY CONNECTED COMPONENTS (undirected graph) : These are a cluster of vertices that have an undirected path to
every vertix.

1               3 -- 6
 \   2       Component 2
  \ /
   4              7
    \         Component 3
     5
 Component 1

 The following cluster contains of 3 connected components :
 Component_1 : 1, 2, 4, 5
 Component_2 : 3, 6
 Component_3 : 7

 STRONGLY CONNECTED COMPONENTS (directed graph) : These are a cluster of vertices that have a directed
 path to every vertix.

A cluster of single connected component is called a tree.

------------------------- SOLVING APPROACH -------------------------------------

1. Initailize all the vertices as visited,
2. Iteratively run a dfs(i) algorithm on all the unvisited vertiecs.
3. At the end of each dfs algorithm all the vertices connected to 'i' will be marked
  as visited and would represent a single connected component.
4. Count the number of DFS calls made while traversal in step 2. Those represent
  separate connected component.
5. Print the count.

*/
#include <bits/stdc++.h>
#define N 1000
using namespace std;
int adj[N][N];
void dfs(int vertix, int visited[], int n)
{
  visited[vertix] = 1;
  for(int i=1; i<=n; i++)
  {
    if(adj[vertix][i] == 1 && !visited[i])
      dfs(i, visited, n);
  }
}
int main()
{
  int n;  // number of vertices/nodes 1-based indexing
  int e;  // number of edges
  cin >> n >> e;
  fill(*adj, *adj + N*N, 0);
  int visited[n+1] = {0};
  for(int i=0; i<e; i++)  // connections between vertices.
  {
    int vertix1, vertix2;
    cin >> vertix1;
    cin >> vertix2;
    adj[vertix1][vertix2] = 1;
    adj[vertix2][vertix1] = 1;
  }
  int count = 0;  // track of all components in the cluster.
  for(int i=1; i<=n; i++)
  {
    if(!visited[i])
    {
      count++;    // if you find any unvisited vertix even after running DFS then that means that is a new Connected Component.
      dfs(i, visited, n);
    }
  }
  cout << "Number of Connected Components are : " << count;
  return 0;
}
