class Solution {
public:

    int n,one,two,three,dp[366];
    int fun( int i , vector<int>& arr ) {
        if( i >= n )
            return 0;

        if( dp[i] != -1 )
            return dp[i];
        
        int ans = 1e9;
        ans = min( ans , fun( i+1 , arr ) + one );
        int idx1 = lower_bound(arr.begin(),arr.end(),arr[i]+7)-arr.begin();
        //if(i<idx1)
            ans = min( ans , fun(idx1,arr) + two );
        int idx2 = lower_bound(arr.begin(),arr.end(),arr[i]+30)-arr.begin();
        //if(i<idx2)
            ans = min( ans , fun(idx2,arr) + three );
        return dp[i] = ans;
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        n = days.size() ;
        memset(dp,-1,sizeof(dp));
        one=costs[0],two=costs[1],three=costs[2];
        return fun(0,days);
    }
};