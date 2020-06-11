/*
  BINARY SEARCH ON ANSWER : This is a binary search concept that dictates that there
  are some problems where the array is neither sorted in ascending order nor descending
  order, yet binary search can be implimented in those problems.

  -------------------- BINARY SEARCH IS A 2 STEP PROCESS : ---------------------
  1. We analyze the middle, where we choose it as an answer based on some "crieteria 1".
  2. Based on the analysis we either move towards the left of mid or the right
     of mid, based on a different "crieteria 2" derived by the middle element.

  Criteraia 1 and Crireria 2 needs to be derived by the programmer.

  ------------------ COMPARISION WITH NORMAL BINARY SEARCH : -------------------
  1. Normal Binary Search :

              while(low <= high)
              {
                if(arr[mid] == search) return mid;
                else if(arr[mid] > search) high = mid-1;
                else low = mid+1;
              }

  2. Binary Search with Answer :

              while(low <= high)
              {
                if(criteria1(arr[mid])) return mid;
                else if(criteria2(arr[mid])) high = mid-1 or low = mid+1;
                else low = mid+1 or high = mid-1;
              }
  --------------------- Example problem statement ------------------------------

  Peak element : element which is bigger than the neighbouring elements.
  i.e
    arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]  (non edge elements)
    arr[n-1] > arr[n-2]                             (right edge element) where n is the no. of elements
    arr[0] > arr[1]                                 (left edge element)

    Note : There may exist more than 1 "peak" element. Display any one.

 */
 #include <bits/stdc++.h>
 using namespace std;

int findPeak(vector<int> arr)
{
  int n = arr.size() - 1;
  int low = 0;
  int high = n;

  while(low <= high)
  {
    int mid = low + (high - low)/2;
    if(mid > 0 && mid < n)  // if the mid is a non-edge element.
    {
        if((arr[mid] > arr[mid+1]) && (arr[mid] > arr[mid-1]))  // if both its neighbours are smaller.
            return mid;                 // peak element.
        else if(arr[mid+1] > arr[mid])  // if not, compare the right neighbour, if its bigger, it has a possibility of being the "Peak".
            low = mid+1;                // move towards right.
        else if(arr[mid-1] > arr[mid]) // if not, compare left neighbour. if its bigger then it has a possibility of being the "Peak".
            high = mid-1;               // move towards left.
    }
    else if(mid == 0)                 // left most edge.
    {
        if(arr[0] > arr[1])            // single comparision.
            return 0;
        else return 1;                 // if mid == 0 then there are likely only 2 elements in the search range(both being the corner elements).
    }
    else if(mid == n)                 // right most edge.
    {
        if(arr[n] > arr[n-1])         // single comparision
            return n;
        else return n-1;              // if mid == n then there are likely only 2 elements in the search range(both being the corner elements)
    }
  }
  return -1;
}
 int main()
 {
   vector<int> arr;
   int n;
   cin >> n;
   while(n--)
   {
     int input;
     cin >> input;
     arr.push_back(input);
   }
   int index = findPeak(arr);
   if(index == -1) cout << "Peak element not found";
   else cout << "Peak element found at index " << index;
   return 0;
 }
