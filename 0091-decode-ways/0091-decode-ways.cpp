class Solution {
public:

    int dp[102];
    int n ;
    int rec(int i,string& s){
        if( i == n ){
            return 1;
        }

        int ans = 0 ;

        if( dp[i] != -1) 
            return dp[i];

        int a = 0 ;
        if( i < n )
            a = (s[i] - '0');
        if( a != 0 )
            ans += rec( i + 1, s );
        // 226
        //a = 2 
        // b = 22 
        if( i + 1 < n && a == 1 ||a == 2   ){
            int b = a * 10 + s[i+1] - '0';
            if( b <= 26 )
            ans += rec( i + 2 , s ) ; 
        }
        return dp[i] =  ans;
    }
    int numDecodings(string s) {
        n =s.size();
        memset(dp,-1,sizeof(dp));
        int res = rec(0,s);
        char c = '4';
        int a = c - '0';
        cout<<a<<endl;

        return res;
    }
};