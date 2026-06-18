class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=0,sum=0;
        int mx=*max_element(nums.begin(),nums.end());
        if(mx<0)
            return mx;
        for(int num:nums){
            sum+=num;
            if(sum<0)
                sum=0;
            ans=max(ans,sum);
        }
        return ans;
    }
};