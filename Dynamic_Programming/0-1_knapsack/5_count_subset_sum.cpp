/*
--------------------------- Problem Statement ----------------------------------
Given an array of 'n' size, Count the number of array subset that satisfy the
given sum.

------------------------------- Approach ---------------------------------------

1. Constants / Variables :
  - Constants : arr[]
  - Variables : no. of array size.
                sum to be formed.

2. base case :
  - When there are no arrays to satisfy the sum. (n == 0 && sum > 0) return 0
  - When there are no sums to satisfy (n>=0 && sum == 0) return 1;

3. Choice diagram : (0-index)

                    if(picked element < sum) ------------> else -------> Dont pick Element
                      /                   \                              count(arr, n-1, sum)
                    /                      \
          Pick the element.             Dont pick element.
  count(arr, n-1, sum - arr[n-1])     count(arr, n-1, sum)

*/
#include <bits/stdc++.h>
using namespace std;
int dp[2000][2000];
int countSubset(int arr[], int n, int sum)
{
  if(dp[n][sum] == -1)
  {
    // base case :
    if(n == 0 && sum > 0) dp[n][sum] =  0;
    if(n >= 0 && sum == 0) dp[n][sum] = 1;

    // choice diagram :
    if(arr[n-1] <= sum)
      dp[n][sum] = countSubset(arr, n-1, sum - arr[n-1]) + countSubset(arr, n-1, sum);
    else
      dp[n][sum] = countSubset(arr, n-1, sum);
  }
  return dp[n][sum];
}
int main()
{
  for(int i=0; i<2000; i++)
  for(int j=0; j<2000; j++) dp[i][j] = -1;

  cout << "Enter the length of the array : ";
  int n; cin >> n;
  int arr[n];
  cout << "Enter " << n << " elements in the array : \n";
  for(int i=0; i<n; i++) cin >> arr[i];

  int sum;
  cout << "Enter the sum to be formed : ";
  cin >> sum;

  int count = subset(arr, n, sum);
  if(count) cout << "Number of subsets satisfying the sum " << sum << " is : " << count;
  else cout << "It is not possible to satisfy the sum";
  return 0;
}
