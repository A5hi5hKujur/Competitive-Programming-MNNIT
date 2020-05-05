/*
  --------------------------- Probem Statement ---------------------------------

  Given a string 'A' and 'B', you need to perform minimum operations to convert
  string A to string B.

  operations include :
  - Deletion (from any location)
  - Insertion (to any location)

  eg :                      operations :
    string A : heap          1. delete 'a' form the 2nd index.
    string B : help          2. insert 'l' on the 2nd index.

                             Total operations : 2.

--------------------------- Solving Approach -----------------------------------

- Lcs(string A, string B)
1. number of deletions = length of string A - Lcs.  (remove extra charecters)
2. number of insertions = length of string B - Lcs. (add the required charecters)

total number of operations = 1 + 2
  ------------------------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;
int dp[2000][2000];
int lcs(string s1, string s2, int n, int m)
{
    if(dp[n][m] != -1) return dp[n][m];

    if( n==0 || m ==0) return dp[n][m] = 0;

    if(s1[n-1] == s2[m-1]) return 1 + lcs(s1, s2, n-1, m-1);
    else return max(lcs(s1, s2, n, m-1),lcs(s1, s2, n-1, m));
}
int main()
{
  for(int i=0; i<2000; i++)
  for(int j=0; j<2000; j++) dp[i][j] = -1;

  cout << "Enter the 2 strings : ";
  string s1,s2;
  cin >> s1 >> s2;
  int n = s1.length();
  int m = s2.length();
  int l = lcs(s1, s2, n, m);
  cout << "The minimum number of operations required to convert " << s1 << " to " << s2 << " is : "  << (n - l) + (m - l);
  return 0;
}
