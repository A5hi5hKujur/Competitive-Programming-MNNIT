/*
    Fractional Knapsack Problem : O(nlog(n))

    We are given 'n' objects having some value to a unit portion weight assigned to it.
    We have a knapsack of 'm' capacity, i.e capable of holding items upto 'm' weight.
    We need to maximize our profit by collecting items in the knapsack.

    NOTE : items can be divided into portions in order to completly fill the knapsack(maximum profit).

    Algorithm :
    1. Find the value to weight ratio of all the items.
    2. Arrange this ratio in descending order, as to pick the item with the most value to weight ratio first.
    3. Keep subtracting the capacity of the knapsack to the weight of the items you include in the knapsack.
        - Items which cannot be completly fitted into the knapsack must be divided
          into 'portion' remaining to the capacity of the knapsack.

          portion = (remaining capacity of the knapsack / total weight of the item ) x value of item.

    4. Repeat step 3 until your knapsack capacity gets exhausted.
*/
#include <bits/stdc++.h>
using namespace std;
double greedy(int n, int knap, int value[], int weight[])
{
    double profit = 0;  // stores total profit.
    vector<pair<double,int>> ratio; // vector which stores pairs to store pairs of cost to weight ratio and item index.
    for(int i=0; i<n; i++)
    {
        pair<double,int> temp;  // temporary pair to populate the data structure.
        temp.first = (double)value[i] / weight[i];
        temp.second = i;
        ratio.push_back(temp);
    }
    sort(ratio.begin(),ratio.end());    // sort the vector based on the first pair value(CTV ratio).
    auto item = ratio.rbegin(); // start the selection process from the last position.
    while(knap) // while there is room in your bag.
    {
        if(weight[item -> second] <= knap)  // if complete portion of the item can fit in the bag.
        {
            profit = profit + value[item -> second];    // add the value of the item to profit.
            knap = knap - weight[item -> second];   // occupy the space in the bag with the item weight.
        }
        else    // if complete portion of the item cannot fit.
        {
            double portion = ((double)knap / weight[item -> second]) * value[item -> second];   // break of the portion that can fit.
            profit = profit + portion;  // add towards profit.
            knap = 0;   // knapsack becomes full ! or you can simply break out of the loop.
        }
        item++;
    }
    return profit;
}
int main()
{
    cout << "Enter the knapsack capacity : ";
    int knap;
    cin >> knap;
    cout << "Enter the number of items : ";
    int n;
    cin >> n;
    int value[n];
    int weight[n];
    for(int i=0; i<n; i++){
        cout << "Enter value and weight of the item : ";
        cin >> value[i];
        cin >> weight[i];
    }
    cout << "The maximum value of the knapsack : "<< greedy(n, knap, value, weight) << endl;
    return 0;
}
