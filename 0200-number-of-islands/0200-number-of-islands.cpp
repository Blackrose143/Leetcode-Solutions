class Solution {
public:

    vector<int> dx={0,1,0,-1},dy={1,0,-1,0};
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size(),ans=0;
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    q.push({i,j});
                    ans++;
                    while(!q.empty()){
                        auto [x,y]=q.front();
                        q.pop();
                        for(int i=0;i<4;i++){
                            int ix=dx[i]+x;
                            int iy=dy[i]+y;
                            if(ix>=0 && ix<n && iy>=0 && iy<m && grid[ix][iy]=='1'){
                                q.push({ix,iy});
                                grid[ix][iy]='0';
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};