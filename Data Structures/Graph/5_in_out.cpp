/*
  In and out time : Measured by edge count.
  In time  : The exact time when the control entered a vertix.
  Out time : The exact time when the control left a vertix.

  - This concept is used in algorithms to find articulate point.
  - By itself you can use it to check if 2 given vertices belong to the same subtree.
*/
#include<bits/stdc++.h>
#define N 100005        // Max capacity of N.
using namespace std;

vector<int> adj[N];    // adjacent list
int timer = 1;        // timer to track in/out time, starts from 1.
void dfs(int vertix, int in[], int out[], int visited[])
{
  visited[vertix] = 1;    // new vertix visited
  in[vertix] = timer++;   // log the exact moment the vertix is visited and increment the timer.
  for(int child : adj[vertix])    // iterate through all the children of the vertix.
  {
    if(!visited[child])   // if the child vertix is unvisited
    dfs(child, in, out, visited); // explore
  }
  out[vertix] = timer++; // once all its childen are explored, log the exact time before the control leaves the vertix and increment the timer.
}
int main()
{
  int n,e;
  cin >> n >> e;
  int visited[n+1] = {0};
  for(int i=0; i<e; i++)
  {
    int vertix1, vertix2;
    cin >> vertix1 >> vertix2;
    adj[vertix1].push_back(vertix2);
    adj[vertix2].push_back(vertix1);
  }
  int in_time[n+1] = {0};
  int out_time[n+1] = {0};
  for(int i=1; i<=n; i++) // run dfs on all connected components
  {
    if(!visited[i])
        dfs(i,in_time,out_time,visited);
  }
  for(int i=1; i<=n; i++) // display table of vertex in/out time.
  {
    cout << "Vertix "<< i << "\tIn Time : " << in_time[i] << "\tOut Time : " << out_time[i] << "\n";
  }
  return 0;
}
