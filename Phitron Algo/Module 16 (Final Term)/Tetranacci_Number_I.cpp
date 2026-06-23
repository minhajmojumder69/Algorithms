#include<bits/stdc++.h>
using namespace std;
int dp[45];
int tetranacci(int n)
{
    if(n == 0)
        return 0;
    if(dp[n] != -1)
        return dp[n];

    dp[n] = tetranacci(n-1) + tetranacci(n-2) + tetranacci(n-3) + tetranacci(n-4);
    return dp[n];
}
int main()
{
    memset(dp,-1,sizeof(dp));
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 2;

    int n;
    cin >> n;
    
    cout << tetranacci(n) << endl;

    return 0;
}