/*
Diameter of a Tree / longest path between 2 vertices in a tree.
Step 1 : Choose any random vertix in a given tree.
Step 2 : find the vertix with the furthest distance using DFS(random_vertix), this would be the first point of the diameter.
Step 3 : run dfs on the furthest distance vertix, found in step 2 to find the 2nd point of the diameter.
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> adj[100005];

void dfs(int vertix, int distance, int distances[], int visited[])  // DFS to populate distance array from any source.
{
    visited[vertix] = 1;
    distances[vertix] = distance;
    for(int child : adj[vertix])
      if(!visited[child])
        dfs(child, distance + 1, distances, visited);
}
int main()
{
    int n,m;
    cin >> n >> m;
    for(int i=0; i<m; i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int visited[n+1] = {0};
    int distances[n+1] = {0};
    dfs(n,0, distances, visited); // run dfs on an arbitrary index n.
    int v1 = 0;
    for(int i=1; i<=n; i++) // once all the distances are stored, find the vertix with the max distance. (Diameter vertix 1)
    {
        if(distances[i] > distances[v1])
            v1 = i;
    }
    fill(visited, visited+(n+1), 0);
    fill(distances, distances+(n+1), 0);
    dfs(v1, 0, distances, visited); // run a fresh dfs with reset values on the furthest vertix found. (Diameter vertix 2)
    int v2 = v1;
    for(int i=1; i<=n; i++)
    {
        if(distances[i] > distances[v2])
            v2 = i;
    }
    cout << "The longest path exists between vertix " << v1 << " and vertix " << v2;
    return 0;
}
