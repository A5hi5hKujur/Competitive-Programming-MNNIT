/******************************************************************************
Kruskal's algorithm : Minimum spanning tree creation algorithm.
Algorithm :
1. Create a array of structures which stores the connection between INIVIDUAL SET
   of source vertix, destination vertix and the edge weight connecting these vertices.

   struct edge{
        int source;
        int destination;
        int weight;
   };

   struct edge connection[no. of edge connections]

2. push all the edge connections in the "connection" array.

3. sort the connection array with respect to connection[i].weight in ascending order.
   this way connections with the shortest edge weight come first.

UNION FIND :
4. Maintain a root array which keeps track of all the root of all the vertices.
5. Initialize them with themselves.


*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;
//--------------------- Structure of individual connection ---------------------
struct edge{
    int source;
    int destination;
    int weight;
};
//------------------------------------------------------------------------------

//----- Sort structure array in ascending order based on edge weight -----------
bool compareWeight(struct edge s1, struct edge s2)
{
    return s1.weight < s2.weight;
}
//------------------------------------------------------------------------------

//------------------------ Find Root of the vertix -----------------------------

int findRoot(int root[], int i)
{
    if(root[i] == i) return i;
    return findRoot(root, root[i]);
}
//------------------------------------------------------------------------------
//------------------------- Kruskal Algorithm ----------------------------------

void Kruskal(struct edge connections[], int n, int e)
{
    int root[n]; // array that tracks roots of all the connected vertices.
    for(int i=0; i<n; i++) root[i] = i; // initially each vertix is connected to itself

    int count = 0; // tracks the number of vertices picked.
    struct edge MST[n-1]; // vertices in the MST.
    for(int i=0; i<e; i++)
    {
        if(count < n-1)   // continue loop till you have n-1 edges which is maximum amount of edges required to connect all vertices in MST.
        {
            struct edge current_edge = connections[i]; // stores the current connection to be worked on.
            int source_root = findRoot(root, current_edge.source);
            int destination_root = findRoot(root, current_edge.destination);
            if(source_root != destination_root) // if there are no cycles
            {
                MST[count] = current_edge;
                count++;
                root[source_root] = destination_root; // union
            }
        }
        else break;
    }
    //print MST
    for(int i=0; i<n-1; i++)
    {
        if(MST[i].source < MST[i].destination)
        cout << MST[i].source << " " << MST[i].destination << " " << MST[i].weight << "\n";
        else
        cout << MST[i].destination << " " << MST[i].source << " " << MST[i].weight << "\n";
    }
}
//------------------------------------------------------------------------------
int main()
{
    int n, e; // n : no. of vertices / e : no. of edges
    cin >> n >> e;
    struct edge connections[e];
    for(int i=0; i<e; i++)
    {
        int s,d,w;
        cin >> s >> d >> w;
        connections[i].source = s;
        connections[i].destination = d;
        connections[i].weight = w;
    }
    sort(connections, connections+e, compareWeight);
    Kruskal(connections, n, e);
    return 0;
}
