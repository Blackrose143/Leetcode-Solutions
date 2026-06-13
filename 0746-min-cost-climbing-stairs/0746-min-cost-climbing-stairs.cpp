class Solution {
public:

    int n,dp[1032];
    int rec(int i,vector<int>& cost){
        if(i>=n)
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        return dp[i]=cost[i]+min(rec(i+1,cost),rec(i+2,cost));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        n=cost.size();
        memset(dp,-1,sizeof(dp));
        return min(rec(0,cost),rec(1,cost));
    }
};