/*
---------------------------- PROBLEM STATMENT ----------------------------------
Consider an array that stores the hight of the histogram :
arr = {6, 2, 5, 4, 5, 1, 6, 3, 1, 4, 1}

graphical representation :

   6                           6
 ____--------5---------5----- ____
|   |     ____  4   ____     |   |            4
|   |    |   | ____|   |     |   |---3------ ____
|   |  2 |   ||   ||   |     |   | ____     |   |
|   | ___|   ||   ||   |  1  |   ||   |  1  |   |  1
|   ||  ||   ||   ||   | ____|   ||   | ____|   | ____
|   ||  ||   ||   ||   ||   ||   ||   ||   ||   ||   |
------------------------------------------------------
  0    1   2    3    4    5    6    7   8    9    10

Now Imagine someone spilled water all over it, you have to calculate the area
of water trapped between the histogram.

In this case water is trappd between (arr[0] and arr[6]) && (arr[6] and arr[9]) .
Water cannot be stored in any other crevese without spilling out.

Total water stored :
arr[0] = 0 unit of water.
arr[1] = 4 unit of water.
arr[2] = 1 unit of water.
arr[3] = 2 unit of water.
arr[4] = 1 unit of water.     Total water : 0 + 4 + 1 + 2 + 1 + 5
arr[5] = 5 unit of water.                  0 + 1 + 3 + 0 + 0 = 17 units
arr[6] = 0 unit of water.
arr[7] = 1 unit of water.
arr[8] = 3 unit of water.
arr[9] = 0 unit of water.
arr[10] = 0 unit of water.


----------------------------- SOLVING APPROACH ---------------------------------

Observations :
1. Water can only be trapped between bars of same height or greater.
2. Any bars submerged under water have (water_level - arr[i]) unit of water above it.
3. Water level above a perticular bar(arr[i]) depends upon the maximum height bar to the left
   and maximum bar to the right (whichever is smller out of both).
4. Any bars not submerged in water have 0 units of water above it.
5. Max water level for a perticular bar depends on the largest bar in the right and
   the largest bar on the left.

Algorithm :
1. Find the maximum bar to the left of an element.
2. Find the maximum bar to the right of the element.
3. Summation of : min(left_max, right_max) - arr[i].

Complexity : O(N x 3)
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for(int i=0; i<n; i++)
        cin >> arr[i];                // Input Stream

    int left_max[n], right_max[n];    // array to store the element's left maximum height bar and right maximum height bar.
    int left = arr[0], right = arr[n-1]; // variables to save the height of the right most bar and the left most bar.

    for(int i=0; i<n; i++)            // starting from the left we populate the array that contains current bar's respective max left height bar.
    {
        left = max(left, arr[i]);     // left stores the maximum height at each iteration, by comparing current bar with whatever is max at the time, staring from the leftmost element.
        left_max[i] = left;           // that value will be stored in left_max array for each bar.
    }
    for(int i=n-1; i>=0; i--)         // starting from the right we populte the array that contains current bar's respective max right height bar.
    {
        right = max(right, arr[i]);
        right_max[i] = right;
    }
    int water_area = 0;               // summation of total water trapped
    for(int i=0; i<n; i++)
    {
        water_area += min(left_max[i], right_max[i]) - arr[i]; // water level above each bar is the water level trapped - the height of the current bar itself.
    }
    cout << "Total area of water trapped : " << water_area;
}
