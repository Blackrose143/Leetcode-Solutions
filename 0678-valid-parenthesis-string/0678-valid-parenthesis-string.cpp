class Solution {
public:

    int n;
    vector<vector<int>> dp;
    bool fun(int i,int cnt,string& s) {

        if(cnt<0)
            return false;
        
        if(i==n)
            return cnt==0;

        if(dp[i][cnt]!=-1)
            return dp[i][cnt];

        bool ans=false;
        if(s[i]=='(')
            ans |= fun(i+1,cnt+1,s);
        else if(s[i]==')')
            ans |= fun(i+1,cnt-1,s);
        else{
            ans |= fun(i+1,cnt+1,s);
            ans |= fun(i+1,cnt-1,s);
            ans |= fun(i+1,cnt,s);
        }
        return dp[i][cnt] = ans;
    }

    bool checkValidString(string s) {
        n = s.length();
        dp.resize(n,vector<int>(n,-1));
        return fun(0,0,s);
    }
};