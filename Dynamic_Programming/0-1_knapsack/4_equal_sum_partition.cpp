/*
------------------------------ Problem Statement -------------------------------

  Given an array of size 'n' you need to find if there exists a pair of subset with equal sum.
  i.e, if the elements of an array can be split into 2 subsets both yielding an equal sum.

------------------------------ Solving Approach --------------------------------
1. Constants / Variables :
  - Constant : array -> arr[]
  - Variables : n   -> size of array.
                sum -> sum to be formed at a perticular sub-problem.

  here, we don't know what 'sum' is as of now, we are not given the sum in the question.
  We are only told to create a pair of sums from the given array elements which are equal.

  NUMBER THEORY :
    A number can only be split into 2 equal number if the number is even, because let 'x' be
    a number let 'y' be another number equal to 'x' :
          therefor, x = y and now we have 2x which by nature is even.

    Therefor we conclude that if all elements of the array are added to form an odd number,
    there can NEVER exist a pair of equal sum elements.
    eg : 22/2 can be split into 11 and 11.
         23/2 can be split into 12 and 11.

    sum = sum/2

2. Base case :
  - when there is no number to pick and no sum to be formed (n == 0 && sum == 0) : you've satisfied the sum (return true).
  - when there is no number to pick and sum to be formed (n == 0 && sum > 0) : you cannot satisfy the sum (return false).

3. Choice Diagram : (inclusion starts from n-1th index : 0-based index)

                                  if(sum is even) -----> else -----------> return false (the problem does not have a solution,
                                      /                                                   and so does the subproblem ).
                                    /
                if(picked array element < sum) ---------> else -----------> Do not pick the arr. element.
                    /                      \                                  equalSum(arr, n-1, sum)
                  /                         \
        Pick the arr. element             Do not pick the arr. element.
equalSum(arr, n-1, sum - arr[n-1])          equalSum(arr, n-1, sum)

-------------------------------------------------------------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;
bool dp[2000][2000];
bool equalSum(int arr[], int n, int sum)
{
  if(dp[n][sum] == -1)
  {
    // base case :
    if(n >= 0 && sum == 0) dp[n][sum] = true;
    if(n == 0 && sum > 0) dp[n][sum] = false;

    // choice diagram :
    if(arr[n-1] <= sum)
      dp[n][sum] = equalSum(arr, n-1, sum - arr[n-1]) || equalSum(arr, n-1, sum);
    else dp[n][sum] = equalSum(arr, n-1, sum);
  }
  return dp[n][sum];
}
void partition(int arr[], int n)
{
  int sum = 0;
  for(int i=0; i<n; i++) sum += arr[i];
  if((sum % 2) cout << "No equal sum pair exist"; // odd numbers can never be equally divided.
  else
  {
    if(equalSum(arr, n, sum/2)) cout << "Pair exists";  // knapsack capacity becomes half the sum.
    else cout << "No equal pair sum exists";
  }
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

  partition(arr, n);
  return 0;
}
