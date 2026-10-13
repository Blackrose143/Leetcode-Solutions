class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long n=nums.size(),ans=0;
        for(int i=0;i<n;i++) {
            nums[i] = nums[i]*nums[i];
        }
        sort(nums.begin(),nums.end());
        for(int i=n/2;i<n;i+=1) {
            ans += nums[i];
        }
        for(int i=0;i<n/2;i++)
            ans -= nums[i];
        return ans;
    }
};