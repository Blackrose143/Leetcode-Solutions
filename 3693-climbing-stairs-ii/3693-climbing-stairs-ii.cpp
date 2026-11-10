class Solution {
public:

    int n;
    vector<int> dp;
    int fun(int i,vector<int>& nums) {
        if(i==n)
            return 0;

        if(dp[i]!=-1)
            return dp[i];

        int ans = 1e9;
        if(i+1<=n)
            ans = min(ans,fun(i+1,nums)+nums[i+1-1]+(((i+1)-i)*((i+1)-i)));
        if(i+2<=n)
            ans = min(ans,fun(i+2,nums)+nums[i+2-1]+(((i+2)-i)*((i+2)-i)));
        if(i+3<=n)
            ans = min(ans,fun(i+3,nums)+nums[i+3-1]+(((i+3)-i)*((i+3)-i)));

        return dp[i] = ans;
    }

    int climbStairs(int n_, vector<int>& costs) {
        n = n_;
        dp.resize(n,-1);
        return fun(0,costs);
    }
};