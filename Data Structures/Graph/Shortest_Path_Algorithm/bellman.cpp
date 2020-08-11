/*
    Bellman Ford Algorithm : (A Dynamic Programming Problem)

    When to use Bellman Ford Algorithm ?
    - When you need to find distances between vertices.
    - When there are few number of vertices and edges.
    - When there are negetive edges between vertices.
    - Alternate for Dijkstra.

    For any node to another there will be a maximum v-1 edges, therefor we do v-1
    relaxations in the hopes to get to the most optimal outcome.



    Step 1 : Fill all the vertices with infinite distance.
                fill(distance, distance + v, INT_MAX)

    Step 2 : Perform relaxation of all the edges v-1 times.
            Edge Relaxation :
                condition 1. If distance of current vertix is not infinity.
                If current vertix distance is INFINITY, that means a path to current has not been found

                condition 2. distance of adj vertix < distance[u] + distance of adj vertix
                If adj. vertix's distance is minimized by adding current distance to the adj. distance

                Then the distance of the adj. vertix is updated to adj. vertix distance + current vertix distance

            If(dist[u] != INT_MAX && dist[u] + distance < dist[v])
                dist[v] = dist[u] + distance;

    Step 3 : Check for negative edge cycle and Print minimum distances to all the vertices

    Complexity : O(V*E)
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<pair<int, pair<int,int>>> adj;   //  pair {weight , pair{v1, v2}}
    int v,e;                                //  no. of vertices and edges
    cin >> v >> e;
    vector<int> dist(v, INT_MAX);           // Initialize all the distances to infinity
    for(int i = 0; i<e; i++)                // INPUT
    {
        int v1, v2, w;
        cin >> v1 >> v2 >> w;               // vertix1, vertix2, weight
        auto vertices = make_pair(v1,v2);   // vertices pair
        adj.push_back({w, vertices});       // {weight, pair}
    }
    dist[0] = 0;                            // starting distance of source = 0
    for(int i=1; i<=v-1; i++)               // v-1 relaxation.
    {
        for(int j=0; j<e; j++)              // number of edges
        {
            int u = adj[j].second.first;    // vertices.first
            int v = adj[j].second.second;   // vertices.second
            int weight = adj[j].first;      // weight

            if(dist[u] != INT_MAX && dist[u] + weight < dist[v])    // if weight of u is not infinity AND weight of adj vertix < weight[u] + weight of v
                dist[v] = dist[u] + weight;     // vertix distance = distance[u] + weight
        }
    }

    // If there are more relaxation after n-1 iteration then there exists a negative cycle.
    for(int i=0; i<e; i++)
    {
        int u = adj[i].second.first;
        int v = adj[i].second.second;
        int weight = adj[i].first;

        if(dist[u] != INT_MAX && dist[u] + weight < dist[v])
            cout << "Graph contains negative cyle";
    }

    for(int i : dist)
        cout << i << " ";
    return 0;
}
