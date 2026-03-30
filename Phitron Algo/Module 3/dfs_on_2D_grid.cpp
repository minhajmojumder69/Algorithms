#include<bits/stdc++.h>
using namespace std;
bool visited[105][105];
char grid[105][105];
vector<pair<int,int>> op = {{-1,0},{1,0},{0,-1},{0,1}};

void dfs(int si,int sj)
{
    cout << si << " " << sj << endl;
    visited[si][sj] = true;

    for(int i=0; i<4 ; i++)
    {
        int ci,cj;
        ci = si + op[i].first;
        cj = sj + op[i].second;
        cout << ci << " " << cj << endl; 
    }   
            
}

int main()
{
    int n,m;
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
    dfs(si,sj);

  return 0;
}
