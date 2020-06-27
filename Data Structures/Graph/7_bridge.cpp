/*
FIND BRIDGES IN YOUR GRAPH.
Bridges in a graph : EDGES which when removed breaks a graph into more connected
components.

For example if we took out the edge between vertix (8 and 10),
(7 and 9), (4 and 1). These edges are called "Bridges", however if we say remove an
edge between (2 and 7) there would still be a path from 2 to 7.

Forward-edge : The edges a dfs algorithms travels through vertices and its descendents.

Back-edges : alternate paths between ancestor vertix and descendent vertix, such that
             ancestor != parent vertix.
             eg : assume there is a direct edge between vertiecs 2 and 7 after dfs is completed.
                  dfs would have left out the edge 2 and 8 during its execution. this alternate
                  path becomes a back-edge.

            4 ------ 1 ------ 3
          /   \       \      /
        5 ---- 6       \   /
                         2
                       / |
                     /   |
                    8 -- 7
                  /      \
                10        9

 Observations :
 - Backedges can never be a "bridge" since there exists an alternate traversal path.

 ---------------------------------- Solving Approach ---------------------------

 1. Find the "back-edges" to eleminate them in the search of "bridges".
    - vertices which is connected to an already visited node that is NOT its parent.

 2. If adjacent vertix is connected to a visited vertix that is not its parent, that means its a backedge.
 3. If adjacent vertix is not visited, there is a chance that it can be a "bridge".

 Tracking ancestor and descendent :
 1. A timer should be maintained upon running a dfs algorithm which tracks the in-time of all vertices.

 2. Intime[ancestor] < Intime[descendent].

 3. Vertix with a backedge will have Intime[ancestor(parent)] > Intime[descendent(child)].

 4. If you find a vertix with backedge, we minimize the Intime it takes to reach the vertix by assigning a
    minimum_in_time = min(Intime[current], Intime[ancestor])
                      why min() ?? because when the algorithm trackbacks, there would be a point where
                      the "ancestor" would become the "current" and vise versa, taking minimum would accurately
                      depect which vertix is the ancestor and which vertix is child.

 5. Bridge condition would be checked at the time of backtracking where every backtracked vertix(parent) will check if the
    vertix from which they came back(child) has an inTime lower then it or not.
    - If yes : there is more ways to reach the vertix's child. so this path is not a "bridge".
               update parent vertix intime as well.
    - If no : there is no more ways to reach the child, mark the edge between parent and the child as "bridge".
*/

#include <bits/stdc++.h>
#define N 100005
using namespace std;
vector<int> adj[N];

int timer = 1;  // in-time counter starts.
/*
  Function description : Function to trace a direct path via dfs and locate bridges
                         while backtracking.

  Return Type : void, array manupulation.

  Paramenters:
  1. vertix = Current node that is being refered to.
  2. parent = The adjacent ancestor node from where the traversal came from.
  3. in_time[] = Array to track in-time of all the vertices while executing dfs in the graph.
  4. low_time[] = Array to track the lowest possible time to access a correspnding vertix.
  5. visited[] = Array to track which vertix is visited.
*/
void dfs(int vertix, int parent, int in_time[], int low_time[], int visited[])
{
  visited[vertix] = 1;
  in_time[vertix] = low_time[vertix] = timer++; // assigning in-time upon first visit of a vertix.
  for(int child : adj[vertix]) // explore adjacent vertices
  {
    if(child == parent) continue; // if the adjacent vertix is the parent ignore !
    if(visited[child]) // if an ancestor vertix is found that is already visited (apart from the parent)
    {
      low_time[vertix] = min(low_time[vertix], in_time[child]); // update the low_time of current vertix to the intime of the ancistor.
    }
    else  // if the child is unvisited.
    {
      dfs(child, vertix, in_time, low_time, visited); // run dfs on the child.

      // Back tracking starts here.
      if(low_time[child] > in_time[vertix]) // if the child you just came from has a low_time higher than the in_time of current vertix.
        cout << "There exists a bridge between " << child << " and " << vertix << "\n"; // there does not exist an alternate path to child.
      low_time[vertix] = min(low_time[vertix], low_time[child]); // update current low time to either itself or the childs low time, whichever is smallest.

      /* the reason we update the low_time of the parent after comparing it with the child is bcause if there exists a path to reach the child, through the parent's
          ancestor, then the parent can reach the same ancestor in atleast the same time it takes for the ancestor to reach the child.
      */
    }
  }
}
int main()
{
  int n,e;
  cin >> n >> e;
  for(int i=0; i<e; i++)
  {
    int u,v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  int visited[n+1] = {0};
  int in_time[n+1] = {0};  // array to track in-time of the correspnding vertix.
  int low_time[n+1] = {0}; // array to track lowest in-time of the correspnding vertix.
  dfs(1, 0, in_time, low_time, visited);
  return 0;
}
