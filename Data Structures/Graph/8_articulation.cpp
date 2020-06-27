/*
  LOCATING ARTICULATION POINT
  Articulation Point : The vertix which when removed from the graph further divides
                       the graph into multiple connected components.

  Observation 1 :

         2 ------ 1 ------ 3          Edges, (2,1) and (1,3) form a bridge.
       /  \              /  \         Vertices, 2,1,3 are articulation point but also the end point of bridges.
     /     \           /     \
    4 ---- 5          6 ----- 7

 Observation 2 :

      2 ------ 1      Edges, (2,1) form a bridge.
    /  \              Even though, vertices 2 and 1 are the end points of the bridge, 2 is an articulation point but 1 isn't.
  /     \             This is because upon removing vertix 1, the number of connected components in the graph remains the same.
 4 ---- 5

 Observation 3 :

      1       4       There are no bridges in this graph,
    /  \    /  \      Yet, vertix 2 is an articulation point since it divides the graph into 2 connected components.
  /     \ /     \
 3 ----- 2 ----- 5

 CONCLUSION : Number of articulation point and their location does not depend upon the number or location of bridges.

---------------------------------- SOLVING APPROACH ----------------------------

Condition for articulation point :
1. If a current vertix is connected to a subtree which is the only path to reach that subtree, i.e,
There does not exist any back-edges from any of the descendents of the current vertix to any of the
ancestor of the current vertix.

2. The current vertix is also directly connected to atleast 2 adjacent vertices.

Similarities to bridge algortithm :
- Same process to trace direct-edge while running a dfs.
- Same process to locate back-edges to ancestors upon backtracking.

New Additions :
 - articulation condition : If at the time of back-tracking, the current vertix has the in-time less or equal to
                            the low-time of the child vertix, and the current vertix has more vertices connected to itself,
                            then the current vertix is an articulation point.

                  Reason : If( low_time[child] <= low_time[vertix])
                             Then whatever vertices that the child is connected to further down the graph has no connection
                             to any ancestor of the current vertix, therefore they can form their own separate connected component
                             without any disturbance from the orignal graph.

 - Root handling : Mark root as articulation point only when there are more than 1 children connected to it.

*/
#include<bits/stdc++.h>
#define N 100005
using namespace std;
vector<int> adj[N];
int timer = 1;
void dfs(int vertix, int parent, int in_time[], int low_time[], int visited[])
{
  visited[vertix] = 1;
  in_time[vertix] = low_time[vertix] = timer++;
  int children = 0;  // track the number of children connected to the vertix.

  //------------------------- Same as bridge tracking --------------------------
  for(int child : adj[vertix])
  {
    if(child == parent) continue;
    if(visited[child])
      low_time[vertix] = min(in_time[child], low_time[vertix]);
    else
    {
      children++; // increment the count of children connected to the vertix (apart from parent)
      dfs(child, vertix, in_time, low_time, visited);
      low_time[vertix] = min(low_time[child], low_time[vertix]);
  //--------------------------- End of Similarities ----------------------------

      if(in_time[vertix] <= low_time[child] && parent != 0)  // Articulation condition(vertix not root) : if intime of the vertix is less(or equal) than the lowest in time of the child
        cout << vertix << " is an articulation point.\n";     // NOTE : if the intime of the vertix is equal to the lowest intime of the child, that means vertix itself is the ancestor of the entire subtree.
    }
  }
  if(parent == 0 && children > 1) // articualtion condition when a vertix is a root.
    cout << vertix << " is an articulation point.\n";
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
  for(int i=1; i<=n; i++)
    if(!visited[i])
        dfs(i, 0, in_time, low_time, visited);
  return 0;
}

/*
  NOTE : Since articualtion points might be visited multiple times during dfs traversal, we can store the points in sets,
         everytime we encounter them to display unique occurance and exact number of the articulate points.
*/
