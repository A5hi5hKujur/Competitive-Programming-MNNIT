/*
  GCD : Greatest Common Divisor.
  If GCD(a,b) = 1; a,b is said to be co-prime.
  Which means a,b themselves are not prime but there exists no common divisor among them except 1.

  A key advantage of the Eucleadian Algorithm is that it can find the GCD efficiently without having to compute the prime factors.

  gcd(a,b,c) = gcd(a,gcd(b,c)) and so on...

  The algorithm is derived from the property :
  gcd(a,b) = gcd(a = a-b, b) (until a < b)
*/
#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
  if(b == 0) return a;
  return gcd(b, a%b);
}
int main()
{
  int a,b;
  cin >> a >> b;
  cout << gcd(a,b);
  return 0;
}
