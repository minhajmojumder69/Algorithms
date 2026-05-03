// class Solution {
// public:
//     int n,m;
//     bool flag;
//     bool visited[505][505];
//     vector<pair<int,int>> op ={{0,1},{0,-1},{1,0},{-1,0}};
//     bool valid(int i,int j)
//     {
//         if(i<0 || i>=n ||j<0 || j>=m)
//         return false;
//         else return true;
//     }
//     void dfs(int si,int sj,vector<vector<int>>& grid1,vector<vector<int>>& grid2){
//         visited[si][sj] = true;
//         if(grid1[si][sj]==0)
//         {
//             flag = false;
//         }
//         for(int i=0;i<4;i++)
//         {
//             int ci = si+op[i].first;
//             int cj = sj+op[i].second;
//             if(valid(ci,cj) && grid2[ci][cj]==1 && !visited[ci][cj])
//             {
//                 dfs(ci,cj,grid1,grid2);
//             }
//         }
//     }
//     int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
//         int count = 0;
//         n = grid1.size();
//         m = grid1[0].size();
//         memset(visited,false,sizeof(visited));
//         for(int i =0; i<n; i++)
//             for(int j=0;j<m;j++)
//                 if(!visited[i][j] && grid2[i][j]==1)
//                 {
//                     flag = true;
//                     dfs(i,j,grid1,grid2);
//                     if(flag)
//                         count++;
//                 }
//         return count;
//     }
// };