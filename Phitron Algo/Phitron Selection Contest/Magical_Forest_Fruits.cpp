#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,q;
    cin >> n >> q;
    long long int ar[n+1];
    ar[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        int fruit;
        cin >> fruit;
        ar[i] = ar[i-1] + fruit;
    }

    while (q--)
    {
        int l,r;
        cin >> l >> r;
        
        cout << ar[r]- ar[l-1] << endl;
    }

  return 0;
}