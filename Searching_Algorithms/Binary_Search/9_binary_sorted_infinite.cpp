/*
  Binary Sorted Array : The array that only contains 1s and 0s, in an order. i.e,
  all the 1s at one side and all the 0s on another. where 1 comes after 0.

  --------------------------- Problem Statement --------------------------------
  Find the first Occurance of 1 in an Infinitely Binary Sorted Array.

  --------------------------- Solution Approach --------------------------------
  The problem is a combination of 2 types of problems previously tackeled :
  1. Searching an element in an Infinitely sorted array.
  2. Finding first Occurance of an element.

  a. We first find a limited range of existance of the element(in this case 1)
     in an Infinite array.

  b. Within that range we find the first Occurance of the element(in this case 1).
  ------------------------------------------------------------------------------
*/
int firstOccurance(int arr, int low, int high)
{
  int ans = high;   // since the fist know Occurance is high.
  while(low <= high)  // while the search range exists
  {
    mid = low + (high - low)/2;
    if(arr[mid] == 1)  // if you encounter a '1' is your mid position
    {
      ans = mid;  // mark it as a possible answer.
      high = mid-1; // move left.
    }
    else
      low = mid+1;  // move right if a '0' is encountered.
  }
  return ans;
}
int binarySortedInfinite(vector<int> arr) // function that accepts an Infinitely Binary Sorted Array, and returns first index of 1.
{
  int low = 0;
  int high = 1;
  while(arr[high] == 0)  // as long as the upper bound of the range is 0.
  {
    low = high;   // change new low to previous high.
    high *= 2;   // change new high to 2x high.
  }
  return firstOccurance(arr, low, high);  // you have a limited range when high == 1
}
