/*
--------------------------- GENERAL APPROACH -----------------------------------

  Unbounded Knapsack : A variation of knapsack where instead of limited number
  of items to process, there is an unlimited supply of items and each item can
  be processed multiple times.

  Bounded knapsack flow :

                  if(picked element fits in the bag)
                    /                           \
                  /                              \
    Put the element in the bag             Do not put the element in the bag,
    and move onto processing the           and move onto processing the next
    next element.                          element.

    knap(arr, n-1, sum - arr[n-1])         knap(arr, n-1, sum)
  (Never reprocess the picked item)       (Never reprocess the discarded item)

  Unbounded knapsack flow :

                if(picked element fits in the bag)
                 /                              \
               /                                 \
    Put the element in the bag                  Do not put the element in the bag,
    but do not move onto                        and move onto processing the next
    processing the next element.                element.

  UKnap(arr, n, sum - arr[n-1])                 UKnap(arr, n-1, sum)
(Picked item is reprocessed until discarded)   (Never reprocess the discarded item)

---------------------------- PROBLEM STATEMENT ---------------------------------

  You are given a single rod of length 'n'. an array of length 'n' containing the
  value of each cut of index length (starting from 1). Maximize the profit.

  eg :
  rod length : 8.
  array of values   : 3 4 5 8 9 12 14 14
  cut length(index) : 1 2 3 4 5 6  7  8

  Cut the rod in such a way to Maximize profit.
*/
#include <bits/stdc++.h>
using namespace std;
int dp[2000][2000];
int unbounded(int value[], int weight[], int n, int length)
{
    if(dp[n][length] != -1) return dp[n][length];
    if(n == 0 || length <= 0) return dp[n][length] = 0;

    if(length < weight[n-1]) dp[n][length] = unbounded(value, weight, n-1, length);
    else dp[n][length] = max(value[n-1] + unbounded(value,weight, n, length - weight[n-1]), unbounded(value, weight, n-1, length));
    return dp[n][length];
}
int main()
{
  for(int i=0; i<2000; i++)
  for(int j=0; j<2000; j++) dp[i][j] = -1;

  int n;
  cout << "Enter the length of the rod : ";
  cin >> n;

  int value[n];
  int weight[n];
  cout << "Enter " << n << " Prices for each length cut starting from 1 unit. : \n";
  for(int i=0; i<n; i++)
  {
      cin >> value[i];
      weight[i] = i+1;
  }
  cout << "Maximum Profit : " << unbounded(value, weight, n, n);
  return 0;
}
