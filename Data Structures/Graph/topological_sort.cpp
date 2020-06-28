/*
  topological sorting in directed graph.
    The order in which vertices needs to be traversed if they have dependencies (indegrees from other vertices)

    Kahn's Algorithm :
    1. Select the vertices with no indegrees (vertices that are no dependent on any other vertix).
    2. One by one select those vertices and remove all directed edges connecting their children. after which push it in the "answer list"
    3. Every time all the indegrees of the child diminish to 0, that represents all its dependencies are taken care of,
       so add it to the list of vertices in step 1.
    4. Do this till all the vertices gets exhausted.

    Time Complexity : O(V+E)
    Space Complexity : O(V)  *queue*
*/
#include<bits/stdc++.h>
#define N 100000
using namespace std;
vector<int> adj[N];
void topSort(int in_degree[], vector<int> order, int n)   // SIMILAR To BFS
{
    queue<int> que;   // que that keeps track of all the vertices with indegree 0.
    for(int i=1; i<=n; i++)
        if(in_degree[i] == 0) que.push(i);

    while(!que.empty()) // while there are vertiecs with in_degree 0
    {
        int vertix = que.front(); // process the vertix on the top of the queue
        que.pop();
        order.push_back(vertix);  // push it in the result list.
        for(int child : adj[vertix])  // explore the directed path between current vertix and its children.
        {
            in_degree[child]--; // remove the directed edge, from vertix -> child
            if(!in_degree[child]) // if there are no longer any indegrees connected to the child
                que.push(child);  // add that child to the queue to be processed.
        }
    }
    for(auto i : order) // Display the topological order (non-unique)
        cout << i << " ";
}
int main()
{
    int n, e;
    cin >> n >> e;
    vector<int> order;
    int in_degree[n+1] = {0};   // count the number of all the indegrees in the correspnding vertices.
    for(int i=0; i<e; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);  // u -> v
        in_degree[v]++;       // incrementing the indegree of vertix v.
    }
    topSort(in_degree, order, n);
    return 0;
}
