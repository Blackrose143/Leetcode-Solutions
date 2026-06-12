class Solution {
public:
    int tribonacci(int n) {
        if(n<=1)
            return n;
        if(n==2)
            return 1;
        int dp[n+1];
        memset(dp,-1,sizeof(dp));
        dp[0]=0,dp[1]=1,dp[2]=1;
        for(int i=3;i<=n;i++)
            dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
        long long ans=0;
        for(int i:dp)
            ans+=i;
        return dp[n];
    }
};