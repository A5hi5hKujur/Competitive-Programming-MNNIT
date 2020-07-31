/*
    STRONGLY CONNECTED COMPONENTS in a Directed Graph (Kosaraju's Algo.) :

    Strongly Connected Components : Components containing vertices that have a directed
                                    path through other vertices to itself.

                   3 ------x 1 -------x 4             SCC : 3 2 1
                   x        /           |             SCC : 4
                    \     /             x             SCC : 5
                     2  x               5

    Step 1 : Order the vertices based on their DFS "out-time", i.e, the vertix with
             that finishes DFS first is in the last position and the vertix which
             finishes last is in the first position.
                - Store the vertix in a stack after they are done with their DFS.

    Step 2 : Transpose the edges of the vertices :
                    a ---> b   becomes   a <--- b

    Step 3 : Based on the ordering taken in step 1, run a DFS and count connected

    Complexity BreakDown :
    Step1 + Step2 + Step3 : O(V+E) + O(V+E) + O(V+E) = O(V+E)
*/
#include <bits/stdc++.h>
using namespace std;
vector<int> adj[6];
vector<int> tadj[6];
vector<bool> visited(6, false);
stack<int> st;

void Order(int vertix)          // Step 1 : Order according to "outtime".
{
    visited[vertix] = true;
    for(int neighbor : adj[vertix])
    {
        if(!visited[neighbor])
            Order(neighbor);
    }
    st.push(vertix);    // push in the stack when the DFS is exhausted.
}

void Transpose()        // Step 2 : Transpose Adj List
{
    for(int i = 1; i<6; i++)
    {
        for(auto j : adj[i])
         tadj[j].push_back(i);
    }
}

void SCCC(int vertix)       // Step 3 : Run DFS to count connected components.
{
    visited[vertix] = true;
    cout << vertix << " ";
    for(int neighbor : tadj[vertix])
    {
        if(!visited[neighbor])
            SCCC(neighbor);
    }
}
int main()
{
    int v,e;
    cin >> v >> e;
    for(int i=0; i<e; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        adj[v1].push_back(v2);
    }
    for(int i=1; i<6; i++)          // step 1
        if(!visited[i])
            Order(i);

    Transpose();                    // step 2
    fill(visited.begin(), visited.end(), false);

    int count = 0;                  // step 3
    while(!st.empty())
    {
        if(!visited[st.top()])
        {
            cout << "SCC : ";
            SCCC(st.top());
            cout << "\n";
            count++;
        }
        st.pop();
    }
    cout << count;              // totol count of SCC
    return 0;
}
