class Solution {
public:

    int n,m;
    vector<vector<int>> dp;
    bool fun(int i,int j,string& s,string& t) {
        if(i<0 && j<0)
            return true;

        if(j<0 && i>=0)
            return false;

        if(i<0 && j>=0) {
            for(int k=0;k<=j;k++)
                if(t[k]!='*')
                    return false;
            return true;
        }

        if(dp[i][j]!=-1)
            return dp[i][j];

        bool ans=false;
        if(s[i]==t[j] || t[j]=='?')
            ans |= fun(i-1,j-1,s,t);
        else if(t[j]=='*')
            ans |= (fun(i-1,j,s,t) | fun(i,j-1,s,t));
        return dp[i][j] = ans;
    }

    bool isMatch(string s, string t) {
        n = s.size();
        m = t.size();

        dp.assign(n,vector<int>(m,-1));
        return fun(n-1,m-1,s,t);
    }
};