class Solution {
public:
    int longestMountain(vector<int>& nums) {
        int n=nums.size(),ans=0;
        vector<int> prf(n+1,0),suf(n+1,0);
        for(int i=1;i<n;i++){
            if(nums[i-1]<nums[i])
                prf[i]=prf[i-1]+1;
        }
        for(int i=n-2;i>0;i--){
            if(nums[i]>nums[i+1])
                suf[i]=suf[i+1]+1;
        }
        for(int i=0;i<n;i++){
            if(prf[i]==0 || suf[i]==0)
                continue;
            int len=prf[i]+suf[i]+1;
            if(len>=3)
                ans=max(ans,len);
        }
        return ans;
    }
};