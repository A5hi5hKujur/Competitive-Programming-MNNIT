/*
---------------------------------- Problem Statement ---------------------------

In a given binary matrix find the maximum area rectangle produced by combining
consequtive 1s.

matrix :
             0  1  2  3
        0  | 0  1  1  0 |
        1  | 1  1  1  1 |
        2  | 1  1  1  1 |
        3  | 1  1  0  0 |

possible grids :
1. arr[0][1], arr[0][2], arr[1][1], arr[1][2], arr[2][1], arr[2][2] : area = 2 x 3 = 6
2. arr[0][1], arr[0][2] : area = 2 x 1 = 2
3. arr[0][1], arr[0][2], arr[1][1], arr[1][2] : area = 2 x 2 = 4
4. arr[1][0], arr[1][1], arr[1][2], arr[1][3] : area = 4 x 1 = 4
5. arr[1][0], arr[1][1], arr[1][2], arr[1][3]
   arr[2][0], arr[2][1], arr[2][2], arr[3][3] : area = 4 x 2 = 8
.
.
.

We observe that out of all these possible grids, grid no. 5 gives the most area, i.e, 8.

Variation of "Maximum Spread Area Probem"

-------------------------------- Solving Approach ------------------------------
The question is basically the "Largest Area of Histogram" question spead out in a
2D array instead of a 1D array.

If we were to convert this grid into a histogram problem, the solution is litrally the same.

1. Process individual rows :

row 0 : {0, 1, 1, 0}  -> Calculate max histogram -> row_area 0

  ADD LEVELS OF THE PREVIOUS ROW TO THE NEW FLOOR {1, 1, 1, 1}
row 1 : {1, 2, 2, 1}  -> Calculate max histogram -> row_area 1

  ADD LEVELS OF THE PREVIOUS ROW TO THE NEW FLOOR {1, 1, 1, 1}
row 2 : {2, 3, 3, 2}  -> Calculate max histogram -> row_area 2

   ADD LEVELS OF THE PREVIOUS ROW TO THE NEW FLOOR {1, 1, 0, 0}
row 3 : {3, 4, 0, 0}  -> Calculate max histogram -> row_area 3

Note : in row 3 when we encounter a '0' that suggests a discontinuity in the grid and therefore the
       chain gets resetted back to 0.

2. Find the maxium row_area out of all the obtained row areas.

*/
#include <bits/stdc++.h>
using namespace std;
void FSL(vector<int> arr, int fsl[], int n)
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
void FSR(vector<int> arr, int fsr[], int n)
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
int MAH(vector<int> arr)  // Maximum Area Histogram Function.
{
  int n = arr.size();
  int fsl[n], fsr[n];
  FSL(arr, fsl, n);
  FSR(arr, fsr, n);
  int max_area = INT_MIN;
  for(int i=0; i<n; i++)
  {
    int area = arr[i] * (fsr[i] - fsl[i] - 1);
    max_area = max(max_area, area);
  }
  return max_area;  // returns the maxiumum area of the row.
}
int main()
{
  int rows, columns;
  cin >> rows >> columns;
  int grid[rows][columns];
  for(int i=0; i<rows; i++)
    for(int j=0; j<columns; j++)
      cin >> grid[i][j];  // grid input.

  int max_grid_area = INT_MIN;  // variable to store the maxium area of a row.
  vector<int> current_row(columns, 0);  // initial row value.
  for(int i=0; i<rows; i++)
  {
      for(int j=0; j<columns; j++)
      {
        if(grid[i][j]  == 1)  // add coloumn value to the corresponding current_row column if there is a 1
          current_row[j] += grid[i][j];
        else
          current_row[j] = 0; // 0 represents a break in the grid.
      }
      int max_row_area = MAH(current_row);
      max_grid_area = max(max_grid_area, max_row_area); // find the maximum of areas of all the row areas.
  }
  cout << "The Maximum Grid Area : " << max_grid_area;
  return 0;
}
