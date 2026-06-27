class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>> vis(n,vector<int>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j]){
                    vis[i][j]=1;
                    vis[j][i]=1;
                    swap(matrix[i][j],matrix[j][i]);
                }
            }
        }
        for(int i=0;i<n;i++)
            reverse(matrix[i].begin(),matrix[i].end());
    }
};