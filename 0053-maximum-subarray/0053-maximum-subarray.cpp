class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0,ans=nums[0];
        for(int num:nums){
            sum=max(sum+num,num);
            ans=max(ans,sum);
        }
        return ans;
    }
};