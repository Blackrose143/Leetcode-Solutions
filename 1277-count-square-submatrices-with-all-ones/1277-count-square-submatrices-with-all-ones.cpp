class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size(),ans=0;
        for(int i=0;i<n;i++){
            int res=0;
            for(int j=0;j<m;j++){
                if(i!=0 && j !=0 && matrix[i][j]==1){
                    matrix[i][j]=1+min({matrix[i][j-1],matrix[i-1][j],matrix[i-1][j-1]});
                    res += matrix[i][j];
                }else
                    res += matrix[i][j];
            }
            cout << res << ' ';
            ans += res;
        }
        return ans;
    }
};