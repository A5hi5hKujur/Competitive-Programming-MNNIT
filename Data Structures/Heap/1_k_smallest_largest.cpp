/*
  Algorithm to find k largest/k smallest in O(nlogk) :
  1. Iterate through the input string and keep pushing inputs in the priority queue.
  2. The priority queue's top element will contain the maximum element upto that point
     in the case of max heap and minimum element upto that point in the case of min heap.
  3. As soon as the heap increases the size k, pop the topmost element out.
     - Finding k smallest : use max heap. (pops out excessivly large elements)
     - Finding k largest : use min heap.  (pops out excessivly small elements)
*/
#include<bits/stdc++.h>
using namespace std;

void kLargest(int arr[], int n, int k) // function to find k largest element.
{
    priority_queue<int, vector<int>, greater<int>> min_heap;
    for(int i=0; i<n; i++)
    {
        int input;
        input = arr[i];
        min_heap.push(input); // keep pushing elements from input stream in min heap.
        if(min_heap.size() > k) // until an excessivly small element is added on the heap.
            min_heap.pop();
    }
    cout << min_heap.top(); // finally the min_heap.top() will contain kth smallest element from the top A.K.A the kth largest element.
}
void kSmallest(int arr[], int n, int k) // function to find k smallest element.
{
   priority_queue<int> max_heap;
    for(int i=0; i<n; i++)
    {
        int input;
        input = arr[i];
        max_heap.push(input);
        if(max_heap.size() > k)
            max_heap.pop();
    }
    cout << max_heap.top();
}
int main()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    for(int i=0; i<n; i++)
        cin >> arr[i];
    kLargest(arr, n, k);
    cout << "\n";
    kSmallest(arr, n, k);
    return 0;
}
