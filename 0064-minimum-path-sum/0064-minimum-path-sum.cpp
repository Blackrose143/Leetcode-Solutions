class Solution {
public:

    int n,m;
    vector<vector<int>> dp;
    int dfs(int i,int j,vector<vector<int>>& grid) {

        if(i>=n || j>=m )
            return 1e9;

        if(i==n-1 && j==m-1)
            return grid[i][j];

        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int ans = 1e9;
        ans = min(ans, grid[i][j]+dfs(i+1,j,grid));
        ans = min(ans, grid[i][j]+dfs(i,j+1,grid));
        return dp[i][j] = ans;
    }

    int minPathSum(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        dp.resize(n,vector<int>(m,-1));
        return dfs(0,0,grid);
    }
};