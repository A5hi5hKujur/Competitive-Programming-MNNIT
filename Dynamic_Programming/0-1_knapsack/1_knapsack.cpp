
/*
In the following recursion tree, K() refers to knap().  The two
parameters indicated in the following recursion tree are n and W.
The recursion tree is for following sample inputs.
weight[] = {1, 1, 1}, knap_cap = 2, value[] = {10, 20, 30}, items = 3

                       K(3, 2)         ---------> K(items, knap_cap)
                   /            \
                 /                \
            K(2,2)                  K(2,1)
          /       \                  /    \
        /           \              /        \
       K(1,2)      K(1,1)        K(1,1)     K(1,0)
       /  \         /   \          /   \
     /      \     /       \      /       \
K(0,2)  K(0,1)  K(0,1)  K(0,0)  K(0,1)   K(0,0) --> base case 1

for any such function call where there would have been a negetive value for knap_cap,i.e:
          K(2,-2) --> base case 2, which entails that whatever "item" generated these parameters need to be discarded.

------------------------------------- Solving Approach -------------------------------------------------------
1. Constants and variables :
  constants : weight array, value array.
  variables : number of items left, knapsack capacity left.

2. base case : Smallest possible VALID input :
   - if knapsack capacity = 0 : no profit can be made, since no items can be included.
   - if number of items = 0 : no profit can be made, since there are no items left to add.
   therefor, in both the cases return profit = 0.

3. Choice diagram : (inclusion starts from n-1th index : 0-based index)

                    if(picked element weight < knapsack capacity) ------- else ------ Dont include item.
                              /                   \                                   knap(wt, val, w, n-1)
                            /                      \
                    Include item                Dont include item
  knap(wt, val, (w - wt[n-1]), n-1)         knap(wt, val, w, n-1)

Time Complexity :
  Normal Recursion : O(2 ^ N) where N = Number of items
  Memoized Recursion / Matrix DP : O(N x W) where N = Number of items and W = Weight                 
---------------------------------------------------------------------------------------------------------------
*/
#include <bits/stdc++.h>
using namespace std;

int dp[2000][2000]; // Global DP matrix
/*
  Function Description(at the time of call) :
    returns : Total value of all the items you can fit in the knapsack within its capacity.
    parameters :
      1. items : total number of items left to pick.
      2. knap_cap : total capacity of the knapsack at that point.
      3. value[] : array containing the values of all the items. (constant)
      4. weight[] : array containing the weight of all the items. (constant)
*/
int knap(int items, int knap_cap, int value[], int weight[])
{
    if(dp[items][knap_cap] == -1)
    {
        if(items == 0 || knap_cap == 0) // Base case 1 : when there are either no items left or no room left in the knapsack.
          dp[items][knap_cap] = 0;

        else if(weight[items - 1] > knap_cap) // Base case 2 : when keeping the nth item in the knapsack will result in overflow of the knapsack.
            dp[items][knap_cap] = knap(items-1, knap_cap, value, weight); // discard this item for the next function call.
        else
        {
            int left_branch = knap(items - 1, knap_cap, value, weight); // discard this item branch for the next function call.
            int right_branch = knap(items - 1, knap_cap - weight[items-1], value, weight); // include the item in the knapsack and update the weight for the next function call.
            dp[items][knap_cap] = max( left_branch, right_branch + value[items-1]); // "+ value[items-1]" : since we chose to include the item obtained in the right branch we also include the value of that item.
            // The maximum value obtained from both branch is stored as the maximum value for this function call.
        }
    }
    return dp[items][knap_cap]; // Whatever value is being returned here is the maximum that this branch can return.
}

//---------------------------------- Iterative DP --------------------------------------------------------------------------------------------------
int knap(int items, int knap_cap, int value[], int weight[])
{
  int dp[items + 1][knap_cap + 1];
  // Initialize DP matrix with base case.
  for(int i=0; i<=items; i++) dp[i][0];
  for(int i=0; i<=knap_cap; i++) dp[0][i];

  for(int i = 1; i<=items; i++)
  {
    for(int j = 1; j<=knap_cap; j++)
    {
      if(weight[i - 1] > j)
          dp[i][j] = dp[i-1][j];
      else
          dp[i][j] = max(dp[i-1][j], dp[i-1][j - weight[i-1]] + value[]);
    }
  }
  return dp[items][knap_cap];
}
//--------------------------------------------------------------------------------------------------------------------------------------------------

int main()
{
    // Populating the DP matrix.
    for(int i=0; i<2000; i++)
    for(int j=0; j<2000; j++) dp[i][j] = -1;

    //input total number of items and the total capacity of the "Knap-sack"
    cout << "Enter the NUMBER OF ITEMS to be collected and the CAPACITY of the knapsack : ";
    int items, knap_cap;
    cin >> items >> knap_cap;

    // Populating weight and value arrays with data.
    int value[items], weight[items];
    for(int i=0; i<items; i++)
    {
        cout << "Enter the value of item " << (i+1) <<" : ";
        cin >> value[i];

        cout << "Enter the weight of item " << (i+1) <<" : ";
        cin >> weight[i];
    }

    cout << "Total value of items you can fit in the knapsack : " << knap(items, knap_cap, value, weight);
    return 0;
}
