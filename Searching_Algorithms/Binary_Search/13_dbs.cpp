/*
  DISCREATE BINARY SEARCH / SOLVING OPTIMIZATION PROBLEM THROUGH BINARY SEARCH :
  Link : https://www.topcoder.com/community/competitive-programming/tutorials/binary-search/

  Binary Search if you think about it is already an optimization problem, if you see it from a
  broader prospective. Let me explain,
    The algorithm works with 3 main variable :
    1. low : The lower bound of the search space.
    2. high : The higher bound of the search space.
    3. mid : possible answer, if not the deciding factor of your next search space.

  Here we are given a search element or 'key' that we have to find in a sorted search space.
  we can consider a key to be the best most optimal solution of the problem that we have to
  find in our givien search space for a more broader problem. In this case we know about the
  key a.k.a the best possible sol. of the problem before hand in order to do a binary search and compare.
  Binary Search becomes merely a tool to solve a sub-problem without even knowing about the real problem.
  Its more of a,"Ok cool you want to find the number 5034 ? ok cool let me CHECK"
  but what if it was,"Wait, WHY do you want me to find the number 5034 ?"

  USING BINARY SEARCH TO SOLVE A PREPOSITIONAL PROBLEM INSTEAD OF JUST CHECKING THE EXISTANCE OF AN ANSWER.
  In a nutshell Discreate binary search is a technique to find the best possible solution of a problem by selecting all
  possible answers from a range of plausible answers for the problem, and picking the best most optimized solution.

  lets break it down into steps and compare it with the binary search we know and love :
  1. low : determine the lowest possible answer of a problem.
  2. high : determine the highest possible answer of a problem.
  3. mid : possible optimized answer to be "checked" if it satisfies the problem constraints.


  ans = low/high (whichever default value is appropriate)
  while(low <= high)
  {
    int mid = high + low / 2
    if(checkAns(mid))          // This function verifies whether "mid" qualifies as a possible answer.
    {
      ans = mid;              // if yes, we move towards a more less favorable range to find a more "unconventional" but "optimized" answer.
      low = mid+1             // mid-1 (depending upon maximization / minimization)
    }
    else                    // if no, we pussy out and move towards a range more "forgivable" with a higher chance of finding an answer.
      high = mid-1          // mid+1 (depending upon maximization / minimization)
  }
  return ans;               // final answer after the exhausting the list.

  NOTE : The "possible outcomes" would be arranged in an order.

  Basically, The algorithm is fairly simple :
  1. analyze your problem.
  2. Think of the lowest and highest possible solution to your problem
  3. Pick a possible solution to the problem as mid
  4. Run it in your solution function to check if that answer satisfies your problem constraints COMPLETELY
  5. If yes, save the answer and move to a range above that.
     If no, move to a range under that.
  6. Repeat the process till the list gets exhausted in O(logn x however long that checkAns() function takes) time.


  HOW TO IDNTIFY IF THE PROBLEM CAN BE SOLVED WITH DESCREATE BINARY SEARCH.
  1. given array which may or may not be sorted.
  2. Problem phrase like "minimize the maximum" or "maximize the minimum".
  3. There would be a "k" value among which the problem needs to be divided.

  eg : painters problem, page allocating problem etc etc.

  -------------------------------------------------- PROBLEM STATEMENT --------------------------------------------------------
  Given an array of integers arr of size n and an integer m where n is the number of boxes (weight of the box is arr[i]) and m is
  the number of workers.

  You have to give boxes to the workers such that:-

    A particular box is given only to one worker.
    Every worker must be given at least one box.
    Only contiguous boxes are given to a worker i.e., for example, a particular worker can be given box number 1, 2 and 3 but not 1, 5 and 7.
    The maximum total weight given to a worker is minimum (check explanation of sample input and output for more clarification).
*/
#include<bits/stdc++.h>
using namespace std;
/*
  Function to check if the given weight can be distributed "efficiently" throughout
  "m" people.
  Here, efficently means m people should carray the least amount of weight while carrying
  most items.

  Parameters :
  1. The array of weights sorted in ascending order.
  2. weight : The possible minimum weight that could be the answer.
  3. people : The number of people required to carry the load.

  Return Type : True / False, depending upon if the given weight is completely
                distributed throughout the given number of people.
*/
bool weight(vector<int> arr, int weight, int people)
{
  int n = arr.size();
  int sum = 0;            // initial starting weight.
  people -= 1;           // The first person starts carrying weights
  for(int i=0; i<n; i++)  // linearly start adding up weights, starting from the least weight.
  {
    sum += arr[i];        // accumalated weight for a single person.
    if(sum > weight)      // as soon as the person goes over the optimal weight.
    {
      people--;           // the next person carries it
      sum = arr[i];       //  with a starting item that went over the weight limit.
    }
  }
  if(people == 0)         // if the weight has been distributed through all people.
    return true;          // selected "weight" could be a possible outcome of the problem.
  else return false;      // selected "weight" can not be a possible outcome of the problem.
}

int main()
{
  int n, m;
  cin >> n >> m;
  vector<int> arr(n);
  int total_weight = 0;
  for(int i=0; i<n; i++)
  {
    cin >> arr[i];
    total_weight += arr[i];     // maximum possible weight carried by a single person.
  }
  int ans = total_weight;       // The edge case where a single person carries all the items.
  sort(arr.begin(), arr.end());
  int low = arr[n-1];           // When a single person carries the maximum weight items. (best case)
  int high = total_weight;      // When a single person carries all the items. (worst case)
  while(low <= high)            // The optimal answer will lie in between those cases(cases inclusive)
  {
    int mid = low + (high - low)/2; // possible answer
    if(weight(arr, mid, m))       // check if the given weight satisfies the condition.
    {
      ans = mid;                // Save the possible weight.
      high = mid - 1;           // Now we move towards an even smaller weight(minimize) to check for the posibility to satisfy the condition with a smaller mid value.
    }
    else                        // If the "mid" weight doesn't satisy the given condition.
      low = mid + 1;            //  We move towards a higher weight(maximize) to check for higher possible mid weight to be the answer.
  }
  cout << ans;
  return 0;
}
