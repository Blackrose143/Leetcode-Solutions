class Solution {
public:

    long long n,dp[100032];
    long long fun( int i , vector<vector<int>>& arr ) {
        if(i >= n)
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        long long ans=-1e18;
        ans = max( ans , fun(i+1,arr));
        ans = max( ans , fun(i+arr[i][1]+1,arr) + arr[i][0] );
        return dp[i] = ans;
    }
    long long mostPoints(vector<vector<int>>& questions) {
        n=questions.size();
        memset(dp,-1,sizeof(dp));
        return fun(0,questions);
    }
};