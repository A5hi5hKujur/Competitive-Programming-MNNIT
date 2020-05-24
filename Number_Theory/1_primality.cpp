/*
primality : Check if the inputted number is prime or not.
Nieve Approach :
  - input a number.
  - run a loop from 2 to n-1 to see if any number within this range completely
    divides the inputted number.
  - If any one number between 2 to n-1 divides n completely, we say that 'n' is
    not a prime number. Otherwise it is a prime number.

Problem of Nieve Approach :
  Time Complexity O(n)

--------------------------------------------------------------------------------
Better Approach :
  Number Theory :
      For a given number n = 12. its factors are made up of pairs (p1, p2).
                                  such that p1 <= sqrt(n) and p2 > sqrt(n).
      factors of 12 = 1, 2, 3, 4, 6, 12
      pairs :
      (1,12) = 1 x 12 = 12
      (2,6)  = 2 x 6  = 12
      (3,4)  = 3 x 4  = 12

      where sqrt(12) = floor(3)

      CONCLUSION : basically if you cant find a factor of a number before sqrt(n)
                   you will NEVER find one after sqrt(n).

  - instead of running your loop till n-1 run it till sqrt(n).
  - Time Complexity O(sqrt(N)).
--------------------------------------------------------------------------------
 */
#include <bits/stdc++.h>
using namespace std;

bool primality(int n);
{
  for(int i=2; i<= sqrt(n); i++)
  {
    if(n % i == 0) return false;
  }
  return true;
}
int main()
{
  int n;
  cin >> n;
  if(primality(n)) cout << n << " is prime.";
  else cout << n << " is not prime.";
  return 0;
}
