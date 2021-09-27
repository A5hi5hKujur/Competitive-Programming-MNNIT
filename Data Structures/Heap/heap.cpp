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

* Parent of a node = arr[i/2]

* Height of a heap is always Log n.

------------------------------------- INSERTION IN HEAP -------------------------------------

Insertion time of a single element : O(log n)
1. If n = length of the heap, the new element should be inserted in (n+1)th position and increase the size of heap.
2. After insertion we make sure that it follows the rule of the heap(either min or max).
    - In case of max heap : new element should be smaller than all its descendents.
    - In case of min heap : new element should be greater than all its descendents.
3. HeapifyUp() : If the new element does not follow step 2, then keep moving up the new element by comparing
   it with its parent at (i/2)th position and swapping them untill step 2 is valid.

---------------------------------------- CREATION OF A HEAP ----------------------------------

Insertion time for n elements : O(nlogn)
1. iteratively insert new elements on the ith position starting from pos = 1.
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
class MaxHeap
{
    private:
    int size;               // total size of the array which is used to implement the heap.
    int pos;                // position where a new element is inserted at the time of push. It also marks the size of heap
    vector<int> arr;        // array through which heap is implimented (1 indexed for convinence)

    public:

    //-------------------- HEAP INITIALIZATION ---------------------------------
    MaxHeap(int n)
    {
        vector<int> temp(n+1);
        size = n;
        arr = temp;
        pos = 1;
    }
    //--------------------------------------------------------------------------

    //-------------------- INSERT NEW ELEMENT IN HEAP --------------------------
    void push(int x)
    {
        if(pos > size)        // if the new insertion exceeds the array capacity
            reorder();        // create a new array with 2x the size and copy all elements over
        arr[pos++] = x;       // add element in the correct 'pos' and point to next pos.
        heapifyUp();          // *IMPORTANT* bubble "up" to the new element to its correct spot
    }
    //--------------------------------------------------------------------------

    //---------------- REMOVE TOP ELEMENT OF THE HEAP --------------------------
    int pop()
    {
        if(pos == 1) return -1;   // underflow
        int val = arr[1];         // top element is always at index 1
        arr[1] = arr[pos-1];      // replace the root with the last element.
        pos--;                   // reduce the size of heap
        heapifyDown();           // *IMPORTANT* bubble "down" the root element to its correct spot
        return val;
    }
    //--------------------------------------------------------------------------
    int peak()
    {
        if(pos == 1) return -1;
        return arr[1];
    }
    bool isEmpty()
    {
        return pos == 1;
    }
    //----------------- HEAPIFY AT THE TIME OF DELETION ------------------------
    /*
      index  = current node. (parent)
      left child = left child of current node (index * 2)
      right child = right child of current node (index * 2 + 1)

      Max heap : compare with bigger child
      Min heap : compare with smaller child

    */
    void heapifyDown()
    {
        int index = 1;           // start with root
        int bigger_child, left_child, right_child;
        left_child = (index * 2 < pos)? arr[index * 2] : INT_MIN;         // left child value if its within bounds
        right_child = (index * 2 < pos)? arr[index * 2 + 1] : INT_MIN;    // right child value if its within bounds
        bigger_child = (left_child > right_child)? index * 2 : index * 2 + 1; // index of the greater value child

        // As long as the bigger child index is within bound and its size is greater than(for maxheap) its parent
        while(bigger_child < pos && arr[index] < arr[bigger_child])
        {
            swap(arr[index], arr[bigger_child]);  // swap parent with child
            index = bigger_child;                 // the child has now become the parent.
            // compute for its children now.
            left_child = (index * 2 < pos)? arr[index * 2] : INT_MIN;
            right_child = (index * 2 < pos)? arr[index * 2 + 1] : INT_MIN;
            bigger_child = (left_child > right_child)? index * 2 : index * 2 + 1;
        }
    }
    //--------------------------------------------------------------------------

    //------------- HEAPIFY AT THE TIME OF INSERTION ---------------------------
    /*
    swap current node with its parent until parent is smaller than (for max heap) the current node or you've reached the root.
    */
    void heapifyUp()
    {
        int index = pos - 1;                        // position of last insertion
        while(index > 1)                           // until you reach the root
        {
            int parent = index / 2;               // get parent address
            if(arr[parent] < arr[index])          // if parent element < current element
                swap(arr[parent], arr[index]);    // swap
            else
                break;                            // if not, then stop.

            index = parent;                        // move up.
        }
    }
    //--------------------------------------------------------------------------

    //----------- RESIZE ABSTRACT DS when it exceeds its size ------------------
    void reorder()
    {
        int new_size = size * 2;
        vector<int> temp(new_size + 1);
        for(int i = 1; i<=size; i++)
            temp[i] = arr[i];
        arr = temp;
        size = new_size;
    }
    //--------------------------------------------------------------------------
};
int main()
{
    MaxHeap max_heap(7);
    max_heap.push(50);
    max_heap.push(30);
    max_heap.push(40);
    max_heap.push(1);
    max_heap.push(20);
    max_heap.push(100);
    max_heap.push(50);
    max_heap.push(30);
    max_heap.push(40);
    max_heap.push(1);
    max_heap.push(20);
    max_heap.push(100);

    while(!max_heap.isEmpty())
    {
        cout << max_heap.pop() << "\n";
    }

    return 0;
}
