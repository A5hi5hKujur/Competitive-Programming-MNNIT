/*
  ------------------------------ Problem Statement -----------------------------

  Given 2 strings find if Subsequence A exists in string B.
  eg :
  A : Elg
  B : TYEGlsdg

  Output : True
  -------------------------------- Solving Approach  ---------------------------

  1. Find the lcs between A and B string.
  2. If lcs = A.length(), we say that the Subsequence A exists in string B.

*/
#include <bits/stdc++.h>
using namespace std;
int dp[2000][2000];
int lcs(string s1, string s2, int n, int m)
{
  if(dp[n][m] != -1) return dp[n][m];

  if(n == 0 || m == 0) return dp[n][m] = 0;

  if(s1[n-1] == s2[m-1]) dp[n][m] = lcs(s1, s2, n-1, m-1);
  else dp[n][m] = max(lcs(s1, s2, n-1, m), lcs(s1, s2, n, m-1));
  return dp[n][m];
}
int main()
{
  string s1, s2;
  cin >> s1 >> s2;
  int n = s1.length();
  int m = s2.length();
  if(n == lcs(s1,s2,n,m)) cout << "MATCH";
  else cout << "NO MATCH";
  return 0;
}
