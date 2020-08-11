/*

  Breadth First Search : A graph traversal Algorithm which follows a 2 step process
                         of scanning all the adjecent (Sibling) vertices.

---------------------------------------- Data Structure Prerequisits ------------------------------------------------------

  1. Adjecency Matrix : A 2d matrix, of (v x v, where v : no. of vertices) size
                        which plots which 2 vertices are connected.
  Eg : Assuming a graph containing 4 vertices, the adj. matrix is :

   _ 1  2  3  4 _       Where : * 1 represents an undirected connection between 2 vertices.
1 |  0  1  1    |               * Vertix associated row represents out-degree connections. (directed graph)
2 |  1 . . . .  |               * Vertix associated coloumn represent in-degree connections. (directed graph)
3 |  1 . . . .  |
4 |_ 0 . . . . _|

2. Visited Array : An array that keeps track of all the vertices visited / not visited. For a graph of n vertices,
                   the length of the array is (n+1) 0-based index(we are gonna start from index 1, to simplify operations).

  Eg : For the above graph, visited = [0,  0, 0, 0, 0];   // initially their values are zero, i.e, not visited.
                                      0    1  2  3  4

3. Queue : To store the vertix to be explored next.
-------------------------------------------------------------------------------------------------------------------------------
-------------------------------------------------- ALGORITHM ---------------------------------------------------

    As defined the algorithm is fundamentally divided into 2 steps :
    1. Visit            2. Explore

    VISIT : where vertix 'i' is visited for the first time.
    Step 1 : input a start vertix (i)
    Step 2 : You have now visited 'i' so mark it as visited : visited[i] = 1.
    Step 3 : Display the value of vertex i : print(i)
    Step 4 : Store the index in the explore queue : queue.insert(i);

    EXPLORE : where adjecent vertices connected to vertix 'i' are explored.
    Step 5 : while(there are elements in the queue) continue visit process.
    Step 6 : Explore all the adjecent, UNVISITED vertices of whatever is on the 'top' position
             of the queue (whatever vertix was first queued for exploration).
             Note : In the case of undirected graph you only need to traverse either row or coloumn (since indegee == outdegree)
    Step 7 : When encounterd an adjecent vertix which is not visited yet, REPEAT step 1 to step 4.

    Time Complexity : O(V + E)
----------------------------------------------------------------------------------------------------------------------------
*/
#include<bits/stdc++.h>
using namespace std;
//----------------------- SETTING UP THE DATA-STRUCTURES ------------------------
int n = 7;
int Adj[][7] = {{0,0,0,0,0,0,0}, // Adjecency Matrix of the graph (starting from 1).
               {0,0,1,1,0,0,0}, // 6x6 data (ignoring index 0s)
               {0,1,0,0,1,0,0},
               {0,1,0,0,1,0,0},
               {0,0,1,1,0,1,1},
               {0,0,0,0,1,0,0},
               {0,0,0,0,1,0,0}};
queue<int> explore;
int visited[7] = {0}; // Array that tracks visited vertices.
//------------------------------------------------------------------------------

//--------------------------- BFS Funtions -------------------------------------
void BFS(int i)
{
    cout << i << " "; // display starting point.
    visited[i] = 1; // mark the start point as visited.
    explore.push(i); // push vertix in "explore queue" to check for the adjecent vertices.
    while(!explore.empty()) // explore till there are vertices to explore in the queue.
    {
      int vertix = explore.front(); // pick the vertix to explore.
      explore.pop(); // remove it out of the queue.
      for(int j = 1; j<n; j++) // explore all elements on the entire row
      {
        if(Adj[vertix][j] == 1 && visited[j] == 0) // if they are connected it, and are unvisited.
        {
          cout << j << " "; // print that connected vertix
          visited[j] = 1; // mark it as "visited"
          explore.push(j); // push it in the queue to be explored AFTER the current vertix is done with its exploration.
        }
      }
    }
}
//------------------------------------------------------------------------------
int main()
{
  BFS(3); // starting point as parameter.
  return 0;
}
