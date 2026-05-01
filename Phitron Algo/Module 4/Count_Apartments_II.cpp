#include <bits/stdc++.h>
using namespace std;
char grid[1005][1005];
bool visited[1005][1005];
vector<pair<int,int>> op = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int n, e;
vector<int> room;
bool valid(int i,int j)
{
    if (i < 0 || i >= n || j < 0 || j >= e)
    {
        return false;
    }

    return true;
}

void dfs(int si, int sj,int &cnt)
{
    visited[si][sj] = true;
    cnt++;

    for (int i = 0; i < 4; i++)
    {
        int ci, cj;
        ci = si + op[i].first;
        cj = sj + op[i].second;
        if (valid(ci, cj) && !visited[ci][cj] && grid[ci][cj] == '.')
        {
            dfs(ci, cj,cnt);
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
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < e; j++)
        {
            if (!visited[i][j] && grid[i][j] == '.')
            {
                int count = 0;
                dfs(i, j,count);
                room.push_back(count);
            }
        }
    }
    
    if (room.empty())
    {
        cout << 0 << endl;
    }
    else
    {
        sort(room.begin(),room.end());
        for (int i = 0; i < room.size(); i++)
        {
            cout << room[i] << " ";
        }
    }

    return 0;
}
