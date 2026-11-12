class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size(), ans = 1, l = 0;
        for(int r=1;r<n;r++) {
            if(nums[r]>nums[r-1]) {
                ans = max(ans,r-l+1);
            }else {
                l = r;
            }
        }
        l = 0;
        for(int r=1;r<n;r++) {
            if(nums[r]<nums[r-1]) {
                ans = max(ans,r-l+1);
            }else {
                l = r;
            }
        }
        return ans;
    }
};