/*
  BFS on 2D grid:
    Here the input will be laid out in a M x N grid where M = no. of rows and
    N = no. of columns.

    The BFS algorithm would essentially be the same except for a few variations.
    Node / vertix = cell of a grid.
    edge = Sides(or corners) of the cell.

    Traversal behaviour is spiral (traverses neighbouring valid cells)

    Concept code.

    Complexity O(V + E)
*/
#include<bits/stdc++.h>
#define N 3000
using namespace std;
int grid[N][N];
bool visited[N][N];
int distances[N][N];
int n,m;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
bool isValid(int x, int y)  // valid move function
{
  if(x > n-1 || x < 0 || y > m-1 || y < 0)
    return false;
  if(visited[x][y])
    return false;
  return true;
}
void bfs(int currX, int currY)
{
  queue<pair<int,int>> que; // push x and y coordinate of the starting cell
  visited[currX][currY] = true; // mark starting cell as visited.
  distances[currX][currY] = 0; // distance from starting cell.
  que.push({currX, currY}); // push the coordinates in the queue to be processed.
  while(!que.empty())
  {
      int x = que.front().first;     // current x
      int y = que.front().second;   // current y
      que.pop();
      for(int i=0; i<4; i++)  // explore cells in 4 direction up,down,left, right
      {
        int nextX = x + dx[i]; // next x
        int nextY = y + dy[i]; // next y
        if(isValid(nextX, nextY)) // if you find a valid cell
        {
          distances[nextX][nextY] = distances[x][y] + 1;  // update distance of the next cell based on current cell
          visited[nextX][nextY] = true; // mark all next cells as visited
          que.push({nextX, nextY}); // push coordinates into the queue to be further explored.
        }
      }
  }
  cout << "Distances : \n";
  for(int i=0; i<n; i++)
  {
    for(int j=0; j<m; j++)
      cout << distances[i][j] << " ";
    cout << "\n";
  }

}
int main()
{
  fill(*grid, *grid + N*N, 0);
  fill(*distances, *distances + N*N, 0);
  fill(*visited, *visited + N*N, false);

  cin >> n >> m;
  int x, y;
  cin >> x >> y;  // single source.
  bfs(x,y);

  return 0;
}

// -------------------------- MULTI SOURCE BFS ---------------------------------
void MultSourceBFS(vector<int> graph[],int n,int sources[],int s)
{
    queue<int> q;   //Create a queue for BFS
    for(int i = 0;i < s; i++)
    {
        q.push(sources[i]);       //Mark all the source vertices as visited and enqueue it
        visited[sources[i]] = true;
    }
    BFS(graph,q);
    for(int i = 1; i <= n; i++)    //Printing the distances
        cout<< i << " " << dist[i] << endl;
}
