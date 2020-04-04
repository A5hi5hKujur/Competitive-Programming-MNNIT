/*
  MERGING 2 SORTED ARRAYS : O(m+n)
  Algorithm :
  1. take 2 sorted arrays of length m,n to be merged. take 1 result array of length
     m+n to store the merged array.

  2. compare the elements of the 2 arrays and store the smaller element on the result
     array (ascending order) until both or any one array gets completely exhausted.

  3. Copy over the remaining element from the array which is not exhausted.

  NOTE : The above algorithm is for 2-way merging, smilarly there is n-way merging
         if we have n no. of arrays to be merged.
*/

//--------------------- Function to merge 2 sorted arrays ----------------------
int result_arr[m+n];
void Merge(int arr1[], int arr2[], n, m)
{
  int i=0, j=0, k=0;
  while(i<n && j<m) // iterate till any one array gets exhausted.
  {
    if(arr1[i] > arr2[j])
    result_arr[k++] = arr2[j++];
    else
    result_arr[k++] = arr1[i++];
  }
  while(i<n) result_arr[k++]; // copy remaining if arr1 is not exhausted
  while(j<m) result_arr[k++]; // copy remaining if arr2 is not exhausted
}
//------------------------------------------------------------------------------

/*
Merge Sort : (THiNGS TO  KnoW beFORE MERGE SORT)
* This sorting algorithm follows the principles of 2-way merging, where
  even n no. of arrays can be merged 2-arrays at a time.

* Initally an array with a single element is itself sorted.

* Elements in an array act as an array of single elements which are recursively merged.

MERGE SORT : O(nlogn) :
Algorithm :
*/
//-------------------------- MERGE SORT PROGRAM --------------------------------
#include <bits/stdc++.h>
using namespace std;
//----------------- MERGE function with auxilary arrays ------------------------
/*
  merge function definition :
  Return : nothing
  Arguments :
    - arr[] : main array to be merge sorted.
    - low : lower index of the array.(starting point of sub-array 1)
    - mid : middle of the array. (ending point of sub-array 1)
    - high : upper index of the array (ending point of sub-array 2).

    Note : starting point of sub-array 2 : mid + 1
*/
void merge(int arr[], int low, int mid, int high)
{
    int n1 = mid - low + 1; // length of sub-array 1
    int n2 = high - mid; // length of sub-array 2
    int temp1[n1]; // auxilary subarray 1
    int temp2[n2]; // auxilary subarray 2

    // copying values from the main array to the auxilary arrays
    for(int i=0; i<n1; i++)
        temp1[i] = arr[low+i]; // subarray 1 starts from low
    for(int i=0; i<n2; i++)
        temp2[i] = arr[mid+1 + i]; // subarray 2 starts from mid+1

    int i=0;  // iterator for subarray1
    int j=0; // iterator for subarray2
    int k=low; // iterator for main array to be sorted.
    while(i<n1 && j<n2) // iterate till any 1 subarray gets exhausted
    {
        if(temp1[i] <= temp2[j]) arr[k++] = temp1[i++]; // if element in subarray1 is smaller, choose that.
        else arr[k++] = temp2[j++]; // else choose element from subarray2.
    }
    while(i<n1) arr[k++] = temp1[i++]; // copy over all elements from subarray1 if unexhausted.
    while(j<n2) arr[k++] = temp2[j++]; // copy over all elements from subarray2 if unexhausted.
}
//------------------------------------------------------------------------------

//------------------------ MERGE SORT function ---------------------------------
/*
  returns : nothing
  arguments :
    - arr[] : array to be sorted.
    - low : lower index of array.
    - high : upper index of array.
*/
void mergeSort(int arr[], int low, int high)
{
    if(low < high) // base case : while lower index is less than the higher index.
    {
        // equivalent to (low + high)/2, in case of very large array (low+high) will overflow the datatype that stores the middle index.
        int mid = low + (high - low)/2;
        mergeSort(arr, low, mid); // divide (and sort) the left half of the array.
        mergeSort(arr, mid+1, high); // divide (and sort) the right half of the array.
        merge(arr, low, mid, high); // this is the actuall sort function call which starts merge sorting when the array is completely divided to single unit.
    }
}
//------------------------------------------------------------------------------

//------------------------------- MAIN FUNCTION --------------------------------
int main()
{
    cout << "Enter the length of the array to be sorted : ";
    int n;
    cin >> n;
    int arr[n];
    cout << "Enter " << n <<" elements in the array : \n";
    for(int i=0; i<n; i++)
      cin >> arr[i];
    mergeSort(arr,0,n-1);
    cout << "Sorted Array :\n";
    for(int i=0; i<n ; i++)
        cout << arr[i] << " ";
    return 0;
}
