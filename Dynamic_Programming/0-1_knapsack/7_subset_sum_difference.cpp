/*
------------------------------ Problem Statement -------------------------------
  Given an array of 'n' numbers count the number subset pairs of with a given
  difference (d).

  i.e :                  Given array(size n)
                          /             \
                        /                \
            Subset 1, Sum1     -    Subset 2, Sum 2   =   given difference (d)

----------------------------- Solving Approach ---------------------------------

  1. Sum1 + Sum2 = Total sum.       number theory
  2. Sum1 - Sum2 = diff.            need to find.

  Combining 1 and 2 :
  Sum1 + Sum1 = Total sum + dif   OR   2 x Sum1 = Total Sum + diff

              ------>  Sum1 = (Total sum + diff) / 2   <-----

  Which means that in order to find the subset sum difference = d, we need to
  find occurance of sum1 = (total sum + diff)/2
  The problem gets converted to counting subset sum problem.
 */
 #include <bits/stdc++.h>
 using namespace std;
 int dp[2000][2000];
 int subset(int arr[], int n, int find)
 {
   if(dp[n][sum] != -1) return dp[n][find];

   if(find == 0) return dp[n][find] = 1;
   if(n == 0 && find > 0) return dp[n][find] = 0;

   if(arr[n-1] > find)  dp[n][find] = subset(arr, n-1, find);
   else dp[n][find] = subset(arr, n-1, find - arr[n-1]) + subset(arr, n-1, find);
   return dp[n][find];
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

   int diff;
   cout << "Enter the difference to be formed : ";
   cin >> diff;

   int find = (diff + sum) / 2; // Number Theory logic
   int count = subset(arr, n, find);  // Same as count subset sum
   if(count) cout << "Number of subset pair sum of difference  " << diff << " is : " << count;
   else cout << "No subset pair sum exists of difference " << diff;
   return 0;
 }
