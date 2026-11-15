class Solution {
public:

    int mod=((int)1e9+7);
    int numOfSubarrays(vector<int>& nums) {
        int n = nums.size();
        int ans = 0, sum = 0, odd = 0, even = 0;
        for(int i=0;i<n;i++) {
            sum += nums[i];
            if(sum%2==0) {
                ans = (ans + odd) % mod;
                even += 1;
            }else {
                ans = (ans + even + 1) % mod;
                odd += 1;
            }
        }
        return ans % mod;
    }
};