class Solution {
public:

    int n,m;
    vector<vector<int>> dp;
    int fun(int i,int j,string& s,string& t) {
        
        if(i==n)
            return m-j;

        if(j==m)
            return n-i;
        
        if(dp[i][j]!=-1)
            return dp[i][j];

        int ans=1e9;
        if(s[i]==t[j])
            ans = min(ans,fun(i+1,j+1,s,t));
        else{
            ans = min(ans,fun(i+1,j+1,s,t)+1);
            ans = min(ans,fun(i+1,j,s,t)+1);
            ans = min(ans,fun(i,j+1,s,t)+1);
        }
        return dp[i][j] = ans;
    }

    int minDistance(string s, string t) {
        n = s.size(), m = t.size();
        dp.resize(n,vector<int>(m,-1));
        return fun(0,0,s,t);
    }
};