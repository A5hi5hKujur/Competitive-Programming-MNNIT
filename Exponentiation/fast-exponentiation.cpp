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
