class Solution {
public:

    long long mod = ((1e9)+7);
    int distinctSubseqII(string s) {
        
        long long tot = 1;
        vector<int> dp(26);
        for(char c:s) {
            int cur = c-'a';
            long long prv = tot;
            tot = (2*tot)%mod;
            tot = (tot-dp[cur]+mod)%mod;
            dp[cur] = prv;
        }
        return (tot-1+mod)%mod;
    }
};