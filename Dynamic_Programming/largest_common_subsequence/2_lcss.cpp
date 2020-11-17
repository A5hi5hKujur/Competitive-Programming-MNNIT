/*
  ---------------------------- Problem Statement -------------------------------

  Given 2 strings (or arrays), find the length of the largest common sub-string,
  from the 2 strings.

  Sub-string : A set of charecters occuring consequtively, in the some order of
               occurance.

  Example :
    String 1 : ashish                   String 1 : Monster
    String 2 : hsihsa                   String 2 : Monday

    Common sub-strings :                Common sub-strings ;
      - a       - s     - h             - Mon     - Mo    - on
      - i      - s      - h

    length of LCSS : 1.                 Length of LCSS : 3

    ------------------------- Solving Approach ---------------------------------

    Constants / Variables :
      Constants : string 1, string 2.
      Variables : length of string 1, length of string 2.

    Base Case :
      - If there is no string1 left, strings cannot be compared.
          if(n == 0) return 0;      where n = length of string 1.

      - If there is no string2 left, strings cannot be compared.
          if(m == 0) return 0;      where m = length of string 2.

    Choice Diagram :

              if(string1[n-1] != string2[m-1]) ----------> else --------->  1 + lcs(string1, string2, n-1, m-1)
                              |
                             |                                              Shorten the length of both string1
                      reset count = 0                                       and string2 and then compare the
                      /             \                                       last charecters in the next recursive
lcs(string1, string2, n-1, m)       lcs(string1, string2, n, m-1)           call.

shorten the length of string1       shorten the length of string2
and then compare the last           and then compare the last charecters
charecters in the next recursive    in the next recursive call.
call.


*/

#include <bits/stdc++.h>
using namespace std;
//------------------------- Recursion + DP -------------------------------------
int ans;
int lcs(int n1, int n2, string s1, string s2, vector<vector<int>>& dp)
{
    if(dp[n1][n2] != -1) return dp[n1][n2];
    if(n1 == 0 || n2 == 0)
        return 0;

    lcs(n1, n2-1, s1, s2, dp);
    lcs(n1-1, n2, s1, s2, dp);

    if(s1[n1-1] == s2[n2-1])
    {
        dp[n1][n2] = lcs(n1-1, n2-1, s1, s2, dp) + 1;
        ans = max(ans, dp[n1][n2]);
        return dp[n1][n2];
    }
    return dp[n1][n2] = 0;
}
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
	    ans = 0;
	    int n,m;
	    cin >> n >> m;
	    string x,y;
	    cin >> x >> y;
	    vector<vector<int>> dp(n+1,vector<int>(m+1, -1));
	    lcs(n,m,x,y,dp);
	    cout << ans << "\n";
	}
	return 0;
}
//------------------------------------------------------------------------------

//--------------------------- Matrix DP ----------------------------------------
int lcs(string string1, string string2, int n, int m)
{
  int dp[n+1][m+1];
  for(int i=0; i<=n; i++)
    for(int j=0; j<=m; j++)
      if(i == 0 || j == 0)
        dp[i][j] == 0;            // base case

  int result = 0;                 // stores maximum substring length
  for(int i=1; i<=n; i++)
  {
    for(int j=1; j<=m; j++)
    {
      if(string[i-1] == string[j-1])    // when charecters match
      {
        dp[i][j] = 1 + dp[i-1][j-1];    // their previous count + 1
        result = max(result, dp[i][j]); // compare with the already obtained highest
      }
      else
        dp[i][j] = 0;                   // reset current streak to 0 when the substring chain breaks
    }
  }
  return result;                // return the final result.
}
int main()
{
  for(int i=0; i<2000; i++)
  for(int j=0; j<2000; j++) dp[i][j] = -1;

  string string1, string2;
  cout << "Enter the 2 strings you want to compare : ";
  cin >> string1 >> string2;
  int n = string1.length();
  int m = string2.length();
  cout << "The length of the LCSS : " << lcs(string1, string2, n, m);
  return 0;
}
