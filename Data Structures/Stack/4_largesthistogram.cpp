/*
  --------------------------- Problem Statement --------------------------------
  Consider an array that stores the hight of the histogram :
  arr = {6, 2, 5, 4, 5, 1, 6}

  graphical representation :

  6                            6
 ____      5         5        ____
|   |     ____  4   ____     |   |
|   |    |   | ____|   |     |   |
|   |  2 |   ||   ||   |     |   |
|   | ___|   ||   ||   |  1  |   |
|   ||  ||   ||   ||   | ____|   |
|   ||  ||   ||   ||   ||   ||   |
---------------------------------
  0    1   2    3    4    5    6

We have to find the largest area of the histogram, which can be :
1. Ether a single tallest bar.
2. Or a combination of consequtive neigh-bars of similar height.

eg : 1. arr[0] = 6 x 1 = 6  ; by taking a single bar of height 6.
     2. arr[0] + arr[1] + arr[2] + arr[3] + arr[4] = 5 x 2 = 10 : by taking 5 bars of height 2.
     3. arr[0] + arr[1] + arr[2] + arr[3] + arr[4] + arr[5] = 6 x 1 : by takig 6 bars of height 1.
     4. arr[2] + arr[3] + arr[4] = 3 x 4 = 12 : by taking 3 bars of height 4.

--------------------------- Solving approach -----------------------------------
1. find index of "first smaller left" element of the current element. (FSL)
2. find index of "first smaller right" element of the current element. (FSR)
3. find the difference of those indices and that would be the maximum consequtive width w.r.t the current element.
eg : current(arr[3]) : FSL = arr[1] = 2
                       FSR = arr[5] = 1
                       (5 - 1) - 1 = 3           (the extra -1 is to remove the edge bar arr[5])
               area = current x 3 = 12.
4. Keep saving the area and comparing it with max element as you process each bar.

Note : if(FSL of an element not found then)
        FSR - (-1)
       if(FSR of an element not found then)
        n - FSL

Complexity : O(N x 4)
*/
#include<bits/stdc++.h>
using namespace std;

void FSR(int arr[], int fsr[], int n)   // function to find index of corresponding "first smaller element to the right" of all elements arr[i].
{
    stack<int> st;
    for(int i=n-1; i>=0; i--)           // starting the iteraction from the right of the input stream.
    {
      if(st.empty())                    // if stack is empty; there are no elements smaller than arr[i] in the right.
        fsr[i] = n;                     // index of the right out of bound.
      else if(arr[st.top()] < arr[i])   // if topmost element of the stack is less than current element
        fsr[i] = st.top();              // you've found the index of the first smallest to the right element.
      else if(arr[st.top()] >= arr[i]) // if the topmost element of the stack is more or equal than the current element
      {
        while(!st.empty() && arr[st.top()] >= arr[i]) // traverse to find the smaller element on the right until either you find it or exhaust the stack
          st.pop();
        if(st.empty())                // if you exhaust the stack that would mean that there is no smaller element to the right side of the current element.
          fsr[i] = n;                 // return the right bound element.
        else
          fsr[i] = st.top();          // else return the index of the the smaller element that you found.
      }
      st.push(i);                     // push current element index into the stack.
    }
}
void FSL(int arr[], int fsl[], int n) // function to find the index of corresponding "first smaller elenent to the left" of all elements arr[i].
{
  stack<int> st;
  for(int i=0; i<n; i++)              // start from the left side of the input stream.
  {
    if(st.empty())                    // if there is no index of element in stack that means there is no elements smaller than arr[i] in the left.
      fsl[i] = -1;                    // return the left bound index.
    else if(arr[st.top()] < arr[i])   // if stack top has the index of an element, smaller than the current element.
      fsl[i] = st.top();              // return the index of the stack top element.
    else if(arr[st.top()] >= arr[i])  // if you encounter an element that is higher or equal to the current element.
    {
      while(!st.empty() && arr[st.top()] >= arr[i]) // traverse stack until you either exhaust it or find an element that is smaller than the current element
        st.pop();
      if(st.empty())                  // if there is no index of element in stack that means there is no elements smaller than arr[i] in the left.
        fsl[i] = -1;                  // return the left bound index.
      else
        fsl[i] = st.top();            // You've found the smaller element, return the index of the stack top element.
    }
    st.push(i);                       // push each index into the stack.
  }
}
int main()
{
  int n;
  cin >> n;
  int arr[n];
  for(int i=0; i<n; i++)
    cin >> arr[i];              // input stream
  int fsr[n];                   // array to store index of "first smaller right" element of all arr[i]
  int fsl[n];                   // array to store index of "first smaller left" element of all arr[i]
  FSR(arr, fsr, n);             // function to populate fsr[]
  FSL(arr, fsl, n);             // function to populate fsl[]

  int max_area = INT_MIN;      // variable to store maximum area
  for(int i=0; i<n; i++)
  {
    int current_block = arr[i];     // height of the rectangle arr[i]
    int difference = (fsr[i] - fsl[i]) - 1;   // width of the rectangle arr[i]
    int current_area = current_block * difference;   // area of the rectangle arr[i]
    max_area = max(max_area, current_area); // storing the max area in each iteration.
  }
  cout << "Maximum Area of the Histogram : " << max_area;
  return 0;
}
