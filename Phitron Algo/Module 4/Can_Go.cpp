#include <bits/stdc++.h>
using namespace std;
char grid[1005][1005];
bool visited[1005][1005];
vector<pair<int,int>> op = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int n, e;

bool valid(int i,int j)
{
    if (i < 0 || i >= n || j < 0 || j >= e)
    {
        return false;
    }

    return true;
}

void dfs(int si, int sj)
{
    visited[si][sj] = true;

    for (int i = 0; i < 4; i++)
    {
        int ci, cj;
        ci = si + op[i].first;
        cj = sj + op[i].second;
        if (valid(ci, cj) && !visited[ci][cj] && grid[ci][cj] != '#')
        {
            dfs(ci, cj);
        }
    }
}

int main()
{
    cin >> n >> e;
    int sni = -1, snj = -1;
    int tri = -1,trj = -1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < e; j++)
        {
            cin >> grid[i][j];

            if (grid[i][j] == 'A')
            {
                sni = i;
                snj = j;
            }
            if (grid[i][j] == 'B')
            {
                tri = i;
                trj = j;
            }
            
        }
    }
    memset(visited,false,sizeof(visited));
    dfs(sni,snj);

    if (visited[tri][trj])
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
    
    return 0;
}