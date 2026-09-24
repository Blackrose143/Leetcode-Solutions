class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        
        int n=s1.size();
        int m=s2.size();
        int l=s3.size();

        if(n+m!=l)
            return false;
        
        if(n<m)
            return isInterleave(s2,s1,s3);

        vector<bool> dp(n+1);
        dp[0] = true;

        for(int i=1;i<=m;i++)
            dp[i] = dp[i-1] && s2[i-1]==s3[i-1];

        for(int i=1;i<=n;i++) {
            dp[0] = dp[0] && s1[i-1]==s3[i-1];
            for(int j=1;j<=m;j++) {
                dp[j] = (dp[j] && s1[i-1]==s3[j+i-1]) || (dp[j-1] && s2[j-1]==s3[j+i-1]);
            }
        }
        return dp[m];
    }
};