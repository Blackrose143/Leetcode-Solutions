class Solution {
public:

    int n;
    vector<int> dp;
    int fun(int i) {
        if(i>n)
            return 0;
        
        if(i==n)
            return 1;

        if(dp[i]!=-1)
            return dp[i];

        int ans=0;
        ans += fun(i+1);
        ans += fun(i+2);
        return dp[i] = ans;
    }

    int climbStairs(int n_) {
        n = n_;
        dp.resize(n,-1);
        return fun(0);
    }
};