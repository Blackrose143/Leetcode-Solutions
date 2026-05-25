class Solution {
public:

    int n,dp[1032];
    int dfs(int i,vector<int>& nums,int d){
        if(dp[i]!=-1)
            return dp[i];
        int ans=1;
        for(int k=i+1;k<=min(n-1,i+d);k++){
            if(nums[k]>=nums[i])
                break;
            ans=max(ans,dfs(k,nums,d)+1);
        }
        for(int k=i-1;k>=max(0,i-d);k--){
            if(nums[k]>=nums[i])
                break;
            ans=max(ans,dfs(k,nums,d)+1);
        }
        return dp[i]=ans;
    }
    int maxJumps(vector<int>& nums, int d) {
        n=nums.size();
        int ans=1;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++)
            ans=max(ans,dfs(i,nums,d));
        return ans;
    }
};