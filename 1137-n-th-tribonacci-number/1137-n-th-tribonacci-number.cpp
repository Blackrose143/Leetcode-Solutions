class Solution {
public:

    int n,dp[50];
    int rec(int i){
        if(i<=1)
            return i;
        if(i==2)
            return 1;
        if(dp[i]!=-1)
            return dp[i];
        return dp[i]=rec(i-1)+rec(i-2)+rec(i-3);
    }
    
    int tribonacci(int n_) {
        n=n_;
        memset(dp,-1,sizeof(dp));
        return rec(n);
    }
};