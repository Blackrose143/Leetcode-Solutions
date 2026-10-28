class Solution {
public:

    int n,m;
    vector<vector<vector<int>>> dp;
    vector<vector<int>> nums;
    int fun(int i,int j,int XOR) {
        if(i==n-1 && j==m-1)
            return XOR;

        if(dp[i][j][XOR]!=-1)
            return 1e9;

        int ans = 1e9;
        if(i+1<n)
            ans = min(ans,fun(i+1,j,XOR^nums[i+1][j]));
        if(j+1<m)
            ans = min(ans,fun(i,j+1,XOR^nums[i][j+1]));
        return dp[i][j][XOR] = ans;
    }

    int minCost(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        nums = grid;
        dp.resize(n,vector<vector<int>>(m,vector<int>(2046,-1)));
        return fun(0,0,grid[0][0]);
    }
};