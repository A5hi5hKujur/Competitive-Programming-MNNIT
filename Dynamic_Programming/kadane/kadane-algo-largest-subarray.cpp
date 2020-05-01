/*
Kadane Algorithm : Finding the largest sub array sum in O(n) linear time.
Sub-array : Consequtive array elements(running chain).

but first some context, basically we have to create a running chain of array elements which gives the maximum sum.
if we choose to break the chain, we start over.

Also, conceptually : This running chain would be made up of smaller running mini chains just added up to our main chain (if you can visualize).
which would entail that : WE ONLY INCLUDE THE MINI CHAINS WHICH HELP GROW OUR MAIN CHAIN, i.e, do not add mini chains with a -ve sum to
our main chain, that will only hurt our chain. And we don't hurt the one's we love.

lets begin :
step 1 : Take a variable which stores the sum of the current mini chain (sum).
step 2 : Take a variable which stores the sum of the main chain (max).
step 3 : Keep adding to the current mini chain the sum of elements (sum += arr[i]).
            - If on the way to expanding your current chain you find a point where your mini chain dips below zero,
              dump that chain and start over (sum < 0 then sum = 0).
              You would still have the maximum sum of a running chain up until that point in the variable max.
            - Every time the sum of the current chain increases, update the main chain. (max < sum then max = sum).
step 4 : Whatever longest sub-array sum you end up with will be in "max".

Note : In case of an array with all negative numbers the algo will return the negetive number closest to zero.
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;      // Number of elements
    cin >> n;
     int arr[n];  // Array.
    for(int i=0; i<n; i++) cin >> arr[i];   // Array Input

    int sum = 0;   // variable that stores the ongoing sum of the subarray.
    int max = INT_MIN;      // variable that stores the maximum sum of the largest subarray

    for(int i=0; i<n; i++) // move linearly.
    {
        sum += arr[i];  // add the element of the array to the ongoing chain.
        if(max < sum)   // if the trailing sum is greater than the maximum value found till now.
        {
            max = sum;  // declare it the as the maximum chain.
        }
        if(sum < 0) // the moment the value of sum goes below zero.
        {
            sum = 0;    // reset the chain.
        }
    } // The chain continues with the updated value of the "sum", which should be a non-negative value
    cout << max << endl;   // Displays Kadane's maximum sum array. 
    return 0;
}
