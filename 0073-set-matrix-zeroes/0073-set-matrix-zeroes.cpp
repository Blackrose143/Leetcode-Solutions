class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        vector<vector<int>> ans(n,vector<int>(m,1));
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                ans[i][j]=matrix[i][j];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    ans[i][j]=0;
                    for(int k=i+1;k<n;k++)
                        ans[k][j]=0;
                    for(int k=i-1;k>=0;k--)
                        ans[k][j]=0;
                    for(int k=j+1;k<m;k++)
                        ans[i][k]=0;
                    for(int k=j-1;k>=0;k--)
                        ans[i][k]=0;
                }
            }
        }
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                matrix[i][j]=ans[i][j];
    }
};