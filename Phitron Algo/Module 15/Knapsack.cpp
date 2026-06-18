#include<bits/stdc++.h>
using namespace std;
int val[1005],weight[1005];

int knapsack(int idx,int mx)
{
    if(idx < 0 || mx <=0)
        return 0;

    if(weight[idx] <= mx)
    {
        // 2 options.
        // 1. bag a rkhbo, 2. rakhbo na;
        int op1 = knapsack(idx-1,mx - weight[idx]) + val[idx];
        int op2 = knapsack(idx-1,mx);  
        return max(op1,op2);
    }
    else
    {
        // 1 option
        // bag a rakhte parbo na
        return knapsack(idx-1,mx);
    }
}

int main()
{
    int n,mx_weight;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
    }
    cin >> mx_weight;

    cout << knapsack(n-1,mx_weight);
    
    return 0;
}