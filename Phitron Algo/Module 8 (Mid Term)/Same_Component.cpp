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
        if (valid(ci, cj) && !visited[ci][cj] && grid[ci][cj] == '.')
        {
            dfs(ci, cj);
        }
    }
}

int main()
{
    cin >> n >> e;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < e; j++)
        {
            cin >> grid[i][j];
        }
    }
    memset(visited, false, sizeof(visited));
    
    int si,sj,di,dj;
    cin >> si >> sj >> di >> dj;
    
    dfs(si,sj);

    if(visited[di][dj])
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}
