/*
    Find Ceil of an element (Just bigger element) :
      - Search the smallest element bigger than the key value.
      - If Key value needs to be present in order to find the Ceil value.
*/
#include <bits/stdc++.h>
using namespace std;

int justBigger(vector<int> arr, int search)
{
    int ans_indx = -1;      // indexes to store every possible Ceil element.
    int high = arr.size() - 1;
    int low = 0;
    while(low <= high)
    {
        int mid = low + (high - low)/2;
        if(arr[mid] > search)  // if element is greater than key,
        {
            ans_indx = mid; // update it as possible answer (because it is sorted array you dont need to check for min)
            high = mid - 1; // shrink search range from the right.
        }
        else if(arr[mid] <= search) // if element is smaller than or equal to key.
        {
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
    int index = justBigger(arr, search);
    if(index == -1) cout << "A bigger number does not exist";
    else cout << "index of Ceil of " << search << " is " << index;
    return 0;
}
