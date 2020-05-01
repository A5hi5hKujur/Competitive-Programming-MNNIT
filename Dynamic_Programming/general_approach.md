
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

CONVERT TOP-DOWN(MEMOIZATION) TO BOTTOM UP :

1. Since Recursion is the parent technique of Dynamic Programming, both top-down(recursive) and bottom-up(iterative)
   method follow the same approach of solving dynamic problem, with an exception, the iterative procedure do not use
   an auxiliary stack to store function calls. Time complexity remains same however.

2. In the iterative method we simulate recursion where a M x N grid(same as memoization) dp, contain the answers for
   a particular sub-problem of corresponding dp[i][j]. The procedure takes the help of the previous sub-problem in order
   to solve the current sub-problem. The dp[][] matrix is populated in a uniform way(diagonally) instead of being
   "scattered" as populated in the case of memoization. The solution of the "asked-problem" is obtained on dp[m][n].

3. Steps to convert recursive method to iterative method :
  - Decide The constants / variables.
  - Find a recursive solution with base case and everything.
  - Create the dp matrix of size dp[m+1][n+1]. where m and n are the variables driving the dynamic program.
  - Initialize the matrix 0th row and 0th column, where all the cells in these row and column have the value of the "base-case".
  - Populating the rest of the dp with the corresponding dp[i][j] values starting from i = 1 ; j = 1.
  - The code for the choice diagram remains the same where answer for a particular sub problem i,j would be stored in dp[i][j].
  - The answer for the "asked problem" of constraint 'm' and 'n', would be in block dp[m][n].

  Note : we do not bother to pre-initialize the rest of the matrix with -1 since we know the progression of solutions obtained
         for each sub-problem would be uniformly filled.

  OPTIMIZED SPACE COMPLEXITY 0-1 KNAPSACK ITERATIVE :

  A given 0-1 knapsack problem where :
  - Number of items can be upto : 0 - 500.
  - Knapsack capacity can be upto : 20000000

  Clearly a dp of size dp[500][20000000] is not feasible. And there is NO WAY to solve this problem by memoization since memoization
  only works with smaller constraints. (something like dp[200][20000]).
  - We have to convert the recursive approach into an iterative one.
  - Instead of building a whole matrix of dp[500][20000000] we only work with 2 rows :
    1. To store all sub-problem solutions of the previous row.
    2. To store all sub-problem solutions of the next row. (to be calculated by the previous row)

  Approach :  
  Time Complexity :  O(n x w) where, n : no. of items.
                                     w : maximum knapsack capacity.
                     but since n is exponentially smaller than w, complexity != O(n^2).

  Space Complexity : O(2 x (w+1))

  1. Create 2 arrays of size w+1 : current[w+1]; previous[w+1];

  2. Run an outer loop to iterate through all the the items(n) :
      for(int i=0; i<n; i++){ .... }

  3. Run an inner loop to iterate through the current variation of the weight :
      for(int j = weight[i]; j <=w ; j++){ ... }

  4. Choices :
     - Pick the item i : choice_1 = value[i] + prev[j - weight[i]];  ---> Value of current item + value of previous item in (j - weight[i])th position.
     - Dont Pick item i : choice_2 = prev[j]; ---> Since you did not pick anything value remains the same.

  5. Optimal choice : current[j] = max(choice_1, choice_2);

  6. previous[] = current[];  ---> current row becomes previous row.

  7. Print(dp[n][w]).


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
