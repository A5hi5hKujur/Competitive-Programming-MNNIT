/*
  Count Set Bits : of a given decimal number.

  n-1 logic :
  - If you negate a number by 1 you are fliping the bits from the
  rightmost upcomming set bits(including the rightmost set bit) :
  eg : 10  ->  0010 10   (n)
       9   ->  0010 01   (n-1)
  - now we & the number by itself and update n,

              0010 01   (decimal 10)
            & 0010 10   (decimal 9)
                10 00   (decimal 8)

  - Repeat the process until the number becomes 0,

  - Keep a counter to count the number of successful loops,
    that would be equal to number of set bits in n.

Complexity : O(log n)
*/
  count = 0;
  while(n)
  {
    n &= (n-1)
    count++;
  }
  cout << count;
