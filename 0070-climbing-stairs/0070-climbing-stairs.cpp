class Solution {
public:

    int n,dp[50];
    int rec(int i){
        if(i==n)
            return 1;
        if(i>n)
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        int ans=0;
        ans+=rec(i+1);
        ans+=rec(i+2);
        return dp[i]=ans;
    }
    int climbStairs(int n_) {
        n=n_;
        memset(dp,-1,sizeof(dp));
        return rec(0);
    }
};