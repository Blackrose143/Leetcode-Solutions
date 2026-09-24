class Solution {
public:

    int n,m,l;
    vector<vector<int>> dp;
    bool fun(int i,int j,int k,string& s1,string& s2,string& t) {

        if(k==l)
            return i==n && j==m;

        if(i>=n && j>=m)
            return false;

        if(dp[i][j]!=-1)
            return dp[i][j];

        bool ans=false;
        if(i<n && s1[i]==t[k])
            ans |= fun(i+1,j,k+1,s1,s2,t);
        if(j<m && s2[j]==t[k])
            ans |= fun(i,j+1,k+1,s1,s2,t);
        return dp[i][j] = ans;
    }

    bool isInterleave(string s1, string s2, string s3) {
        n = s1.size();
        m = s2.size();
        l = s3.size();

        if(n+m != l)
            return false;
            
        dp.assign(n+m,vector<int>(m+n,-1));
        return fun(0,0,0,s1,s2,s3);
    }
};