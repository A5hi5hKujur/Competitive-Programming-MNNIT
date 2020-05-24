/*
  Prime No Factors : 1  x itself.
  Composite no. factors : prime no. x prime no. x prime no. x ...

  Note  : 1 and 0 are neither prime nor composite.
  Prime Factorization : breaking down the number into the multiples of smallest prime factors.
                        eg : 10 = 2 x 5
                             8  = 2 x 2 x 2

  Number Theory : If N is a composite number then there is at least 1 prime number divisor of N
                  below sqrt(N).

                  which means all the factors of N will come before sqrt(N).

  Time Complexity : O(sqrt(n)).
*/

#include <bits/stdc++.h>
using namespace std;

void primeFactors(int n)
{
  for(int i=2; i<= sqrt(n); i++)  // searching prime factors for 'n' starting from 2.
  {
    if(n % i == 0) // if you find a prime factor. (i)
    {
      int power = 0;
      while(n % i == 0) // while n is divisible by i
      {
        n /= i; // keep dividing n by i.
        power++;  // increment power everytime you divide.
      }
      cout << i << "^" << power << "\n";
    }
  }     // if 'n' were a Composite no. it would have been diminished to 1 by this point.
  if(n > 1) // if 'n' was prime to begin with(smallest prime is 2), it will remain unchanged.
  {
    cout << n << "^" << 1 << "\n";
  }
}
int main()
{
  int n;
  cin >> n;
  primeFactors(n);
}
