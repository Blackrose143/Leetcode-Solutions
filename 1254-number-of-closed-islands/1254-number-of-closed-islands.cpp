class Solution {
public:

    int n,m;
    bool dfs(int i,int j,vector<vector<int>>& grid) {
        if(i<0 || i>=n || j<0 || j>=m)
            return false;

        if(grid[i][j])
            return true;

        grid[i][j] = 1;
        bool d = dfs(i+1,j,grid);
        bool u = dfs(i-1,j,grid);
        bool r = dfs(i,j+1,grid);
        bool l = dfs(i,j-1,grid);
        return d && u && r && l;
    }

    int closedIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int ans = 0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j]==0) {
                    if(dfs(i,j,grid))
                        ans++;
                }
            }
        }
        return ans;
    }
};