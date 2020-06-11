/*
    Find Floor of an element (Just smaller element) :
      - Search the greatest element smaller than the key value.
      - If Key value needs to be present in order to find the floor value.

    This question can also be framed as find the element with least absolute difference
    from the search element.
*/
#include <bits/stdc++.h>
using namespace std;

int justSmaller(vector<int> arr, int search)
{
    int ans_indx = -1;      // indexes to store every possible floor element.
    int high = arr.size() - 1;
    int low = 0;
    while(low <= high)
    {
        int mid = low + (high - low)/2;
        if(arr[mid] >= search)  // if element is greater than or equal to key,
        {
            high = mid - 1; // shrink search range from the right.
        }
        else if(arr[mid] < search) // if element is smaller than key
        {
            ans_indx = mid; // update it as possible answer (because it is sorted array you dont need to check for max)
            low = mid + 1; //  shrink the search range from the left since the next greater value would lie towards the right.
        }
    }
    return ans_indx;
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr;
    while(n--)
    {
        int input;
        cin >> input;
        arr.push_back(input);
    }
    int search;
    cin >> search;
    // Run binary search to see if the element exists in the first place,
    // If not then straight away print, element doesn't exist.
    int index = justSmaller(arr, search);
    if(index == -1) cout << "A smaller number does not exist";
    else cout << "index of floor of " << search << " is " << index;
    return 0;
}
