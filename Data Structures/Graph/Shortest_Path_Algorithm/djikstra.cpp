/*
  Dijkstra's Algorithm : Finding shortest distance from the source vertix to all other vertices.
  unlike Prim's Algorithm where the source vertix played no significant path on the outcome of the creation
  of the Minimim Spanning Tree, here the algorithm actually cater's to it.

  The majority of the algorithm, remains same as Prim's algorithm, except we would now be adding the sum
  of the distances along the way and updating the edge weight array, if that sum is lesser than the one
  already assigned to its respective vertix.

  The above process is called : Relaxation.
*/
#include <bits/stdc++.h>
using namespace std;
int v = 5;
int matrix[][5] = {{0,2,0,6,0},
                   {2,0,3,8,5},
                   {0,3,0,0,7},
                   {6,8,0,0,9},
                   {0,5,7,9,0}};
int minLength(vector<int> visited, vector<int> edge)
{
  int min = INT_MAX, min_index;
  for(int i=1; i<=v; i++)
  {
    if(!visited[i] && edge[i] < min)
    {
      min = edge[i];
      min_index = i;
    }
  }
  return min_index;
}
void Djikstra(int source)
{
  vector<int> edge(v+1, INT_MAX);
  vector<int> visited(v+1, 0);
  int visit = 0;
  edge[source] = 0;
  while(visit != v)
  {
    int vertix = minLength(visited, edge);
    visited[vertix] = 1;
    visit++;
    for(int i=1; i<=v; i++)
    {
      /*
      if the adjacent vertix have a path and are unvisited AND the sum of
      the edge weight from the vertix we are currently on and the adjacent vertix
      is less than the edge weight already recorded for the unvisited vertix
      */
      if(matrix[vertix][i] && !visited[i] && edge[vertix] + matrix[vertix][i] < edge[i])
      {
        edge[i] = matrix[vertix][i] + edge[vertix]; // update the edge weight with that sum.
      }
    }
  }
  for(int i=1; i<=v; i++)
  cout << "distance from " << source << " : " << edge[i] << "\n";
}
int main()
{
  int source = 0;
  Djikstra(source);
  return 0;
}
