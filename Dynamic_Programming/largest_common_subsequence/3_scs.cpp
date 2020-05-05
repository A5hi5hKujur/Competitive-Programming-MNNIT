/*
  ----------------------------- Problem Statement ------------------------------

  Given 2 strings, find the shortest common supersequece containing, charecters from
  both string in the same subsequence.

  Example :
  string 1 : geeksforgeek     Largest common supersequece : geeksforgeekforgot : 18.
  string 2 : forget           Shortest common supersequece : geeksforgeekot : 14.

  shortest common supersequece = length of both strings - length of largest common subsequence.

  Note : We simply cannot subtract length of common letters since we have to consider the
         order of occurance of those letters.

------------------------------ Solving Approach --------------------------------

  - Calculate length of the LCS.
  - Subtract that length with the length of both strings.

--------------------------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;
int dp[2000][2000];
int lcs(string s1, string s2, int n, int m)
{
    if(dp[n][m] != -1) return dp[n][m];

    // base case
    if(n == 0 || m == 0) return dp[n][m] = 0;

    // choice diagram
    if(s1[n-1] == s2[m-1]) return dp[n][m] = 1 + lcs(s1, s2, n-1, m-1);
    else return dp[n][m] = max(lcs(s1, s2, n-1, m), lcs(s1, s2, n, m-1));
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
  cout << "The shortest common supersequece is of length : " << n + m - l;
  return 0;
}
