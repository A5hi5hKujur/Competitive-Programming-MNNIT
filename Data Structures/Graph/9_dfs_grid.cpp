/*
  DFS on 2D grid:
    Here the input will be laid out in a M x N grid where M = no. of rows and
    N = no. of columns.

    The DFS algorithm would essentially be the same except for a few variations.
    Node / vertix = cell of a grid.
    edge = Sides(or corners) of the cell.

    Traversal behaviour is linear. (traverses adjoint valid cells and then backtracks)

    Concept code.

    Time Complexity : O(V + E)
*/
#include<bits/stdc++.h>
#define N 3100
using namespace std;
int grid[N][N];
int visited[N][N];
int n,m;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};       // dx[0],dy[0] = right ; dx[1],dy[1] = down ; dx[2],dy[2] = left ; dx[3],dy[3] = up

bool validMove(x, y)
{
  if(x > n-1 || x < 0 || y > m-1 || y < 0 )
    return false;
  if(visited[x][y])
    return false;
  return true;
}
void dfs(int x, int y)
{
    visited[x][y] = 1;
    cout << x << " " << y;
    for(int i=0; i<4; i++)
      if(validMove(x + dx[i], y + dy[i]))
        dfs(x + dx[i], y + dy[i]);
}
int main()
{
  fill(*grid, *grid + N*N, 0);
  fill(*visited, *visited + N*N, 0);
  cin >> n >> m;
  for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
      cin >> grid[i][j];
  dfs(0,0);
  return 0;
}
