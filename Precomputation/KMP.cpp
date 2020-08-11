/*
KMP Algorithm for Pattern Searching : Searh for a pattern 'x' in string 's' where
length of the pattern 'x' can be smaller or equal to the length of the string 's'.

Example : String  : THIS IS A TEST TEXT
          Pattern : TEST

          Output : 10 (pattern was found in index 10)

  KMP Algorithm is a 2 step process :
  1. Generate the KMP index array, i.e an array that keeps track of
    the continuity of the pattern w.r.t similarities between the pattern's prefix and
    sufix at every step.(how similar is the front of the pattern from the back)

  2. Based on the KMP array traverse the string for pattern matching.


  STEPS TO GENERATE KMP INDEX ARRAY :
  1. Create an array of pattern length and start scanning the pattern with 2 pointers
    - pointer 1 : j       <--- bi-directional pointer
    - pointer 2 : i       <--- uni-directional pointer (left to right)
    - assign arr[0] = j

  2. if the charecters at pattern[i] == pattern[j]
      arr[i] = j+1  ; there is a pattern match uptill index 'i'
      - increment i
      - increment j

  3. if the charecters did not match ; send j to the place where the charecters last matched
      j = arr[j-1] and compare again.

      - if during this backtracking j = 0, then j cannot backup any further
        meaning if the match fails at the ith point, the pattern matching would start
        from the begining

        arr[i] = j ; increment i.

  4. Repeat Steps 2 to 3 until i reaches end of pattern.

  PATTERN MATCHING STEPS :
  1. Take 2 pointers one for the string 'i'.      (uni-directional)
                     one for the pattern 'j'.     (bi-directional)

      Note : 'i' runs till the string gets exhausted and 'j' runs till all the
              charecters in the pattern are a match.

  2. If string[i] == pattern[j]
    - increment 'i' and 'j'.

  3. If charecters do not match then go to the last place where the patterns match.
     j = arr[j-1] and compare again.

     - if during this backtracking j = 0, then j cannot backup any further
       meaning if the match fails at the ith point, the pattern matching would start
       from the begining

       arr[i] = j ; increment i.

  4. Repeat step 2 and 3 until either the pattern match or the string is exhausted.

  5. If j == pattern length ; there has been a pattern match.

    i - pattern length = index of pattern start.

    If the string is not exhausted, reset to the starting position of the
    KMP array to continue the process (Step 2 - Step 3)
*/


#include<bits/stdc++.h>
using namespace std;
vector<int> pattern_arr;
void kmpPattern(string pattern)     // STEP 1 : Create KMP index array.
{
    int n = pattern.length();
    vector<int> arr(n);
    int j=0;
    int i = 1;
    arr[0] = j;
    while(i<n)        // iterate pattern string.
    {
        if(pattern.at(j) == pattern.at(i))  // if charecters match.
        {
            arr[i] = j + 1; // update the index where the charecters matched.
            j++;
            i++;
        }
        else  // go to the last poistion and where the charecters matched and check again.
        {
            if(j != 0)    // if you've not backtracked all the way to the start.
                j = arr[j-1]; // position of the last matched.
            else
            {
                arr[i] = 0;   // starting position
                i++;
            }
        }
    }
    pattern_arr = arr;
}
void substringSearch(string str, string pattern)
{
    int i = 0;
    int j = 0;
    int n = str.length();
    int m = pattern.length();

    int match = 0;
    while(i < n && j < m) // until the pattern or the string is exhausted.
    {
        if(str.at(i) == pattern.at(j)) // when pattern matched.
        {
            i++;
            j++;
        }
        else  // when patterns dont match
        {
            if(j!=0)  // go to the last place where a match occured
                j = pattern_arr[j-1];
            else
                i++;
        }
    }
    match = i - m;
    if(j == m)
        cout << match;
    else
        cout << "not found";

}
int main()
{
    string pattern;
    pattern = "abcaby";
    string str;
    str = "abxabcabcaby";
    kmpPattern(pattern);
    substringSearch(str, pattern);
    return 0;
}
