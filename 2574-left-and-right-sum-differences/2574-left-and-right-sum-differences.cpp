class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return {0};
        vector<int> prf(n,0),suf(n,0),ans;
        for(int i=1;i<n;i++)
            prf[i]=prf[i-1]+nums[i-1];
        for(int i=n-2;i>=0;i--)
            suf[i]=suf[i+1]+nums[i+1];
        for(int i=0;i<n;i++)
            ans.push_back(abs(prf[i]-suf[i]));
        return ans;
    }
};