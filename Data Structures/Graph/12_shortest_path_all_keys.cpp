/*
You want to build a house on an empty land which reaches all buildings in the shortest amount of distance.
You can only move up, down, left and right. You are given a 2D grid of values 0, 1 or 2, where:
  Each 0 marks an empty land which you can pass by freely.
  Each 1 marks a building which you cannot pass through.
  Each 2 marks an obstacle which you cannot pass through.

For example, given three buildings at (0,0), (0,4), (2,2), and an obstacle at (0,2):
1 0 2 0 1
0 0 0 0 0
0 0 1 0 0
The point (1,2) is an ideal empty land to build a house, as the total travel distance of 3+3+1=7 is minimal. So return 7.
Note: There will be at least one building. If it is not possible to build such house according to the above rules, return -1.
*/
#include <bits/stdc++.h>
using namespace std;
int h, w;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int visit[105][105];
int found[105][105];
int dist[105][105];
int final[105][105];
bool isValid(vector<vector<int>>& A, int x, int y)
{
    if(x < 0 || y < 0 || x >= h || y >= w)
        return false;
    if(visit[x][y] || A[x][y] == 1 || A[x][y] == 2)
        return false;
    return true;
}
void BFS(vector<vector<int>>& A, int i, int j)
{
    fill(*visit, *visit + (105*105), 0);
    fill(*dist, *dist + (105*105), 0);
    queue<pair<int, int>> que;
    que.push({i, j});
    int d = 0;
    while(!que.empty())
    {
        int x = que.front().first;
        int y = que.front().second;
        que.pop();
        for(int i=0; i<4; i++)
        {
            int adjx = x + dx[i];
            int adjy = y + dy[i];
            if(isValid(A, adjx, adjy))
            {
                que.push({adjx, adjy});
                visit[adjx][adjy] = 1;
                dist[adjx][adjy] +=  dist[x][y] + 1;
                found[adjx][adjy] += 1;
                final[adjx][adjy] += dist[adjx][adjy];
            }
        }
    }
}
int main()
{
    vector<vector<int>> adj = {{1, 0, 2, 0, 1},
                              {0, 0, 0, 0, 0},
                              {0, 0, 1, 0, 0}};

    //vector<vector<int>> adj = {{1,0},{1,0}};
    h = adj.size();
    w = adj[0].size();

    fill(*found, *found + (105*105), 0);
    fill(*final, *final + (105*105), 0);

    int count_building = 0;
    for(int i=0; i<h; i++)
    {
        for(int j=0; j<w; j++)
        {
            if(adj[i][j] == 1)
            {
                BFS(adj, i, j);
                count_building++;
            }
        }
    }
    int min_dist = INT_MAX;
    bool path_found = false;
    for(int i=0; i<h; i++)
    {
        for(int j=0; j<w; j++)
        {
            if(found[i][j] == count_building && final[i][j] > 0)
            {
                min_dist = min(min_dist, final[i][j]);
                path_found = true;
            }
        }
    }

    if(!path_found)
        cout << "No path exists";
    else
        cout << min_dist;

    return 0;
}
