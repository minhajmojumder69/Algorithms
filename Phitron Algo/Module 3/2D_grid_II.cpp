#include<bits/stdc++.h>
using namespace std;
bool visited[105][105];
char grid[105][105];
vector<pair<int,int>> op = {{-1,0},{1,0},{0,-1},{0,1}};
int n,m;

bool valid(int i,int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
    {
        return false;
    }

    return true;    
}

void dfs(int si,int sj)
{
    cout << si << " " << sj << endl;
    visited[si][sj] = true;

    for(int i=0; i<4 ; i++)
    {
        int ci,cj;
        ci = si + op[i].first;
        cj = sj + op[i].second;
        if ( valid(ci,cj) && !visited[ci][cj] )
        {
            dfs(ci,cj);
        }
         
    }   
            
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
        
    }
    
    int si,sj;
    cin >> si >> sj;
    memset(visited,false,sizeof(visited));
    dfs(si,sj);

  return 0;
}
