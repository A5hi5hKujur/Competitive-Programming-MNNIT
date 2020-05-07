/*
  --------------------------------- Problem Statement --------------------------

  Given a string, find the minimum number of deletions in the string that can
  yield the largest palindromic Subsequence from the inputted string.

  Example :
    String : agbcba
    palindromic Subsequence :
    - bcb (3 deletion)      - bb (4 deletion)       - abcba (1 deletion)
                                                          answer

 ---------------------------- Solve Approach -----------------------------------

 We observe that the creation of largest palindromic Substring required the least
amount of deletions.

therefore, min_deletions = string length - lcs.
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
  cout << n - lcs(s1,s2,n,n);
  return 0;
}
