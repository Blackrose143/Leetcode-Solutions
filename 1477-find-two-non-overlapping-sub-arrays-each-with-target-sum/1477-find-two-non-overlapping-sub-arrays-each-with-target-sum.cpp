class Solution {
public:
    static int minSumOfLengths(vector<int>& nums, int tar) {
        
        int n=nums.size();
        int prv=1e9, ans=1e9, sum=0, l=0;
        vector<int> dp(n+1);

        for(int r=0; r<n; r++){

            sum += nums[r];
            while(sum>tar)
                sum -= nums[l++];

            dp[r]=prv;
            if (sum == tar){
                int len = r-l+1;
                if (l>0) 
                    ans = min(ans, len+dp[l-1]);
                dp[r] = min(dp[r], len);
            }
            prv = dp[r];
        }
        return ans>=1e9?-1:ans;
    }
};