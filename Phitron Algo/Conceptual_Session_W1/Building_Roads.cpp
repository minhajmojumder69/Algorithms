#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<bool> visited(100000, false);
vector<vector<int>> adj_list(100000);

void dfs(int src)
{
    visited[src] = true;
    for (auto child : adj_list[src])
    {
        if (!visited[child])
        {
            dfs(child);
        }
    }
}

int main()
{
    cin >> n >> m;

    while (m--)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    vector<int> res;

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            dfs(i);
            res.push_back(i);
        }
    }
    int sz = res.size();
    cout << sz - 1 << endl;

    if (sz > 1)
    {
        for (int i = 0; i < sz - 1; i++)
        {
            cout << res[i] << " " << res[i + 1] << endl;
        }
    }

    return 0;
}