#include<bits/stdc++.h>
using namespace std;
vector<int> pattern_arr;
void kmpPattern(string pattern)
{
    int n = pattern.length();
    vector<int> arr(n);
    int j=0;
    int i = 1;
    arr[0] = j;
    while(i<n)
    {
        if(pattern.at(j) == pattern.at(i))
        {
            arr[i] = j + 1;
            j++;
            i++;
        }
        else
        {
            if(j != 0)
                j = arr[j-1];
            else
            {
                arr[i] = 0;
                i++;
            }
        }
    }
    pattern_arr = arr;
}
void substringSearch(string str, string pattern)
{
    int i = 0;
    int j = 0;
    int n = str.length();
    int m = pattern.length();

    int match = 0;
    while(i < n && j < m)
    {
        if(str.at(i) == pattern.at(j))
        {
            i++;
            j++;
        }
        else
        {
            if(j!=0)
                j = pattern_arr[j-1];
            else
                i++;
        }
    }
    match = i - m;
    if(j == m)
        cout << match;
    else
        cout << "not found";

}
int main()
{
    string pattern;
    pattern = "abcaby";
    string str;
    str = "abxabcabcaby";
    kmpPattern(pattern);
    substringSearch(str, pattern);
    return 0;
}
