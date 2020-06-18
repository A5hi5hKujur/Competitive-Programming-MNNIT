/*
  Monotonic Array : Elements in that array progress in an ascending or desecnding
  manner.

  Bitonic Array : Elements in that array either ascend monotonically, reach a peak
  and then descend monotonically, or decend monotonically, reach a depth and then ascend
  monotonically.

  Note : There can only be a single peak or depth element.
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
    if(mid > 0 && mid < n)
    {
      if((arr[mid] > arr[mid+1]) && (arr[mid] > arr[mid-1]))
        return mid;
      else if(arr[mid+1] > arr[mid])
        low = mid+1;
      else if(arr[mid-1] > arr[mid])
        high = mid-1;
    }
    else if(mid == 0)
    {
      if(arr[0] > arr[1])
        return 0;
      else return 1;
    }
    else if(mid == n)
    {
      if(arr[n] > arr[n-1])
        return n;
      else return n-1;
    }
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
  cout << "The peak element is in " << Peak(arr) << " index.";
  return 0;
}
