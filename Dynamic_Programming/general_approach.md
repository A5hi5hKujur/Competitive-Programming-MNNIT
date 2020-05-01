
IDNETIFYING A DYNAMIC PROBLEM :

1. The problem should be an "optimization problem" (minimize, maximize, summation).
2. The problem should involve a "decision-making" component to it, where you have to choose
   an optimal solution out of 2(or more) choices at EVERY step of the selection process.

APPROACH TO SOLVE DYNAMIC PROBLEM (Recursion + Memoization) :

1. Identify the constants / variables.

2. Find a recursive solution.
  - Identify the inputs and the return type.
  - Identify the base case : Think of the smallest valid input.
  - Make a "choice" diagram illustrating all possible input cases and their responses as output.
  - Code the function.

3. Memoize the recursive function.
  - Create a static array(single/double) of the max constraint of variable function
    input set, which would
    consist of all possible outputs of the given block of the respective index(s).
  - Initialize all the cells of the static array(dp array) as "unvisited" (-1).
  - Every solution for a given set of variable functional inputs will be stored
    in their corresponding block in the dp array.
  - If a value is already occupied in the dp array block, the best possible solution
    for the corresponding inputs have
    already been stored, therefor simply return the value already stored.
  - If a value is in not occupied in the dp array, compute the best possible solution
    for the corresponding inputs and store in the dp array.

PARENT PROBLEMS OF DP :

1. 0/1 Knapsack :
  - Subset Sum Problem.
  - Equal Sum Partition Problem.
  - Count of Subsets sum with a Given Sum.
  - Minimum Subset Sum Difference.
  - Count Number of Subset with a given difference.
  - Target sum.

2. Unbounded Knapsack :
  - Rod Cutting Problem.
  - Coin Change Problem : Maximum number of ways.
  - Coin Change Problem : Minimum number of coins.

3. Longest Common Subsequence(LCS) :
  - Longest Common Substring.
  - Print Longest Common Subsequence.
  - Shortest Common Super sequences.
  - Print Shortest Common Super Sequences.
  - Minimum number of insertions and deletions to convert string 'a' to string 'b'.
  - Largest Repeating Subsequence.
  - Length of largest subsequence of 'a' which is a substring in 'b'.
  - Subsequence pattern matching.
  - Count how many times 'a' appears as subsequence in 'b'.
  - Largest Palindromic Subsequence.
  - Largest Palindromic String.
  - Minimum number of deletion in a string to make it a Palindrome
  - Minimum number of insertions in a string to make it a Palindrome.
  - Longest Increasing Subsequence.

4. Kadane's Algorithm.

5. Matrix Chain Multiplication :
  - Printing MCM.
  - Evaluate Expression to true/boolean parenthesiszation.
  - minimium / maximum value of an expression.
  - Palindrome Partitioning.
  - Scramble String.
  - Egg Dropping Problem.

6. DP on Trees :
  - Diameter of a Binary Tree.
  - Maximum Path sum from any node to any node.
  - Maximum Path sum from leaf to leaf.
  - Diameter of N-ary Tree.

7. DP on Grids.
