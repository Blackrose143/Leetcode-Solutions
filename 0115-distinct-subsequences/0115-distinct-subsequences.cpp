class Solution {
public:

    int m,n;
    vector<vector<int>> dp;
    int fun(int i,int j,string& s,string& t) {

        if(j==n)
            return 1;

        if(i>=m)
            return 0;

        if(dp[i][j]!=-1)
            return dp[i][j];

        int ans = 0;
        if(i<m && j<n && s[i]==t[j]) {
            ans += fun(i+1,j+1,s,t);
        }
        ans += fun(i+1,j,s,t);
        return dp[i][j] = ans;
    }

    int numDistinct(string s, string t) {
        m = s.length();
        n = t.length();
        dp.resize(m,vector<int>(n,-1));
        return fun(0,0,s,t);
    }
};