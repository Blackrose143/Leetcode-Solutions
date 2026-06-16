class Solution {
public:

    int n,dp[132];
    int fun( int i , string s){
        if(i==n)
            return 1;
        if(i>n)
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        int ways=0,a=(s[i]-'0');
        if(a != 0)
            ways += fun( i+1 , s);
        if(i+1 < n && a==1 || a==2){
            int val=10*a+(s[i+1]-'0');
            if(val<=26)
                ways += fun(i+2,s);
        }
        return dp[i]=ways;
    }
    int numDecodings(string s) {
        n=s.length();
        memset(dp,-1,sizeof(dp));;
        return fun(0,s);
    }
};