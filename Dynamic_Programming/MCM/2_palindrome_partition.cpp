/*-------------------------- Problem Statement ---------------------------------
Find the minimum partion in a string that would make every substring in the
partition a palindrome.

Eg :    String  : KUJUR
        min palindrome partition : 3  K | UJU | R

//---------------------------- Approach ----------------------------------------
Step 1 :
 Find starting range i and j.
- since a single charecter is a valid palindrome i starts from index 0.
- since the entire string can be a palindrome j ends from index n-1.

Step 2 :
  Base conditions :
1. When the range is exhausted no partition can be done,return no of partition = 0;
2. When there is a single charecter in a range, it is already a palindrome return partition = 0;
3. When the string within the range is already a palindrome return number of partition = 0;

Step 3 :
  Determine Loop Partitions (Partition Scheme) :
  loop(k = i to k = j-1)  k cannot go till j because then there will be no room for partition 2 (out of bound)
  partition 1 : i to k
  partition 2 : k+1 to j

Step 4 :
  Deterine Temporary answer :
  no. of palindromes in partition 1 + no. of palindromes in partition 2 + 1 partition between these 2 partition.
  Final Answer : min(Temporary Answer, Final Answer)
--------------------------------------------------------------------------------------------------------
*/
#include <bits/stdc++.h>
#define N 2000
using namespace std;
int dp[N][N];
bool isPalindrome(string s, int i, int j)
{
  while(i<=j)
  {
      if(s.at(i++) != s.at(j--))
        return false;
  }
  return true;
}
int palindromePartition(string s, int i, int j)
{
  if(dp[i][j] != -1)    // already in dp
    return dp[i][j];

  if(i >= j || isPalindrome(s,i,j))   // STEP 2 : base cases
    return dp[i][j] = 0;

  int mn = INT_MAX;
  for(int k = i; k < j-1; k++) // STEP 3
  {
    int partition1, partition2;
    if(dp[k][j] != -1) partition1 = dp[i][k];
    else partition1 = palindromePartition(s, i, k);
    if(dp[k+1][j] != -1) partition2 = dp[k+1][j];
    else partition2 = palindromePartition(s, k+1, j);
    int temp = partition1 + 1 + partition2;     // STEP 4
    mn = min(temp, mn);
  }
  return dp[i][j] = mn;
}
int main()
{
  fill(*dp, *dp + N*N, -1);
  string s;
  cin >> s;
  cout << "Minimum Partition : " << palindromePartition(s, 0, s.length()-1);   // STEP 1 : dimensions i : 1  to j : n-1
  return 0;
}
