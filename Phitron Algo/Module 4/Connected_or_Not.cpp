#include <bits/stdc++.h>
using namespace std;
int adj[1005][1005];

int main()
{
    int n, e;
    cin >> n >> e;
    memset(adj,0,sizeof(adj));
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj[a][b] = 1;
    }
    int q;
    cin >> q;
    while(q--)
    {
        int n1,n2;
        cin >> n1 >> n2;
        if (n1 == n2)
        {
            cout << "YES" << endl;
        }
        else if (adj[n1][n2] == 1)
        {
            cout << "YES" << endl;
            
        }
        else
        {
            cout << "NO" << endl;
        }
        
    }
    return 0;
}