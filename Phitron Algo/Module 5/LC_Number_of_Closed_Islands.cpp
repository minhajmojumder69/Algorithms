// class Solution {
// public:
//     int n,m;
//     bool flag;
//     bool visited[105][105];
//     vector<pair<int,int>> op ={{0,1},{0,-1},{1,0},{-1,0}};
//     bool valid(int i,int j)
//     {
//         if(i<0 || i>=n ||j<0 || j>=m)
//         return false;
//         else return true;
//     }
//     void dfs(int si,int sj,vector<vector<int>>& grid){
//         visited[si][sj] = true;
//         for(int i=0;i<4;i++)
//         {
//             int ci = si+op[i].first;
//             int cj = sj+op[i].second;
//             if(!valid(ci,cj))
//                 flag = false;
//             if(valid(ci,cj) && grid[ci][cj]==0 && !visited[ci][cj])
//             {
//                 dfs(ci,cj,grid);
//             }
//         }
//     }
//     int closedIsland(vector<vector<int>>& grid) {
//         int count = 0;
//         n = grid.size();
//         m = grid[0].size();
//         memset(visited,false,sizeof(visited));
//         for(int i =0; i<n; i++)
//             for(int j=0;j<m;j++)
//                 if(!visited[i][j] && grid[i][j]==0)
//                 {
//                     flag = true;
//                     dfs(i,j,grid);
//                     if(flag)
//                         count++;
//                 }
//         return count;       
//     }
// };