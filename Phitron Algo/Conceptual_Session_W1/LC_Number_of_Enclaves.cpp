// class Solution {
// public:
//     int n,m;
//     bool visited[505][505];
//     vector<pair<int,int>> op = {{0,1},{0,-1},{1,0},{-1,0}};
//     bool valid(int i,int j)
//     {
//         if(i<0 || i >=n || j<0 || j>=m)
//         return false;
//         else return true;
//     }
//     void dfs(int sr1,int sr2,vector<vector<int>>& grid)
//     {
//         visited[sr1][sr2] = true;
//         for(int i =0;i<4;i++)
//         {
//             int ci = sr1+op[i].first;
//             int cj = sr2+op[i].second;
//             if(valid(ci,cj) && !visited[ci][cj] && grid[ci][cj] == 1)
//             {
//                 dfs(ci,cj,grid);
//             }
//         }
//     }
//     int numEnclaves(vector<vector<int>>& grid)
//     {
//         n = grid.size();
//         m = grid[0].size();

//         memset(visited,false,sizeof(visited));

//         for(int i =0;i<n;i++)
//             for(int j=0;j<m;j++)
//                 {
//                     if(i == 0 || i== n-1 || j==0 || j == m-1)
//                     {
//                         if(!visited[i][j] && grid[i][j]==1)
//                             dfs(i,j,grid);
//                     }
//                 }

//         int count = 0;
//         for(int i = 0;i<n;i++)
//             for(int j=0;j<m;j++)
//                 if(!visited[i][j] && grid[i][j] == 1)
//                 {
//                     count++;
//                 }

//         return count;

//     }
// };