/*
Count number of rotations (left)
1. pivot element : smallest element of the array, whose left and right element both would be greater than itself.
                     If no such element is found then array is sorted correctly.

The number of rotation depends upon the position of the pivot element, which happens to be the smallest element in the
array. The offset of that element would be the number of rotations (left).

eg : correct order : 2 3 4
     rotated order : 4 2 3  ; here the smallest element is at offset index 1, i.e, it has been rotated once.

Algorithm :
  1. Search the pivot element,
      if(current mid < current mid-1 && current mid < current mid+1) pivot element found.
  2. If pivot element not found in 'mid',
      - compare 'mid' with 'low'  : Normally, arr[mid] element should be greater than arr[low] element.
      - compare 'mid' with 'high' : Normally, arr[mid] element should be smaller than arr[high] element.

      Since the above mentioned conditions are true in the case of Normally sorted array, but rotation
      of a sorted array creates an anomaly in these conditions. And since pivot element is the source of this
      anomaly, we move in the direction where either one of the condition is false.

  3. Iterativly repeat this process unless you either find the pivot point or you exhaust the array.

  OPTIMIZATION : The Algorithm runs in O(log n) time irrespective of the array being rotated or not.
                Find if the array is rotated in O(1) :
                  if(arr[low] < arr[high])
                    array is not rotated.
                  else
                    array is rotated.
*/
#include <bits/stdc++.h>
using namespace std;
int Pivot(vector<int> arr)
{
    int n = arr.size();       // find size of array to apply % to avoid over/underflow.
    int low = 0;
    int high = arr.size() - 1;
    while(low <= high)
    {
        int mid = low + (high - low)/2;
        int next = arr[(mid+1) % n];    // avoid overflow when fetching (mid+1)th element.
        int prev = arr[(mid+n-1) % n];  // avoid underflow when fetching (mid-1)th element.
        if((arr[mid] <= next) && (arr[mid] <= prev)) // compare mid with its neighbours, if mid is smaller than both its neighbours.
        {
            return mid; // Pivot element found !
        }
        else
        {
          if(arr[mid]>=arr[low] && arr[mid]<=arr[high]) // edge case where mid is the largest element.
          {
            return low;
          }
          else if(arr[low] <= arr[mid]) // if the left section of the array is sorted.
          {
              low = mid+1;  // move to the right.
          }
          else if(arr[mid] <= arr[high])  // if the right section of the array is sorted.
          {
              high = mid-1; // move to the left.
          }
        }
    }
    return -1;
}
int main()
{
    vector<int> arr = {8,11,12,14,18,2};
    int pivot = Pivot(arr);
    if(pivot == -1)
    cout << "Number of Rotations : 0";
    else cout << "NUmber of Rotations : " << pivot;
    return 0;
}
