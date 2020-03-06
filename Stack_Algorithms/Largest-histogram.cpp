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
            else area = arr[top] * (i - height.top() - 1); // arr[top] ranges from i to the next element in the stack.
            if(area > max) max = area;  // check if the calculated area is maximum.
        }
    }
    while(!height.empty()){            // for all the remaing continuation of heights. (backtracking...sort of.)
        top = height.top();
        height.pop();
        if(height.empty()) area = arr[top] * i;
        else area = arr[top] * (i - height.top() - 1);
        if(area > max) max = area;
    }
    cout << max;
    return 0;
}
