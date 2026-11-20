class Solution {
public:

    int n;
    vector<vector<int>> dp;
    int fun(int l,int r,string& s) {

        if(l>r)
            return 0;

        if(dp[l][r]!=-1)
            return dp[l][r];

        int ans = 0;
        if(s[l]==s[r] && l!=r)
            ans = max(ans,fun(l+1,r-1,s)+2);
        else if(l==r)
            ans = max(ans,fun(l+1,r-1,s)+1);
        ans = max(ans,fun(l+1,r,s));
        ans = max(ans,fun(l,r-1,s));

        return dp[l][r] = ans;
    }

    int longestPalindromeSubseq(string s) {
        n = s.length();
        dp.assign(n,vector<int>(n,-1));
        return fun(0,n-1,s);
    }
};