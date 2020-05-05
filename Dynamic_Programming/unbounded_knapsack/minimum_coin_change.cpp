/*
  ------------------------------ Problem Statement -----------------------------

  Given an array of size 'n' of different denominations of coins (available in unlimited supply),
  and an 'amount' to be formed by these denominations. Find out the minimium
  number of coins required to form the given amount from the given coins.

  ------------------------------ Solivng Approach ------------------------------

  1. Constants and Variables :
    - Constants : coin array.
    - Variables : length of array, amount to be formed.

  2. Base Case :
    - When you run out of coins, but the amount is not fullfilled : These coin should no be picked.
      if(n == 0 && amount > 0) return INT_MAX; -> returning a maxium possible amount ensures that this will not be picked in a minimization problem.
    - When your amount gets fullfilled, irrespective of the coins you've used : addition of 1 coin fullfilled the amount
      if(amount == 0) return 1;

  3. Choice Diagram :

                        if(The picked coin  <= amount) ------> else ----> Discard the coin.
                          /                       \                       coin(arr, n-1, amount)
                        /                          \
      Include the coin and count it.            Discard the coin
  coin(arr, n, amount - arr[n-1]) + 1         coin(arr, n-1, amount)
                        \                          /
                         \                       /
            Choose the option that yields the minimum no. of coin.
  */

  #include <bits/stdc++.h>
  using namespace std;
  int dp[2000][2000];
  int coin(int arr[], int n, int amount)
  {
      if(dp[n][amount] != -1) return dp[n][amount];

      if(n == 0 && amount > 0) return dp[n][amount] = INT_MAX - 1;
      if(amount == 0) return dp[n][amount] = 0;

      if(amount < arr[n-1]) dp[n][amount] = coin(arr, n-1, amount);
      else dp[n][amount] = min(1 + coin(arr, n, amount - arr[n-1]), coin(arr, n-1, amount));
      return dp[n][amount];
  }
  int main()
  {
    for(int i=0; i<2000; i++)
    for(int j=0; j<2000; j++) dp[i][j] = -1;

    int n;
    cout << "Enter the number of coin denominations available : ";
    cin >> n;

    int arr[n];
    cout << "Enter the denominations : \n";
    for(int i=0; i<n; i++) cin >> arr[i] ;

    int amount;
    cout << "Enter the amount : ";
    cin >> amount;

    cout << "The minimum coins required to form an amount " << amount << " is : " << coin(arr, n, amount);
    return 0;
   }
