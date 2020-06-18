/*
Algorithm to find the largest rectangle in the histogram.
1.  Insert index values in the stack till you reach an element who's value is smaller
  than the values of the top element of the corresponding index value in the stack.
    -> This would mean that the bars from stack[top]th index and the ith index
       can form a rectangle, by chaining the corresponding bars of the histogram.

       * area = top element x (ith index - stack.top index {-1 because 0-index})

       * area = top element x ith index  // When top element is the smallest bar in the stack(up till that point)
                                            so it will be multiplied by all the bars which were
                                            coverd up till that point.

2.  Keep comparing and updating this area with the max area obtained previously.

3. If the stack is still left with indices that means that no smaller height element was found,
  Keep popping out elements form the stack and repeat the same proceedure.
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> height;  // STL Stack
    int n;
    cin >> n;   // input length of stack.

    long arr[n]; // input array element.
    for(int i=0; i<n; i++) cin >> arr[i];

    int top,i,area,max = 0;
    for(i=0; i<n; ) // stack operation.
    {
        if(height.empty() || arr[i] >= arr[height.top()] )
            height.push(i++);                    // push when stack empty or push greater elements.
        else{                                   // when a smaller element is encountered.
            top = height.top();                 // store the stack top (larger) element.
            height.pop();                       // pop that mofo out.
            if(height.empty()) area = arr[top] * i;    // if the stack is exhausted then there are i chain before it.
            else area = arr[top] * (i - height.top() - 1); // height.top = element whoes chain is running which came before i(current index) ; -1 because 0-index
            if(area > max) max = area;  // check if the calculated area is maximum.
        }
    }
    while(!height.empty()){            // for all the remaing continuation of heights. (backtracking...sort of.)
        top = height.top();
        height.pop();
        if(height.empty()) area = arr[top] * i; // at the final stage of the computation i would be equal to n.
                                                // and arr[top] would have the value of the last element in the stack which would be the smallest value.
                                                // hence n x smallest value would give the area where all the bars are included.
        else area = arr[top] * (i - height.top() - 1);
        if(area > max) max = area;
    }
    cout << max;
    return 0;
}
