/*
  Binomial Coefficient : The binomial coefficient is the number of ways of picking
  unordered outcomes from possibilities, also known as a combination or combinatorial number

  Formula :     n!
            ----------
            r! x (n-r)!

  Since factorial calculations lead to extremly large numbers we use modulo operation to avoid
  overflow of the data type.

  modulo Formula :       n! % N
                   --------------------
                   n! % N  x (n-r)! % N

  converted modulo Formula :
            n! % N  x inv(n! % N) % N x inv((n-r)! % N) % N         where, inv() : inverse function.

  */
  #include <bits/stdc++.h>
  using namespace std;
// Precompute modulo factorials.

  int main()
  {
    int n, r, m;
    cin >> n >> r >> m;
    binomial(n, r, m)
    return 0;
  }
