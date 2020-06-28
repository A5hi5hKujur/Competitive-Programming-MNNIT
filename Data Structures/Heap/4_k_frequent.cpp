/*
  On a given array, find the element with kth most frequency.
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n,k;
  cin >> n >> k;
  unordered_map<int, int> mp;
  priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> min_heap;
  for(int i=0; i<n; i++)
  {
      int input;
      cin >> input;
      mp[input]++;  // save frequency in a map
  }
  for(auto itr = mp.begin(); itr != mp.end(); itr++)
  {
    min_heap.push({itr->second, itr->first}); // push the number along with the frequency, where frequency is the key.
    if(min_heap.size() > k)
      min_heap.pop();
  }
  cout << min_heap.top().second << " ";
  return 0;
}
