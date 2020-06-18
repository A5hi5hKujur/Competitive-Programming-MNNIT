/*
  -------------------- IDENTIFICATION OF A STACK PROBLEM -------------------------
  Stacks are more often used as an auxilary data structure to track and process the
  top item, once the processing is complete the 'top' item gets popped and forever be
  lost. With this auxilary nature of a stack we con conclude that if a varible is depending
  upon another variable at every stage of a problem solving process, we can use a stack to
  convert an operation which would take polynomial time O(n^2) to linear time O(n).

  - The problem statement should work with an array of data.
  - There should be a dependency among the element while processing, i.e :
      for(int i=0; i<n; i++)           OR           for(int i=0; i<n; i++)
        for(int j=i; j<n; j++)                        for(int j=0; j<i; j++)

  In both the examples we see a dependency of the inner loop with the outer loop.
  In an array implimentation for every loop(i) we are running an inner loop(j) depending
  on the outer loop, but what if we could save the outcome of the outer loop by some
  precomputation and then linearly process the inner loop ?

  Stacks are used for preciesly this sort of applications.

  --------------------------- Problem Statement --------------------------------
  For a given elements in an array arr[] of size 'n' find the first value larger then the element arr[i]
  in the right hand side. Return -1 for the numbers that do not have a larger number on their right side.

------------------------------- Solving Approach -------------------------------
  Nieve Approach :
  1. Linearly Pick a number from arr[0] to arr[n-2]
  2. for every number arr[i] again run a linear search from arr[i+1] till arr[n-1] to find the firt occurance of a number
     larger than arr[i].

  Complexity : Polinomial. O(n^2)

  Stack Approach :
  1. Linearly insert the values in a stack starting from the right hand side (arr[n-1])
  2. The purpose of the stack is to keep the information of the larger element that comes AFTER the said element.
      - If the stack is empty then there is no element greater than the number that is being considered. (-1 case.)
  3. As your linear loop progresses (from step 1), keep comparing arr[i] to stack(top)
      - If stack(top) < arr[i] : discard stack top cuz it is not the bigger element for arr[i] but also for any number that comes
                                 after arr[i] (say arr[i-1]), stack(top) would'nt have been the answer for it anyway, it would have
                                 been arr[i] or any other greater number in the stack after stack(top).

      - If stack(top) >= arr[i] : Push arr[i] into the stack, it can be a possible larger value for the next element (arr[i-1])
  4. Every time you push an element in the stack, you've basically found your "next" largest element in stack(top) position unless
     stack is empty. Push that "next largest" in an auxilary array<vector>.
  5. At the end you'll have all the corresponding "next larger" elements in an auxilary array in reverse order.

  Note : The complexity in the case of non increasing array would still be O(n) since the element at each case would be poppd out only once.
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<int> arr;        // input array.
  vector<int> aux;       // array to store the corresponding next largest element.
  stack<int> st;         // stack to keep track of the next largest element.
  for(int i=0; i<n; i++)
  {
    int input;
    cin >> input;
    arr.push_back(input);
  }
  for(int i = n-1 ; i>=0; i--)  // starting from the back of the input stream.
  {
    int current = arr[i];       // current element in the input stream from the back.
    if(st.empty())              // if stack already empty there doesn't exist a higher value for current.
        aux.push_back(-1);
    else if(st.top() > current)  // if current top of stack has a value higher than the current elemet.
      aux.push_back(st.top());   // the higer element on the stack is the next higher for current and current is added to the stack.
    else if(st.top() <= current)
    {
      while(!st.empty() && st.top() <= current) // keep poping values from the stack till you find a bigger number or you run out of numbers.
        st.pop();
      if(st.empty())   // if you run out of stack elements, that means there were no elements greater than current.
        aux.push_back(-1);
      else
        aux.push_back(st.top());  // you've reached a stack element greater than current.
    }
    st.push(current);
  }
  for(int i=n-1; i>0; i--)    // since the output order is reversed, we again reverse the output stream to display the corresponding higher numbers.
    cout << aux[i] << " ";
  return 0;
}
