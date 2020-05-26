/*
  MODULAR ARITHMATIC :
    i) Modular congurency (~=) :
      13 ~= 41 (mod 7) which means that : (13 % 7) == (41 % 7)

    This principle also holds when,
     {(13 + 35 + 5) % 7} == {(41 + 35 + 5) % 7 } because 13 ~= 41

     ii) This is because of Modular arithmatic :
         ----------------------------------------
        |  (x + y) % n    ==   (x%n + y%n) % n  |
        ----------------------------------------
     - if a ~= b (mod N)      (if 'a' and 'b' are modularly congurent w.r.t 'N')
       then,
            a - b ~= 0 (mod N)
            a - b is divisible by N.
            a = N * k + b
            b = N * k + a           where, k is the difference of a and b.

      Eg 13 ~= 41 (mod 7)
          13 - 41 = -28
          41 - 13 = 28
          28 % 7 = 0

    iii) Multiplicative modulo :
       -------------------------------------------
      |  (a * b) % N == {(a % N) * (b % N)} % N  |
      -------------------------------------------
    iv) Exponentiation in modular arithmatic :
          if a ~= b (mod N) then                eg : 16   ~= 1   (mod 3) then
          a^k ~= b^k (mod N)                         16^5 ~= 1^5 (mod 3)

          eg : Find (29^10) % 3
          =>    29 ~= 2 (mod 3)
                2^10 % 3 = 1024 % 3       (to calculate n mod 3 and n mod 9, add all the digits in n and perform modulo)
                7 % 3 = 1

    v) Moduo Subtraction :
      ------------------------------------------------
      |  (a - b) % N == {(a % N) - (b % N) + a} % N  |
      ------------------------------------------------

    vi) Modulo Multiplicative Inverse :
    ( a / b ) % N    !=   {(a % N) / (b % N)} % N      since (a / b) % N where a < b would yield 0.

        - normal multiplicative inverse :
            a / b = a x multiplicative inverse of b.

        - modulo multiplicative inverse :
        ----------------------------------------
       |  (a/b) % N = {(a % N) x (B % N)} % N  |   where, B is the modulo multiplicative inverse of 'b'.
       -----------------------------------------

       - How to find modulo multiplicative inverse ?
        As multiplicative inverse property states that if you multiply a number with its inverse, the
        result is '1'. There is a great similarity with this statement in the case of modulo Multiplicative
        inverse as well.

            - Same property w.r.t modulo ,ultiplicative inverse :  n x B ~= 1 (mod N)
              eg : Finding modulo multiplicative inverse of 5. under mod 7.
                              5 x i ~= 1 (mod 7),
              meaning : we should find a number 'i' to multiply with 5 such that the product when mod with 7, gives 1.

            - brute force : run loop from 0 to 5-1, and see which value i yields a result '1'.
*/
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
