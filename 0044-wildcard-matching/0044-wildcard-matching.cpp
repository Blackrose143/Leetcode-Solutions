class Solution {
public:
    bool isMatch(string s, string t) {
        
        int n=s.length();
        int m=t.length();

        vector<vector<bool>> dp(n+1,vector<bool>(m+1));
        dp[0][0] = true;

        for(int i=1;i<=m;i++) {
            bool flag=true;
            for(int k=0;k<i;k++) {
                if(t[k]!='*') {
                    flag=false;
                    break;
                }
            }
            dp[0][i] = flag;
        }

        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                if(s[i-1]==t[j-1] || t[j-1]=='?')
                    dp[i][j] = dp[i-1][j-1];
                else if(t[j-1]=='*')
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                else
                    dp[i][j] = false;
            }
        }
        return dp[n][m];
    }
};