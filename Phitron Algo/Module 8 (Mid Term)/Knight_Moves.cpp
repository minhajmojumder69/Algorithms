#include <bits/stdc++.h>
using namespace std;
bool visited[1005][1005];
char grid[1005][1005];
int level[1005][1005];
vector<pair<int, int>> op = {{-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {-1, -2}, {1, -2}, {2, -1}, {2, 1}};
int n, m;

bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
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

        for (int i = 0; i < 8; i++)
        {
            int ci, cj;
            ci = parent_i + op[i].first;
            cj = parent_j + op[i].second;

            if (valid(ci, cj) && !visited[ci][cj])
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
    int q;
    cin >> q;

    while (q--)
    {
        cin >> n >> m;
        int si, sj, di, dj;
        cin >> si >> sj >> di >> dj;
        memset(visited, false, sizeof(visited));
        memset(level, -1, sizeof(level));
        if (si == di && sj == dj)
        {
            cout << "0" << endl;
        }
        else
        {
            bfs(si, sj);
            if (visited[di][dj])
                cout << level[di][dj] << endl;
            else
                cout << "-1\n";
        }
    }

    return 0;
}
