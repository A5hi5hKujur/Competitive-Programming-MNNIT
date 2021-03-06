/*
  ------------------------------ Problem Statement -----------------------------

  Given an array of unsorted numbers find if there exists a subset of the array,
  comprised of the elements of the array, that form a sum "k".

  ------------------------------- Solving Approach -----------------------------

  1. Constants and variables :
    constants : inputted array.
    variables : number of elements in array, given sum (k).

  2. base case : Smallest possible VALID input :
    - if no. of elements = 0 && sum to be formed > 0 : no subset can be formed, return false.
    - if no. of elements >= 0 && sum to be formed = 0 : 1 empty subset {} can be formed, return true.

  3. Choice diagram : (inclusion starts from n-1th index : 0-based index)

              if(picked element value < sum) -------------- else ------- Dont include number
                /                       \                              subset(arr, n-1, sum)
              /                          \
    Include number                      Dont include number
subset(arr, n-1, sum - arr[n-1])       subset(arr, n-1, sum)
  ------------------------------------------------------------------------------
*/
#include <bits/stdc++.h>
using namespace std;

bool dp[2000][2000]; // Global DP matrix.
/*
Functional Description(at the time of call) :
returns : either true or false, depending upon if the remaining 'n' elements can form a subset to form 'sum'.
parameters :
  1. arr : list of numbers (unsorted)
  2. n : length of array.
  3. sum : sum to be formed at that point in recursive function call.
*/
bool subset(int arr, int n, int sum)
{
  if(dp[n][sum] == -1)
  {
    // Base case :
    if(n == 0 && sum > 0) dp[n][sum] =  false;   // 1. No elements left to form subset while sum to be calculated.
    if(sum == 0) dp[n][sum] =  true;             // 2. No sum to be calculated whatever.

    // Choice Diagram :
    if(arr[n-1] <= sum)                   // number picked is smaller than sum to be calculated.
      dp[n][sum] = subset(arr, n-1, sum - arr[n-1]) || subset(arr, n-1, sum);
                  // either pick the number        or   dont pick the number.
    else                                // number picked is bigger than the sum to be calculated.
      dp[n][sum] = subset(arr, n-1, sum); // do not pick the number and move onto the next number.
  }
  return dp[n][sum];  // store and return the value from the dp.
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

  if(subset(arr, n, sum)) cout << "It is possible to form a subset";
  else cout << "It is not possible";
  return 0;
}


//-------------------------------------- Iterative Method -----------------------------------------------
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Input Stream
    int n, sum;
    cin >> n >> sum;
    int arr[n];
    for(int i=0; i<n; i++)
        cin >> arr[i];

    // Initialize base Case : Can be optimized to O(n) but the overall complexity is O(n*sum)
    bool dp[n+1][sum+1];
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=sum; j++)
        {
            if(i == 0 && j != 0)  // when items are exhausted and the sum is not satisfied.
                dp[i][j] = false;
            if(j == 0)            // when the sum is satisfied.
                dp[i][j] = true;
        }
    }

    for(int i=1; i<=n; i++)       // iterate all items
    {
        for(int j=1; j<=sum; j++)   // iterate the sums
        {
            if(arr[i-1] > j)        // if item on the (i-1)th index of arr is greater than the sum to satisfy (j), item cannot be included.
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j - arr[i-1]] || dp[i-1][j];     // to include or not to incude.
        }
    }
    if(dp[n][sum])
        cout << "Subset Sum exists";
    else
        cout << "Subset Sum doesnt exist";
    return 0;
}
