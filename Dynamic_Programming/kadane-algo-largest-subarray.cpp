#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;      // Number of elements
    int arr[];  // Array.
    cin >> n;
    for(int i=0; i<n; i++) cin >> arr[i];   // Array Input
    
    int sum = arr[0];   // variable that stores the ongoing sum of the subarray(starts with the first value of the array).
    int max = sum;      // variable that stores the maximum sum of the largest subarray.
    int start = 0;      // start index of the largest subarray.
    int end = 0;        // end index of the largest subarray.
    bool negative_arr = true;   // status for all negative element array. (true by default)
    
    // Check if the array is completely negetive, if so find the least negative(largest) number in the array.
    int neg_max = -999;
    for(int i=0; i<n; i++){
        if(arr[i] > 0){
            negative_arr = false;   // exit out and flag the negative array as false if a single +ve no. is found.
            break;
        }
        if(arr[i] > neg_max){
            neg_max = arr[i]; // The least negative number. 
            start = i; // start = end since its a single digit.
            end = i;
        }
    }
    if(!negative_arr){  // if the array is non-negative move towards Kadane's Algo.
        start = 0;
        end = 0;
        for(int i=1; i<n; i++) // move linearly from the 2nd element.
        {   
            if(sum + arr[i] > arr[i])   // if the trailing sum is greater than the value of current element alone
            {
                sum += arr[i];  // include the current element on the trail too !
            }
            else
            {
                sum = arr[i];   // otherwise start a new trail where the first element of the new trail would be the current element, which was larger than the previous trail combined,
                start = i;      // since the trail starts fresh
                end = i;
            }
            if(max < sum)       // if the sum crosses maximum value update max
            {   
                max = sum;
                end = i;        // mark the trail end upto that point.
            }
        }
        cout << max << endl;   // Displays Kadane's maximum sum array.
    }
    else
        cout << neg_max << endl;    // Displays least negative number in the completely negative array.
    
    
    for(int i=start; i<=end; i++) cout << arr[i] << " "; // display the actual sub-array.
    return 0;
}
