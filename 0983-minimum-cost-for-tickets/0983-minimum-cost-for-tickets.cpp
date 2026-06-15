class Solution {
public:
    int n ;
int one ,two ,three;
int dp[366];
    int fun( int i , vector<int>&arr ) {

        if( i >= n ){
            return 0 ;
        }

        if(dp[i] != -1 ){
            return dp[i];
        }
        int ans = 1e9 ;
        ans = min( ans , fun( i + 1 , arr ) + one  );

        int ind = lower_bound(arr.begin() , arr.end() , arr[i] + 7  ) - arr.begin()   ;
        if( i < ind )
        ans = min( ans , fun( ind , arr ) + two  );
        
        int ind2 = lower_bound(arr.begin() , arr.end() , arr[i] + 30 ) - arr.begin() ;
        if( i < ind2 )
        ans = min( ans , fun( ind2 , arr ) + three  );

        return dp[i] =  ans;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        n = days.size();
        one = costs[0];
        two = costs[1];
        three = costs[2];

        memset(dp,-1,sizeof(dp));

        int res=  fun( 0 , days );
        return res;
    }
};