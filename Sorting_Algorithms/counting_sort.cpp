/*
  COUNTING SORT : Algorithm that stable sorts the item if there are limited number of charecter occurances
                  in the unsorted array.

  Time Complexity : O(n+k) ; where n = unsorted array length
                                   k = limited number of charecter occurances.

  Eg : Assuming an unsorted list of 10^5 elements, where the elements comparise of 2,3,4.
       O(10^5 + 3)

  ------------------------------ Algorithm -------------------------------------
  eg : 4 3 4 4 3 2 4
  1. Make a cache to count the number of occurances of the elements.
        map[4]++;     map :    2  3  4
        map[3]++;    freq :    1  2  4
        map[2]++;

  2. Now we determine the position to start populating for each element.
      - Add the frequencies in the proper order accumalatively.
                    map :    2  3  4
                   sum :     1  3  7
      - Shift the sums to the right.
                map : 2  3  4
              shift : 0  1  3       <-- Starting indices for the rannge of numbers that occur
                                        in the sorted list.

  3. Make a new array of same size as the unsorted array, this wil house your sorted
     elements.

  4. Iterate throught the unsorted array, any number you encounter, check the starting position of
     that number from the cache and place that number in the auxilary array at the start position mentioned
     after which increment the start position of that corresponding element, which denotes the start position
     of the next occurance of the same number.s
*/
#include <bits/stdc++.h>
  using namespace std;

  int main()
  {
    map<int,int> cache;
    int n, k;  // n : length of unsorted array.   k : length of cache.
    cin >> n >> k;
    for(int i=0; i<k; i++)  // input cache
    {
      int input;
      cin >> input;
      cache.insert({input,0});
    }
    int arr[n];
    for(int i=0; i<n; i++) // input unsorted array.
    {
        cin >> arr[i];
        cache[arr[i]]++;  // frequency count.
    }

    // accumalatively sum;
    int sum = 0;
    for(auto itr = cache.begin(); itr != cache.end(); itr++)
    {
      itr -> second += sum;
      sum += itr -> second;
    }

    // right shift;
    for(auto itr = cache.rbegin(); itr!= cache.rend(); itr++)
      itr -> second = next(itr) -> second;

    // count sorting
    int sorted_arr[n];
    for(int i=0; i<n; i++)
    {
      sorted_arr[cache.at(arr[i])] = arr[i];  // starting position of the arr[i] element.
      cache.at(arr[i])++; // next starting position of the next occurance of the arr[i] element.
    }

    // display sorted_arr
    for(int i : sorted_arr)
        cout << i << " ";
    return 0;
  }
