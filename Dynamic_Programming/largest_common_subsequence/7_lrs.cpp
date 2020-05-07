/*
  ------------------------------ Problem Statement -----------------------------

  Longest Repeating Subsequence :
  Given a string, find the length of the larget repeating Subsequence without
  repeating the same elements to form another Subsequence.

  eg :
  string : geeksforgeek contains 2 repeation of "geek" of length 4,
  therefor LRS = 4.

  ------------------------------ Solving Approach ------------------------------

  - We find the lcs of a string with itself.
  - Since the repeated Subsequence cannot be formed by repeated charecters we
    cannot consider charecters with same index position. (charecters with same
    index position suggest that they've already been considered)
  - If there are no repeating Subsequence the output will be 0.
*/
#include <bits/stdc++.h>
using namespace std;
int dp[2000][2000];
lcs(string s1, string s2, int n, int m)
{
  if(dp[n][m] != -1) return dp[n][m];
  if(n == 0 || m == 0) return dp[n][m] = 0;
  if(s1[n-1] == s2[m-1] && n != m) dp[n][m] = 1 + lcs(s1, s2, n-1, m-1);
  else dp[n][m] = max(lcs(s1, s2, n-1, m), lcs(s1, s2, n, m-1));
  return dp[n][m];
}
int main()
{
  string s1;
  cin >> s1;
  string s2 = s1;
  int n = s1.length();
  cout << lcs(s1,s1,n,n);
  return 0;
}
