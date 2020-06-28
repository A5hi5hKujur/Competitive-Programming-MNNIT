/*
  Completely sort an almost sorted(k-sorted) array in log(nlogk) :
  We have to sort an array that would either be offset by i-k or i+k position.

  Observation : Since the ordering would be offset by k position we do not need to
                sort the entire array, just arr[i] to arr[i+k] for a given i.

  Algorithm :
  1. Create a minimum heap to process k elements at any given time.
  2. iterativly insert elements in the min_heap.
  3. As soon as the size of the heap exceeds k, pop out the topmost element of min_heap and place it in its correct index(starting from 0.)
  4. The heap would be left over with last k elements, pop out and place the top elements in their correct index till the heap is exhausted.
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
  priority_queue<int, vector<int>, greater<int>> min_heap;
  int n, k;
  cin >> n >> k;
  int arr[n];

  for(int i=0; i<n; i++)
    cin >> arr[i];

  int index = 0;  // index to start placing the correct elements in.
  for(int i=0; i<n; i++)
  {
    min_heap.push(arr[i]);  // insert elements in the min_heap
    if(min_heap.size() > k) // as soon as the elements in the min_heap exceed k
    {
      arr[index++] = min_heap.top();  // place the topmost element in the correct index.
      min_heap.pop(); // remove the topmost element. (Size of heap right now = k)
    }
  }
  while(min_heap.size() > 0)  // k elements would still be left over.
  {
    arr[index++] = min_heap.top();  // place the topmost element in the correct index.
    min_heap.pop();                 // until the heap is exhausted.
  }
  for(int i : arr)     // display sorted array.
    cout << i << " ";
  return 0;
}
