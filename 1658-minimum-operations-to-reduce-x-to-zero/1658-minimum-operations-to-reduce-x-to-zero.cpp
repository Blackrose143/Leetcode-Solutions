class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n=nums.size();
        int tot=accumulate(nums.begin(),nums.end(),0LL);
        int l=0,sum=0,tar=tot-k,ans=1e9;
        for(int r=0;r<n;r++) {
            sum += nums[r];
            while(l<=r && sum>tar)
                sum -= nums[l++];
            if(sum==tar)
                ans = min(ans,n-(r-l+1));
        }
        return ans==1e9?-1:ans;
    }
};