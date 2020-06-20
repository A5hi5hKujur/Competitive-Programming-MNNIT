/*
 ------------------------------ Probem Statement -------------------------------
  In a given array, find the number of CONSECUTIVE ELEMENTS(including itself) smaller than or equal to
  itself for all the elements in the array.

  eg : arr = { 100, 80, 60, 70, 60, 75, 85 }
       ans = {  1 , 1 , 1 , 2 , 1 , 4 , 6  }

       explaination :
       arr[0] = 100, has no element smaller than or equal to itself. therefor, ans[0] = 1.
       arr[3] = 70, has only 1 element apart from itself satisfying the condition.
       arr[6] = 85, has 5 elements, apart from itself satisfying the condition.

------------------------------- Solving Approach -------------------------------
The problem basically a variation of "finding the first bigger element before the element".
1. Find the first element to the left maximum to the element arr[i]
2. Display the difference of the index of the found element with the index of the current element.

Note : instead of storing the elements in the stack lets store the index values since we will be
       using index values to find the count of elements.

Working : This algorithm works on the principles of precomputation during linear run time, meaning :
          current element = arr[i]  ; current index = i
          previous element = arr[i-1] ; previous index = i-1

          If(current element < previous element)
              You dont have to check further.
          If(current element > previous element)
              - The stack top-1 would have the index of the element that was bigger than i-1;
              - And now arr[i] gets a chance to see if it can go any further than arr[i-1]'s stopping point;
              - arr[i] doesnt have to go through elements that arr[i-1] already went through.
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  stack<int> st;
  int arr[n];    // input stream (uneccsory if using stack<pair<int, int>> st)
  for(int i=0; i<n; i++)
    cin >> arr[i];
  for(int i=0; i<n; i++)  // stack operation.
  {
    int input;
    input = arr[i];
    if(st.empty())      // if you can't find a greater element on left, return current index + 1.
      cout << i - (-1) << " ";
    else if(arr[st.top()] > input)  // if the top element is greater than the current element return the diffrence.
      cout << i - st.top() << " ";
    else if(arr[st.top()] <= input) // if top element is smaller than the current element start popping them out until you reach a bigger element.
    {
      while(!st.empty() && arr[st.top()] <= input)
        st.pop();
      if(st.empty())
        cout << i - (-1) << " ";
      else
        cout << i - st.top() << " ";
    } // return the difference.
    st.push(i); // push the current index
  }
  return 0;
}
