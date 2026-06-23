#include <bits/stdc++.h>
using namespace std;
long long dp[100005]; 
bool rec(long long n,long long tar)
{
    if(n == tar)
        return true;
    if(n > tar)
        return false;
    if(dp[n] != -1)
        return dp[n];

    bool op1 = rec(n*2,tar);
    bool op2 = rec(n+3,tar);
    dp[n] = (op1 || op2);

    return dp[n];
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        memset(dp, -1, sizeof(dp));
        long long n;
        cin >> n;

        if(rec(1,n) == true)
        {
            cout << "YES\n";
        }
        else
            cout << "NO\n";
    }
    

    return 0;
}