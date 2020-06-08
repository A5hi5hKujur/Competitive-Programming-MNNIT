/*
    Nearly Sorted Array : The way of scrambling a sorting array where a perticular
                          element can either be at sorted position or offset by 1 position,
                          i.e, either at ith position(sorted) or (i+1)th and (i-1)th position(offset)
*/

#include <bits/stdc++.h>
using namespace std;
int nearlyBinarySearch(vector<int> arr, int search)
{
    int low = 0;
    int high = arr.size() - 1;
    while(low <= high)
    {
        int mid = low + (high - low)/2;
        if(arr[mid] == search)  // check if the element is at its correct spot.
            return mid;
        if(mid+1 <= high && arr[mid+1] == search)   // compare with (mid+1)th element unless mid+1 goes over the range of search.
            return mid+1;
        if(mid-1 >= low && arr[mid-1] == search)  // compare with (mid-1)th element unless mid-1 goes under the range of search.
            return mid-1;
        if(arr[mid] < search)
            low = mid+2;  // move 2 spaces to the left.
        else if(arr[mid] > search)
            high = mid-2; // move 2 spaces to the right.
    }
    return -1;
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr;
    while(n--)
    {
        int input;
        cin >> input;
        arr.push_back(input);
    }
    int search;
    cin >> search;
    int index = nearlyBinarySearch(arr, search);
    if(index == -1) cout << "Element not found";
    else cout << "Element " << search << " is at index " << index;
    return 0;
}
