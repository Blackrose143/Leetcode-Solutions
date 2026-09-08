class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int tar) {
        int n = nums.size();
        int l = 0, r = n-1;
        while(l<r) {
            int val = nums[l]+nums[r];
            if(val==tar)
                return {l+1,r+1};
            if(val>tar)
                r--;
            else
                l++;
        }
        return {-1,-1};
    }
};