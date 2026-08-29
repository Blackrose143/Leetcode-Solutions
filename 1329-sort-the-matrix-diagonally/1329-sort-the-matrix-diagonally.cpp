class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size() , n = mat[0].size();
        vector<int> cal;
        for(int i=0;i<m;i++) {
            cal.clear();
            for(int c=0,r=i;r<m && c<n;r++,c++) {
                cal.push_back(mat[r][c]);
            }
            sort(cal.begin(),cal.end());
            int r=i,c=0;
            for(int x:cal)
                mat[r++][c++] = x;
        }
        for(int i=1;i<n;i++) {
            cal.clear();
            for(int r=0,c=i;r<m && c<n;r++,c++) {
                cal.push_back(mat[r][c]);
            }
            sort(cal.begin(),cal.end());
            int c=i,r=0;
            for(int x:cal)
                mat[r++][c++] = x;
        }
        return mat;
    }
};