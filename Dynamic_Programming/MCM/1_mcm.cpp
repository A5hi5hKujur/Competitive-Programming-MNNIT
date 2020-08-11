/*
  ----------------------- Matrix Chain Multiplication --------------------------

  Given a sequence of matrices, find the most efficient way to multiply these
  matrices together. The problem is not actually to perform the multiplications,
  but merely to decide in which order to perform the multiplications.
  Eg :
  Input Array = [10, 30, 5, 60]
  This will generate 3 matrices :
  A : 10 x 30   ;   B : 30 x 5  ;  C : 5 x 60

  Operation Variation 1 :
  (AB)C :
    (AB) = (10×30 x 30×5)
           10 x (30 x 30) x 5       resultant matrix will be (10 x 5)
           10 x 30 x 5 = 1500
    (AB)xC = 10 x 5  x 5 x 60
             10 x 5 x 60 = 3000
    Total Cost = 1500 + 3000 = 4500 operations

  Operation Variation 2 :
  A(BC) :
    (BC) = (30x5 x 5x60)
           30 x (5 x 5) 60          resultant matrix would be (30 x 60)
           30 x 5 x 60 = 18000
    A(BC) = (10x30 x 30x60)
          = 10 x (30 x 30) x 60
          = 10 x 30 x 60 = 9000
    Total Cost = 9000 + 18000 = 27000 operations

    Operation Variation 1 is cleary more optimal.

  ---------------------------- MCM Identification ------------------------------
  Any perticular probem which requires grouping of elements and processing them.
  For example in this instance :

    Input :                            A B C D
    Groupings :          (A B) (C D)    (A B C) D      A (B C D)

    Here we illustrate grouping by representing them with brackets, during the
    implimentation we use 3 variables to divide the array (elements)
  ------------------------ General Format --------------------------------------

  - This algorithm follows divide and conquer technique where the data is divided
    into two parts and then processed.

  - This method is used in problems where we need to find optimized solution by
    linear partition of input data and can be generalized into a common Format
    (different questions may have different variations of it) :

  1. The inputs : These type of questions will have a single array or string.

  2. function signature :
      int mcm(int arr, int i, int j)
      where,
        arr : input array.
        i : starting point of partition 1.  i < j (left side)
        j : ending point of partition 2.    j > i (right side)

  3. base case : stop the process when (j < i). (binary search logic)

  4. linear partition : We add a loop in the Recursive function...what ??
     This loop will help change the range of the 2 partitions.

     Scheme :
     i = 0  and j = n-1         where n : length o array/string
     for(int k = i; k < j; k++)

     Partition :
     a. mcm(arr, i, k)      b. mcm(arr, k+1, j)

     Data :
     1 2 3 4 5 6 7      partition a : 1
     i           j      partition b : 2 3 4 5 6 7
     k

     1 2 3 4 5 6 7      partition a : 1 2 3 4
     i     k     j      partition b : 5 6 7

     1 2 3 4 5 6 7      partition a : 1 2 3 4 5 6
     i         k j      partition b : 7

  5. Temporary answers : We find all possible answers in each iteration in a
     particular function call within the loop in search for the optimized answer.

        int mn = INT_MAX
        for(int k = i ; k < j ; k++)
        {
          int temp = mcm(arr, i, k) + mcm(arr, k+1, j)  // temp answer in each iteration.
          mn = min(temp, mn); // update the optimized answer.
        }
        return mn; // final optimized answer.

  6. Optimized Memoization : since there is a case of itereative function calls,
     we check the hashmap in 3 separate occasions :
     a. Check if an optimized answer for the whole function call exists.
          if(dp[i][j] != -1) return dp[i][j];

     b. Check if the optimized answer for the left partion already exists.
          if(dp[i][k] != -1) partition1 = dp[i][k];

     c. Check if the optimized answer for the right partition already exists.
          if(dp[k+1][j] != -1) partion2 = dp[k+1][j];

---------------------------------- VARIATIONS ----------------------------------

  1. Input : array or string

  2. Choose starting index of i and j (partitions)

  3. base case : addition of more base cases apart from general base case depending
     upon the problem Statement.

  4. schema / partition : position of 'k' decides the order of partition.

---------------------------------- MCM INPUT FORMAT ----------------------------

  arr[] = 40 20 30 10 30      Therefor we see that, for 'n' input we have 'n-1'
  M1 = 40 x 20                matrix where each matrix 'i' : arr[i-1] x arr[i]
  M2 = 20 x 30
  M3 = 30 x 10                Therefor here the partition starts form index 1 (instead 0)
  M4 = 10 x 30                and goes upto index n-1.

  The range should consist of atleast 2 elements to be computed.
  BASE CASE :
  Case 1 :  i == j states there is a single element.
  Case 2 : and i > j states that there are no element. T
  the algorithm wont work in either of these 2 cases. therefor base case should be
        if(i >= j) return 0;   // the point where the function just breaks

*/
#include <bits/stdc++.h>
using namespace std;
int dp[2000][2000];
int mcm(int arr[], int i, int j)
{
  if(dp[i][j] != -1) return dp[i][j];

  if(i >= j) return dp[i][j] = 0;   // base case
  int mn = INT_MAX;
  for(int k = i; k<j; k++)          // partition loop
  {
    int partition1, partition2;
    if(dp[i][k] != -1) partition1 = dp[i][k]; // if this partition already exists refer dp
    else partition1 = mcm(arr, i, k);         // partition 1 : i to k

    if(dp[k+1][j] != -1) partition2 = dp[k+1][j]; // if this partition already exists refer dp
    else partition2 = mcm(arr, k+1, j);           // partition 2 : k+1 to j

    int temp =  partition1 + partition2 + (arr[i-1] * arr[k] * arr[j]); //(first elemnt of partion1 x common elemnt of both partition x last element of partition2)
    // cost of part1 + cost of part2 + cost of multiplying part1 and part2
    mn = min(temp, mn);
  }
  return dp[i][j] = mn;
}
int main()
{
  for(int i=0; i<2000; i++)
  for(int j=0; j<2000; j++) dp[i][j] = -1;
  int n;
  cout << "Enter the number of matrix to be chain multiplied : ";
  cin >> n;
  int arr[n];
  cout << "Enter matix data : \n";
  for(int i=0; i<n; i++) cin >> arr[i];
  cout << "Minimum operations : " << mcm(arr, 1, n-1);   // dimensions i : 1  to j : n-1
  return 0;
}
