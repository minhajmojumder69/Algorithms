#include <bits/stdc++.h>
using namespace std;
int val[1005], weight[1005];
int dp[1005][1005];

int knapsack(int idx, int mx)
{
    if (idx < 0 || mx <= 0)
        return 0;

    if (dp[idx][mx] != -1)
        return dp[idx][mx];

    if (weight[idx] <= mx)
    {
        int op1 = knapsack(idx - 1, mx - weight[idx]) + val[idx];
        int op2 = knapsack(idx - 1, mx);
        dp[idx][mx] = max(op1, op2);
        return dp[idx][mx];
    }
    else
    {
        dp[idx][mx] = knapsack(idx - 1, mx);
        return dp[idx][mx];
    }
}

int main()
{
    int ts;
    cin >> ts;
    while (ts--)
    {
        int n, mx_weight;
        cin >> n;
        cin >> mx_weight;
        for (int i = 0; i < n; i++)
        {
            cin >> weight[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> val[i];
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= mx_weight; j++)
            {
                dp[i][j] = -1;
            }
        }
        cout << knapsack(n - 1, mx_weight) << endl;
    }

    return 0;
}