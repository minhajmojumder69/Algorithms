#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[1005];
bool visited[1005];

int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    for (int i = 0; i < n; i++)
    {
        sort(adj_list[i].begin(),adj_list[i].end(),greater<int>());
    }
    

    int q;
    cin >> q;
    while (q--)
    {
        int nd;
        cin >> nd;
        if (adj_list[nd].empty())
        {
            cout << -1 << endl;
        }
        else
        {
            for (int i : adj_list[nd])
            {
                cout << i << " ";
            }
            cout << endl;
            
        }
        
    }
    return 0;
}