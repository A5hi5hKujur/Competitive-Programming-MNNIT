/*
Prim's algorithm to create Minimum Spanning Tree :
Applications : Densly populated graph with weighted undirected edges.

Algorithm :
1. maintain a record of all the 'minimum' edge weight connected to n vertices.
    key[n], from i = 0 to i = n-1

  The edge weight of any vertix will be updated every time a path to that vertix
  appears carraying a weight less than the weight already entered.

  Initially the record will have the weight of all vertices as "infinite" (INT_MAX)
  since they are undiscovered.

2. Maintain a record of all the vertices visited, visited[n] and initialize them to
   0, to represent unvisited. (1 = visited).

3. maintain a counter to track the number of vertices visited, the algorithm ends
   when all the 'n' vertices are visited.

4. Find the vertix with minimum weight edge of all the discoverd paths leading to unvisited vertices
    and choose that path by selecting the Vertix which that path leads to, and mark it as "visited".
    (increment the 'visit' counter after every vertix you visit)

5. Look for its adjacent unvisited vertices,
   - if there exists a path of less edge weight than already in the record (key[]),
      update the value of key[i] = matrix[vertix][i]

6. Stop when you have visited all the vertices

Complexities :
1. Adjacency Matrix : O(V x E) where V = no. vertices, E = no. edges
2. Adjacency List : O(E+V) (adj. list) x O(log V) (binary heap)
*/
#include <bits/stdc++.h>
using namespace std;
//---------------------------- Global Variables ---------------------------------
int v = 5;
int matrix[][5] = {{0,2,0,6,0},
                   {2,0,3,8,5},
                   {0,3,0,0,7},
                   {6,8,0,0,9},
                   {0,5,7,9,0}};
//------------------------------------------------------------------------------

//------ Function to return index(vertix) with minimum edge weight -------------

int minEdge(int key[], int visited[]) // O(n)
{
  int min_index, min = INT_MAX;
  for(int i=0; i<v; i++)
  {
    if(!visited[i] && key[i] < min) // any unvisited vertix with the minimum edge weight
    {
        min = key[i];
        min_index = i;
    }
  }
  return min_index;
}
//-------------------------------------------------------------------------------

//---------------------------- Prim's Algo -------------------------------------

void Prims(int start) // starting index as parameter.
{
  int parent[v];                                // Record to store the parent information of the verties 'i'.
  parent[start] = -1;                           // There would be no parent of the starting vertix(since that vertix would be the root).
  int key[v];                                   // array that stores the minimum connected edge weight to the vertix
  for(int i=0; i<v; i++) key[i] = INT_MAX;      // initially all the undiscovered edges have infinite weight.
  int visited[v] = {0};                         // inititially non of the vertices are visited.
  key[start] = 0;                               // the initial min. weigth edge connected to the starting vertix = 0.
  int visit = 0;                                // counter which tracks the number of vertices visited so far (intitially for the starting vertix)
  while(visit != v)                             // untill all the vertix are not visited.
  {
    int vertex = minEdge(key, visited);         // find the unvisited minimum weight vertix to visit to next.
    visited[vertex] = 1;                        // mark that vertix as visited.
    visit++;                                    // increment the number of vertices you visit
    for(int i=0; i<v; i++)                      // check its adjecent connected vertices
    {
      if(matrix[vertex][i] && !visited[i] && key[i] > matrix[vertex][i]) // if there is a "unvisited", "connected" vertix with lesser edge weight.
      {
        key[i] = matrix[vertex][i];             // then update the edge of that vertex to the lesser edge weight.
        parent[i] = vertix;                     // updating the parent information of vertix 'i'.
      }
    }
  }

  int total_edge_weight = 0;
  for(int i=0; i<v; i++) total_edge_weight += key[i];
  cout << "Total Edge weight of all the paths connecting : " << total_edge_weight <<"\n";
  cout << "Vertix : Parent Vertix \n";
  for(int i=0; i<v; i++)
  cout << i << " : " << parent[i] << "\n";
}
//------------------------------------------------------------------------------
int main()
{
  int start = 0;
  Prims(start);
  return 0;
}

//------------------------- Adjecnecy List + Binary Heap -----------------------
#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> adj[9];
vector<bool> visited(9, false);
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> min_heap;
vector<int> key(9, INT_MAX);

void primsMST()
{
    min_heap.push({0,0});
    key[0] = 0;
    while(!min_heap.empty())
    {
        int node = min_heap.top().second;
        min_heap.pop();
        visited[node] = true;
        for(auto neighbor : adj[node])
        {
            int weight = neighbor.first;
            int vertix = neighbor.second;
            if(!visited[vertix] && key[vertix] > weight)
            {
                key[vertix] = weight;
                min_heap.push({weight, vertix});
            }
        }
    }
    int sum = 0;
    for(int i : key)
        sum += i;
    cout << sum;
}
int main()
{
    int v, e;
    cin >> v >> e;
    for(int i = 0; i<e; i++)
    {
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        adj[v1].push_back({w, v2});
        adj[v2].push_back({w, v1});
    }
    primsMST();
    return 0;
}
