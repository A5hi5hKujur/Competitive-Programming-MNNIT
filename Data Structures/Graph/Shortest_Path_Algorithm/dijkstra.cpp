/*
  Dijkstra's Algorithm : Finding shortest distance from the source vertix to all other vertices.
  unlike Prim's Algorithm where the source vertix played no significant path on the outcome of the creation
  of the Minimim Spanning Tree, here the algorithm actually cater's to it.

  The majority of the algorithm, remains same as Prim's algorithm, except we would now be adding the sum
  of the distances along the way and updating the edge weight array, if that sum is lesser than the one
  already assigned to its respective vertix.

  The above process is called : Relaxation.

  Where to use Dijkstra ?
  - To find distance of all the vertices from source vertix in a graph.
  - To find the shortest distance from source vertix to destination Vertix
        - In this case you need not require to visit all the verticecs in the graph, if you reach the
          destination vertix you can stop the algorithm since Dijkstra takes the best possible path at every step
          so if a destination is reached it is likly that the shortest distance upto the destination vertix will
          not change irrespective of how many alternate path we process. (if you found the vertix you are already in the
          most optimal path to begin with.)

  Where NOT to use Dijkstra ?
  - Djikstra fails in the case of negative weight edges.
      - You'll keep on "relaxing" at a single spot.
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

//---------------------------- Adjacency list + priority_queue -----------------

void Djikstra(int source, int v)
{
  vector<pair<int, int>> adj[v];
  vector<bool> visited(v, false);
  vector<int> edge(v, INT_MAX);
  priority_queue<pair<int,int> , vector<pair<int, int>>, greater<pair<int, int>>> min_heap;

  min_heap.push({0, source});
  edge[source] = 0;
  visited[source] = true;
  while(!min_heap.empty())
  {
    auto node = min_heap.top();
    min_heap.pop();
    if(edge[node.second] < node.first)      // priority queue redundant pair
      continue;

    for(auto neighbor : adj[node.second])
    {
      int weight = neighbor.first;
      int vertix = neighbor.second;
      if(!visited[vertix] && edge[node.second] + weight < edge[vertix])
      {
        visited[vertix] = true;
        edge[vertix] = edge[node.second] + weight;
        min_heap.push({edge[vertix], vertix});
      }
    }
  }
}
