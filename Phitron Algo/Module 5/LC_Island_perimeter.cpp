// class Solution {
// public:
//     bool visited[105][105];
//     vector<pair<int,int>> op = {{0,1},{0,-1},{1,0},{-1,0}};
//     int n,m;
//     int count;
//     bool valid(int i,int j)
//     {
//         if(i<0 || i>=n || j<0 || j>=m)
//             return false;
//         return true;
//     }
//     void dfs(int si,int sj,vector<vector<int>>& grid)
//     {
//         visited[si][sj] = true;
//         for(int i = 0; i<4; i++)
//         {
//             int ci = si + op[i].first;
//             int cj = sj + op[i].second;
            
//             if(!valid(ci,cj))
//                 count++;
//             else if(valid(ci,cj) && grid[ci][cj] == 0)
//                 count++;
//             else if(valid(ci,cj) && !visited[ci][cj] && grid[ci][cj] == 1)
//                  dfs(ci,cj,grid);
//         }
//     }

//     int islandPerimeter(vector<vector<int>>& grid) {
//         count=0;
//         n = grid.size();
//         m = grid[0].size();
//         memset(visited,0,sizeof(visited));
//         for(int i = 0; i < n; i++)
//             for(int j =0; j < m ; j++)
//                 if(!visited[i][j] && grid[i][j] == 1)
//                     dfs(i,j,grid);
//         return count;
//     }
// };