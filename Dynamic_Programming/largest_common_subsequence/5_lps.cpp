/*
  ------------------------------- Problem Statement ----------------------------
  Longest Palindromic Subsequence :
  Given a string of 'n' length find the longest Subsequence that forms a palindrome.

  eg :
  string : Ashish
  palindromic Subsequence :
  - shs   - hsh   - hih   - sis

  LPS : 3

  ------------------------------ Solving Approach ------------------------------

    LPS = lcs(string , string.rev)

    Reason :
    Palindrome : string = string.rev

*/

#include <bits/stdc++.h>
using namespace std;
int dp[2000][2000];
lcs(string s1, string s2, int n, int m)
{
  if(dp[n][m] != -1) return dp[n][m];
  if(n == 0 || m == 0) return dp[n][m] = 0;
  if(s1[n-1] == s2[m-1]) dp[n][m] = 1 + lcs(s1, s2, n-1, m-1);
  else dp[n][m] = max(lcs(s1, s2, n-1, m), lcs(s1, s2, n, m-1));
  return dp[n][m];
}
int main()
{
  string s1;
  cin >> s1;
  string s2 = s1;
  reverse(s2.begin(), s2.end());
  int n = s1.length();
  cout << lcs(s1,s2,n,n);
  return 0;
}
