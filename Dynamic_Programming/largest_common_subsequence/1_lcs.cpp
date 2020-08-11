/*
  ---------------------------- Problem Statement -------------------------------

  Given 2 strings (or arrays), find the length of the largest common subsequence,
  from the 2 strings.

  subsequence : A set of charecters not neccessarilly occuring consequtively, but
                in the same order of occurance.

  substrings : A set of CONTINEOUS charecters and frequency.

  Example :
    String 1 : ashish
    String 2 : hsihsa

    Common subsequences :
      - a       - sis     - shs
      - sh      - his

    length of LCS : 3.

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
                /                           \
              /                              \                              Shorten the length of both string1
lcs(string1, string2, n-1, m)       lcs(string1, string2, n, m-1)            and string2 and then compare the
                                                                            last charecters in the next recursive
shorten the length of string1       shorten the length of string2           call.
and then compare the last           and then compare the last charecters
charecters in the next recursive    in the next recursive call.
call.


*/

#include <bits/stdc++.h>
using namespace std;
//----------------------------- Memoization ------------------------------------
dp[2000][2000];
int lcs(string string1, string string2, int n, int m)
{
  if(dp[n][m] != -1) return dp[n][m];

  // Base Case :
  if(n == 0 || m == 0) return dp[n][m] = 0;

  // Choice Diagram :
  if(string1[n-1] == string2[m-1]) return dp[n][m] = 1 + lcs(string1, string2, n-1, m-1);
  else return dp[n][m] = max(lcs(string1, string2, n-1, m), lcs(string1, string2, n, m-1));
}
//------------------------------------------------------------------------------
int main()
{
  for(int i=0; i<2000; i++)
  for(int j=0; j<2000; j++) dp[i][j] = -1;

  string string1, string2;
  cout << "Enter the 2 strings you want to compare : ";
  cin >> string1 >> string2;
  int n = string1.length();
  int m = string2.length();
  cout << "The length of the LCS : " << lcs(string1, string2, n, m);
  return 0;
}

//--------------------- ITERATIVE DP + PRINT LCS ---------------------------------

int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.length();
        int n2 = text2.length();

        int dp[n1+1][n2+1];
        for(int i=0; i<=n1; i++)
            for(int j=0; j<=n2; j++)
                if(i == 0 || j == 0)
                    dp[i][j] = 0;

        for(int i=1; i<=n1; i++)
        {
            for(int j=1; j<=n2; j++)
            {
                if(text1[i-1] == text2[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        int count = dp[n1][n2];     // count of lcs stored here.

        char lcs[count+1];          // lcs letters to be stored here.
        lcs[count] = '\0';          // +1 extra for end of charecters.
        int i = n1, j = n2, index = count - 1;
        while(i > 0 || j > 0)       // while both the strings are not exhausted
        {
          if(text1[i-1] == text2[j-1])  // if the charecters match from the back
          {
            lcs[count - 1] = text1[i-1];  // store in the char array
            i--;                         // decrement both match.
            j--;
            index++;
          }
          else{                         // if the charectes are a mismatch
            if(dp[i-1][j] > dp[i][j-1])  // compare values of L[i-1][j] and L[i][j-1] and go in direction of greater value.
              i--;
            else
              j--;
          }
        }
    }
