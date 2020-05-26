/*
Fermat's Little Theorem : Finding modulo multiplicative inverse in Log n time.

- Do all number have modulo inverse ?
No, in order to find modulo inverse of 'a' under modulo 'N' check if GCD(a, N) = 1. (co-prime, dont share any prime divisor.)

- Fermat's little theorm to find modulo multiplicative inverse :
  conditions :
    1. In ( a / b ) % N  ; N should be a prime.
    2. In order to solve the above expression, (a / b) needs to be converted to (a x B).
       Where B is modulo multiplicative inverse of 'b'.
       'b' and 'N' should be co-primes.

 Formula : b^N-2 ~= B    (B = modulo multiplicative inverse of 'b')

 check answer :
  4 ~= 2 (mod 7)
  4 x 2 = 8.
  8 % 7 = 1 (property of modulo multiplicative inverse (a x A) % N = 1 ; where 'A' is mmi of 'a') 
*/
#include <bits/stdc++.h>
using namespace std;
int fastExpo(int b, int n, int m)
{
  if(n == 1) return b;
  if(n == 0) return 1;
  int res = fastExpo(b, n/2, m);
  if(n % 2 == 0) return ((res % m) * (res % m)) % m;
  else return ((res % m) * (res % m) * (b % m)) % m;
}
int main()
{
  int b, n;
  cin >> b >> n;
  cout << b << "^-1 = " << fastExpo(b, n-2, n);
}
