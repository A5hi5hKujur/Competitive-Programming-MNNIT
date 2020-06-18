/*
Search Element in a Bitonic Array :
- Basically a bitonic array is divided into 2 sorted monotonic array, i.e,
  ascending and descending / descending and ascending.
- The peak element is the divide point.

Algorithm :
1. Find the peak element position.
2. index1 = binarySearch(0, peak-1, arr, search).
3. index2 = binarySearch(peak, n-1, arr, search).
4. if(index1 && index2 == -1) Element not found.
   else Print max(index1, index2)
*/
#include <bits/stdc++.h>
using namespace std;
int Peak(vector<int> arr)
{
  int n = arr.size() - 1;
  int low = 0;
  int high = n;
  while(low <= high)
  {
    int mid = low + (high - low)/2;
    if((mid > 0) && (mid < n))
    {
        if((arr[mid] > arr[mid-1]) && (arr[mid] > arr[mid+1]))
          return mid;
        else if(arr[mid+1] > arr[mid])
          low = mid+1;
        else if(arr[mid-1] > arr[mid])
          high = mid-1;
    }
    else if(mid == 0)
    {
      return max(arr[0], arr[1]);
    }
    else if(mid == n)
    {
      return max(arr[mid], arr[mid-1]);
    }
  }
  return -1;
}
int binarySearch(vector<int> arr, int low, int high, int search)
{
    if(arr[low] < arr[high])
    {
        // binarySearch in ascending array.
        while(low <= high)
        {
          int mid = low + (high - low)/2;
          if(arr[mid] == search)
            return mid;
          else if(arr[mid] > search)
            high = mid-1;
          else
            low = mid+1;
        }
        return -1;
    }
    else
    {
        // binarySearch in descending arry.
        while(low <= high)
        {
          int mid = low + (high - low)/2;
          if(arr[mid] == search)
            return mid;
          else if(arr[mid] > search)
            low = mid+1;
          else
            high = mid-1;
        }
        return -1;
    }
    return -1;
}
int main()
{
  int n;
  cin >> n;
  vector<int> arr(n);
  for(int i=0; i<n; i++)
    cin >> arr[i];
  int search;
  cin >> search;
  int peak_index = Peak(arr);
  if(arr[peak_index] == search)
  {
    cout << peak_index;
  }
  else
  {
    int index1 = binarySearch(arr, 0, peak_index, search);
    int index2 = binarySearch(arr, peak_index, n-1, search);;
    if((index1 == -1) && (index2 == -1))
      cout << "Element not found.";
    else
      cout << max(index1, index2);
  }
  return 0;
}
