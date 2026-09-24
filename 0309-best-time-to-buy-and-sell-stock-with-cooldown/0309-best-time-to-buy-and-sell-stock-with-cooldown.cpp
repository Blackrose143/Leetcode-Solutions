class Solution {
public:

    int n;
    vector<vector<int>> dp;
    int fun(int i,int k,vector<int>& prices) {
        if(i>=n)
            return 0;

        if(dp[i][k]!=-1)
            return dp[i][k];

        int ans=-1e9;
        if(!k) {
            ans = max(ans,fun(i+1,k^1,prices)-prices[i]);
            ans = max(ans,fun(i+1,k,prices));
        }else{
            ans = max(ans,fun(i+2,k^1,prices)+prices[i]);
            ans = max(ans,fun(i+1,k,prices));
        }
        return dp[i][k] = ans;
    }

    int maxProfit(vector<int>& prices) {

        n = prices.size();
        dp.resize(n,vector<int>(2,-1));
        return fun(0,0,prices);
    }
};