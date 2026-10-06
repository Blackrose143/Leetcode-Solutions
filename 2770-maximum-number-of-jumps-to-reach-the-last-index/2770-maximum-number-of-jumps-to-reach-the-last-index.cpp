class Solution {
public:

    int n,t;
    vector<int> dp;
    int fun(int i,vector<int>& nums) {
        if(i>=n)
            return -1e9;

        if(i==n-1)
            return 0;

        if(dp[i]!=-1)
            return dp[i];
        
        int ans=-1e9;
        for(int k=i+1;k<n;k++) {
            if(abs(nums[k]-nums[i])<=t) 
                ans = max(ans,fun(k,nums)+1);
        }
        return dp[i] = ans;
    }

    int maximumJumps(vector<int>& nums, int target) {
        n = nums.size();
        t = target;
        dp.resize(n,-1);
        int ans=fun(0,nums);
        if(ans<0)
            return -1;
        return ans;
    }
};