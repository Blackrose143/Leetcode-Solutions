class Solution {
public:

    int dp[22][23];
    int rec(int i,int j,vector<int>& nums){
        if(i==j)
            return nums[i];
        
        if(dp[i][j] != -1)  
            return dp[i][j];

        int left = nums[i] - rec(i+1,j,nums);
        int right = nums[j] - rec(i,j-1,nums);
        return dp[i][j] = max(left,right);
    }

    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        memset(dp,-1,sizeof(dp));
        return rec(0,n-1,nums) >= 0;    
    }
};