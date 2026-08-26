class Solution {
public:

    int n,m;
    vector<int> dx={-1,0,1,0};
    vector<int> dy={0,1,0,-1};
    vector<vector<bool>> vis;
    bool check(int i,int j) {
        if(i>=0 && i<n && j>=0 && j<m)
            return true;
        return false;
    }

    bool check(int i,int j,int val,vector<vector<int>>& grid) {

        if(i==n-1 && j==m-1)
            return true;

        vis[i][j] = true;
        for(int k=0;k<4;k++) {
            int ni=dx[k]+i;
            int nj=dy[k]+j;
            if(check(ni,nj) && !vis[ni][nj] && (abs(grid[ni][nj]-grid[i][j])<=val) )
                if(check(ni,nj,val,grid))
                    return true;
        }

        return false;
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        
        n = heights.size();
        m = heights[0].size();

        int lb = 0, ub = ((int)1e6);
        int ans = ub;
        while(lb<=ub) {
            int mi = (ub-lb)/2+lb;
            vis.assign(n,vector<bool>(m,false));
            if(check(0,0,mi,heights)) {
                ans = mi;
                ub = mi - 1;
            }else
                lb = mi + 1;
        }
        return ans;
    }
};