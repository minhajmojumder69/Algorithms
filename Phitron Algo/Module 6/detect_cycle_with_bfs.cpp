#include<bits/stdc++.h>
using namespace std;

bool visited[105];
bool cycle;
int par[105];

vector<int> adj_list[105];

void bfs(int si)
{
    queue<int> q;
    q.push(si);
    visited[si] = true;
    while (!q.empty())
    {
        int parent = q.front();
        q.pop();

        for (int child : adj_list[parent])
        {
            if (visited[child] && par[parent] != child)
            {
                cycle = true;
            }
            
            else if (!visited[child])
            {
                q.push(child);
                visited[child] = true;
                par[child] = parent;
            }
            
        }
        
    }
    
}

int main()
{
    int n,e;
    cin >> n >> e;
    while (e--)
    {
        int a,b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    memset(visited,false,sizeof(visited));
    memset(par,-1,sizeof(par));
    cycle = false;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            bfs(i);
        }
        
    }
    if(cycle)
        cout << "Cycle Detected\n";
    else
        cout << "No Cycle\n";

  return 0;
}