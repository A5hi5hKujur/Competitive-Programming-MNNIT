/*
  Find the k closest element
  Given an array and a number x, find the kth number that is closest to x.
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
    priority_queue<pair<int,int>> max_heap;
    int n, k, x;
    cin >> n >> k >> x;
    int arr[n];
    int diff[n];  // array that stores the difference of x.
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
        diff[i] = abs(x - arr[i]);
    }
    for(int i=0; i<n; i++)
    {
        max_heap.push({diff[i], arr[i]}); // pushing difference and element in the max heap such that difference is the key
        if(max_heap.size() > k)
            max_heap.pop();
    }
    while(max_heap.size() > 0)
    {
        cout << max_heap.top().second << " ";
        max_heap.pop();
    }
    return 0;
}
