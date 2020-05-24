/*
Finding factors of a number through sieve of eratosthenes (precomputation approach)
 - Create a map(array) that stores the smallest factor of the number (index values represent number)
  1. Create an array of size 'n' and initialize its individual cells with its corresponding index value.
     The idea is to mark each number as prime initially(their smallest factor is themselves), the sieve approach.
  2. Using the sieve of eratosthenes algorithm, assign individual cellblocks of the array with its smallest prime factor.

 - Accept multple queries.
 - Factorization of multiple queries :
  1. run loop till the number becomes 1, i.e, no factors remaining.
  2. if number at the cell = number at the index, the number is prime and cannot be further factorized.
  3. if number at the cell != number at the index, the cell value is the minimum factor of index number.
  4. Divide the number by the cell value and lookup the next cell (arr[n/arr[n]]).
*/
#include <bits/stdc++.h>
using namespace std;
vector<int> numb;     // sieve map
void Sieve(int n)
{
    for(int i=2; i <= sqrt(n); i++)
      for(int j = i*i; j <= n; j += i)
        numb[j] = i;    // using sieve to assign smallest factor 'i' to 'j's. (where j are all the numbers in range n)
}
void Factorization(int n)
{
    while(n != 1) // keep looking up factors of 'n' till there are no factors left.
    {
        if(numb[n] == n) cout << n << " ";  // if index = arr[index] ; The number is prime and it is the smallest factor.
        else cout << numb[n] << " ";        // else arr[index] is the smallest factor of index number (n).
        n /= numb[n];                       // divide the number by its smallest factor and continue the process.
    }
}
int main()
{
    int n;
    cin >> n;
    for(int i=0; i<=n; i++) numb.push_back(i);  // all prime numbers will have themselves as minimum factor.
    Sieve(n);
    int q;
    cin >> q;
    while(q--)
    {
        int input;
        cin >> input;
        Factorization(input);
        cout << "\n";
    }
    return 0;
}
