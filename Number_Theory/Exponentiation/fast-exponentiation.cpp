/*
  Fast Exponentiation / Binary Exponentiation : Finding value of a^b. where a and b is provided as input.

  Nieve Approach : a^b = a x a x a x a x .... x a (b times). Time Complexity : O(n)

  Better Approach :
    a^b = a x a x a x ..      a x a x a x ..
            b/2                  b/2            (when b is even)
            R1        x           R2                (R1 = R2)
  The problem can be recursively divided into smaller subproblems(b/2, b/4, b/8, ..), i.e 2 identical parts
  R1 and R2, we can simple find R1 and multiply the result with itself.

    a^b = a x a x a x ..  x a x   .. a x a x a x ..
            b/2                         b/2            (when b is odd)
            R1           x a x          R2                (R1 = R2)

    Time Complexity : O(log n)

*/
#include <bits/stdc++.h>
using namespace std;
int fastExpo(int b, int n)
{
    if(n == 1) return b;            // b^1 = b
    if(n == 0) return 1;            // b^0 = 1
    int r = fastExpo(b,n/2);        // n/2 x n/2 -> fast exponentiation.
    if(n % 2 == 0) return r * r;    // n/2 equal partition.
    else return r * r * b;          // 2 x n/2 x b since there can't be an equal partition.
}
int main()
{
    cout << fastExpo(5,2);
    return 0;
}
