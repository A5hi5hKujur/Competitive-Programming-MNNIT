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
*/
#include<bits/stdc++.h>
using namespace std;

void FSR(int arr[], int fsr[], int n)
{
    stack<int> st;
    for(int i=n-1; i>=0; i--)
    {
      if(st.empty())
        fsr[i] = n;
      else if(arr[st.top()] < arr[i])
        fsr[i] = st.top();
      else if(arr[st.top()] >= arr[i])
      {
        while(!st.empty() && arr[st.top()] >= arr[i])
          st.pop();
        if(st.empty())
          fsr[i] = n;
        else
          fsr[i] = st.top();
      }
      st.push(i);
    }
}
void FSL(int arr[], int fsl[], int n)
{
  stack<int> st;
  for(int i=0; i<n; i++)
  {
    if(st.empty())
      fsl[i] = -1;
    else if(arr[st.top()] < arr[i])
      fsl[i] = st.top();
    else if(arr[st.top()] >= arr[i])
    {
      while(!st.empty() && arr[st.top()] >= arr[i])
        st.pop();
      if(st.empty())
        fsl[i] = -1;
      else
        fsl[i] = st.top();
    }
    st.push(i);
  }
}
int main()
{
  int n;
  cin >> n;
  int arr[n];
  for(int i=0; i<n; i++)
    cin >> arr[i];
  int fsr[n];
  int fsl[n];
  FSR(arr, fsr, n);
  FSL(arr, fsl, n);

  int max_area = INT_MIN;
  for(int i=0; i<n; i++)
  {
    int current_block = arr[i];
    int difference = (fsr[i] - fsl[i]) - 1;
    int current_area = current_block * difference;
    max_area = max(max_area, current_area);
  }
  cout << "Maximum Area of the Histogram : " << max_area;
  return 0;
}
