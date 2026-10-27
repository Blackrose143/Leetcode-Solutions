class Solution {
public:

    int n,m;
    vector<vector<char>> res; 
    bool fun(int i,int j) {

        if(i==n-1 && j==m-1) {
            res[i][j] ='.';
            return true;
        }

        if(i>=n || j>=m)
            return false;

        
        if(fun(i+1,j)) {
            res[i][j] = '.';
            return true;
        }

        if(fun(i,j+1)) {
            res[i][j] = '.';
            return true;
        }

        return false;
    }
    vector<string> createGrid(int m_, int n_) {
        n = m_;
        m = n_;
        res.resize(n,vector<char>(m,'#'));
        fun(0,0);
        vector<string> ans;
        for(auto vc:res) {
            string s="";
            for(char c:vc) {
                s += c;
            }
            ans.push_back(s);
        }
        return ans;
    }
};