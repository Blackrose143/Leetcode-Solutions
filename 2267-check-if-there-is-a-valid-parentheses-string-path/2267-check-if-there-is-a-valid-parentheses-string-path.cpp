class Solution {
public:

    int n,m;
    vector<vector<vector<int>>> dp;
    bool fun(int i,int j,int cnt,vector<vector<char>>& grid) {

        if(i>=n || j>=m)
            return false;

        if(grid[i][j]=='(')
            cnt++;
        else
            cnt--;

        if(cnt<0)
            return false;

        if(dp[i][j][cnt]!=-1)
            return dp[i][j][cnt];

        if(i==n-1 && j==m-1) {
            return dp[i][j][cnt] = (cnt==0);
        }

        bool ans=false;
        ans |= fun(i+1,j,cnt,grid);
        ans |= fun(i,j+1,cnt,grid);
        return dp[i][j][cnt] = ans;
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();

        if(grid[0][0]==')' || grid[n-1][m-1]=='(' || (n+m-1)%2!=0)
            return false;
    
        dp.resize(n,vector<vector<int>>(m,vector<int>(n+m,-1)));
        return fun(0,0,0,grid);
    }
};