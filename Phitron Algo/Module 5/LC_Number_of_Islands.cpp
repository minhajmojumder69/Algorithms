// class Solution {
// public:
//     int n,m;
//     bool visited[305][305];
//     vector<pair<int,int>> op = {{0,1},{0,-1},{1,0},{-1,0}};
//     bool valid(int i,int j)
//     {
//         if(i<0 || i>=n || j<0 || j>=m)
//             return false;
//         else return true;
//     }
//     void dfs(int si,int sj,vector<vector<char>>& grid)
//     {
//         visited[si][sj] = true;
//         for(int i=0; i<4; i++)
//         {
//             int ci = si + op[i].first;
//             int cj = sj + op[i].second;
//             if(valid(ci,cj) && !visited[ci][cj] && grid[ci][cj]== '1')
//             {
//                 dfs(ci,cj,grid);
//             }
//         }
//     }
//     int numIslands(vector<vector<char>>& grid)
//     {
//         int count=0;
//         n = grid.size();
//         m = grid[0].size();
//         for(int i=0; i<n ; i++)
//             for(int j=0;j<m;j++)
//                 if(grid[i][j]=='1' && !visited[i][j])
//                     {
//                         dfs(i,j,grid);
//                         count++;
//                     }
//         return count;
//     }
// };