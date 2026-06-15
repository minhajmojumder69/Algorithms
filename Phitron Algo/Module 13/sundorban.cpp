#include <bits/stdc++.h>
using namespace std;
bool visited[105][105];
char grid[105][105];
int level[105][105];
vector<pair<int, int>> op = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int n;

bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= n)
    {
        return false;
    }

    return true;
}

void bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    visited[si][sj] = true;
    level[si][sj] = 0;
    while (!q.empty())
    {
        pair<int, int> parent = q.front();
        q.pop();
        int parent_i = parent.first;
        int parent_j = parent.second;

        //cout << parent_i << " " << parent_j << endl;

        for (int i = 0; i < 4; i++)
        {
            int ci, cj;
            ci = parent_i + op[i].first;
            cj = parent_j + op[i].second;

            if (valid(ci, cj) && !visited[ci][cj] && grid[ci][cj] != 'T')
            {
                q.push({ci, cj});
                visited[ci][cj] = true;
                level[ci][cj] = level[parent_i][parent_j] + 1;
            }
        }
    }
}

int main()
{
    int si,sj,ti,tj;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
            if(grid[i][j] == 'S')
            {
                si = i;
                sj = j;
            }
            if(grid[i][j] == 'E')
            {
                ti = i;
                tj = j;
            }
        }
    }

    
    memset(visited, false, sizeof(visited));
    memset(level,-1,sizeof(level));
    bfs(si, sj);
    cout << level[ti][tj] << endl;
    return 0;
}
