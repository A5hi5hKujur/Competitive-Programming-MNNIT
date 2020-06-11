/*
  Find an element in an infinitly sorted array.

  -------------------------- Problem Statement ---------------------------------
  Disclaimer : This problem will not be asked in any coding platform rather, it
  may be asked during a technial interview, since it provides a new prospective
  on Binary Search algorithm.

  As I mentioned earlier, it is impossible to ask this question in a coding
  platform since they have a certain limit on the array size (arr[10^7]).
  This problem aims to find a solution for a sub problem. i.e,
  "How do you allocate an upperbound limit to your search range if your search
  range is limitless ?"

--------------------------- Solving Approach -----------------------------------
Since all we are aware of is :
1. The starting index of the array (lower bound of the search range), 'low'.
2. The element to be searched, 'mid'.

The process of finding 'high' becomes an ongoing process before finding the
element itself.
1. Start range with low = 0 and high = 1.
2. If the element isn't in that range, move the new position of low = high.
                                       move the new position of high = 2 x high.

  By moving high twice the index value we ensure our time complexity to be around O(log n)
  incrementing it at any higher rate will increment the search time of the actual element
  exponentially, therefore moving 2x high seems to be an optimum pace.

3. We stop moving the range as soon as the value of 'high' exceeds the value to be seached.
  This means if our element exists in an infinitly sorted array, the element will exist within
  this LIMITED range(Sliding Window Problem, sort of).

4. Once we find the range, we apply binary search on that range.
*/

/*
  FUNCTION DESCRIPTION :
  The function "infinitlySorted()", takes an infinitly sorted vector "arr" and the element to
  be searched in the array "search" and returns the index of the element if found or -1 if the
  element is not found.
*/
int infinitlySorted(vector<int> arr, int search)
{
  int low = 0;
  int high = 1;
  while(search < arr[high])
  {
    low = high;
    high *= 2;
  }
  return binarySearch(low, high, search);
}
