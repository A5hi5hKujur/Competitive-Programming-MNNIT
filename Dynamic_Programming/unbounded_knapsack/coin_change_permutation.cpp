/*
determine the number of ways of making change for a particular number of units using the given types of coins
- There can be upto 50 differet types of coins.
- The coins can differ from 1 unit to 50 units.
- The amount to be made should be no more than 250 units

Solution :
State 1 : reduce the array by 1 along with fixed amount.
State 2 : reduce the amount by the largest element from the array with fixed size array.
Ans = State 1 + State 2.

Don't forget to eliminate the overlapping subproblems using memoization,
or your solution will time out.
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll dp[52][260];  // Global DP.
ll coin(ll arr[],ll amount,ll number_of_coins)
{
    // BASE CASES
    if(amount == 0) return 1;     // When you've used a set of coins to reduce the amount to zero.
    if(number_of_coins <= 0 && amount > 0) return 0; // When you have no more coins left to reduce the amount.
    if(amount < 0) return 0;  // When you cannot reduce the amount without underflow.

    // DP : if the cell is not occupied, reduce the search range of the recursive calls and save the result in the DP.
    if(dp[number_of_coins][amount] == -1)
      dp[number_of_coins][amount] = coin(arr, amount, number_of_coins - 1) + coin(arr,amount - arr[number_of_coins - 1],number_of_coins);
    return dp[number_of_coins][amount];
}
// arr : contains the coins of different denotions.
int main()
{
    // Inputs
    ll k,n;
    cin >> k >> n;
    ll arr[n];
    for(ll i=0; i<n; i++) cin >> arr[i]; // coin denotions
    // Initializing DP
    for(int i=0; i<52; i++)
        for(int j=0; j<260; j++) dp[i][j] = -1;
    cout << coin(arr, k,n);
    return 0;
}
