class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=0,mi=nums[nums.size()/2];
        for(int x:nums)
            ans += abs(x-mi);
        return ans;
    }
};