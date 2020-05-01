/*
  THIS PROBLEM CAN ONLY BE SOLVED BY THE ITERATIVE METHOD with single dimension array.

  OPTIMIZED SPACE COMPLEXITY 0-1 KNAPSACK ITERATIVE :

  A given 0-1 knapsack problem where :
  - Number of items can be upto : 0 - 500.
  - Knapsack capacity can be upto : 20000000

  Clearly a dp of size dp[500][20000000] is not feasible. And there is NO WAY to solve this problem by memoization since memoization
  only works with smaller constraints. (something like dp[200][20000]).
  - We have to convert the recursive approach into an iterative one.
  - Instead of building a whole matrix of dp[500][20000000] we only work with 2 rows :
    1. To store all sub-problem solutions of the previous row.
    2. To store all sub-problem solutions of the next row. (to be calculated by the previous row)

  Approach :
  Time Complexity :  O(n x w) where, n : no. of items.
                                     w : maximum knapsack capacity.
                     but since n is exponentially smaller than w, complexity != O(n^2).

  Space Complexity : O(2 x (w+1))

  1. Create 2 arrays of size w+1 : current[w+1]; previous[w+1];

  2. Run an outer loop to iterate through all the the items(n) :
      for(int i=0; i<n; i++){ .... }

  3. Run an inner loop to iterate through the current variation of the weight :
      for(int j = weight[i]; j <=w ; j++){ ... }

  4. Choices :
     - Pick the item i : choice_1 = value[i] + prev[j - weight[i]];  ---> Value of current item + value of previous item in (j - weight[i])th position.
     - Dont Pick item i : choice_2 = prev[j]; ---> Since you did not pick anything value remains the same.

  5. Optimal choice : current[j] = max(choice_1, choice_2);

  6. previous[] = current[];  ---> current row becomes previous row.

  7. Print(previous[n][w]).
*/
#include <bits/stdc++.h>
using namespace std;

int knap(int value[], int weight[], int n, int w)
{
  vector<int> current(w+1, 0);    // current row data
  vector<int> previous(w+1, 0);   // previous row data
                                  // length w+1 : to access index w.
  for(int i=0; i<n; i++)          // iterate through all sub problems of variable item length.
  {
    for(int j=weight[i]; j<=w; j++) // populate the new row based on previous row data (weight row.)
    {
      current[j] = max(previous[j], value[i] + previous[w - weight[j]]); // chose wether to include or discard item.
    }
    previous = current; // current row becomes previous.
  }
  return previous[w]; // solution of asked problem.
}
int main()
{
    int n,p;
    cin >> n >> p;
    int weight[n];   // weight
    int value[n];  // value.
    for(int i=0; i<n; i++) cin >> weight[i] >> value[i];
    cout << booty(value, weight, n, p);
    return 0;
}
