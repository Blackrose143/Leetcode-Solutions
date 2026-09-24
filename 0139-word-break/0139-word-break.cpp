class Solution {
public:

    int n;
    unordered_set<string> st;
    vector<bool> dp;
    bool fun(int i,string& s) {

        if(!dp[i])
            return false;

        string w="";
        for(int k=i;k<n;k++) {
            w += s[k];
            if(st.find(w)!=st.end()) {
                if(k==n-1)
                    return true;

                if(k<n-1 && fun(k+1,s))
                    return true;
            }
        }
        return dp[i] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        n = s.length();
        for(string& w:wordDict)
            st.insert(w);

        dp.assign(n+1,true);
        return fun(0,s);
    }
};