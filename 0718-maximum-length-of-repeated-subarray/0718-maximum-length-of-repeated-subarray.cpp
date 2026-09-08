class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums1.size(), m = nums2.size();

        if(m>n)
            return findLength(nums2,nums1);

        int ans = 0;
        vector<int> dp(m+1);
        for(int i=1;i<=n;i++) {
            int prv = 0;
            for(int j=1;j<=m;j++) {
                int temp = dp[j];
                if(nums1[i-1]==nums2[j-1])
                    dp[j] = 1+prv;
                else
                    dp[j] = 0;
                prv = temp;
                ans = max(ans,dp[j]);
            }
        }
        return ans;
    }
};