/*
Find a number in a sorted rotated array.
Continuation of "rotation_count.cpp" where the pivot basically divides the sorted
rotated array into 2 sorted array.

1. You can either run binary search in both the arrays and check if any one section
   returns a valid index.

2. You can compare the last element with the element to be searched.
    - In an array sorted in ascending order.
      If(search element < last element) search on the right section.
      else search on the disturbed section (left).

*/
#include <bits/stdc++.h>
using namespace std;
vector<int> arr;
int Pivot()
{
  int n = arr.size();
  int high = n-1;
  int low = 0;
  while(low <= high)
  {
    int mid = low + (high - low)/2;
    int prev = arr[(mid-1 + n) % n];
    int next = arr[(mid+1) % n];
    if((arr[mid] < prev) && (arr[mid] < next))
      return mid;
    else if(arr[mid] >= arr[low]) low = mid+1;
    else if(arr[mid] <= arr[high]) high = mid-1;
  }
  return -1;
}
int binarySearch(int l, int h, int search)
{
  int low = l;
  int high = h;
  while(low <= high)
  {
    int mid = low + (high - low)/2;
    if(arr[mid] == search)
      return mid;
    else if(arr[mid] < search) low = mid+1;
    else if(arr[mid] > search) high = mid-1;
  }
  return -1;
}
int main()
{
  int n;
  cin >> n;
  for(int i=0; i<n; i++)
  {
    int input;
    cin >> input;
    arr.push_back(input);
  }
  int pivot = Pivot();
  int search;
  cin >> search;
  int index;
  if(arr[arr.size() - 1] > search)
    index = binarySearch(pivot, arr.size() - 1, search);
  else if(arr[arr.size() - 1] < search)
    index = binarySearch(0, pivot-1, search);
  else index = arr.size() - 1;
  if(index == -1) cout << "Element not found";
  else cout << "Element is in the " << index << " index";
  return 0;
}
