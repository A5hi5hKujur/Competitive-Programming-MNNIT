#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int arr[];
    cin >> n;
    for(int i=0; i<n; i++) cin >> arr[i];
    int sum = arr[0];
    int max = sum;
    int start = 0;
    int end = 0;
    bool negative_arr = true;
    
    int neg_max = -999;
    for(int i=0; i<n; i++){
        if(arr[i] > 0){
            negative_arr = false;
            break;
        }
        if(arr[i] > neg_max){
            neg_max = arr[i];  
            start = i;
            end = i;
        }
    }
    if(!negative_arr){
        start = 0;
        end = 0;
        for(int i=1; i<n; i++)
        {   
            if(sum + arr[i] > arr[i])
            {
                sum += arr[i];
            }
            else
            {
                sum = arr[i];
                start = i;
                end = i;
            }
            if(max < sum)
            {   
                max = sum;
                end = i;
            }
        }
        cout << max << endl;   
    }
    else
        cout << neg_max << endl;
    
    
    for(int i=start; i<=end; i++) cout << arr[i] << " ";
    return 0;
}
