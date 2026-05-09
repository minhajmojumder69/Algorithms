#include <bits/stdc++.h>
using namespace std;
char grid[105][1005];
bool visited[1005][1005];
pair<int, int> parent[1005][1005];
// int level[1005];
int n, m;

vector<pair<int, int>> op = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
    {
        return false;
    }
    else
        return true;
}

void bfs(int si, int sj, int tri, int trj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    visited[si][sj] = true;
    // level[src] = 0;

    while (!q.empty())
    {
        pair<int, int> par = q.front();
        q.pop();
        int par_i = par.first;
        int par_j = par.second;

        for (int i = 0; i < 4; i++)
        {
            int ci, cj;
            ci = par_i + op[i].first;
            cj = par_j + op[i].second;

            if (valid(ci, cj) && !visited[ci][cj] && grid[ci][cj] != '#')
            {
                q.push({ci, cj});
                visited[ci][cj] = true;
                parent[ci][cj] = {par_i, par_j};
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    int sni = -1, snj = -1;
    int tri = -1, trj = -1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];

            if (grid[i][j] == 'R')
            {
                sni = i;
                snj = j;
            }
            if (grid[i][j] == 'D')
            {
                tri = i;
                trj = j;
            }
        }
    }

    memset(visited, false, sizeof(visited));
    // memset(level,-1, sizeof(level));

    bfs(sni, snj, tri, trj);
    // cout << level[dst] << endl;

    if (tri != -1 && trj != -1 && visited[tri][trj])
    {
        pair<int, int> psnt = parent[tri][trj];

        while (psnt.first != sni || psnt.second != snj)
        {
            grid[psnt.first][psnt.second] = 'X';
            psnt = parent[psnt.first][psnt.second];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << grid[i][j];
        }
        cout << endl;
    }
    if (visited[tri][trj])
        return 0;
}