#include <bits/stdc++.h>
#define M 100000007
using namespace std;
int fastExpo(int b, int n)
{
    if(n == 1) return b;
    if(n == 0) return 1;
    int r = fastExpo(b,n/2);
    if(n % 2 == 0) return ((r%M) * (r%M))%M;  // modulo multiplicative property for even case.
    else ((r%M) * (r%M) * b)%M;               // modulo multiplicative property for odd case.
}
int main()
{
    cout << fastExpo(5,2);
    return 0;
}
