/*
  CHECK IF A GIVEN GRAPH IS BIPERTITE OR NOT.
  Bipertite Graph : Graph that contains 2 sets of vertices that are not connected by
  vertices of the same set but if connected, they're always connected to the other
  set,

 BIPERTITE RULE : vertices adjacent to each other should not have the same color/set-value
  ----------------------------- Solving Approach -------------------------------
  Assign 0 = group 1 ; 1 = group 2 or any other id to identify elements of same group.
  1. Run an iterative DFS on all the vertices that are adjoint to the current vertix.
  2. If adjoint vertix is unvisited, visit the vertix and mark is as visited and Assign
     a group(color) opposite to the color of the vertix that it came from.

          dfs(vertix, color)  where, vertix : current vertix being explored.
                                     color : color of the vertix from where it came from.

  3. If the adjoint vertix is visited, check the color of the visited vertix, if it is same
     as the vertix from which it came from then return false.
  4. Return true if condition in step 3 doesn't suffice.

  At any point the function returns false, the graph is not bipertite.
*/
#include<bits/stdc++.h>
#define N 3000
using namespace std;
int adj[N][N];          // adj. matrix
/*
  Function Discription :
  Return type : boolean,
                TRUE : The condition for the graph to be bipertite, holds correct so far.
                FALSE : The condition for the graph to be bipertite has failed.
  Parameters :
  1. Vertix = The current vertix you are exploring.
  2. color = The color of the neighbouring vertix.
  3. visited[] = list to keep track of all the visited vertices.
  4. colors[] = list to keep track of all the colors of the visited vertices.
  5. n = total number of vertices.

  The function explores all the vertices in a connected componenets to check if all the vertices
  connections uphold the rule of a bipertite graph.
*/
bool bipertiteDFS(int vertix, int color, int visited[], int colors[], int n)
{
  if(visited[vertix] == 1)  // if the node is visited before
  {
    if(colors[vertix] == color) // check if the visited node has the same color than its neighbour.
      return false; // if so then bipertite condition failed.
    else
      return true;  // if not the bipertite condition is upholded so far.
  }
  else  // if the node is unvisited and you are visiting it for the first time.
  {
    visited[vertix] = 1;  // mark it as visited
    colors[vertix] = !color; // mark the color opposite to the color of the neighbouring vertix
    for(int i=1; i<=n; i++) // look for adjacent vertices to explore.
    {
      if(adj[vertix][i] == 1) // if adjacent vertix is found.
      {
        if(dfs(i,colors[vertix],visited,colors,n) == false) // run the bipertiteDFS function on it to and wait for a recursive response.
        return false; // if the recursive response is returned false, then somewhare along the line there were a set of vertices that failed to uphold the bipertite rule.
      }
    }
  }
  return true;
}
int main()
{
  fill(*adj, *adj + N*N, 0);
  int n;  // no. of vertices
  int e;  // no. of edges
  cin >> n >> e;
  int visited[n+1];
  int color[n+1];
  for(int i=0; i<e; i++)
  {
    int vertix1, vertix2;
    cin >> vertix1;
    cin >> vertix2;
    adj[vertix1][vertix2] = 1;
    adj[vertix2][vertix1] = 1;
  }
  bool result = true; // variable to store the anser of all connected componenets.
   for(int i=1; i<=n; i++)  // checking bipertite rule in all connnected componenets of a graph.
   {
     if(!visited[i])
     {
         result =  bipertiteDFS(i, 1, visited, colors, n);
     }
     if(result == false) break; // if any one connected componenet returns false, the graph is not bipertite.
   }
   if(result == true)
     cout << "Graph is Bipertite\n";
   else
     cout << "Graph is not Bipertite\n";
  return 0;
}
