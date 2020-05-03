/*
------------------------------ Problem Statement -----------------------------

MINIMUM ABSOLUTE DIFFERENCE OF SUM OF 2 array partitions :
  Given an array of size 'n' you are to create 2 subsets of the array whose sums
  will return the minimim difference.

                              Given array
                            /            \
                          /               \
                    Subset 1             Subset 2
      'k' elements (0<= k <= n)    'l' elements (0<= l <= n)
                         \                /
                          \             /
                        min(sum 1 - sum 2)

----------------------------- Solving Approach ---------------------------------

  NUMBER THEORY :
    let us assume sum1 to be the sum obtained by adding 'n' array elements.
    let us assume sum2 to be the sum obtained by adding 0 array elements (sum2 = 0)

    1. The maximum sum that can be obtained is max_sum = (sum1 - sum2).
       i.e, no sum within the sum1, sum2 range would be greater than max_sum.

    2. if sum1 > sum2, then :   sum2 = max_sum - sum1
                      since :   (max_sum = sum1 + sum2)

CONSTANTS / VARIABLES :
  constants : array.
  variables : no. of elements , sum

  here, 'sum' : sum of all elements

Procedure :
  - Fill up the DP matrix with all the possible sums that can be formed by all
    the variations of 'sum' that can be formed by n numbers, within the range
    of total sum.
    (complete nth row of the matrix.)
  - Use subset sum method to populate matrix.
  - Pick the minimum sum variation of the nth row.
*/

#include <bits/stdc++.h>
using namespace std;
int dp[2000][2000];
int partitionDiff(int arr[], int n, int sum)  // using subset sum method to find set of
{                                        // all the acceptable sums within the total sum range
  if(dp[n][sum] != -1) return dp[n][sum];

  if(sum == 0) return dp[n][sum] = 1; // 1 : true, i.e, sum is possible.
  if(n == 0 && sum > 0) return dp[n][sum] = 0; // 0 : false, i.e, sum is not possible.

  if(sum < arr[n-1]) dp[n][sum] = partitionDiff(arr, n-1, sum);
  else dp[n][sum] = partitionDiff(arr, n-1, sum - arr[n-1]) || partitionDiff(arr, n-1, sum);
  return dp[n][sum];
}
int main()
{
  for(int i=0; i<2000; i++)
  for(int j=0; j<2000; j++) dp[i][j] = -1;

  cout << "Enter the length of the array : ";
  int n; cin >> n;
  int arr[n];
  int sum = 0;
  cout << "Enter " << n << " elements in the array : \n";
  for(int i=0; i<n; i++)
  {
      cin >> arr[i];
      sum += arr[i];
  }
  partitionDiff(arr, n, sum); // dp matrix get filled up with what sums are acceptable for all variations of 'n'.
  vector<int> sum_arr;  // list of acceptable sum values for n elements.
  for(int i=0; i<=sum/2; i++) // populate only the first half of the last row.
    if(dp[n][i]) sum_arr.push_back(i);

  int mn = INT_MAX;
  for(int i=0; i<sum_arr.size(); i++)
    // comparing sum difference with minimum value and updating at every iteration.
    mn = min(mn, sum - (2 * sum_arr[i])); //NUMBER THEORY LOGIC : division of array w.r.t sum.
                                          // total sum = sum1 + sum2. where sum1 < sum2
                                          // we have to perform (sum2 - sum1), but sum2 can be found from sum1 : total_sum - sum1.
                                          // total_sum - sum1 - sum1, i.e:
                                          // total_sum - (2xsum1)

  cout << "MINIMUM SUM PARTITION DIFFERENCE : " << mn;  
  return 0;
}
