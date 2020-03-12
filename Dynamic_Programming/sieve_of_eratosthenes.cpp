/*
  Algorithm to find out all the prime numbers in a given range(2 to n).
  Input : n
  Algorithm :
  1. Take a boolean array of n+1 size to check all the numbers that fall before 'n'.
  2. Initially mark all the numbers as prime (true).
  3. Linearly move one by one to the elements which are marked prime uptill sqrt(n).
      - Once you find a number which is marked prime you mark all of its multiples
        as non-prime(false) until u reach the end (n).

  Is this a Dynamic Approach ??
  We could think of the Sieve of Eratosthenes as an example of dynamic programming.
  The subproblems would be all the composite numbers. Skipping over marked numbers
  is a perfect demonstration of the subproblems overlapping since if they did not
  overlap we wouldn't be skipping over them.
*/
#include <bits/stdc++.h>
using namespace std;
void Sieve(int n)
{
  vector<bool> prime(n+1, true);  // boolean array which initializes all the numbers true.
  // we start with 2 since its the first prime number.
  // we further reduce computation by running the loop till sqrt(n) instead of n.
  for(int p = 2; p <= sqrt(n); p++)
  {
    if(prime[p] == true)  // skip the numbers which are not marked 'true' (prime).
    {
      for(int i=p*p; i<=n; i += p)  // this unmarking prime process runs till nth number but skipping values(1/2 + 1/3 + 1/5 +....)
      {
        prime[i] = false; // marking all the multiples of 'p' as 'false' (not prime).
      }
    }
  }
  // print all the numbers which remain marked prime
  cout << "List of prime numbers within the range 2 to " << n <<" :" << endl;
  for(int i=2; i<=n; i++)
  {
    if(prime[i]) cout << i << " ";
  }
}
int main()
{
  int n;
  cout << "Enter the number upto which you want to generate your prime. : ";
  cin >> n;
  Sieve(n);
  return 0;
}
