/*
  Spiral Traversal(clockwise) :
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int r,c;
    cin >> r >> c;
    int grid[r][c];
    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++)
            cin >> grid[i][j];

    int top = 0;        // initial top pointer, topmost row.
    int down = (r-1);   // initial down pointer, bottomost row.
    int left = 0;       // initial left pointer, leftmost column.
    int right = (c-1);  // initial right pointer, rightmost column.

    int dir = 0;  // starting direction
    /*
      (Clockwise)
      dir = 0 : left to right. (on topmost row)
      dir = 1 : top to bottom. (on leftmost column)
      dir = 2 : right to left. (on bottomost row)
      dir = 3 : bottom to top. (on rightmost column)

      (Anti Clockwise)
      dir = 0 : top to bottom (on leftmost column)
      dir = 1 : left to right (on bottomost row)
      dir = 2 : bottom to top (on rightmost column)
      dir = 3 : right to left (on topmost row)
    */
    while(top <= down && left <= right)       // while all the pointers are within their range.
    {
        if(dir == 0)                          // traverse left to right.
        {
            for(int i=left; i<= right; i++)   // start from left, move to right.
                cout << grid[top][i] << " ";  // traverse in the topmost row.
            top++;                            // shift top one place down (visually)
        }
        else if(dir == 1)                       // traverse top to bottom.
        {
            for(int i = top; i<=down; i++)      // start from top, move to down.
                cout << grid[i][right] << " ";  // traverse in the rightmost column.
            right--;                            // shift right one place left. (visually)
        }
        else if(dir == 2)                       // traverse right to left.
        {
            for(int i=right; i>=left; i--)      // start from right, move to left.
                cout << grid[down][i] << " ";   // traverse in the bottommost row.
            down--;                             // shift bottom one place up. (visually)
        }
        else if(dir == 3)                       // traverse down to top.
        {
            for(int i=down; i>=top; i--)        // start from down, move to top.
                cout << grid[i][left] << " ";   // traverse in the leftmost row.
            left++;                             // shift left one place right. (visually)
        }
        dir = (dir + 1) % 4;                    // next direction.
    }
    return 0;
}
