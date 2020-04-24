/*
  UNION FIND : O(log n)
  This is a method to :
  1. Find if there exists a cycle in a graph.
  2. Number of connections in disjoint sets.
  3. Connected members in disjoint sets.

  DATA-STRUCTURE to trace the graph information :
  * Array Of Objects (theoretically)
   arr = [{},{},{},..]

  * Vector pairs (practically)
  arr = [(x,y) ,(), ()...]
  arr[i].first : stores root information. (x)
  arr[i].second : stores total number of vertices connected to it. (y)
  where,
   ___________________________________________
  | index of a vector = label of that vertix.|
  ''''''''''''''''''''''''''''''''''''''''''''
  ALGORITHM :
  1. Initialzing the graph (arr)
    - elements 1 to n would disjoint sets where their :
      x : themselves
      y : 1 (since their party include of themselves initially)

  2. Find the roots of the inputed vertices (a,b) to be merged.

  3. Process to find the root of a vertix (i) :
    - if( i == arr[i].root ) ->  return i // vertix i is already the root of the disjoint set.
    - if not -> travese the arr[i].root of the arr[i] till i == arr[i].root
    - return root.
    Optimization note : change the root information of vertix i to root,
                        doing this would shorten the time taken to trace back to
                        the root the next time.

   4. perform UNION of the 2 disjoint sets from their roots :
    - if(root A == root B) There exists a cycle.
    - if(connections A > connections B) merge B to A.
    - if(connections B > connections A) merge A to B.
    - if(connections B == connections A) && if(root A < root B) merge B to A.
    - if(connections B == connections A) && if(root B < root A) merge A to B.

  5. Display informations (END)

  AT THE END OF THE QUERIES, VERTICES WITH :
  connections = 1 : the disjoint set consists of only the root element.
  connections = 0 : the disjoint set has been dissolved into another.

  - Minimum connections (conn > 1 && conn < min)
  - Maximum connections (conn > max)
  - Minimum connections can be equal to Maximum connections.
  ------------------------ PROBLEM ---------------------------------------------
  The data structure used however, vector of pairs, will be highly memory
  consuming and will exhaust its limit in mildly large values.

  SOLUTION : take 2 vectors
            1. vector <int> root(n+1); // to map root
            2. vector <int> count(n+1); // connection count

  EXAMPLE :
    for (int i=1;i<=n;i++) {
        root[i]=i; // arr[i].first
        count[i]=1; // arr[i].second.
    }

  P.S : I observed this problem while submitting this to an online judge. The
       algorithm however remains unchanged.

--------------------------------------------------------------------------------
*/

//-------------------------- PROGRAM 1 (conceptual) ----------------------------
#include <bits/stdc++.h>
using namespace std;
//-------------------------- GLOBAL VARIABLES ----------------------------------
int n; // number of vertices in the graph.
vector<pair<int,int>> arr; // Data structure to store graph information.
//------------------------------------------------------------------------------

//------------ Function to Find the root of the selected vertix. ---------------
int findRoot(int x)
{
  int element = x; // index value of the DS 'arr'.
  int find = arr[element].first; // root information of the vertix 'x'.
  while(element != find){ // traverse until you reach the root of x.
    element = find;
    find = arr[element].first;
  }
  // when the loop terminates 'element' has the value of root of x.
  // if x wasn't already pointing to the root, make it point to the root.
  if(x != element) arr[element].first = element; // OPTIMIZATION.
  return element; // return the root of x.
}
//------------------------------------------------------------------------------

//---------------------- Performing union of 2 roots ---------------------------
// union of y vertix to x vertix, after which y gets dissolved into x.
// x is the dominant vertix.
// y is merged with x.
void Union(int x, int y){
  arr[x].second += arr[y].second; // all of y's connections are added to x's connections.
  arr[y].first = arr[x].first;  // y's root is now x's root.
  arr[y].second = 0 // y's connections are now dissolved.
}
//------------------------------------------------------------------------------
int main()
{
  cout << "Enter the total number of members in the arr : ";
  cin >> n;
  cout << "Enter the number of operations to be performed (q) : ";
  int q;  // queries.
  cin >> q;
  int cycle = 0; // cyclic counter.
  while(q--)
  {
      arr.push_back(make_pair(0,0)); // occupying 0 index(working on a 1-based index)
      for(int i=1; i<=n; i++) arr.push_back(make_pair(i,1)); // initialzing the DS with disjoint values from 1 to n.

      cout << "Enter the values of the query : ";
      int a,b;
      cin >> a >> b;
      if(arr[a].first != a) a = findRoot(a); // assign a the value of its root element if not already root.
      if(arr[b].first != b) b = findRoot(b); // assign b the value of its root element if not already root.

      //operations
      if(arr[a].first == arr[b].first){ // if the root of the vertices are the same.
        cycle++;  // there exists a cycle.
        continue; // skip this query.
      }
      //----------- Ranked Union ----------------------------------------------
      if(arr[a].second > arr[b].second) Union(a,b); // if 'a' has more connections than 'b', 'B' IS MERGED TO 'A'
      else if(arr[a].second < arr[b].second) Union(b,a); // if 'b' has more connections than 'a', 'A' is MERGED TO 'B'
      else if(arr[a].second == arr[b].second) // if 'a' and 'b' have equal number of connections then it can be merged either way.
      { // .....but for the sake of some form of structure...
        if(arr[a].first < arr[b].first) Union(a,b); // if the value of the root(a) is smaller than root(b), 'B' is merged to 'A'.
        else if(arr[a].first > arr[b].first) Union(b,a); // .. you get the idea.
      }
      //-------------- End of Ranked Union -------------------------------------
      cout << "Root of " << a << " : " << arr[a].first << "\n";
      cout << "vertiecs connected to " << a << " : " << arr[a].second << "\n";
      cout << "Root of " << b << " : " << arr[b].first << "\n";
      cout << "vertiecs connected to " << b << " : " << arr[b].second << "\n";
      cout << "Number of Cycles in the graph : " << cycle;
  }
  return 0;
}

//-------------------------- PROGRAM 2 (practical) ----------------------------
#include <bits/stdc++.h>
using namespace std;
//-------------------------- GLOBAL VARIABLES ----------------------------------
int n; // number of vertices in the graph.
vector<int> root; // Data structure to store graph information.
vector<int> conn;
//------------------------------------------------------------------------------

//------------ Function to Find the root of the selected vertix. ---------------
int findRoot(int x)
{
  while(x != root[x])
  {
    root[x] = root[root[x]]; // optimization
    x = root[x];
  }
  return x;
}
//------------------------------------------------------------------------------

//---------------------- Performing union of 2 roots ---------------------------
void Union(int x, int y){
  conn[x] += conn[y];
  root[y] = root[x];
  conn[y] = 0;
}
//------------------------------------------------------------------------------
int main()
{
  cout << "Enter the total number of members in the arr : ";
  cin >> n;
  cout << "Enter the number of operations to be performed (q) : ";
  int q;  // queries.
  cin >> q;
  int cycle = 0; // cyclic counter.
  root.push_back(0);
  conn.push_back(0);
  for(int i=1; i<=n; i++)
  {
    root.push_back(i);
    conn.push_back(1);
  }
  while(q--)
  {
      cout << "Enter the values of the query : ";
      int a,b;
      cin >> a >> b;
      if(root[a] != a) a = findRoot(a);
      if(root[b] != b) b = findRoot(b);

      //operations
      if(root[a] == root[b]){
        cycle++;
        continue;
      }
      if(conn[a] > conn[b]) Union(a,b);
      else if(conn[a] < conn[b]) Union(b,a);
      else if(conn[a] == conn[b])
      {
        if(root[a] < root[b]) Union(a,b);
        else if(root[a] > root[b]) Union(b,a);
      }
      display(); // display function (Define however you feel like it)
  }
  return 0;
}
