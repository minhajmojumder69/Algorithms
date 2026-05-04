#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[105];
bool visited[105];
bool pathvisit[105];
bool cycle;

void dfs(int src)
{
    visited[src] = true;
    pathvisit[src] = true;
    for (int child : adj_list[src])
    {
        if (visited[child] && pathvisit[child])
        {
            cycle = true;
        }

        if (!visited[child])
        {
            
            dfs(child);
        }
    }
    pathvisit[src] = false;
}
int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        
    }
    memset(pathvisit, false, sizeof(pathvisit));
    memset(visited, false, sizeof(visited));
    cycle = false;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(i);
        }
    }
    if (cycle)
        cout << "Cycle Detected\n";
    else
        cout << "No Cycle\n";
    return 0;
}