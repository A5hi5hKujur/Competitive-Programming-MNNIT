/*
  -------------------------------- Problem Statement ----------------------------
  Find the first larger element from the left hand side for each element in the array.
  If no larger element exists then print -1.

  --------------------------------- Solving Approach ----------------------------
  Unlike the "Next Larger Element", this problem is more of a "Last Larger Element",
  Therefor we just need only one linear traversal from arr[0] to arr[n-1] and for every element
  store the possible large element for the input (arr[i]) element that has already occured in the
  input string.

  The core algorithm however stays the same.
  ---------------------------------- Variations --------------------------------
  Smaller Number to the left.
  Smaller Number to the right.
  Are the variations of the 1st 2 stack probems with essentially the same code but different
  comparision operators.
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  stack<int> st;      // stores the smallest possible higher value at the top of the stack.
  for(int i=0; i<n; i++)
  {
    int input;
    cin >> input;
    if(st.empty())    // when there is no bigger element before input.
      cout << -1 << " ";
    else if(st.top() > input)   // when already occured element is greater than the input.
      cout << st.top();         // display the bigger element.
    else if(st.top() <= input)  // when already occured element is smaller than the input.
    {
      while(!st.empty() && st.top() <= input) // keep popping elements till you find a greater element or stack is exhausted.
        st.pop();
      if(st.empty())
        cout << -1 << " ";
      else
        cout << st.top();
    }
    st.push(input); // push the input in the stack since it can be the first larger number than the element from the left.
  }
  return 0;
}

//---------------------------- Next Larger Variations --------------------------------
void nextLargerLeft(vector<int> arr)
{
    cout << "Next Larger Left \n";
    int n = arr.size();
    stack<int> st;
    int ans[n];
    for(int i = 0; i<n; i++)
    {
        int current = arr[i];
        while(!st.empty() && st.top() <= current)
            st.pop();
        if(st.empty())
            ans[i] = -1;
        else
            ans[i] = st.top();
        st.push(current);
    }
    for(int i=0; i<n; i++)
        cout << ans[i] << " ";
}
void nextLargerRight(vector<int> arr)
{
    cout << "Next Larger Right \n";
    int n = arr.size();
    stack<int> st;
    int ans[n];
    for(int i=n-1; i>=0; i--)
    {
        int current = arr[i];
        while(!st.empty() && st.top() <= current)
            st.pop();
        if(st.empty())
            ans[i] = -1;
        else
            ans[i] = st.top();
        st.push(current);
    }
    for(int i=0; i<n; i++)
        cout << ans[i] << " ";
}
void nextSmallerLeft(vector<int> arr)
{
    cout << "Next Smaller Left \n";
    int n = arr.size();
    stack<int> st;
    int ans[n];
    for(int i=0; i<n; i++)
    {
        int current = arr[i];
        while(!st.empty() && st.top() >= current)
            st.pop();
        if(st.empty())
            ans[i] = -1;
        else
            ans[i] = st.top();
        st.push(current);
    }
    for(int i=0; i<n; i++)
        cout << ans[i] << " ";
}
void nextSmallerRight(vector<int> arr)
{
    cout << "Next Smaller Right \n";
    int n = arr.size();
    stack<int> st;
    int ans[n];
    for(int i=n-1; i>=0; i--)
    {
        int current = arr[i];
        while(!st.empty() && st.top() >= current)
         st.pop();
        if(st.empty())
            ans[i] = -1;
        else
            ans[i] = st.top();
        st.push(current);
    }
    for(int i=0; i<n; i++)
        cout << ans[i] << " ";
}
