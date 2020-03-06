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
    for(int i=start; i<=end; i++) cout << arr[i] << " "; // display the actual sub-array.
    return 0;
}
