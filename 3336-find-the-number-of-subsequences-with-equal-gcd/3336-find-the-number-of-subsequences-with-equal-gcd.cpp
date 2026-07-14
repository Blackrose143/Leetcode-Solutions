class Solution {
public:

    int n,mod=((int)1e9+7);
    int dp[201][201][201];
    int fun(int idx,int g1,int g2,vector<int>& nums){
        if(idx==n)
            return (g1!=0 && g1==g2);
        
        int &ans=dp[idx][g1][g2];
        if(ans!=-1)
            return ans;

        ans=0;

        ans = fun(idx+1,g1,g2,nums);

        int ng1 = (g1==0) ? nums[idx] : gcd(g1,nums[idx]);
        ans = (ans + fun(idx+1,ng1,g2,nums)) % mod;

        int ng2 = (g2==0) ? nums[idx] : gcd(g2,nums[idx]);
        ans = (ans + fun(idx+1,g1,ng2,nums)) % mod;

        return ans;
    }
    
    int subsequencePairCount(vector<int>& nums) {
        n=nums.size();
        memset(dp,-1,sizeof(dp));
        return fun(0,0,0,nums);
    }
};