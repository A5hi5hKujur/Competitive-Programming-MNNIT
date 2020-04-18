/*
Heap : A complete Binary Tree.
Max-Heap: Root node must be GREATEST among all of it’s children.
          The same property must be recursively true for all sub-trees in that Binary Tree.

Min-Heap: Root node must be MINIMUM among all of it’s children.
          The same property must be recursively true for all sub-trees in that Binary Tree

---------------------------- Representation of Heap in array ------------------------------

* The reason that it MUST be a complete Binary Tree because the array should not have any
  gaps in between.

* For any Node arr[i] :
  left child = arr[2*i]
  right child = arr[2*i + 1]

* Height of a heap is always Log n.

------------------------------------- INSERTION IN HEAP -------------------------------------

Insertion time of a single element : O(log n)
1. If n = length of the heap, the new element should be inserted in (n+1)th position.
2. After insertion we make sure that it follows the rule of the heap(either min or max).
    - In case of max heap : new element should be smaller than all its descendents.
    - In case of min heap : new element should be greater than all its descendents.
3. If the new element does not follow step 2, then keep moving up the new element by comparing
   it with its parent at (i/n)th position and swapping them untill step 2 is valid.

---------------------------------------- CREATION OF A HEAP ----------------------------------

Insertion time for n elements : O(nlogn)
1. itteratively insert new elements on the ith position starting from i = 2.
2. Repeat the insertion heap procedure.

------------------------------------- Deletion from HEAP -------------------------------------

1. Deletion on the heap is done at the root and is replaced by the last element of the heap.
   as a 'new root'(to compansate for the gap).
2. The root is reserved for either the largest element (incase of max Heap) or the smallest
   element (in case of min Heap), and the 'new root' is most definately neither, therefore the proper
   element should be in the root and the element in the root position should be shifted to its proper
   position.
3. Compare the 'new root' with both the children :
   max heap : keep replacing 'new root' with max(left child, right child), until both the children
              of that element is less than the element itself.
   min heap : keep replacing 'new root' with min(left child, right child), until both the children
                         of that element is greater than the element itself.

--------------------------------------- Heap Sort -----------------------------------------------

1. Keep deleting the root element and place it on the last position, while shrinking the heap,
   what was once a max-heap / min-heap would now be a sorted-heap.

--------------------------------------------------------------------------------------------------
*/
#include <bits/stdc++.h>
using namespace std;
int n; // Size of heap
vector<int> min_heap(n+1); // Min Heap
vector<int> max_heap(n+1); // Max Heap

//-------------------------- Function to create Max Heap -----------------------------------------
void maxHeap(vector<int> arr, int n) // arguments : input string , number of elements
{
  max_heap = arr; // initialize heap array with the input array.
  for(int i=2; i<=n; i++) // starting from the 2nd element to the last element
  {
    int j = i; // include the element to the heap from the back
    while(max_heap[j] > max_heap[j/2] && j > 1) // while child is greater than the parent and pointer is upto the root element.
    {
        swap(max_heap[j], max_heap[j/2]); // keep swapping the greater child to the smaller parent.
        j = j/2; // move on to the next parent.
    }
  }
  cout << "Max Heap : \n";
  for(int i=1; i<=n; i++) cout << max_heap[i] << " ";
}
//-------------------------------------------------------------------------------------------------

//--------------------------------------- Funtion to create Min Heap ----------------------------------
void minHeap(vector<int> arr, int n)
{
  min_heap = arr;
  for(int i=2; i<=n; i++)
  {
    int j = i;
    while(min_heap[j] < min_heap[j/2] && j > 1) // same process as max heap but here we check if the parent has mimimum value.
    {
        swap(min_heap[j], min_heap[j/2]);
        j = j/2;
    }
  }
  cout << "Min Heap : \n";
  for(int i=1; i<=n; i++) cout << min_heap[i] << " ";
}
//--------------------------------------------------------------------------------------------------------

//--------------------------------------- Function to delete elements from heap ----------------------------
void Delete(int n) // working range for deletion
{
    swap(max_heap[1], max_heap[n]); // swap the max element with the last element.
    int i = 1; // first parent (root), must place it in its correct spot.
    int j = 2*i; // first child of root.
    while((max_heap[i] < max_heap[j] || max_heap[i] < max_heap[j+1]) && j < n-1) // if node element is smaller than either of its children
    {
        if(max_heap[j] > max_heap[j+1]) // if the left child is bigger
        {
            swap(max_heap[i], max_heap[j]); // swap parent with the left child
            i = j; // now follow the path of the left child
        }
        else // if the right child is bigger
        {
            swap(max_heap[i], max_heap[j+1]); // swap parent with the right child
            i = j+1; // now follow the path of the right child
        }
        j = 2*i; // first child of whatever path i is in.
    }
}
//------------------------------------------------------------------------------------

//------------------------------- Function for Heap sort ----------------------------
void heapSort(int n) // total number of elements in the heap.
{
    for(int i=n; i > 1 ; i--) // starting from the complete heap length
    { // to shrinking it by 1 position at each iteration.
        Delete(i);
    }
    cout << "\nAscending sort : \n";
    for(int i=1; i<=n; i++) cout << max_heap[i] << " ";
}
//----------------------------------------------------------------------------------------
int main()
{
  cout << "Enter the size of the heap : ";
  cin >> n;
  vector<int> arr(n+1);
  cout << "Enter " << n <<" elements : \n";
  for(int i=1; i<=n; i++) cin >> arr[i];
  maxHeap(arr,n);
  cout << "\n";
  minHeap(arr,n);

  heapSort(n);
  return 0;
}
