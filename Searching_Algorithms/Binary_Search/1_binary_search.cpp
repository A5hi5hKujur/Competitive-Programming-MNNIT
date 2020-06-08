/*
  Binary Search : Return the position of the search element in the
                  sorted array if found otherwise return -1 if not
                  found.

  Reduces the search range by half every iteration,
  Time Complexity : O(log n).

  Note : The algorithm is designed for the array to be in ascending order.
*/
#include <bits/stdc++.h>
using namespace std;
int binary(int arr[], int n, int search)
{
    int low = 0;  // start position of the search range.
    int high = n-1; // end position of the search range.
    while(high >= low)  // Search till the high is less than the low.
    {
        int mid = low + (high - low)/2 // find the middle element (overflow optimized).
        if(arr[mid] == search) return mid;  // search point = mid.
        if(search < arr[mid]) high = mid - 1; // search field is moved to the left side.
        else low = mid + 1; // else move the search field to right side.
    }
    return -1;  // element was not found.
}
int main()
{
    cout << "Enter the number of elements in the array : ";
    int n;
    cin >> n;
    int arr[n];
    cout << "Enter the array elements : ";
    for(int i=0; i<n;) cin >> arr[i++];
    cout << "Enter the element to be searched : ";
    int search;
    cin >> search;
    int output = binary(arr, n, search);
    if(output == -1) cout << "Element not found";
    else cout << "The element is in position " << output;
    return 0;
}
