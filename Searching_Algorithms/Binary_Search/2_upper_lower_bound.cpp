/*
Problem :
1. Find the first occurance of an element in a SORTED array.
2. Find the last occurance of an element in a SORTED array.
3. Find the number of occurances of an element in the SORTED array.

1. Binary search with reduced range towards the left until the array is exhausted.
2. Binary search with reduced range towrds the right until the array is exhausted.
3. Total occurance = Last occurance - First occurance + 1 (0-based index).
*/

#include <bits/stdc++.h>
int firstOccurance(vector<int> arr, int search)
{
    int ans = -1;   // inital answer "-1" to represent the element was not found.
    int low = 0;
    int high = arr.size() - 1;
    while(low <= high)
    {
        int mid = low + (high - low)/2;
        if(arr[mid] == search)  // If element is found,
        {
            ans = mid;  // mark index as plausible first occurance of the element.
            high = mid-1; // shrink the range towards the left side to find more occurances BEFORE current element.
        }
        else if(arr[mid] > search)
            high = mid-1;
        else if(arr[mid] < search)
            low = mid+1;
    }
    return ans;
}
int lastOccurance(vector<int> arr, int search)
{
    int ans = -1;
    int low = 0;
    int high = arr.size() -1;
    while(low <= high)
    {
        int mid = low + (high - low)/2;
        if(arr[mid] == search)  // If element is found,
        {
            ans = mid;  // mark index as plausible flast occurance of the element.
            low = mid+1; // shrink the range towards the right side to find more occurances AFTER current element.
        }
        else if(arr[mid] > search)
            high = mid-1;
        else if(arr[mid] < search)
            low = mid+1;
    }
    return ans;
}
int main()
{
    vector<int> arr = {5,5,5,5,5,5,5,5};
    int first = firstOccurance(arr, 5);
    int last = lastOccurance(arr, 5);
    cout << "Lower Bound : " <<  first << "\n";
    cout << "Upper Bound : " << last << "\n";
    cout << "Number of Occurances of 5 : " << last - first + 1;
    return 0;
}
